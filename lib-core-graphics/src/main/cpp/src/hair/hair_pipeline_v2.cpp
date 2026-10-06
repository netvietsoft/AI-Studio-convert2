#include "hair/hair_pipeline_v2.h"
#include "ai/bisenet_face_parser.h"
#include "ai/selfie_human_parser.h"
#include "hair_strand_dye.h"
#include <android/log.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <omp.h>

#define TAG "HCE_HairPipelineV2"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)

#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) | \
                               ((static_cast<uint32_t>(b) & 0xFF) << 16) | \
                               ((static_cast<uint32_t>(g) & 0xFF) << 8)  | \
                               ((static_cast<uint32_t>(r) & 0xFF) << 0))

namespace meitu_native::hce {

static bool sHairPipelineV2Enabled = true;
static int sHairPipelineVersion = static_cast<int>(HairPipelineV2::Version::VERSION_V3_REBUILD);

void HairPipelineV2::setEnabled(bool enabled) {
    sHairPipelineV2Enabled = enabled;
    LOGI("HairPipelineV2: Feature flag set to %d", enabled ? 1 : 0);
}

bool HairPipelineV2::isEnabled() {
    return sHairPipelineV2Enabled;
}

void HairPipelineV2::setExecutionVersion(int version) {
    sHairPipelineVersion = version;
    LOGI("HairPipelineV2: Execution version set to %d", version);
}

int HairPipelineV2::getExecutionVersion() {
    return sHairPipelineVersion;
}

HairPipelineV2& HairPipelineV2::getInstance() {
    static HairPipelineV2 instance;
    return instance;
}

static inline uint8_t clampU8(int v) {
    return static_cast<uint8_t>(std::clamp(v, 0, 255));
}

static inline bool isHumanSkinPixel(int r, int g, int b) {
    if (r <= 45 || g <= 28 || b <= 15) return false;
    float y = 0.299f * r + 0.587f * g + 0.114f * b;
    float cr = (r - y) * 0.713f + 128.0f;
    float cb = (b - y) * 0.564f + 128.0f;
    if (cr >= 130.0f && cr <= 175.0f && cb >= 77.0f && cb <= 130.0f && r > b) {
        return true;
    }
    if (r > g && g >= b && (r - g) >= 5 && (r - b) >= 10) {
        return true;
    }
    return false;
}

static void boxFilter2D(const float* src, float* dst, int w, int h, int r) {
    std::vector<float> temp(w * h, 0.0f);

    #pragma omp parallel for schedule(static, 16)
    for (int y = 0; y < h; ++y) {
        float sum = 0.0f;
        for (int x = -r; x <= r; ++x) {
            int cx = std::clamp(x, 0, w - 1);
            sum += src[y * w + cx];
        }
        temp[y * w] = sum;
        for (int x = 1; x < w; ++x) {
            int prev = std::clamp(x - r - 1, 0, w - 1);
            int next = std::clamp(x + r, 0, w - 1);
            sum += src[y * w + next] - src[y * w + prev];
            temp[y * w + x] = sum;
        }
    }

    float norm = 1.0f / ((2 * r + 1) * (2 * r + 1));
    #pragma omp parallel for schedule(static, 16)
    for (int x = 0; x < w; ++x) {
        float sum = 0.0f;
        for (int y = -r; y <= r; ++y) {
            int cy = std::clamp(y, 0, h - 1);
            sum += temp[cy * w + x];
        }
        dst[x] = sum * norm;
        for (int y = 1; y < h; ++y) {
            int prev = std::clamp(y - r - 1, 0, h - 1);
            int next = std::clamp(y + r, 0, h - 1);
            sum += temp[next * w + x] - temp[prev * w + x];
            dst[y * w + x] = sum * norm;
        }
    }
}

static void resizeLinear(const float* src, int sw, int sh, float* dst, int dw, int dh) {
    #pragma omp parallel for schedule(static, 16)
    for (int dy = 0; dy < dh; ++dy) {
        float sy = dy * (float)sh / dh;
        int y0 = std::clamp((int)sy, 0, sh - 1);
        int y1 = std::clamp(y0 + 1, 0, sh - 1);
        float fy = sy - y0;

        for (int dx = 0; dx < dw; ++dx) {
            float sx = dx * (float)sw / dw;
            int x0 = std::clamp((int)sx, 0, sw - 1);
            int x1 = std::clamp(x0 + 1, 0, sw - 1);
            float fx = sx - x0;

            float v00 = src[y0 * sw + x0];
            float v10 = src[y0 * sw + x1];
            float v01 = src[y1 * sw + x0];
            float v11 = src[y1 * sw + x1];

            float v = (1.0f - fx) * (1.0f - fy) * v00 +
                      fx * (1.0f - fy) * v10 +
                      (1.0f - fx) * fy * v01 +
                      fx * fy * v11;
            dst[dy * dw + dx] = v;
        }
    }
}

void HairPipelineV2::sRGBToOKLab(float r, float g, float b, float& L, float& a, float& bCoord) {
    auto toLinear = [](float c) {
        return (c <= 0.04045f) ? (c / 12.92f) : std::pow((c + 0.055f) / 1.055f, 2.4f);
    };
    float lr = toLinear(r);
    float lg = toLinear(g);
    float lb = toLinear(b);

    float l = std::cbrt(0.4122214708f * lr + 0.5363325363f * lg + 0.0514459929f * lb);
    float m = std::cbrt(0.2119034982f * lr + 0.6806995451f * lg + 0.1073969566f * lb);
    float s = std::cbrt(0.0883024619f * lr + 0.2817188376f * lg + 0.6299787005f * lb);

    L = 0.2104542553f * l + 0.7936177850f * m - 0.0040720468f * s;
    a = 1.9779984951f * l - 2.4285922050f * m + 0.4505937099f * s;
    bCoord = 0.0259040371f * l + 0.7827717662f * m - 0.8086757660f * s;
}

void HairPipelineV2::oklabTosRGB(float L, float a, float bCoord, float& r, float& g, float& b) {
    float l = L + 0.3963377774f * a + 0.2158037573f * bCoord;
    float m = L - 0.1055613458f * a - 0.0638541728f * bCoord;
    float s = L - 0.0894841775f * a - 1.2914855480f * bCoord;

    float l3 = l * l * l;
    float m3 = m * m * m;
    float s3 = s * s * s;

    float lr = +4.0767434721f * l3 - 3.3077115913f * m3 + 0.2309699292f * s3;
    float lg = -1.2684380046f * l3 + 2.6097574011f * m3 - 0.3413193965f * s3;
    float lb = -0.0041960863f * l3 - 0.7034186147f * m3 + 1.7076147010f * s3;

    auto fromLinear = [](float c) {
        float clamped = std::clamp(c, 0.0f, 1.0f);
        return (clamped <= 0.0031308f) ? (clamped * 12.92f) : (1.055f * std::pow(clamped, 1.0f / 2.4f) - 0.055f);
    };

    r = fromLinear(lr);
    g = fromLinear(lg);
    b = fromLinear(lb);
}

// Stage 1: Input Validation
bool HairPipelineV2::validateInputs(const uint32_t* srcPixels, int width, int height) {
    return (srcPixels != nullptr && width > 0 && height > 0 && width <= 8192 && height <= 8192);
}

// Stage 2: Hair Segmentation / Matte
bool HairPipelineV2::extractHairMatte(
    const uint32_t* srcPixels, int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    std::vector<float>& outMatte,
    std::vector<uint8_t>& outFullLabels,
    bool& outIsBald
) {
    outMatte.assign(width * height, 0.0f);
    outFullLabels.assign(width * height, 0);
    outIsBald = false;

    if (!meitu::ai::BiSeNetFaceParser::getInstance().isInitialized()) {
        LOGE("HairPipelineV2: BiSeNet parser not initialized!");
        return false;
    }

    std::vector<uint8_t> labels512(512 * 512, 0);
    std::vector<float> hairProb512(512 * 512, 0.0f);

    bool ok = meitu::ai::BiSeNetFaceParser::getInstance().parseFace19Adaptive(
        srcPixels, width, height, outFullLabels, &labels512, &hairProb512
    );
    if (!ok) {
        LOGE("HairPipelineV2: BiSeNet adaptive parsing failed");
        return false;
    }

    // Anchor face center & hair count
    int hair_pixels = 0;
    float seed_r = 0.0f, seed_g = 0.0f, seed_b = 0.0f;
    int seed_count = 0;

    #pragma omp parallel for reduction(+:hair_pixels, seed_r, seed_g, seed_b, seed_count) schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint8_t lbl = outFullLabels[i];
        if (lbl == 17) { // HAIR
            hair_pixels++;
            uint32_t c = srcPixels[i];
            seed_r += RGBA_R(c);
            seed_g += RGBA_G(c);
            seed_b += RGBA_B(c);
            seed_count++;
        }
    }

