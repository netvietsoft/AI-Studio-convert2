#include "liquify_warp.h"
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

class SkinHairClassifier {
public:
    // 1. Phân loại màu da người (Human Skin Color Gamut) trong không gian YCbCr + RGB
    static inline float computeSkinColorConfidence(uint32_t c) {
        float r = static_cast<float>(RGBA_R(c));
        float g = static_cast<float>(RGBA_G(c));
        float b = static_cast<float>(RGBA_B(c));

        // YCbCr chuyển đổi chuẩn ITU-R BT.601
        float y  = 0.299f * r + 0.587f * g + 0.114f * b;
        float cb = 128.0f - 0.168736f * r - 0.331264f * g + 0.5f * b;
        float cr = 128.0f + 0.5f * r - 0.418688f * g - 0.081312f * b;

        // Tóc đen / tối màu (Dark Hair / Black Hair strands):
        // Giá trị sáng Y rất thấp hoặc cả 3 kênh RGB đều tối
        if (y < 48.0f || (r < 42.0f && g < 42.0f && b < 42.0f)) {
            return 0.0f; // Chắc chắn là tóc hoặc nền tối, chặn hoàn toàn biến dạng
        }
        // Tóc đen / hạt dẻ có độ bão hòa màu rất thấp gần trục xám
        if (y < 80.0f && std::abs(cb - 128.0f) < 12.0f && std::abs(cr - 128.0f) < 12.0f) {
            return 0.0f; // Chắc chắn là tóc
        }

        // Quy tắc RGB của biểu bì da người: R > G và R > B
        if (r <= g || r <= b || (r - g) < 4.0f) {
            return 0.0f; // Không phải da người
        }

        // Phạm vi elip da trong YCbCr
        if (y < 35.0f || y > 252.0f || cb < 70.0f || cb > 138.0f || cr < 130.0f || cr > 185.0f || cr <= cb) {
            return 0.0f; // Ngoài phổ da
        }

        // Điểm số mượt mà từ tâm cụm màu da chuẩn (Cb ~ 102, Cr ~ 152)
        float dCb = (cb - 102.0f) / 28.0f;
        float dCr = (cr - 152.0f) / 26.0f;
        float distSq = dCb * dCb + dCr * dCr;
        float conf = std::clamp(1.0f - distSq * 0.45f, 0.0f, 1.0f);
        return conf;
    }

    // 2. Tính năng lượng biên độ vân sợi tóc (High-Frequency Hair Strand Texture Energy)
    static inline float computeHairTextureEnergy(const uint32_t* src, int w, int h, int x, int y) {
        int x0 = std::max(0, x - 1);
        int x1 = std::min(w - 1, x + 1);
        int y0 = std::max(0, y - 1);
        int y1 = std::min(h - 1, y + 1);

        uint32_t cL = src[y * w + x0];
        uint32_t cR = src[y * w + x1];
        uint32_t cT = src[y0 * w + x];
        uint32_t cB = src[y1 * w + x];

        float lumL = 0.299f * RGBA_R(cL) + 0.587f * RGBA_G(cL) + 0.114f * RGBA_B(cL);
        float lumR = 0.299f * RGBA_R(cR) + 0.587f * RGBA_G(cR) + 0.114f * RGBA_B(cR);
        float lumT = 0.299f * RGBA_R(cT) + 0.587f * RGBA_G(cT) + 0.114f * RGBA_B(cT);
        float lumB = 0.299f * RGBA_R(cB) + 0.587f * RGBA_G(cB) + 0.114f * RGBA_B(cB);

        float gx = lumR - lumL;
        float gy = lumB - lumT;
        return std::sqrt(gx * gx + gy * gy);
    }

