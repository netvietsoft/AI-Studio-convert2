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

void BackgroundProtectionEngine::reconstructVacatedHoles(
    uint32_t* currentPixels,
    const uint32_t* originalSnapshot,
    int width, int height,
    const uint8_t* isVacatedMask,
    const uint8_t* parsingMask,
    const std::vector<meitu_native::StructuralLine>* lines
) {
    if (!currentPixels || !originalSnapshot || width <= 0 || height <= 0 || !isVacatedMask) {
        return;
    }

    #pragma omp parallel for
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            if (!isVacatedMask[idx]) {
                if (parsingMask && parsingMask[idx] == CLASS_BACKGROUND) {
                    currentPixels[idx] = originalSnapshot[idx];
                }
                continue;
            }

            // 1. Kiem tra xem co duong thang cau truc (tuong, cua, san nha) cat qua pixel bi bo trong khong
            bool lineHandled = false;
            if (lines) {
                for (const auto& line : *lines) {
                    if (line.type == LINE_WALL_VERTICAL && std::abs(static_cast<float>(x) - line.x1) <= 3.5f) {
                        uint32_t topPix = 0, botPix = 0;
                        bool hasTop = false, hasBot = false;
                        for (int dy = 1; dy <= 40; ++dy) {
                            int sy = y - dy;
                            if (sy >= 0 && (!isVacatedMask[sy * width + x] || (parsingMask && parsingMask[sy * width + x] == CLASS_BACKGROUND))) {
                                topPix = originalSnapshot[sy * width + x];
                                hasTop = true;
                                break;
                            }
                        }
                        for (int dy = 1; dy <= 40; ++dy) {
                            int sy = y + dy;
                            if (sy < height && (!isVacatedMask[sy * width + x] || (parsingMask && parsingMask[sy * width + x] == CLASS_BACKGROUND))) {
                                botPix = originalSnapshot[sy * width + x];
                                hasBot = true;
                                break;
                            }
                        }
                        if (hasTop && hasBot) {
                            uint8_t r = static_cast<uint8_t>(((topPix & 0xFF) + (botPix & 0xFF)) >> 1);
                            uint8_t g = static_cast<uint8_t>((((topPix >> 8) & 0xFF) + ((botPix >> 8) & 0xFF)) >> 1);
                            uint8_t b = static_cast<uint8_t>((((topPix >> 16) & 0xFF) + ((botPix >> 16) & 0xFF)) >> 1);
                            currentPixels[idx] = r | (g << 8) | (b << 16) | 0xFF000000;
                            lineHandled = true;
                            break;
                        } else if (hasTop) {
                            currentPixels[idx] = topPix;
                            lineHandled = true;
                            break;
                        } else if (hasBot) {
                            currentPixels[idx] = botPix;
                            lineHandled = true;
                            break;
                        }
                    } else if (line.type == LINE_FLOOR_HORIZONTAL && std::abs(static_cast<float>(y) - line.y1) <= 3.5f) {
                        uint32_t leftPix = 0, rightPix = 0;
                        bool hasLeft = false, hasRight = false;
                        for (int dx = 1; dx <= 40; ++dx) {
                            int sx = x - dx;
                            if (sx >= 0 && (!isVacatedMask[y * width + sx] || (parsingMask && parsingMask[y * width + sx] == CLASS_BACKGROUND))) {
                                leftPix = originalSnapshot[y * width + sx];
                                hasLeft = true;
                                break;
                            }
                        }
                        for (int dx = 1; dx <= 40; ++dx) {
                            int sx = x + dx;
                            if (sx < width && (!isVacatedMask[y * width + sx] || (parsingMask && parsingMask[y * width + sx] == CLASS_BACKGROUND))) {
                                rightPix = originalSnapshot[y * width + sx];
                                hasRight = true;
                                break;
                            }
                        }
                        if (hasLeft && hasRight) {
                            uint8_t r = static_cast<uint8_t>(((leftPix & 0xFF) + (rightPix & 0xFF)) >> 1);
                            uint8_t g = static_cast<uint8_t>((((leftPix >> 8) & 0xFF) + ((rightPix >> 8) & 0xFF)) >> 1);
                            uint8_t b = static_cast<uint8_t>((((leftPix >> 16) & 0xFF) + ((rightPix >> 16) & 0xFF)) >> 1);
                            currentPixels[idx] = r | (g << 8) | (b << 16) | 0xFF000000;
                            lineHandled = true;
                            break;
                        } else if (hasLeft) {
                            currentPixels[idx] = leftPix;
                            lineHandled = true;
                            break;
                        } else if (hasRight) {
                            currentPixels[idx] = rightPix;
                            lineHandled = true;
                            break;
                        }
                    }
                }
            }

            if (lineHandled) continue;

            // 2. Tinh toan noi suy ket cau huong Gradient (Isophote Directional Continuity)
            float sumW = 0.0f;
            float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f;
            const int dirs[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};

            for (int d = 0; d < 8; ++d) {
                int stepX = dirs[d][0];
                int stepY = dirs[d][1];
                for (int s = 1; s <= 24; ++s) {
                    int nx = x + stepX * s;
                    int ny = y + stepY * s;
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height) break;
                    int nidx = ny * width + nx;
                    if (!isVacatedMask[nidx] && (!parsingMask || parsingMask[nidx] == CLASS_BACKGROUND)) {
                        uint32_t p = originalSnapshot[nidx];
                        float dist = static_cast<float>(s);
                        float weight = 1.0f / (dist * dist);
                        sumR += (p & 0xFF) * weight;
                        sumG += ((p >> 8) & 0xFF) * weight;
                        sumB += ((p >> 16) & 0xFF) * weight;
                        sumW += weight;
                        break;
                    }
                }
            }

            if (sumW > 1e-4f) {
                uint8_t r = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumR / sumW)));
                uint8_t g = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumG / sumW)));
                uint8_t b = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumB / sumW)));
                currentPixels[idx] = r | (g << 8) | (b << 16) | 0xFF000000;
            } else {
                currentPixels[idx] = originalSnapshot[idx];
            }
        }
    }
}

void BackgroundProtectionEngine::synthesizeVacatedBackground(
    uint32_t* currentPixels,
    const uint32_t* originalSnapshot,
    int width, int height,
    const uint8_t* parsingMask,
    const float* dxField,
    const float* dyField,
    const std::vector<meitu_native::StructuralLine>* lines
) {
    if (!currentPixels || !originalSnapshot || width <= 0 || height <= 0 || !parsingMask || !dxField || !dyField) {
        return;
    }

    std::vector<uint8_t> isVacated(width * height, 0);

    #pragma omp parallel for
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int idx = y * width + x;
            if (parsingMask[idx] == CLASS_BACKGROUND) {
                currentPixels[idx] = originalSnapshot[idx];
                continue;
            }

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

    reconstructVacatedHoles(currentPixels, originalSnapshot, width, height, isVacated.data(), parsingMask, lines);
}

} // namespace body
} // namespace meitu
