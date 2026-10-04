# 17 — UNRESOLVED FUNCTIONS & DYNAMIC TEST PLAN

### 1. Quantified Unresolved Elements
- **Truncated Section Headers:** Exactly 1 file (`libmfxkit.so`) has truncated section headers from vendor distribution. Analyzed successfully via in-memory `PT_LOAD` segments.
- **Obfuscated Asset Shaders:** Certain `.fs` files in `assets/ARKernel3Builtin` are XOR/AES encrypted at rest and decrypted at runtime inside `libarkernel3.so`.

### 2. Follow-Up Dynamic Analysis Protocol (Frida / LLDB)
- Hook `glShaderSource` in `libMTFilterKernel.so` and `libarkernel3.so` during live execution on Samsung Galaxy A50 to capture any dynamic runtime shader variations.
- Hook `RegisterNatives` dynamically via Frida to verify if any runtime-constructed tables exist beyond the 1,949 statically recovered entries.
