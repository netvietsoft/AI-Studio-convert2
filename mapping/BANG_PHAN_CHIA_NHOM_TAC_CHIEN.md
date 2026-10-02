# BẢNG PHÂN CHIA NHÓM ĐIỀU PHỐI TÁC CHIẾN (MEITU REBORN 100%)
**Dự án:** Meitu Reborn (Package: `com.mt.mtxx.mtxx`)  
**Tài liệu điều phối chuẩn:** Theo *Development Workspace Standard V2.1 Design Gated*  
**Mục tiêu:** Phân chia ranh giới module rõ ràng, độc lập tuyệt đối để nhiều nhóm kỹ sư / AI Agents (Claude, Codex, DeepSeek,...) cùng phát triển song song không gây xung đột (Zero Collision), hướng tới độ chính xác 100% nguyên bản.

---

## 1. THIẾT LUẬT PHÂN TẦNG VÀ ĐIỀU PHỐI NHÓM

> [!IMPORTANT]
> **Quy tắc vàng:**
> 1. Tổng số file decompiled là 138,552 files, trong đó **~117,000 files là thư viện bên thứ 3** (AndroidX, Google, OkHttp, Retrofit, Glide, v.v.) -> **TUYỆT ĐỐI KHÔNG CONVERT** mà dùng dependencies Gradle.
> 2. Khối lượng code nghiệp vụ thực sự cần convert là **~21,500 files**.
> 3. Từng nhóm hoạt động độc lập trong module được phân công, bẻ gãy đệ quy phụ thuộc bằng **Stubbing Interface**.

---

## 2. MA TRẬN PHÂN CHIA CÁC NHÓM TÁC CHIẾN

| Nhóm | Phân hệ Module | ~Files thực tế | Thư viện Native C++ (`.so`) | Ưu tiên | Thư mục Package nguồn (JADX) | Module đích trong CONVERT2 | Trách nhiệm cốt lõi |
| :--- | :--- | :---: | :---: | :---: | :--- | :--- | :--- |
| **Nhóm 1** | **Core Graphics & JNI Bridge** | **~890** | **45 file `.so`**<br>(`libarkernel3.so`, `libMTFilterKernel.so`, `libbmpKit.so`, `libc++_shared.so`...) | **P0**<br>*(Bắt buộc)* | `com/meitu/core/*`<br>`com/meitu/glx/*`<br>`com/meitu/render/*` | `:lib-core-graphics` | Dựng toàn bộ JNI Wrappers, giữ 100% package & method signatures, nạp `MeituNativeLoader`. |
| **Nhóm 2** | **Common UI & Foundation** | **~1,800** | **KHÔNG**<br>(Pure Kotlin / Jetpack Compose) | **P0**<br>*(Bắt buộc)* | `com/meitu/library/*`<br>`com/meitu/common/*` | `:lib-common-ui` | Dựng hệ thống Material3 Theme, BaseViewModel, BaseActivity, Custom Views, Dialog, 29 Fonts. |
| **Nhóm 3** | **On-Device AI Engine** | **~650** | **4 file `.so`**<br>(`libManis.so`, `libAIModelKit.so`, `libmanis_npu_adapter.so`...) | **P1**<br>*(Song song)* | `com/meitu/manis/*`<br>`com/meitu/facedetect/*`<br>`com/meitu/ai/*` | `:lib-ai-engine` | Nạp 28 AI Models (.bin, .manis), nhận diện 106 điểm khuôn mặt, Face Parsing, Hair & Skin Segment. |
| **Nhóm 4** | **Photo Editor & Beauty** | **~4,200** | **GIÁN TIẾP**<br>(Gọi JNI qua `:lib-core-graphics`) | **P1**<br>*(Song song)* | `com/meitu/edit/*`<br>`com/meitu/makeup/*`<br>`com/meitu/beauty/*` | `:lib-photo-editor` | Bộ công cụ chỉnh ảnh cốt lõi: Làm mịn da (SkinSoften), Gọt cằm (Slim), Son môi, Kẻ mắt, 3D LUTs. |
| **Nhóm 5** | **Interactive & RoboNeo AI** | **~1,980** | **1 file `.so`**<br>(`libLayerFlow.so`) | **P2**<br>*(Song song)* | `com/meitu/layerflow/*`<br>`com/meitu/roboneo/*` | `:lib-roboneo` | Canvas đa tầng LayerFlow, Sticker tương tác, Khung ảnh, Trợ lý AI RoboNeo kết nối MiracleVision qua SSE. |
| **Nhóm 6** | **Video Engine & FX** | **~2,150** | **6 file `.so`**<br>(`libffmpeg.so`, `libPVGVideoCodec.so`, `libVERenderer.so`...) | **P2**<br>*(Song song)* | `com/meitu/videoedit/*`<br>`com/meitu/media/*` | `:lib-video-engine` | Timeline video đa track, cắt ghép, chuyển cảnh, hiệu ứng Video FX, bộ trích xuất audio, bộ nén MP4. |
| **Nhóm 7** | **VIP Monetization & Billing** | **~940** | **KHÔNG**<br>(Google Play Billing 7.0) | **P2**<br>*(Song song)* | `com/meitu/vip/*`<br>`com/meitu/sub/*`<br>`com/meitu/iap/*` | `:lib-billing` | Quản lý hạn dùng VIP, Paywall popup mở khóa tính năng cao cấp, xử lý biên lai Google Play Billing. |
| **Nhóm 8** | **App Shell & Pipeline Chính** | **~3,880** | **KHÔNG**<br>(Module điều phối ứng dụng) | **P3**<br>*(Tích hợp sau cùng)* | `com/mt/mtxx/mtxx/*`<br>`com/meitu/album/*`<br>`com/meitu/camera/*` | `:app` | Màn hình Home, Điều hướng Navigation, Room Database 92 bảng, Ktor Network API, Camera Preview. |

