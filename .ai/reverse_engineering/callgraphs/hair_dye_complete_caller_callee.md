# Đồ Thị Gọi Hàm Hoàn Chỉnh Toàn Chuỗi Nhuộm Tóc (End-to-End Call Graph)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  

---

```
[Android UI: HairDyeActivity]
  │
  ├─► EffectDenseHairDataJNI.nSetTraditionHairDyeIntensityAndShine (JNI)
  │     │
  │     └─► libLayerFlow.so (0x00051e80)
  │           │
  │           ├─► LayerFlow::CHairConfigDecoder::DecodeConfigJSON (0x00067340)
  │           │
  │           └─► LayerFlow::CHairConfigLoader::LoadResources (0x000685b0)
  │                 │
  │                 └─► libMTFilterKernel.so (0x000f3f58: CMTFilterSoftHair)
  │                       │
  │                       ├─► CMTFilterHairMask::ProcessMask (0x000e8210)
  │                       │     └── [Pass 1: Ngưỡng & Làm mềm mặt nạ Class 17]
  │                       │
  │                       ├─► CMTFilterGrayEye::ApplyFilter (0x0008ebd4)
  │                       │     └── [Pass 2: Triệt sắc nền tự nhiên]
  │                       │
  │                       ├─► CStructureTensor2D::ComputeGradients (0x00094120)
  │                       │     │
  │                       │     └─► CMTFilterBlur::Separable5x5 (0x0008edd8)
  │                       │           └── [Pass 3: Khử nhiễu ten-xơ hướng sợi]
  │                       │
  │                       ├─► CFilterHairLIC21::IntegrateAlongFlow (0x00097480)
  │                       │     └── [Pass 4: Tích phân đường cong 21-tap LIC]
  │                       │
  │                       ├─► CSoftHairBlending::ApplyPegtopMap (0x0009c310)
  │                       │     └── [Pass 5: Pegtop SoftLight hòa trộn sắc tố]
  │                       │
  │                       └─► CMakeupHairMatcher::BlendScalpHairline (0x000a12e0)
  │                             └── [Pass 6: Phối trộn chân tóc tiếp giáp da mặt]
  │
  └─► libPVGColorFunctions.so (0x00011170: Apply3DLUTTetra)
        └── [Pass 7: Ánh xạ 3D LUT hoàn thiện màu sắc điện ảnh]
```
