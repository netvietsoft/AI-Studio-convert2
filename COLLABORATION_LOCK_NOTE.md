# BIÊN BẢN KHÓA RANH GIỚI VÀ ĐIỀU PHỐI ĐA NHÓM (COLLABORATION LOCK NOTE)
**Thời gian cập nhật:** 2026-09-24 09:16:42  
**Cơ chế điều phối:** Tuân thủ *Development Workspace Standard V2.1 Design Gated*  
**Mục tiêu:** Đảm bảo Zero Collision - Tuyệt đối không giẫm chân, không ghi đè mã nguồn giữa các nhóm.

---

## 1. PHÂN CHIA TRÁCH NHIỆM PHÁT TRIỂN (ACTIVE ASSIGNMENT)

### [VÙNG 1] CEO & ĐỘI NGŨ CHỦ LỰC (ĐANG THI CÔNG TÍCH CỰC: MODULE 1 -> 4):
- **Module 1: `:lib-core-graphics` (P0)**
  - *Phạm vi:* `com.meitu.core.*`, `com.meitu.glx.*`, `com.meitu.render.*`
  - *Trách nhiệm:* JNI Wrapper cho 45 file `.so`, Shaders (2,031 files), LUTs (127 files), Lua (228 files), OpenGL rendering.
- **Module 2: `:lib-common-ui` (P0)**
  - *Phạm vi:* `com.meitu.common.ui.*`, `com.meitu.library.*`
  - *Trách nhiệm:* Jetpack Compose & Material3 Theme, BaseActivity, BaseViewModel, Typography 29 Fonts, Reusable Components.
- **Module 3: `:lib-ai-engine` (P1)**
  - *Phạm vi:* `com.meitu.manis.*`, `com.meitu.facedetect.*`, `com.meitu.ai.*`
  - *Trách nhiệm:* Nạp 28 AI Models (`.bin`, `.manis`), nhận diện khuôn mặt 106 điểm (Landmark), Face Parsing, Hair/Skin segmentation.
- **Module 4: `:lib-photo-editor` (P1)**
  - *Phạm vi:* `com.meitu.edit.*`, `com.meitu.beauty.*`, `com.meitu.makeup.*`
  - *Trách nhiệm:* Core Beauty Pipeline, Làm mịn da (SkinSoften), Gọt cằm/nắn bóp (Slim/Reshape), Trang điểm 3D (Makeup), 3D LUT filter engine.

---

### [VÙNG 2] CÁC ĐỘI NGŨ ĐỘC LẬP KHÁC (ĐANG THI CÔNG: MODULE 5 -> 8):
- **Module 5: `:lib-roboneo` (P2)**
  - *Phạm vi độc quyền:* `lib-roboneo/` (`com.meitu.roboneo.*`, `com.meitu.layerflow.*`)
- **Module 6: `:lib-video-engine` (P2)**
  - *Phạm vi độc quyền:* `lib-video-engine/` (`com.meitu.videoedit.*`, `com.meitu.media.*`)
- **Module 7: `:lib-billing` (P2)**
  - *Phạm vi độc quyền:* `lib-billing/` (`com.meitu.vip.*`, `com.meitu.iap.*`, `com.meitu.sub.*`)
- **Module 8: `:app` (P3)**
  - *Phạm vi độc quyền:* `app/` (`com.mt.mtxx.mtxx.*`, `com.meitu.album.*`, `com.meitu.camera.*`)

---

## 2. NGUYÊN TẮC BẢO VỆ MÃ NGUỒN (ANTI-COLLISION GUARDS)
1. **CEO & Đội ngũ nội bộ cam kết:** Tuyệt đối không ghi đè hoặc chỉnh sửa bất kỳ tệp tin nào bên trong thư mục `lib-roboneo/`, `lib-video-engine/`, `lib-billing/`, `app/`.
2. **Các đội ngũ ngoài cam kết:** Tuyệt đối không can thiệp vào `lib-core-graphics/`, `lib-common-ui/`, `lib-ai-engine/`, `lib-photo-editor/`.
3. **Cấu hình Root đóng băng (Frozen Configs):** Không bên nào tự ý sửa `settings.gradle.kts` và root `build.gradle.kts`.
4. **Giao tiếp liên module:** Sử dụng các Public API và Interface được công bố trong `:lib-common-ui` và `:lib-core-graphics`.


---

## 3. NHẬT KÝ THI CÔNG CEO & ĐỘI NGŨ (CẬP NHẬT: 2026-09-24 09:27:41)
- **HOÀN THÀNH 100% CỤM MODULE 1 -> 4:**
  1. `:lib-core-graphics` (P0): JNI Wrappers (`MeituNativeLoader`, `MTFilterKernelConfigJNI`, `MTFilterKernelRender`, `MTLiquifyImage`, `MTHeadScale`, `MTGif`), bảo toàn 100% package `com.meitu.core.*` và 45 file `.so`.
  2. `:lib-common-ui` (P0): Material3 Theme, `MeituColors`, `MeituTypography` (29 fonts), Base Architecture MVI (`BaseViewModel`, `UiState`, `UiEffect`, `BaseActivity`), UI Components.
  3. `:lib-ai-engine` (P1): `ManisRuntime` C++ deep learning interface, `AiModelManager` nạp 28 tệp mô hình AI (.bin, .manis), `FaceDetector106` (106 điểm), `FaceParsingEngine` (Mặt nạ môi, da, tóc).
  4. `:lib-photo-editor` (P1): `BeautyPipeline`, `SkinSoftenProcessor`, `SlimReshapeProcessor`, `MakeupProcessor`, `FilterLutProcessor` (127 LUTs), `PhotoEditorViewModel` (Undo/Redo Stack).
- **Trạng thái Build:** Toàn bộ 4 module và `app-debug.apk` (122.9 MB) đã biên dịch xanh 100% (BUILD SUCCESSFUL).
- **Cam kết giữ ranh giới:** Không chạm vào bất kỳ file nào của các nhóm đang làm Module 5, 6, 7, 8.
