#include "clothing_aware_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu_native {

ClothingAwareEngine::ClothingAwareEngine() = default;
ClothingAwareEngine::~ClothingAwareEngine() = default;

bool ClothingAwareEngine::extractClothingConstraints(
    const uint8_t* rgba,
    int width,
    int height,
    const uint8_t* parsingMask,
    std::vector<float>& outRigidityMap,
    std::vector<RigidElement>& outRigidElements
) {
    if (width <= 0 || height <= 0) return false;
    int totalPixels = width * height;
    outRigidityMap.assign(totalPixels, 0.0f);
    outRigidElements.clear();

    if (!parsingMask) return false;

    // 1. Phan loai vung vai va phu kien tren co the
    std::vector<uint8_t> isClothing(totalPixels, 0);
    std::vector<uint8_t> isAccessory(totalPixels, 0);

    #pragma omp parallel for
    for (int i = 0; i < totalPixels; ++i) {
        uint8_t c = parsingMask[i];
        if (c == CLASS_UPPER_CLOTHES || c == CLASS_LOWER_CLOTHES || c == CLASS_DRESS) {
            isClothing[i] = 1;
            outRigidityMap[i] = 0.25f; // Do dan hoi co ban cua chat lieu vai (cotton, denim, len)
        } else if (c == CLASS_ACCESSORY) {
            isAccessory[i] = 1;
            outRigidityMap[i] = 0.95f; // Phu kien cung (that lung, dong ho, trang suc)
        } else if (c == CLASS_SHOE_LEFT || c == CLASS_SHOE_RIGHT) {
            isAccessory[i] = 1;
            outRigidityMap[i] = 0.98f; // Giay dep / de cung
        }
    }

    if (!rgba) return true;

    // 2. Tinh toan gradient cuong do sang de nhan dien cuc ao, duong may, khoa keo
    std::vector<uint8_t> lum(totalPixels);
    #pragma omp parallel for
    for (int i = 0; i < totalPixels; ++i) {
        int idx4 = i * 4;
        lum[i] = static_cast<uint8_t>((rgba[idx4] * 77 + rgba[idx4 + 1] * 150 + rgba[idx4 + 2] * 29) >> 8);
    }

    std::vector<int> gradMag(totalPixels, 0);
    #pragma omp parallel for
    for (int y = 2; y < height - 2; ++y) {
        for (int x = 2; x < width - 2; ++x) {
            int idx = y * width + x;
            if (!isClothing[idx] && !isAccessory[idx]) continue;

            int gx = lum[idx + 1] - lum[idx - 1];
            int gy = lum[idx + width] - lum[idx - width];
            int mag = std::abs(gx) + std::abs(gy);
            gradMag[idx] = mag;

            if (mag > 45) {
                // Tang do cung cuc bo tai duong vien may va nep gap
                outRigidityMap[idx] = std::min(0.85f, outRigidityMap[idx] + (mag / 255.0f) * 0.45f);
            }
        }
    }

    // 3. Phat hien cuc ao tron (Radial Symmetry Transform cho cuc ao nhua / kim loai)
    const int minR = 4;
    const int maxR = 12;

    for (int y = maxR + 2; y < height - maxR - 2; y += 4) {
        for (int x = maxR + 2; x < width - maxR - 2; x += 4) {
            int idx = y * width + x;
            if (!isClothing[idx]) continue;

            int centerLum = lum[idx];
            int ringSum = 0;
            int ringCount = 8;
            const float angles[8] = {0.0f, 0.785f, 1.57f, 2.356f, 3.141f, 3.927f, 4.712f, 5.497f};

            for (int r = minR; r <= maxR; r += 2) {
                ringSum = 0;
                for (int a = 0; a < ringCount; ++a) {
                    int rx = x + static_cast<int>(r * std::cos(angles[a]));
                    int ry = y + static_cast<int>(r * std::sin(angles[a]));
                    ringSum += lum[ry * width + rx];
                }
                int ringAvg = ringSum / ringCount;
                int contrast = std::abs(centerLum - ringAvg);

                if (contrast > 40) {
                    RigidElement btn;
                    btn.x = static_cast<float>(x);
                    btn.y = static_cast<float>(y);
                    btn.radius = static_cast<float>(r + 2);
                    btn.type = RIGID_BUTTON;
                    btn.rigidity = 0.98f;
                    outRigidElements.push_back(btn);

                    for (int dy = -r - 2; dy <= r + 2; ++dy) {
                        for (int dx = -r - 2; dx <= r + 2; ++dx) {
                            if (dx * dx + dy * dy <= (r + 2) * (r + 2)) {
                                int pIdx = (y + dy) * width + (x + dx);
                                if (pIdx >= 0 && pIdx < totalPixels) {
                                    outRigidityMap[pIdx] = 0.98f;
                                }
                            }
                        }
                    }
                    break;
                }
            }
        }
    }

    // 4. Phat hien khoa keo (Vertical continuous zipper line)
    for (int x = static_cast<int>(width * 0.2f); x < static_cast<int>(width * 0.8f); x += 6) {
        int continuousEdge = 0;
        int startY = 0;
        for (int y = static_cast<int>(height * 0.15f); y < static_cast<int>(height * 0.85f); ++y) {
            int idx = y * width + x;
            if (isClothing[idx] && gradMag[idx] > 50) {
                if (continuousEdge == 0) startY = y;
                continuousEdge++;
            } else {
                if (continuousEdge >= 18) {
                    RigidElement zip;
                    zip.x = static_cast<float>(x);
                    zip.y = static_cast<float>((startY + y) * 0.5f);
                    zip.radius = static_cast<float>(continuousEdge * 0.5f);
                    zip.type = RIGID_ZIPPER;
                    zip.rigidity = 0.95f;
                    outRigidElements.push_back(zip);

                    for (int zy = startY; zy < y; ++zy) {
                        for (int zx = x - 3; zx <= x + 3; ++zx) {
                            int pIdx = zy * width + zx;
                            if (pIdx >= 0 && pIdx < totalPixels) {
                                outRigidityMap[pIdx] = std::max(outRigidityMap[pIdx], 0.95f);
                            }
                        }
                    }
                }
                continuousEdge = 0;
            }
        }
    }

    // 5. Nhan dien mat khoa that lung / phu kien nhua, kim loai
    for (int y = 4; y < height - 4; y += 8) {
        for (int x = 4; x < width - 4; x += 8) {
            int idx = y * width + x;
            if (isAccessory[idx]) {
                RigidElement acc;
                acc.x = static_cast<float>(x);
                acc.y = static_cast<float>(y);
                acc.radius = 10.0f;
                acc.type = RIGID_BUCKLE;
                acc.rigidity = 1.0f;
                outRigidElements.push_back(acc);
            }
        }
    }

    return true;
}

