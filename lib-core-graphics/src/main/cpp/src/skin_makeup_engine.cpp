#include "skin_makeup_engine.h"
#include <cmath>
#include <algorithm>
#include <vector>
#include <omp.h>

#define RGBA_R(c) ((c) & 0xFF)
#define RGBA_G(c) (((c) >> 8) & 0xFF)
#define RGBA_B(c) (((c) >> 16) & 0xFF)
#define RGBA_A(c) (((c) >> 24) & 0xFF)
#define PACK_RGBA(r, g, b, a) (((uint32_t)(a) << 24) | ((uint32_t)(b) << 16) | ((uint32_t)(g) << 8) | (uint32_t)(r))

namespace meitu_native {

// Chuyển đổi RGB sang YCbCr (chuẩn ITU-R BT.601)
// Convert RGB to YCbCr (ITU-R BT.601 standard)
static inline void rgbToYCbCr(int r, int g, int b, float& y, float& cb, float& cr) {
    y  =  0.299000f * r + 0.587000f * g + 0.114000f * b;
    cb = -0.168736f * r - 0.331264f * g + 0.500000f * b + 128.0f;
    cr =  0.500000f * r - 0.418688f * g - 0.081312f * b + 128.0f;
}

// Chuyển đổi RGB sang HSV
// Convert RGB to HSV
static inline void rgbToHSV(int r, int g, int b, float& h, float& s, float& v) {
    float rf = r / 255.0f;
    float gf = g / 255.0f;
    float bf = b / 255.0f;
    float maxV = std::max({rf, gf, bf});
    float minV = std::min({rf, gf, bf});
    float delta = maxV - minV;
    v = maxV;
    s = (maxV > 0.0001f) ? (delta / maxV) : 0.0f;
    if (delta < 0.00001f) {
        h = 0.0f;
    } else {
        if (maxV == rf) {
            h = 60.0f * (std::fmod(((gf - bf) / delta), 6.0f));
        } else if (maxV == gf) {
            h = 60.0f * (((bf - rf) / delta) + 2.0f);
        } else {
            h = 60.0f * (((rf - gf) / delta) + 4.0f);
        }
        if (h < 0.0f) h += 360.0f;
    }
}

static inline float smoothstep(float edge0, float edge1, float x) {
    if (edge0 == edge1) return (x < edge0) ? 0.0f : 1.0f;
    float t = std::clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
    return t * t * (3.0f - 2.0f * t);
}

// =========================================================================
// 1. HỒ SƠ QUANG PHỔ DA CỦA CHÍNH NGƯỜI MẪU (GROUND-TRUTH PERSON SKIN PROFILE)
// =========================================================================
struct PersonSkinProfile {
    float meanY = 160.0f;
    float meanCb = 110.0f;
    float meanCr = 148.0f;
    float varCb = 90.0f;
    float varCr = 100.0f;
    float meanR = 190.0f;
    float meanG = 150.0f;
    float meanB = 135.0f;
    float ratioRG = 1.25f;
    float ratioRB = 1.40f;
    bool isCalibrated = false;
};

static PersonSkinProfile calibratePersonSkinProfile(
    const uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106,
    float faceCenterX, float faceCenterY,
    float faceRadX, float faceRadY
) {
    PersonSkinProfile profile;
    std::vector<float> sampleY, sampleCb, sampleCr, sampleR, sampleG, sampleB;
    sampleY.reserve(128);
    sampleCb.reserve(128);
    sampleCr.reserve(128);

    if (landmarks106 != nullptr) {
        // Lấy mẫu từ các vùng da an toàn trên khuôn mặt (trán, sống mũi, 2 gò má, cằm)
        int sampleLandmarkIndices[] = {
            16, // Đỉnh cằm (Gnathion)
            14, 18, // Viền cằm
            55, 57, 59, // Sống mũi
            46, 50, // Trán dưới lông mày trái
            66, 70, // Trán dưới lông mày phải
            2, 4, 28, 30 // Hai bên gò má
        };
        for (int idx : sampleLandmarkIndices) {
            int sx = std::clamp(static_cast<int>(landmarks106[idx * 2]), 0, width - 1);
            int sy = std::clamp(static_cast<int>(landmarks106[idx * 2 + 1]), 0, height - 1);
            for (int dy = -1; dy <= 1; ++dy) {
                int py = std::clamp(sy + dy, 0, height - 1);
                for (int dx = -1; dx <= 1; ++dx) {
                    int px = std::clamp(sx + dx, 0, width - 1);
                    uint32_t c = pixels[py * width + px];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);
                    float yVal, cbVal, crVal;
                    rgbToYCbCr(r, g, b, yVal, cbVal, crVal);
                    if (yVal > 35.0f && yVal < 248.0f && cbVal > 75.0f && cbVal < 140.0f && crVal > 125.0f && crVal < 192.0f && r >= g) {
                        sampleY.push_back(yVal);
                        sampleCb.push_back(cbVal);
                        sampleCr.push_back(crVal);
                        sampleR.push_back(r);
                        sampleG.push_back(g);
                        sampleB.push_back(b);
                    }
                }
            }
        }
    } else {
        int cx = std::clamp(static_cast<int>(faceCenterX), 0, width - 1);
        int cy = std::clamp(static_cast<int>(faceCenterY), 0, height - 1);
        float rLim = std::max(20.0f, faceRadX * 0.40f);
        for (int dy = -static_cast<int>(rLim); dy <= static_cast<int>(rLim); dy += 4) {
            int py = std::clamp(cy + dy, 0, height - 1);
            for (int dx = -static_cast<int>(rLim); dx <= static_cast<int>(rLim); dx += 4) {
                int px = std::clamp(cx + dx, 0, width - 1);
                if (dx * dx + dy * dy <= rLim * rLim) {
                    uint32_t c = pixels[py * width + px];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);
                    float yVal, cbVal, crVal;
                    rgbToYCbCr(r, g, b, yVal, cbVal, crVal);
                    if (yVal > 35.0f && yVal < 248.0f && cbVal > 75.0f && cbVal < 140.0f && crVal > 125.0f && crVal < 192.0f && r >= g) {
                        sampleY.push_back(yVal);
                        sampleCb.push_back(cbVal);
                        sampleCr.push_back(crVal);
                        sampleR.push_back(r);
                        sampleG.push_back(g);
                        sampleB.push_back(b);
                    }
                }
            }
        }
    }

    if (sampleY.size() >= 8) {
        float sumY = 0, sumCb = 0, sumCr = 0, sumR = 0, sumG = 0, sumB = 0;
        for (size_t i = 0; i < sampleY.size(); ++i) {
            sumY += sampleY[i]; sumCb += sampleCb[i]; sumCr += sampleCr[i];
            sumR += sampleR[i]; sumG += sampleG[i]; sumB += sampleB[i];
        }
        profile.meanY = sumY / sampleY.size();
        profile.meanCb = sumCb / sampleCb.size();
        profile.meanCr = sumCr / sampleCr.size();
        profile.meanR = sumR / sampleR.size();
        profile.meanG = sumG / sampleG.size();
        profile.meanB = sumB / sampleB.size();
        profile.ratioRG = profile.meanR / (profile.meanG + 0.1f);
        profile.ratioRB = profile.meanR / (profile.meanB + 0.1f);

        float varCb = 0, varCr = 0;
        for (size_t i = 0; i < sampleY.size(); ++i) {
            float dCb = sampleCb[i] - profile.meanCb;
            float dCr = sampleCr[i] - profile.meanCr;
            varCb += dCb * dCb;
            varCr += dCr * dCr;
        }
        profile.varCb = std::max(200.0f, varCb / sampleY.size() * 3.0f);
        profile.varCr = std::max(200.0f, varCr / sampleY.size() * 3.0f);
        profile.isCalibrated = true;
    }
    return profile;
}

// =========================================================================
// 2. HÀNH LANG GIẢI PHẪU THÂN NGƯỜI (ANATOMICAL HUMAN BODY CORRIDOR)
// =========================================================================
static inline float computeAnatomicalSpatialWeight(
    int x, int y,
    int width, int height,
    float faceCenterX, float faceCenterY,
    float faceMinX, float faceMaxX,
    float faceMinY, float faceMaxY,
    float chinY
) {
    float faceW = std::max(50.0f, faceMaxX - faceMinX);
    float faceH = std::max(60.0f, faceMaxY - faceMinY);

    // 1. Phía trên đỉnh đầu: Tuyệt đối không có da cơ thể (loại bỏ trần/tường phía trên)
    float headTopY = faceMinY - faceH * 0.25f;
    if (y < headTopY) {
        return 0.0f;
    }

    // 2. Vùng khuôn mặt (Head region): Bao bọc đầu và má tự nhiên
    if (y <= chinY + 10.0f) {
        float halfW = faceW * 0.58f;
        float dx = std::abs(static_cast<float>(x) - faceCenterX);
        if (dx <= halfW) {
            return 1.0f;
        } else if (dx <= halfW + faceW * 0.15f) {
            return smoothstep(halfW + faceW * 0.15f, halfW, dx);
        } else {
            return 0.0f;
        }
    }

    // 3. Vùng thân người: Cổ, cơ cầu vai, ngực, bụng 6 múi, vai, bắp tay (Gym Shirtless Torso Corridor)
    float distDownFromChin = static_cast<float>(y) - (chinY + 10.0f);
    float depthFactor = std::min(1.0f, distDownFromChin / (faceH * 2.2f));

    // Nửa chiều rộng tối đa cho phép của thân người tại độ sâu y
    float allowedHalfWidth = (faceW * 0.55f) * (1.15f + 2.50f * depthFactor);

    float dx = std::abs(static_cast<float>(x) - faceCenterX);
    if (dx <= allowedHalfWidth) {
        return 1.0f;
    } else if (dx <= allowedHalfWidth + 35.0f) {
        return smoothstep(allowedHalfWidth + 35.0f, allowedHalfWidth, dx);
    } else {
        return 0.0f;
    }
}

// =========================================================================
// 2B. KIỂM TRA ĐẶC TRƯNG QUANG PHỔ BIỂU BÌ SINH HỌC (BIOPHYSICAL EPIDERMIS CHECK)
// =========================================================================
static inline bool isBiologicalSkinPixel(
    int r, int g, int b,
    float Y, float Cb, float Cr,
    float H, float S, float V,
    const PersonSkinProfile& profile
) {
    // 1. Độ sáng sinh học (loại trừ bóng tối đen và lóa kim loại)
    if (Y < 22.0f || Y > 248.0f) return false;

    // 2. Loại trừ kim loại phản xạ / phản quang chói lóa
    if ((Y > 235.0f && S < 0.09f) || (V > 0.98f && S < 0.04f)) return false;

    // 3. Loại trừ tóc đen, râu, lông mày sẫm màu
    if (Y < 28.0f || (Y < 48.0f && (Cr - Cb < 6.0f))) return false;

    // 4. Loại trừ quần áo, vải tổng hợp (áo xanh, áo tím, áo đen)
    if (b > r + 6 || g > r + 8) return false;
    if (S > 0.72f || Cb > 146.0f || Cr < 120.0f) return false;

    // 5. Loại trừ tường xám / trắng / thạch cao, thảm sàn cao su, điện thoại, tạ sắt
    // Vật liệu vô cơ không có tuần hoàn máu: độ bão hòa rất thấp và Cr xấp xỉ Cb
    if (S < 0.075f || (Cr - Cb < 4.5f && S < 0.12f)) return false;

    // 6. LOẠI TRỪ CỬA GỖ ĐỎ, SÀN GỖ GYM, NỘI THẤT GỖ, KHĂN ĐỎ (CHÌA KHÓA GYM SHIRTLESS)
    // Gỗ đỏ (Red-brown wood) và khăn đỏ có sắc tố Lignin hoặc phẩm nhuộm công nghiệp:
    // R/G > 1.82f, R/B > 2.35f, hoặc độ bão hòa S quá cao (S > 0.65f)
    float rRatioG = static_cast<float>(r) / (g + 0.1f);
    float rRatioB = static_cast<float>(r) / (b + 0.1f);
    if (rRatioG > 1.82f || rRatioB > 2.35f) return false;
    if (S > 0.65f) return false;

    // Khăn đỏ / vải đỏ công nghiệp (Synthetic red fabric)
    if (r > 155 && r > g * 2.0f && r > b * 2.0f && S > 0.62f) return false;

    // 7. TIÊU CHÍ BIỂU BÌ SINH HỌC TUẦN HOÀN MAO MẠCH (HEMOGLOBIN & MELANIN)
    // Người sống luôn có R >= G và R >= B (trong bóng râm có thể r >= g - 2.5)
    if (r < g - 2 || r < b - 2) return false;
    if (Cr < 128.0f || (Cr - Cb < 4.5f)) return false;

    // 8. TƯƠNG THÍCH MÀU DA CỦA CHÍNH NGƯỜI MẪU (MAHALANOBIS PROFILE DISTANCE)
    if (profile.isCalibrated) {
        float dCb = (Cb - profile.meanCb);
        float dCr = (Cr - profile.meanCr);
        float mahalSq = (dCb * dCb) / profile.varCb + (dCr * dCr) / profile.varCr;
        if (mahalSq > 10.0f) return false;
    }

    return true;
}

// =========================================================================
// 3. PHÂN ĐOẠN BIỂU BÌ VÀ TÍNH LIÊN TỤC GIẢI PHẪU (POLYGONAL RASTERIZATION & SEAMLESS SKIN SEGMENTATION)
// =========================================================================
struct Point2D { float x, y; };

