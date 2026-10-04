# Master Cross-App Image Effect Graph

```mermaid
flowchart TD
    subgraph Input_Stage [Stage 1: Ingestion & Decode]
        IN[Camera / Gallery Bitmap] --> DEC[Native YUV/RGBA Decode: libyuv / libturbojpeg]
        DEC --> CS[Color Management: sRGB / Display-P3 / ProPhoto]
    end

    subgraph Detection_Stage [Stage 2: Vision & AI Tracking]
        CS --> LM[Facial Landmark Tracking: 106-pt / MediaPipe / SenseTime]
        CS --> SEG[Semantic Segmentation: Hair, Face Skin, Background, Body]
    end

    subgraph Core_Engine [Stage 3: Multi-App Specialized Native Engines]
        LM --> WARP[Reshape / Liquify: Meitu / Facetune Radial Falloff]
        SEG --> HAIR[Hair Recolor: Meitu 5-pass Directional LIC]
        SEG --> SKIN[Skin Smooth: Facetune Frequency Separation + Pore Texture]
        CS --> LUT[Color Grading: VSCO Tetrahedral 3D LUT Evaluation]
    end

    subgraph Composite_Stage [Stage 4: FBO Ping-Pong & Output]
        WARP --> COMP[Double-Buffered FBO Render Graph: libVERenderer / librender]
        HAIR --> COMP
        SKIN --> COMP
        LUT --> COMP
        COMP --> CLARITY[Unsharp Mask Clarity Scaling: 0.4 x 1.8]
        CLARITY --> OUT[Final Surface / Storage Encode]
    end
```

## Architectural Synthesis Across 14 Apps
1. **Meitu Family (Meitu, BeautyPlus, Wink)**: Shares unified core (`libMTFilterKernel.so`, `libManis.so`, `libVERenderer.so`, `libPVGColorFunctions.so`). High degree of code reuse for hair, beauty, and video.
2. **Facetune (Lightricks)**: Highly optimized C++ math core (`libfacetune.so`, `librender.so`) with radial falloff liquify and Google MediaPipe SelfieSegmentation.
3. **VSCO**: Focus on color science (`libvscocore.so`, `libuniffi_cel.so`) with Rust UniFFI bindings and tetrahedral 3D LUT sampling.
4. **ByteDance (Ulike)**: EffectSDK (`libeffect.so`) with custom neural runtime (`libbytenn.so`) and brush stroke engine.
5. **B612 / Snow**: SenseTime computer vision suite (`libst_mobile.so`) with 106-point tracking and OpenGL PBO buffers.