---

## 3. SƠ ĐỒ ĐỘ PHỤ THUỘC (DEPENDENCY FLOW)

```mermaid
graph TD
    subgraph TẦNG 0 - NỀN TẢNG BẮT BUỘC (P0)
        G1[Nhóm 1: Core Graphics JNI<br>:lib-core-graphics]
        G2[Nhóm 2: Common UI & Base<br>:lib-common-ui]
    end

    subgraph TẦNG 1 - TÍNH NĂNG ĐỘC LẬP (P1)
        G3[Nhóm 3: On-Device AI Engine<br>:lib-ai-engine]
        G4[Nhóm 4: Photo Editor & Beauty<br>:lib-photo-editor]
    end

    subgraph TẦNG 2 - MỞ RỘNG & KINH DOANH (P2)
        G5[Nhóm 5: RoboNeo & LayerFlow<br>:lib-roboneo]
        G6[Nhóm 6: Video Engine & FFmpeg<br>:lib-video-engine]
        G7[Nhóm 7: VIP Paywall & Billing<br>:lib-billing]
    end

    subgraph TẦNG 3 - TỔNG HỢP ỨNG DỤNG (P3)
        G8[Nhóm 8: App Shell, Room DB, Navigation<br>:app]
    end

    G1 --> G3
    G1 --> G4
    G2 --> G4
    G3 --> G4
    G1 --> G5
    G1 --> G6
    G2 --> G7
    G4 --> G8
    G5 --> G8
    G6 --> G8
    G7 --> G8
```

---

## 4. QUY ĐỊNH PHỐI HỢP TÁC CHIẾN ĐA NHÓM (COLLISION-FREE PROTOCOL)

1. **Ranh giới bất khả xâm phạm:**
   - Mỗi nhóm chỉ được tạo/sửa file trong module của mình (`/lib-xyz/src/main/kotlin/...`).
   - Tuyệt đối không sửa file cấu hình root (`settings.gradle.kts`, root `build.gradle.kts`) khi chưa có lệnh từ CEO Orchestrator.
2. **Quy tắc JNI Package (Sống còn):**
   - Nhóm 1 và Nhóm 3 khi viết wrapper cho C++ phải bảo toàn nguyên vẹn tên package `com.meitu.core.*` và `com.meitu.manis.*`. Nếu đổi package sẽ gây crash ngay lập tức (`java.lang.UnsatisfiedLinkError`).
3. **Quy tắc Bẻ gãy phụ thuộc (Stubbing):**
   - Khi Nhóm 4 (Photo Editor) cần gọi Nhóm 7 (VIP), hãy tạo interface `VipFeatureGate` ngay trong `lib-photo-editor` với triển khai mặc định `DefaultVipFeatureGate` trả về `isVip = true` để biên dịch độc lập.
4. **Quy tắc Nghiệm thu (Build Gate):**
   - Mỗi khi nhóm hoàn thành một cụm code, bắt buộc chạy kiểm thử:
     ```powershell
     .\gradlew.bat :<module-name>:compileDebugKotlin
     ```
     Chỉ khi build xanh mới được báo cáo hoàn thành.
