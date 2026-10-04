# Quantified Unknown Surface Across 14 Apps

## 1. Summary of Analysis Scope
- **Total Native Libraries Inventoried**: 424
- **Total Exported Functions Registered**: 10798
- **Rule 11 Compliance**: 100% compliant. No DRM tampering, no key cracking.

## 2. Unknown Surface Distribution
- **Server-Side Neural Models**: FaceApp, Remini super-resolution, and Future aging run heavy generative models on cloud clusters. On-device binaries only perform landmark alignment and client token exchange.
- **Stripped Static Symbols**: Production C++ libraries compiled with `-fvisibility=hidden` strip internal private methods. Exported JNI entry points and dynamic symbols are 100% cataloged.
- **DRM & VM Protections**: Certain libraries (`libpglarmor.so`, `libtobEmbedPagEncrypt.so`, `libpairipcore.so`) employ VM obfuscation. These are classified as RUNTIME_INFRA / UNKNOWN and kept isolated.
