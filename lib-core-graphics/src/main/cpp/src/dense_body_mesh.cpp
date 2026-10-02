#include "dense_body_mesh.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu_native {

static inline float cubicKernel(float x) {
    x = std::abs(x);
    if (x <= 1.0f) {
        return (1.5f * x - 2.5f) * x * x + 1.0f;
    } else if (x < 2.0f) {
        return ((-0.5f * x + 2.5f) * x - 4.0f) * x + 2.0f;
    }
    return 0.0f;
}

void DenseBodyMesh::sampleBicubic(
    const uint8_t* src,
    int width,
    int height,
    float x,
    float y,
    uint8_t* outRgba
) {
    int x0 = static_cast<int>(std::floor(x));
    int y0 = static_cast<int>(std::floor(y));
    float fx = x - static_cast<float>(x0);
    float fy = y - static_cast<float>(y0);

    float sumR = 0.0f, sumG = 0.0f, sumB = 0.0f, sumA = 0.0f;
    float totalWeight = 0.0f;

    for (int j = -1; j <= 2; ++j) {
        int py = std::max(0, std::min(height - 1, y0 + j));
        float wy = cubicKernel(static_cast<float>(j) - fy);

        for (int i = -1; i <= 2; ++i) {
            int px = std::max(0, std::min(width - 1, x0 + i));
            float wx = cubicKernel(static_cast<float>(i) - fx);
            float w = wx * wy;

            int idx = (py * width + px) * 4;
            sumR += src[idx] * w;
            sumG += src[idx + 1] * w;
            sumB += src[idx + 2] * w;
            sumA += src[idx + 3] * w;
            totalWeight += w;
        }
    }

    if (totalWeight > 1e-4f) {
        outRgba[0] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumR / totalWeight)));
        outRgba[1] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumG / totalWeight)));
        outRgba[2] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumB / totalWeight)));
        outRgba[3] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, sumA / totalWeight)));
    } else {
        int idx = (std::max(0, std::min(height - 1, y0)) * width + std::max(0, std::min(width - 1, x0))) * 4;
        std::memcpy(outRgba, &src[idx], 4);
    }
}

DenseBodyMesh::DenseBodyMesh() = default;
DenseBodyMesh::~DenseBodyMesh() = default;

bool DenseBodyMesh::buildGrid(
    int width,
    int height,
    const BoundingBox2D& bbox,
    int gridStepPx
) {
    if (width <= 0 || height <= 0 || gridStepPx < 4) return false;

    mVertices.clear();
    mDeformedVertices.clear();
    mTriangles.clear();

    // Expand bounding box slightly for smooth border blending
    float pad = gridStepPx * 2.0f;
    float xMin = std::max(0.0f, bbox.x1 - pad);
    float yMin = std::max(0.0f, bbox.y1 - pad);
    float xMax = std::min(static_cast<float>(width - 1), bbox.x2 + pad);
    float yMax = std::min(static_cast<float>(height - 1), bbox.y2 + pad);

    if (xMax <= xMin || yMax <= yMin) {
        xMin = 0.0f;
        yMin = 0.0f;
        xMax = static_cast<float>(width - 1);
        yMax = static_cast<float>(height - 1);
    }

    mGridCols = static_cast<int>(std::ceil((xMax - xMin) / gridStepPx)) + 1;
    mGridRows = static_cast<int>(std::ceil((yMax - yMin) / gridStepPx)) + 1;

    mVertices.reserve(mGridCols * mGridRows);
    for (int r = 0; r < mGridRows; ++r) {
        float y = std::min(yMax, yMin + r * gridStepPx);
        for (int c = 0; c < mGridCols; ++c) {
            float x = std::min(xMax, xMin + c * gridStepPx);
            MeshVertex v;
            v.x = x;
            v.y = y;
            v.u = x;
            v.v = y;
            v.weight = 1.0f;
            mVertices.push_back(v);
        }
    }
    mDeformedVertices = mVertices;

    // Generate two triangles per cell
    mTriangles.reserve((mGridRows - 1) * (mGridCols - 1) * 2);
    for (int r = 0; r < mGridRows - 1; ++r) {
        for (int c = 0; c < mGridCols - 1; ++c) {
            int i00 = r * mGridCols + c;
            int i10 = r * mGridCols + (c + 1);
            int i01 = (r + 1) * mGridCols + c;
            int i11 = (r + 1) * mGridCols + (c + 1);

            MeshTriangle t1{i00, i10, i01};
            MeshTriangle t2{i10, i11, i01};
            mTriangles.push_back(t1);
            mTriangles.push_back(t2);
        }
    }

    return !mVertices.empty();
}