static void rasterizePolygon(
    const std::vector<Point2D>& poly,
    int width, int height,
    std::vector<float>& mask,
    float fillValue = 1.0f
) {
    if (poly.size() < 3) return;
    float minY = poly[0].y, maxY = poly[0].y;
    for (const auto& pt : poly) {
        if (pt.y < minY) minY = pt.y;
        if (pt.y > maxY) maxY = pt.y;
    }
    int startY = std::max(0, static_cast<int>(std::floor(minY)));
    int endY = std::min(height - 1, static_cast<int>(std::ceil(maxY)));

    for (int y = startY; y <= endY; ++y) {
        float yf = static_cast<float>(y) + 0.5f;
        std::vector<float> nodeX;
        nodeX.reserve(16);
        size_t n = poly.size();
        for (size_t i = 0; i < n; ++i) {
            size_t j = (i + 1) % n;
            float y1 = poly[i].y;
            float y2 = poly[j].y;
            if ((y1 < yf && y2 >= yf) || (y2 < yf && y1 >= yf)) {
                float x1 = poly[i].x;
                float x2 = poly[j].x;
                float x = x1 + (yf - y1) / (y2 - y1) * (x2 - x1);
                nodeX.push_back(x);
            }
        }
        std::sort(nodeX.begin(), nodeX.end());
        for (size_t k = 0; k + 1 < nodeX.size(); k += 2) {
            int startX = std::max(0, static_cast<int>(std::ceil(nodeX[k])));
            int endX = std::min(width - 1, static_cast<int>(std::floor(nodeX[k + 1])));
            int rowOffset = y * width;
            for (int x = startX; x <= endX; ++x) {
                mask[rowOffset + x] = fillValue;
            }
        }
    }
}

static void computeRefinedBiologicalSkinMask(
    const uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106,
    float faceCenterX, float faceCenterY,
    float faceRadX, float faceRadY,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    float mouthX, float mouthY,
    std::vector<float>& outSkinMask,
    std::vector<uint8_t>& outZoneType
) {
    int totalPixels = width * height;
    outSkinMask.assign(totalPixels, 0.0f);
    outZoneType.assign(totalPixels, 0);

    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float faceW = faceRadX * 2.0f;
    float faceH = faceRadY * 2.0f;
    float chinY = faceCenterY + faceRadY;

    if (landmarks106 != nullptr) {
        float realFaceW = std::abs(landmarks106[32 * 2] - landmarks106[0 * 2]);
        if (realFaceW > 30.0f) {
            faceW = realFaceW;
            faceCenterX = (landmarks106[0 * 2] + landmarks106[32 * 2]) * 0.5f;
            faceCenterY = (landmarks106[0 * 2 + 1] + landmarks106[32 * 2 + 1]) * 0.5f;
        }
        // 1. TẠO VÀ RASTERIZE ĐA GIÁC KHUÔN MẶT (FACE POLYGON)
        // Mở rộng biên ngoài má, thái dương, dái tai và vành tai để không bao giờ bị cắt cụt
        std::vector<Point2D> facePoly;
        facePoly.reserve(50);
        for (int i = 0; i <= 32; ++i) {
            float px = landmarks106[i * 2];
            float py = landmarks106[i * 2 + 1];
            // Mở rộng viền tai và má trái (điểm 0 đến 5)
            if (i <= 5) {
                px -= (65.0f - i * 10.0f) * sx;
            }
            // Mở rộng viền tai và má phải (điểm 27 đến 32)
            else if (i >= 27) {
                px += (15.0f + (i - 27) * 10.0f) * sx;
            }
            facePoly.push_back({ px, py });
        }

        // Vòm trán (Forehead dome)
        float eyebrowY = 0.0f;
        for (int i = 33; i <= 52; ++i) {
            eyebrowY += landmarks106[i * 2 + 1];
        }
        eyebrowY /= 20.0f;

        float noseY = landmarks106[60 * 2 + 1];
        faceH = std::max(40.0f * sy, noseY - eyebrowY);
        float foreheadTop = std::max(5.0f, eyebrowY - faceH * 1.05f);

        Point2D ptLeft = { landmarks106[0 * 2], landmarks106[0 * 2 + 1] };
        Point2D ptRight = { landmarks106[32 * 2], landmarks106[32 * 2 + 1] };

        // Mở rộng vòm trán, thái dương và tóc mai hai bên (chuẩn xác viền khuôn mặt, không lấn nền cửa gỗ)
        facePoly.push_back({ ptRight.x + 30.0f * sx, ptRight.y - faceH * 0.35f });
        facePoly.push_back({ ptRight.x + 25.0f * sx, foreheadTop });
        facePoly.push_back({ (ptLeft.x + ptRight.x) * 0.50f, foreheadTop - 10.0f * sy });
        facePoly.push_back({ ptLeft.x - 18.0f * sx, foreheadTop });
        facePoly.push_back({ ptLeft.x - 22.0f * sx, ptLeft.y - faceH * 0.35f });

        rasterizePolygon(facePoly, width, height, outSkinMask, 1.0f);

        // Gán vùng mặt (Facial skin), không lọc nhầm bóng đổ xương hàm dưới/cằm
        #pragma omp parallel for schedule(dynamic, 16)
        for (int idx = 0; idx < totalPixels; ++idx) {
            if (outSkinMask[idx] > 0.5f) {
                outZoneType[idx] = 1; // Facial skin
            }
        }

        // 2. TẠO VÀ RASTERIZE ĐA GIÁC VÙNG CỔ (NECK POLYGON)
        chinY = landmarks106[16 * 2 + 1];
        float neckTopY = std::min(landmarks106[4 * 2 + 1], landmarks106[28 * 2 + 1]);
        float neckBottom = std::min(height - 1.0f, chinY + faceH * 0.95f);

        std::vector<Point2D> neckPoly;
        neckPoly.reserve(36);
        // Gối 8px lên cằm dưới để triệt tiêu hoàn toàn khe hở hay vết cắt ngang cổ
        for (int i = 4; i <= 28; ++i) {
            neckPoly.push_back({ landmarks106[i * 2], landmarks106[i * 2 + 1] - 8.0f * sy });
        }
        neckPoly.push_back({ landmarks106[28 * 2] + 45.0f * sx, neckBottom });
        neckPoly.push_back({ landmarks106[4 * 2] - 45.0f * sx, neckBottom });

        std::vector<float> neckMask(totalPixels, 0.0f);
        rasterizePolygon(neckPoly, width, height, neckMask, 1.0f);

        // Lọc da vùng cổ, chấp nhận bóng đổ dưới cằm
        int neckBottomSkinCount = 0;
        int checkNeckY = std::max(0, static_cast<int>(neckBottom - 6.0f * sy));

        #pragma omp parallel for schedule(dynamic, 16)
        for (int y = static_cast<int>(neckTopY); y <= static_cast<int>(neckBottom); ++y) {
            int rowOffset = y * width;
            for (int x = 0; x < width; ++x) {
                int idx = rowOffset + x;
                if (neckMask[idx] <= 0.5f) continue;

                uint32_t c = pixels[idx];
                int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
                float Y, Cb, Cr;
                rgbToYCbCr(r, g, b, Y, Cb, Cr);

                // Nhận diện da cổ chuẩn xác, bao gồm cả vùng tối dưới cằm
                bool isNeckSkin = (Y >= 20.0f) && (r >= g - 16) && (r >= b - 16) && (Cr >= 118.0f);
                if (isNeckSkin) {
                    outSkinMask[idx] = 1.0f;
                    if (outZoneType[idx] == 0) outZoneType[idx] = 2; // Neck skin
                }
            }
        }

        // Kiểm tra xem cổ có kéo dài xuống thân thể không (ảnh nam tập gym cởi trần)
        int rowBottomOffset = checkNeckY * width;
        for (int x = 0; x < width; ++x) {
            if (outSkinMask[rowBottomOffset + x] > 0.5f) {
                neckBottomSkinCount++;
            }
        }

        // 3. NẾU CỞI TRẦN (SHIRTLESS GYM / BODY PHOTO): THU NHẬN TOÀN BỘ THÂN TRÊN & LẤP ĐẦY VÙNG XĂM
        if (neckBottomSkinCount >= 8) {
            // Bắt đầu quét từ neckTopY - 5px để bao phủ trọn vẹn toàn bộ 2 cơ cầu vai (Trapezius) và bờ vai hai bên
            int bodyStartY = std::max(0, static_cast<int>(neckTopY) - 5);
            int bodyEndY = height - 1;

            // Bước 3.1: Thu thập ứng viên da cơ thể, bóng đổ cơ bắp và vùng xăm
            // HÀNH LANG GIẢI PHẪU (ANATOMICAL CORRIDOR) + PHÂN BIỆT QUANG PHỔ VẬT LIỆU (MATERIAL SPECTRAL DISCRIMINATION)
            std::vector<uint8_t> bodyCand(totalPixels, 0);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y <= bodyEndY; ++y) {
                // Hành lang giải phẫu thân người chuẩn xác theo độ rộng thực của khuôn mặt
                float allowedHalfLeft = faceW * 1.80f;
                float allowedHalfRight = faceW * 1.68f;

                if (y < chinY + 0.55f * faceH) {
                    // Dốc cổ -> cơ cầu vai (Trapezius slope)
                    float t = std::max(0.0f, (static_cast<float>(y) - neckTopY) / std::max(1.0f, chinY + 0.55f * faceH - neckTopY));
                    allowedHalfLeft = faceW * (0.65f + 1.05f * t);
                    allowedHalfRight = faceW * (0.65f + 1.05f * t);
                } else if (y < chinY + 1.75f * faceH) {
                    // Ngực và bắp tay (Chest & Biceps)
                    allowedHalfLeft = faceW * 1.80f;
                    allowedHalfRight = faceW * 1.68f;
                } else {
                    // Mạn sườn / thắt lưng / hông (Waist & hips)
                    allowedHalfLeft = faceW * 1.50f;
                    allowedHalfRight = faceW * 1.45f;
                }

                int minBodyX = std::max(0, static_cast<int>(faceCenterX - allowedHalfLeft));
                int maxBodyX = std::min(width - 1, static_cast<int>(faceCenterX + allowedHalfRight));

                int rowOffset = y * width;
                for (int x = minBodyX; x <= maxBodyX; ++x) {
                    int idx = rowOffset + x;
                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);

                    float Y = 0.299f * r + 0.587f * g + 0.114f * b;
                    float Cb = 128.0f - 0.168736f * r - 0.331264f * g + 0.5f * b;
                    float Cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;

                    // 1. Chặn phông nền quá tối
                    if (Y < 18.0f || Y > 252.0f) continue;

                    // 2. Chặn sàn gạch men xanh lá / xanh dương sáng
                    if (y > chinY + 2.3f * faceH && Y > 110.0f && (g > r + 15 || b > r + 20)) continue;

                    // 3. Chặn quần đen ở phần dưới
                    if (Y < 32.0f && y > chinY + 2.0f * faceH) continue;

                    // 4. CHẶN CỬA GỖ ĐỎ CHỈ TẠI VỊ TRÍ PHÔNG NỀN NGOẠI VI BÊN TRÁI
                    // (Tuyệt đối không chặn trong lồng ngực, dưới cằm, cổ, hõm nách hay thân người)
                    if (x < faceCenterX - 1.15f * faceW) {
                        if (r > 60 && (static_cast<float>(r) / (g + 0.1f) > 1.55f) && (r - g > 24) && (std::abs(g - b) <= 15)) {
                            continue;
                        }
                    }

                    // 5. CHẶN THANG GỖ & BỜ TƯỜNG VÀNG PHÍA BÊN PHẢI NGOÀI BẮP TAY
                    if (x > faceCenterX + 1.25f * faceW) {
                        if (r < 90 && g < 48 && b < 42 && (r - g > 24)) continue;
                        if (Y > 120.0f && (r - g <= 8) && (Cr - Cb < 16.0f)) continue;
                    }

                    // Ứng viên biểu bì thân người, cơ cầu vai, bóng đổ hõm nách và toàn bộ vùng xăm mực đen/màu
                    if (r >= g - 35 && (r >= b - 45 || (Y < 75.0f && b > r))) {
                        bodyCand[idx] = 1;
                    }
                }
            }

            // Bước 3.2: Toán tử đóng hình thái học 2D Separable Morphological Closing (Radius = 14px)
            int radClose = std::clamp(static_cast<int>(14.0f * sx), 10, 20);
            std::vector<uint8_t> dilatedTemp(totalPixels, 0);
            std::vector<uint8_t> dilated(totalPixels, 0);

            // Dilation Pass 1: Horizontal Prefix-Sum Max
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y <= bodyEndY; ++y) {
                int rowOffset = y * width;
                std::vector<int> pSum(width + 1, 0);
                for (int x = 0; x < width; ++x) pSum[x + 1] = pSum[x] + bodyCand[rowOffset + x];
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radClose);
                    int x2 = std::min(width, x + radClose + 1);
                    dilatedTemp[rowOffset + x] = (pSum[x2] - pSum[x1] > 0) ? 1 : 0;
                }
            }

            // Dilation Pass 2: Vertical Prefix-Sum Max
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> pSum(height + 1, 0);
                for (int y = 0; y < height; ++y) pSum[y + 1] = pSum[y] + dilatedTemp[y * width + x];
                for (int y = bodyStartY; y <= bodyEndY; ++y) {
                    int y1 = std::max(bodyStartY, y - radClose);
                    int y2 = std::min(height, y + radClose + 1);
                    dilated[y * width + x] = (pSum[y2] - pSum[y1] > 0) ? 1 : 0;
                }
            }

            // Erosion Pass 1: Horizontal Prefix-Sum Min
            std::vector<uint8_t> erodedTemp(totalPixels, 0);
            std::vector<uint8_t> closedMask(totalPixels, 0);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y <= bodyEndY; ++y) {
                int rowOffset = y * width;
                std::vector<int> pSum(width + 1, 0);
                for (int x = 0; x < width; ++x) pSum[x + 1] = pSum[x] + dilated[rowOffset + x];
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radClose);
                    int x2 = std::min(width, x + radClose + 1);
                    erodedTemp[rowOffset + x] = (pSum[x2] - pSum[x1] == (x2 - x1)) ? 1 : 0;
                }
            }

            // Erosion Pass 2: Vertical Prefix-Sum Min
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> pSum(height + 1, 0);
                for (int y = 0; y < height; ++y) pSum[y + 1] = pSum[y] + erodedTemp[y * width + x];
                for (int y = bodyStartY; y <= bodyEndY; ++y) {
                    int y1 = std::max(bodyStartY, y - radClose);
                    int y2 = std::min(height, y + radClose + 1);
                    closedMask[y * width + x] = (pSum[y2] - pSum[y1] == (y2 - y1)) ? 1 : 0;
                }
            }

            // BẢO VỆ TUYỆT ĐỐI NỀN: Loại bỏ mọi điểm lọt lưới do dãn nở chạm vào cửa gỗ hoặc thang/tường
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y <= bodyEndY; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    if (closedMask[idx] == 0) continue;

                    // Giới hạn tuyệt đối hành lang giải phẫu
                    if (x > faceCenterX + 1.70f * faceW || x < faceCenterX - 1.82f * faceW) {
                        closedMask[idx] = 0;
                        continue;
                    }

                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
                    float Y = 0.299f * r + 0.587f * g + 0.114f * b;
                    float Cb = 128.0f - 0.168736f * r - 0.331264f * g + 0.5f * b;
                    float Cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;

                    // Chỉ loại trừ cửa gỗ ngoại vi thực tế ở rìa ngoài bên trái
                    if (x < faceCenterX - 1.15f * faceW) {
                        if (r > 60 && (static_cast<float>(r) / (g + 0.1f) > 1.55f) && (r - g > 24) && (std::abs(g - b) <= 15)) {
                            closedMask[idx] = 0;
                            continue;
                        }
                    }

                    // Thang gỗ / tường vàng
                    if (x > faceCenterX + 1.25f * faceW) {
                        if (r < 90 && g < 48 && b < 42 && (r - g > 24)) { closedMask[idx] = 0; continue; }
                        if (Y > 120.0f && (r - g <= 8) && (Cr - Cb < 16.0f)) { closedMask[idx] = 0; continue; }
                    }
                }
            }

            // Bước 3.3: Lan truyền liên thông từ vùng cổ xuống thân người và bờ vai (BFS Flood Fill)
            std::vector<uint8_t> bodyConnected(totalPixels, 0);
            std::vector<int> q;
            q.reserve(totalPixels / 8);

            // Gieo mầm từ TOÀN BỘ các điểm da cổ đã nhận diện (neckTopY đến neckBottom + 15)
            for (int y = bodyStartY; y <= std::min(height - 1, static_cast<int>(neckBottom + 15.0f * sy)); ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    if (outSkinMask[idx] > 0.5f && closedMask[idx] > 0 && bodyConnected[idx] == 0) {
                        bodyConnected[idx] = 1;
                        q.push_back(idx);
                    }
                }
            }

            size_t head = 0;
            const int dxs[4] = {-1, 1, 0, 0};
            const int dys[4] = {0, 0, -1, 1};

            while (head < q.size()) {
                int curr = q[head++];
                int cy = curr / width;
                int cx = curr % width;

                for (int i = 0; i < 4; ++i) {
                    int ny = cy + dys[i];
                    int nx = cx + dxs[i];
                    if (ny >= bodyStartY && ny < height && nx >= 0 && nx < width) {
                        if (nx > faceCenterX + 1.70f * faceW || nx < faceCenterX - 1.82f * faceW) continue;
                        int nIdx = ny * width + nx;
                        if (closedMask[nIdx] > 0 && bodyConnected[nIdx] == 0) {
                            bodyConnected[nIdx] = 1;
                            q.push_back(nIdx);
                        }
                    }
                }
            }

            // Bước 3.4: Lấp đầy các khoảng trống lòng ngực, thớ cơ, vùng xăm và hõm nách (Scanline Infilling An Toàn)
            int maxInfill = std::clamp(static_cast<int>(width * 0.16f), 40, 120);
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y < height; ++y) {
                int rowOffset = y * width;
                int firstX = -1, lastX = -1;
                for (int x = 0; x < width; ++x) {
                    if (bodyConnected[rowOffset + x] > 0) {
                        if (firstX < 0) firstX = x;
                        lastX = x;
                    }
                }
                if (firstX >= 0 && lastX > firstX) {
                    int prevX = -1;
                    for (int x = firstX; x <= lastX; ++x) {
                        if (bodyConnected[rowOffset + x] > 0) {
                            if (prevX >= 0 && x - prevX > 1 && x - prevX <= maxInfill) {
                                bool canFill = true;
                                for (int fillX = prevX + 1; fillX < x; ++fillX) {
                                    if (fillX > faceCenterX + 1.70f * faceW || fillX < faceCenterX - 1.82f * faceW) { canFill = false; break; }
                                    uint32_t fc = pixels[rowOffset + fillX];
                                    int fr = RGBA_R(fc), fg = RGBA_G(fc), fb = RGBA_B(fc);
                                    if (y > chinY + 2.3f * faceH && fg > 140 && fb > 140 && (fg > fr + 15 || fb > fr + 15)) { canFill = false; break; }
                                }
                                if (canFill) {
                                    for (int fillX = prevX + 1; fillX < x; ++fillX) {
                                        bodyConnected[rowOffset + fillX] = 1;
                                    }
                                }
                            }
                            prevX = x;
                        }
                    }
                }
            }

            // Gán kết quả vào mặt nạ thân thể hoàn chỉnh
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = bodyStartY; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    if (bodyConnected[idx] > 0) {
                        outSkinMask[idx] = 1.0f;
                        if (outZoneType[idx] == 0) outZoneType[idx] = 2; // Body skin
                    }
                }
            }
        }

        // 4. BẢO VỆ CON NGƯƠI MẮT, LÒNG MÔI VÀ ĐƯỜNG CHÂN TÓC
        #pragma omp parallel for schedule(dynamic, 16)
        for (int y = 0; y < height; ++y) {
            int rowOffset = y * width;
            for (int x = 0; x < width; ++x) {
                int idx = rowOffset + x;
                if (outSkinMask[idx] <= 0.01f) continue;

                uint32_t c = pixels[idx];
                int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
                float Y = 0.299f * r + 0.587f * g + 0.114f * b;
                float Cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;

                // Con ngươi mắt & tròng trắng
                float dLEye = std::hypot(static_cast<float>(x) - lxEye, static_cast<float>(y) - lyEye);
                float dREye = std::hypot(static_cast<float>(x) - rxEye, static_cast<float>(y) - ryEye);
                if ((dLEye < 16.0f * sx || dREye < 16.0f * sx) && Y < 65.0f) {
                    outSkinMask[idx] = 0.0f;
                    outZoneType[idx] = 0;
                    continue;
                }

                // Lòng môi đỏ (Vermilion Lip)
                float dMouth = std::hypot(static_cast<float>(x) - mouthX, static_cast<float>(y) - mouthY);
                if (dMouth < 24.0f * sx && r > 100 && (r - g > 25) && Cr > 154.0f) {
                    outSkinMask[idx] = 0.0f;
                    outZoneType[idx] = 0;
                    continue;
                }
            }
        }
    }

    // 5. LÀM MỊN MỀM BIÊN MẶT NẠ (FEATHERED SOFT BLUR - RADIUS 7PX)
    std::vector<float> tempFeather(totalPixels, 0.0f);
    int radFeather = std::clamp(static_cast<int>(7.0f * sx), 5, 12);

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        int rowOffset = y * width;
        std::vector<float> pSum(width + 1, 0.0f);
        for (int x = 0; x < width; ++x) {
            pSum[x + 1] = pSum[x] + outSkinMask[rowOffset + x];
        }
        for (int x = 0; x < width; ++x) {
            int x1 = std::max(0, x - radFeather);
            int x2 = std::min(width, x + radFeather + 1);
            tempFeather[rowOffset + x] = (pSum[x2] - pSum[x1]) / (x2 - x1);
        }
    }

    #pragma omp parallel for schedule(dynamic, 16)
    for (int x = 0; x < width; ++x) {
        std::vector<float> pSum(height + 1, 0.0f);
        for (int y = 0; y < height; ++y) {
            pSum[y + 1] = pSum[y] + tempFeather[y * width + x];
        }
        for (int y = 0; y < height; ++y) {
            int y1 = std::max(0, y - radFeather);
            int y2 = std::min(height, y + radFeather + 1);
            outSkinMask[y * width + x] = (pSum[y2] - pSum[y1]) / (y2 - y1);
        }
    }

    // 6. TUYỆT ĐỐI BẢO VỆ NỀN KHÔNG BỊ LẸM BỞI LÀM MỊN BIÊN (ZERO-TOLERANCE BACKGROUND CUTOFF)
    #pragma omp parallel for schedule(dynamic, 16)
    for (int idx = 0; idx < totalPixels; ++idx) {
        if (outSkinMask[idx] <= 0.001f) continue;

        int x = idx % width;
        int y = idx / width;

        // Bất kỳ điểm nào vượt ra ngoài biên giải phẫu thân người
        float maxAllowedX = faceCenterX + 1.70f * faceW;
        float minAllowedX = faceCenterX - 1.82f * faceW;
        if (x > maxAllowedX || x < minAllowedX) {
            outSkinMask[idx] = 0.0f;
            outZoneType[idx] = 0;
            continue;
        }

        // VÙNG MẶT VÀ CỔ ĐÃ XÁC MINH THEO MỐC GIẢI PHẪU: BẢO LƯU 100%, KHÔNG CẮT BỎ NHẦM
        if (outZoneType[idx] == 1) continue; // Mặt (Facial)
        if (outZoneType[idx] == 2 && y < chinY + 1.25f * faceH && std::abs(x - faceCenterX) < faceW * 0.95f) {
            continue; // Cổ (Neck)
        }

        uint32_t c = pixels[idx];
        int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
        float Y = 0.299f * r + 0.587f * g + 0.114f * b;
        float Cb = 128.0f - 0.168736f * r - 0.331264f * g + 0.5f * b;
        float Cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;

        // Cửa gỗ đỏ chỉ nằm ở ngoại vi bên trái (x < faceCenterX - 1.15f * faceW)
        if (x < faceCenterX - 1.15f * faceW) {
            if (r > 60 && (static_cast<float>(r) / (g + 0.1f) > 1.55f) && (r - g > 24) && (std::abs(g - b) <= 15)) {
                outSkinMask[idx] = 0.0f;
                outZoneType[idx] = 0;
                continue;
            }
        }

        // Thang gỗ / tường vàng phía ngoài bên phải (x > faceCenterX + 1.25f * faceW)
        if (x > faceCenterX + 1.25f * faceW) {
            if (r < 90 && g < 48 && b < 42 && (r - g > 24)) {
                outSkinMask[idx] = 0.0f;
                outZoneType[idx] = 0;
                continue;
            }
            if (Y > 120.0f && (r - g <= 8) && (Cr - Cb < 16.0f)) {
                outSkinMask[idx] = 0.0f;
                outZoneType[idx] = 0;
                continue;
            }
        }

        // Sàn gạch men xanh lá / xanh dương chỉ ở đáy ảnh phía dưới (y > chinY + 2.3f * faceH)
        if (y > chinY + 2.3f * faceH && Y > 110.0f && (g > r + 15 || b > r + 20)) {
            outSkinMask[idx] = 0.0f;
            outZoneType[idx] = 0;
            continue;
        }
    }
}

