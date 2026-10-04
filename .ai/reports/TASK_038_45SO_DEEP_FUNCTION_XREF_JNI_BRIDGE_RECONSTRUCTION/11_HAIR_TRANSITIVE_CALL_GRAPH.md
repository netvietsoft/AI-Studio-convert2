# TASK_038 — Hair Transitive Call Graph Reconstruction

## 1. End-to-End Transitive Trace (UI to Native GPU & Math)

```mermaid
sequenceDiagram
    autonumber
    participant UI as HairRecolorActivity (UI / Kotlin)
    participant JNI as MTFilterKernelRender (JNI Bridge)
    participant Core as CMTFilterSoftHair (libMTFilterKernel.so)
    participant FBO as OpenGL Framebuffer Objects (4 FBOs)
    participant Shader as GLSL Fragment Shader Pipeline
    participant Manis as BiSeNet / Manis Neural Engine

    UI->>Manis: Request Hair Segmentation Matte
    Manis-->>UI: Return 8-bit Alpha Hair Mask (512x512)
    UI->>JNI: nInit(handle)
    UI->>JNI: nLoadFilterConfig(handle, "hair_dye_rose_gold.json")
    UI->>JNI: nSetBodyTexture(handle, maskTexId, w, h)
    UI->>JNI: nRenderToOutTexture(handle, inTex, outTex, w, h, orientation, frameType)
    
    JNI->>Core: FilterToFBO(inTex, outTex, isPortrait)
    Core->>FBO: ReleaseFramebufferTexture()
    Core->>FBO: CreateFBO(4 intermediate textures: Gray, Grad, BlurH, BlurV)
    
    Note over Core,Shader: Pass 1: Luminance Extraction
    Core->>Shader: GrayFilterToFBO(inTex) [dot(rgb, vec3(0.298912, 0.586611, 0.114478))]
    Shader-->>FBO: Output to FBO_Gray
    
    Note over Core,Shader: Pass 2: 2x2 Structure Tensor / Orientation Field
    Core->>Shader: HairMaskFilterToFBO(FBO_Gray, MaskTex) [gradDouble calculation]
    Shader-->>FBO: Output to FBO_Grad
    
    Note over Core,Shader: Pass 3 & 4: Separable 5-Tap Tensor Blur
    Core->>Shader: BlurHFilterToFBO(FBO_Grad) [Offsets[5], Weights[5]]
    Shader-->>FBO: Output to FBO_BlurH
    Core->>Shader: BlurVFilterToFBO(FBO_BlurH) [Offsets[5], Weights[5]]
    Shader-->>FBO: Output to FBO_BlurV
    
    Note over Core,Shader: Pass 5: 10-Tap Strand-Aligned Bilateral Blend
    Core->>Shader: SoftHairFilterToFBO(inTex, FBO_BlurV, MaskTex, LUT)
    Note right of Shader: atan(grad.y, grad.x) * 0.5 + PI*0.5<br/>10-tap Gaussian (sigma=5.0)<br/>Photoshop Soft Light Equation<br/>mix(orig, blend, mask * gain)
    Shader-->>FBO: Render Final Pixels to outTex
    FBO-->>UI: Display Onscreen / Save to Bitmap
```

---

## 2. Function Trace Nodes & Addresses

| Step | Component | Symbol / Function Name | Library | RVA | Role in Pipeline |
|---|---|---|---|---|---|
| **01** | UI | `HairRecolorActivity.applyHairDye` | Android APK | DEX | User selects color preset & intensity slider |
| **02** | JNI | `MTFilterKernelRender.nRenderToOutTexture` | Java | DEX | Entry bridge into native graphics |
| **03** | JNI Target | `Java_com_meitu_core_MTFilterKernelRender_nRenderToOutTexture` | `libMTFilterKernel.so` | `0x000bfee4` | Unpacks JNI arguments into native C++ context |
| **04** | Dispatcher | `MTFilterKernelRender::RenderToOutTexture` | `libMTFilterKernel.so` | `0x000bfef8` | Binds active filter configuration |
| **05** | Filter Core | `CMTFilterSoftHair::FilterToFBO` | `libMTFilterKernel.so` | `0x001344e8` | Master 5-pass hair compositor coordinator |
| **06** | Pass 1 | `CMTFilterSoftHair::GrayFilterToFBO` | `libMTFilterKernel.so` | `0x0013488c` | Computes grayscale luminance FBO |
| **07** | Pass 2 | `CMTFilterSoftHair::HairMaskFilterToFBO` | `libMTFilterKernel.so` | `0x00134970` | Computes 2x2 Structure Tensor gradient field |
| **08** | Pass 3 | `CMTFilterSoftHair::BlurHFilterToFBO` | `libMTFilterKernel.so` | `0x00134a90` | Horizontal 5-tap blur on tensor field |
| **09** | Pass 4 | `CMTFilterSoftHair::BlurVFilterToFBO` | `libMTFilterKernel.so` | `0x00134c10` | Vertical 5-tap blur on tensor field |
| **10** | Pass 5 | `CMTFilterSoftHair::SoftHairFilterToFBO` | `libMTFilterKernel.so` | `0x00134d90` | 10-tap anisotropic strand-aligned Soft Light filter |
| **11** | Shader Exec | `glDrawArrays(GL_TRIANGLE_STRIP, 0, 4)` | `libGLESv2.so` | PLT | Final GPU rasterization |