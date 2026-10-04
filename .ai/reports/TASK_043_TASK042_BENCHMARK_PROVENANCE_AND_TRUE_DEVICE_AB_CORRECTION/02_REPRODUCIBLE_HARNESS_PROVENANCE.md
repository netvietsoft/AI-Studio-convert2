# 02. REPRODUCIBLE HARNESS PROVENANCE & BUILD SPECIFICATION

**Harness Source**: `scratch/task043/harness/ab_benchmark_harness.cpp`  
**Target Hardware ABI**: `arm64-v8a` (Android API 30+)  
**Toolchain**: Android NDK 28.2.13676358 / Clang 19.0.1  

---

## 1. Toolchain & Compilation Provenance

| Parameter | Specification |
|---|---|
| Compiler Path | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\aarch64-linux-android30-clang++.cmd` |
| Compiler Version | Android Clang version 19.0.1 (based on r530567e, target `aarch64-unknown-linux-android30`) |
| Optimization Flags | `-O3 -std=c++17 -fopenmp -static-openmp -static-libstdc++` |
| Linker Mode | Fully static C++ runtime and OpenMP (zero external dynamic dependency on Android device) |
| Output Binary | `scratch/task043/harness/harness_ab_arm64` |
| Binary Size | 6,667,400 bytes |
| Binary SHA-256 | `6D23E4CF7889EF90427BD6E6C91681EE8B77B5D7F700EE3B11B4A7F39A0C09FF` |

### Exact Compilation Command Line:
```cmd
"C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\aarch64-linux-android30-clang++.cmd" ^
    -O3 -std=c++17 -fopenmp -static-openmp -static-libstdc++ ^
    scratch/task043/harness/ab_benchmark_harness.cpp ^
    -o scratch/task043/harness/harness_ab_arm64
```

---

## 2. Physical Device Execution Provenance

Both connected physical devices were verified and utilized:

### Device 1: Samsung Galaxy A07 (SM-A075F)
- **ADB Serial**: `192.168.1.18:40159`
- **SoC**: MediaTek Helio G99 (`mt6789`) Octa-Core
- **OS**: Android 16 (SDK 36, Platform `mt6789`)
- **ABI**: `arm64-v8a`
- **Execution Target Directory**: `/data/local/tmp/task043_ab/`
- **Execution Permission**: `chmod 777 /data/local/tmp/task043_ab/harness_ab_arm64`

### Device 2: Samsung Galaxy A50s (SM-A507FN)
- **ADB Serial**: `192.168.1.2:41775`
- **SoC**: Samsung Exynos 9611 (`universal9611`) Octa-Core
- **OS**: Android 11 (SDK 30, Platform `exynos9610`)
- **ABI**: `arm64-v8a`
- **Execution Target Directory**: `/data/local/tmp/task043_ab/`
- **Execution Permission**: `chmod 777 /data/local/tmp/task043_ab/harness_ab_arm64`

### Exact Device Command Template:
```bash
/data/local/tmp/task043_ab/harness_ab_arm64 \
    /data/local/tmp/task043_ab/inputs/<case_name>.rgb \
    /data/local/tmp/task043_ab/inputs/<case_name>.mask \
    <width> <height> <has_hair:0|1> \
    /data/local/tmp/task043_ab/outputs
```

---

## 3. Input Test Assets Provenance

All 8 canonical test portraits were ingested from `TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE` and exported to uncompressed binary buffers (`.rgb` and `.mask`):

| Portrait Case | Resolution | Raw RGB Bytes | Raw Mask Bytes | Original Source SHA-256 |
|---|---|---|---|---|
| `portrait_0_curly` | 960x1280 | 3,686,400 | 1,228,800 | `ba84225bcc3c5f2066d03f56eb72aa48d3db0c5a242c74d6c6e73c3eeab91bf4` |
| `portrait_1_male_wavy` | 576x1280 | 2,211,840 | 737,280 | `3281c617c3dc60d47348e3cfc9c762e8ea06ea64e1d1ebc343bc551d02c77d46` |
| `portrait_model1_blonde` | 800x1000 | 2,400,000 | 800,000 | `39a3ee45b4e692723791dbe2b2b2fa09930f305cbe0fbaf814f85e3c83401da9` |
| `portrait_model2_long_straight` | 800x1200 | 2,880,000 | 960,000 | `e7ecfe98f65246c33d659ad76891ebbf7bcfe8950d603a110255ec3e64883445` |
| `portrait_model3_wavy_curls` | 800x1200 | 2,880,000 | 960,000 | `7575f0c21905071477146522cbe23403a49281a8b9e6931758652d58fb0dca6a` |
| `portrait_model4_messy_curls` | 800x1200 | 2,880,000 | 960,000 | `44bae086710379ba921e4ea511c5fdfb2d6a7ef6134b22c00227187c2bf3f07a` |
| `portrait_model6_fringe_bangs` | 800x1200 | 2,880,000 | 960,000 | `4d691fd76c520bec0dff098cff06e3009bc8725838031d87e0b534b17f9b8c0c` |
| `portrait_monk_bald_neg` | 500x333 | 499,500 | 166,500 | `00ae77069c02c8834db7a5dfeb13c12aaecf342f15ffb9690184ce1baeb2d1f0` |
