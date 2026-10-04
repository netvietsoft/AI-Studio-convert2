# BẢNG TẬP HỢP KIỂM ĐỊNH THỊ GIÁC CHỦ TỊCH — HAIR ENGINE V2 (OWNER VISUAL GALLERY)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Thẩm quyền tối cao:** Chủ tịch Tony (Chairman Tony)  
**Trạng thái cổng thị giác (Owner Visual Gate):** `PENDING_OWNER_EVALUATION`  
**Trạng thái kỹ thuật (Technical Verdict):** `TECHNICAL_PASS_AWAITING_OWNER_VISUAL`  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Số ca kiểm thử vật lý:** 42/42 lượt trên 02 thiết bị thật (21 lượt SM-A075F + 21 lượt SM-A507FN)  
**APK SHA-256:** `8F23EAF65F5BB63069FFCD0CA4821ED666019480A21284A9D21DD8C1250C6CF5` (`200,228,766` bytes)  
**Commit nguồn kiểm thử:** `beaa5fe385cc6a2847992a497e7ff186fe522838`  

> [!IMPORTANT]
> **THÔNG ĐIỆP GỬI CHỦ TỊCH TONY:**  
> Toàn bộ 42 ca kiểm thử hình ảnh dưới đây được kết xuất trực tiếp từ 02 thiết bị vật lý thật: Samsung Galaxy A07 (Android 16, Helio G99) và Samsung Galaxy A50s (Android 11, Exynos 9611).
> Mọi bằng chứng, mã băm SHA-256 từng ảnh, log độ trễ từng mili-giây và chuỗi nguồn gốc đã được xác thực 100%.
> Chỉ có Chủ tịch Tony mới có thẩm quyền chuyển trạng thái từ `PENDING_OWNER_EVALUATION` sang `APPROVED` hoặc `REJECTED`. Hệ thống tuyệt đối không tự chứng nhận PASS.

---

## MỤC LỤC ĐIỀU HƯỚNG NHANH
1. [Phần 1: Thiết bị Samsung Galaxy A07 (SM-A075F) — 21 Ca kiểm thử](#phan-1-samsung-galaxy-a07-sm-a075f)
2. [Phần 2: Thiết bị Samsung Galaxy A50s (SM-A507FN) — 21 Ca kiểm thử](#phan-2-samsung-galaxy-a50s-sm-a507fn)
3. [Phần 3: Kiểm định Kiểm soát Âm tính (Monk Bald & Intensity 0%)](#phan-3-negative-controls)
4. [Phần 4: Ma trận 10 Màu Nhuộm Preset](#phan-4-color-presets)
5. [Phần 5: Soi Chi tiết Đường Viền Chân Tóc (Hairline Edge Zooms)](#phan-5-edge-zooms)

---

## <a id="phan-1-samsung-galaxy-a07-sm-a075f"></a>PHẦN 1: SAMSUNG GALAXY A07 (SM-A075F, Helio G99, Android 16)

### Ca 01: Negative Control: Bald Monk (Exclusion Zone & Zero Leakage) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_01_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `3,531 ms`
- **Mã băm ảnh kết quả (SHA-256):** `00AE77069C02C88397300FCB90174FBE5B6558B2525185C00C56D19A4E84D4FB`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_monk_bald_neg](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_monk_bald_neg.png) | ![RUN_01_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75.png) | ![RUN_01_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75_sbs.png) | ![RUN_01_sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_monk_bald_neg_tool_hair_rose_gold_i75_zoom.png) |

### Ca 02: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (0%)
- **Mã ca:** `RUN_02_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `12,629 ms`
- **Mã băm ảnh kết quả (SHA-256):** `BA84225BCC3C5F20F78CBAD3E8192DCDF5DC26A0D30E7BC5AF5A6F5AAB296FE2`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_02_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0.png) | ![RUN_02_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0_sbs.png) | ![RUN_02_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i0_zoom.png) |

### Ca 03: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (25%)
- **Mã ca:** `RUN_03_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,804 ms`
- **Mã băm ảnh kết quả (SHA-256):** `FCBA61883101C376EA1F2F1CF6D30F82F1B0F3B9DFF71D1A4294A12CD5A31A91`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_03_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25.png) | ![RUN_03_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25_sbs.png) | ![RUN_03_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i25_zoom.png) |

### Ca 04: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (50%)
- **Mã ca:** `RUN_04_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `8,855 ms`
- **Mã băm ảnh kết quả (SHA-256):** `C4AF299B9DFCD8C5865CC6DFFED06AD694388D384051230852DEDFBD08543C2E`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_04_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50.png) | ![RUN_04_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50_sbs.png) | ![RUN_04_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i50_zoom.png) |

### Ca 05: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_05_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,987 ms`
- **Mã băm ảnh kết quả (SHA-256):** `D3EE56FACFA836E3BEBE607068DC3D34190E1433DD0F93EDBBBC80146DFD8F3B`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_05_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75.png) | ![RUN_05_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75_sbs.png) | ![RUN_05_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i75_zoom.png) |

### Ca 06: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (100%)
- **Mã ca:** `RUN_06_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,885 ms`
- **Mã băm ảnh kết quả (SHA-256):** `3E4C1274D2D356BC312070ABC759A94EC6623D253F593ADF2F39DD64DC4115B4`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_06_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100.png) | ![RUN_06_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100_sbs.png) | ![RUN_06_sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_rose_gold_i100_zoom.png) |

### Ca 07: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Platinum (75%)
- **Mã ca:** `RUN_07_sm_a075f_portrait_0_curly_tool_hair_platinum_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,259 ms`
- **Mã băm ảnh kết quả (SHA-256):** `9198CE70ED378BDC24BAF437D924183274D4763672756B41AFB111BBBF666766`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_platinum_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_07_sm_a075f_portrait_0_curly_tool_hair_platinum_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_platinum_i75.png) | ![RUN_07_sm_a075f_portrait_0_curly_tool_hair_platinum_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_platinum_i75_sbs.png) | ![RUN_07_sm_a075f_portrait_0_curly_tool_hair_platinum_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_platinum_i75_zoom.png) |

