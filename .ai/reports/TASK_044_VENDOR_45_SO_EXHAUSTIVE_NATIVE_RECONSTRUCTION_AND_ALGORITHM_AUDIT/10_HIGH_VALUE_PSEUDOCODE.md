# TASK_044 — HIGH-VALUE ALGORITHM RECONSTRUCTION & PSEUDOCODE

## 1. MTSoftHairFilter: Complete FBO Render Pipeline (`libMTFilterKernel.so`)

```cpp
// RECONSTRUCTED VENDOR PIPELINE: MTSoftHairFilter
// Provenance: libMTFilterKernel.so (ELF 64-bit ARM64, SHA-256 verified)
void MTSoftHairFilter::renderHairPipeline(
    GLuint inputTexture, GLuint hairMaskTexture, GLuint toneLutTexture,
    float intensity, float shine, FBO& outputFBO) 
{
    // Step 1: Extract Luminance map from input portrait
    // Pass: GrayFilterToFBO
    grayFBO.bind();
    grayShader.use();
    grayShader.setTexture("u_inputTexture", inputTexture);
    renderQuad();

    // Step 2: Separate 2-Pass Gaussian blur on Hair Mask for soft subpixel edge
    // Pass: BlurHFilterToFBO
    blurHFBO.bind();
    blurHShader.use();
    blurHShader.setTexture("u_maskTexture", hairMaskTexture);
    blurHShader.setFloat("u_blurRadius", 2.5f);
    renderQuad();

    // Pass: BlurVFilterToFBO
    blurVFBO.bind();
    blurVShader.use();
    blurVShader.setTexture("u_maskTexture", blurHFBO.getTexture());
    blurVShader.setFloat("u_blurRadius", 2.5f);
    renderQuad();

    // Step 3: Photoshop Soft Light Blending with Tone LUT
    // Pass: SoftHairFilterToFBO / MTFilter_PsSoftLightr.fs
    outputFBO.bind();
    softHairShader.use();
    softHairShader.setTexture("u_inputTexture", inputTexture);
    softHairShader.setTexture("u_grayMap", grayFBO.getTexture());
    softHairShader.setTexture("u_hairMask", blurVFBO.getTexture());
    softHairShader.setTexture("u_toneLutMap", toneLutTexture);
    softHairShader.setFloat("u_intensity", intensity);
    softHairShader.setFloat("u_shine", shine);
    renderQuad();
}
```

## 2. GLSL Soft Light Mathematical Equation (`MTFilter_PsSoftLightr.fs`)

```glsl
// Fragment Shader equation extracted from libMTFilterKernel.so
vec3 ps_soft_light(vec3 base, vec3 blend) {
    vec3 result;
    for (int i = 0; i < 3; i++) {
        if (blend[i] <= 0.5) {
            result[i] = 2.0 * base[i] * blend[i] + base[i] * base[i] * (1.0 - 2.0 * blend[i]);
        } else {
            result[i] = 2.0 * base[i] * (1.0 - blend[i]) + sqrt(base[i]) * (2.0 * blend[i] - 1.0);
        }
    }
    return result;
}
```

## 3. Display-P3 / sRGB Matrix Transcode (`libPVGColorFunctions.so`)

```cpp
// Reconstructed from .rodata floating point constants
static const float P3_TO_SRGB[3][3] = {
    {  1.22494017f, -0.22474041f,  0.00000000f },
    { -0.04205696f,  1.04205696f,  0.00000000f },
    { -0.01963760f, -0.07863605f,  1.09827365f }
};
```
