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
            outProtectionMask[i] = (parsingMask[i] == CLASS_BACKGROUND) ? 255 : 0;
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
            if (cx >= 0 && cx < width) {
                #pragma omp parallel for
                for (int y = 0; y < height; ++y) {
                    int idx = y * width + cx;
                    dxField[idx] = 0.0f;
                }
            }
        } else if (line.type == LINE_FLOOR_HORIZONTAL) {
            int cy = static_cast<int>(line.y1);
            if (cy >= 0 && cy < height) {
                #pragma omp parallel for
                for (int x = 0; x < width; ++x) {
                    int idx = cy * width + x;
                    dyField[idx] = 0.0f;
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

    #pragma omp parallel for
    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int idx = y * width + x;
            if (parsingMask[idx] == CLASS_BACKGROUND) {
                dxField[idx] = 0.0f;
                dyField[idx] = 0.0f;
            } else {
                bool nearBg = (parsingMask[idx - 1] == CLASS_BACKGROUND ||
                               parsingMask[idx + 1] == CLASS_BACKGROUND ||
                               parsingMask[idx - width] == CLASS_BACKGROUND ||
                               parsingMask[idx + width] == CLASS_BACKGROUND);
                if (nearBg) {
                    dxField[idx] *= 0.25f;
                    dyField[idx] *= 0.25f;
                }
            }
        }
    }
}

} // namespace body
} // namespace meitu