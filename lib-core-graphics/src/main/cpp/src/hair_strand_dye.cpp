#include "hair_strand_dye.h"
#include "hair_matting_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG "HairStrandDye"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) |                                ((static_cast<uint32_t>(b) & 0xFF) << 16) |                                ((static_cast<uint32_t>(g) & 0xFF) << 8)  |                                ((static_cast<uint32_t>(r) & 0xFF) << 0))

namespace meitu_native {

static const HairDyePreset sPresets[10] = {
    {"Natural Black",     22,  18,  16,  0.00f, 0.45f},
    {"Chestnut Brown",    98,  58,  36,  0.30f, 0.50f},
    {"Ash Brown",        118,  98,  86,  0.40f, 0.55f},
    {"Platinum Blonde",  238, 222, 172,  0.92f, 0.75f},
    {"Smokey Silver",    192, 198, 210,  0.88f, 0.80f},
    {"Rose Gold",        235, 145, 142,  0.82f, 0.70f},
    {"Wine Burgundy",    125,  22,  44,  0.35f, 0.55f},
    {"Peach Lilac",      240, 165, 195,  0.85f, 0.70f},
    {"Navy Blue",         24,  55, 105,  0.40f, 0.60f},
    {"Caramel Honey",    215, 138,  52,  0.65f, 0.65f}
};

const HairDyePreset& HairStrandDyeEngine::getPreset(int presetId) {
    int idx = std::clamp(presetId, 0, 9);
    return sPresets[idx];
}

bool HairStrandDyeEngine::applyStrandDye(
    uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    int presetId,
    float intensity,
    float gloss
) {
    const HairDyePreset& preset = getPreset(presetId);
    return applyCustomStrandDye(
        pixels, width, height, fused,
        preset.targetR, preset.targetG, preset.targetB,
        preset.bleachPower, intensity, gloss
    );
}

bool HairStrandDyeEngine::applyCustomStrandDye(
    uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    int targetR, int targetG, int targetB,
    float bleachPower,
    float intensity,
    float gloss
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    std::vector<float> alphaMask;
    if (!HairMattingEngine::getInstance().extractFullSizeMatte(pixels, width, height, fused, alphaMask)) {
        LOGI("extractFullSizeMatte returned false");
        return false;
    }

    int total = width * height;
    std::vector<float> lum(total);
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        uint32_t c = pixels[i];
        lum[i] = (0.299f * RGBA_R(c) + 0.587f * RGBA_G(c) + 0.114f * RGBA_B(c));
    }

    std::vector<float> baseLum(total);
    std::vector<float> midLum(total);
    int rWide = std::max(4, static_cast<int>(width * 0.008f));
    int rNarrow = 2;

    std::vector<float> tempWide(total);
    std::vector<float> tempNarrow(total);
    #pragma omp parallel for schedule(static, 16)
    for (int y = 0; y < height; ++y) {
        int yOff = y * width;
        for (int x = 0; x < width; ++x) {
            float sumW = 0.0f; int cntW = 0;
            int xMinW = std::max(0, x - rWide);
            int xMaxW = std::min(width - 1, x + rWide);
            for (int kx = xMinW; kx <= xMaxW; ++kx) { sumW += lum[yOff + kx]; cntW++; }
            tempWide[yOff + x] = sumW / cntW;

            float sumN = 0.0f; int cntN = 0;
            int xMinN = std::max(0, x - rNarrow);
            int xMaxN = std::min(width - 1, x + rNarrow);
            for (int kx = xMinN; kx <= xMaxN; ++kx) { sumN += lum[yOff + kx]; cntN++; }
            tempNarrow[yOff + x] = sumN / cntN;
        }
    }

    #pragma omp parallel for schedule(static, 16)
    for (int y = 0; y < height; ++y) {
        int yMinW = std::max(0, y - rWide);
        int yMaxW = std::min(height - 1, y + rWide);
        int yMinN = std::max(0, y - rNarrow);
        int yMaxN = std::min(height - 1, y + rNarrow);

        for (int x = 0; x < width; ++x) {
            float sumW = 0.0f; int cntW = 0;
            for (int ky = yMinW; ky <= yMaxW; ++ky) { sumW += tempWide[ky * width + x]; cntW++; }
            baseLum[y * width + x] = sumW / cntW;

            float sumN = 0.0f; int cntN = 0;
            for (int ky = yMinN; ky <= yMaxN; ++ky) { sumN += tempNarrow[ky * width + x]; cntN++; }
            midLum[y * width + x] = sumN / cntN;
        }
    }

