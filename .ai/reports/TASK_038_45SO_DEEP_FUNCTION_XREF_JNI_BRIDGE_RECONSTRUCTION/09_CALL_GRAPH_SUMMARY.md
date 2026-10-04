# TASK_038 — Call Graph Summary & Hub Analysis

## 1. Global Call Graph Metrics
- **Total Executable Functions Discovered:** 33,388
- **Total Direct Call Edges Extracted:** 142,850
- **Total String References Recovered:** 68,412
- **Mean Call Depth from JNI Entry:** 4.8 hops
- **Max Call Depth (LayerFlow graph traversal):** 16 hops

---

## 2. Top Hub Functions (Most Called Internals)

| Library | Function RVA | Function Name / Mangled Symbol | Caller Count | Semantic Role |
|---|---|---|---|---|
| `libMTFilterKernel.so` | `0x001b4270` | `__android_log_print` (PLT) | 482 | Native telemetry and debugging |
| `libMTFilterKernel.so` | `0x001347ac` | `CMTFilterSoftHair::CreateFBO` | 4 | Intermediate render target allocation |
| `libMTFilterKernel.so` | `0x0013488c` | `CMTFilterSoftHair::GrayFilterToFBO` | 1 | Luminance pass caller |
| `libMTFilterKernel.so` | `0x00134970` | `CMTFilterSoftHair::HairMaskFilterToFBO` | 1 | Mask tensor binding caller |
| `libMTFilterKernel.so` | `0x00134a90` | `CMTFilterSoftHair::BlurHFilterToFBO` | 1 | Horizontal blur caller |
| `libMTFilterKernel.so` | `0x00134c10` | `CMTFilterSoftHair::BlurVFilterToFBO` | 1 | Vertical blur caller |
| `libMTFilterKernel.so` | `0x00134d90` | `CMTFilterSoftHair::SoftHairFilterToFBO` | 1 | Directional anisotropic blend caller |
| `libarkernel3.so` | `0x0056b70c` | `DataRequire::requireHairMask` | 18 | Mask requirement flag query |
| `libarkernel3.so` | `0x0056b718` | `DataRequire::requireHairMaskAdditionCPU` | 12 | CPU mask buffer requirement |
| `libarkernel3.so` | `0x0056b724` | `DataRequire::requireHairMaskAdditionGPU` | 14 | GPU texture mask requirement |
| `libPVGColorFunctions.so`| `0x0002b284` | `PVGCOLOR::convertToLab` | 19 | CIE-Lab color conversion |
| `libPVGColorFunctions.so`| `0x00020f70` | `PVGColorFunctions::getDisplayP3ICCProfile` | 8 | Wide gamut color profile retrieval |
| `libLayerFlow.so` | `0x002cb780` | `LFEffectDenseHairDataJNI::nSetInfo` | 1 | Dense hair parameter unpack |

---

## 3. Dynamic Dispatch & Indirect Calling Conventions

1. **`blr x8` Indirect Dispatch:**
   - Heavily utilized for JNI interface dispatch (`env->GetEnv`, `env->FindClass`, `env->RegisterNatives`).
   - C++ virtual method calls (`vtable[N]`).
   - In `CMTFilterSoftHair::FilterToFBO`, all 5 filter passes are invoked via direct static branch `bl #RVA`, proving that the pass order is hardcoded and deterministic, not dynamically overridden.