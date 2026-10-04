# App Knowledge Profile: Facetune (APP_04)

- **Package Name**: `com.lightricks.facetune.free`
- **Version**: `2.60.0.1`
- **Vendor / Lineage**: Lightricks Ltd
- **Container Type**: XAPK
- **Primary Container**: `Facetune+Hair,+Photo+Editor_2.60.0.1-free_APKPure.xapk`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 19 (12 Product-Meaningful, 7 Runtime Infra)
- **Observed Models on Disk**: 10
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 55.8 / 100
- **UI Engine**: Java/Kotlin DEX + C++ Lightricks Core
- **Render Engine**: libfacetune.so + librender.so + libfs-native.so
- **AI Runtime**: TensorFlow Lite + MediaPipe SelfieSegmentation FP16 + FaceSSD
- **Focus Domains**: Hair, Face, Skin, Reshape, Retouch, Segmentation, Render

## Architectural Notes
Lightricks projective liquify mesh warp w(r)=(1-(r/R)^2)^3, dual-pass skin frequency separation.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
