# App Knowledge Profile: Adobe Lightroom Mobile (APP_03)

- **Package Name**: `com.adobe.lrmobile`
- **Version**: `9.4.2`
- **Vendor / Lineage**: Adobe Inc / Uptodown Stub
- **Container Type**: APK_WRAPPER
- **Primary Container**: `uptodown-com.adobe.lrmobile.apk`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 4 (0 Product-Meaningful, 4 Runtime Infra)
- **Observed Models on Disk**: 1
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 15.0 / 100
- **UI Engine**: Java/Kotlin DEX + Uptodown Stub
- **Render Engine**: libuptodown-native.so + libutd-services-native.so (Container Stub)
- **AI Runtime**: Cloud ACR Backend (On-device native ACR core packaged in separate split)
- **Focus Domains**: Color, Render, Camera

## Architectural Notes
Container APK is Uptodown installer shell; core ACR binary is server-offloaded or in dynamic splits.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