    if (seed_count >= 60) {
        seed_r /= seed_count;
        seed_g /= seed_count;
        seed_b /= seed_count;
    } else {
        seed_r = 45.0f; seed_g = 38.0f; seed_b = 32.0f;
    }

    // Bald Safeguard (Monk negative control)
    if (hair_pixels < 350 && seed_count < 60) {
        LOGI("HairPipelineV2: Bald negative subject detected (hair_px=%d). Zero alpha output.", hair_pixels);
        outIsBald = true;
        return true;
    }

    // Initial matte strictly from hair class 17 (excluding skin pixels)
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint8_t lbl = outFullLabels[i];
        if (lbl == 17) {
            uint32_t c = srcPixels[i];
            if (!isHumanSkinPixel(RGBA_R(c), RGBA_G(c), RGBA_B(c))) {
                outMatte[i] = 1.0f;
            }
        }
    }

    return true;
}

// Stage 3: Edge / Hairline Refinement
bool HairPipelineV2::refineHairlineEdges(
    const uint32_t* srcPixels, int width, int height,
    const std::vector<float>& inMatte,
    const std::vector<uint8_t>& fullLabels,
    std::vector<float>& outRefinedMatte
) {
    outRefinedMatte.assign(width * height, 0.0f);

    // Compute grayscale guide
    std::vector<float> gray(width * height, 0.0f);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = srcPixels[i];
        gray[i] = (0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c)) / 255.0f;
    }

    // Fast Guided Filter (Box r=6, subsampled by 2x)
    const int scale = 2;
    const int gw = width / scale, gh = height / scale;
    std::vector<float> g_sub(gw * gh), p_sub(gw * gh);
    resizeLinear(gray.data(), width, height, g_sub.data(), gw, gh);
    resizeLinear(inMatte.data(), width, height, p_sub.data(), gw, gh);

    const int r_sub = 4;
    const float eps = 1e-3f;
    std::vector<float> mean_I(gw * gh), mean_p(gw * gh), mean_Ip(gw * gh), mean_II(gw * gh);
    std::vector<float> Ip(gw * gh), II(gw * gh);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < gw * gh; ++i) {
        Ip[i] = g_sub[i] * p_sub[i];
        II[i] = g_sub[i] * g_sub[i];
    }

    boxFilter2D(g_sub.data(), mean_I.data(), gw, gh, r_sub);
    boxFilter2D(p_sub.data(), mean_p.data(), gw, gh, r_sub);
    boxFilter2D(Ip.data(), mean_Ip.data(), gw, gh, r_sub);
    boxFilter2D(II.data(), mean_II.data(), gw, gh, r_sub);

    std::vector<float> a(gw * gh), b(gw * gh);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < gw * gh; ++i) {
        float var_I = mean_II[i] - mean_I[i] * mean_I[i];
        float cov_Ip = mean_Ip[i] - mean_I[i] * mean_p[i];
        float ak = cov_Ip / (var_I + eps);
        float bk = mean_p[i] - ak * mean_I[i];
        a[i] = ak;
        b[i] = bk;
    }

    std::vector<float> mean_a(gw * gh), mean_b(gw * gh);
    boxFilter2D(a.data(), mean_a.data(), gw, gh, r_sub);
    boxFilter2D(b.data(), mean_b.data(), gw, gh, r_sub);

    std::vector<float> mean_a_full(width * height), mean_b_full(width * height);
    resizeLinear(mean_a.data(), gw, gh, mean_a_full.data(), width, height);
    resizeLinear(mean_b.data(), gw, gh, mean_b_full.data(), width, height);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float q = mean_a_full[i] * gray[i] + mean_b_full[i];
        outRefinedMatte[i] = std::clamp(q, 0.0f, 1.0f);
    }

    return true;
}

// Stage 4: Confidence & Skin/Face/Background Exclusion
bool HairPipelineV2::applyConfidenceAndExclusion(
    const uint32_t* srcPixels, int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    const std::vector<uint8_t>& fullLabels,
    const std::vector<float>& inMatte,
    std::vector<float>& outConfidenceMatte
) {
    outConfidenceMatte.assign(width * height, 0.0f);

    int bgY = static_cast<int>(std::ceil(0.16f * height));
    int bgX1 = static_cast<int>(std::ceil(0.22f * width));
    int bgX2 = static_cast<int>(std::floor(0.78f * width));

    int fhY1 = height / 3;
    int fhY2 = static_cast<int>(0.49f * height);
    int fhX1 = static_cast<int>(0.37f * width);
    int fhX2 = static_cast<int>(0.63f * width);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        bool inBgY = (y < bgY);
        bool inFhY = (y >= fhY1 && y <= fhY2);

        for (int x = 0; x < width; ++x) {
            int idx = yOff + x;
            uint8_t lbl = fullLabels[idx];

            // 1. Strict label gate: ONLY hair class 17 is permitted.
            // Non-hair classes (0=Background, 1=Face skin, 2..5, 10..13=Features,
            // 6=Glasses, 7,8=Ears, 9=Earrings, 14,15=Neck, 16=Clothing, 18=Hat)
            // are strictly excluded with 0.0f confidence.
            if (lbl != 17) {
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }

            // 2. Strict background corner exclusion: eliminate stray corner labels in top outer corners
            if (inBgY && (x < bgX1 || x >= bgX2)) {
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }

            // 3. Strict skin exclusion: zero tolerance for skin pixels even if misclassified as hair
            uint32_t c = srcPixels[idx];
            int r = RGBA_R(c);
            int g = RGBA_G(c);
            int b = RGBA_B(c);
            if (isHumanSkinPixel(r, g, b)) {
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }

            // 4. Strict Forehead Box Protection: zero tolerance for any skin/near-skin in forehead zone
            if (inFhY && (x >= fhX1 && x <= fhX2)) {
                float yVal = 0.299f * r + 0.587f * g + 0.114f * b;
                float cr = (r - yVal) * 0.713f + 128.0f;
                if ((cr >= 125.0f && cr <= 180.0f && r > b) || (r > g && g >= b)) {
                    outConfidenceMatte[idx] = 0.0f;
                    continue;
                }
            }

            float conf = inMatte[idx];
            if (conf < 0.02f) {
                conf = 0.0f;
            }

            outConfidenceMatte[idx] = std::clamp(conf, 0.0f, 1.0f);
        }
    }

    return true;
}