    // 3. Phân biệt hình học: Khuôn mặt (trong) vs Tóc/Nền (ngoài) & Vùng da giáp tóc
    static inline float computeSkinHairGate(
        const uint32_t* src,
        int w, int h,
        int x, int y,
        float startX, float startY,
        float endX, float endY,
        float radius,
        const float* landmarks106
    ) {
        uint32_t c = src[y * w + x];
        float skinConf = computeSkinColorConfidence(c);

        // 1. Phân loại biểu bì da: Nếu không phải sắc tố màu da -> Tuyệt đối không biến dạng (Tóc/Nền giữ nguyên 100%)
        if (skinConf < 0.35f) {
            return 0.0f; // Vùng tóc và ngoại cảnh: Triệt tiêu biến dạng hoàn toàn (Zero displacement)
        }

        // 2. Phát hiện sợi tóc dựa trên năng lượng kết cấu sợi tần số cao
        float strandEnergy = computeHairTextureEnergy(src, w, h, x, y);
        if (strandEnergy > 25.0f && skinConf < 0.65f) {
            return 0.0f; // Sợi tóc: Triệt tiêu biến dạng
        }

        // Tọa độ tâm khuôn mặt
        float faceCenterX = startX;
        float faceCenterY = startY;

        if (landmarks106 != nullptr) {
            // Sử dụng tọa độ mũi (landmark 46 hoặc 59) làm tâm quy chiếu khuôn mặt
            float noseX = landmarks106[46 * 2];
            float noseY = landmarks106[46 * 2 + 1];
            if (noseX > 10.0f && noseY > 10.0f && noseX < (float)(w - 10) && noseY < (float)(h - 10)) {
                faceCenterX = noseX;
                faceCenterY = noseY;
            } else if (landmarks106[59 * 2] > 10.0f) {
                faceCenterX = landmarks106[59 * 2];
                faceCenterY = landmarks106[59 * 2 + 1];
            } else {
                faceCenterX = (float)w * 0.5f;
                faceCenterY = (float)h * 0.48f;
            }
        } else {
            faceCenterX = (float)w * 0.5f;
            faceCenterY = (float)h * 0.48f;
        }

        // Vector hướng từ điểm xuất phát (startX, startY) vào bên trong khuôn mặt
        float toCenterX = faceCenterX - startX;
        float toCenterY = faceCenterY - startY;
        float centerDist = std::sqrt(toCenterX * toCenterX + toCenterY * toCenterY);

        if (centerDist > 1.0f) {
            toCenterX /= centerDist;
            toCenterY /= centerDist;
        } else {
            // Nếu không có tâm rõ ràng, sử dụng hướng di chuyển nắn stroke
            float dx = endX - startX;
            float dy = endY - startY;
            float strokeLen = std::sqrt(dx * dx + dy * dy);
            if (strokeLen > 0.5f) {
                toCenterX = dx / strokeLen;
                toCenterY = dy / strokeLen;
            } else {
                toCenterX = 0.0f;
                toCenterY = 0.0f;
            }
        }

        // Vector hướng RA NGOÀI mặt (về phía tóc và bối cảnh)
        float outX = -toCenterX;
        float outY = -toCenterY;

        // Khoảng cách chiếu của điểm (x, y) theo hướng ra ngoài mặt
        float relX = (float)x - startX;
        float relY = (float)y - startY;
        float distOut = relX * outX + relY * outY;

        // VÙNG PHÂN BIỆT RÕ RÀNG:
        // 3. Phía ngoài (distOut > 4.0px về phía tóc):
        //    Chỉ cho phép biến dạng nếu độ tin cậy da rất cao (da thật); nếu không phải da thật hoặc có vân sợi tóc -> triệt tiêu
        if (distOut > 4.0f) {
            if (skinConf < 0.50f || strandEnergy > 18.0f) {
                return 0.0f; // Tóc và nền ngoài mặt: GIỮ NGUYÊN 100%, KHÔNG BỊ UỐN CONG!
            }
        }

        // 4. Vùng da giáp tóc (Hairline Transition zone, -6.0px đến +8.0px):
        //    Sử dụng hàm Hermite Smoothstep C^1 để tạo chuyển tiếp mềm mại,
        //    giúp viền da trượt tự nhiên mà không kéo tóc và không gây gãy nét (shear tear).
        float geomGate = 1.0f;
        if (distOut > -6.0f) {
            float t = std::clamp((8.0f - distOut) / 14.0f, 0.0f, 1.0f);
            geomGate = t * t * (3.0f - 2.0f * t); // Smoothstep
        }

        // 5. Kết hợp gating hình học với độ tin cậy biểu bì da
        float finalGate = geomGate;
        if (skinConf < 0.50f) {
            finalGate *= ((skinConf - 0.35f) / 0.15f);
        }

        return std::clamp(finalGate, 0.0f, 1.0f);
    }
};

