#include "deformation_constraint_solver.h"
#include <cmath>
#include <algorithm>
#include <cstring>
#include <omp.h>

namespace meitu_native {

DeformationConstraintSolver::DeformationConstraintSolver() = default;
DeformationConstraintSolver::~DeformationConstraintSolver() = default;

bool DeformationConstraintSolver::solveDisplacementField(
    int width,
    int height,
    const HumanFrameResult& human,
    const float* rawDx,
    const float* rawDy,
    float* outDx,
    float* outDy,
    const SolverConstraints& constraints
) {
    if (width <= 0 || height <= 0 || !rawDx || !rawDy || !outDx || !outDy) {
        return false;
    }

    int totalPixels = width * height;
    std::memcpy(outDx, rawDx, totalPixels * sizeof(float));
    std::memcpy(outDy, rawDy, totalPixels * sizeof(float));

    // Objective 1: Hand & Foreground Limb Occlusion Decoupling (SPEC Section 74)
    // Neu ban tay hoac phu kien che truoc eo, giam toi da chuyen vi de khong lam bop meo ban tay
    if (constraints.enableOcclusionDecoupling && !human.parsingMask.empty()) {
        #pragma omp parallel for
        for (int i = 0; i < totalPixels; ++i) {
            uint8_t c = human.parsingMask[i];
            if (c == CLASS_HAND_LEFT || c == CLASS_HAND_RIGHT || c == CLASS_FOREGROUND_OBJ) {
                outDx[i] *= 0.05f; // Triet tieu 95% bien dang tren ban tay
                outDy[i] *= 0.05f;
            }
        }
    }

    // Objective 2: Rigid Elements & Clothing Fabric Regularization (SPEC Section 73)
    // Bao ve cuc ao nhua, khoa keo kim loai, mat khoa that lung khong bi bien dang
    // Bao ve ket cau soi vai theo nguyen ly Cauchy-Riemann Conformal Elasticity
    if (constraints.enableClothingProtection && !human.parsingMask.empty()) {
        std::vector<float> rigidityMap(totalPixels, 0.0f);
        std::vector<RigidElement> rigidElements;
        mClothingEngine.extractClothingConstraints(
            nullptr, width, height, human.parsingMask.data(), rigidityMap, rigidElements
        );
        mClothingEngine.regularizeClothingDisplacement(
            width, height, rigidityMap, rigidElements, outDx, outDy
        );
    }

    // Objective 3: Background & Structural Line Constraints (SPEC Sections 82, 83)
    if (constraints.enableBackgroundProtection) {
        if (!human.parsingMask.empty()) {
            mBgEngine.attenuateBoundaryLeakage(
                width, height, human.parsingMask.data(), outDx, outDy
            );
        }
        if (!human.backgroundProtectionMask.empty()) {
            mBgEngine.regularizeDisplacementField(
                width, height,
                human.backgroundProtectionMask.data(),
                human.structuralLines,
                outDx, outDy
            );
        }
    }

    // Objective 4: Strict Silhouette Clamping (Zero displacement outside body bounding box)
    const BoundingBox2D& bbox = human.background.bodyBoundingBox;
    if (bbox.x2 > bbox.x1 && bbox.y2 > bbox.y1) {
        int minX = std::max(0, static_cast<int>(bbox.x1) - 4);
        int maxX = std::min(width - 1, static_cast<int>(bbox.x2) + 4);
        int minY = std::max(0, static_cast<int>(bbox.y1) - 4);
        int maxY = std::min(height - 1, static_cast<int>(bbox.y2) + 4);

        #pragma omp parallel for
        for (int y = 0; y < height; ++y) {
            if (y < minY || y > maxY) {
                std::memset(outDx + y * width, 0, width * sizeof(float));
                std::memset(outDy + y * width, 0, width * sizeof(float));
            } else {
                for (int x = 0; x < minX; ++x) {
                    outDx[y * width + x] = 0.0f;
                    outDy[y * width + x] = 0.0f;
                }
                for (int x = maxX + 1; x < width; ++x) {
                    outDx[y * width + x] = 0.0f;
                    outDy[y * width + x] = 0.0f;
                }
            }
        }
    }

    // Objective 5: Laplacian Smoothing iterations to guarantee C1 continuity and prevent fold-overs
    std::vector<float> tmpDx(totalPixels);
    std::vector<float> tmpDy(totalPixels);

    for (int it = 0; it < constraints.smoothingIterations; ++it) {
        #pragma omp parallel for
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                int idx = y * width + x;
                if (!human.backgroundProtectionMask.empty() && human.backgroundProtectionMask[idx] >= 220) {
                    tmpDx[idx] = 0.0f;
                    tmpDy[idx] = 0.0f;
                    continue;
                }

                float avgDx = (outDx[idx - 1] + outDx[idx + 1] +
                               outDx[idx - width] + outDx[idx + width]) * 0.25f;
                float avgDy = (outDy[idx - 1] + outDy[idx + 1] +
                               outDy[idx - width] + outDy[idx + width]) * 0.25f;

                tmpDx[idx] = outDx[idx] * 0.60f + avgDx * 0.40f;
                tmpDy[idx] = outDy[idx] * 0.60f + avgDy * 0.40f;
            }
        }

        #pragma omp parallel for
        for (int y = 1; y < height - 1; ++y) {
            for (int x = 1; x < width - 1; ++x) {
                int idx = y * width + x;
                outDx[idx] = tmpDx[idx];
                outDy[idx] = tmpDy[idx];
            }
        }
    }

    return true;
}

} // namespace meitu_native
