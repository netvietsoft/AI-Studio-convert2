#ifndef MEITU_HEAD_SEMANTIC_MODEL_H
#define MEITU_HEAD_SEMANTIC_MODEL_H

#include <cstdint>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "landmark_fusion.h"

namespace meitu_native {

// =========================================================================
// 1. CÁC CẤU TRÚC HÌNH HỌC VÀ ĐẶC TRƯNG TỪNG PHÂN VÙNG GIẢI PHẪU
// (Tuân thủ mục 2, 3, 4, 6, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 32 SPEC)
// =========================================================================

struct BoundingBox2D {
    float x1 = 0.0f, y1 = 0.0f, x2 = 0.0f, y2 = 0.0f;
    float width() const { return std::max(0.0f, x2 - x1); }
    float height() const { return std::max(0.0f, y2 - y1); }
    float centerX() const { return (x1 + x2) * 0.5f; }
    float centerY() const { return (y1 + y2) * 0.5f; }
};

struct Point2DF {
    float x = 0.0f;
    float y = 0.0f;
};

// 1.1. Head Geometry (Kích thước đầu, vòm sọ, vòm trán, tỷ lệ đầu/mặt — Mục 2, 3)
struct HeadGeometry {
    BoundingBox2D headBox;
    float headWidth = 0.0f;
    float headHeight = 0.0f;
    float crownHeight = 0.0f;         // Độ cao vòm sọ từ hairline lên đỉnh đầu
    float foreheadHeight = 0.0f;      // Chiều cao trán từ chân mày tới hairline
    float foreheadWidth = 0.0f;       // Chiều rộng trán giữa 2 thái dương
    float templeWidth = 0.0f;         // Chiều rộng thái dương
    float faceToHeadRatio = 0.0f;     // Tỷ lệ diện tích khuôn mặt so với toàn bộ đầu
    float yaw = 0.0f, pitch = 0.0f, roll = 0.0f; // Góc pose đầu 3D
    float visibleContourConfidence = 0.0f;
    bool isValid = false;
};

// 1.2. Scalp Model (Da đầu — Mục 4)
struct ScalpModel {
    BoundingBox2D scalpBox;
    std::vector<Point2DF> scalpContour;
    float scalpColorR = 0.0f, scalpColorG = 0.0f, scalpColorB = 0.0f;
    float hairOcclusionRatio = 0.0f;
    bool isVisible = false;
};

// 1.3. Hair Model (Tóc — Mục 5)
struct HairModel {
    BoundingBox2D hairBox;
    Point2DF hairlineCenter;
    float apparentDensity = 0.0f;
    float apparentVolume = 0.0f;
    float shineLevel = 0.0f;
    float baseColorR = 0.0f, baseColorG = 0.0f, baseColorB = 0.0f;
    bool hasBangs = false;
    bool isValid = false;
};

// 1.4. Skin Model (Da mặt, khuyết điểm & biểu bì — Mục 6)
struct SkinModel {
    float averageLuminance = 0.0f;
    float toneChroma = 0.0f;
    float rednessIndex = 0.0f;
    float poreVisibility = 0.0f;
    float oilinessLevel = 0.0f;
    int estimatedSkinType = 0; // 0: Normal, 1: Oily, 2: Dry, 3: Combined, 4: Sensitive
    int detectedAcneCount = 0;
    int detectedSpotCount = 0;
    float wrinkleSeverity = 0.0f;
    float underEyeDarkness = 0.0f;
};

// 1.5. Forehead & Temple Model (Trán & Thái dương — Mục 7)
struct ForeheadTempleModel {
    Point2DF center;
    float curvature = 0.0f;
    float leftTempleX = 0.0f, leftTempleY = 0.0f;
    float rightTempleX = 0.0f, rightTempleY = 0.0f;
    float symmetryScore = 1.0f;
};

// 1.6. Ear Model Left/Right (Tai — Mục 8)
struct SubEarModel {
    bool isVisible = false;
    Point2DF center;
    Point2DF tragus;
    Point2DF lobeCenter;
    float width = 0.0f;
    float height = 0.0f;
    float projectionDegree = 0.0f; // Độ vểnh biểu kiến
    float lobeThickness = 0.0f;
    float rosyTone = 0.0f;
    bool hasEarring = false;
};

struct EarModel {
    SubEarModel left;
    SubEarModel right;
};

// 1.7. Eyebrow Model Left/Right (Lông mày — Mục 10)
struct SubBrowModel {
    bool isVisible = false;
    Point2DF head;
    Point2DF arch;
    Point2DF tail;
    Point2DF archPoint;
    BoundingBox2D browBox;
    float thickness = 0.0f;
    float length = 0.0f;
    float density = 0.0f;
    float colorR = 0.0f, colorG = 0.0f, colorB = 0.0f;
};

struct BrowModel {
    SubBrowModel left;
    SubBrowModel right;
    float interBrowDistance = 0.0f;
};

// 1.8. Eyelash Model Left/Right (Lông mi — Mục 11)
struct SubLashModel {
    float length = 0.0f;
    float curlAngle = 0.0f;
    float apparentDensity = 0.0f;
};

struct LashModel {
    SubLashModel left;
    SubLashModel right;
};

// 1.9. Eye Model Left/Right (Mắt — Mục 12)
struct SubEyeModel {
    bool isVisible = false;
    Point2DF center;
    Point2DF innerCanthus;
    Point2DF outerCanthus;
    Point2DF irisCenter;
    float irisRadius = 0.0f;
    float aperture = 0.0f; // Độ mở mắt
    float width = 0.0f;
    float height = 0.0f;
    float canthalTilt = 0.0f; // Độ xếch mắt
    float scleraWhiteness = 0.0f;
    bool hasCatchlight = false;
};

struct EyeModel {
    SubEyeModel left;
    SubEyeModel right;
    float eyeDistance = 0.0f;
    float eyeSymmetry = 1.0f;
};

// 1.10. Nose Model (Mũi — Mục 13)
struct NoseModel {
    Point2DF root;
    Point2DF bridge;
    Point2DF tip;
    Point2DF leftAla;
    Point2DF rightAla;
    float bridgeWidth = 0.0f;
    float bridgeHeight = 0.0f;
    float alaWidth = 0.0f;
    float tipProjection = 0.0f;
    float length = 0.0f;
    float symmetry = 1.0f;
};

// 1.11. Cheek Model Left/Right (Má & Gò má — Mục 14)
struct CheekModel {
    Point2DF leftCheekbone;
    Point2DF rightCheekbone;
    float cheekWidth = 0.0f;
    float cheekboneProminence = 0.0f;
    float leftSmileLineSeverity = 0.0f;
    float rightSmileLineSeverity = 0.0f;
};

// 1.12. Jaw & Chin Model (Xương hàm & Cằm — Mục 15, 16)
struct JawChinModel {
    Point2DF leftJawAngle;
    Point2DF rightJawAngle;
    Point2DF chinTip;
    float jawWidth = 0.0f;
    float jawAngleDegrees = 0.0f;
    float chinLength = 0.0f;
    float chinWidth = 0.0f;
    float chinSharpness = 0.0f;
    float chinProjection = 0.0f;
    float vLineFactor = 0.0f;
};

// 1.13. Philtrum Model (Nhân trung — Mục 17)
struct PhiltrumModel {
    Point2DF baseNose;
    Point2DF cupidsBowCenter;
    float length = 0.0f;
    float width = 0.0f;
    float grooveDepth = 0.0f;
};

// 1.14. Mouth & Lip Model (Miệng & Môi — Mục 18)
struct MouthLipModel {
    Point2DF center;
    Point2DF leftCorner;
    Point2DF rightCorner;
    Point2DF upperLipTop;
    Point2DF lowerLipBottom;
    float mouthWidth = 0.0f;
    float upperLipThickness = 0.0f;
    float lowerLipThickness = 0.0f;
    float smileCurve = 0.0f;
    float lipColorR = 0.0f, lipColorG = 0.0f, lipColorB = 0.0f;
    float lipGloss = 0.0f;
    float mouthOpenness = 0.0f;
};

// 1.15. Teeth Model (Răng — Mục 19)
struct TeethModel {
    bool isVisible = false;
    float whitenessLevel = 0.0f;
    float yellowCastReduction = 0.0f;
    float enamelGloss = 0.0f;
    float alignmentScore = 1.0f;
};

// 1.16. Beard Model (Râu — Mục 20)
struct BeardModel {
    bool hasMustache = false;
    bool hasGoatee = false;
    bool hasChinstrap = false;
    float apparentDensity = 0.0f;
    float grayPercentage = 0.0f;
    float colorR = 0.0f, colorG = 0.0f, colorB = 0.0f;
};

// 1.17. Neck & Clavicle Model (Cổ & Xương quai xanh — Mục 21, 22)
struct NeckClavicleModel {
    Point2DF throatCenter;
    Point2DF leftClavicle;
    Point2DF rightClavicle;
    float neckWidth = 0.0f;
    float neckLength = 0.0f;
    float neckWrinkleSeverity = 0.0f;
    float clavicleProminence = 0.0f;
    float shoulderSlope = 0.0f;
    float skinToneDeltaFaceNeck = 0.0f;
};

// 1.18. Accessory & Occlusion Model (Kính, Khuyên tai, Vật cản — Mục 23)
struct AccessoryOcclusionModel {
    bool hasGlasses = false;
    BoundingBox2D glassesBox;
    bool hasEarrings = false;
    BoundingBox2D leftEarringBox;
    BoundingBox2D rightEarringBox;
    bool hasMask = false;
    bool hasHat = false;
    bool isHandOccludingFace = false;
};

// 1.19. Depth & Lighting Model (Chiều sâu bề mặt & Hướng sáng 3D — Mục 24)
struct DepthLightingModel {
    float estimatedLightDirectionX = 0.0f;
    float estimatedLightDirectionY = -0.5f;
    float estimatedLightDirectionZ = 0.866f;
    float dominantLightIntensity = 1.0f;
    float relativeDepthFaceToBack = 0.0f;
};

// =========================================================================
// 2. KHUNG DỮ LIỆU ĐẦU - MẶT TOÀN DIỆN (HEAD FRAME RESULT — Mục 32 SPEC)
// =========================================================================
struct HeadFrameResult {
    int imageWidth = 0;
    int imageHeight = 0;
    float overallConfidence = 0.0f;
    bool isFaceDetected = false;
    bool isValid = false;