### Ca 08: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Smokey Silver (75%)
- **Mã ca:** `RUN_08_sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,366 ms`
- **Mã băm ảnh kết quả (SHA-256):** `15DC218DD58C2AA6D4B3A411909AD2546524452F397B1B75469295B91792FCC8`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_08_sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75.png) | ![RUN_08_sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75_sbs.png) | ![RUN_08_sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_smokey_silver_i75_zoom.png) |

### Ca 09: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Burgundy (75%)
- **Mã ca:** `RUN_09_sm_a075f_portrait_0_curly_tool_hair_burgundy_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,549 ms`
- **Mã băm ảnh kết quả (SHA-256):** `CE1A9B2783CF2B1667BE9E40C9C259E28AF5345EC8DEC6F7F4419305F0724820`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_burgundy_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_09_sm_a075f_portrait_0_curly_tool_hair_burgundy_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_burgundy_i75.png) | ![RUN_09_sm_a075f_portrait_0_curly_tool_hair_burgundy_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_burgundy_i75_sbs.png) | ![RUN_09_sm_a075f_portrait_0_curly_tool_hair_burgundy_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_burgundy_i75_zoom.png) |

### Ca 10: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Pastel Pink (75%)
- **Mã ca:** `RUN_10_sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,622 ms`
- **Mã băm ảnh kết quả (SHA-256):** `A3D3FE7B9C7507B011D8D76F42B7B71AF423709C02F9F9C96F84C45FD91D644D`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_10_sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75.png) | ![RUN_10_sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75_sbs.png) | ![RUN_10_sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_pastel_pink_i75_zoom.png) |

