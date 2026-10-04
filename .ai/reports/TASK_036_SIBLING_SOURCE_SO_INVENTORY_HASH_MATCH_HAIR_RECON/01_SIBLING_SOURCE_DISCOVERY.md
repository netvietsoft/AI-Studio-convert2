# 01 — SIBLING SOURCE DISCOVERY & RECONCILIATION REPORT

## 1. Physical Filesystem Discovery & Path Resolution

During autonomous dispatch for `TASK_036_SIBLING_SOURCE_45_SO_INVENTORY_HASH_MATCH_HAIR_ALGORITHM_RECON_ACTIVE`, the task prompt directed the agent to locate a sibling directory referred to by the user as `"soure"` or `"source"`.

### Path Analysis Across Environments

1. **Local Physical Workstation Origin (`F:\` drive):**
   - Development Root: `F:\CONVERT\com.mt.mtxx.mtxx`
   - Original Workspace: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2`
   - Sibling Directory: `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`
   - Relative Directory Path from workspace: `../SOURCE` (matching user's case-insensitive reference `"soure"` / `"source"`)

2. **Actions CI Runner Execution Environment (`C:\` drive):**
   - Active Git Clone: `C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2`
   - Physical Runner Node: `CONVERT2-WINDOWS-02` (Self-hosted on physical machine with attached `F:\` drive)
   - Discovered Native Library Source Path:
     `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE\extracted_native_libs\lib\arm64-v8a`

3. **Read-Only Access Verification:**
   - In accordance with HIẾN PHÁP VẬN HÀNH CONVERT and the task authorization specification, the sibling folder was accessed strictly with read-only semantics.
   - Zero files were created, moved, patched, or deleted within `F:\CONVERT\com.mt.mtxx.mtxx\SOURCE`.
   - File modification timestamps on all sibling `.so` files remain intact at `2026-09-06 11:12:00`.

---

## 2. Explicit Reconciliation of the 45-vs-46 Library Count

The Chairman's task brief stated:
> *"The user reports roughly 45 .so files in the sibling source folder. Reconcile the 45-vs-46 discrepancy explicitly."*

Our forensic comparison across the physical filesystem and Git repository revealed the exact cause of this discrepancy:

| Metric | Sibling Source (`F:\...`) | GitHub Repository (`lib-core-graphics/...`) | Variance |
|---|---|---|---|
| **Total .so File Count** | **45** | **46** | **+1 in GitHub** |
| **Vendor Binaries (from Meitu APK)** | 45 | 45 | 0 (Identical) |
| **Architecture / ABI** | `arm64-v8a` (ELF64 / AArch64) | `arm64-v8a` (ELF64 / AArch64) | Identical |
| **Exact Hash Matches (SHA-256)** | 45 / 45 (100.0%) | 45 / 46 (97.8%) | N/A |
| **Hash Mismatches** | 0 | 0 | 0 |
| **Source-Only Libraries** | 0 | 0 | 0 |
| **GitHub-Only Libraries** | 0 | **1 (`libomp.so`)** | +1 |

### Explanation of `libomp.so`
- **File Name:** `libomp.so`
- **File Size:** 1,205,616 bytes
- **SHA-256:** `6D1C680BF28C6E25DC605C915EBEB2BAFC7E835DEE000078DB9CEBC261C7F620`
- **SONAME:** `libomp.so`
- **Build ID:** `18dc60b457e4eefb`
- **Origin & Purpose:**
  - Added by engineer Thuy in commit [`d971feaf8f2fcc208298912e749711a31e180550`](https://github.com/netvietsoft/AI-Studio-convert2/commit/d971feaf8f2fcc208298912e749711a31e180550) on `2026-10-02 10:54:45 +07:00`.
  - Added as part of Phase P6: *Multi-core CPU OpenMP reference & GPU compute architecture*.
  - `libomp.so` is the standard LLVM OpenMP runtime library bundled to support `#pragma omp parallel for` multi-threading in `hair_pipeline_v2.cpp` for structure tensor calculation, box filtering, and OKLab color mapping.
  - It is **not** an original vendor library from the Meitu APK; rather, it is a runtime dependency for the reconstructed native engine.
- **Conclusion:** The original vendor distribution contains exactly **45** native libraries. The repository contains **46** libraries because **1** OpenMP runtime dependency was added during engine development.

---

## 3. Discovered Sibling Binary Inventory (45 Files)

| # | Binary Name | Size (Bytes) | SHA-256 Checksum |
|---|---|---|---|
| 1 | `libAIModelKit.so` | 280,608 | `96EB16089DA9B1B797928A73EC4B4DDD27C43BC557940C96CA167CF657A89B9C` |
| 2 | `libAIModelSearchKit.so` | 1,027,728 | `20233F05B4B010280D16E728103A0995CA2580697B5F9C708FA333E9FF8D1899` |
| 3 | `libARKernelInterface.so` | 17,829,224 | `594C5085475D8BB58BAACB20293AEC805211AA5CCC53B3542F3149196D354953` |
| 4 | `libARSPM.so` | 5,298,024 | `EC420F2EEC97CF2DEBBF4778045CFD0AC08B78EAE656A4F90E282D49B3EF0114` |
| 5 | `libCtaApiLib.so` | 494,080 | `4A91CCAC45408DAA30E8DD60F7C6EEE68AEFFBDD66E1E9B6E435B1AA3377FCD5` |
| 6 | `libKKMusicFX.so` | 519,504 | `CD876A2E49A129B1BCEFDC4ACA42047FAA4AAF954C6C1286EDB80209AC38031D` |
| 7 | `libLayerFlow.so` | 5,544,776 | `EF8D1581038778B72ABCA3CA8FD5046E49FD44E0465871B023647FE42A582262` |
| 8 | `libMTARMPM.so` | 99,704 | `A8CC628D8542EF953BCBEA36252DF569FF03EFCEA40C3E99A01A5D01489965B4` |
| 9 | `libMTFilterKernel.so` | 1,858,440 | `F938FE73095FCEBA72875D1AB42F8AEB6A9F31F3933831BEC070404C0E7ECAC4` |
| 10 | `libMTGif.so` | 83,560 | `04FF001EFD608381180DF00B53FA37C2F6CEBA93262D9A3B5EEAEFBDFE479017` |
| 11 | `libMTLReportTool.so` | 73,224 | `BA2002CC7A9F55BCF7BE73E0C6A0BC8C6FEFDE25A9371B9EE91C635DCDE52A4A` |
| 12 | `libManis.so` | 9,928,576 | `BC1F69C95453F77640698BF709971D50DF0BDDCBDC574F2FDBEF12C2087524EA` |
| 13 | `libMtlabSign.so` | 22,016 | `E7D6BE53DCC29CDA328C69FAED33036FBF8B2943324C3DCE5BD7677DA878C8AE` |
| 14 | `libPVGCodec.so` | 1,283,760 | `F39F0257F538E53A7CF80E53B0BA724128D3F985EB72B62FE426E861E63C4CD9` |
| 15 | `libPVGColorFunctions.so` | 380,224 | `BC2247BE017B3C45FF52A3C72A0D10D08A46123BFBBA9F5320F3EB44249CEF33` |
| 16 | `libPVGImageCodec.so` | 5,133,080 | `606709EBEEFA26760B95FEEC2B72352F773A8A366CCCE30B9DB0643A25265691` |
| 17 | `libPVGLive.so` | 603,200 | `23BAFF6788575EFA3F4B3C683DA4C37936E7DA71CFFC7844059A3029F39A5D6B` |
| 18 | `libPVGVideoCodec.so` | 1,150,016 | `869AE06612739FBFDF96B85E898495ECFB877C18413626C15E39BC72506B65BC` |
| 19 | `libVERenderer.so` | 429,728 | `9E1A334EE3A2518FCE0A6E3B95B11C54C115A5EDD8BDE4F455A1BE0EB4A7FE97` |
| 20 | `libaicodec.so` | 2,107,800 | `E1CD2DE6A64B2961BEB27871C80AE492BCBC3084C9ED36C701B4D2F2843EC5FA` |
| 21 | `libaidetectionplugin.so` | 531,680 | `482645BF38779FA1CA126A20412353EAA109F2BAF09BEBE1D1C34A2929007DA0` |
| 22 | `libarkernel3.so` | 17,786,488 | `C2B3F0D11C0B0C42BC8045F1DE1B45464F2BB959325D54C254DCFF27F70F04D6` |
| 23 | `libarkernel3_android.so` | 693,576 | `C9D8BCDF69986345C512A45FE1246CE45E94EB1C6FA1035B91BD89A4B889BA14` |
| 24 | `libarkernel3_c.so` | 501,664 | `E1430030E40A5DE873200D8EB9962534F6A220F6E6C51EC1F4D3C402BE437293` |
| 25 | `libbmpKit.so` | 486,360 | `F3950FA2298F2CE69480DF4CEEBC08092B0D5501B6CE1BD7BCE8488E021FE207` |
| 26 | `libbuffer_pgl.so` | 9,000 | `2D6A5DFF518F122B32047E7A315C6B751296DFE8160B3F11F1D06CD68B14BD6A` |
| 27 | `libbytehook.so` | 59,080 | `D5B110486DBC5D8FE797CC5B26E6E60DA1F96515A2E9A4B80E09673413BCE056` |
| 28 | `libc++_shared.so` | 1,292,904 | `7A8E6627C174127027582D3D0BD453E879E339C933BCECDA8CD51B63814B2C3A` |
| 29 | `libdexvmp.so` | 516,600 | `47DA26B9D6E14B6F77685D23055DC2801D387DE97BA75510659C9988D41C4977` |
| 30 | `libfantasy.so` | 2,623,024 | `18A6A4CAED034BCDEBE481B26E05DE7E9DC7969DF676C3AE85A9A7453B02C485` |
| 31 | `libffavc.so` | 1,161,456 | `6645391EE3E78229F6CFBD5184B4FAEB77DC9B8F421C0AE73AF920C82806283C` |
| 32 | `libffmpeg.so` | 7,546,632 | `96FE6108BF0568AFDE0D2F3AF517A7163B8B9B11DFE4FA35AE456B738A562B2B` |
| 33 | `libffmpegfilter.so` | 267,600 | `A8C4092E47702EE48E21BFD16E985FA47721A0A02BC39BF461FA9A4036FE967C` |
| 34 | `libfftw3.so` | 502,784 | `A7D2C0CD431238BCB55DB235D96521A1AC5640BD3FAEDDC0BF8CD4AC3ED8C913` |
| 35 | `libfile_lock_pgl.so` | 6,312 | `320601B2E3F976BD543BDE23EEBF4A9B0B76F5E3737E90B091FA47C3BD9E2184` |
| 36 | `libfntvcrash.so` | 57,592 | `83DE92F019864FE084E6CF3C6BAE2C44B1DA9091871CD5C671DC7FF6428CD434` |
| 37 | `libglide-webp.so` | 412,080 | `3A4A31C2D43FF5BF97CE590A2EBC13D9C96E0A6F42D52DB419E77F67873D5430` |
| 38 | `libhiai.so` | 446,504 | `F42A7C31DF076E4B65B540306E5D7B1C88E3E04FF4B5ECF91E1DB8BDE71DB5C8` |
| 39 | `libhiai_ir.so` | 868,936 | `B1E03DFF99BF76C8DE1324BF29E0B6E2C790D8F6AE4983BF6C5FBC45543D6343` |
| 40 | `libhiai_ir_build.so` | 27,120 | `73305BE33036E0FD213F7FEFECE0C895C953DB00B70D6E266498F5353DE8229E` |
| 41 | `libhttpelf.so` | 51,272 | `6FE694E0349CD0374C04AE52D92DC65D7B3224B2EB72CD630E53B026BE72E8E6` |
| 42 | `libkoom-strip-dump.so` | 576,288 | `B86C45F4D3C5FECC7852B81F26CCDA0C42EC12B3B30623A8C74D01DC566FF0D8` |
| 43 | `liblabdeviceinfo.so` | 126,312 | `CD1D0FA8D094FD0E11AC4053B552F2494E3EE2C5E78ED07BFA5B6B837AF15BC6` |
| 44 | `libmanis_npu_adapter.so` | 1,022,088 | `A7F2A2875DFD0851DB4A92FF86280E1C936E7AE5B826279E22A093CC489069F9` |
| 45 | `libmfxkit.so` | 773,652 | `3BCAC92AE6E3A3C94E0BC95C9A986877BEB7882209F21B7CFD4B6DFE0EFE4523` |