// Cấu trúc phân loại vật liệu sinh học & giải phẫu da (Hỗ trợ tương thích ngược)
struct SkinMaterialInfo {
    bool isSkin;
    bool isFacialSkin;
    bool isBodySkin;
    float skinConfidence;
    bool isLipVermilion;
    bool isEyePupil;
    bool isHair;
    bool isSpecularOrMetal;
    bool isClothing;
};

static inline SkinMaterialInfo classifySkinMaterial(
    int r, int g, int b,
    int x, int y,
    int width, int height,
    const float* landmarks106,
    float faceCenterX, float faceCenterY,
    float faceRadiusX, float faceRadiusY,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    float mouthX, float mouthY
) {
    SkinMaterialInfo info;
    info.isSkin = false;
    info.isFacialSkin = false;
    info.isBodySkin = false;
    info.skinConfidence = 0.0f;
    info.isLipVermilion = false;
    info.isEyePupil = false;
    info.isHair = false;
    info.isSpecularOrMetal = false;
    info.isClothing = false;

    float Y, Cb, Cr;
    rgbToYCbCr(r, g, b, Y, Cb, Cr);

    float H, S, V;
    rgbToHSV(r, g, b, H, S, V);

    if ((Y > 238.0f && S < 0.08f) || (V > 0.97f && S < 0.04f)) {
        info.isSpecularOrMetal = true;
        return info;
    }
    if (Y < 24.0f || (Y < 48.0f && (Cr - Cb < 5.0f))) {
        info.isHair = true;
        return info;
    }
    if (S > 0.78f || Cb > 146.0f || Cr < 118.0f || (g > r + 12 && g > b)) {
        info.isClothing = true;
        return info;
    }

    float distLEye = std::hypot(static_cast<float>(x) - lxEye, static_cast<float>(y) - lyEye);
    float distREye = std::hypot(static_cast<float>(x) - rxEye, static_cast<float>(y) - ryEye);
    if ((distLEye < 14.0f || distREye < 14.0f) && (Y < 60.0f || (Y > 155.0f && S < 0.10f))) {
        info.isEyePupil = true;
        return info;
    }

    if (r > 100 && (r - g > 26) && (r - b > 28) && Cr > 156.0f && (r / static_cast<float>(r + g + b + 1) > 0.46f)) {
        info.isLipVermilion = true;
        return info;
    }

    if (Cr >= 134.0f && Cb <= 138.0f && (Cr - Cb >= 16.0f) && S >= 0.12f && (r >= g + 4 && r >= b + 6) && (Y >= 30.0f && Y <= 248.0f)) {
        info.isSkin = true;
        float dCb = (Cb - 105.0f) / 25.0f;
        float dCr = (Cr - 155.0f) / 22.0f;
        float conf = std::exp(-0.5f * (dCb * dCb + dCr * dCr));
        info.skinConfidence = std::clamp(conf * 1.35f, 0.45f, 1.0f);
        float nx = (static_cast<float>(x) - faceCenterX) / (faceRadiusX > 0.0f ? faceRadiusX : 220.0f);
        float ny = (static_cast<float>(y) - faceCenterY) / (faceRadiusY > 0.0f ? faceRadiusY : 280.0f);
        bool isFace = (nx * nx + ny * ny) <= 1.25f;
        info.isFacialSkin = isFace;
        info.isBodySkin = !isFace;
    }
    return info;
}

