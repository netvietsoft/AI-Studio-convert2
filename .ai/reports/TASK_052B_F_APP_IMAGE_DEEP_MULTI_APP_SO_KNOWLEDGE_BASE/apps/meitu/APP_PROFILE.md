# App Knowledge Profile: Meitu (APP_05)

- **Package Name**: `com.mt.mtxx.mtxx`
- **Version**: `12.17.8`
- **Vendor / Lineage**: Meitu Inc
- **Container Type**: XAPK_DECOMPILED
- **Primary Container**: `Meitu_12.17.8_APKPure.xapk`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 45 (40 Product-Meaningful, 5 Runtime Infra)
- **Observed Models on Disk**: 0
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 69.7 / 100
- **UI Engine**: Java/Kotlin DEX + Meitu Native Core
- **Render Engine**: libMTFilterKernel.so (5-pass LIC) + libVERenderer.so + libLayerFlow.so
- **AI Runtime**: Manis NCNN/MNN Engine + BiSeNet 19-class + AIModelKit
- **Focus Domains**: Hair, Face, Skin, Body, Reshape, Retouch, Color, Segmentation, Matting, Render, Video

## Architectural Notes
Primary reference engine for CONVERT2; tau_aspect=1.80, 5-pass soft hair FBO, Display-P3 color.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
