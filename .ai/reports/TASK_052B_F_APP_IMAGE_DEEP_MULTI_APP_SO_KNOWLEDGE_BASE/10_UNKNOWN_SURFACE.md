# Quantified Unknown Surface & Technical Probe Plan

## 1. Identified Unknown Surfaces
1. **Dynamic JNI Binding via RegisterNatives:** Several commercial libraries (e.g. `libeffect.so`, `libxeno_native.so`) do not export JNI methods as public dynamic symbols, instead registering them dynamically in `JNI_OnLoad`. Full signature recovery requires dynamic memory hooks in Frida / QEMU.
2. **Proprietary Model Encodings:** Meitu's `.bin` models and ByteDance `.model` files incorporate proprietary header obfuscation and weight quantization.
3. **Cloud Server Offloading:** FaceApp and SnapEdit rely substantially on remote GPU clusters for high-compute generative tasks, rendering local binary reversing insufficient for complete neural weight extraction.

## 2. Technical Probe Plan
- **Probe A:** Runtime instrumentation of `env->RegisterNatives` to capture in-memory function pointers and JNI signatures.
- **Probe B:** Memory dump of decrypted neural weights during model initialization in ART sandbox.