bool ClothingAwareEngine::extractClothingConstraints(
    const uint8_t* rgba,
    int width,
    int height,
    const uint8_t* parsingMask,
    std::vector<float>& outRigidityMap,
    std::vector<ClothingFeature>& outFeatures
) {
    std::vector<RigidElement> rigidElems;
    bool res = extractClothingConstraints(rgba, width, height, parsingMask, outRigidityMap, rigidElems);
    outFeatures.clear();
    for (const auto& elem : rigidElems) {
        ClothingFeature f;
        f.x = elem.x;
        f.y = elem.y;
        f.rigidity = elem.rigidity;
        outFeatures.push_back(f);
    }
    return res;
}

void ClothingAwareEngine::applyRigidElementConstraints(
    int width,
    int height,
    const std::vector<RigidElement>& rigidElements,
    float* dxField,
    float* dyField
) {
    if (!dxField || !dyField || width <= 0 || height <= 0 || rigidElements.empty()) {
        return;
    }

    for (const auto& elem : rigidElements) {
        int cx = static_cast<int>(elem.x);
        int cy = static_cast<int>(elem.y);
        int r = static_cast<int>(elem.radius);
        int r2 = r * r;
        int blendMargin = 3;
        int rOuter = r + blendMargin;
        int rOuter2 = rOuter * rOuter;

        int minX = std::max(0, cx - rOuter);
        int maxX = std::min(width - 1, cx + rOuter);
        int minY = std::max(0, cy - rOuter);
        int maxY = std::min(height - 1, cy + rOuter);

        float sumDx = 0.0f, sumDy = 0.0f;
        int count = 0;
        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                int dx = x - cx;
                int dy = y - cy;
                if (dx * dx + dy * dy <= r2) {
                    int idx = y * width + x;
                    sumDx += dxField[idx];
                    sumDy += dyField[idx];
                    count++;
                }
            }
        }

        if (count == 0) continue;
        float meanDx = sumDx / count;
        float meanDy = sumDy / count;

        for (int y = minY; y <= maxY; ++y) {
            for (int x = minX; x <= maxX; ++x) {
                int dx = x - cx;
                int dy = y - cy;
                int d2 = dx * dx + dy * dy;
                int idx = y * width + x;

                if (d2 <= r2) {
                    dxField[idx] = meanDx;
                    dyField[idx] = meanDy;
                } else if (d2 <= rOuter2) {
                    float dist = std::sqrt(static_cast<float>(d2));
                    float t = (dist - r) / static_cast<float>(blendMargin);
                    t = std::max(0.0f, std::min(1.0f, t));
                    float blend = 1.0f - (t * t * (3.0f - 2.0f * t));
                    dxField[idx] = meanDx * blend + dxField[idx] * (1.0f - blend);
                    dyField[idx] = meanDy * blend + dyField[idx] * (1.0f - blend);
                }
            }
        }
    }
}