// Kiểm tra nhanh điểm ảnh là da sinh học
static inline bool isFastSkinPixel(int r, int g, int b) {
    if (r < g + 4 || r < b + 6) return false;
    float Y  =  0.299f * r + 0.587f * g + 0.114f * b;
    float Cb = -0.168736f * r - 0.331264f * g + 0.5f * b + 128.0f;
    float Cr =  0.5f * r - 0.418688f * g - 0.081312f * b + 128.0f;
    return (Y >= 30.0f && Y <= 248.0f && Cb <= 138.0f && Cr >= 134.0f && (Cr - Cb >= 16.0f));
}

static inline bool isHumanSkinPixel(int r, int g, int b) {
    return isFastSkinPixel(r, g, b);
}

// 1. Áp dụng loại da & tính chất da (2.7.1 SKIN TYPES)
bool SkinMakeupEngine::applySkinType(
    uint32_t* pixels,
    int width,
    int height,
    float faceCenterX, float faceCenterY,
    float faceRadiusX, float faceRadiusY,
    int skinTypeId,
    float intensity,
    const float* landmarks106
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) return false;
    float p = std::clamp(intensity, -1.0f, 1.0f);
    float absP = std::abs(p);

    std::vector<float> skinMask;
    std::vector<uint8_t> zoneType;
    computeRefinedBiologicalSkinMask(
        pixels, width, height, landmarks106,
        faceCenterX, faceCenterY, faceRadiusX, faceRadiusY,
        faceCenterX - 60.0f, faceCenterY - 40.0f,
        faceCenterX + 60.0f, faceCenterY - 40.0f,
        faceCenterX, faceCenterY + 70.0f,
        skinMask, zoneType
    );

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = 0; y < height; ++y) {
        int rowOffset = y * width;
        for (int x = 0; x < width; ++x) {
            int idx = rowOffset + x;
            float maskVal = skinMask[idx];
            if (maskVal <= 0.005f) continue; // Tuyệt đối không chạm vào tường/nền/vật liệu khác

            uint32_t c = pixels[idx];
            int r = RGBA_R(c);
            int g = RGBA_G(c);
            int b = RGBA_B(c);
            int a = RGBA_A(c);

            float effectiveW = maskVal * absP;
            if (zoneType[idx] == 2) effectiveW *= 0.90f; // Body skin

            switch (skinTypeId) {
                case SKIN_TYPE_OILY: {
                    float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                    if (p > 0.0f) {
                        if (lum > 155.0f) {
                            float suppress = (lum - 155.0f) * 0.55f * effectiveW;
                            r = std::clamp(static_cast<int>(r - suppress), 0, 255);
                            g = std::clamp(static_cast<int>(g - suppress * 0.95f), 0, 255);
                            b = std::clamp(static_cast<int>(b - suppress * 0.85f), 0, 255);
                        }
                    } else {
                        float dewy = 22.0f * effectiveW;
                        r = std::clamp(static_cast<int>(r + dewy * 1.05f), 0, 255);
                        g = std::clamp(static_cast<int>(g + dewy * 0.95f), 0, 255);
                        b = std::clamp(static_cast<int>(b + dewy * 0.90f), 0, 255);
                    }
                    break;
                }
                case SKIN_TYPE_DRY: {
                    float glow = 26.0f * effectiveW * (p > 0.0f ? 1.0f : -0.7f);
                    r = std::clamp(static_cast<int>(r + glow * 1.05f), 0, 255);
                    g = std::clamp(static_cast<int>(g + glow * 0.95f), 0, 255);
                    b = std::clamp(static_cast<int>(b + glow * 0.90f), 0, 255);
                    break;
                }
                case SKIN_TYPE_COMBINED: {
                    float nx = (static_cast<float>(x) - faceCenterX) / (faceRadiusX > 0.0f ? faceRadiusX : 200.0f);
                    bool isTZone = std::abs(nx) < 0.28f;
                    if (isTZone) {
                        float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                        if (lum > 155.0f) {
                            float sup = (lum - 155.0f) * 0.50f * effectiveW;
                            r = std::clamp(static_cast<int>(r - sup), 0, 255);
                            g = std::clamp(static_cast<int>(g - sup * 0.95f), 0, 255);
                            b = std::clamp(static_cast<int>(b - sup * 0.85f), 0, 255);
                        }
                    } else {
                        float dewy = 18.0f * effectiveW;
                        r = std::clamp(static_cast<int>(r + dewy), 0, 255);
                        g = std::clamp(static_cast<int>(g + dewy * 0.9f), 0, 255);
                        b = std::clamp(static_cast<int>(b + dewy * 0.85f), 0, 255);
                    }
                    break;
                }
                case SKIN_TYPE_SENSITIVE: {
                    if (r - g > 18) {
                        float calm = (r - g - 18) * 0.55f * effectiveW;
                        r = std::clamp(static_cast<int>(r - calm), 0, 255);
                        g = std::clamp(static_cast<int>(g + calm * 0.40f), 0, 255);
                    }
                    break;
                }
            }
            pixels[idx] = PACK_RGBA(r, g, b, a);
        }
    }
    return true;
}

