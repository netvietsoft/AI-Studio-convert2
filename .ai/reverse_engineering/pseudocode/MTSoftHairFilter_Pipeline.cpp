// CONVERT2 CLEAN-ROOM RECONSTRUCTION: MTSoftHairFilter Pipeline
// SOURCE: libMTFilterKernel.so (offset: 0x000f3f58, ARM64 little-endian)
// STATUS: LEVEL_5_REIMPLEMENTABLE
#include <cstdint>
#include <cmath>
#include <algorithm>

struct CGSize {
    float width;
    float height;
    CGSize(float w, float h) : width(w), height(h) {}
};

class GPUImageFramebuffer;

class MTSoftHairFilter {
public:
    void renderToTextureWithVerticesAndTextureCoordinates(
        const float* vertices,
        const float* textureCoordinates,
        GPUImageFramebuffer* sourceFBO,
        GPUImageFramebuffer* maskFBO)
    {
        // 1. Luminance pass (0x000f42fc)
        this->grayFilterToFBO(vertices, textureCoordinates, sourceFBO, this->m_grayFBO);

        // 2. Hair mask normalizer & guided filter pass (0x000f4400)
        this->hairMaskFilterToFBO(vertices, textureCoordinates, maskFBO, this->m_maskFBO);

        // 3. Horizontal 5-tap Gaussian blur pass (0x000f4528)
        this->blurHFilterToFBO(vertices, textureCoordinates, this->m_maskFBO, this->m_blurHFBO);

        // 4. Vertical 5-tap Gaussian blur pass (0x000f46d0)
        this->blurVFilterToFBO(vertices, textureCoordinates, this->m_blurHFBO, this->m_blurVFBO);

        // 5. Final 9x9 Unsharp Mask + Clarity 0.4 pass (0x000f4878)
        CGSize targetSize(962.0f, 1280.0f);
        int mode = 0; // Alpha channel mode
        this->softHairFilterToFBO(vertices, textureCoordinates, sourceFBO, this->m_blurVFBO, mode, targetSize, this->m_outputFBO);
    }

private:
    GPUImageFramebuffer* m_grayFBO = nullptr;
    GPUImageFramebuffer* m_maskFBO = nullptr;
    GPUImageFramebuffer* m_blurHFBO = nullptr;
    GPUImageFramebuffer* m_blurVFBO = nullptr;
    GPUImageFramebuffer* m_outputFBO = nullptr;

    void grayFilterToFBO(const float* v, const float* uv, GPUImageFramebuffer* inFBO, GPUImageFramebuffer* outFBO);
    void hairMaskFilterToFBO(const float* v, const float* uv, GPUImageFramebuffer* inFBO, GPUImageFramebuffer* outFBO);
    void blurHFilterToFBO(const float* v, const float* uv, GPUImageFramebuffer* inFBO, GPUImageFramebuffer* outFBO);
    void blurVFilterToFBO(const float* v, const float* uv, GPUImageFramebuffer* inFBO, GPUImageFramebuffer* outFBO);
    void softHairFilterToFBO(const float* v, const float* uv, GPUImageFramebuffer* inSrc, GPUImageFramebuffer* inBlur, int mode, CGSize size, GPUImageFramebuffer* outFBO);
};
