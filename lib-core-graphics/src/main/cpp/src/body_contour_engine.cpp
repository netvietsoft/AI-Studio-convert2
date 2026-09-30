#include "body_contour_engine.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu {
namespace body {

BodyContourEngine::BodyContourEngine() = default;
BodyContourEngine::~BodyContourEngine() = default;

bool BodyContourEngine::extractSilhouetteContour(
    const uint8_t* parsingMask,
    int width, int height,
    std::vector<ContourPoint>& outContour
) {
    if (!parsingMask || width <= 2 || height <= 2) return false;
    outContour.clear();

    for (int y = 1; y < height - 1; ++y) {
        for (int x = 1; x < width - 1; ++x) {
            int idx = y * width + x;
            uint8_t c = parsingMask[idx];
            if (c != CLASS_BACKGROUND) {
                // Check if adjacent to background
                uint8_t up = parsingMask[idx - width];
                uint8_t dn = parsingMask[idx + width];
                uint8_t lf = parsingMask[idx - 1];
                uint8_t rt = parsingMask[idx + 1];

                if (up == CLASS_BACKGROUND || dn == CLASS_BACKGROUND ||
                    lf == CLASS_BACKGROUND || rt == CLASS_BACKGROUND) {
                    ContourPoint pt;
                    pt.x = static_cast<float>(x);
                    pt.y = static_cast<float>(y);

                    float gx = (rt == CLASS_BACKGROUND ? 1.0f : 0.0f) - (lf == CLASS_BACKGROUND ? 1.0f : 0.0f);
                    float gy = (dn == CLASS_BACKGROUND ? 1.0f : 0.0f) - (up == CLASS_BACKGROUND ? 1.0f : 0.0f);
                    float len = std::sqrt(gx * gx + gy * gy);
                    if (len > 1e-4f) {
                        pt.nx = gx / len;
                        pt.ny = gy / len;
                    } else {
                        pt.nx = 1.0f;
                        pt.ny = 0.0f;
                    }
                    outContour.push_back(pt);
                }
            }
        }
    }
    return !outContour.empty();
}

bool BodyContourEngine::smoothContour(
    const std::vector<ContourPoint>& inContour,
    float smoothingFactor,
    std::vector<ContourPoint>& outContour
) {
    if (inContour.size() < 5) {
        outContour = inContour;
        return true;
    }

    outContour = inContour;
    int n = static_cast<int>(inContour.size());
    float w0 = 0.20f * smoothingFactor;
    float w1 = 0.15f * smoothingFactor;
    float wc = 1.0f - 2.0f * (w0 + w1);

    for (int i = 2; i < n - 2; ++i) {
        outContour[i].x = inContour[i - 2].x * w1 + inContour[i - 1].x * w0 +
                          inContour[i].x * wc +
                          inContour[i + 1].x * w0 + inContour[i + 2].x * w1;
        outContour[i].y = inContour[i - 2].y * w1 + inContour[i - 1].y * w0 +
                          inContour[i].y * wc +
                          inContour[i + 1].y * w0 + inContour[i + 2].y * w1;
    }
    return true;
}

bool BodyContourEngine::computeSignedDistanceField(
    const uint8_t* parsingMask,
    int width, int height,
    float* outSdf
) {
    if (!parsingMask || !outSdf || width <= 0 || height <= 0) return false;

    const float INF = 1e6f;
    std::vector<float> distInner(width * height, INF);
    std::vector<float> distOuter(width * height, INF);

    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        if (parsingMask[i] == CLASS_BACKGROUND) {
            distOuter[i] = 0.0f;
        } else {
            distInner[i] = 0.0f;
        }
    }

    // Forward pass
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            if (x > 0) {
                distOuter[idx] = std::min(distOuter[idx], distOuter[idx - 1] + 1.0f);
                distInner[idx] = std::min(distInner[idx], distInner[idx - 1] + 1.0f);
            }
            if (y > 0) {
                distOuter[idx] = std::min(distOuter[idx], distOuter[idx - width] + 1.0f);
                distInner[idx] = std::min(distInner[idx], distInner[idx - width] + 1.0f);
            }
        }
    }

    // Backward pass
    for (int y = height - 1; y >= 0; --y) {
        for (int x = width - 1; x >= 0; --x) {
            int idx = y * width + x;
            if (x < width - 1) {
                distOuter[idx] = std::min(distOuter[idx], distOuter[idx + 1] + 1.0f);
                distInner[idx] = std::min(distInner[idx], distInner[idx + 1] + 1.0f);
            }
            if (y < height - 1) {
                distOuter[idx] = std::min(distOuter[idx], distOuter[idx + width] + 1.0f);
                distInner[idx] = std::min(distInner[idx], distInner[idx + width] + 1.0f);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < width * height; ++i) {
        if (parsingMask[i] == CLASS_BACKGROUND) {
            outSdf[i] = distInner[i]; // Positive outside
        } else {
            outSdf[i] = -distOuter[i]; // Negative inside
        }
    }

    return true;
}

} // namespace body
} // namespace meitu