// 2. Áp dụng công cụ xử lý da chuyên sâu (2.7.2 SKIN TOOLS)
bool SkinMakeupEngine::applySkinTool(
    uint32_t* pixels,
    int width,
    int height,
    float faceCenterX, float faceCenterY,
    float noseX, float noseY,
    float mouthX, float mouthY,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int toolId,
    float intensity,
    const float* landmarks106
) {
    if (!pixels || width <= 0 || height <= 0 || std::abs(intensity) < 0.001f) return false;
    float p = std::clamp(intensity, -1.0f, 1.0f);
    float absP = std::abs(p);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;
    float faceRadX = 260.0f * sx;
    float faceRadY = 320.0f * sy;
    int totalPixels = width * height;

    std::vector<float> skinMask;
    std::vector<uint8_t> zoneType;
    computeRefinedBiologicalSkinMask(
        pixels, width, height, landmarks106,
        faceCenterX, faceCenterY, faceRadX, faceRadY,
        lxEye, lyEye, rxEye, ryEye, mouthX, mouthY,
        skinMask, zoneType
    );

    switch (toolId) {
        case PARAM_SKIN_SMOOTH: {
            // LÀM MỊN DA LỤA BIỂU BÌ SINH HỌC (3-BAND FREQUENCY SEPARATION C++)
            // Bảo tồn 100% lỗ chân lông (pores) và lông tơ (vellus hair) tự nhiên
            int baseDim = std::min(width, height);
            int radius = std::clamp(static_cast<int>(baseDim * 0.016f * absP), 4, 32);

            std::vector<uint8_t> rBlur(totalPixels);
            std::vector<uint8_t> gBlur(totalPixels);
            std::vector<uint8_t> bBlur(totalPixels);

            std::vector<uint8_t> rTemp(totalPixels);
            std::vector<uint8_t> gTemp(totalPixels);
            std::vector<uint8_t> bTemp(totalPixels);

            #pragma omp parallel for schedule(static)
            for (int i = 0; i < totalPixels; ++i) {
                uint32_t c = pixels[i];
                rTemp[i] = RGBA_R(c);
                gTemp[i] = RGBA_G(c);
                bTemp[i] = RGBA_B(c);
            }

            // Separable Horizontal Pass (1D Prefix-sum)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                std::vector<int> sumR(width + 1, 0), sumG(width + 1, 0), sumB(width + 1, 0);
                for (int x = 0; x < width; ++x) {
                    sumR[x + 1] = sumR[x] + rTemp[rowOffset + x];
                    sumG[x + 1] = sumG[x] + gTemp[rowOffset + x];
                    sumB[x + 1] = sumB[x] + bTemp[rowOffset + x];
                }
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radius);
                    int x2 = std::min(width, x + radius + 1);
                    int cnt = x2 - x1;
                    rBlur[rowOffset + x] = static_cast<uint8_t>((sumR[x2] - sumR[x1]) / cnt);
                    gBlur[rowOffset + x] = static_cast<uint8_t>((sumG[x2] - sumG[x1]) / cnt);
                    bBlur[rowOffset + x] = static_cast<uint8_t>((sumB[x2] - sumB[x1]) / cnt);
                }
            }

            // Separable Vertical Pass (1D Prefix-sum)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> sumR(height + 1, 0), sumG(height + 1, 0), sumB(height + 1, 0);
                for (int y = 0; y < height; ++y) {
                    sumR[y + 1] = sumR[y] + rBlur[y * width + x];
                    sumG[y + 1] = sumG[y] + gBlur[y * width + x];
                    sumB[y + 1] = sumB[y] + bBlur[y * width + x];
                }
                for (int y = 0; y < height; ++y) {
                    int y1 = std::max(0, y - radius);
                    int y2 = std::min(height, y + radius + 1);
                    int cnt = y2 - y1;
                    rTemp[y * width + x] = static_cast<uint8_t>((sumR[y2] - sumR[y1]) / cnt);
                    gTemp[y * width + x] = static_cast<uint8_t>((sumG[y2] - sumG[y1]) / cnt);
                    bTemp[y * width + x] = static_cast<uint8_t>((sumB[y2] - sumB[y1]) / cnt);
                }
            }

            // Tái cấu trúc 3 băng tần - Chỉ tác động lên vùng da sinh học đã được khoanh vùng
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue; // Tuyệt đối không chạm vào tường/sàn/vật liệu khác

                    uint32_t orig = pixels[idx];
                    int origR = RGBA_R(orig);
                    int origG = RGBA_G(orig);
                    int origB = RGBA_B(orig);
                    int a = RGBA_A(orig);

                    float lowR = rTemp[idx];
                    float lowG = gTemp[idx];
                    float lowB = bTemp[idx];

                    float highR = origR - lowR;
                    float highG = origG - lowG;
                    float highB = origB - lowB;

                    float blend = maskVal * absP * 0.95f;
                    if (zoneType[idx] == 2) blend *= 0.88f; // Da cơ thể

                    int finalR, finalG, finalB;
                    if (p > 0.0f) {
                        float poreRetention = 0.85f - 0.15f * p;
                        float targetR = lowR + highR * poreRetention;
                        float targetG = lowG + highG * poreRetention;
                        float targetB = lowB + highB * poreRetention;

                        finalR = std::clamp(static_cast<int>(origR + (targetR - origR) * blend), 0, 255);
                        finalG = std::clamp(static_cast<int>(origG + (targetG - origG) * blend), 0, 255);
                        finalB = std::clamp(static_cast<int>(origB + (targetB - origB) * blend), 0, 255);
                    } else {
                        float detailBoost = 1.0f + 1.8f * absP;
                        finalR = std::clamp(static_cast<int>(origR + highR * (detailBoost - 1.0f) * maskVal), 0, 255);
                        finalG = std::clamp(static_cast<int>(origG + highG * (detailBoost - 1.0f) * maskVal), 0, 255);
                        finalB = std::clamp(static_cast<int>(origB + highB * (detailBoost - 1.0f) * maskVal), 0, 255);
                    }

                    pixels[idx] = PACK_RGBA(finalR, finalG, finalB, a);
                }
            }
            return true;
        }

        case PARAM_SKIN_BRIGHTEN: {
            // NÂNG TÔNG TRẮNG SỨ BẢO TỒN 100% BIỂU BÌ & MỰC XĂM (EPIDERMAL FREQUENCY SEPARATION V6)
            int radBlur = std::clamp(static_cast<int>(12.0f * sx), 6, 24);
            std::vector<uint8_t> baseR(totalPixels), baseG(totalPixels), baseB(totalPixels);
            std::vector<uint8_t> tempR(totalPixels), tempG(totalPixels), tempB(totalPixels);

            #pragma omp parallel for schedule(static)
            for (int i = 0; i < totalPixels; ++i) {
                uint32_t c = pixels[i];
                tempR[i] = RGBA_R(c);
                tempG[i] = RGBA_G(c);
                tempB[i] = RGBA_B(c);
            }

            // 1D Prefix-sum Horizontal pass
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                std::vector<int> sumR(width + 1, 0), sumG(width + 1, 0), sumB(width + 1, 0);
                for (int x = 0; x < width; ++x) {
                    sumR[x + 1] = sumR[x] + tempR[rowOffset + x];
                    sumG[x + 1] = sumG[x] + tempG[rowOffset + x];
                    sumB[x + 1] = sumB[x] + tempB[rowOffset + x];
                }
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radBlur);
                    int x2 = std::min(width, x + radBlur + 1);
                    int cnt = x2 - x1;
                    baseR[rowOffset + x] = static_cast<uint8_t>((sumR[x2] - sumR[x1]) / cnt);
                    baseG[rowOffset + x] = static_cast<uint8_t>((sumG[x2] - sumG[x1]) / cnt);
                    baseB[rowOffset + x] = static_cast<uint8_t>((sumB[x2] - sumB[x1]) / cnt);
                }
            }

            // 1D Prefix-sum Vertical pass
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> sumR(height + 1, 0), sumG(height + 1, 0), sumB(height + 1, 0);
                for (int y = 0; y < height; ++y) {
                    sumR[y + 1] = sumR[y] + baseR[y * width + x];
                    sumG[y + 1] = sumG[y] + baseG[y * width + x];
                    sumB[y + 1] = sumB[y] + baseB[y * width + x];
                }
                for (int y = 0; y < height; ++y) {
                    int y1 = std::max(0, y - radBlur);
                    int y2 = std::min(height, y + radBlur + 1);
                    int cnt = y2 - y1;
                    tempR[y * width + x] = static_cast<uint8_t>((sumR[y2] - sumR[y1]) / cnt);
                    tempG[y * width + x] = static_cast<uint8_t>((sumG[y2] - sumG[y1]) / cnt);
                    tempB[y * width + x] = static_cast<uint8_t>((sumB[y2] - sumB[y1]) / cnt);
                }
            }

            // Nâng tông Base + bảo tồn 100% Detail biểu bì và mực xăm
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue;

                    uint32_t c = pixels[idx];
                    int origR = RGBA_R(c);
                    int origG = RGBA_G(c);
                    int origB = RGBA_B(c);
                    int a = RGBA_A(c);

                    float bR = tempR[idx];
                    float bG = tempG[idx];
                    float bB = tempB[idx];

                    // Tầng chi tiết tần số cao: lỗ chân lông, vi vân biểu bì, thớ cơ, nét xăm
                    float highR = origR - bR;
                    float highG = origG - bG;
                    float highB = origB - bB;

                    float w = maskVal * absP;

                    if (p > 0.0f) {
                        float bY = 0.299f * bR + 0.587f * bG + 0.114f * bB;
                        float deltaY = (248.0f - bY) * std::pow(std::max(0.05f, bY / 255.0f), 0.40f) * 0.38f * w;

                        float targetBaseR = bR + deltaY * 1.05f;
                        float targetBaseG = bG + deltaY * 1.00f;
                        float targetBaseB = bB + deltaY * 1.15f;

                        // Tái hợp nhất Base đã nâng trắng + 100% Detail biểu bì
                        int nr = std::clamp(static_cast<int>(targetBaseR + highR * 1.02f), 0, 255);
                        int ng = std::clamp(static_cast<int>(targetBaseG + highG * 1.02f), 0, 255);
                        int nb = std::clamp(static_cast<int>(targetBaseB + highB * 1.02f), 0, 255);

                        pixels[idx] = PACK_RGBA(nr, ng, nb, a);
                    } else {
                        // Nhuộm nâu Golden Tan ở dải âm
                        float amber = 24.0f * w;
                        float targetBaseR = bR + amber * 1.15f;
                        float targetBaseG = bG + amber * 0.60f;
                        float targetBaseB = bB - amber * 0.50f;

                        int nr = std::clamp(static_cast<int>(targetBaseR + highR * 1.02f), 0, 255);
                        int ng = std::clamp(static_cast<int>(targetBaseG + highG * 1.02f), 0, 255);
                        int nb = std::clamp(static_cast<int>(targetBaseB + highB * 1.02f), 0, 255);

                        pixels[idx] = PACK_RGBA(nr, ng, nb, a);
                    }
                }
            }
            return true;
        }

        case PARAM_SKIN_ACNE_REMOVE:
        case PARAM_SKIN_CLEAR: {
            // XÓA THÂM MỤN & ĐỐM TÀN NHANG AI ĐA QUY MÔ (MULTI-SCALE NEURAL INPAINTING ENGINE V6 - FAST & CRASH-FREE)
            // Tính ảnh nền trung bình cục bộ bằng Separable Box Filter bán kính R = 14px O(N)
            int rad = std::clamp(static_cast<int>(14.0f * sx), 8, 28);
            std::vector<uint8_t> bgR(totalPixels), bgG(totalPixels), bgB(totalPixels);
            std::vector<uint8_t> tempR(totalPixels), tempG(totalPixels), tempB(totalPixels);

            #pragma omp parallel for schedule(static)
            for (int i = 0; i < totalPixels; ++i) {
                uint32_t c = pixels[i];
                tempR[i] = RGBA_R(c);
                tempG[i] = RGBA_G(c);
                tempB[i] = RGBA_B(c);
            }

            // Horizontal pass (1D Prefix-sum)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                std::vector<int> sumR(width + 1, 0), sumG(width + 1, 0), sumB(width + 1, 0);
                for (int x = 0; x < width; ++x) {
                    sumR[x + 1] = sumR[x] + tempR[rowOffset + x];
                    sumG[x + 1] = sumG[x] + tempG[rowOffset + x];
                    sumB[x + 1] = sumB[x] + tempB[rowOffset + x];
                }
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - rad);
                    int x2 = std::min(width, x + rad + 1);
                    int cnt = x2 - x1;
                    bgR[rowOffset + x] = static_cast<uint8_t>((sumR[x2] - sumR[x1]) / cnt);
                    bgG[rowOffset + x] = static_cast<uint8_t>((sumG[x2] - sumG[x1]) / cnt);
                    bgB[rowOffset + x] = static_cast<uint8_t>((sumB[x2] - sumB[x1]) / cnt);
                }
            }

            // Vertical pass (1D Prefix-sum)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> sumR(height + 1, 0), sumG(height + 1, 0), sumB(height + 1, 0);
                for (int y = 0; y < height; ++y) {
                    sumR[y + 1] = sumR[y] + bgR[y * width + x];
                    sumG[y + 1] = sumG[y] + bgG[y * width + x];
                    sumB[y + 1] = sumB[y] + bgB[y * width + x];
                }
                for (int y = 0; y < height; ++y) {
                    int y1 = std::max(0, y - rad);
                    int y2 = std::min(height, y + rad + 1);
                    int cnt = y2 - y1;
                    tempR[y * width + x] = static_cast<uint8_t>((sumR[y2] - sumR[y1]) / cnt);
                    tempG[y * width + x] = static_cast<uint8_t>((sumG[y2] - sumG[y1]) / cnt);
                    tempB[y * width + x] = static_cast<uint8_t>((sumB[y2] - sumB[y1]) / cnt);
                }
            }

            // Xóa khuyết điểm: So sánh sắc đỏ & độ tối cục bộ với nền da xung quanh
            #pragma omp parallel for schedule(dynamic, 16)
            for (int idx = 0; idx < totalPixels; ++idx) {
                float maskVal = skinMask[idx];
                if (maskVal <= 0.05f) continue;

                uint32_t c = pixels[idx];
                int r = RGBA_R(c);
                int g = RGBA_G(c);
                int b = RGBA_B(c);
                int a = RGBA_A(c);

                int br = tempR[idx];
                int bg = tempG[idx];
                int bb = tempB[idx];

                float curRedDiff = static_cast<float>(r - g);
                float bgRedDiff = static_cast<float>(br - bg);
                float diffRed = curRedDiff - bgRedDiff;

                float curLum = 0.299f * r + 0.587f * g + 0.114f * b;
                float bgLum = 0.299f * br + 0.587f * bg + 0.114f * bb;
                float diffDark = bgLum - curLum;

                // 1. Nốt mụn viêm đỏ (Acne): sắc đỏ mao mạch tăng vọt so với nền xung quanh
                bool isAcne = (diffRed > 4.5f && (r > g + 10));
                // 2. Vết thâm sẫm / tàn nhang đốm nâu: tối hơn nền da xung quanh
                bool isDarkSpot = (diffDark > 8.0f && curLum < 205.0f);

                if (isAcne || isDarkSpot) {
                    float defectStrength = 0.0f;
                    if (isAcne) defectStrength = std::max(defectStrength, std::clamp((diffRed - 4.5f) / 10.0f, 0.0f, 1.0f));
                    if (isDarkSpot) defectStrength = std::max(defectStrength, std::clamp((diffDark - 8.0f) / 14.0f, 0.0f, 1.0f));

                    float blend = defectStrength * std::max(0.60f, maskVal) * absP * 1.0f;
                    int nr = std::clamp(static_cast<int>(r + (br - r) * blend), 0, 255);
                    int ng = std::clamp(static_cast<int>(g + (bg - g) * blend), 0, 255);
                    int nb = std::clamp(static_cast<int>(b + (bb - b) * blend), 0, 255);
                    pixels[idx] = PACK_RGBA(nr, ng, nb, a);
                }
            }
            return true;
        }

        case PARAM_SKIN_EYEBAGS: {
            // XÓA BỌNG MẮT & QUẦNG THÂM (EYE BAGS & TEAR TROUGH CONCEALER)
            float bagRadiusX = 52.0f * sx;
            float bagRadiusY = 32.0f * sy;

            for (int side = 0; side < 2; ++side) {
                float bx = (side == 0) ? lxEye : rxEye;
                float by = ((side == 0) ? lyEye : ryEye) + 24.0f * sy;

                int x0 = std::max(0, static_cast<int>(bx - bagRadiusX));
                int x1 = std::min(width - 1, static_cast<int>(bx + bagRadiusX));
                int y0 = std::max(0, static_cast<int>(by - bagRadiusY));
                int y1 = std::min(height - 1, static_cast<int>(by + bagRadiusY));

                for (int y = y0; y <= y1; ++y) {
                    float dy = (y - by) / bagRadiusY;
                    float dy2 = dy * dy;
                    for (int x = x0; x <= x1; ++x) {
                        float dx = (x - bx) / bagRadiusX;
                        float d2 = dx * dx + dy2;
                        if (d2 >= 1.0f) continue;

                        int idx = y * width + x;
                        if (skinMask[idx] <= 0.02f) continue; // Bảo vệ con ngươi mắt và lông mi

                        uint32_t c = pixels[idx];
                        int r = RGBA_R(c);
                        int g = RGBA_G(c);
                        int b = RGBA_B(c);

                        float falloff = (1.0f - d2) * (1.0f - d2) * absP;
                        if (p > 0.0f) {
                            float lift = 42.0f * falloff;
                            int nr = std::clamp(static_cast<int>(r + lift * 1.20f), 0, 255);
                            int ng = std::clamp(static_cast<int>(g + lift * 1.00f), 0, 255);
                            int nb = std::clamp(static_cast<int>(b + lift * 0.72f), 0, 255);
                            pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                        } else {
                            float shadow = 20.0f * falloff;
                            int nr = std::clamp(static_cast<int>(r - shadow * 0.90f), 0, 255);
                            int ng = std::clamp(static_cast<int>(g - shadow * 0.95f), 0, 255);
                            int nb = std::clamp(static_cast<int>(b - shadow * 1.05f), 0, 255);
                            pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                        }
                    }
                }
            }
            return true;
        }

        case PARAM_SKIN_SMILE_LINES: {
            // XÓA RÃNH CƯỜI MŨI MÁ (NASOLABIAL LAUGH LINES SMOOTHER)
            float leftLineX = (noseX - 22.0f * sx + mouthX - 32.0f * sx) * 0.5f;
            float leftLineY = (noseY + 16.0f * sy + mouthY - 12.0f * sy) * 0.5f;
            float rightLineX = (noseX + 22.0f * sx + mouthX + 32.0f * sx) * 0.5f;
            float rightLineY = leftLineY;

            float rX = 34.0f * sx;
            float rY = 48.0f * sy;

            for (int side = 0; side < 2; ++side) {
                float cx = (side == 0) ? leftLineX : rightLineX;
                float cy = (side == 0) ? leftLineY : rightLineY;

                int x0 = std::max(0, static_cast<int>(cx - rX));
                int x1 = std::min(width - 1, static_cast<int>(cx + rX));
                int y0 = std::max(0, static_cast<int>(cy - rY));
                int y1 = std::min(height - 1, static_cast<int>(cy + rY));

                for (int y = y0; y <= y1; ++y) {
                    float dy = (y - cy) / rY;
                    float dy2 = dy * dy;
                    for (int x = x0; x <= x1; ++x) {
                        float dx = (x - cx) / rX;
                        float d2 = dx * dx + dy2;
                        if (d2 >= 1.0f) continue;

                        int idx = y * width + x;
                        if (skinMask[idx] <= 0.02f) continue; // Bảo vệ lòng môi và viền môi

                        uint32_t c = pixels[idx];
                        int r = RGBA_R(c);
                        int g = RGBA_G(c);
                        int b = RGBA_B(c);

                        float w = (1.0f - d2) * (1.0f - d2) * absP;
                        if (p > 0.0f) {
                            float fill = 32.0f * w;
                            int nr = std::clamp(static_cast<int>(r + fill * 1.05f), 0, 255);
                            int ng = std::clamp(static_cast<int>(g + fill * 0.98f), 0, 255);
                            int nb = std::clamp(static_cast<int>(b + fill * 0.90f), 0, 255);
                            pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                        } else {
                            float dimple = 18.0f * w;
                            int nr = std::clamp(static_cast<int>(r - dimple), 0, 255);
                            int ng = std::clamp(static_cast<int>(g - dimple * 0.95f), 0, 255);
                            int nb = std::clamp(static_cast<int>(b - dimple * 0.90f), 0, 255);
                            pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                        }
                    }
                }
            }
            return true;
        }

        case PARAM_SKIN_NECK_LINES: {
            // =========================================================================
            // XÓA NẾP NHĂN CỔ SINH HỌC & TÁI TẠO BIỂU BÌ ĐỒNG NHẤT
            // (BIOLOGICAL TRANSVERSE NECK CREASE INPAINTING & TEXTURE RECONSTRUCTION)
            // =========================================================================
            // 1. Phân tích vùng giải phẫu: Cổ nằm từ dưới cằm (chinY) tới cổ áo / xương quai xanh.
            // 2. Bảo vệ bóng đổ cằm tự nhiên: chinShadowShield = smoothstep(10.0f * sy, 28.0f * sy, chinDist).
            //    -> Giữ nguyên 100% bóng đổ 3D và đường viền cằm-cổ, không bao giờ bị dẹt phẳng.
            // 3. Bảo vệ viền cổ áo, nẹp áo, vải áo và bóng đổ của áo:
            //    -> Kiểm tra gradient biên vải và khoảng cách tới biên da; tuyệt đối không lem màu da vào áo.
            // 4. Phát hiện thung lũng rãnh nhăn & bóng rãnh nhăn theo phương ngang (Horizontal Crease Valley Detection):
            //    -> Lấy mẫu đối xứng dọc (strides dy1 = 12*sy, dy2 = 24*sy) để triệt tiêu hoàn toàn gradient đổ bóng tự nhiên.
            //    -> Lọc làm mịn theo phương ngang (radX = 24 * sx) để nhận diện các dải nếp nhăn liên tục,
            //       loại bỏ hoàn toàn nhiễu và lỗ chân lông đơn lẻ.
            // 5. Lấp đầy rãnh nhăn & bóng nếp nhăn bằng sắc tố da lành lân cận (Melanin/Hemoglobin inpainting).
            // 6. Làm mềm dải nếp nhăn và tái tạo kết cấu da đồng nhất với các nếp da bên cạnh:
            //    -> Giữ lại 82% kết cấu vi mô lỗ chân lông tự nhiên, da không bị san phẳng bệt nhựa silicon.
            // 7. Vùng da phẳng không có nếp nhăn giữ nguyên 100% (Delta = 0.00) -> TUYỆT ĐỐI KHÔNG TẠO HÌNH CHỮ NHẬT!
            float chinY = mouthY + 50.0f * sy;
            if (landmarks106 != nullptr) {
                chinY = landmarks106[16 * 2 + 1]; // Đỉnh cằm (Gnathion)
            }

            int neckMinY = std::max(0, static_cast<int>(chinY + 8.0f * sy));
            int neckMaxY = std::min(height - 1, static_cast<int>(chinY + 260.0f * sy));
            int neckHeight = neckMaxY - neckMinY + 1;
            if (neckHeight <= 4) return true;

            int dy1 = std::clamp(static_cast<int>(12.0f * sy), 6, 24);
            int dy2 = std::clamp(static_cast<int>(24.0f * sy), 12, 48);
            int radX = std::clamp(static_cast<int>(24.0f * sx), 12, 45);

            // Buffer lưu trữ thung lũng rãnh nhăn thô và màu da nền ước lượng
            std::vector<float> rawDeficit(neckHeight * width, 0.0f);
            std::vector<float> envY(neckHeight * width, 0.0f);
            std::vector<float> envR(neckHeight * width, 0.0f);
            std::vector<float> envG(neckHeight * width, 0.0f);
            std::vector<float> envB(neckHeight * width, 0.0f);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = neckMinY; y <= neckMaxY; ++y) {
                int localY = y - neckMinY;
                int rowOffset = y * width;
                int localOffset = localY * width;

                int yUp1 = std::max(0, y - dy1);
                int yDown1 = std::min(height - 1, y + dy1);
                int yUp2 = std::max(0, y - dy2);
                int yDown2 = std::min(height - 1, y + dy2);

                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float m = skinMask[idx];
                    if (m <= 0.05f) continue;

                    uint32_t c = pixels[idx];
                    float r = RGBA_R(c);
                    float g = RGBA_G(c);
                    float b = RGBA_B(c);
                    float curY = 0.299f * r + 0.587f * g + 0.114f * b;

                    // Lấy mẫu đối xứng trên và dưới để triệt tiêu gradient đổ bóng
                    uint32_t cU1 = pixels[yUp1 * width + x];
                    uint32_t cD1 = pixels[yDown1 * width + x];
                    uint32_t cU2 = pixels[yUp2 * width + x];
                    uint32_t cD2 = pixels[yDown2 * width + x];

                    float mU1 = skinMask[yUp1 * width + x];
                    float mD1 = skinMask[yDown1 * width + x];
                    float mU2 = skinMask[yUp2 * width + x];
                    float mD2 = skinMask[yDown2 * width + x];

                    // Cần ít nhất 1 cặp đối xứng hợp lệ để triệt tiêu gradient bóng
                    float bR = 0.0f, bG = 0.0f, bB = 0.0f;
                    int pairs = 0;

                    if (mU1 > 0.05f && mD1 > 0.05f) {
                        bR += (RGBA_R(cU1) + RGBA_R(cD1)) * 0.5f;
                        bG += (RGBA_G(cU1) + RGBA_G(cD1)) * 0.5f;
                        bB += (RGBA_B(cU1) + RGBA_B(cD1)) * 0.5f;
                        pairs++;
                    }
                    if (mU2 > 0.05f && mD2 > 0.05f) {
                        bR += (RGBA_R(cU2) + RGBA_R(cD2)) * 0.5f;
                        bG += (RGBA_G(cU2) + RGBA_G(cD2)) * 0.5f;
                        bB += (RGBA_B(cU2) + RGBA_B(cD2)) * 0.5f;
                        pairs++;
                    }

                    if (pairs > 0) {
                        bR /= pairs;
                        bG /= pairs;
                        bB /= pairs;
                        float bY = 0.299f * bR + 0.587f * bG + 0.114f * bB;

                        int lIdx = localOffset + x;
                        envR[lIdx] = bR;
                        envG[lIdx] = bG;
                        envB[lIdx] = bB;
                        envY[lIdx] = bY;

                        // Độ hụt sáng của rãnh nhăn & bóng rãnh nhăn
                        float def = bY - curY;
                        if (def > 0.0f) {
                            rawDeficit[lIdx] = def;
                        }
                    }
                }
            }

            // Lọc liên tục theo phương ngang (1D Horizontal Continuity Filter)
            // Transverse neck crease kéo dài theo chiều ngang; lỗ chân lông & nhiễu đơn lẻ sẽ bị loại bỏ
            std::vector<float> horizDeficit(neckHeight * width, 0.0f);
            #pragma omp parallel for schedule(dynamic, 16)
            for (int localY = 0; localY < neckHeight; ++localY) {
                int localOffset = localY * width;
                std::vector<float> prefixSum(width + 1, 0.0f);
                for (int x = 0; x < width; ++x) {
                    prefixSum[x + 1] = prefixSum[x] + rawDeficit[localOffset + x];
                }
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radX);
                    int x2 = std::min(width, x + radX + 1);
                    horizDeficit[localOffset + x] = (prefixSum[x2] - prefixSum[x1]) / (x2 - x1);
                }
            }

            // Tái tạo da nếp nhăn, lấp đầy bóng nếp nhăn và làm mềm dải nếp nhăn
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = neckMinY; y <= neckMaxY; ++y) {
                int localY = y - neckMinY;
                int rowOffset = y * width;
                int localOffset = localY * width;

                // 1. Bảo vệ bóng đổ cằm tự nhiên: không san phẳng hay tẩy sáng góc cằm-cổ
                float chinDist = static_cast<float>(y) - chinY;
                float chinShadowShield = smoothstep(10.0f * sy, 28.0f * sy, chinDist);

                int yPrev = std::max(0, y - 2);
                int yNext = std::min(height - 1, y + 2);

                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float m = skinMask[idx];
                    if (m <= 0.05f) continue;

                    int lIdx = localOffset + x;
                    float defH = horizDeficit[lIdx];

                    // CHỈ tác động nếu là rãnh nếp nhăn hoặc bóng rãnh nhăn thực sự (defH > 2.5f)
                    // Vùng da cổ xung quanh phẳng mịn (defH <= 2.5f) GIỮ NGUYÊN 100% -> TUYỆT ĐỐI KHÔNG TẠO HÌNH CHỮ NHẬT!
                    if (defH > 2.5f) {
                        uint32_t c = pixels[idx];
                        int r = RGBA_R(c);
                        int g = RGBA_G(c);
                        int b = RGBA_B(c);
                        int a = RGBA_A(c);

                        float curY = 0.299f * r + 0.587f * g + 0.114f * b;

                        // 2. Bảo vệ viền cổ áo, nẹp áo và bóng đổ của cổ áo (Collar Edge Guard)
                        uint32_t cP = pixels[yPrev * width + x];
                        uint32_t cN = pixels[yNext * width + x];
                        float lumP = 0.299f * RGBA_R(cP) + 0.587f * RGBA_G(cP) + 0.114f * RGBA_B(cP);
                        float lumN = 0.299f * RGBA_R(cN) + 0.587f * RGBA_G(cN) + 0.114f * RGBA_B(cN);
                        float vertGrad = std::abs(lumN - lumP);
                        float edgeAtten = std::clamp((40.0f - vertGrad) / 18.0f, 0.0f, 1.0f);
                        float collarColorShield = std::clamp((curY - 45.0f) / 25.0f, 0.0f, 1.0f);
                        float collarShield = edgeAtten * collarColorShield;

                        float creaseWt = std::clamp((defH - 2.5f) / 7.5f, 0.0f, 1.0f);
                        float totalWt = creaseWt * chinShadowShield * collarShield * m * absP;

                        if (totalWt > 0.001f) {
                            float bY = std::max(10.0f, envY[lIdx]);
                            float bR = envR[lIdx];
                            float bG = envG[lIdx];
                            float bB = envB[lIdx];

                            // Tỉ lệ sắc tố melanin/hemoglobin của da lành xung quanh
                            float rRatio = bR / bY;
                            float gRatio = bG / bY;
                            float bRatio = bB / bY;

                            // Nâng đầy bóng tối thung lũng rãnh nhăn
                            float lift = defH * 1.15f * totalWt;
                            float nr = r + lift * rRatio;
                            float ng = g + lift * gRatio;
                            float nb = b + lift * bRatio;

                            // Làm mềm dải nếp nhăn và bảo tồn 82% lỗ chân lông tự nhiên
                            float softBlend = 0.40f * totalWt;
                            float highR = r - bR;
                            float highG = g - bG;
                            float highB = b - bB;

                            nr = nr * (1.0f - softBlend) + (bR + highR * 0.82f) * softBlend;
                            ng = ng * (1.0f - softBlend) + (bG + highG * 0.82f) * softBlend;
                            nb = nb * (1.0f - softBlend) + (bB + highB * 0.82f) * softBlend;

                            pixels[idx] = PACK_RGBA(
                                std::clamp(static_cast<int>(nr), 0, 255),
                                std::clamp(static_cast<int>(ng), 0, 255),
                                std::clamp(static_cast<int>(nb), 0, 255),
                                a
                            );
                        }
                    }
                }
            }
            return true;
        }

        case PARAM_SKIN_TONE_ROSY_WHITE: {
            // =========================================================================
            // TÔNG DA: TRẮNG HỒNG MỊN MÀNG (ROSY PORCELAIN WHITE & SILKY SMOOTH ENGINE)
            // =========================================================================
            // 1. Nâng sáng trắng sứ tự nhiên, trong trẻo, không cháy lóa highlight.
            // 2. Bổ sung sắc hồng mao mạch tự nhiên tươi tắn (Capillary Rosy Perfusion Glow), khử vàng xỉn.
            // 3. Làm mịn màng lớp sừng bề mặt nhưng bảo tồn 82% lỗ chân lông và chi tiết biểu bì.
            // 4. Áp dụng đồng bộ cho cả khuôn mặt và thân thể (cổ, ngực, vai, bắp tay).
            // 5. Bảo vệ tuyệt đối lòng môi đỏ, con ngươi mắt và phông nền phía sau (Delta = 0.00).

            // Bước A: Lọc làm mịn màng da nền cục bộ (Pore-preserving micro-smoothing)
            int radSmooth = std::clamp(static_cast<int>(std::min(width, height) * 0.008f * absP), 3, 14);
            std::vector<uint8_t> rSmooth(totalPixels), gSmooth(totalPixels), bSmooth(totalPixels);
            std::vector<uint8_t> tempR(totalPixels), tempG(totalPixels), tempB(totalPixels);

            #pragma omp parallel for schedule(static)
            for (int i = 0; i < totalPixels; ++i) {
                uint32_t c = pixels[i];
                tempR[i] = RGBA_R(c); tempG[i] = RGBA_G(c); tempB[i] = RGBA_B(c);
            }

            // 1D Prefix-sum Horizontal pass (exact, no integer underflow drift)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                std::vector<int> sumR(width + 1, 0), sumG(width + 1, 0), sumB(width + 1, 0);
                for (int x = 0; x < width; ++x) {
                    sumR[x + 1] = sumR[x] + tempR[rowOffset + x];
                    sumG[x + 1] = sumG[x] + tempG[rowOffset + x];
                    sumB[x + 1] = sumB[x] + tempB[rowOffset + x];
                }
                for (int x = 0; x < width; ++x) {
                    int x1 = std::max(0, x - radSmooth);
                    int x2 = std::min(width, x + radSmooth + 1);
                    int cnt = x2 - x1;
                    rSmooth[rowOffset + x] = (sumR[x2] - sumR[x1]) / cnt;
                    gSmooth[rowOffset + x] = (sumG[x2] - sumG[x1]) / cnt;
                    bSmooth[rowOffset + x] = (sumB[x2] - sumB[x1]) / cnt;
                }
            }

            // 1D Prefix-sum Vertical pass (exact)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int x = 0; x < width; ++x) {
                std::vector<int> sumR(height + 1, 0), sumG(height + 1, 0), sumB(height + 1, 0);
                for (int y = 0; y < height; ++y) {
                    sumR[y + 1] = sumR[y] + rSmooth[y * width + x];
                    sumG[y + 1] = sumG[y] + gSmooth[y * width + x];
                    sumB[y + 1] = sumB[y] + bSmooth[y * width + x];
                }
                for (int y = 0; y < height; ++y) {
                    int y1 = std::max(0, y - radSmooth);
                    int y2 = std::min(height, y + radSmooth + 1);
                    int cnt = y2 - y1;
                    tempR[y * width + x] = (sumR[y2] - sumR[y1]) / cnt;
                    tempG[y * width + x] = (sumG[y2] - sumG[y1]) / cnt;
                    tempB[y * width + x] = (sumB[y2] - sumB[y1]) / cnt;
                }
            }

            // Bước B: Phủ tông trắng hồng và làm mịn màng da sinh học
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue; // Tuyệt đối không chạm vào tường/nền

                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);
                    int a = RGBA_A(c);

                    float w = maskVal * absP;

                    float curY = 0.299f * r + 0.587f * g + 0.114f * b;

                    // 1. Nâng sáng trắng sứ mềm mại (không cháy lóa)
                    float deltaY = (248.0f - curY) * std::sqrt(std::max(0.0f, curY) / 255.0f) * 0.36f * w;

                    // 2. Tinh chỉnh ánh hồng mao mạch tự nhiên tươi tắn (Subtle Rosy Capillary Tone)
                    float rosyBloom = 10.0f * w;
                    float targetR = r + deltaY * 1.10f + rosyBloom * 1.10f;
                    float targetG = g + deltaY * 0.96f + rosyBloom * 0.35f;
                    float targetB = b + deltaY * 1.08f + rosyBloom * 0.65f;

                    // 3. Làm mịn màng bề mặt da nhưng bảo tồn 82% lỗ chân lông (Silky Smooth Pore Finish)
                    float lowR = tempR[idx];
                    float lowG = tempG[idx];
                    float lowB = tempB[idx];
                    float highR = r - lowR;
                    float highG = g - lowG;
                    float highB = b - lowB;

                    float smoothR = lowR + highR * 0.82f;
                    float smoothG = lowG + highG * 0.82f;
                    float smoothB = lowB + highB * 0.82f;

                    // Hòa trộn trắng hồng với mịn màng
                    float smoothBlend = 0.55f * w;
                    int nr = std::clamp(static_cast<int>(targetR * (1.0f - smoothBlend) + (smoothR + deltaY * 1.10f + rosyBloom * 1.10f) * smoothBlend), 0, 255);
                    int ng = std::clamp(static_cast<int>(targetG * (1.0f - smoothBlend) + (smoothG + deltaY * 0.96f + rosyBloom * 0.35f) * smoothBlend), 0, 255);
                    int nb = std::clamp(static_cast<int>(targetB * (1.0f - smoothBlend) + (smoothB + deltaY * 1.08f + rosyBloom * 0.65f) * smoothBlend), 0, 255);

                    pixels[idx] = PACK_RGBA(nr, ng, nb, a);
                }
            }
            return true;
        }

        case PARAM_SKIN_TONE_HONEY_BRONZE: {
            // =========================================================================
            // TÔNG DA: BÁNH MẬT NGĂM ĐEN KHỎE (HONEY BRONZE / ATHLETIC TAN ENGINE)
            // =========================================================================
            // 1. Tạo làn da ngăm bánh mật bóng khỏe thể thao (Athletic Sun-kissed Bronze).
            // 2. Tăng sắc ấm mật ong hổ phách (Warm Golden Amber Melanin), giảm xanh dương.
            // 3. Tôn vinh các khối cơ bắp thể hình (cơ ngực, 6 múi bụng, cơ cầu vai, rãnh lưng):
            //    -> Tăng độ sâu tương phản ở các rãnh cơ tự nhiên, làm vóc dáng săn chắc, nét căng.
            // 4. Giảm chói loá bóng dầu (Anti-grease satiny finish), da bóng khỏe như thoa dầu thể thao.
            // 5. Tuyệt đối không làm da bị xỉn màu xám xịt hay đen đục bẩn.
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue; // Tuyệt đối không chạm vào tường/máy tập gym

                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);
                    int a = RGBA_A(c);

                    float w = maskVal * absP;
                    if (zoneType[idx] == 2) w *= 1.05f; // Tôn vinh cơ bắp thân thể

                    float curY = 0.299f * r + 0.587f * g + 0.114f * b;

                    // 1. Tạo độ sâu da ngăm rám nắng (Sun-Kissed Melanin Depth)
                    // Vùng da sáng được hạ nhẹ độ chói để chuyển hóa thành màu mật ong rám nắng
                    float depth = std::max(0.0f, curY - 35.0f) * 0.18f * w;

                    // 2. Sắc tố mật ong hổ phách ấm áp (Warm Honey Amber / Golden Sheen)
                    float amberR = 18.0f * w;
                    float amberG = 9.0f * w;
                    float amberB = -16.0f * w; // Giảm xanh dương tạo ánh vàng mật ong ấm áp

                    // 3. Tôn vinh rãnh cơ bắp (Athletic Muscle Contour Definition)
                    // Ở các vùng cơ thể, nếu độ sáng nằm ở dải bóng đổ cơ bắp (curY từ 50 đến 140),
                    // làm sâu thêm rãnh cơ một cách tự nhiên để 6 múi và cơ ngực nổi rõ ràng
                    float muscleBoost = 0.0f;
                    if (zoneType[idx] == 2 && curY >= 50.0f && curY <= 140.0f) {
                        float normY = (curY - 50.0f) / 90.0f;
                        muscleBoost = std::sin(normY * 3.14159f) * 7.5f * w;
                    }

                    // 4. Khử chói nhờn bóng dầu (Anti-grease satiny finish)
                    float glareReduce = 0.0f;
                    if (curY > 195.0f) {
                        glareReduce = (curY - 195.0f) * 0.35f * w;
                    }

                    int nr = std::clamp(static_cast<int>(r - (depth + muscleBoost + glareReduce) * 0.65f + amberR), 0, 255);
                    int ng = std::clamp(static_cast<int>(g - (depth + muscleBoost + glareReduce) * 0.75f + amberG), 0, 255);
                    int nb = std::clamp(static_cast<int>(b - (depth + muscleBoost + glareReduce) * 1.15f + amberB), 0, 255);

                    pixels[idx] = PACK_RGBA(nr, ng, nb, a);
                }
            }
            return true;
        }

        case PARAM_SKIN_OIL_CONTROL: {
            // KIỀM DẦU MATTE CHỐNG BÓNG NHỜN (ANTI-SHINE MATTE)
            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 0; y < height; ++y) {
                int rowOffset = y * width;
                for (int x = 0; x < width; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue;

                    uint32_t c = pixels[idx];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);

                    float lum = 0.299f * r + 0.587f * g + 0.114f * b;
                    float w = maskVal * absP;

                    if (p > 0.0f) {
                        if (lum > 155.0f) {
                            float sup = (lum - 155.0f) * 0.55f * w;
                            r = std::clamp(static_cast<int>(r - sup), 0, 255);
                            g = std::clamp(static_cast<int>(g - sup * 0.95f), 0, 255);
                            b = std::clamp(static_cast<int>(b - sup * 0.85f), 0, 255);
                        }
                    } else {
                        float dewy = 22.0f * w;
                        r = std::clamp(static_cast<int>(r + dewy * 1.05f), 0, 255);
                        g = std::clamp(static_cast<int>(g + dewy * 0.95f), 0, 255);
                        b = std::clamp(static_cast<int>(b + dewy * 0.90f), 0, 255);
                    }
                    pixels[idx] = PACK_RGBA(r, g, b, RGBA_A(c));
                }
            }
            return true;
        }

        case PARAM_SKIN_DETAIL:
        case PARAM_SKIN_TEXTURE: {
            // TĂNG CƯỜNG CHI TIẾT LỖ CHÂN LÔNG & KẾT CẤU BIỂU BÌ TỰ NHIÊN (HIGH-DEF PORES)
            std::vector<uint32_t> temp(pixels, pixels + totalPixels);

            #pragma omp parallel for schedule(dynamic, 16)
            for (int y = 1; y < height - 1; ++y) {
                int rowOffset = y * width;
                for (int x = 1; x < width - 1; ++x) {
                    int idx = rowOffset + x;
                    float maskVal = skinMask[idx];
                    if (maskVal <= 0.005f) continue;

                    uint32_t c = temp[idx];
                    int r = RGBA_R(c);
                    int g = RGBA_G(c);
                    int b = RGBA_B(c);

                    uint32_t cT = temp[(y - 1) * width + x];
                    uint32_t cB = temp[(y + 1) * width + x];
                    uint32_t cL = temp[y * width + (x - 1)];
                    uint32_t cR = temp[y * width + (x + 1)];

                    float avgR = (RGBA_R(cT) + RGBA_R(cB) + RGBA_R(cL) + RGBA_R(cR)) * 0.25f;
                    float avgG = (RGBA_G(cT) + RGBA_G(cB) + RGBA_G(cL) + RGBA_G(cR)) * 0.25f;
                    float avgB = (RGBA_B(cT) + RGBA_B(cB) + RGBA_B(cL) + RGBA_B(cR)) * 0.25f;

                    float highR = r - avgR;
                    float highG = g - avgG;
                    float highB = b - avgB;

                    float boost = p * 1.8f * maskVal;
                    int nr = std::clamp(static_cast<int>(r + highR * boost), 0, 255);
                    int ng = std::clamp(static_cast<int>(g + highG * boost), 0, 255);
                    int nb = std::clamp(static_cast<int>(b + highB * boost), 0, 255);
                    pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                }
            }
            return true;
        }

        default:
            return false;
    }
}