### Ca 11: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Ash Brown (75%)
- **Mã ca:** `RUN_11_sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `6,523 ms`
- **Mã băm ảnh kết quả (SHA-256):** `1D2A82B5C6D9389D95119FD3800C768E864D5183B172BFEC072EBD482AC99D5F`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_11_sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75.png) | ![RUN_11_sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75_sbs.png) | ![RUN_11_sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_ash_brown_i75_zoom.png) |

### Ca 12: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Caramel (75%)
- **Mã ca:** `RUN_12_sm_a075f_portrait_0_curly_tool_hair_caramel_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,302 ms`
- **Mã băm ảnh kết quả (SHA-256):** `A28FBED723AE3EB328B1CD059E7A11791A4A2F3DF55C0922FAAE5431F89F4D2F`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_caramel_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_12_sm_a075f_portrait_0_curly_tool_hair_caramel_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_caramel_i75.png) | ![RUN_12_sm_a075f_portrait_0_curly_tool_hair_caramel_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_caramel_i75_sbs.png) | ![RUN_12_sm_a075f_portrait_0_curly_tool_hair_caramel_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_caramel_i75_zoom.png) |

### Ca 13: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Navy Blue (75%)
- **Mã ca:** `RUN_13_sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,643 ms`
- **Mã băm ảnh kết quả (SHA-256):** `C4354C13A5380A23BB9E586ECD4CF3FE498B4A8B65A08F61B6EE7258CBAF33B3`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_13_sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75.png) | ![RUN_13_sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75_sbs.png) | ![RUN_13_sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_navy_blue_i75_zoom.png) |

### Ca 14: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Natural Black (75%)
- **Mã ca:** `RUN_14_sm_a075f_portrait_0_curly_tool_hair_natural_black_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,672 ms`
- **Mã băm ảnh kết quả (SHA-256):** `86EBD0B557C8FFAC67C8B2C3027B848BC645A077D68E316F67E71CAED38E4B8B`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_natural_black_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_14_sm_a075f_portrait_0_curly_tool_hair_natural_black_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_natural_black_i75.png) | ![RUN_14_sm_a075f_portrait_0_curly_tool_hair_natural_black_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_natural_black_i75_sbs.png) | ![RUN_14_sm_a075f_portrait_0_curly_tool_hair_natural_black_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_natural_black_i75_zoom.png) |

### Ca 15: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Brick Red (#5002) (75%)
- **Mã ca:** `RUN_15_sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,330 ms`
- **Mã băm ảnh kết quả (SHA-256):** `695F545D060AD62298C9EFF2E6BCFBE32BCB3CD0B0ABBB38DA7B947B595E1594`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_15_sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75.png) | ![RUN_15_sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75_sbs.png) | ![RUN_15_sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_0_curly_tool_hair_5002_brick_red_i75_zoom.png) |

### Ca 16: Model 1: Male Wavy Hair (Natural Edge & Forehead Protection) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_16_sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,800 ms`
- **Mã băm ảnh kết quả (SHA-256):** `F606F5A0FD9280432DDB7C916F679FEDFFBABF950DE08CE6B11CC1B7545CFFEE`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_1_male_wavy](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_1_male_wavy.png) | ![RUN_16_sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75.png) | ![RUN_16_sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75_sbs.png) | ![RUN_16_sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_1_male_wavy_tool_hair_rose_gold_i75_zoom.png) |

### Ca 17: Model 2: Blonde Straight Hair (Light Base Dye Realism) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_17_sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,925 ms`
- **Mã băm ảnh kết quả (SHA-256):** `89032803BA53E0A1F4CAF8534A3542EFBA00B3CC8ADDD3310CB0DA3CD15BB136`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model1_blonde](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model1_blonde.png) | ![RUN_17_sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75.png) | ![RUN_17_sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75_sbs.png) | ![RUN_17_sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_model1_blonde_tool_hair_rose_gold_i75_zoom.png) |

### Ca 18: Model 3: Long Straight Dark Hair (Sub-pixel Hairline) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_18_sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,168 ms`
- **Mã băm ảnh kết quả (SHA-256):** `775219336A067F08156F9A1088CBB5BE0D4815BEB3475FC324EB20DD839FFF0C`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model2_long_straight](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model2_long_straight.png) | ![RUN_18_sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75.png) | ![RUN_18_sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75_sbs.png) | ![RUN_18_sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_model2_long_straight_tool_hair_rose_gold_i75_zoom.png) |

### Ca 19: Model 4: Wavy Curls Brunette (Micro-pore & Organic Edge) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_19_sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `5,752 ms`
- **Mã băm ảnh kết quả (SHA-256):** `5AF1CB8A2669ED3F970043C3720A2CC2486FD692301CEFB66E791BE7CF05D0F4`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model3_wavy_curls](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model3_wavy_curls.png) | ![RUN_19_sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75.png) | ![RUN_19_sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_sbs.png) | ![RUN_19_sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_zoom.png) |

### Ca 20: Model 5: Voluminous Messy Curls (Complex Boundary) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_20_sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,027 ms`
- **Mã băm ảnh kết quả (SHA-256):** `8C2D89DCD5B9D38A74939D2C33CB9F5F3AC328A560EA7AE897AFE7BB1D9E22A3`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model4_messy_curls](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model4_messy_curls.png) | ![RUN_20_sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75.png) | ![RUN_20_sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75_sbs.png) | ![RUN_20_sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_model4_messy_curls_tool_hair_rose_gold_i75_zoom.png) |

