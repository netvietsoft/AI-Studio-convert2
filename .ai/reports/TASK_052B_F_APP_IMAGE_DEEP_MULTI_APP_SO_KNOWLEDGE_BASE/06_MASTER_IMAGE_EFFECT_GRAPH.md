# Master Cross-App Image & Video Pipeline Graph

```mermaid
graph TD
  subgraph MEITU_ECOSYSTEM [Meitu Xiuxiu, BeautyPlus, Wink]
    M_UI[Meitu UI / Camera] --> M_MANIS[Manis NPU / ARKernel3]
    M_MANIS --> M_FILTER[MTFilterKernel / PixRenderCore]
    M_FILTER --> M_RENDER[MTMVCore / LayerFlow Compositor]
  end
  subgraph FACETUNE_ECOSYSTEM [Facetune]
    F_UI[Facetune UI] --> F_3DMM[Facetune 3DMM Face Model]
    F_3DMM --> F_RENDER[Render Core / ColorTransfer]
    F_RENDER --> F_XENO[Xeno Native Compositor]
  end
  subgraph BYTEDANCE_ECOSYSTEM [Ulike]
    U_UI[Ulike UI] --> U_BYTENN[ByteNN Vision Runtime]
    U_BYTENN --> U_EFFECT[ByteDance EffectSDK 26.8MB]
    U_EFFECT --> U_VESDK[TTVESDK Video Engine]
  end
  subgraph ONNX_RESTORE_ECOSYSTEM [Remini]
    R_UI[Remini UI] --> R_JAVET[Javet V8 Logic]
    R_JAVET --> R_ONNX[ONNX Runtime 19.3MB]
    R_ONNX --> R_TILE[Tile Super-Resolution Reconstructor]
  end
```

### Pipeline Cross-Comparison
- **Real-Time AR Face Mesh:** SenseTime (`libst_mobile.so`, 240 landmarks) and Meitu (`libarkernel3.so` + `libMTAiInterface.so`) lead in ultra-dense landmark tracking, while Facetune implements parametric 3D Morphable Model regression (`libfacetune.so`).
- **Hair Color & Matting:** Meitu (`libMTFilterKernel.so` + `libLayerFlow.so`) utilizes directional Line Integral Convolution (LIC) with soft-light hair FBO blending, whereas Facetune couples selfie segmentation TFLite with multi-pass color transfer.
- **Super-Resolution & Restoration:** Remini leads with local ONNX neural execution (`libonnxruntime.so`) operating in tiled overlapping patches.