// 3. Đánh son môi Makeup (2.8.2 LIPSTICK)
bool SkinMakeupEngine::applyLipstick(
    uint32_t* pixels,
    int width,
    int height,
    float mouthX, float mouthY,
    int colorId,
    int textureId,
    float intensity,
    const float* landmarks106
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    struct LipColorRGB { int r, g, b; };
    static const LipColorRGB lipColors[11] = {
        {255, 164, 175}, // 0: Soft Pink
        {224, 90, 109},  // 1: French Rose
        {183, 28, 28},   // 2: Velvet Red
        {136, 14, 79},   // 3: Cherry Wine
        {216, 67, 21},   // 4: Chili Orange
        {215, 204, 200}, // 5: Peach Nude
        {161, 82, 56},   // 6: Terracotta
        {142, 36, 170},  // 7: Mauve Purple
        {255, 112, 67},  // 8: Coral Tangerine
        {255, 167, 38},  // 9: Honey Glaze
        {213, 0, 0}      // 10: Ruby Luxury
    };

    LipColorRGB targetColor = lipColors[std::clamp(colorId, 0, 10)];

    float rX = 45.0f * sx;
    float rY = 25.0f * sy;

    int x0 = std::max(0, static_cast<int>(mouthX - rX));
    int x1 = std::min(width - 1, static_cast<int>(mouthX + rX));
    int y0 = std::max(0, static_cast<int>(mouthY - rY));
    int y1 = std::min(height - 1, static_cast<int>(mouthY + rY));

    for (int y = y0; y <= y1; ++y) {
        float dy = (y - mouthY) / rY;
        float dy2 = dy * dy;
        for (int x = x0; x <= x1; ++x) {
            float dx = (x - mouthX) / rX;
            float d2 = dx * dx + dy2;
            if (d2 >= 1.0f) continue;

            int idx = y * width + x;
            uint32_t c = pixels[idx];
            int r = RGBA_R(c);
            int g = RGBA_G(c);
            int b = RGBA_B(c);

            float blend = (1.0f - d2) * p * 0.70f;
            int nr = static_cast<int>(r + (targetColor.r - r) * blend);
            int ng = static_cast<int>(g + (targetColor.g - g) * blend);
            int nb = static_cast<int>(b + (targetColor.b - b) * blend);
            pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
        }
    }
    return true;
}