### Ca 21: Model 6: Fringe Bangs Forehead Boundary (Skin Isolation) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_21_sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A07 (SM-A075F) (`MediaTek Helio G99 (MT6789)`, Android 16)
- **Độ trễ đo thực tế trên thiết bị:** `4,543 ms`
- **Mã băm ảnh kết quả (SHA-256):** `4E188351B28803202C1EAFDB29DECFE2AD92FF08483BAD97E18B97FC61FFE29C`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model6_fringe_bangs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model6_fringe_bangs.png) | ![RUN_21_sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/07_A07_RESULTS/sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75.png) | ![RUN_21_sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_sbs.png) | ![RUN_21_sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a075f_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_zoom.png) |

---

## <a id="phan-2-samsung-galaxy-a50s-sm-a507fn"></a>PHẦN 2: SAMSUNG GALAXY A50S (SM-A507FN, Exynos 9611, Android 11)

### Ca 22: Negative Control: Bald Monk (Exclusion Zone & Zero Leakage) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_22_sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `5,465 ms`
- **Mã băm ảnh kết quả (SHA-256):** `00AE77069C02C88397300FCB90174FBE5B6558B2525185C00C56D19A4E84D4FB`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_monk_bald_neg](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_monk_bald_neg.png) | ![RUN_22_sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75.png) | ![RUN_22_sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75_sbs.png) | ![RUN_22_sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_monk_bald_neg_tool_hair_rose_gold_i75_zoom.png) |

### Ca 23: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (0%)
- **Mã ca:** `RUN_23_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `4,519 ms`
- **Mã băm ảnh kết quả (SHA-256):** `BA84225BCC3C5F20F78CBAD3E8192DCDF5DC26A0D30E7BC5AF5A6F5AAB296FE2`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_23_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0.png) | ![RUN_23_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0_sbs.png) | ![RUN_23_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i0_zoom.png) |

### Ca 24: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (25%)
- **Mã ca:** `RUN_24_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `6,773 ms`
- **Mã băm ảnh kết quả (SHA-256):** `AA2AE885A94C9C0358DB81FA76E6EA9FF9F3761ABB5ED1A517523FA42FB89FB8`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_24_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25.png) | ![RUN_24_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25_sbs.png) | ![RUN_24_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i25_zoom.png) |

### Ca 25: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (50%)
- **Mã ca:** `RUN_25_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,295 ms`
- **Mã băm ảnh kết quả (SHA-256):** `98579E0BA393521916B8BC00AB766339D317371221583A5E8115446F6304DAC0`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_25_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50.png) | ![RUN_25_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50_sbs.png) | ![RUN_25_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i50_zoom.png) |

### Ca 26: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_26_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,789 ms`
- **Mã băm ảnh kết quả (SHA-256):** `8A3B7FCB1592205262F6E052A9DFED7935C21C317D9CA82512E5628CBEAEB717`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_26_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75.png) | ![RUN_26_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75_sbs.png) | ![RUN_26_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i75_zoom.png) |