static inline uint32_t sampleBilinear(const uint32_t* src, int w, int h, float fx, float fy) {
    if (fx < 0.0f) fx = 0.0f;
    if (fy < 0.0f) fy = 0.0f;
    if (fx > (float)(w - 1)) fx = (float)(w - 1);
    if (fy > (float)(h - 1)) fy = (float)(h - 1);

    int x0 = (int)fx;
    int y0 = (int)fy;
    int x1 = (x0 + 1 < w) ? x0 + 1 : x0;
    int y1 = (y0 + 1 < h) ? y0 + 1 : y0;

    float wx = fx - (float)x0;
    float wy = fy - (float)y0;
    float w00 = (1.0f - wx) * (1.0f - wy);
    float w10 = wx * (1.0f - wy);
    float w01 = (1.0f - wx) * wy;
    float w11 = wx * wy;

    uint32_t p00 = src[y0 * w + x0];
    uint32_t p10 = src[y0 * w + x1];
    uint32_t p01 = src[y1 * w + x0];
    uint32_t p11 = src[y1 * w + x1];

    float r = RGBA_R(p00) * w00 + RGBA_R(p10) * w10 + RGBA_R(p01) * w01 + RGBA_R(p11) * w11;
    float g = RGBA_G(p00) * w00 + RGBA_G(p10) * w10 + RGBA_G(p01) * w01 + RGBA_G(p11) * w11;
    float b = RGBA_B(p00) * w00 + RGBA_B(p10) * w10 + RGBA_B(p01) * w01 + RGBA_B(p11) * w11;
    float a = RGBA_A(p00) * w00 + RGBA_A(p10) * w10 + RGBA_A(p01) * w01 + RGBA_A(p11) * w11;

    uint32_t ir = (uint32_t)std::clamp((int)std::round(r), 0, 255);
    uint32_t ig = (uint32_t)std::clamp((int)std::round(g), 0, 255);
    uint32_t ib = (uint32_t)std::clamp((int)std::round(b), 0, 255);
    uint32_t ia = (uint32_t)std::clamp((int)std::round(a), 0, 255);

    return PACK_RGBA(ir, ig, ib, ia);
}