// Stage 5: Strand / Texture Guidance & Shadow/Specular Maps
bool HairPipelineV2::extractStrandTextureGuidance(
    const uint32_t* srcPixels, int width, int height,
    const std::vector<float>& confidenceMatte,
    std::vector<float>& outTextureGuidance,
    std::vector<float>& outShadowMap,
    std::vector<float>& outSpecularMap
) {
    outTextureGuidance.assign(width * height, 0.0f);
    outShadowMap.assign(width * height, 1.0f);
    outSpecularMap.assign(width * height, 0.0f);

    std::vector<float> gray(width * height, 0.0f);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = srcPixels[i];
        gray[i] = (0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c)) / 255.0f;
    }

    // Local mean luminance for shadow/specular decomposition (box filter r=6)
    std::vector<float> localMean(width * height, 0.0f);
    boxFilter2D(gray.data(), localMean.data(), width, height, 6);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 1; y < height - 1; ++y) {
        int yOff = y * width;
        for (int x = 1; x < width - 1; ++x) {
            int idx = yOff + x;
            if (confidenceMatte[idx] < 0.01f) continue;

            float g = gray[idx];
            // High-frequency strand micro-contrast
            outTextureGuidance[idx] = g - localMean[idx];

            // Shadow Map (crevices where pixel is darker than local mean)
            float diff = localMean[idx] - g;
            float shadow = std::clamp(1.0f - diff * 2.2f, 0.15f, 1.0f);
            outShadowMap[idx] = shadow;

            // Specular Map (bright glints with low local variance)
            if (g > 0.55f && diff < -0.05f) {
                float spec = std::clamp((g - 0.55f) / 0.35f, 0.0f, 1.0f);
                outSpecularMap[idx] = spec;
            }
        }
    }

    return true;
}

// Stage 6: Physically Plausible Salon Color Transform
bool HairPipelineV2::transformColor(
    const uint32_t* srcPixels, int width, int height,
    const std::vector<float>& confidenceMatte,
    const std::vector<float>& textureGuidance,
    const std::vector<float>& shadowMap,
    const HairDyeMaterialParams& params,
    std::vector<uint32_t>& outColorPixels
) {
    outColorPixels.assign(srcPixels, srcPixels + width * height);

    float hueRad = params.targetHue * 0.0174532925f; // Deg to Rad
    float targetC = std::clamp(params.targetChroma / 100.0f * 0.28f, 0.0f, 0.35f);
    float targetA = targetC * std::cos(hueRad);
    float targetBCoord = targetC * std::sin(hueRad);
    float targetL = std::clamp(params.targetLightness / 100.0f, 0.05f, 0.95f);

    std::vector<float> origL(width * height, 0.0f);
    std::vector<float> origA(width * height, 0.0f);
    std::vector<float> origB(width * height, 0.0f);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = srcPixels[i];
        float r = RGBA_R(c) / 255.0f;
        float g = RGBA_G(c) / 255.0f;
        float b = RGBA_B(c) / 255.0f;
        sRGBToOKLab(r, g, b, origL[i], origA[i], origB[i]);
    }

    // Base illumination map via 2D box filter (r=3)
    std::vector<float> baseL(width * height, 0.0f);
    boxFilter2D(origL.data(), baseL.data(), width, height, 3);

    // High-frequency RGB strand preservation maps (box filter r=3)
    std::vector<float> origR(width * height), origG(width * height), origB_f(width * height);
    std::vector<float> baseR(width * height), baseG(width * height), baseB_f(width * height);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = srcPixels[i];
        origR[i] = static_cast<float>(RGBA_R(c));
        origG[i] = static_cast<float>(RGBA_G(c));
        origB_f[i] = static_cast<float>(RGBA_B(c));
    }
    boxFilter2D(origR.data(), baseR.data(), width, height, 3);
    boxFilter2D(origG.data(), baseG.data(), width, height, 3);
    boxFilter2D(origB_f.data(), baseB_f.data(), width, height, 3);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float conf = confidenceMatte[i];
        if (conf < 0.01f) continue;

        uint32_t c = srcPixels[i];
        float bL = baseL[i];

        // 1. Physically plausible melanin lift (bleach) applied to low-frequency base illumination
        float liftAmount = targetL - bL;
        float shadowF = shadowMap[i];
        float creviceDepth = std::pow(shadowF, 1.35f) * params.shadowPreservation + (1.0f - params.shadowPreservation);

        float melaninCurve = (bL > 0.0f) ? (0.40f + 0.60f * std::sqrt(std::clamp(bL, 0.0f, 1.0f))) : 0.40f;
        float liftedBaseL = bL + liftAmount * params.bleachPower * melaninCurve * creviceDepth;
        float finalL = std::clamp(liftedBaseL, 0.01f, 0.99f);

        // 2. Salon Dye Toner Deposition (Chroma)
        float midtoneWeight = 4.0f * finalL * (1.0f - finalL);
        float effectiveDyeStrength = std::clamp(0.40f + 0.60f * midtoneWeight, 0.0f, 1.0f) * creviceDepth;

        float finalA = origA[i] * (1.0f - effectiveDyeStrength) + targetA * effectiveDyeStrength;
        float finalB = origB[i] * (1.0f - effectiveDyeStrength) + targetBCoord * effectiveDyeStrength;

        // Convert base dye to sRGB
        float outR, outG, outB;
        oklabTosRGB(finalL, finalA, finalB, outR, outG, outB);

        // 3. Output smooth base dye illumination (exact 100% linear high-frequency strand fibers injected in Stage 9)
        outColorPixels[i] = PACK_RGBA(
            clampU8(static_cast<int>(std::round(outR * 255.0f))),
            clampU8(static_cast<int>(std::round(outG * 255.0f))),
            clampU8(static_cast<int>(std::round(outB * 255.0f))),
            RGBA_A(c)
        );
    }

    return true;
}

