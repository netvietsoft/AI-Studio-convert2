# App Knowledge Profile: PicsArt (APP_08)

- **Package Name**: `com.picsart.studio`
- **Version**: `30.7.8`
- **Vendor / Lineage**: PicsArt Inc
- **Container Type**: APKS
- **Primary Container**: `Picsart_30.7.8.apks`
- **Target Architecture**: arm64-v8a (primary)
- **Total Native SOs**: 17 (11 Product-Meaningful, 6 Runtime Infra)
- **Observed Models on Disk**: 1
- **Observed Shaders / Color LUTs**: 23
- **Mean Maturity Score**: 55.3 / 100
- **UI Engine**: Java/Kotlin DEX + PicsArt Native GE
- **Render Engine**: libgecore.so + libsmudgetool.so + libbucketfill.so + libnative-filters.so
- **AI Runtime**: PicsArt AI Pipeline + Fresco Native Image Pipeline
- **Focus Domains**: Retouch, Filter, Inpaint, Render

## Architectural Notes
Proprietary brush smudge engine, flood fill, and native filter kernels.

## Governance & Evidence Standard
- Verified against physical disk contents in `F:\App\Image`.
- No synthetic model or function names. Disavows unverified TASK_046 claims.
- Clean-room preservation: zero DRM/credential circumvention.
