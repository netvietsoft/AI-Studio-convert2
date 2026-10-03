#include "hair/hair_pipeline_v2.h"
#include "ai/bisenet_face_parser.h"
#include <android/log.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
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

void HairPipelineV2::setEnabled(bool enabled) {
    sHairPipelineV2Enabled = enabled;
    LOGI("HairPipelineV2: Feature flag set to %d", enabled ? 1 : 0);
}

bool HairPipelineV2::isEnabled() {
    return sHairPipelineV2Enabled;
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

    // Initial matte from class 17 + hat class 18 if color matches hair seed
    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        uint8_t lbl = outFullLabels[i];
        if (lbl == 17) {
            outMatte[i] = 1.0f;
        } else if (lbl == 18) { // HAT/Accessory check
            uint32_t c = srcPixels[i];
            float dr = RGBA_R(c) - seed_r;
            float dg = RGBA_G(c) - seed_g;
            float db = RGBA_B(c) - seed_b;
            float dist = std::sqrt(dr * dr + dg * dg + db * db);
            if (seed_count >= 60 && dist < 32.0f) {
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

    #pragma omp parallel for schedule(static, 32)
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            int idx = yOff + x;
            uint8_t lbl = fullLabels[idx];

            // 1. Strict facial exclusions (zero leakage)
            if (lbl == 1) { // Skin
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }
            if ((lbl >= 2 && lbl <= 5) || lbl == 10 || (lbl >= 11 && lbl <= 13)) {
                // Brows, Eyes, Nose, Mouth/Lips
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }
            if (lbl == 14) { // Neck
                outConfidenceMatte[idx] = 0.0f;
                continue;
            }
            if (lbl == 16) { // Clothing
                // Only allow thin overlapping flyaway strands if refined matte is strong
                if (inMatte[idx] < 0.65f) {
                    outConfidenceMatte[idx] = 0.0f;
                    continue;
                }
            }

            // 2. Ears (lbl == 7, 8)
            if (lbl == 7 || lbl == 8) {
                // Must be strong hair over ear, else 0
                if (inMatte[idx] < 0.70f) {
                    outConfidenceMatte[idx] = 0.0f;
                    continue;
                }
            }

            // 3. Background (lbl == 0)
            if (lbl == 0) {
                // Only allow delicate flyaways directly connected to hair
                if (inMatte[idx] < 0.20f) {
                    outConfidenceMatte[idx] = 0.0f;
                    continue;
                }
            }

            // 4. Hairline pore-level attenuation
            uint32_t c = srcPixels[idx];
            int r = RGBA_R(c);
            int g = RGBA_G(c);
            int b = RGBA_B(c);
            bool isSkin = isHumanSkinPixel(r, g, b);

            float conf = inMatte[idx];
            if (isSkin) {
                // Attenuate skin tone to avoid coloring forehead or hairline pores
                conf *= 0.15f;
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
            // Laplacian high-frequency micro-contrast
            float lap = 4.0f * g - gray[idx - 1] - gray[idx + 1] - gray[idx - width] - gray[idx + width];
            outTextureGuidance[idx] = std::clamp(lap * 2.0f, -0.5f, 0.5f);

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

    #pragma omp parallel for schedule(static, 32)
    for (int i = 0; i < width * height; ++i) {
        float conf = confidenceMatte[i];
        if (conf < 0.01f) continue;

        uint32_t c = srcPixels[i];
        float origR = RGBA_R(c) / 255.0f;
        float origG = RGBA_G(c) / 255.0f;
        float origB = RGBA_B(c) / 255.0f;

        float origL, origOklabA, origOklabB;
        sRGBToOKLab(origR, origG, origB, origL, origOklabA, origOklabB);

        // 1. Physically plausible melanin lift (bleach)
        // Dark hair needs non-linear lift so shadows remain deep and highlights don't blow out
        float liftAmount = targetL - origL;
        float shadowF = shadowMap[i];
        float creviceDepth = std::pow(shadowF, 1.35f) * params.shadowPreservation + (1.0f - params.shadowPreservation);

        float melaninCurve = (origL > 0.0f) ? (0.40f + 0.60f * std::sqrt(origL)) : 0.40f;
        float liftedL = origL + liftAmount * params.bleachPower * melaninCurve * creviceDepth;

        // 2. Strand texture guidance: add micro-contrast back to final lightness
        float microTex = textureGuidance[i];
        float finalL = liftedL + microTex * 0.85f * std::sqrt(std::clamp(origL * (1.0f - origL), 0.01f, 0.25f));
        finalL = std::clamp(finalL, 0.02f, 0.98f);

        // 3. Salon Dye Toner Deposition (Chroma)
        // Rich in midtones, gracefully tapering in deep shadows to prevent flat neon wash
        float midtoneWeight = 4.0f * finalL * (1.0f - finalL);
        float effectiveDyeStrength = std::clamp(0.40f + 0.60f * midtoneWeight, 0.0f, 1.0f) * creviceDepth;

        float finalA = origOklabA * (1.0f - effectiveDyeStrength) + targetA * effectiveDyeStrength;
        float finalB = origOklabB * (1.0f - effectiveDyeStrength) + targetBCoord * effectiveDyeStrength;

        // Convert back to sRGB
        float outR, outG, outB;
        oklabTosRGB(finalL, finalA, finalB, outR, outG, outB);

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

// Full Pipeline V2 End-to-End
bool HairPipelineV2::executePipelineV2(
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

    // Stage 2: Hair Segmentation / Matte
    std::vector<float> rawMatte;
    std::vector<uint8_t> fullLabels;
    bool isBald = false;
    if (!extractHairMatte(srcPixels, width, height, fused, rawMatte, fullLabels, isBald)) {
        LOGE("HairPipelineV2: Hair matte extraction failed!");
        return false;
    }

    // Negative Control: If bald subject, copy src to dst unchanged
    if (isBald) {
        std::memcpy(dstPixels, srcPixels, width * height * sizeof(uint32_t));
        if (debugStages) {
            debugStages->isBald = true;
            debugStages->rawHairMask = rawMatte;
            debugStages->composited.assign(srcPixels, srcPixels + width * height);
        }
        return true;
    }

    // Stage 3: Edge / Hairline Refinement
    std::vector<float> refinedMatte;
    refineHairlineEdges(srcPixels, width, height, rawMatte, fullLabels, refinedMatte);

    // Stage 4: Confidence & Skin/Face/Background Exclusion
    std::vector<float> confidenceMatte;
    applyConfidenceAndExclusion(srcPixels, width, height, fused, fullLabels, refinedMatte, confidenceMatte);

    // Stage 5: Strand / Texture Guidance & Shadow/Specular Maps
    std::vector<float> textureGuidance;
    std::vector<float> shadowMap;
    std::vector<float> specularMap;
    extractStrandTextureGuidance(srcPixels, width, height, confidenceMatte, textureGuidance, shadowMap, specularMap);

    // Stage 6: Physically Plausible Salon Color Transform
    std::vector<uint32_t> colorPixels;
    transformColor(srcPixels, width, height, confidenceMatte, textureGuidance, shadowMap, materialParams, colorPixels);

    // Stage 7: Highlight / Shadow Preservation & Anisotropic Specular
    std::vector<uint32_t> specularPixels;
    preserveHighlightsAndShadows(srcPixels, colorPixels.data(), width, height, confidenceMatte, specularMap, specularParams, specularPixels);

    // Stage 8: Alpha Compositing with Original
    alphaComposite(srcPixels, specularPixels.data(), width, height, confidenceMatte, materialParams.blendIntensity, dstPixels);

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
