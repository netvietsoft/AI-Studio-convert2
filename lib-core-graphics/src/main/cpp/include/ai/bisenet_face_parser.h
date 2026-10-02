#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <memory>

namespace ncnn {
    class Net;
}

namespace meitu::ai {

enum class Face19Class : uint8_t {
    BACKGROUND = 0,
    SKIN = 1,
    LEFT_BROW = 2,
    RIGHT_BROW = 3,
    LEFT_EYE = 4,
    RIGHT_EYE = 5,
    GLASSES = 6,
    LEFT_EAR = 7,
    RIGHT_EAR = 8,
    EARRING = 9,
    NOSE = 10,
    MOUTH_TEETH = 11,
    UPPER_LIP = 12,
    LOWER_LIP = 13,
    NECK = 14,
    NECKLACE = 15,
    CLOTH = 16,
    HAIR = 17,
    HAT = 18
};

class BiSeNetFaceParser {
public:
    static BiSeNetFaceParser& getInstance();

    BiSeNetFaceParser();
    ~BiSeNetFaceParser();

    bool init(const std::string& paramPath, const std::string& binPath);
    bool isInitialized() const { return mInitialized; }

    bool parseFace19(
        const uint32_t* srcRgba,
        int width,
        int height,
        std::vector<uint8_t>& outMask512,
        std::vector<float>* outClassProb512 = nullptr,
        std::vector<float>* outHairProb512 = nullptr
    );

    bool parseFace19Adaptive(
        const uint32_t* srcRgba,
        int width,
        int height,
        std::vector<uint8_t>& outFullMask,
        std::vector<uint8_t>* outMask512 = nullptr,
        std::vector<float>* outHairProb512 = nullptr
    );

    bool extractSingleClassAlpha(
        Face19Class targetClass,
        const std::vector<uint8_t>& mask512,
        std::vector<float>& outAlpha512
    );

    bool extractIsolatedHairAlpha(
        const std::vector<uint8_t>& mask512,
        std::vector<float>& outHairAlpha512
    );

    bool extractSoftHairAlpha(
        const std::vector<float>& hairProb512,
        const std::vector<uint8_t>& mask512,
        std::vector<float>& outHairAlpha512
    );

    bool extractSkinAndNeckAlpha(
        const std::vector<uint8_t>& mask512,
        std::vector<float>& outSkinAlpha512
    );

    bool extractLipsAlpha(
        const std::vector<uint8_t>& mask512,
        std::vector<float>& outLipsAlpha512
    );

private:
    ncnn::Net* mNet;
    bool mInitialized;

    void fallbackGeometricParse(
        const uint32_t* srcRgba,
        int width,
        int height,
        std::vector<uint8_t>& outMask512,
        std::vector<float>* outHairProb512 = nullptr
    );
};

} // namespace meitu::ai