// Stage 7: Highlight / Shadow Preservation & Anisotropic Specular
bool HairPipelineV2::preserveHighlightsAndShadows(
    const uint32_t* srcPixels,
    const uint32_t* coloredPixels,
    int width, int height,
    const std::vector<float>& confidenceMatte,
    const std::vector<float>& specularMap,
    const HairSpecularParams& specParams,
    std::vector<uint32_t>& outFinalDyePixels
) {
    outFinalDyePixels.assign(coloredPixels, coloredPixels + width * height);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float conf = confidenceMatte[i];
        if (conf < 0.01f) continue;

        float spec = specularMap[i];
        if (spec > 0.02f) {
            uint32_t origC = srcPixels[i];
            uint32_t dyeC = coloredPixels[i];

            // Blend in neutral/translucent specular glint from original hair fibers
            float specSheen = spec * specParams.apparentShine * (1.0f - specParams.specularTint);
            specSheen = std::clamp(specSheen, 0.0f, 0.85f);

            int r = static_cast<int>(RGBA_R(dyeC) * (1.0f - specSheen) + RGBA_R(origC) * specSheen);
            int g = static_cast<int>(RGBA_G(dyeC) * (1.0f - specSheen) + RGBA_G(origC) * specSheen);
            int b = static_cast<int>(RGBA_B(dyeC) * (1.0f - specSheen) + RGBA_B(origC) * specSheen);

            outFinalDyePixels[i] = PACK_RGBA(clampU8(r), clampU8(g), clampU8(b), RGBA_A(dyeC));
        }
    }

    return true;
}

// Stage 8: Alpha Compositing with Original
bool HairPipelineV2::alphaComposite(
    const uint32_t* srcPixels,
    const uint32_t* dyedPixels,
    int width, int height,
    const std::vector<float>& finalAlpha,
    float intensity,
    uint32_t* dstPixels
) {
    float clampedIntensity = std::clamp(intensity, 0.0f, 1.0f);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float alpha = finalAlpha[i] * clampedIntensity;
        if (alpha <= 0.0001f) {
            dstPixels[i] = srcPixels[i];
            continue;
        }

        uint32_t origC = srcPixels[i];
        uint32_t dyeC = dyedPixels[i];

        if (alpha >= 0.9999f) {
            dstPixels[i] = dyeC;
            continue;
        }

        float invAlpha = 1.0f - alpha;
        int r = static_cast<int>(std::round(RGBA_R(origC) * invAlpha + RGBA_R(dyeC) * alpha));
        int g = static_cast<int>(std::round(RGBA_G(origC) * invAlpha + RGBA_G(dyeC) * alpha));
        int b = static_cast<int>(std::round(RGBA_B(origC) * invAlpha + RGBA_B(dyeC) * alpha));

        dstPixels[i] = PACK_RGBA(clampU8(r), clampU8(g), clampU8(b), RGBA_A(origC));
    }

    return true;
}

// Baseline V2 Pipeline (Preserved for rollback and exact A/B comparison)
bool HairPipelineV2::executePipelineV2_Baseline(
    const uint32_t* srcPixels,
    uint32_t* dstPixels,
    int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    const HairDyeMaterialParams& materialParams,
    const HairSpecularParams& specularParams,
    HairV2IntermediateStages* debugStages
) {
    // Stage 1: Input Validation
    if (!validateInputs(srcPixels, width, height) || !dstPixels) {
        LOGE("HairPipelineV2: Input validation failed!");
        return false;
    }

    // Preserve untouched input copy so in-place operations cannot corrupt source
    std::vector<uint32_t> originalSrcCopy(srcPixels, srcPixels + width * height);
    const uint32_t* origSrc = originalSrcCopy.data();

    // Stage 2: Hair Segmentation / Matte
    std::vector<float> rawMatte;
    std::vector<uint8_t> fullLabels;
    bool isBald = false;
    if (!extractHairMatte(origSrc, width, height, fused, rawMatte, fullLabels, isBald)) {
        LOGE("HairPipelineV2: Hair matte extraction failed!");
        return false;
    }

    // Negative Control: If bald subject, copy src to dst unchanged
    if (isBald) {
        std::memcpy(dstPixels, origSrc, width * height * sizeof(uint32_t));
        if (debugStages) {
            debugStages->isBald = true;
            debugStages->rawHairMask = rawMatte;
            debugStages->composited.assign(origSrc, origSrc + width * height);
        }
        return true;
    }

    // Stage 3: Edge / Hairline Refinement
    std::vector<float> refinedMatte;
    refineHairlineEdges(origSrc, width, height, rawMatte, fullLabels, refinedMatte);

    // Stage 4: Confidence & Skin/Face/Background Exclusion
    std::vector<float> confidenceMatte;
    applyConfidenceAndExclusion(origSrc, width, height, fused, fullLabels, refinedMatte, confidenceMatte);

    // Stage 5: Strand / Texture Guidance & Shadow/Specular Maps
    std::vector<float> textureGuidance;
    std::vector<float> shadowMap;
    std::vector<float> specularMap;
    extractStrandTextureGuidance(origSrc, width, height, confidenceMatte, textureGuidance, shadowMap, specularMap);

    // Stage 6: Physically Plausible Salon Color Transform
    std::vector<uint32_t> colorPixels;
    transformColor(origSrc, width, height, confidenceMatte, textureGuidance, shadowMap, materialParams, colorPixels);

    // Stage 7: Highlight / Shadow Preservation & Anisotropic Specular
    std::vector<uint32_t> specularPixels;
    preserveHighlightsAndShadows(origSrc, colorPixels.data(), width, height, confidenceMatte, specularMap, specularParams, specularPixels);

    // Stage 8: Alpha Compositing with Original
    alphaComposite(origSrc, specularPixels.data(), width, height, confidenceMatte, materialParams.blendIntensity, dstPixels);

    // Stage 9: High-Frequency Strand Texture Micro-Injection
    // Decompose composited image into low-pass base illumination and inject 100% original strand micro-fibers
    if (materialParams.blendIntensity > 0.01f) {
        const int r_box = 3; // 7x7 box filter matching base illumination decomposition
        std::vector<float> origR(width * height), origG(width * height), origB(width * height);
        std::vector<float> baseOrigR(width * height), baseOrigG(width * height), baseOrigB(width * height);
        std::vector<float> compR(width * height), compG(width * height), compB(width * height);
        std::vector<float> baseCompR(width * height), baseCompG(width * height), baseCompB(width * height);

        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < width * height; ++i) {
            uint32_t oc = origSrc[i];
            origR[i] = static_cast<float>(RGBA_R(oc));
            origG[i] = static_cast<float>(RGBA_G(oc));
            origB[i] = static_cast<float>(RGBA_B(oc));

            uint32_t dc = dstPixels[i];
            compR[i] = static_cast<float>(RGBA_R(dc));
            compG[i] = static_cast<float>(RGBA_G(dc));
            compB[i] = static_cast<float>(RGBA_B(dc));
        }

        boxFilter2D(origR.data(), baseOrigR.data(), width, height, r_box);
        boxFilter2D(origG.data(), baseOrigG.data(), width, height, r_box);
        boxFilter2D(origB.data(), baseOrigB.data(), width, height, r_box);

        boxFilter2D(compR.data(), baseCompR.data(), width, height, r_box);
        boxFilter2D(compG.data(), baseCompG.data(), width, height, r_box);
        boxFilter2D(compB.data(), baseCompB.data(), width, height, r_box);

        #pragma omp parallel for schedule(static, 32)
        for (int i = 0; i < width * height; ++i) {
            float conf = confidenceMatte[i];
            if (conf < 0.02f) continue;

            float strandR = origR[i] - baseOrigR[i];
            float strandG = origG[i] - baseOrigG[i];
            float strandB = origB[i] - baseOrigB[i];

            int finalRed = static_cast<int>(std::round(baseCompR[i] + strandR));
            int finalGreen = static_cast<int>(std::round(baseCompG[i] + strandG));
            int finalBlue = static_cast<int>(std::round(baseCompB[i] + strandB));

            dstPixels[i] = PACK_RGBA(
                clampU8(finalRed),
                clampU8(finalGreen),
                clampU8(finalBlue),
                RGBA_A(origSrc[i])
            );
        }
    }

    LOGI("HairPipelineV2: executePipelineV2_Baseline complete. w=%d, h=%d, intensity=%.2f", width, height, materialParams.blendIntensity);

    if (debugStages) {
        debugStages->isBald = false;
        debugStages->rawHairMask = rawMatte;
        debugStages->refinedMatte = refinedMatte;
        debugStages->confidenceMatte = confidenceMatte;
        debugStages->textureGuidance = textureGuidance;
        debugStages->shadowMap = shadowMap;
        debugStages->specularMap = specularMap;
        debugStages->colorTransformed = colorPixels;
        debugStages->specularPreserved = specularPixels;
        debugStages->composited.assign(dstPixels, dstPixels + width * height);
    }

    return true;
}

