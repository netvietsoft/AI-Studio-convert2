# App Knowledge Profile: Future Self Aging (APP_06)

- **Package Name**: `com.future.self.face.aging.changer`
- **Version**: `1.0.9.6`
- **Vendor / Lineage**: Future Tech
- **Container Type**: APKS
- **Primary Container**: `Future Self Face Aging Changer_1.0.9.6_28082026.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 15 (4 Product-Meaningful, 11 Runtime Infra)
- **Observed Models on Disk**: 1
- **Observed Shaders / Color LUTs**: 0
- **Mean Maturity Score**: 30.0 / 100
- **UI Engine**: Java DEX + uCrop
- **Render Engine**: libucrop.so + libamg.so
- **AI Runtime**: Cloud Aging API + Local Facial Landmark Preprocessing
- **Focus Domains**: Face, Retouch, Filter

## Architectural Notes
Aging morphing executed via cloud service, local crop/alignment via uCrop.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
