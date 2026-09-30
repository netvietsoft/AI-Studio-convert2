#include "background_protection_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu {
namespace body {

using namespace meitu_native;

BackgroundProtectionEngine::BackgroundProtectionEngine() = default;
BackgroundProtectionEngine::~BackgroundProtectionEngine() = default;

bool BackgroundProtectionEngine::detectStructuralLines(
    const uint8_t* rgba, int width, int height,
    std::vector<StructuralLine>& outLines
) {
    if (!rgba || width <= 8 || height <= 8) return false;
    outLines.clear();

    std::vector<uint8_t> gray(width * height);
    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * 4;
            gray[y * width + x] = static_cast<uint8_t>(
                (rgba[idx] * 77 + rgba[idx + 1] * 150 + rgba[idx + 2] * 29) >> 8
            );
        }
    }

    const int threshold = 45;
    std::vector<int> vertVotes(width, 0);
    std::vector<int> horizVotes(height, 0);

    #pragma omp parallel for
    for (int y = 2; y < height - 2; ++y) {
        for (int x = 2; x < width - 2; ++x) {
            int gx = -gray[(y - 1) * width + (x - 1)] + gray[(y - 1) * width + (x + 1)]
                     - 2 * gray[y * width + (x - 1)] + 2 * gray[y * width + (x + 1)]
                     - gray[(y + 1) * width + (x - 1)] + gray[(y + 1) * width + (x + 1)];

            int gy = -gray[(y - 1) * width + (x - 1)] - 2 * gray[(y - 1) * width + x] - gray[(y - 1) * width + (x + 1)]
                     + gray[(y + 1) * width + (x - 1)] + 2 * gray[(y + 1) * width + x] + gray[(y + 1) * width + (x + 1)];

            int mag = std::abs(gx) + std::abs(gy);
            if (mag > threshold) {
                if (std::abs(gx) > 2 * std::abs(gy)) {
                    #pragma omp atomic
                    vertVotes[x]++;
                } else if (std::abs(gy) > 2 * std::abs(gx)) {
                    #pragma omp atomic
                    horizVotes[y]++;
                }
            }
        }
    }

    int minVertCount = height / 6;
    for (int x = 4; x < width - 4; ++x) {
        if (vertVotes[x] > minVertCount &&
            vertVotes[x] > vertVotes[x - 1] && vertVotes[x] >= vertVotes[x + 1]) {
            StructuralLine line;
            line.x1 = static_cast<float>(x);
            line.y1 = 0.0f;
            line.x2 = static_cast<float>(x);
            line.y2 = static_cast<float>(height);
            line.angleDeg = 90.0f;
            line.stiffness = 1.0f;
            line.type = LINE_WALL_VERTICAL;
            outLines.push_back(line);
        }
    }

    int minHorizCount = width / 6;
    for (int y = 4; y < height - 4; ++y) {
        if (horizVotes[y] > minHorizCount &&
            horizVotes[y] > horizVotes[y - 1] && horizVotes[y] >= horizVotes[y + 1]) {
            StructuralLine line;
            line.x1 = 0.0f;
            line.y1 = static_cast<float>(y);
            line.x2 = static_cast<float>(width);
            line.y2 = static_cast<float>(y);
            line.angleDeg = 0.0f;
            line.stiffness = 1.0f;
            line.type = LINE_FLOOR_HORIZONTAL;
            outLines.push_back(line);
        }
    }

    return !outLines.empty();
}

