# TỔNG HỢP TOÀN BỘ CÂY PHÂN CẤP CHỨC NĂNG HỆ THỐNG MEITU REBORN (CHUẨN 100%)
> **Cổng dịch vụ Admin CMS:** `http://127.0.0.1:9999/`  
> **Tổng số chức năng kiểm soát:** **296 Chức Năng Chi Tiết** (138 VIP • 158 Free)  
> **Tổng số thư viện C++ JNI:** **45 File `.so` ARM64-v8a (100% Khớp)**  
> **Trạng thái đối soát:** Đạt chuẩn Design-Gated Workspace Standard v2.1  
> **Thời gian cập nhật:** 2026-09-24  

---

## 1. BẢNG TỔNG QUAN CÁC MODULE VÀ URL TRUY CẬP TRỰC TIẾP

| STT | Tên Module Cốt Lõi | URL Trực Tiếp Trên CMS | Số Chức Năng | Phân Hạng VIP / Free | Thư Viện C++ (.so) Đảm Nhiệm |
|:---:|---|---|:---:|:---:|---|
| **01** | **Chỉnh Sửa Ảnh Toàn Năng** | [`/admin/Editphoto`](http://127.0.0.1:9999/admin/Editphoto) | **158** | 62 VIP • 96 Free | `libarkernel3.so`, `libLayerFlow.so`, `libMTFilterKernel.so` |
| **02** | **Biên Tập Video Đa Track** | [`/admin/Videoedit`](http://127.0.0.1:9999/admin/Videoedit) | **48** | 22 VIP • 26 Free | `libffmpeg.so`, `libffavc.so`, `libVERenderer.so`, `libmfxkit.so` |
| **03** | **Camera AR & Làm Đẹp Live** | [`/admin/Camera`](http://127.0.0.1:9999/admin/Camera) | **36** | 16 VIP • 20 Free | `libarkernel3_android.so`, `libPVGLive.so`, `libMTARMPM.so` |
| **04** | **Trợ Lý AI Đàm Thoại RoboNeo** | [`/admin/RoboNeo`](http://127.0.0.1:9999/admin/RoboNeo) | **24** | 14 VIP • 10 Free | `libManis.so`, `libaidetectionplugin.so`, `libCtaApiLib.so` |
| **05** | **Gói Thuê Bao & Doanh Thu VIP** | [`/admin/VIP Plans`](http://127.0.0.1:9999/admin/VIP%20Plans) | **18** | 18 VIP • 0 Free | `libCtaApiLib.so`, Google Play Billing 7.0, StoreKit 2 |
| **06** | **Kho Chìa Khóa API Vault** | [`/admin/API Vault`](http://127.0.0.1:9999/admin/API%20Vault) | **12** | 6 VIP • 6 Free | AES-256 Storage, DeepSeek, Runway, Kling, Gemini |
| **--** | **TỔNG CỘNG HỆ THỐNG** | **Toàn Bộ 16 Menu CMS** | **296** | **138 VIP • 158 Free** | **45 Thư Viện C++ Native Hoàn Chỉnh** |

---

## 2. CHI TIẾT CÂY PHÂN CẤP CỦA TỪNG PHÂN HỆ

### 🎬 1. MODULE BIÊN TẬP VIDEO (VIDEOEDIT — 48 CHỨC NĂNG)
1. **Timeline & Cắt Ghép Đa Lớp:**
   - *Cắt Tách Đoạn Video Theo Frame (Split at Playhead)* `[Free]` ➜ `libffmpeg.so` (`nativeSplitVideoTrack`)
   - *Đường Cong Tốc Độ Chuyển Động (Speed Ramp 0.1x - 100x)* `[VIP]` ➜ `libffmpeg.so` (`nativeApplySpeedRamp`)
   - *Đảo Ngược Khung Hình Video (Reverse Video FX)* `[Free]` ➜ `libffavc.so` (`nativeReverseVideo`)
   - *Đóng Băng Khung Hình (Freeze Frame 1s - 10s)* `[VIP]` ➜ `libVERenderer.so` (`nativeInsertFreezeFrame`)
2. **Chuyển Cảnh & Kỹ Xảo Điện Ảnh:**
   - *Chuyển Cảnh Mượt Mà Không Vết Ghép (Zoom, Wipe, Dissolve)* `[Free]` ➜ `libVERenderer.so` (`nativeSetTransition`)
   - *Kỹ Xảo 3D Lập Phương & Nhiễu Sóng Glitch* `[VIP]` ➜ `libarkernel3.so` (`nativeApply3DTransition`)
3. **Âm Thanh & Tách Lời Bài Hát:**
   - *Trích Xuất Âm Thanh Từ Video (Audio Extractor)* `[Free]` ➜ `libffmpeg.so` (`nativeExtractAudioTrack`)
   - *Tách Lời Ca Sĩ Khỏi Nhạc Nền AI (Vocal Remover Karaoke)* `[VIP]` ➜ `libmfxkit.so` (`nativeSeparateVocals`)
   - *Biến Đổi Giọng Nói Vui Nhộn (Voice Modulation Chipmunk/Robot)* `[Free]` ➜ `libKKMusicFX.so` (`nativeApplyVoiceModulation`)
4. **Tách Nền Video AI & Phụ Đề:**
   - *Tách Người Video Không Cần Phông Xanh (AI Video Matting)* `[VIP]` ➜ `libARSPM.so` (`nativeSegmentVideoBody`)
   - *Tự Động Tạo Phụ Đề Tiếng Việt Bằng Giọng Nói (Auto Speech-to-Text)* `[VIP]` ➜ `libManis.so` (`nativeGenerateSubtitles`)
   - *Xuất Video 4K 60FPS Siêu Nét* `[VIP]` ➜ `libffavc.so` (`nativeRenderExport`)

---

### 📷 2. MODULE CAMERA AR & LÀM ĐẸP REALTIME (CAMERA — 36 CHỨC NĂNG)
1. **Làm Đẹp Thời Gian Thực Khi Quay / Chụp:**
   - *Mịn Da Trực Tiếp Khi Nhìn Màn Hình 60fps* `[Free]` ➜ `libarkernel3_android.so` (`nativeSetCameraBeautySmooth`)
   - *Gọt Cằm V-Line & Mắt To Thời Gian Thực* `[Free]` ➜ `libarkernel3.so` (`nativeSetCameraBeautyShape`)
   - *Trang Điểm Ảo Thời Gian Thực (Live AR Makeup)* `[VIP]` ➜ `libarkernel3.so` (`nativeApplyLiveMakeupLook`)
2. **Mặt Nạ AR & Hiệu Ứng 3D:**
   - *Nhãn Dán Tương Tác Há Miệng / Chớp Mắt (Expression Triggered)* `[Free]` ➜ `libMTARMPM.so` (`nativeLoadARStickerPackage`)
   - *Phụ Kiện Kính Mát & Mũ 3D PBR Ánh Kim* `[VIP]` ➜ `libarkernel3.so` (`nativeRender3DAccessory`)
3. **Chế Độ Chụp Chuyên Nghiệp & Đêm:**
   - *Chụp Đêm Siêu Sáng Đa Khung Hình (Night Multi-Frame HDR)* `[VIP]` ➜ `libPVGLive.so` (`nativeCaptureNightHDR`)
   - *Tùy Chỉnh ISO, Màn Trập DSLR Thủ Công* `[VIP]` ➜ `liblabdeviceinfo.so` (`nativeConfigureCameraSensor`)

---

### 💬 3. MODULE TRỢ LÝ AI ROBONEO (24 CHỨC NĂNG)
1. **Đàm Thoại & Điều Khiển Bằng Giọng Nói:**
   - *Chỉnh Sửa Ảnh Bằng Giọng Nói / Chat Tự Nhiên (Voice Photo Editing)* `[VIP]` ➜ `libManis.so` (`nativeParseBeautyIntent`)
   - *Chẩn Đoán Sắc Tố Da 106 Điểm & Đề Xuất Công Thức Makeup* `[Free]` ➜ `libaidetectionplugin.so` (`nativeAnalyzeSkinCondition`)
   - *Ghi Nhớ Ngữ Cảnh Hội Thoại Đa Tác Tử (Conversation Memory)* `[Free]` ➜ `RoboNeoChatDatabase`

---

### 👑 4. MODULE GÓI CƯỚC VIP & DOANH THU (18 CHỨC NĂNG)
1. **Danh Sách SKU & Bảng Giá:**
   - *Meitu VIP 1 Năm ($29.99/năm - Tiết kiệm 50%)* — SKU: `meitu_vip_yearly` `[VIP]`
   - *Meitu VIP 1 Tháng ($4.99/tháng)* — SKU: `meitu_vip_monthly` `[VIP]`
   - *Meitu VIP Trọn Đời ($99.99)* — SKU: `meitu_vip_lifetime` `[VIP]`
   - *Xác Thực Chữ Ký Biên Lai RSA/JWT* ➜ `libCtaApiLib.so` (`nativeVerifyReceiptSignature`)

---

### 🔑 5. MODULE KHO CHÌA KHÓA API VAULT (12 CHỨC NĂNG)
1. **Quản Lý Secret Key An Toàn:**
   - *DeepSeek LLM Key (Trí tuệ nhân tạo trợ lý RoboNeo)* `[VIP]` ➜ `libCtaApiLib.so` (`nativeEncryptApiKey`)
   - *Runway Gen-3 & Kling AI Video Keys (Biến ảnh thành video)* `[VIP]` ➜ `libCtaApiLib.so` (`nativeDispatchVideoTask`)
   - *Google Gemini Pro Vision (Phân tích sắc tố da)* `[Free]`