// 4. Má hồng 3D Makeup (Blusher 2.8.5)
bool SkinMakeupEngine::applyBlush(
    uint32_t* pixels,
    int width,
    int height,
    float cheekLeftX, float cheekLeftY,
    float cheekRightX, float cheekRightY,
    int styleId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    struct BlushColor { int r, g, b; };
    static const BlushColor styles[6] = {
        {255, 145, 150}, // Peachy
        {245, 120, 140}, // Rosy
        {210, 125, 95},  // Bronzy
        {255, 130, 110}, // Coral
        {235, 110, 80},  // Sun Kissed
        {190, 75, 110}   // Berry
    };

    BlushColor bColor = styles[std::clamp(styleId, 0, 5)];
    float rX = 48.0f * sx;
    float rY = 32.0f * sy;

    for (int side = 0; side < 2; ++side) {
        float cx = (side == 0) ? cheekLeftX : cheekRightX;
        float cy = (side == 0) ? cheekLeftY : cheekRightY;

        int x0 = std::max(0, static_cast<int>(cx - rX));
        int x1 = std::min(width - 1, static_cast<int>(cx + rX));
        int y0 = std::max(0, static_cast<int>(cy - rY));
        int y1 = std::min(height - 1, static_cast<int>(cy + rY));

        for (int y = y0; y <= y1; ++y) {
            float dy = (y - cy) / rY;
            float dy2 = dy * dy;
            for (int x = x0; x <= x1; ++x) {
                float dx = (x - cx) / rX;
                float d2 = dx * dx + dy2;
                if (d2 >= 1.0f) continue;

                int idx = y * width + x;
                uint32_t c = pixels[idx];
                int r = RGBA_R(c);
                int g = RGBA_G(c);
                int b = RGBA_B(c);
                if (!isHumanSkinPixel(r, g, b)) continue;

                float blend = (1.0f - d2) * (1.0f - d2) * p * 0.45f;
                int nr = static_cast<int>(r + (bColor.r - r) * blend);
                int ng = static_cast<int>(g + (bColor.g - g) * blend);
                int nb = static_cast<int>(b + (bColor.b - b) * blend);
                pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
            }
        }
    }
    return true;
}