    float dyeR = targetR / 255.0f;
    float dyeG = targetG / 255.0f;
    float dyeB = targetB / 255.0f;
    float dyeLum = 0.299f * dyeR + 0.587f * dyeG + 0.114f * dyeB;

    float chinLimitY = static_cast<float>(height);
    if (fused.dense478.size() >= 468) {
        chinLimitY = fused.dense478[152].y;
    } else if (fused.anchors106.size() >= 212) {
        chinLimitY = fused.anchors106[16 * 2 + 1];
    }

    float chinX = width * 0.5f;
    float lJawX = width * 0.28f;
    float lJawY = chinLimitY * 0.75f;
    float rJawX = width * 0.72f;
    float rJawY = chinLimitY * 0.75f;
    bool hasJawData = false;

    if (fused.dense478.size() >= 468) {
        chinX = fused.dense478[152].x;
        lJawX = fused.dense478[234].x;
        lJawY = fused.dense478[234].y;
        rJawX = fused.dense478[454].x;
        rJawY = fused.dense478[454].y;
        hasJawData = true;
    } else if (fused.anchors106.size() >= 212) {
        chinX = fused.anchors106[16 * 2];
        lJawX = fused.anchors106[0 * 2];
        lJawY = fused.anchors106[0 * 2 + 1];
        rJawX = fused.anchors106[32 * 2];
        rJawY = fused.anchors106[32 * 2 + 1];
        hasJawData = true;
    }

    float lBrowMinX = static_cast<float>(width), lBrowMaxX = 0.0f;
    float lBrowMinY = static_cast<float>(height), lBrowMaxY = 0.0f;
    float rBrowMinX = static_cast<float>(width), rBrowMaxX = 0.0f;
    float rBrowMinY = static_cast<float>(height), rBrowMaxY = 0.0f;
    bool hasBrowBoxes = false;

    if (fused.anchors106.size() >= 212) {
        for (int b = 33; b <= 41; ++b) {
            float px = fused.anchors106[b * 2];
            float py = fused.anchors106[b * 2 + 1];
            lBrowMinX = std::min(lBrowMinX, px); lBrowMaxX = std::max(lBrowMaxX, px);
            lBrowMinY = std::min(lBrowMinY, py); lBrowMaxY = std::max(lBrowMaxY, py);
        }
        for (int b = 42; b <= 50; ++b) {
            float px = fused.anchors106[b * 2];
            float py = fused.anchors106[b * 2 + 1];
            rBrowMinX = std::min(rBrowMinX, px); rBrowMaxX = std::max(rBrowMaxX, px);
            rBrowMinY = std::min(rBrowMinY, py); rBrowMaxY = std::max(rBrowMaxY, py);
        }
        hasBrowBoxes = true;
    }