bool BackgroundProtectionEngine::generateProtectionMask(
    int width, int height,
    const uint8_t* parsingMask,
    const std::vector<StructuralLine>& lines,
    uint8_t* outProtectionMask
) {
    if (!outProtectionMask || width <= 0 || height <= 0) return false;

    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        if (parsingMask) {
            uint8_t c = parsingMask[i];
            if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
                outProtectionMask[i] = 255;
            } else {
                outProtectionMask[i] = 0;
            }
        } else {
            outProtectionMask[i] = 0;
        }
    }

    const int radius = 12;
    for (const auto& line : lines) {
        if (line.type == LINE_WALL_VERTICAL) {
            int cx = static_cast<int>(line.x1);
            int xMin = std::max(0, cx - radius);
            int xMax = std::min(width - 1, cx + radius);
            #pragma omp parallel for
            for (int y = 0; y < height; ++y) {
                for (int x = xMin; x <= xMax; ++x) {
                    outProtectionMask[y * width + x] = 255;
                }
            }
        } else if (line.type == LINE_FLOOR_HORIZONTAL) {
            int cy = static_cast<int>(line.y1);
            int yMin = std::max(0, cy - radius);
            int yMax = std::min(height - 1, cy + radius);
            #pragma omp parallel for
            for (int y = yMin; y <= yMax; ++y) {
                for (int x = 0; x < width; ++x) {
                    outProtectionMask[y * width + x] = 255;
                }
            }
        }
    }

    return true;
}

void BackgroundProtectionEngine::regularizeDisplacementField(
    int width, int height,
    const uint8_t* protectionMask,
    const std::vector<StructuralLine>& lines,
    float* dxField, float* dyField
) {
    if (!dxField || !dyField || width <= 0 || height <= 0) return;

    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        if (protectionMask) {
            uint8_t stiffness = protectionMask[i];
            if (stiffness >= 220) {
                dxField[i] = 0.0f;
                dyField[i] = 0.0f;
            } else if (stiffness > 0) {
                float factor = 1.0f - (static_cast<float>(stiffness) / 220.0f);
                dxField[i] *= factor;
                dyField[i] *= factor;
            }
        }
    }

    for (const auto& line : lines) {
        if (line.type == LINE_WALL_VERTICAL) {
            int cx = static_cast<int>(line.x1);
            int margin = 6;
            int x0 = std::max(0, cx - margin);
            int x1 = std::min(width - 1, cx + margin);
            #pragma omp parallel for
            for (int y = 0; y < height; ++y) {
                for (int x = x0; x <= x1; ++x) {
                    int idx = y * width + x;
                    dxField[idx] = 0.0f; // Khoa tuyet doi thanh phan ngang vuong goc voi tuong
                }
            }
        } else if (line.type == LINE_FLOOR_HORIZONTAL) {
            int cy = static_cast<int>(line.y1);
            int margin = 6;
            int y0 = std::max(0, cy - margin);
            int y1 = std::min(height - 1, cy + margin);
            #pragma omp parallel for
            for (int y = y0; y <= y1; ++y) {
                for (int x = 0; x < width; ++x) {
                    int idx = y * width + x;
                    dyField[idx] = 0.0f; // Khoa tuyet doi thanh phan doc vuong goc voi san nha
                }
            }
        }
    }
}

void BackgroundProtectionEngine::attenuateBoundaryLeakage(
    int width, int height,
    const uint8_t* parsingMask,
    float* dxField, float* dyField,
    int marginPx
) {
    if (!parsingMask || !dxField || !dyField || width <= 0 || height <= 0) return;

    int safeMargin = std::max(1, std::min(32, marginPx));
    std::vector<int> distToBg(width * height, safeMargin + 1);

    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        uint8_t c = parsingMask[i];
        if (c == CLASS_BACKGROUND || c == CLASS_FOREGROUND_OBJ) {
            distToBg[i] = 0;
            dxField[i] = 0.0f;
            dyField[i] = 0.0f;
        }
    }

    // Forward distance pass
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            if (distToBg[idx] > 0) {
                if (x > 0) distToBg[idx] = std::min(distToBg[idx], distToBg[idx - 1] + 1);
                if (y > 0) distToBg[idx] = std::min(distToBg[idx], distToBg[idx - width] + 1);
            }
        }
    }

    // Backward distance pass
    for (int y = height - 1; y >= 0; --y) {
        for (int x = width - 1; x >= 0; --x) {
            int idx = y * width + x;
            if (distToBg[idx] > 0) {
                if (x < width - 1) distToBg[idx] = std::min(distToBg[idx], distToBg[idx + 1] + 1);
                if (y < height - 1) distToBg[idx] = std::min(distToBg[idx], distToBg[idx + width] + 1);
            }
        }
    }

    // Multi-ring smooth boundary attenuation using Hermite smoothstep
    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        int d = distToBg[i];
        if (d == 0) {
            dxField[i] = 0.0f;
            dyField[i] = 0.0f;
        } else if (d < safeMargin) {
            float t = static_cast<float>(d) / static_cast<float>(safeMargin);
            float smoothFactor = t * t * (3.0f - 2.0f * t);
            dxField[i] *= smoothFactor;
            dyField[i] *= smoothFactor;
        }
    }
}

