# App Knowledge Profile: Remini (APP_09)

- **Package Name**: `com.bigwinepot.nwdn.international`
- **Version**: `3.7.1447`
- **Vendor / Lineage**: Bending Spoons / Big Winepot
- **Container Type**: APKS_DECOMPILED
- **Primary Container**: `Remini_3.7.1447.202524746.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 14 (4 Product-Meaningful, 10 Runtime Infra)
- **Observed Models on Disk**: 0
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 32.9 / 100
- **UI Engine**: Java/Kotlin DEX + V8 Javet Runtime
- **Render Engine**: libjavet-v8-android.so + libbuffer.so
- **AI Runtime**: Microsoft ONNX Runtime (libonnxruntime.so) + Cloud Super-Resolution
- **Focus Domains**: Texture, Face, Skin, Retouch

## Architectural Notes
Uses ONNX Runtime mobile for local inference; heavy facial restoration runs on cloud clusters.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
