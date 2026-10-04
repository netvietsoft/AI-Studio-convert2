# App Knowledge Profile: Wink (APP_14)

- **Package Name**: `com.meitu.wink`
- **Version**: `3.16.5`
- **Vendor / Lineage**: Meitu Inc
- **Container Type**: APKS
- **Primary Container**: `Wink_3.16.5.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 64 (53 Product-Meaningful, 11 Runtime Infra)
- **Observed Models on Disk**: 13
- **Observed Shaders / Color LUTs**: 594
- **Mean Maturity Score**: 64.1 / 100
- **UI Engine**: Java/Kotlin DEX + Meitu Video Engine
- **Render Engine**: libVERenderer.so + libmtmvcore.so + libarkernel3.so + libPVGColorFunctions.so
- **AI Runtime**: Manis NPU Engine + libaidetectionplugin.so + libAIModelKit.so
- **Focus Domains**: Hair, Face, Skin, Body, Reshape, Retouch, Color, Render, Video

## Architectural Notes
Meitu's advanced AI video & portrait retouch editor sharing core shaders and Manis models.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
