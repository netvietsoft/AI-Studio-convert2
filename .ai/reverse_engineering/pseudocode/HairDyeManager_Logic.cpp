// CONVERT2 CLEAN-ROOM RECONSTRUCTION: HairDyeManager Logic
// SOURCE: libLayerFlow.so & MTIKABHairFilter.java
// STATUS: LEVEL_5_REIMPLEMENTABLE
#include <cstdint>
#include <string>

struct HairDyeConfig {
    float intensity = 0.8f;
    float shine = 0.5f;
    int mode = 0; // 0 = Alpha mask, 1 = Red mask
    bool isHighlights = false;
    std::string lutPath;
};

class HairDyeManager {
public:
    void setIntensityAndShine(float intensity, float shine) {
        m_config.intensity = std::clamp(intensity, 0.0f, 1.0f);
        m_config.shine = std::clamp(shine, 0.0f, 1.0f);
        updateShaderUniforms();
    }

    void loadConfig(const std::string& lutPath, bool isTraditional) {
        m_config.lutPath = lutPath;
        m_isTraditional = isTraditional;
    }

private:
    HairDyeConfig m_config;
    bool m_isTraditional = true;
    void updateShaderUniforms();
};