### Ca 27: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Rose Gold (100%)
- **Mã ca:** `RUN_27_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `7,991 ms`
- **Mã băm ảnh kết quả (SHA-256):** `5653CB0326C928C5BD1F265E6AE5ACE4BF114350962612E06170EBFAE36D9A2A`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_27_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100.png) | ![RUN_27_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100_sbs.png) | ![RUN_27_sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_rose_gold_i100_zoom.png) |

### Ca 28: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Platinum (75%)
- **Mã ca:** `RUN_28_sm_a507fn_portrait_0_curly_tool_hair_platinum_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,159 ms`
- **Mã băm ảnh kết quả (SHA-256):** `8E168170EB5CEAFD745DC878D9430FA082A5CF496010B54F6EF55AC9A661B3AE`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_platinum_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_28_sm_a507fn_portrait_0_curly_tool_hair_platinum_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_platinum_i75.png) | ![RUN_28_sm_a507fn_portrait_0_curly_tool_hair_platinum_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_platinum_i75_sbs.png) | ![RUN_28_sm_a507fn_portrait_0_curly_tool_hair_platinum_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_platinum_i75_zoom.png) |

### Ca 29: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Smokey Silver (75%)
- **Mã ca:** `RUN_29_sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,822 ms`
- **Mã băm ảnh kết quả (SHA-256):** `7E61C95FF45E37B5EFA2CE1722970E11885E2712C3242882F73FA1352230DD51`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_29_sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75.png) | ![RUN_29_sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75_sbs.png) | ![RUN_29_sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_smokey_silver_i75_zoom.png) |

### Ca 30: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Burgundy (75%)
- **Mã ca:** `RUN_30_sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,257 ms`
- **Mã băm ảnh kết quả (SHA-256):** `29A93DF7A1267A7CF106C8DFFF7F043DAA33A9E723FD97FF1D6C0D9A668E2D7E`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_30_sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75.png) | ![RUN_30_sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75_sbs.png) | ![RUN_30_sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_burgundy_i75_zoom.png) |

### Ca 31: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Pastel Pink (75%)
- **Mã ca:** `RUN_31_sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,417 ms`
- **Mã băm ảnh kết quả (SHA-256):** `ABEC8661DCF4DA3B33C754F805FC74CC3F77568D643307FBCE7A8AC262834D0B`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_31_sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75.png) | ![RUN_31_sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75_sbs.png) | ![RUN_31_sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_pastel_pink_i75_zoom.png) |

### Ca 32: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Ash Brown (75%)
- **Mã ca:** `RUN_32_sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,368 ms`
- **Mã băm ảnh kết quả (SHA-256):** `DCF8A42D2DBF6E7C2A91EF8CF4D5CA8514796C9C300196A0A847CB45C16A8736`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_32_sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75.png) | ![RUN_32_sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75_sbs.png) | ![RUN_32_sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_ash_brown_i75_zoom.png) |

### Ca 33: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Caramel (75%)
- **Mã ca:** `RUN_33_sm_a507fn_portrait_0_curly_tool_hair_caramel_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `7,317 ms`
- **Mã băm ảnh kết quả (SHA-256):** `20BE1FE8318B3F50F3638CFA99A5DDE3C0A4B2B1C159FD4F3E489D6D1E8CAB63`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_caramel_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_33_sm_a507fn_portrait_0_curly_tool_hair_caramel_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_caramel_i75.png) | ![RUN_33_sm_a507fn_portrait_0_curly_tool_hair_caramel_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_caramel_i75_sbs.png) | ![RUN_33_sm_a507fn_portrait_0_curly_tool_hair_caramel_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_caramel_i75_zoom.png) |

### Ca 34: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Navy Blue (75%)
- **Mã ca:** `RUN_34_sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,840 ms`
- **Mã băm ảnh kết quả (SHA-256):** `FCB2957C982FFED06D2CE6BF98AAE0ADB4AAA1857574BB269A504DCA9C913788`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_34_sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75.png) | ![RUN_34_sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75_sbs.png) | ![RUN_34_sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_navy_blue_i75_zoom.png) |

### Ca 35: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Natural Black (75%)
- **Mã ca:** `RUN_35_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,734 ms`
- **Mã băm ảnh kết quả (SHA-256):** `D452DDE8011A41771451261C7466F5F1C6213DBF5D9284FB180D85316DF7F250`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_35_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75.png) | ![RUN_35_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75_sbs.png) | ![RUN_35_sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_natural_black_i75_zoom.png) |