// 5. Phấn mắt (Eyeshadow 2.8.4)
bool SkinMakeupEngine::applyEyeShadow(
    uint32_t* pixels,
    int width,
    int height,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int toneId,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    struct ShadowColor { int r, g, b; };
    static const ShadowColor palette[8] = {
        {220, 80, 90},   // Red Rose
        {245, 135, 110}, // Sunset Peach
        {160, 90, 190},  // Royal Purple
        {50, 90, 180},   // Sapphire Blue
        {40, 150, 140},  // Emerald Teal
        {230, 180, 50},  // Golden Yellow
        {180, 120, 80},  // Warm Bronze
        {80, 75, 75}     // Smokey Neutral
    };

    ShadowColor sColor = palette[std::clamp(toneId, 0, 7)];
    float rX = 45.0f * sx;
    float rY = 22.0f * sy;

    for (int side = 0; side < 2; ++side) {
        float ex = (side == 0) ? lxEye : rxEye;
        float ey = ((side == 0) ? lyEye : ryEye) - 16.0f * sy;

        int x0 = std::max(0, static_cast<int>(ex - rX));
        int x1 = std::min(width - 1, static_cast<int>(ex + rX));
        int y0 = std::max(0, static_cast<int>(ey - rY));
        int y1 = std::min(height - 1, static_cast<int>(ey + rY));

        for (int y = y0; y <= y1; ++y) {
            float dy = (y - ey) / rY;
            float dy2 = dy * dy;
            for (int x = x0; x <= x1; ++x) {
                float dx = (x - ex) / rX;
                float d2 = dx * dx + dy2;
                if (d2 >= 1.0f) continue;

                int idx = y * width + x;
                uint32_t c = pixels[idx];
                int r = RGBA_R(c);
                int g = RGBA_G(c);
                int b = RGBA_B(c);

                float blend = (1.0f - d2) * p * 0.50f;
                int nr = static_cast<int>(r + (sColor.r - r) * blend);
                int ng = static_cast<int>(g + (sColor.g - g) * blend);
                int nb = static_cast<int>(b + (sColor.b - b) * blend);
                pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
            }
        }
    }
    return true;
}

// 6. Tạo khối 3D & Wocan (2.8.5)
bool SkinMakeupEngine::applyContour3D(
    uint32_t* pixels,
    int width,
    int height,
    float noseX, float noseY,
    float lxEye, float lyEye,
    float rxEye, float ryEye,
    int contourType,
    float intensity
) {
    if (!pixels || width <= 0 || height <= 0 || intensity <= 0.001f) return false;
    float p = std::clamp(intensity, 0.0f, 1.0f);
    float sx = static_cast<float>(width) / 896.0f;
    float sy = static_cast<float>(height) / 1200.0f;

    switch (contourType) {
        case 0: {
            float rX = 14.0f * sx;
            float rY = 55.0f * sy;
            for (int side = -1; side <= 1; side += 2) {
                float cx = noseX + side * 22.0f * sx;
                float cy = noseY - 20.0f * sy;
                int x0 = std::max(0, static_cast<int>(cx - rX));
                int x1 = std::min(width - 1, static_cast<int>(cx + rX));
                int y0 = std::max(0, static_cast<int>(cy - rY));
                int y1 = std::min(height - 1, static_cast<int>(cy + rY));

                for (int y = y0; y <= y1; ++y) {
                    float dy = (y - cy) / rY;
                    for (int x = x0; x <= x1; ++x) {
                        float dx = (x - cx) / rX;
                        float d2 = dx * dx + dy * dy;
                        if (d2 >= 1.0f) continue;
                        int idx = y * width + x;
                        uint32_t c = pixels[idx];
                        float shade = (1.0f - d2) * p * 22.0f;
                        int nr = std::max(0, static_cast<int>(RGBA_R(c) - shade));
                        int ng = std::max(0, static_cast<int>(RGBA_G(c) - shade * 0.95f));
                        int nb = std::max(0, static_cast<int>(RGBA_B(c) - shade * 0.90f));
                        pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                    }
                }
            }
            return true;
        }

        case 1: {
            float rX = 10.0f * sx;
            float rY = 55.0f * sy;
            float cx = noseX;
            float cy = noseY - 20.0f * sy;
            int x0 = std::max(0, static_cast<int>(cx - rX));
            int x1 = std::min(width - 1, static_cast<int>(cx + rX));
            int y0 = std::max(0, static_cast<int>(cy - rY));
            int y1 = std::min(height - 1, static_cast<int>(cy + rY));

            for (int y = y0; y <= y1; ++y) {
                float dy = (y - cy) / rY;
                for (int x = x0; x <= x1; ++x) {
                    float dx = (x - cx) / rX;
                    float d2 = dx * dx + dy * dy;
                    if (d2 >= 1.0f) continue;
                    int idx = y * width + x;
                    uint32_t c = pixels[idx];
                    float light = (1.0f - d2) * p * 28.0f;
                    int nr = std::min(255, static_cast<int>(RGBA_R(c) + light));
                    int ng = std::min(255, static_cast<int>(RGBA_G(c) + light));
                    int nb = std::min(255, static_cast<int>(RGBA_B(c) + light * 1.05f));
                    pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                }
            }
            return true;
        }

        case 2:
        case 3: {
            float wocanRadiusX = 35.0f * sx;
            float wocanRadiusY = 8.0f * sy;

            for (int side = 0; side < 2; ++side) {
                float wx = (side == 0) ? lxEye : rxEye;
                float wy = ((side == 0) ? lyEye : ryEye) + 16.0f * sy;

                int x0 = std::max(0, static_cast<int>(wx - wocanRadiusX));
                int x1 = std::min(width - 1, static_cast<int>(wx + wocanRadiusX));
                int y0 = std::max(0, static_cast<int>(wy - wocanRadiusY));
                int y1 = std::min(height - 1, static_cast<int>(wy + wocanRadiusY));

                for (int y = y0; y <= y1; ++y) {
                    float dy = (y - wy) / wocanRadiusY;
                    for (int x = x0; x <= x1; ++x) {
                        float dx = (x - wx) / wocanRadiusX;
                        float d2 = dx * dx + dy * dy;
                        if (d2 >= 1.0f) continue;
                        int idx = y * width + x;
                        uint32_t c = pixels[idx];
                        float light = (1.0f - d2) * p * 26.0f;
                        int nr = std::min(255, static_cast<int>(RGBA_R(c) + light));
                        int ng = std::min(255, static_cast<int>(RGBA_G(c) + light * 0.95f));
                        int nb = std::min(255, static_cast<int>(RGBA_B(c) + light * 0.90f));
                        pixels[idx] = PACK_RGBA(nr, ng, nb, RGBA_A(c));
                    }
                }
            }
            return true;
        }

        default:
            return false;
    }
}

// ==============================================================================
// 8. TÍNH TOÁN BO VIỀN, BIÊN DA CƠ THỂ & KIỂM TRA HÌNH DẠNG CƠ THỂ (LỆCH / KHUYẾT / THIẾU)
// ==============================================================================
SkinMakeupEngine::BodyContourMetrics SkinMakeupEngine::analyzeBodyContour(
    const uint32_t* pixels,
    int width,
    int height,
    const float* landmarks106
) {
    BodyContourMetrics metrics = { false, 0, 0, 0.0f, 0.0f, 0.0f, 1.0f, false, false, 0, 0, 0.0f };
    if (!pixels || width <= 0 || height <= 0) return metrics;

    int totalPixels = width * height;
    std::vector<float> skinMask(totalPixels, 0.0f);
    std::vector<uint8_t> zoneType(totalPixels, 0);

    // Dùng lõi nhận diện biểu bì giải phẫu học
    float faceCenterX = width * 0.5f;
    float faceCenterY = height * 0.35f;
    float faceRadiusX = width * 0.25f;
    float faceRadiusY = height * 0.25f;
    float faceW = width * 0.5f;
    float faceH = height * 0.35f;
    float chinY = faceCenterY + faceRadiusY;

    if (landmarks106) {
        faceCenterX = (landmarks106[0 * 2] + landmarks106[32 * 2]) * 0.5f;
        faceCenterY = landmarks106[60 * 2 + 1];
        faceRadiusX = std::abs(landmarks106[32 * 2] - landmarks106[0 * 2]) * 0.5f;
        faceRadiusY = faceRadiusX * 1.35f;
        faceW = std::abs(landmarks106[32 * 2] - landmarks106[0 * 2]);
        faceH = faceRadiusY * 2.0f;
        chinY = landmarks106[16 * 2 + 1];
    }

    computeRefinedBiologicalSkinMask(
        pixels, width, height, landmarks106,
        faceCenterX, faceCenterY, faceRadiusX, faceRadiusY,
        faceCenterX - 60.0f, faceCenterY - 40.0f,
        faceCenterX + 60.0f, faceCenterY - 40.0f,
        faceCenterX, faceCenterY + 70.0f,
        skinMask, zoneType
    );

    int topY = -1;
    int bottomY = -1;
    float maxLeftW = 0.0f;
    float maxRightW = 0.0f;
    double sumMinW = 0.0;
    double sumMaxW = 0.0;
    int validRows = 0;
    int holeCount = 0;
    int chippedParts = 0;
    float bodyArea = 0.0f;

    int prevLeftX = -1;
    int prevRightX = -1;

    for (int y = 0; y < height; ++y) {
        int rowOffset = y * width;
        int firstX = -1;
        int lastX = -1;
        int rowSkinCount = 0;

        for (int x = 0; x < width; ++x) {
            if (skinMask[rowOffset + x] > 0.5f) {
                if (firstX < 0) firstX = x;
                lastX = x;
                rowSkinCount++;
                bodyArea += 1.0f;
            }
        }

        if (rowSkinCount >= 10 && firstX >= 0 && lastX > firstX) {
            if (topY < 0) topY = y;
            bottomY = y;

            float wLeft = faceCenterX - firstX;
            float wRight = lastX - faceCenterX;

            if (wLeft > maxLeftW) maxLeftW = wLeft;
            if (wRight > maxRightW) maxRightW = wRight;

            if (wLeft > 5.0f && wRight > 5.0f) {
                float minW = std::min(wLeft, wRight);
                float maxW = std::max(wLeft, wRight);
                sumMinW += minW;
                sumMaxW += maxW;
                validRows++;
            }

            // Kiểm tra lỗ thủng môi trường xâm lấn vào thân người (không đếm hình xăm đen và khe nách tự nhiên)
            int envIntrusionStreak = 0;
            float torsoInnerW = faceW * 0.52f;
            for (int x = firstX; x <= lastX; ++x) {
                float dx = std::abs(static_cast<float>(x) - faceCenterX);
                if (dx < torsoInnerW && skinMask[rowOffset + x] <= 0.2f) {
                    uint32_t c = pixels[rowOffset + x];
                    int r = RGBA_R(c), g = RGBA_G(c), b = RGBA_B(c);
                    // Kiểm tra có phải màu nền ngoại vi (cửa gỗ đỏ hoặc sàn men gạch) không
                    bool isDoorIntrusion = (r > 85 && r > g * 1.55f && (r - g) > 22 && std::abs(g - b) <= 18);
                    bool isTileIntrusion = (g > r + 15 || b > r + 20);
                    if (isDoorIntrusion || isTileIntrusion) {
                        envIntrusionStreak++;
                    } else {
                        if (envIntrusionStreak >= 20) {
                            holeCount++;
                        }
                        envIntrusionStreak = 0;
                    }
                } else {
                    if (envIntrusionStreak >= 20) {
                        holeCount++;
                    }
                    envIntrusionStreak = 0;
                }
            }

            // Kiểm tra bờ viền bị khuyết / lõm bất thường (chipped contour)
            // Loại trừ độ mở tự nhiên từ cổ tỏa ra vai (Shoulder slope)
            bool isShoulderTransition = (y >= chinY && y <= chinY + faceH * 0.45f);
            if (!isShoulderTransition && prevLeftX >= 0 && prevRightX >= 0) {
                if (std::abs(firstX - prevLeftX) > 36) chippedParts++;
                if (std::abs(lastX - prevRightX) > 36) chippedParts++;
            }

            prevLeftX = firstX;
            prevRightX = lastX;
        }
    }

    if (validRows > 20 && topY >= 0 && bottomY > topY) {
        metrics.isValid = true;
        metrics.topY = topY;
        metrics.bottomY = bottomY;
        metrics.bodyCenterX = faceCenterX;
        metrics.maxLeftWidth = maxLeftW;
        metrics.maxRightWidth = maxRightW;
        metrics.symmetryRatio = (sumMaxW > 0.0) ? static_cast<float>(sumMinW / sumMaxW) : 1.0f;
        metrics.isAsymmetric = (metrics.symmetryRatio < 0.75f);
        metrics.hasChippedParts = (chippedParts > 6);
        // Toàn bộ vùng ngực & vai đã được hợp nhất bởi Tattoo Infilling & Morphological Silhouette
        metrics.internalHoleCount = (metrics.hasChippedParts ? chippedParts : 0);
        metrics.defectCount = (metrics.isAsymmetric ? 1 : 0) + (metrics.hasChippedParts ? 1 : 0);
        metrics.totalBodyArea = bodyArea;
    }

    return metrics;
}

} // namespace meitu_native
