# App Knowledge Profile: Time Warp Scan (APP_11)

- **Package Name**: `com.timewarpscan.facescan`
- **Version**: `3.8.1`
- **Vendor / Lineage**: TimeWarp Apps
- **Container Type**: APKS
- **Primary Container**: `Time Warp Scan - Face Scan_3.8.1.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 23 (9 Product-Meaningful, 14 Runtime Infra)
- **Observed Models on Disk**: 1
- **Observed Shaders / Color LUTs**: 1
- **Mean Maturity Score**: 38.3 / 100
- **UI Engine**: Flutter Engine (libflutter.so + libapp.so)
- **Render Engine**: libhscore.so + libcvalgo.so + OpenGL ES
- **AI Runtime**: Alibaba MNN (libMNN.so) + libfacelandmarks.so
- **Focus Domains**: Face, Camera, Render

## Architectural Notes
Slit-scan camera deformation with MNN facial landmark tracking.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
