# App Knowledge Profile: BeautyPlus (APP_02)

- **Package Name**: `com.commsource.beautyplus`
- **Version**: `7.46.0`
- **Vendor / Lineage**: Meitu Ecosystem / Pixocial
- **Container Type**: APKS
- **Primary Container**: `BeautyPlus_7.46.0.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 89 (73 Product-Meaningful, 16 Runtime Infra)
- **Observed Models on Disk**: 48
- **Observed Shaders / Color LUTs**: 739
- **Mean Maturity Score**: 64.5 / 100
- **UI Engine**: Java/Kotlin DEX + Meitu Native Core
- **Render Engine**: libMTFilterKernel.so + libVERenderer.so + libPixRenderCore.so
- **AI Runtime**: Manis NPU Adapter + libaidetectionplugin.so + libAIModelKit.so
- **Focus Domains**: Hair, Face, Skin, Body, Reshape, Retouch, Color, Render

## Architectural Notes
Direct sibling of Meitu sharing MTFilterKernel, Manis, ARKernel3, and PVGColorFunctions.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
