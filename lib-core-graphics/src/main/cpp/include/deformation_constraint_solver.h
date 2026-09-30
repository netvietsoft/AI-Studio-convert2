#ifndef MEITU_DEFORMATION_CONSTRAINT_SOLVER_H
#define MEITU_DEFORMATION_CONSTRAINT_SOLVER_H

#include <vector>
#include <cstdint>
#include "body_semantic_model.h"
#include "background_protection_engine.h"
#include "clothing_aware_engine.h"
#include "body_contour_engine.h"

namespace meitu_native {

struct SolverConstraints {
    bool enableBackgroundProtection{true};
    bool enableClothingProtection{true};
    bool enableRigidElementProtection{true};
    bool enableOcclusionDecoupling{true};
    bool enableFabricConformalElasticity{true};
    int smoothingIterations{2};
};

/**
 * @brief Deformation Constraint Solver (SPEC Section 88).
 * Multi-objective solver for generating high-fidelity dense displacement fields (dx, dy).
 * Enforces:
 * - Target shape deformation
 * - Background line straightness and zero background distortion
 * - Rigid clothing feature preservation (cuc ao, khoa keo, mat khoa, phu kien nhua)
 * - Hand & limb occlusion decoupling (e.g. hands over waist do not get squeezed)
 * - C1 continuous deformation preventing mesh fold-overs and fabric weave breaking
 */
class DeformationConstraintSolver {
public:
    DeformationConstraintSolver();
    ~DeformationConstraintSolver();

    /**
     * @brief Solve for regularized dense displacement field (dx, dy).
     */
    bool solveDisplacementField(
        int width,
        int height,
        const HumanFrameResult& human,
        const float* rawDx,
        const float* rawDy,
        float* outDx,
        float* outDy,
        const SolverConstraints& constraints = SolverConstraints()
    );

private:
    meitu::body::BackgroundProtectionEngine mBgEngine;
    ClothingAwareEngine mClothingEngine;
    meitu::body::BodyContourEngine mContourEngine;
};

} // namespace meitu_native

namespace meitu {
namespace body {
    using DeformationConstraintSolver = meitu_native::DeformationConstraintSolver;
    using SolverConstraints = meitu_native::SolverConstraints;
}
}

#endif // MEITU_DEFORMATION_CONSTRAINT_SOLVER_H