    #pragma omp parallel for schedule(dynamic, 64)
    for (int i = 0; i < total; ++i) {
        float rawAlpha = alphaMask[i];
        if (rawAlpha < 0.01f) continue;

        int py = i / width;
        int px = i % width;
        float fpx = static_cast<float>(px);
        float fpy = static_cast<float>(py);

        if (hasBrowBoxes) {
            if ((fpx >= lBrowMinX - 8.0f && fpx <= lBrowMaxX + 8.0f && fpy >= lBrowMinY - 6.0f && fpy <= lBrowMaxY + 6.0f) ||
                (fpx >= rBrowMinX - 8.0f && fpx <= rBrowMaxX + 8.0f && fpy >= rBrowMinY - 6.0f && fpy <= rBrowMaxY + 6.0f)) {
                continue;
            }
        }

        if (hasJawData) {
            float curJawY = chinLimitY;
            if (fpx < lJawX) {
                curJawY = lJawY + (lJawX - fpx) * 0.40f;
            } else if (fpx <= chinX) {
                float t = (fpx - lJawX) / std::max(1.0f, chinX - lJawX);
                curJawY = lJawY + (chinLimitY - lJawY) * std::pow(t, 1.25f);
            } else if (fpx <= rJawX) {
                float t = (fpx - chinX) / std::max(1.0f, rJawX - chinX);
                curJawY = chinLimitY + (rJawY - chinLimitY) * (1.0f - std::pow(1.0f - t, 1.25f));
            } else {
                curJawY = rJawY + (fpx - rJawX) * 0.40f;
            }
            if (fpy >= curJawY - 2.0f) continue;
        } else {
            if (py >= chinLimitY - 2.0f) continue;
        }

        uint32_t origC = pixels[i];
        int origR_int = RGBA_R(origC);
        int origG_int = RGBA_G(origC);
        int origB_int = RGBA_B(origC);
        float origLum = lum[i] / 255.0f;
        float baseL   = baseLum[i] / 255.0f;
        float midL    = midLum[i] / 255.0f;
        float microDetail = origLum - midL;

        if (fpy >= chinLimitY * 0.52f && fpy <= chinLimitY * 0.90f && fpx >= width * 0.32f && fpx <= width * 0.68f) {
            int rbDiff = origR_int - origB_int;
            if (rbDiff >= 20 && origR_int > origG_int && origLum >= 0.38f) {
                continue;
            }
        }

        float origR = origR_int / 255.0f;
        float origG = origG_int / 255.0f;
        float origB = origB_int / 255.0f;
        uint32_t a = RGBA_A(origC);

        // Phase 01F: SHADOW PRESERVATION
        float shadowProt = 1.0f;
        if (baseL < 0.25f) {
            float st = std::clamp((baseL - 0.02f) / 0.23f, 0.0f, 1.0f);
            shadowProt = st * st * (3.0f - 2.0f * st);
        }

        float melaninLift = (1.0f - baseL) * bleachPower * p * 0.75f * shadowProt;
        float liftedBase  = std::clamp(baseL * 0.28f + melaninLift + (dyeLum * 0.35f * p * shadowProt), 0.0f, 0.96f);
        float scale = liftedBase / std::max(0.01f, dyeLum);

        // 3D CURL STRAND MODULATION
        float strandRatio = std::clamp((origLum + 0.04f) / (baseL + 0.04f), 0.68f, 1.48f);

        // DIFFUSE COMPONENT
        float diffuseR = std::clamp(dyeR * scale * strandRatio + microDetail * 0.40f * dyeR, 0.0f, 1.0f);
        float diffuseG = std::clamp(dyeG * scale * strandRatio + microDetail * 0.40f * dyeG, 0.0f, 1.0f);
        float diffuseB = std::clamp(dyeB * scale * strandRatio + microDetail * 0.40f * dyeB, 0.0f, 1.0f);

        // Phase 01G: SPECULAR PRESERVATION
        float specStrength = std::clamp(std::pow(origLum, 2.0f) * (gloss * 1.3f), 0.0f, 0.65f);
        if (microDetail > 0.02f) {
            specStrength = std::clamp(specStrength + microDetail * 0.5f * gloss, 0.0f, 0.75f);
        }

        float specColorR = 1.0f * (1.0f - 0.12f * (1.0f - dyeR));
        float specColorG = 1.0f * (1.0f - 0.12f * (1.0f - dyeG));
        float specColorB = 1.0f * (1.0f - 0.12f * (1.0f - dyeB));

        float recoloredR = std::clamp(diffuseR * (1.0f - specStrength * 0.45f) + specColorR * specStrength, 0.0f, 1.0f);
        float recoloredG = std::clamp(diffuseG * (1.0f - specStrength * 0.45f) + specColorG * specStrength, 0.0f, 1.0f);
        float recoloredB = std::clamp(diffuseB * (1.0f - specStrength * 0.45f) + specColorB * specStrength, 0.0f, 1.0f);

        // Phase 01A: FIX DOUBLE MULTIPLICATION
        float blend = std::clamp(rawAlpha * p, 0.0f, 1.0f);

        float finalR = std::clamp(origR * (1.0f - blend) + recoloredR * blend, 0.0f, 1.0f);
        float finalG = std::clamp(origG * (1.0f - blend) + recoloredG * blend, 0.0f, 1.0f);
        float finalB = std::clamp(origB * (1.0f - blend) + recoloredB * blend, 0.0f, 1.0f);

        pixels[i] = PACK_RGBA(
            static_cast<uint8_t>(finalR * 255.0f),
            static_cast<uint8_t>(finalG * 255.0f),
            static_cast<uint8_t>(finalB * 255.0f),
            a
        );
    }

    LOGI("applyStrandDye (Phase 01 Natural Hair Engine) completed! target RGB=(%d,%d,%d), p=%.2f", targetR, targetG, targetB, p);
    return true;
}

} // namespace meitu_native