// Verbatim Pegtop SoftLight kernel from Meitu MTFilter_PsSoftLightr.fs (TASK_062)
static inline float softLightPegtop(float A, float B) {
    if (B <= 0.5f) {
        return (A * B / 0.5f) + A * A * (1.0f - 2.0f * B);
    } else {
        return (A * (1.0f - B) / 0.5f) + std::sqrt(std::max(0.0f, A)) * (2.0f * B - 1.0f);
    }
}

// Rebuilt V3 Pipeline (TASK_035 & TASK_062: Mask Exclusion Clamping + Pegtop SoftLight)
bool HairPipelineV2::executePipelineV3_Rebuild(
    const uint32_t* srcPixels,
    uint32_t* dstPixels,
    int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    const HairDyeMaterialParams& materialParams,
    const HairSpecularParams& specularParams,
    HairV2IntermediateStages* debugStages
) {
    if (!validateInputs(srcPixels, width, height) || !dstPixels) {
        LOGE("HairPipelineV3: Input validation failed!");
        return false;
    }

    // Fast-path bit-exact pass-through if blendIntensity == 0.0f
    if (materialParams.blendIntensity <= 0.0001f) {
        std::memcpy(dstPixels, srcPixels, width * height * sizeof(uint32_t));
        LOGI("HairPipelineV3: Intensity 0.0 - 100%% bit-exact pass-through");
        return true;
    }

    std::vector<uint32_t> origCopy(srcPixels, srcPixels + width * height);
    const uint32_t* origSrc = origCopy.data();

    // 1. BiSeNet 19-class Adaptive Parsing
    std::vector<uint8_t> fullLabels(width * height, 0);
    std::vector<uint8_t> labels512(512 * 512, 0);
    std::vector<float> hairProb512(512 * 512, 0.0f);
    std::vector<float> fullHairProb(width * height, 0.0f);

    bool parseOk = meitu::ai::BiSeNetFaceParser::getInstance().parseFace19Adaptive(
        origSrc, width, height, fullLabels, &labels512, &hairProb512, &fullHairProb
    );
    if (!parseOk) {
        LOGE("HairPipelineV3: Face parsing failed, failing closed (original pass-through)");
        std::memcpy(dstPixels, origSrc, width * height * sizeof(uint32_t));
        return false;
    }

    // 2. Selfie Human Segmentation (if initialized)
    std::vector<float> personProb(width * height, 1.0f);
    std::vector<uint8_t> personBinary(width * height, 255);
    bool hasPersonSeg = false;
    if (meitu::ai::SelfieHumanParser::getInstance().isInitialized()) {
        hasPersonSeg = meitu::ai::SelfieHumanParser::getInstance().segmentPerson(
            origSrc, width, height, personProb, personBinary
        );
    }

    // 3. Anatomical Head & Face Feature Detection
    int min_fx = width, max_fx = 0, min_fy = height, max_fy = 0;
    int feature_px_count = 0;
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            uint8_t lbl = fullLabels[yOff + x];
            // Face skin (1), Brows (2, 3), Eyes (4, 5), Glasses (6), Nose (10), Mouth (11..13)
            if (lbl == 1 || (lbl >= 2 && lbl <= 6) || lbl == 10 || (lbl >= 11 && lbl <= 13)) {
                if (x < min_fx) min_fx = x;
                if (x > max_fx) max_fx = x;
                if (y < min_fy) min_fy = y;
                if (y > max_fy) max_fy = y;
                feature_px_count++;
            }
        }
    }

    float face_cx, face_cy, chin_y, forehead_y, face_w, face_h;
    if (feature_px_count > 100) {
        face_cx = (min_fx + max_fx) * 0.5f;
        face_cy = (min_fy + max_fy) * 0.5f;
        chin_y = static_cast<float>(max_fy);
        face_w = static_cast<float>(max_fx - min_fx);
        face_h = static_cast<float>(max_fy - min_fy);
        forehead_y = static_cast<float>(min_fy) - 0.25f * face_h;
    } else {
        face_cx = width * 0.5f;
        face_cy = height * 0.42f;
        chin_y = height * 0.60f;
        face_w = width * 0.38f;
        face_h = height * 0.36f;
        forehead_y = height * 0.24f;
    }

    // 4. Strict Protected Region Gate & Mask Exclusion Clamping (TASK_062 / MTFilter_HairMaskMix.fs)
    // Non-hair classes: 1=Skin, 2..6=Eyes/Brows/Glasses, 7..9=Ears/Earrings,
    // 10..13=Nose/Mouth/Lips, 14,15=Neck/Necklace, 16=Cloth, 18=Hat
    std::vector<uint8_t> protectedMask(width * height, 0);
    std::vector<float> exclusionMask(width * height, 0.0f);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        float ny = static_cast<float>(y);
        for (int x = 0; x < width; ++x) {
            int idx = yOff + x;
            uint8_t lbl = fullLabels[idx];
            uint32_t c = origSrc[idx];
            int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
            bool isSkin = isHumanSkinPixel(r, g, b);

            // A. Semantic label protection (facial skin, eyes, nose, ears, neck, cloth, hat)
            if (lbl == 1 || (lbl >= 2 && lbl <= 15) || lbl == 16 || lbl == 18) {
                protectedMask[idx] = 1;
                exclusionMask[idx] = 1.0f;
                continue;
            }

            // B. Outside person protection (background)
            if (hasPersonSeg && personProb[idx] < 0.20f) {
                protectedMask[idx] = 1;
                exclusionMask[idx] = 1.0f;
                continue;
            }

            // Top background corners
            if (y < 0.16f * height && (x < 0.20f * width || x > 0.80f * width) && lbl != 17) {
                protectedMask[idx] = 1;
                exclusionMask[idx] = 1.0f;
                continue;
            }

            // C. Direct Skin Protection: strictly exclude any human skin outside cranial scalp
            if (isSkin) {
                // If below eyebrows or outside cranium skull width, 100% protect
                if (ny > min_fy || std::abs(static_cast<float>(x) - face_cx) > face_w * 0.90f) {
                    protectedMask[idx] = 1;
                    exclusionMask[idx] = 1.0f;
                    continue;
                }
            }
        }
    }

    // Mask Exclusion Clamping: Verbatim Meitu HairMaskMix fragment logic (MTFilter_HairMaskMix.fs)
    // float blackvalue = 1.0 - black.r;
    // float val = src.r;
    // if (black.r > 0.0) { if (src.r > blackvalue) val = blackvalue; }
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float rawHair = fullHairProb[i];
        float exclVal = exclusionMask[i];
        float blackValue = 1.0f - exclVal;
        float val = rawHair;
        if (exclVal > 0.0f) {
            if (rawHair > blackValue) {
                val = blackValue;
            }
        }
        if (exclVal >= 0.95f || protectedMask[i]) {
            val = 0.0f;
        }
        fullHairProb[i] = val;
    }

    // 5. Scalp Hair Seed & Appearance Model
    // Scalp cranial crown: top of the head strictly above or near eyebrows (min_fy)
    // Horizontally centered within cranium skull (abs(x - face_cx) <= face_w * 0.95f)
    // This strictly excludes shoulders, chest, arms, and clothing from corrupting the hair seed model.
    float craniumMaxY = static_cast<float>(min_fy) + 0.08f * face_h;
    std::vector<float> seedL, seedA, seedB;
    seedL.reserve(width * 64);
    seedA.reserve(width * 64);
    seedB.reserve(width * 64);

    for (int y = 0; y < height; ++y) {
        if (static_cast<float>(y) > craniumMaxY) break;
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            if (std::abs(static_cast<float>(x) - face_cx) > face_w * 0.95f) continue;
            int idx = yOff + x;
            if (fullLabels[idx] == 17 && !protectedMask[idx] && fullHairProb[idx] > 0.40f) {
                uint32_t c = origSrc[idx];
                float L, a, bCoord;
                sRGBToOKLab(RGBA_R(c) / 255.0f, RGBA_G(c) / 255.0f, RGBA_B(c) / 255.0f, L, a, bCoord);
                seedL.push_back(L);
                seedA.push_back(a);
                seedB.push_back(bCoord);
            }
        }
    }

    // If subject has parted or side hair and crown count is small, relax horizontal bound slightly
    if (seedL.size() < 120) {
        for (int y = 0; y < height; ++y) {
            if (static_cast<float>(y) > chin_y) break;
            int yOff = y * width;
            for (int x = 0; x < width; ++x) {
                if (std::abs(static_cast<float>(x) - face_cx) > face_w * 1.35f) continue;
                int idx = yOff + x;
                if (fullLabels[idx] == 17 && !protectedMask[idx] && fullHairProb[idx] > 0.45f) {
                    uint32_t c = origSrc[idx];
                    float L, a, bCoord;
                    sRGBToOKLab(RGBA_R(c) / 255.0f, RGBA_G(c) / 255.0f, RGBA_B(c) / 255.0f, L, a, bCoord);
                    seedL.push_back(L);
                    seedA.push_back(a);
                    seedB.push_back(bCoord);
                }
            }
        }
    }

    // Bald Safeguard (e.g. Monk negative control): zero alpha output
    if (seedL.size() < 120) {
        LOGI("HairPipelineV3: Bald / negative control subject detected (scalp seeds=%zu). Unmodified pass-through.", seedL.size());
        std::memcpy(dstPixels, origSrc, width * height * sizeof(uint32_t));
        if (debugStages) {
            debugStages->isBald = true;
            debugStages->composited.assign(origSrc, origSrc + width * height);
        }
        return true;
    }

    float mean_hL = 0.0f, mean_ha = 0.0f, mean_hb = 0.0f;
    for (size_t i = 0; i < seedL.size(); ++i) {
        mean_hL += seedL[i];
        mean_ha += seedA[i];
        mean_hb += seedB[i];
    }
    mean_hL /= seedL.size();
    mean_ha /= seedL.size();
    mean_hb /= seedL.size();

    float var_hL = 0.0f, var_ha = 0.0f, var_hb = 0.0f;
    for (size_t i = 0; i < seedL.size(); ++i) {
        var_hL += (seedL[i] - mean_hL) * (seedL[i] - mean_hL);
        var_ha += (seedA[i] - mean_ha) * (seedA[i] - mean_ha);
        var_hb += (seedB[i] - mean_hb) * (seedB[i] - mean_hb);
    }
    float std_hL = std::sqrt(var_hL / seedL.size());
    float std_ha = std::sqrt(var_ha / seedL.size());
    float std_hb = std::sqrt(var_hb / seedL.size());
    float sigmaL = std::clamp(std_hL * 2.2f, 0.06f, 0.16f);

    LOGI("HairPipelineV3: Scalp hair appearance OKLab: L=%.3f+-%.3f, a=%.3f, b=%.3f (seeds=%zu)",
         mean_hL, std_hL, mean_ha, mean_hb, seedL.size());

    // 6. Candidate Hair Validation (Filter out false-positive clothing/arms/shoulders)
    std::vector<uint8_t> hairCandidate(width * height, 0);

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            int idx = yOff + x;
            if (fullLabels[idx] != 17 || protectedMask[idx]) continue;
            if (fullHairProb[idx] < 0.25f) continue;

            bool isCrown = (static_cast<float>(y) <= craniumMaxY) &&
                           (std::abs(static_cast<float>(x) - face_cx) <= face_w * 0.95f);

            uint32_t c = origSrc[idx];
            int cr = RGBA_R(c), cg = RGBA_G(c), cb = RGBA_B(c);

            // Outside immediate cranial crown: validate hair appearance & reject clothing/shoulders
            if (!isCrown) {
                float L, a, bCoord;
                sRGBToOKLab(cr / 255.0f, cg / 255.0f, cb / 255.0f, L, a, bCoord);

                // A. Color Distance in OKLab from cranial scalp hair
                float dL = (L - mean_hL) / sigmaL;
                float da = (a - mean_ha) / 0.08f;
                float db = (bCoord - mean_hb) / 0.08f;
                float d_color = std::sqrt(dL * dL + da * da + db * db);

                // B. Reject sheer/dark clothing when hair is lighter (e.g. Failure Case B blonde vs black sheer)
                if (mean_hL >= 0.22f) {
                    if (L < 0.26f || (cr < 70 && cg < 70 && cb < 70)) {
                        continue;
                    }
                    if (std::abs(L - mean_hL) > 0.28f) {
                        continue;
                    }
                }

                // C. Reject any pixel below chin level that deviates from scalp hair palette
                if (static_cast<float>(y) > chin_y && d_color > 2.20f) {
                    continue;
                }

                // D. General hair color deviation threshold outside crown
                if (d_color > 2.80f) {
                    continue;
                }
            }

            hairCandidate[idx] = 1;
        }
    }

    // Topological reachability from cranial crown seeds
    std::vector<uint8_t> connectedHair(width * height, 0);
    std::queue<int> q;
    for (int y = 0; y < height; ++y) {
        if (static_cast<float>(y) > craniumMaxY) break;
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            if (std::abs(static_cast<float>(x) - face_cx) > face_w * 0.95f) continue;
            int idx = yOff + x;
            if (hairCandidate[idx] && fullHairProb[idx] > 0.45f) {
                connectedHair[idx] = 1;
                q.push(idx);
            }
        }
    }

    // BFS 4-connectivity
    const int dxs[4] = {1, -1, 0, 0};
    const int dys[4] = {0, 0, 1, -1};
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        int cx = cur % width;
        int cy = cur / width;
        for (int d = 0; d < 4; ++d) {
            int nx = cx + dxs[d];
            int ny = cy + dys[d];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                int nidx = ny * width + nx;
                if (hairCandidate[nidx] && !connectedHair[nidx]) {
                    connectedHair[nidx] = 1;
                    q.push(nidx);
                }
            }
        }
    }

    // 7. Edge-Preserving Matting (Trimap + Guided Filter)
    std::vector<float> trimap(width * height, 0.0f);
    std::vector<float> gray(width * height, 0.0f);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = origSrc[i];
        gray[i] = (0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c)) / 255.0f;
        if (protectedMask[i] || !connectedHair[i]) {
            trimap[i] = 0.0f;
        } else if (fullHairProb[i] > 0.65f) {
            trimap[i] = 1.0f;
        } else {
            trimap[i] = 0.5f;
        }
    }

    // Edge-preserving Guided Filter on full-resolution gray guide (r=4, eps=1e-3)
    const int r_guide = 4;
    const float eps = 1e-3f;
    std::vector<float> mean_I(width * height), mean_p(width * height), mean_Ip(width * height), mean_II(width * height);
    std::vector<float> Ip(width * height), II(width * height);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        Ip[i] = gray[i] * trimap[i];
        II[i] = gray[i] * gray[i];
    }

    boxFilter2D(gray.data(), mean_I.data(), width, height, r_guide);
    boxFilter2D(trimap.data(), mean_p.data(), width, height, r_guide);
    boxFilter2D(Ip.data(), mean_Ip.data(), width, height, r_guide);
    boxFilter2D(II.data(), mean_II.data(), width, height, r_guide);

    std::vector<float> a_coeff(width * height), b_coeff(width * height);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float var_I = mean_II[i] - mean_I[i] * mean_I[i];
        float cov_Ip = mean_Ip[i] - mean_I[i] * mean_p[i];
        float ak = cov_Ip / (var_I + eps);
        float bk = mean_p[i] - ak * mean_I[i];
        a_coeff[i] = ak;
        b_coeff[i] = bk;
    }

    std::vector<float> mean_a(width * height), mean_b(width * height);
    boxFilter2D(a_coeff.data(), mean_a.data(), width, height, r_guide);
    boxFilter2D(b_coeff.data(), mean_b.data(), width, height, r_guide);

    std::vector<float> finalAlpha(width * height, 0.0f);
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        if (protectedMask[i]) {
            finalAlpha[i] = 0.0f;
            continue;
        }
        float q = mean_a[i] * gray[i] + mean_b[i];
        float alpha = std::clamp(q, 0.0f, 1.0f) * std::clamp(fullHairProb[i] * 1.25f, 0.0f, 1.0f);
        if (alpha < 0.02f) alpha = 0.0f;
        finalAlpha[i] = alpha;
    }

    // 8. Natural Salon Color Transform via Pegtop SoftLight (TASK_062 / MTFilter_PsSoftLightr.fs)
    float hueRad = materialParams.targetHue * 0.0174532925f; // Deg to Rad
    float targetC = std::clamp(materialParams.targetChroma / 100.0f * 0.28f, 0.0f, 0.35f);
    float targetA = targetC * std::cos(hueRad);
    float targetBCoord = targetC * std::sin(hueRad);
    float targetL = std::clamp(materialParams.targetLightness / 100.0f, 0.05f, 0.95f);

    float targetDyeR, targetDyeG, targetDyeB;
    oklabTosRGB(targetL, targetA, targetBCoord, targetDyeR, targetDyeG, targetDyeB);
    targetDyeR = std::clamp(targetDyeR, 0.0f, 1.0f);
    targetDyeG = std::clamp(targetDyeG, 0.0f, 1.0f);
    targetDyeB = std::clamp(targetDyeB, 0.0f, 1.0f);

    std::vector<float> origR(width * height), origG(width * height), origB(width * height);
    std::vector<float> baseR(width * height), baseG(width * height), baseB(width * height);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint32_t c = origSrc[i];
        origR[i] = RGBA_R(c) / 255.0f;
        origG[i] = RGBA_G(c) / 255.0f;
        origB[i] = RGBA_B(c) / 255.0f;
    }

    // Base illumination map via 2D box filter (r=3, 7x7) for high-frequency cuticle detail
    boxFilter2D(origR.data(), baseR.data(), width, height, 3);
    boxFilter2D(origG.data(), baseG.data(), width, height, 3);
    boxFilter2D(origB.data(), baseB.data(), width, height, 3);

    float intensity = std::clamp(materialParams.blendIntensity, 0.0f, 1.0f);
    float bleachFactor = std::clamp(materialParams.bleachPower * 0.75f, 0.0f, 0.85f);

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float alpha = finalAlpha[i] * intensity;
        if (alpha <= 0.001f || exclusionMask[i] >= 0.95f || protectedMask[i]) {
            dstPixels[i] = origSrc[i];
            continue;
        }

        float r = origR[i];
        float g = origG[i];
        float b = origB[i];

        // A. Stage 0: Pre-Whitening / Melanin Bleach
        float Y = 0.299f * r + 0.587f * g + 0.114f * b;
        float baseDesatR = r * (1.0f - bleachFactor) + Y * bleachFactor;
        float baseDesatG = g * (1.0f - bleachFactor) + Y * bleachFactor;
        float baseDesatB = b * (1.0f - bleachFactor) + Y * bleachFactor;

        // B. Stage 3: Photoshop Pegtop SoftLight Kernel (MTFilter_PsSoftLightr.fs)
        float dyedR = softLightPegtop(baseDesatR, targetDyeR);
        float dyedG = softLightPegtop(baseDesatG, targetDyeG);
        float dyedB = softLightPegtop(baseDesatB, targetDyeB);

        // C. Stage 4: High-frequency Cuticle & Specular Detail Preservation
        float detailR = r - baseR[i];
        float detailG = g - baseG[i];
        float detailB = b - baseB[i];
        dyedR = std::clamp(dyedR + 0.25f * detailR, 0.0f, 1.0f);
        dyedG = std::clamp(dyedG + 0.25f * detailG, 0.0f, 1.0f);
        dyedB = std::clamp(dyedB + 0.25f * detailB, 0.0f, 1.0f);

        // D. Stage 5: Alpha Compositing
        float compR = r * (1.0f - alpha) + dyedR * alpha;
        float compG = g * (1.0f - alpha) + dyedG * alpha;
        float compB = b * (1.0f - alpha) + dyedB * alpha;

        int finalR = clampU8(static_cast<int>(std::round(compR * 255.0f)));
        int finalG = clampU8(static_cast<int>(std::round(compG * 255.0f)));
        int finalB = clampU8(static_cast<int>(std::round(compB * 255.0f)));

        dstPixels[i] = PACK_RGBA(finalR, finalG, finalB, RGBA_A(origSrc[i]));
    }

    LOGI("HairPipelineV3: executePipelineV3_Rebuild complete. w=%d, h=%d, intensity=%.2f", width, height, intensity);

    if (debugStages) {
        debugStages->isBald = false;
        debugStages->rawHairMask = fullHairProb;
        debugStages->refinedMatte = finalAlpha;
        debugStages->confidenceMatte = finalAlpha;
        debugStages->composited.assign(dstPixels, dstPixels + width * height);
    }

    return true;
}

