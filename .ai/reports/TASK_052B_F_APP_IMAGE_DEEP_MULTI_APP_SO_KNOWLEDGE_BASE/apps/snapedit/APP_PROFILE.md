# App Knowledge Profile: SnapEdit (APP_10)

- **Package Name**: `snapedit.app.remove`
- **Version**: `7.7.7`
- **Vendor / Lineage**: SnapEdit Team
- **Container Type**: XAPK_DECOMPILED
- **Primary Container**: `xapk_extracted`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 23 (14 Product-Meaningful, 9 Runtime Infra)
- **Observed Models on Disk**: 0
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 52.2 / 100
- **UI Engine**: Java/Kotlin DEX + FFmpeg Media Pipeline
- **Render Engine**: libavcodec.so + libavfilter.so + libavformat.so + libswscale.so
- **AI Runtime**: MediaPipe SelfieSegmentation FP16 + MobileNetV2 Text Detector
- **Focus Domains**: Inpaint, Segmentation, Video, Render

## Architectural Notes
Object removal uses client-side mask delineation + cloud LaMa inpainting service.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
