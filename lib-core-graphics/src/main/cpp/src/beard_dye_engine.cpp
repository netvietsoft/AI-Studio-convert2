#include "beard_dye_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>
#include <android/log.h>

#define LOG_TAG "BeardDyeEngine"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

#define RGBA_R(c) (((c) >> 0) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((static_cast<uint32_t>(a) & 0xFF) << 24) | \
                               ((static_cast<uint32_t>(b) & 0xFF) << 16) | \
                               ((static_cast<uint32_t>(g) & 0xFF) << 8)  | \
                               ((static_cast<uint32_t>(r) & 0xFF) << 0))

namespace meitu_native {

// 20 diem moc vien ngoai moi de loai tru tuyet doi long moi
static const int LIPS_OUTER_INDICES[20] = {
    61, 146, 91, 181, 84, 17, 314, 405, 321, 375, 291,
    308, 324, 318, 402, 317, 14, 87, 178, 88
};

// 20 diem moc khe ho long trong mieng (Inner lips aperture - bao ve rang, luoi, khoang mieng khi mo)
static const int INNER_MOUTH_INDICES[20] = {
    78, 191, 80, 81, 82, 13, 312, 311, 310, 415,
    308, 324, 318, 402, 317, 14, 87, 178, 88, 95
};

// 21 diem moc xuong ham chuan tu Mang Tai Trai (234) -> Cam (152) -> Mang Tai Phai (454)
static const int JAWLINE_SPINE[21] = {
    234,  // 0: mang tai trai (tragus)
    93,   // 1: canh dung tren trai
    132,  // 2: canh dung duoi trai
    58,   // 3: goc ham tren trai
    172,  // 4: goc ham duoi trai (mandibular angle)
    136,  // 5: than ham sau trai
    150,  // 6: than ham giua trai
    149,  // 7: than ham truoc trai
    176,  // 8: canh cam trai
    148,  // 9: goc duoi cam trai
    152,  // 10: dinh cam thap nhat (menton)
    377,  // 11: goc duoi cam phai
    400,  // 12: canh cam phai
    378,  // 13: than ham truoc phai
    379,  // 14: than ham giua phai
    365,  // 15: than ham sau phai
    397,  // 16: goc ham duoi phai (mandibular angle)
    288,  // 17: goc ham tren phai
    361,  // 18: canh dung duoi phai
    323,  // 19: canh dung tren phai
    454   // 20: mang tai phai (tragus)
};

static inline bool isInsidePolygon(float x, float y, const std::vector<MeituReborn::Point3D>& poly) {
    bool inside = false;
    size_t n = poly.size();
    if (n < 3) return false;
    for (size_t i = 0, j = n - 1; i < n; j = i++) {
        float xi = poly[i].x, yi = poly[i].y;
        float xj = poly[j].x, yj = poly[j].y;
        if (((yi > y) != (yj > y)) && (x < (xj - xi) * (y - yi) / (yj - yi + 1e-6f) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}

static inline float smoothStep(float edge0, float edge1, float x) {
    float t = std::clamp((x - edge0) / (edge1 - edge0 + 1e-6f), 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

// 1. Noi suy Y cua vien tren moi tren tai toa do X (Cupid's bow curvature)
static inline float getUpperLipTopY(float x, const MeituReborn::FusedFaceGeometry& fused) {
    static const int LIP_TOP_PTS[11] = { 61, 185, 40, 39, 37, 0, 267, 269, 270, 409, 291 };
    float xMin = fused.dense478[61].x;
    float xMax = fused.dense478[291].x;
    if (x <= xMin) return fused.dense478[61].y;
    if (x >= xMax) return fused.dense478[291].y;

    for (int i = 0; i < 10; ++i) {
        float xA = fused.dense478[LIP_TOP_PTS[i]].x;
        float xB = fused.dense478[LIP_TOP_PTS[i + 1]].x;
        float yA = fused.dense478[LIP_TOP_PTS[i]].y;
        float yB = fused.dense478[LIP_TOP_PTS[i + 1]].y;
        float lo = std::min(xA, xB);
        float hi = std::max(xA, xB);
        if (x >= lo && x <= hi) {
            float t = (x - xA) / (xB - xA + 1e-6f);
            return yA + t * (yB - yA);
        }
    }
    return fused.dense478[0].y;
}

// 2. Noi suy Y cua vien duoi moi duoi tai toa do X
static inline float getLowerLipBottomY(float x, const MeituReborn::FusedFaceGeometry& fused) {
    static const int LIP_BOT_PTS[11] = { 61, 146, 91, 181, 84, 17, 314, 405, 321, 375, 291 };
    float xMin = fused.dense478[61].x;
    float xMax = fused.dense478[291].x;
    if (x <= xMin) return fused.dense478[61].y;
    if (x >= xMax) return fused.dense478[291].y;

    for (int i = 0; i < 10; ++i) {
        float xA = fused.dense478[LIP_BOT_PTS[i]].x;
        float xB = fused.dense478[LIP_BOT_PTS[i + 1]].x;
        float yA = fused.dense478[LIP_BOT_PTS[i]].y;
        float yB = fused.dense478[LIP_BOT_PTS[i + 1]].y;
        float lo = std::min(xA, xB);
        float hi = std::max(xA, xB);
        if (x >= lo && x <= hi) {
            float t = (x - xA) / (xB - xA + 1e-6f);
            return yA + t * (yB - yA);
        }
    }
    return fused.dense478[17].y;
}

// 3. Noi suy Y cua chan mui tai toa do X (vach ngan, canh mui trai va phai)
static inline float getNoseBottomY(float x, const MeituReborn::FusedFaceGeometry& fused) {
    if (fused.dense478.size() < 468) {
        if (fused.anchors106.size() >= 106 * 2) {
            float xL = fused.anchors106[48 * 2], yL = fused.anchors106[48 * 2 + 1];
            float xM = fused.anchors106[49 * 2], yM = fused.anchors106[49 * 2 + 1];
            float xR = fused.anchors106[50 * 2], yR = fused.anchors106[50 * 2 + 1];
            if (x <= xL) return yL;
            if (x >= xR) return yR;
            if (x <= xM) return yL + (x - xL) / (xM - xL + 1e-6f) * (yM - yL);
            return yM + (x - xM) / (xR - xM + 1e-6f) * (yR - yM);
        }
        return 0.0f;
    }

    float xL = fused.dense478[98].x,  yL = fused.dense478[98].y;
    float xM = fused.dense478[2].x,   yM = fused.dense478[2].y;
    float xR = fused.dense478[327].x, yR = fused.dense478[327].y;

    if (fused.dense478.size() > 164) yM = std::max(yM, fused.dense478[164].y);
    if (fused.dense478.size() > 97)  yL = std::max(yL, fused.dense478[97].y);
    if (fused.dense478.size() > 60)  yL = std::max(yL, fused.dense478[60].y);
    if (fused.dense478.size() > 99)  yL = std::max(yL, fused.dense478[99].y);
    if (fused.dense478.size() > 326) yR = std::max(yR, fused.dense478[326].y);
    if (fused.dense478.size() > 290) yR = std::max(yR, fused.dense478[290].y);
    if (fused.dense478.size() > 328) yR = std::max(yR, fused.dense478[328].y);

    if (x <= xL) return yL;
    if (x >= xR) return yR;
    if (x <= xM) {
        float t = (x - xL) / (xM - xL + 1e-6f);
        return yL + t * (yM - yL);
    } else {
        float t = (x - xM) / (xR - xM + 1e-6f);
        return yM + t * (yR - yM);
    }
}

// 4. Tinh toan hat chan rau vi mo da huong tu nhien (khong ke soc ma vach)
static inline float computeOrganicFollicleFill(
    float x, float y,
    float tangentX, float tangentY,
    float thickness,
    float baseZoneWeight
) {
    // Toa do doc theo huong moc rau u va vuong goc v
    float u = x * tangentX + y * tangentY;
    float v = -x * tangentY + y * tangentX;

    float density = std::clamp(thickness, 0.4f, 2.2f);

    // Cac song vi mo da huong tao texture chan rau vo dinh hinh
    float g1 = std::sin(v * 1.15f * density + std::sin(u * 0.42f) * 1.8f);
    float g2 = std::cos(u * 1.35f * density - std::cos(v * 0.55f) * 1.6f);
    float g3 = std::sin((u + v) * 2.1f * density + g1 * 1.2f);

    // Cham chan rau li ti (follicle pores)
    float dotU = std::sin(u * 2.8f * density);
    float dotV = std::sin(v * 3.4f * density);
    float follicleDots = std::max(0.0f, dotU * dotV);

    float organic = 0.50f + 0.22f * g1 + 0.18f * g2 + 0.10f * g3 + 0.15f * follicleDots;
    organic = std::clamp(organic, 0.0f, 1.0f);

    // Tang bong chan rau (Root Shading Fill) chiem 70% - 85% de rau FILL DAY DAN, khong bi lo vet da trang
    float solidRootShade = std::clamp(0.68f + 0.22f * (thickness - 1.0f), 0.55f, 0.90f);
    float textureMod = solidRootShade + (1.0f - solidRootShade) * organic;

    return baseZoneWeight * std::clamp(textureMod, 0.0f, 1.0f);
}

bool BeardDyeEngine::extractBeardFiberMask(
    const uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    std::vector<float>& outFiberMask,
    std::vector<bool>& outIsGrayFiber,
    float thickness,
    float heightOffset,
    float widthScale,
    int beardStyle,
    float horizontalOffset
) {
    int total = width * height;
    outFiberMask.assign(total, 0.0f);
    outIsGrayFiber.assign(total, false);

    if (fused.dense478.size() < 468) {
        LOGI("fused.dense478 not available for strict anatomical beard extraction");
        return false;
    }

    // 1. DA GIAC LOAI TRU 100% LONG MOI
    std::vector<MeituReborn::Point3D> lipsPoly;
    lipsPoly.reserve(20);
    for (int idx : LIPS_OUTER_INDICES) {
        lipsPoly.push_back(fused.dense478[idx]);
    }

    // 2. CAC TOA DO VA VECTOR HE QUY CHIEU 3D KHUON MAT
    float chinTipY    = fused.dense478[152].y;
    float noseBaseY   = fused.dense478[2].y;
    float mouthLeftX  = fused.dense478[61].x;
    float mouthRightX = fused.dense478[291].x;
    float mouthWidth  = std::max(40.0f, mouthRightX - mouthLeftX);
    float cupidBowX   = fused.dense478[0].x + horizontalOffset;
    float cupidBowY   = fused.dense478[0].y;
    float faceHeight  = std::max(60.0f, chinTipY - fused.dense478[10].y);
    float faceCenterX = fused.dense478[1].x;
    float faceCenterY = fused.dense478[1].y;

    // Khoang cach nhan trung tai trung tam (tu chan mui xuong dinh moi tren)
    float philtrumCenterHeight = std::max(16.0f, cupidBowY - noseBaseY);

    // Vector truc doc khuon mat V (giua hai mat -> cam)
    float midEyeX = (fused.dense478[133].x + fused.dense478[362].x) * 0.5f;
    float midEyeY = (fused.dense478[133].y + fused.dense478[362].y) * 0.5f;
    float vDirX = fused.dense478[152].x - midEyeX;
    float vDirY = fused.dense478[152].y - midEyeY;
    float vLen = std::sqrt(vDirX * vDirX + vDirY * vDirY + 1e-6f);
    vDirX /= vLen; vDirY /= vLen;

    // Vector truc ngang khuon mat U (vuong goc voi V huong sang ma phai)
    float uDirX = -vDirY;
    float uDirY =  vDirX;

    // Uoc luong goc quay ngang Yaw cua mat (-0.6 .. +0.6) tu vi tri mang tai
    float distToLeftJaw  = std::hypot(fused.dense478[234].x - faceCenterX, fused.dense478[234].y - faceCenterY);
    float distToRightJaw = std::hypot(fused.dense478[454].x - faceCenterX, fused.dense478[454].y - faceCenterY);
    float yawBias = std::clamp((distToRightJaw - distToLeftJaw) / (distToRightJaw + distToLeftJaw + 1e-5f), -0.6f, 0.6f);

    // RAO CHAN VAT LY TUYET DOI KHAC PHUC LOI LAN XUONG CO / XUONG QUAI XANH
    float maxNeckCutoffY = chinTipY + 4.0f;

    // Chieu rong dai rau quai non om sat vien xuong ham
    float baseBandWidth = std::clamp(faceHeight * 0.048f, 14.0f, 22.0f);
    float maxBandWidth  = baseBandWidth * widthScale;

    int minX = std::max(0, static_cast<int>(std::min(fused.dense478[234].x, fused.dense478[127].x) - 10.0f));
    int maxX = std::min(width - 1, static_cast<int>(std::max(fused.dense478[454].x, fused.dense478[356].x) + 10.0f));
    int minY = std::max(0, static_cast<int>(noseBaseY - 4.0f));
    int maxY = std::min(height - 1, static_cast<int>(maxNeckCutoffY));

    // 3. MAU DA THAM CHIEU CUC BO
    float refSkinR = 210.0f, refSkinG = 160.0f, refSkinB = 140.0f;
    {
        int cx = std::clamp(static_cast<int>(fused.dense478[118].x), 0, width - 1);
        int cy = std::clamp(static_cast<int>(fused.dense478[118].y), 0, height - 1);
        uint32_t sc = pixels[cy * width + cx];
        refSkinR = RGBA_R(sc);
        refSkinG = RGBA_G(sc);
        refSkinB = RGBA_B(sc);
    }
    float refSkinLum = 0.299f * refSkinR + 0.587f * refSkinG + 0.114f * refSkinB;

    bool allowMustache = (beardStyle == BEARD_STYLE_FULL || beardStyle == BEARD_STYLE_MUSTACHE_GOATEE || beardStyle == BEARD_STYLE_MUSTACHE_ONLY);
    bool allowGoatee   = (beardStyle == BEARD_STYLE_FULL || beardStyle == BEARD_STYLE_MUSTACHE_GOATEE || beardStyle == BEARD_STYLE_GOATEE_ONLY);
    bool allowChinstrap = (beardStyle == BEARD_STYLE_FULL);

    // 4. QUET VUNG RAU QUAI NON, RIA MEP VA RAU CAM (DA LUONG OPENMP)
    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = minY; y <= maxY; ++y) {
        float fy = static_cast<float>(y);
        if (fy > maxNeckCutoffY) continue;

        for (int x = minX; x <= maxX; ++x) {
            float fx = static_cast<float>(x);
            int idx = y * width + x;

            // 4.1. LOAI TRU 100% LONG MOI
            if (isInsidePolygon(fx, fy, lipsPoly)) {
                continue;
            }

            float zoneWeight = 0.0f;
            float tangentX = 1.0f, tangentY = 0.0f;

            // 4.2. VUNG A: RIA MEP (Mustache) - Duoi mui & tren mep moi tren
            // THICH UNG 3D POSE / YAW THEO TOA DO CHUAN HOA u (-1.0 .. +1.0)
            if (allowMustache) {
                float lipTopAtX = getUpperLipTopY(fx, fused);

                // Chuan hoa vi tri x doc theo khuon mieng (u = -1 tai mep trai 61, 0 tai giua 0, +1 tai mep phai 291)
                float u = 0.0f;
                if (fx < cupidBowX) {
                    u = (fx - cupidBowX) / (cupidBowX - mouthLeftX + 1e-5f); // [-1, 0]
                } else {
                    u = (fx - cupidBowX) / (mouthRightX - cupidBowX + 1e-5f); // [0, 1]
                }

                // Gioi han do rong ria mep theo thang dieu chinh widthScale
                float effectiveWidth = std::max(0.50f, widthScale);
                float normU = std::abs(u) / effectiveWidth;

                if (normU <= 1.0f) {
                    // ABSOLUTE NOSE & NOSTRIL EXCLUSION SHIELD (HÀNG RÀO BẢO VỆ LỖ MŨI 100%)
                    float yNoseBase = getNoseBottomY(fx, fused);
                    float distFromCenter = std::abs(fx - cupidBowX);
                    float nostrilHalfW = std::max(16.0f, mouthWidth * 0.28f);
                    float relNostrilX = distFromCenter / nostrilHalfW;
                    float nostrilArch = (relNostrilX <= 1.2f) ? std::sin(std::clamp(relNostrilX, 0.0f, 1.0f) * 3.14159f) : 0.0f;
                    float clearanceFactor = 0.28f + 0.14f * nostrilArch;
                    float noseShieldMargin = std::max(16.0f, philtrumCenterHeight * clearanceFactor);
                    float noseCutoffY = yNoseBase + noseShieldMargin;

                    if (fy <= noseCutoffY) {
                        continue; // KHU VỰC BẢO VỆ TUYỆT ĐỐI: LỖ MŨI VÀ VÙNG SÁT MŨI
                    }

                    // Duong bien tren cua ria mep: uon cong tu nhien duoi chan mui xuong mep
                    float tFold = smoothStep(0.35f, 1.0f, std::abs(u));
                    float yCornerTop = lipTopAtX - std::max(6.0f, philtrumCenterHeight * 0.22f);
                    float mustacheTopRaw = (1.0f - tFold) * noseCutoffY + tFold * yCornerTop;

                    float philtrumGap = std::max(10.0f, lipTopAtX - mustacheTopRaw);

                    float baseNoseMargin = std::max(2.0f, philtrumGap * 0.08f);
                    float baseLipMargin  = std::max(5.0f, philtrumGap * 0.20f);

                    float effOffset = std::clamp(heightOffset, -(baseLipMargin - 3.5f), (philtrumGap * 0.22f));
                    float mustacheTop = mustacheTopRaw + (baseNoseMargin - effOffset);
                    float mustacheBot = lipTopAtX  - (baseLipMargin  + effOffset);

                    // Dieu chinh do day mong (thickness) cua ria mep
                    float midY = (mustacheTop + mustacheBot) * 0.5f;
                    float halfH = (mustacheBot - mustacheTop) * 0.5f;
                    float effHalfH = halfH * std::clamp(0.40f + 0.60f * thickness, 0.35f, 1.0f);

                    if (effHalfH > 1.0f && std::abs(fy - midY) <= effHalfH) {
                        float normY = std::abs(fy - midY) / effHalfH;
                        float fadeY = std::cos(normY * 1.5707963f);
                        float fadeX = 1.0f - smoothStep(0.70f, 1.0f, normU);

                        // Feathering mem mai ngay duoi hang rao chan lo mui (6px)
                        float noseDist = fy - noseCutoffY;
                        float noseFade = std::clamp(noseDist / 6.0f, 0.0f, 1.0f);

                        float wMustache = fadeX * fadeY * noseFade;
                        if (wMustache > zoneWeight) {
                            zoneWeight = wMustache;
                            // Huong moc soi rau ria mep: tu giua nhan trung ru nhe toa sang 2 ben khoe mieng
                            float sideSign = (u >= 0.0f) ? 1.0f : -1.0f;
                            tangentX = uDirX + 0.35f * sideSign * std::abs(u);
                            tangentY = uDirY + 0.25f * sideSign * std::abs(u);
                            float tLen = std::sqrt(tangentX * tangentX + tangentY * tangentY + 1e-6f);
                            tangentX /= tLen;
                            tangentY /= tLen;
                        }
                    }
                }
            }

            // 4.3. VUNG B: CHOM RAU CAM DUOI MOI (Goatee / Soul Patch & Chin Beard)
            // Nhap vung rau cam dang hinh khoi chu nhat / hinh thang loe nhe (chuan theo hinh ve nguoi dung)
            if (allowGoatee) {
                float lipBotAtX = getLowerLipBottomY(fx, fused);

                // Khoang dem an toan duoi moi duoi: khong de len vien moi duoi
                float lowerLipMargin = std::max(4.0f, faceHeight * 0.024f) - heightOffset * 0.5f;
                lowerLipMargin = std::max(3.2f, lowerLipMargin);

                float goateeTop = lipBotAtX + lowerLipMargin;
                float goateeBot = chinTipY + 2.0f;

                if (fy >= goateeTop && fy <= goateeBot) {
                    float yProgress = (fy - goateeTop) / (goateeBot - goateeTop + 1e-6f);

                    // Do rong chom rau cam: phu tu soul patch duoi moi xuong tron ven cam (~44% do rong mieng)
                    float mouthWidth = (mouthRightX - mouthLeftX);
                    // Duoi moi duoi rong 34%, xuong cam loe ra 48% tao hinh khoi rau cam day dan
                    float flareFactor = 0.34f + 0.16f * yProgress;
                    float baseHalfWidth = mouthWidth * 0.5f * flareFactor * widthScale;

                    // Thich ung goc quay 3D Yaw
                    float dxFace = fx - (faceCenterX + horizontalOffset);
                    float sideSign = (dxFace >= 0.0f) ? 1.0f : -1.0f;
                    float yawFactorGoatee = 1.0f + sideSign * (yawBias * 0.65f);
                    float effectiveHalfWidth = baseHalfWidth * std::clamp(yawFactorGoatee, 0.60f, 1.40f);

                    if (std::abs(dxFace) <= effectiveHalfWidth) {
                        float normX = std::abs(dxFace) / effectiveHalfWidth;
                        float fadeX = std::cos(normX * 1.5707963f); // Bien mo tu nhien sang 2 ben
                        float fadeY = smoothStep(0.0f, 0.10f, yProgress);
                        if (fy > chinTipY - 3.0f) {
                            fadeY *= (1.0f - smoothStep(0.0f, 5.0f, fy - (chinTipY - 3.0f)));
                        }

                        float wGoatee = fadeX * fadeY;
                        if (wGoatee > zoneWeight) {
                            zoneWeight = wGoatee;
                            tangentX = vDirX + 0.12f * sideSign * normX;
                            tangentY = vDirY;
                            float tLen = std::sqrt(tangentX * tangentX + tangentY * tangentY + 1e-6f);
                            tangentX /= tLen;
                            tangentY /= tLen;
                        }
                    }
                }
            }

            // 4.4. VUNG C: DAI RAU QUAI NON (Chinstrap Ribbon Band om sat vien xuong ham)
            // Chi ap dung khi beardStyle == BEARD_STYLE_FULL
            if (allowChinstrap && zoneWeight < 1.0f && fy >= fused.dense478[234].y) {
                float minDistSq = 1e9f;
                int bestSegment = -1;
                float bestT = 0.0f;

                for (int s = 0; s < 20; ++s) {
                    const auto& pA = fused.dense478[JAWLINE_SPINE[s]];
                    const auto& pB = fused.dense478[JAWLINE_SPINE[s + 1]];
                    float abx = pB.x - pA.x;
                    float aby = pB.y - pA.y;
                    float apx = fx - pA.x;
                    float apy = fy - pA.y;
                    float abLenSq = abx * abx + aby * aby;
                    if (abLenSq < 1e-4f) continue;
                    float t = std::clamp((apx * abx + apy * aby) / abLenSq, 0.0f, 1.0f);
                    float qx = pA.x + t * abx;
                    float qy = pA.y + t * aby;
                    float dx = fx - qx;
                    float dy = fy - qy;
                    float dSq = dx * dx + dy * dy;
                    if (dSq < minDistSq) {
                        minDistSq = dSq;
                        bestSegment = s;
                        bestT = t;
                    }
                }

                if (bestSegment >= 0 && minDistSq <= (maxBandWidth * maxBandWidth)) {
                    const auto& pA = fused.dense478[JAWLINE_SPINE[bestSegment]];
                    const auto& pB = fused.dense478[JAWLINE_SPINE[bestSegment + 1]];
                    float segVx = pB.x - pA.x;
                    float segVy = pB.y - pA.y;
                    float segLen = std::sqrt(segVx * segVx + segVy * segVy + 1e-6f);
                    float qx = pA.x + bestT * segVx;
                    float qy = pA.y + bestT * segVy;

                    float inDirX = faceCenterX - qx;
                    float inDirY = faceCenterY - qy;
                    float inDirLen = std::sqrt(inDirX * inDirX + inDirY * inDirY + 1e-6f);
                    inDirX /= inDirLen;
                    inDirY /= inDirLen;

                    float px = fx - qx;
                    float py = fy - qy;
                    float dInward = px * inDirX + py * inDirY;

                    if (dInward >= -3.5f && dInward <= maxBandWidth) {
                        float bandNorm = std::clamp(dInward / maxBandWidth, 0.0f, 1.0f);
                        float wJaw = 1.0f - smoothStep(0.65f, 1.0f, bandNorm);
                        if (dInward < 0.0f) {
                            wJaw *= (1.0f - (-dInward / 3.5f));
                        }
                        if (wJaw > zoneWeight) {
                            zoneWeight = wJaw;
                            tangentX = segVx / segLen;
                            tangentY = segVy / segLen;
                        }
                    }
                }
            }

            if (zoneWeight <= 0.01f) continue;

            // 4.5. TAO LOP PHU RAU TU NHIEN (FILL VAO DEU DAN & HAT CHAN RAU VI MO)
            // Triet tieu hoan toan hien tuong ke soc ban cao / ma vach
            float combinedDensity = computeOrganicFollicleFill(fx, fy, tangentX, tangentY, thickness, zoneWeight);

            // Phan loai soi bac & soi rau thuong
            uint32_t c = pixels[idx];
            float r = RGBA_R(c);
            float g = RGBA_G(c);
            float b = RGBA_B(c);
            float lum = 0.299f * r + 0.587f * g + 0.114f * b;
            float maxC = std::max({r, g, b});
            float minC = std::min({r, g, b});
            float sat = (maxC > 0.001f) ? ((maxC - minC) / maxC) : 0.0f;

            if (sat < 0.12f && lum > refSkinLum - 10.0f && std::abs(r - g) < 12 && std::abs(g - b) < 12) {
                outFiberMask[idx] = zoneWeight * 0.88f;
                outIsGrayFiber[idx] = true;
            } else {
                outFiberMask[idx] = combinedDensity;
            }
        }
    }

    LOGI("extractBeardFiberMask completed (style=%d, pose-aware, clean philtrum, wide goatee, thickness=%.2f, offset=%.2f, width=%.2f)",
         beardStyle, thickness, heightOffset, widthScale);
    return true;
}

bool BeardDyeEngine::applyGrayAway(
    uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    float intensity,
    float thickness,
    float heightOffset,
    float widthScale,
    int beardStyle
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    std::vector<float> fiberMask;
    std::vector<bool> isGray;
    if (!extractBeardFiberMask(pixels, width, height, fused, fiberMask, isGray, thickness, heightOffset, widthScale, beardStyle, 0.0f)) return false;

    int total = width * height;
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        if (!isGray[i]) continue;
        float alpha = fiberMask[i] * p * 0.90f;
        if (alpha < 0.02f) continue;

        uint32_t c = pixels[i];
        int r = RGBA_R(c);
        int g = RGBA_G(c);
        int b = RGBA_B(c);
        uint32_t a = RGBA_A(c);

        int targetR = 24;
        int targetG = 20;
        int targetB = 18;

        int finalR = static_cast<int>(r * (1.0f - alpha) + targetR * alpha);
        int finalG = static_cast<int>(g * (1.0f - alpha) + targetG * alpha);
        int finalB = static_cast<int>(b * (1.0f - alpha) + targetB * alpha);

        pixels[i] = PACK_RGBA(finalR, finalG, finalB, a);
    }

    LOGI("applyGrayAway completed successfully! style=%d", beardStyle);
    return true;
}

bool BeardDyeEngine::applyBeardDye(
    uint32_t* pixels,
    int width,
    int height,
    const MeituReborn::FusedFaceGeometry& fused,
    int targetR, int targetG, int targetB,
    float intensity,
    float thickness,
    float heightOffset,
    float widthScale,
    int beardStyle,
    float horizontalOffset
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);

    std::vector<float> fiberMask;
    std::vector<bool> isGray;
    if (!extractBeardFiberMask(pixels, width, height, fused, fiberMask, isGray, thickness, heightOffset, widthScale, beardStyle, horizontalOffset)) return false;

    int total = width * height;
    #pragma omp parallel for schedule(static, 1024)
    for (int i = 0; i < total; ++i) {
        float alpha = fiberMask[i] * p * 0.90f;
        if (alpha < 0.02f) continue;

        uint32_t c = pixels[i];
        int r = RGBA_R(c);
        int g = RGBA_G(c);
        int b = RGBA_B(c);
        uint32_t a = RGBA_A(c);

        float origLum = (0.299f * r + 0.587f * g + 0.114f * b) / 255.0f;
        float scale = std::clamp(origLum * 1.15f, 0.45f, 1.25f);

        int dyedR = std::clamp(static_cast<int>(targetR * scale), 0, 255);
        int dyedG = std::clamp(static_cast<int>(targetG * scale), 0, 255);
        int dyedB = std::clamp(static_cast<int>(targetB * scale), 0, 255);

        int finalR = static_cast<int>(r * (1.0f - alpha) + dyedR * alpha);
        int finalG = static_cast<int>(g * (1.0f - alpha) + dyedG * alpha);
        int finalB = static_cast<int>(b * (1.0f - alpha) + dyedB * alpha);

        pixels[i] = PACK_RGBA(finalR, finalG, finalB, a);
    }

    LOGI("applyBeardDye completed! style=%d, target RGB=(%d,%d,%d), p=%.2f, thickness=%.2f, offset=%.2f, width=%.2f",
         beardStyle, targetR, targetG, targetB, p, thickness, heightOffset, widthScale);
    return true;
}

bool BeardDyeEngine::applyPresetBeard(
    uint32_t* pixels,
    int width,
    int height,
    const uint32_t* beardPixels,
    int beardWidth,
    int beardHeight,
    const MeituReborn::FusedFaceGeometry& fused,
    float intensity,
    int targetR, int targetG, int targetB,
    bool isDyeActive,
    float thickness,
    float heightOffset,
    float widthScale,
    float horizontalOffset
) {
    if (!pixels || width <= 0 || height <= 0 || !beardPixels || beardWidth <= 0 || beardHeight <= 0) {
        return false;
    }
    if (fused.dense478.size() < 468) {
        LOGI("fused.dense478 not available for preset beard warp");
        return false;
    }

    float p = std::clamp(intensity, 0.0f, 1.0f);
    if (p <= 0.001f) return true;

    // 1. Khe ho long trong mieng (bao ve rang, luoi, khoang mieng khi mo he)
    std::vector<MeituReborn::Point3D> innerMouthPoly;
    innerMouthPoly.reserve(20);
    for (int idx : INNER_MOUTH_INDICES) {
        innerMouthPoly.push_back(fused.dense478[idx]);
    }

    // 2. Face anchor points from 478 dense landmarks
    float mouthLeftX  = fused.dense478[61].x,  mouthLeftY  = fused.dense478[61].y;
    float mouthRightX = fused.dense478[291].x, mouthRightY = fused.dense478[291].y;
    float upperLipX   = fused.dense478[0].x,   upperLipY   = fused.dense478[0].y;
    float lowerLipX   = fused.dense478[17].x,  lowerLipY   = fused.dense478[17].y;
    float noseBaseX   = fused.dense478[2].x,   noseBaseY   = fused.dense478[2].y;
    float chinTipX    = fused.dense478[152].x, chinTipY    = fused.dense478[152].y;

    // Destination mouth center and orientation vectors
    float mouthCenterX = (upperLipX + lowerLipX) * 0.5f;
    float mouthCenterY = (upperLipY + lowerLipY) * 0.5f;

    // Vector along mouth width (horizontal)
    float uDirX = mouthRightX - mouthLeftX;
    float uDirY = mouthRightY - mouthLeftY;
    float mouthWidth = std::sqrt(uDirX * uDirX + uDirY * uDirY + 1e-6f);
    uDirX /= mouthWidth; uDirY /= mouthWidth;

    // Vector perpendicular to mouth towards chin (vertical)
    float vDirX = chinTipX - noseBaseX;
    float vDirY = chinTipY - noseBaseY;
    float chinSpan = std::sqrt(vDirX * vDirX + vDirY * vDirY + 1e-6f);
    vDirX /= chinSpan; vDirY /= chinSpan;

    // Destination vertical spans along face vertical axis
    float destPhiltrum = std::max(18.0f, std::abs((upperLipX - noseBaseX) * vDirX + (upperLipY - noseBaseY) * vDirY));
    float destLipHalfH = std::max(8.0f,  std::abs((upperLipX - mouthCenterX) * vDirX + (upperLipY - mouthCenterY) * vDirY));
    float destChinSpan = std::max(30.0f, std::abs((chinTipX - lowerLipX) * vDirX + (chinTipY - lowerLipY) * vDirY));

    // 3. Dynamic Auto-Calibration of the Source Beard Template (runs in <0.05ms)
    float srcMouthCenterX = beardWidth * 0.5f;
    float srcMouthCenterY = beardHeight * 0.462f;
    float srcMouthWidth   = beardWidth * 0.44f;
    float srcMustacheTop  = 300.0f;
    float srcMustacheBot  = 460.0f;
    float srcLowerLipY    = 690.0f;
    float srcChinBot      = 1050.0f;

    int midX = beardWidth / 2;
    std::vector<std::pair<int, int>> vSegments;
    bool inSeg = false;
    int segStart = 0;
    for (int y = 0; y < beardHeight; ++y) {
        int sumA = 0;
        for (int dx = -5; dx <= 5; ++dx) {
            int sx = std::clamp(midX + dx, 0, beardWidth - 1);
            sumA += RGBA_A(beardPixels[y * beardWidth + sx]);
        }
        int avgA = sumA / 11;
        if (avgA > 25) {
            if (!inSeg) {
                inSeg = true;
                segStart = y;
            }
        } else {
            if (inSeg) {
                inSeg = false;
                vSegments.push_back({segStart, y - 1});
            }
        }
    }
    if (inSeg) vSegments.push_back({segStart, beardHeight - 1});

    bool hasMustache = (!vSegments.empty() && vSegments.front().first < static_cast<int>(beardHeight * 0.48f));
    bool hasChin = (!vSegments.empty() && vSegments.back().second > static_cast<int>(beardHeight * 0.52f));

    if (hasMustache && hasChin && vSegments.size() >= 2) {
        // Full Beard, Goatee, Van Dyke, Circle Beard, Balbo, Anchor
        srcMustacheTop = static_cast<float>(vSegments[0].first);
        srcMustacheBot = static_cast<float>(vSegments[0].second);
        srcLowerLipY   = static_cast<float>(vSegments[1].first);
        srcChinBot     = static_cast<float>(vSegments.back().second);
        srcMouthCenterY = (srcMustacheBot + srcLowerLipY) * 0.5f;

        // Scan horizontal opening at srcMouthCenterY
        int my = std::clamp(static_cast<int>(srcMouthCenterY), 0, beardHeight - 1);
        int holeLeft = midX, holeRight = midX;
        while (holeLeft > 0 && RGBA_A(beardPixels[my * beardWidth + holeLeft]) < 30) holeLeft--;
        while (holeRight < beardWidth - 1 && RGBA_A(beardPixels[my * beardWidth + holeRight]) < 30) holeRight++;
        if (holeRight > holeLeft + 50) {
            srcMouthWidth = static_cast<float>(holeRight - holeLeft) * 0.85f;
        }
    } else if (hasMustache && !hasChin) {
        // Mustache Only (Chevron, Handlebar)
        srcMustacheTop = static_cast<float>(vSegments.front().first);
        srcMustacheBot = static_cast<float>(vSegments.front().second);
        srcMouthCenterY = srcMustacheBot + 45.0f;
        srcLowerLipY    = srcMouthCenterY + 45.0f;
        srcChinBot      = srcMouthCenterY + 350.0f;
        srcMouthWidth   = 620.0f;
    } else if (!hasMustache && hasChin) {
        // Chin Only (Chinstrap with soul patch)
        srcLowerLipY    = static_cast<float>(vSegments.front().first);
        srcChinBot      = static_cast<float>(vSegments.back().second);
        srcMouthCenterY = srcLowerLipY - 70.0f;
        srcMustacheBot  = srcMouthCenterY - 45.0f;
        srcMustacheTop  = srcMustacheBot - 100.0f;
        srcMouthWidth   = 580.0f;
    }

    // Quét điểm cao nhất thực tế của ria mép trên template (tính cả vòm cánh mũi)
    if (hasMustache) {
        float trueMustacheTop = srcMustacheTop;
        int scanHalfW = std::min(240, beardWidth / 4);
        for (int sx = midX - scanHalfW; sx <= midX + scanHalfW; ++sx) {
            if (sx < 0 || sx >= beardWidth) continue;
            for (int sy = 0; sy < static_cast<int>(srcMustacheBot); ++sy) {
                if (RGBA_A(beardPixels[sy * beardWidth + sx]) > 25) {
                    trueMustacheTop = std::min(trueMustacheTop, static_cast<float>(sy));
                    break;
                }
            }
        }
        srcMustacheTop = trueMustacheTop;
    }

    srcMouthWidth = std::clamp(srcMouthWidth, 480.0f, 650.0f);
    float srcMustacheSpan = std::max(40.0f, srcMustacheBot - srcMustacheTop);
    float srcChinSpan     = std::max(100.0f, srcChinBot - srcLowerLipY);

    // 4. Horizontal and Vertical Scaling
    float effWidthScale = std::max(0.40f, widthScale);
    float effThickness  = std::clamp(thickness, 0.40f, 2.50f);

    float scaleX = (mouthWidth * 1.05f * effWidthScale) / srcMouthWidth;
    if (scaleX <= 0.01f) return false;

    // Chieu cao va ti le ria mep & cam can doi theo giai phau
    float srcMouthToMustache = std::max(30.0f, srcMouthCenterY - srcMustacheTop);
    float srcMouthToChin     = std::max(60.0f, srcChinBot - srcMouthCenterY);

    float mustacheScaleY = (destPhiltrum * 0.72f * effThickness) / srcMouthToMustache;
    float chinScaleY     = (destChinSpan * 1.05f * effThickness) / srcMouthToChin;

    // Gioi han an toan dich chuyen linh hoat cho nguoi dung keo tha tren man hinh (Touch Drag)
    float maxDownShift = std::max(150.0f, destChinSpan * 1.5f);
    float maxUpShift   = std::max(80.0f, destPhiltrum * 1.0f);
    float effHeightOffset = std::clamp(heightOffset, -maxDownShift, maxUpShift);

    float maxSideShift = std::max(120.0f, mouthWidth * 0.8f);
    float effHorizontalOffset = std::clamp(horizontalOffset, -maxSideShift, maxSideShift);

    // 5. Bounding box on destination face (mo rong theo vung keo tha)
    float maxRadius = std::max(beardWidth, beardHeight) * std::max(scaleX, chinScaleY) * 0.95f;
    int minDestX = std::max(0, static_cast<int>(mouthCenterX - maxRadius - std::abs(effHorizontalOffset) - 50.0f));
    int maxDestX = std::min(width - 1, static_cast<int>(mouthCenterX + maxRadius + std::abs(effHorizontalOffset) + 50.0f));
    int minDestY = std::max(0, static_cast<int>(noseBaseY - 50.0f - std::abs(effHeightOffset)));
    int maxDestY = std::min(height - 1, static_cast<int>(mouthCenterY + maxRadius + std::abs(effHeightOffset) + 50.0f));

    // OpenMP parallel processing over destination face
    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = minDestY; y <= maxDestY; ++y) {
        float fy = static_cast<float>(y);

        for (int x = minDestX; x <= maxDestX; ++x) {
            float fx = static_cast<float>(x);

            // 5.1. BAO VE TUYET DOI LO MUI (NOSTRIL EXCLUSION SHIELD)
            // getNoseBottomY(fx, fused) la chan lo mui va goc mui.
            // Chi loai tru vung TRONG lo mui (fy <= yNoseBase + 2.0f),
            // giu tron ven 100% hinh thai ria mep, khong xen lech meo.
            float yNoseBase = getNoseBottomY(fx, fused);
            float noseCutoffY = yNoseBase + 2.0f;
            if (fy <= noseCutoffY) {
                continue; // Vung cam: trong lo mui
            }
            float noseDist = fy - noseCutoffY;
            float noseFade = std::clamp(noseDist / 4.0f, 0.0f, 1.0f);

            // 5.2. BAO VE KHOANG MIENG TRONG (INNER MOUTH EXCLUSION)
            // Loai tru 100% khoang ho rang, luoi ben trong mieng khi mo he.
            // Tuyet doi KHONG cat xen vien ngoai moi tren - noi ria mep phu tu nhien,
            // khong con tinh trang rau bi di chuyen duoi layer moi lam xen cut rau.
            if (!innerMouthPoly.empty() && isInsidePolygon(fx, fy, innerMouthPoly)) {
                continue;
            }

            // Toa do lech tuong doi so voi tam mieng (duoc dich chuyen tu do boi effHeightOffset & effHorizontalOffset)
            float dx = fx - mouthCenterX;
            float dy = fy - mouthCenterY;

            // Chieu len he truc giai phau khuon mat co tinh ca do dich chuyen cua nguoi dung
            float du = dx * uDirX + dy * uDirY - effHorizontalOffset;
            float dv = dx * vDirX + dy * vDirY - effHeightOffset;

            // 5.3. QUY DOI TOA DO LIEN TUC VA DONG NHAT KHONG BI XEN RAU
            // Goc dv = 0 la tam mieng trong suot cua template rau.
            // dv < 0: vung ria mep phia tren moi -> anh xa lien tuc, day du hinh thai.
            // dv >= 0: vung chom rau cam phia duoi moi -> anh xa lien tuc xuong cam.
            float su = srcMouthCenterX + du / scaleX;
            float sv;

            if (dv < 0.0f) {
                if (!hasMustache) continue;
                sv = srcMouthCenterY + dv / mustacheScaleY;
            } else {
                if (!hasChin) continue;
                sv = srcMouthCenterY + dv / chinScaleY;
            }

            if (su < 0.0f || su >= static_cast<float>(beardWidth - 1) ||
                sv < 0.0f || sv >= static_cast<float>(beardHeight - 1)) {
                continue;
            }

            // Bilinear interpolation in source beard PNG
            int x0 = static_cast<int>(su);
            int y0 = static_cast<int>(sv);
            int x1 = x0 + 1;
            int y1 = y0 + 1;
            float tu = su - static_cast<float>(x0);
            float tv = sv - static_cast<float>(y0);

            uint32_t c00 = beardPixels[y0 * beardWidth + x0];
            uint32_t c10 = beardPixels[y0 * beardWidth + x1];
            uint32_t c01 = beardPixels[y1 * beardWidth + x0];
            uint32_t c11 = beardPixels[y1 * beardWidth + x1];

            float a00 = RGBA_A(c00), a10 = RGBA_A(c10);
            float a01 = RGBA_A(c01), a11 = RGBA_A(c11);
            float alphaInterp = (1.0f - tu) * (1.0f - tv) * a00 +
                                tu * (1.0f - tv) * a10 +
                                (1.0f - tu) * tv * a01 +
                                tu * tv * a11;

            if (alphaInterp <= 2.0f) continue;

            float rInterp = (1.0f - tu) * (1.0f - tv) * RGBA_R(c00) +
                            tu * (1.0f - tv) * RGBA_R(c10) +
                            (1.0f - tu) * tv * RGBA_R(c01) +
                            tu * tv * RGBA_R(c11);

            float gInterp = (1.0f - tu) * (1.0f - tv) * RGBA_G(c00) +
                            tu * (1.0f - tv) * RGBA_G(c10) +
                            (1.0f - tu) * tv * RGBA_G(c01) +
                            tu * tv * RGBA_G(c11);

            float bInterp = (1.0f - tu) * (1.0f - tv) * RGBA_B(c00) +
                            tu * (1.0f - tv) * RGBA_B(c10) +
                            (1.0f - tu) * tv * RGBA_B(c01) +
                            tu * tv * RGBA_B(c11);

            // Optional Recoloring / Dyeing of beard hair
            float finalR = rInterp;
            float finalG = gInterp;
            float finalB = bInterp;

            if (isDyeActive) {
                float lum = (0.299f * rInterp + 0.587f * gInterp + 0.114f * bInterp) / 255.0f;
                float scaleLum = std::clamp(lum * 1.25f, 0.40f, 1.35f);
                finalR = std::clamp(static_cast<float>(targetR) * scaleLum, 0.0f, 255.0f);
                finalG = std::clamp(static_cast<float>(targetG) * scaleLum, 0.0f, 255.0f);
                finalB = std::clamp(static_cast<float>(targetB) * scaleLum, 0.0f, 255.0f);
            }

            // Alpha blending with destination face pixel + nose feathering
            int destIdx = y * width + x;
            uint32_t destColor = pixels[destIdx];
            float destR = RGBA_R(destColor);
            float destG = RGBA_G(destColor);
            float destB = RGBA_B(destColor);
            uint32_t destA = RGBA_A(destColor);

            float blendAlpha = (alphaInterp / 255.0f) * p * noseFade;

            int outR = static_cast<int>(destR * (1.0f - blendAlpha) + finalR * blendAlpha);
            int outG = static_cast<int>(destG * (1.0f - blendAlpha) + finalG * blendAlpha);
            int outB = static_cast<int>(destB * (1.0f - blendAlpha) + finalB * blendAlpha);

            pixels[destIdx] = PACK_RGBA(outR, outG, outB, destA);
        }
    }

    LOGI("applyPresetBeard completed with NOSE SHIELD! size=%dx%d, p=%.2f, isDye=%d, targetRGB=(%d,%d,%d), philtrumH=%.1f",
         beardWidth, beardHeight, p, isDyeActive ? 1 : 0, targetR, targetG, targetB, destPhiltrum);
    return true;
}

} // namespace meitu_native