// Full Pipeline Dispatcher
bool HairPipelineV2::executePipelineV2(
    const uint32_t* srcPixels,
    uint32_t* dstPixels,
    int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    const HairDyeMaterialParams& materialParams,
    const HairSpecularParams& specularParams,
    HairV2IntermediateStages* debugStages
) {
    if (!isEnabled() || sHairPipelineVersion == static_cast<int>(Version::VERSION_V1)) {
        LOGI("HairPipelineV2: Dispatching to Version V1 legacy path");
        std::vector<uint32_t> temp(srcPixels, srcPixels + width * height);
        bool ok = meitu_native::HairStrandDyeEngine::applyCustomStrandDye(
            temp.data(), width, height, fused,
            200, 100, 100, materialParams.bleachPower, materialParams.blendIntensity, specularParams.apparentShine
        );
        std::memcpy(dstPixels, temp.data(), width * height * sizeof(uint32_t));
        return ok;
    }

    if (sHairPipelineVersion == static_cast<int>(Version::VERSION_V2_BASELINE)) {
        LOGI("HairPipelineV2: Dispatching to Version V2 baseline path");
        return executePipelineV2_Baseline(srcPixels, dstPixels, width, height, fused, materialParams, specularParams, debugStages);
    }

    // Default V3 Rebuild
    LOGI("HairPipelineV2: Dispatching to Version V3 rebuild path");
    return executePipelineV3_Rebuild(srcPixels, dstPixels, width, height, fused, materialParams, specularParams, debugStages);
}