    SubBrowModel browLeft;
    SubBrowModel browRight;
    SubEyeModel eyeLeft;
    SubEyeModel eyeRight;

    HeadGeometry            headGeometry;
    ScalpModel              scalp;
    HairModel               hair;
    SkinModel               skin;
    ForeheadTempleModel     foreheadTemple;
    EarModel                ear;
    BrowModel               brow;
    LashModel               lash;
    EyeModel                eye;
    NoseModel               nose;
    CheekModel              cheek;
    JawChinModel            jawChin;
    PhiltrumModel           philtrum;
    MouthLipModel           mouthLip;
    TeethModel              teeth;
    BeardModel              beard;
    NeckClavicleModel       neckClavicle;
    AccessoryOcclusionModel accessory;
    DepthLightingModel      depthLighting;
};

// =========================================================================
// 3. LỚP ĐIỀU PHỐI MÔ HÌNH HÓA ĐẦU - MẶT CHUẨN SEMANTIC (HEAD SEMANTIC ENGINE)
// =========================================================================
class HeadSemanticEngine {
public:
    static HeadSemanticEngine& getInstance();

    // Khởi tạo và trích xuất toàn bộ Semantic Head Model từ ảnh và Fused Face Geometry
    HeadFrameResult extractSemanticModel(
        const uint32_t* pixels,
        int width,
        int height,
        const MeituReborn::FusedFaceGeometry& fused
    );

    // Static convenience method from landmarks
    static HeadFrameResult extractSemanticModel(
        const std::vector<float>& landmarks,
        const uint32_t* pixels,
        int width,
        int height
    ) {
        MeituReborn::FusedFaceGeometry fused;
        if (landmarks.size() >= 468 * 2) {
            fused.dense478.resize(478);
            for (size_t i = 0; i < 478 && i * 2 + 1 < landmarks.size(); ++i) {
                fused.dense478[i] = { landmarks[i * 2], landmarks[i * 2 + 1], 0.0f };
            }
        }
        if (landmarks.size() >= 212) {
            fused.anchors106.assign(landmarks.begin(), landmarks.begin() + 212);
        }
        HeadFrameResult res = getInstance().extractSemanticModel(pixels, width, height, fused);
        res.isValid = res.isFaceDetected;
        return res;
    }


    // Lấy kết quả khung hình gần nhất
    const HeadFrameResult& getLastFrameResult() const { return mLastResult; }

private:
    HeadSemanticEngine() = default;
    HeadFrameResult mLastResult;
};

} // namespace meitu_native

#endif // MEITU_HEAD_SEMANTIC_MODEL_H
