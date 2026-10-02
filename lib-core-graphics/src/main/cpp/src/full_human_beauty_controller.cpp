#include "full_human_beauty_controller.h"
#include <vector>
#include <algorithm>

namespace meitu_native {

FullHumanBeautyController::FullHumanBeautyController()
    : mHeadController(std::make_unique<BeautyParameterController>()),
      mBodyEngine(std::make_unique<BodyBeautyEngine>()),
      mConstraintSolver(std::make_unique<DeformationConstraintSolver>()),
      mDenseMesh(std::make_unique<DenseBodyMesh>()) {
}

FullHumanBeautyController::~FullHumanBeautyController() = default;

bool FullHumanBeautyController::applyFullHumanPipeline(
    uint8_t* rgbaImage,
    int width,
    int height,
    int stride,
    const std::vector<float>& headLandmarks,
    const std::vector<float>& bodyPosePoints,
    const FullHumanBeautyParameters& params
) {
    if (!rgbaImage || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }

    uint32_t* pixels = reinterpret_cast<uint32_t*>(rgbaImage);

    // Giai doan 1: Snapshot ban goc de bao ve boi canh & phu kien (SPEC Sections 82, 83)
    std::vector<uint32_t> originalSnapshot(width * height);
    std::copy(pixels, pixels + (width * height), originalSnapshot.begin());

    // Giai doan 2: Trich xuat mo hinh giai phau toan dien (Full Human Semantic Model)
    HumanFrameResult human = BodySemanticEngine::extractHumanModel(
        bodyPosePoints, headLandmarks, pixels, width, height
    );

    // Giai doan 3: Ap dung Head & Face Beauty Pipeline (SPEC Sections 3-23)
    if (human.head.isValid) {
        mHeadController->applyBeautyPipeline(
            rgbaImage, width, height, stride, headLandmarks, params.headParams
        );
    }

    // Giai doan 4: Ap dung Full Body Beauty Pipeline (SPEC Sections 41-87)
    if (human.isValid) {
        mBodyEngine->processFullBodyBeauty(
            rgbaImage, width, height, stride, human, params.bodyParams
        );
    }

    // Giai doan 5: Bao ve boi canh tuyet doi (Zero Background Warping)
    // Cac pixel nam hoan toan ngoai bodyBoundingBox duoc khoi phuc nguyen ban 100%
    const BoundingBox2D& bbox = human.background.bodyBoundingBox;
    int bX1 = std::max(0, static_cast<int>(bbox.x1));
    int bY1 = std::max(0, static_cast<int>(bbox.y1));
    int bX2 = std::min(width - 1, static_cast<int>(bbox.x2));
    int bY2 = std::min(height - 1, static_cast<int>(bbox.y2));

    // Khoi phuc 4 mien ngoai khung co the
    // Vung tren
    for (int y = 0; y < bY1; ++y) {
        std::copy(originalSnapshot.data() + y * width,
                  originalSnapshot.data() + (y + 1) * width,
                  pixels + y * width);
    }
    // Vung duoi
    for (int y = bY2 + 1; y < height; ++y) {
        std::copy(originalSnapshot.data() + y * width,
                  originalSnapshot.data() + (y + 1) * width,
                  pixels + y * width);
    }
    // Hai ben trai / phai
    for (int y = bY1; y <= bY2; ++y) {
        if (bX1 > 0) {
            std::copy(originalSnapshot.data() + y * width,
                      originalSnapshot.data() + y * width + bX1,
                      pixels + y * width);
        }
        if (bX2 + 1 < width) {
            std::copy(originalSnapshot.data() + y * width + (bX2 + 1),
                      originalSnapshot.data() + (y + 1) * width,
                      pixels + y * width + (bX2 + 1));
        }
    }

    return true;
}

} // namespace meitu_native