bool LiquifyWarpEngine::applyWarp(
    uint32_t* pixels,
    int width,
    int height,
    float startX,
    float startY,
    float endX,
    float endY,
    float radius,
    float intensity,
    int mode,
    const uint32_t* originalPixels,
    const float* landmarks106,
    bool protectHair
) {
    if (!pixels || width <= 0 || height <= 0 || radius <= 1.0f) {
        return false;
    }

    float rSq = radius * radius;
    int minX = std::max(0, (int)std::floor(startX - radius));
    int maxX = std::min(width - 1, (int)std::ceil(startX + radius));
    int minY = std::max(0, (int)std::floor(startY - radius));
    int maxY = std::min(height - 1, (int)std::ceil(startY + radius));

    if (minX > maxX || minY > maxY) return false;

    float dx = endX - startX;
    float dy = endY - startY;
    float clampedIntensity = std::clamp(intensity, 0.0f, 2.0f);

    // Lưu snapshot vùng ảnh biến dạng để nội suy độc lập nguồn và đích
    std::vector<uint32_t> snapshot(width * height);
    #pragma omp parallel for schedule(static)
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            snapshot[y * width + x] = pixels[y * width + x];
        }
    }

    #pragma omp parallel for schedule(dynamic, 16)
    for (int y = minY; y <= maxY; ++y) {
        for (int x = minX; x <= maxX; ++x) {
            float curDx = (float)x - startX;
            float curDy = (float)y - startY;
            float distSq = curDx * curDx + curDy * curDy;

            if (distSq < rSq) {
                float distRatio = distSq / rSq;
                float falloff = (1.0f - distRatio);
                float weight = falloff * falloff * clampedIntensity;

                if (mode == WARP_RESTORE) {
                    if (originalPixels != nullptr) {
                        uint32_t curColor = pixels[y * width + x];
                        uint32_t origColor = originalPixels[y * width + x];

                        float blend = std::clamp(weight, 0.0f, 1.0f);
                        uint32_t r = (uint32_t)std::round(RGBA_R(curColor) * (1.0f - blend) + RGBA_R(origColor) * blend);
                        uint32_t g = (uint32_t)std::round(RGBA_G(curColor) * (1.0f - blend) + RGBA_G(origColor) * blend);
                        uint32_t b = (uint32_t)std::round(RGBA_B(curColor) * (1.0f - blend) + RGBA_B(origColor) * blend);
                        uint32_t a = (uint32_t)std::round(RGBA_A(curColor) * (1.0f - blend) + RGBA_A(origColor) * blend);

                        pixels[y * width + x] = PACK_RGBA(r, g, b, a);
                    }
                    continue;
                }

                // Gating bảo vệ tóc, phân biệt vùng da và vùng da giáp tóc
                if (protectHair) {
                    float gate = SkinHairClassifier::computeSkinHairGate(
                        snapshot.data(), width, height, x, y,
                        startX, startY, endX, endY, radius, landmarks106
                    );
                    weight *= gate;
                }

                // Nếu trọng số biến dạng gần 0 (vùng tóc / ngoài mặt), giữ nguyên điểm ảnh gốc, không dịch chuyển
                if (weight < 0.0001f) {
                    pixels[y * width + x] = snapshot[y * width + x];
                    continue;
                }

                float sampleX = (float)x;
                float sampleY = (float)y;

                if (mode == WARP_PUSH) {
                    sampleX = (float)x - dx * weight;
                    sampleY = (float)y - dy * weight;

                    // Sample boundary clamping: Nếu điểm lấy mẫu (sampleX, sampleY) bị vượt ra ngoài vùng da
                    // và rơi vào vùng tóc/nền tối, ta lùi lại dọc theo vector biến dạng về phía (x, y)
                    // cho đến khi điểm mẫu nằm tại ranh giới da thật.
                    // Đảm bảo da mặt không bao giờ lấy mẫu từ tóc (triệt tiêu hoàn toàn vệt đen/hõm má)!
                    if (protectHair) {
                        int ix = std::clamp((int)std::round(sampleX), 0, width - 1);
                        int iy = std::clamp((int)std::round(sampleY), 0, height - 1);
                        if (SkinHairClassifier::computeSkinColorConfidence(snapshot[iy * width + ix]) < 0.35f) {
                            // Lien tuc hoa ranh gioi bang Binary Search tren truc to do thuc (sub-pixel continuous)
                            float low = 0.0f;
                            float high = 1.0f;
                            for (int it = 0; it < 6; ++it) {
                                float mid = (low + high) * 0.5f;
                                float mx = sampleX + mid * ((float)x - sampleX);
                                float my = sampleY + mid * ((float)y - sampleY);
                                int mix = std::clamp((int)std::round(mx), 0, width - 1);
                                int miy = std::clamp((int)std::round(my), 0, height - 1);
                                if (SkinHairClassifier::computeSkinColorConfidence(snapshot[miy * width + mix]) >= 0.35f) {
                                    high = mid;
                                } else {
                                    low = mid;
                                }
                            }
                            sampleX = sampleX + high * ((float)x - sampleX);
                            sampleY = sampleY + high * ((float)y - sampleY);
                        }
                    }
                } else if (mode == WARP_EXPAND) {
                    // Maximum safe expansion factor: 0.35 (prevents coordinate inversion & spherical black distortion)
                    float expandW = falloff * std::min(clampedIntensity * 0.28f, 0.35f);
                    if (protectHair) {
                        float gate = SkinHairClassifier::computeSkinHairGate(
                            snapshot.data(), width, height, x, y,
                            startX, startY, endX, endY, radius, landmarks106
                        );
                        expandW *= gate;
                    }
                    sampleX = (float)x - curDx * expandW;
                    sampleY = (float)y - curDy * expandW;
                } else if (mode == WARP_PINCH) {
                    float pinchW = falloff * std::min(clampedIntensity * 0.28f, 0.35f);
                    if (protectHair) {
                        float gate = SkinHairClassifier::computeSkinHairGate(
                            snapshot.data(), width, height, x, y,
                            startX, startY, endX, endY, radius, landmarks106
                        );
                        pinchW *= gate;
                    }
                    sampleX = (float)x + curDx * pinchW;
                    sampleY = (float)y + curDy * pinchW;
                }

                pixels[y * width + x] = sampleBilinear(snapshot.data(), width, height, sampleX, sampleY);
            }
        }
    }

    return true;
}

} // namespace meitu_native