// Preset-based execution
bool HairPipelineV2::executePresetDyeV2(
    const uint32_t* srcPixels,
    uint32_t* dstPixels,
    int width, int height,
    const MeituReborn::FusedFaceGeometry& fused,
    int presetId,
    float intensity,
    float gloss,
    HairV2IntermediateStages* debugStages
) {
    if (!isEnabled() || sHairPipelineVersion == static_cast<int>(Version::VERSION_V1)) {
        LOGI("HairPipelineV2: executePresetDyeV2 dispatching to Version V1 legacy path");
        std::vector<uint32_t> temp(srcPixels, srcPixels + width * height);
        bool ok = meitu_native::HairStrandDyeEngine::applyStrandDye(
            temp.data(), width, height, fused, presetId, intensity, gloss
        );
        std::memcpy(dstPixels, temp.data(), width * height * sizeof(uint32_t));
        return ok;
    }

    HairDyeMaterialParams mat;
    mat.blendIntensity = std::clamp(intensity, 0.0f, 1.0f);
    mat.shadowPreservation = 0.88f;
    mat.rootStrength = 0.92f;

    HairSpecularParams spec;
    spec.apparentShine = std::clamp(gloss, 0.0f, 1.0f);
    spec.roughness = 0.32f;
    spec.specularTint = 0.15f;
    spec.preserveOriginalGlint = true;

    // Scientifically balanced salon presets
    switch (presetId) {
        case 0: // Natural Black (Deep melanin restore, rich shine)
            mat.targetLightness = 16.0f; mat.targetChroma = 3.5f; mat.targetHue = 35.0f; mat.bleachPower = 0.00f; break;
        case 1: // Chestnut Brown (Warm rich salon brown)
            mat.targetLightness = 36.0f; mat.targetChroma = 30.0f; mat.targetHue = 40.0f; mat.bleachPower = 0.35f; break;
        case 2: // Ash Brown (Cool refined smoky brunette)
            mat.targetLightness = 40.0f; mat.targetChroma = 12.0f; mat.targetHue = 55.0f; mat.bleachPower = 0.42f; break;
        case 3: // Platinum Blonde (High lift tone mapping, no yellow crush)
            mat.targetLightness = 86.0f; mat.targetChroma = 22.0f; mat.targetHue = 75.0f; mat.bleachPower = 0.92f; break;
        case 4: // Smokey Silver (Luminous cool silver, micro-strand preservation)
            mat.targetLightness = 74.0f; mat.targetChroma = 5.0f; mat.targetHue = 220.0f; mat.bleachPower = 0.88f; break;
        case 5: // Rose Gold (Warm pastel gold-rose, zero neon paint)
            mat.targetLightness = 64.0f; mat.targetChroma = 42.0f; mat.targetHue = 18.0f; mat.bleachPower = 0.82f; break;
        case 6: // Wine Burgundy (Deep vampy burgundy, rich shadows)
            mat.targetLightness = 28.0f; mat.targetChroma = 46.0f; mat.targetHue = 355.0f; mat.bleachPower = 0.38f; break;
        case 7: // Peach Lilac (Translucent fairy tone)
            mat.targetLightness = 70.0f; mat.targetChroma = 34.0f; mat.targetHue = 320.0f; mat.bleachPower = 0.85f; break;
        case 8: // Navy Blue (Midnight oceanic sheen)
            mat.targetLightness = 22.0f; mat.targetChroma = 36.0f; mat.targetHue = 245.0f; mat.bleachPower = 0.42f; break;
        case 9: // Caramel Honey (Golden amber salon glaze)
            mat.targetLightness = 54.0f; mat.targetChroma = 44.0f; mat.targetHue = 50.0f; mat.bleachPower = 0.68f; break;
        default:
            mat.targetLightness = 45.0f; mat.targetChroma = 28.0f; mat.targetHue = 35.0f; mat.bleachPower = 0.30f; break;
    }

    return executePipelineV2(srcPixels, dstPixels, width, height, fused, mat, spec, debugStages);
}

} // namespace meitu_native::hce