void BackgroundProtectionEngine::synthesizeVacatedBackground(
    uint32_t* currentPixels,
    const uint32_t* originalSnapshot,
    int width, int height,
    const uint8_t* parsingMask,
    const float* dxField,
    const float* dyField
) {
    if (!currentPixels || !originalSnapshot || width <= 0 || height <= 0 || !parsingMask || !dxField || !dyField) {
        return;
    }

    // Phat hien cac pixel thuoc vung bi bo trong khi co the thu gon (Inward contraction)
    // Mot pixel duoc xem la vacated neu no von la bien co the (parsingMask != BG)
    // nhung sau bien dang, diem lay mau (srcX, srcY) da roi xa khoi pixel do huong vao trong tam co the.
    std::vector<uint8_t> isVacated(width * height, 0);

    #pragma omp parallel for
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int idx = y * width + x;
            if (parsingMask[idx] == CLASS_BACKGROUND) {
                // Background nguyen thuy: giu nguyen 100% tu snapshot goc
                currentPixels[idx] = originalSnapshot[idx];
                continue;
            }

            // Kiem tra neu pixel nam sat bien va co chuyen vi co ngot huong vao trong
            bool nearBg = (parsingMask[idx - 1] == CLASS_BACKGROUND ||
                           parsingMask[idx + 1] == CLASS_BACKGROUND ||
                           parsingMask[idx - width] == CLASS_BACKGROUND ||
                           parsingMask[idx + width] == CLASS_BACKGROUND);

            if (nearBg) {
                float dispMag = std::sqrt(dxField[idx] * dxField[idx] + dyField[idx] * dyField[idx]);
                if (dispMag > 0.5f) {
                    isVacated[idx] = 1;
                }
            }
        }
    }

    // Diffusion noi suy ket cau background vao vung bi bo trong
    // Giu tuong, cua va vat the phia sau luon lien tuc va thang hang
    for (int pass = 0; pass < 2; ++pass) {
        #pragma omp parallel for
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                int idx = y * width + x;
                if (!isVacated[idx]) continue;

                // Lay mau trung binh tu cac pixel background lan can trong snapshot goc
                int bgCount = 0;
                int sumR = 0, sumG = 0, sumB = 0;
                const int nIdx[4] = {idx - 1, idx + 1, idx - width, idx + width};

                for (int k = 0; k < 4; ++k) {
                    int ni = nIdx[k];
                    if (parsingMask[ni] == CLASS_BACKGROUND) {
                        uint32_t p = originalSnapshot[ni];
                        sumR += p & 0xFF;
                        sumG += (p >> 8) & 0xFF;
                        sumB += (p >> 16) & 0xFF;
                        bgCount++;
                    }
                }

                if (bgCount > 0) {
                    uint8_t r = static_cast<uint8_t>(sumR / bgCount);
                    uint8_t g = static_cast<uint8_t>(sumG / bgCount);
                    uint8_t b = static_cast<uint8_t>(sumB / bgCount);
                    currentPixels[idx] = r | (g << 8) | (b << 16) | 0xFF000000;
                }
            }
        }
    }
}

} // namespace body
} // namespace meitu
