# TASK_038 — HAIR PARAMETER AND DATA FLOW SPECIFICATION

| Parameter | Range | Default | Type | Vendor Native Mapping |
|---|---|---|---|---|
| `intensity` | `0.0 - 1.0` | `0.80` | `float` | `nSetDyeHairRenderAlpha` / `nSetAlpha` |
| `shine / gloss` | `0.0 - 1.0` | `0.40` | `float` | `MakeupHairSoftPart::setGloss` |
| `hairMask` | `uint8_t[W*H]` | `None` | `ByteBuffer` | `nativeSetFaceHairMask` |
| `colorSpace` | `sRGB / P3` | `sRGB` | `int` | `PVGColorFunctions::transcode` |
