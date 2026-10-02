#ifndef MEITU_DENSE_BODY_MESH_H
#define MEITU_DENSE_BODY_MESH_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"

namespace meitu_native {

struct MeshVertex {
    float x{0.0f};
    float y{0.0f};
    float u{0.0f};
    float v{0.0f};
    float weight{1.0f};
};

struct MeshTriangle {
    int v0{0};
    int v1{0};
    int v2{0};
};

/**
 * @brief Dense Body Deformation Mesh (SPEC Section 80).
 * Generates 1500-3500 triangle vertices spanning the body bounding box.
 * Performs fast piecewise continuous deformation with subpixel accuracy.
 */
class DenseBodyMesh {
public:
    DenseBodyMesh();
    ~DenseBodyMesh();

    /**
     * @brief Build a uniform triangulation grid over the body ROI.
     */
    bool buildGrid(
        int width,
        int height,
        const BoundingBox2D& bbox,
        int gridStepPx = 16
    );

    /**
     * @brief Apply dense displacement field (dx, dy) to mesh vertices.
     */
    void deformVertices(
        int width,
        int height,
        const float* dxField,
        const float* dyField
    );

    /**
     * @brief Render the deformed mesh into the destination image using piecewise bicubic texture sampling.
     */
    bool renderDeformedImage(
        const uint8_t* srcRgba,
        uint8_t* dstRgba,
        int width,
        int height,
        int stride
    );

    const std::vector<MeshVertex>& getVertices() const { return mVertices; }
    const std::vector<MeshTriangle>& getTriangles() const { return mTriangles; }

private:
    std::vector<MeshVertex> mVertices;
    std::vector<MeshVertex> mDeformedVertices;
    std::vector<MeshTriangle> mTriangles;
    int mGridCols{0};
    int mGridRows{0};

    void sampleBicubic(
        const uint8_t* src,
        int width,
        int height,
        float x,
        float y,
        uint8_t* outRgba
    );
};

} // namespace meitu_native

namespace meitu {
namespace body {
    using MeshVertex = meitu_native::MeshVertex;
    using MeshTriangle = meitu_native::MeshTriangle;
    using DenseBodyMesh = meitu_native::DenseBodyMesh;
}
}

#endif // MEITU_DENSE_BODY_MESH_H
