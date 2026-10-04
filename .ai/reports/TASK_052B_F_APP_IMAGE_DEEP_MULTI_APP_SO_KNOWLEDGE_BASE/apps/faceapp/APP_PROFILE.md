# App Knowledge Profile: FaceApp (APP_07)

- **Package Name**: `io.faceapp`
- **Version**: `12.9.6`
- **Vendor / Lineage**: FaceApp Inc
- **Container Type**: APK
- **Primary Container**: `FaceApp+Perfect+Face+Editor_12.9.6_APKPure.apk`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 0 (0 Product-Meaningful, 0 Runtime Infra)
- **Observed Models on Disk**: 13
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 0.0 / 100
- **UI Engine**: Java/Smali DEX + Android View Hierarchy
- **Render Engine**: OpenGL ES FBO Blending + Android Canvas
- **AI Runtime**: FaceSSD Local Landmark Tracker + Server Neural Generative Pipeline
- **Focus Domains**: Hair, Face, Skin, Relight, Segmentation

## Architectural Notes
Heavy hair recoloring/aging is cloud-based; local assets contain 13 real models (FSSD, gender.tflite).

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