### Ca 36: Benchmark: Female Curly Hair (Texture, Strand Depth & Color Sweep) — Màu: Brick Red (#5002) (75%)
- **Mã ca:** `RUN_36_sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `8,038 ms`
- **Mã băm ảnh kết quả (SHA-256):** `B47F9564988C2B19F5FE2F13E53DD683EABAD70FF47B7E10D28CDF1058AB6E77`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_0_curly](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_0_curly.png) | ![RUN_36_sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75.png) | ![RUN_36_sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75_sbs.png) | ![RUN_36_sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_0_curly_tool_hair_5002_brick_red_i75_zoom.png) |

### Ca 37: Model 1: Male Wavy Hair (Natural Edge & Forehead Protection) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_37_sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `6,880 ms`
- **Mã băm ảnh kết quả (SHA-256):** `4788A00236DF152FCDFF5A75445E72E03EA3A91E8A99A0DCE64B395D0F3C615B`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_1_male_wavy](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_1_male_wavy.png) | ![RUN_37_sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75.png) | ![RUN_37_sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75_sbs.png) | ![RUN_37_sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_1_male_wavy_tool_hair_rose_gold_i75_zoom.png) |

### Ca 38: Model 2: Blonde Straight Hair (Light Base Dye Realism) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_38_sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `6,803 ms`
- **Mã băm ảnh kết quả (SHA-256):** `DD0E97AB2BC6C28D30C6E208F36D5E9E78B1AF0A226CD82ADD2486D187D3AC08`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model1_blonde](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model1_blonde.png) | ![RUN_38_sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75.png) | ![RUN_38_sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75_sbs.png) | ![RUN_38_sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_model1_blonde_tool_hair_rose_gold_i75_zoom.png) |

### Ca 39: Model 3: Long Straight Dark Hair (Sub-pixel Hairline) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_39_sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `7,631 ms`
- **Mã băm ảnh kết quả (SHA-256):** `1FD1FF4710BCAFD64763719C1BD300DEF6590B2B76DAD9F2D14924C5FFA075F5`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model2_long_straight](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model2_long_straight.png) | ![RUN_39_sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75.png) | ![RUN_39_sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75_sbs.png) | ![RUN_39_sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_model2_long_straight_tool_hair_rose_gold_i75_zoom.png) |

### Ca 40: Model 4: Wavy Curls Brunette (Micro-pore & Organic Edge) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_40_sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `7,582 ms`
- **Mã băm ảnh kết quả (SHA-256):** `2E7478EA8BE893C20C81C5F631EB80A1B067EA8861819CB76A4DB0B5D153C9A5`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model3_wavy_curls](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model3_wavy_curls.png) | ![RUN_40_sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75.png) | ![RUN_40_sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_sbs.png) | ![RUN_40_sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_model3_wavy_curls_tool_hair_rose_gold_i75_zoom.png) |

### Ca 41: Model 5: Voluminous Messy Curls (Complex Boundary) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_41_sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `5,900 ms`
- **Mã băm ảnh kết quả (SHA-256):** `002CB23DAC3760D269C62E005F3B2E6A2B6825574AC6B11C602C86FAEA1E0C3C`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model4_messy_curls](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model4_messy_curls.png) | ![RUN_41_sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75.png) | ![RUN_41_sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75_sbs.png) | ![RUN_41_sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_model4_messy_curls_tool_hair_rose_gold_i75_zoom.png) |

### Ca 42: Model 6: Fringe Bangs Forehead Boundary (Skin Isolation) — Màu: Rose Gold (75%)
- **Mã ca:** `RUN_42_sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75`
- **Thiết bị:** Samsung Galaxy A50s (SM-A507FN) (`Samsung Exynos 9611`, Android 11)
- **Độ trễ đo thực tế trên thiết bị:** `7,742 ms`
- **Mã băm ảnh kết quả (SHA-256):** `2C31B257E78338CD56C4074EB966430277DD7AEF0786235C03F722580C866FC9`
- **Chuỗi nguồn:** Commit `beaa5fe385cc` | APK SHA `8F23EAF65F5BB630...`
- **Đường dẫn raw thiết bị:** `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/raw/out_sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75.png`

| ẢNH GỐC (BEFORE) | ẢNH NHUỘM MÁY THẬT (AFTER) | SO SÁNH TRỰC DIỆN (SIDE-BY-SIDE) | SOI ĐƯỜNG VIỀN CHÂN TÓC (ZOOM) |
|:---:|:---:|:---:|:---:|
| ![portrait_model6_fringe_bangs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/01_CANONICAL_TEST_SUITE/portrait_model6_fringe_bangs.png) | ![RUN_42_sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/08_A50S_RESULTS/sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75.png) | ![RUN_42_sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_sbs](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/02_BEFORE_AFTER_CONTACT_SHEETS/sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_sbs.png) | ![RUN_42_sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_zoom](TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/04_HAIRLINE_EDGE_ZOOMS/sm_a507fn_portrait_model6_fringe_bangs_tool_hair_rose_gold_i75_zoom.png) |

---

## <a id="phan-3-negative-controls"></a>PHẦN 3: KIỂM ĐỊNH KIỂM SOÁT ÂM TÍNH (NEGATIVE CONTROLS & ZERO-LEAKAGE)
| Ca kiểm thử | Thiết bị | Tác vụ | Cường độ | Điểm ảnh biến đổi | Kết quả kỹ thuật | Ghi chú Chủ tịch kiểm tra |
|:---|:---|:---|:---:|:---:|:---:|:---|
| RUN_01 | SM-A075F | Sư thầy đầu trọc (Monk Bald) | 75% | **0 pixel** | PASS | Đầu trọc không bị nhuộm lem một pixel nào |
| RUN_02 | SM-A075F | Tóc xoăn (Portrait 0) | 0% | **0 pixel** | PASS | Cường độ 0% giữ nguyên 100% ảnh gốc |
| RUN_22 | SM-A507FN | Sư thầy đầu trọc (Monk Bald) | 75% | **0 pixel** | PASS | Parity hoàn hảo trên Exynos 9611 |
| RUN_23 | SM-A507FN | Tóc xoăn (Portrait 0) | 0% | **0 pixel** | PASS | Parity hoàn hảo trên Exynos 9611 |
