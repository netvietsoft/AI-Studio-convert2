# HCE V1 — PRODUCTION PIPELINE TRACE & EXECUTION GRAPH
**Document ID:** HCE-V1-PROD-TRACE-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1  
**Architecture Contract:** HCE_CONTRACT_V1  

---

## 1. BIỂU ĐỒ ĐƯỜNG ỐNG SẢN XUẤT NATIVE THỰC TẾ (PRODUCTION CALL GRAPH)

```mermaid
graph TD
    UI[Android UI / PhotoEditorFragment] -->|Call| KT[MeituNativeEngine.kt: nativeApplyHairStrandDye]
    KT -->|JNI Direct Call| JNI[jni_bridge.cpp: Java_com_meitu_core_nativeengine_MeituNativeEngine_nativeApplyHairStrandDye]
    JNI -->|Lock Bitmap Buffer| BLK[AndroidBitmap_lockPixels]
    BLK -->|Call Pipeline| PIPE[HairColorPipeline::applyColor]
    
    subgraph Core_Pipeline [HairColorPipeline Execution Engine]
        PIPE --> P0[P0: HairMattingEngine::detectAndRefineHairMatte]
        P0 -->|p0Matte Contract| P1[P1: HairOrientationEngine::computeOrientation]
        P1 -->|orientation Contract| P2[P2: HairTextureEngine::extractTexture]
        P0 -->|p0Matte Contract| P3[P3: HairAppearanceEngine::extractAppearance]
        
        P2 -->|texture Contract| P4[P4: HairDyeMaterialEngine::applyDye]
        P3 -->|appearance Contract| P4
        
        P4 -->|recoloredPixels| P5[P5: HairAnisotropicSpecularEngine::applySpecular]
        P1 -->|orientation Contract| P5
        P3 -->|appearance Contract| P5
        
        P5 -->|finalPixels| P6[P6: HairGpuBackend::executePipeline]
        P6 -->|Unified Output Buffer| OUT[HairRenderOutput]
    end
    
    OUT -->|Unlock Bitmap| UNBLK[AndroidBitmap_unlockPixels]
    UNBLK -->|Return Success| UI
```

---

## 2. CHI TIẾT CONTRACTS & DỮ LIỆU ĐẦU VÀO/ĐẦU RA THEO TỪNG GIAI ĐOẠN

| Giai đoạn | Entry Function | Input Contract | Output Contract | Backend thực thi | Error/Fallback Handling |
|---|---|---|---|---|---|
| **P0** | `HairMattingEngine::detectAndRefineHairMatte` | `srcPixels, W, H, landmarks` | `HairMatteResult` (alphaData, boundaryMask) | Native C++ BiSeNet + Guided Filter | Trả alpha rỗng nếu không có mặt, bảo vệ nền |
| **P1** | `HairOrientationEngine::computeOrientation` | `srcPixels, W, H, p0Matte` | `HairOrientationField` (angles, confidence) | C++ OpenMP Structure Tensor | Fallback góc thẳng đứng $(0.0)$ nếu $C < 0.2$ |
| **P2** | `HairTextureEngine::extractTexture` | `srcPixels, W, H, p0Matte, orientation` | `HairTextureContext` (flowAlignedTexture) | C++ OpenMP Laplace Directional Filter | Bảo lưu nguyên bản nếu gradient quá yếu |
| **P3** | `HairAppearanceEngine::extractAppearance` | `srcPixels, W, H, p0Matte` | `HairAppearanceContext` (shadowMap, highlightMask) | C++ OpenMP Rec.601 Adaptive | Bảo toàn trung vị nếu độ tương phản thấp |
| **P4** | `HairDyeMaterialEngine::applyDye` | `srcPixels, W, H, appearance, texture, material` | `recoloredPixels` (ARGB32) | C++ OpenMP OKLab Transform | Clamping sRGB chống cháy màu ngoài gamut |
| **P5** | `HairAnisotropicSpecularEngine::applySpecular` | `recoloredPixels, orientation, appearance, specular` | `finalPixels` (ARGB32) | C++ OpenMP Marschner R-Lobe | Giới hạn $I_{\text{specular}} \le 0.35$ chống lóa |
| **P6** | `HairGpuBackend::executePipeline` | `HairRenderInputs` | `HairRenderOutput` | OpenMP Multi-core CPU Reference | Graceful fallback CPU khi Vulkan chưa link |