void ClothingAwareEngine::regularizeClothingDisplacement(
    int width,
    int height,
    const std::vector<float>& rigidityMap,
    const std::vector<RigidElement>& rigidElements,
    float* dxField,
    float* dyField
) {
    if (!dxField || !dyField || width <= 0 || height <= 0) return;
    int totalPixels = width * height;
    if (rigidityMap.size() < static_cast<size_t>(totalPixels)) return;

    applyRigidElementConstraints(width, height, rigidElements, dxField, dyField);

    std::vector<float> regDx(totalPixels);
    std::vector<float> regDy(totalPixels);
    std::memcpy(regDx.data(), dxField, totalPixels * sizeof(float));
    std::memcpy(regDy.data(), dyField, totalPixels * sizeof(float));

    const int iterations = 3;
    for (int iter = 0; iter < iterations; ++iter) {
        #pragma omp parallel for
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                int idx = y * width + x;
                float r = rigidityMap[idx];
                if (r <= 0.05f) continue;

                if (r >= 0.95f) {
                    continue;
                }

                float ddx_dx = (dxField[idx + 1] - dxField[idx - 1]) * 0.5f;
                float ddx_dy = (dxField[idx + width] - dxField[idx - width]) * 0.5f;
                float ddy_dx = (dyField[idx + 1] - dyField[idx - 1]) * 0.5f;
                float ddy_dy = (dyField[idx + width] - dyField[idx - width]) * 0.5f;

                float cr_diag = ddx_dx - ddy_dy;
                float cr_cross = ddx_dy + ddy_dx;

                float avgDx = (dxField[idx - 1] + dxField[idx + 1] + dxField[idx - width] + dxField[idx + width]) * 0.25f;
                float avgDy = (dyField[idx - 1] + dyField[idx + 1] + dyField[idx - width] + dyField[idx + width]) * 0.25f;

                float corrDx = avgDx - 0.15f * cr_diag;
                float corrDy = avgDy - 0.15f * cr_cross;

                float fabricWeight = 0.55f;
                regDx[idx] = dxField[idx] * (1.0f - fabricWeight) + corrDx * fabricWeight;
                regDy[idx] = dyField[idx] * (1.0f - fabricWeight) + corrDy * fabricWeight;

                regDx[idx] = std::max(-30.0f, std::min(30.0f, regDx[idx]));
                regDy[idx] = std::max(-30.0f, std::min(30.0f, regDy[idx]));
            }
        }

        #pragma omp parallel for
        for (int i = 0; i < totalPixels; ++i) {
            if (rigidityMap[i] > 0.05f && rigidityMap[i] < 0.95f) {
                dxField[i] = regDx[i];
                dyField[i] = regDy[i];
            }
        }

        applyRigidElementConstraints(width, height, rigidElements, dxField, dyField);
    }
}

void ClothingAwareEngine::regularizeClothingDisplacement(
    int width,
    int height,
    const std::vector<float>& rigidityMap,
    float* dxField,
    float* dyField
) {
    std::vector<RigidElement> emptyRigid;
    regularizeClothingDisplacement(width, height, rigidityMap, emptyRigid, dxField, dyField);
}

} // namespace meitu_native
