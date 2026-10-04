# TASK_045 — MANIS, LAYERFLOW & PVG FORENSIC REVALIDATION

### 1. `libManis.so` Forensic Revalidation
- **Binary SHA-256:** `9928576` bytes | ELF 64-bit AArch64
- **TASK_044 Erroneous Claim:** *"BiSeNet 19-Class Semantic Segmentation, ArgMax(Softmax(Conv2D(X))) -> Class 17 (Hair), HIGH, Model Strings & LayerFlow Interface"*
- **TASK_045 Physical Verification:**
  - Automated binary search for string needles:
    * `BiSeNet` / `bisenet`: **0 occurrences**
    * `hair` / `Hair`: **0 occurrences**
    * `segment` / `Segment`: **0 occurrences**
  - Architecture Analysis: `libManis.so` is Meitu's proprietary neural network inference runtime (equivalent to NCNN, TNN, or MNN). It implements general tensor execution primitives: `manis::Executor`, `GroupNorm`, `ScatterND`, `SVMClassifier`, `Softmax`.
  - **Verdict:** **DOWNGRADED TO UNSUPPORTED RUNTIME EXECUTOR**. No BiSeNet or class-17 hair segmentation logic is hardcoded inside the binary. Model topologies and class mappings are supplied exclusively via external `.manis` model files at runtime.

---

### 2. `libLayerFlow.so` Forensic Revalidation
- **Binary SHA-256:** `5544776` bytes | ELF 64-bit AArch64
- **Component Identified:** `CLFDenseHairProcessor` (Modular Hair Dye Engine)
- **TASK_045 Physical Verification:**
  - Code XREFs at `0x3fc088` and `0x3fc0e8` reference the symbol `decodeHairDyeConfig` (.rodata `0x1dc829`).
  - Code XREFs at `0x3fa328` and `0x3fa454` reference the symbol `loadHairDyeConfig` (.rodata `0x1dea88`).
  - Extracted Chinese format strings reveal exact asset package dependencies:
    * `CLFDenseHairProcessor<%s:%d> 染发素材包中的 config.json 解析失败: %s - %s`
    * `CLFDenseHairProcessor<%s:%d> 无法打开染发素材 config 文件: %s/config.json`
    * `CLFDenseHairProcessor<%s:%d> 染发素材 config 路径为空`
  - Texture Assets: Directly references `lut.png` (.rodata `0x1dcd58`) for hair tone recoloring.
  - **Verdict:** **EVIDENCE-GROUNDED REVALIDATION**. Proves that hair dyeing operates via material asset bundles containing `config.json` and `lut.png`.

---

### 3. `libPVGColorFunctions.so` Forensic Revalidation
- **Binary SHA-256:** `380224` bytes | ELF 64-bit AArch64
- **TASK_044 Erroneous Claim:** *"Display-P3 / sRGB Matrix Transcode, M_p3_to_srgb = [[1.2249, -0.2247, 0.0], ...], HIGH, Matrix Coefficients in .rodata"*
- **TASK_045 Physical Verification:**
  - Float constant search in `.rodata` showed zero instances of the textbook matrix claimed in TASK_044.
  - Real methods disassembled:
    * `PVGColorFunctions::getDisplayP3ICCProfile` (0x20f70): Loads address `0xe11b`.
    * `PVGColorFunctions::getDisplayP3ICCProfileSize` (0x20f7c): Returns `0x218` (536 bytes).
  - Inspection of offset `0xe11b` in `.rodata`:
    * Header: `b'\x00\x00\x02\x18appl\x04\x00\x00\x00mntrRGB XYZ ...'`
    * Magic at offset 36: `b'acsp'` (Official Apple Display-P3 ICC Color Profile).
  - Real color transformations are executed via ICC profiles and GLSL fragment code `gGLESColorTransferFragData` (0x11170).
  - **Verdict:** **FABRICATED MATRIX RETRACTED**. Ground-truth proven to be embedded ICC color profiles.
