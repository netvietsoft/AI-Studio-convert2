#ifndef MEITU_FULL_HUMAN_BEAUTY_CONTROLLER_H
#define MEITU_FULL_HUMAN_BEAUTY_CONTROLLER_H

#include <cstdint>
#include <vector>
#include <memory>
#include "head_semantic_model.h"
#include "body_semantic_model.h"
#include "beauty_parameter_controller.h"
#include "body_beauty_engine.h"
#include "deformation_constraint_solver.h"
#include "dense_body_mesh.h"

namespace meitu_native {

struct FullHumanBeautyParameters {
    // 1. Head & Face Parameters (SPEC Sections 3-23)
    BeautyParameters headParams;

    // 2. Body & Full Anatomy Parameters (SPEC Sections 41-91)
    BodyBeautyParameters bodyParams;
};

/**
 * @brief Master Coordinator for Full Human Beauty Pipeline (SPEC Section 91).
 * Executes Head + Body transformations in verified physiological and occlusion order:
 * 1. Semantic Model Extraction (Head 106 + WholeBody 25).
 * 2. Background & Rigid Accessory Snapshot.
 * 3. Head & Skull Geometry Sculpting.
 * 4. Neck-Clavicle Constraint Zone (prevent head drifting from body).
 * 5. Full Body Height & Long Legs.
 * 6. Torso, Waist & Hip Sculpting.
 * 7. Arm & Shoulder Slimming.
 * 8. Leg Slimming.
 * 9. Facial Features & Teeth/Ear Beauty.
 * 10. Head & Body Skin Beauty (micro-pores >= 75%).
 * 11. Rigid Accessory & Structural Line Protection (Zero Background Distortion).
 */
class FullHumanBeautyController {
public:
    FullHumanBeautyController();
    ~FullHumanBeautyController();

    bool applyFullHumanPipeline(
        uint8_t* rgbaImage,
        int width,
        int height,
        int stride,
        const std::vector<float>& headLandmarks, // 106 landmarks
        const std::vector<float>& bodyPosePoints,// 25 pose points
        const FullHumanBeautyParameters& params
    );

private:
    std::unique_ptr<BeautyParameterController> mHeadController;
    std::unique_ptr<BodyBeautyEngine> mBodyEngine;
    std::unique_ptr<DeformationConstraintSolver> mConstraintSolver;
    std::unique_ptr<DenseBodyMesh> mDenseMesh;
};

} // namespace meitu_native

#endif // MEITU_FULL_HUMAN_BEAUTY_CONTROLLER_H