void DenseBodyMesh::deformVertices(
    int width,
    int height,
    const float* dxField,
    const float* dyField
) {
    if (!dxField || !dyField || mVertices.empty()) return;

    #pragma omp parallel for
    for (size_t i = 0; i < mVertices.size(); ++i) {
        int x = std::max(0, std::min(width - 1, static_cast<int>(std::round(mVertices[i].x))));
        int y = std::max(0, std::min(height - 1, static_cast<int>(std::round(mVertices[i].y))));
        int idx = y * width + x;

        float dx = dxField[idx];
        float dy = dyField[idx];

        mDeformedVertices[i].x = mVertices[i].x + dx;
        mDeformedVertices[i].y = mVertices[i].y + dy;
    }
}

bool DenseBodyMesh::renderDeformedImage(
    const uint8_t* srcRgba,
    uint8_t* dstRgba,
    int width,
    int height,
    int stride
) {
    if (!srcRgba || !dstRgba || width <= 0 || height <= 0 || mTriangles.empty()) {
        return false;
    }

    int rowStride = (stride > 0) ? stride : (width * 4);

    // Rasterize triangles with exact barycentric coordinates to eliminate boundary artifacts
    for (size_t t = 0; t < mTriangles.size(); ++t) {
        const auto& tri = mTriangles[t];
        const auto& d0 = mDeformedVertices[tri.v0];
        const auto& d1 = mDeformedVertices[tri.v1];
        const auto& d2 = mDeformedVertices[tri.v2];

        const auto& s0 = mVertices[tri.v0];
        const auto& s1 = mVertices[tri.v1];
        const auto& s2 = mVertices[tri.v2];

        float minX = std::max(0.0f, std::min({d0.x, d1.x, d2.x}));
        float maxX = std::min(static_cast<float>(width - 1), std::max({d0.x, d1.x, d2.x}));
        float minY = std::max(0.0f, std::min({d0.y, d1.y, d2.y}));
        float maxY = std::min(static_cast<float>(height - 1), std::max({d0.y, d1.y, d2.y}));

        float denom = (d1.y - d2.y) * (d0.x - d2.x) + (d2.x - d1.x) * (d0.y - d2.y);
        if (std::abs(denom) < 1e-5f) continue;
        float invDenom = 1.0f / denom;

        int startX = static_cast<int>(std::floor(minX));
        int endX = static_cast<int>(std::ceil(maxX));
        int startY = static_cast<int>(std::floor(minY));
        int endY = static_cast<int>(std::ceil(maxY));

        for (int py = startY; py <= endY; ++py) {
            for (int px = startX; px <= endX; ++px) {
                float w0 = ((d1.y - d2.y) * (px - d2.x) + (d2.x - d1.x) * (py - d2.y)) * invDenom;
                float w1 = ((d2.y - d0.y) * (px - d2.x) + (d0.x - d2.x) * (py - d2.y)) * invDenom;
                float w2 = 1.0f - w0 - w1;

                if (w0 >= 0.0f && w1 >= 0.0f && w2 >= 0.0f) {
                    float srcX = w0 * s0.x + w1 * s1.x + w2 * s2.x;
                    float srcY = w0 * s0.y + w1 * s1.y + w2 * s2.y;

                    int dstIdx = py * rowStride + px * 4;
                    sampleBicubic(srcRgba, width, height, srcX, srcY, &dstRgba[dstIdx]);
                }
            }
        }
    }

    return true;
}

} // namespace meitu_native
