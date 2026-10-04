# CALLGRAPH: Hair Specular & Feathering Integration Call Graph
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Rule 11 Clean-Room  

---

```mermaid
graph TD
    A[UI Slider: Shine & Smoothness] --> B[EffectDenseHairDataJNI::nSetTraditionHairDyeIntensityAndShine]
    B --> C[meitu::hair::HairDyeFilterCoordinator::SetParameters]
    C --> D[meitu::hair::MTSoftHairFilter::DrawAllPasses]
    
    subgraph MultiPass Execution Pipeline
        D --> P1[Pass 1: HairMaskFilter 0x000e8210]
        P1 --> P2[Pass 2: MakeupHairSoftPart_Feather 0x000a2410]
        P2 --> P3[Pass 3: GrayFilter 0x0008ebd4]
        P3 --> P4[Pass 4: SoftHairFilter_PegtopSoftLight 0x0009c310]
        P4 --> P5[Pass 5: MTAnisotropicSpecularShader 0x0009d180]
    end
    
    P5 --> OUT[Final Color Render Buffer FBO]
```

---

## BẢNG XREF LIÊN KẾT NHỊ PHÂN
| Hàm Native C++ | Địa Chỉ Offset | Ký Hiệu Đã Demangle | Lệnh Nhánh ARM64 | Thư Viện Nguồn |
|---|---|---|---|---|
| `MakeupHairSoftPart_Feather` | `0x000a2410` | `_ZN7meitu24MakeupHairSoftPartFilter16FeatherEdgeAlphaEPNS_12RenderContextE` | `BL 0xa2410` | `libMTFilterKernel.so` |
| `MTAnisotropicSpecularShader` | `0x0009d180` | `_ZN7meitu25MTAnisotropicSpecularShader9RenderPassEPNS_12RenderContextE` | `BL 0x9d180` | `libMTFilterKernel.so` |
| `SoftHairFilter_PegtopSoftLight` | `0x0009c310` | `_ZN7meitu18SoftHairFilterBase17PegtopSoftLightFBOEPNS_12RenderContextE` | `BL 0x9c310` | `libMTFilterKernel.so` |
