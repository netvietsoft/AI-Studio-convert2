# THIẾT KẾ & TỔ CHỨC MENU ADMIN CMS MEITU REBORN (CHUẨN ENTERPRISE)
> **Cổng dịch vụ Backend & CMS:** `http://127.0.0.1:9999/`  
> **Cơ chế Router:** Universal SPA Fallback Router (Hỗ trợ truy cập trực tiếp mọi URL, bookmark, reload và pushState).  
> **Phiên bản:** v2.2 Production Ready  
> **Thời gian cập nhật:** 2026-09-24  

---

## 1. NGUYÊN TẮC THIẾT KẾ ĐIỀU HƯỚNG URL
1. **Truy cập trực tiếp (Direct Deep-link):** Người dùng có thể gõ hoặc paste bất kỳ URL nào như `http://127.0.0.1:9999/admin/Makeup Styles` hoặc `http://127.0.0.1:9999/admin/makeup-styles` vào trình duyệt, Server trả về mã `200 OK` (SPA Fallback) và Router JavaScript tự động active đúng tab, highlight đúng menu trên Sidebar.
2. **Không Reload Trang (Zero-Flicker SPA):** Khi click vào bất kỳ menu nào trên Sidebar hoặc Topbar, URL trên thanh địa chỉ duyệt web tự động cập nhật qua `window.history.pushState(null, '', route)`.
3. **Hỗ trợ Nút Lịch Sử Duyệt Web (History Popstate):** Hỗ trợ đầy đủ phím Back / Forward của trình duyệt mà không làm mất trạng thái dữ liệu.
4. **Cô Lập Tuyệt Đối:** Dự án chạy hoàn toàn độc lập trên cổng **9999**, bảo vệ nguyên vẹn dự án cũ tại cổng **8097**.

---

## 2. BẢNG DANH MỤC MENU & URL CHUẨN ĐÃ TRIỂN KHAI

| STT | Tên Menu CMS | URL Chuẩn Hiển Thị | URL Mềm (Aliases Hỗ Trợ) | Tab View ID | Chức Năng Chính |
|---|---|---|---|---|---|
| **01** | **Tổng quan Hệ thống** | `/admin/Dashboard` | `/admin/`, `/admin/dashboard` | `tab-dashboard` | Giám sát KPI thời gian thực, RAM, Uptime, Traffic |
| **02** | **Giám sát Build Mobile** | `/admin/Build Monitor` | `/admin/build-monitor`, `/admin/build` | `tab-build-monitor` | Theo dõi 8 Modules Kotlin, Native Binaries, Tải APK Debug |
| **03** | **Phong cách Trang điểm** | `/admin/Makeup Styles` | `/admin/makeup-styles`, `/admin/makeup` | `tab-makeup` | **Quản lý Preset Son môi, Má hồng, Mi, Eyeliner, Live Simulator** |
| **04** | **Bộ lọc & 3D LUTs** | `/admin/Filters` | `/admin/filters`, `/admin/3d-luts` | `tab-filters` | Quản lý 127 LUTs màu điện ảnh, chân dung, retro |
| **05** | **Nắn bóp & Gọt cằm** | `/admin/Facelift` | `/admin/facelift`, `/admin/face-lift` | `tab-facelift` | Hiệu chỉnh 106 điểm Facial Landmarks (V-line, mắt to, mũi cao) |
| **06** | **Phông chữ Nghệ thuật** | `/admin/Fonts` | `/admin/fonts` | `tab-fonts` | Quản lý 29 Fonts typography hỗ trợ tiếng Việt |
| **07** | **Hàng đợi Tác vụ AIGC** | `/admin/AIGC Queue` | `/admin/aigc-queue`, `/admin/aigc` | `tab-aigc-queue` | Giám sát GPU Cloud Render, AI Inpainting, Eraser |
| **08** | **Gói Ảnh Chân Dung AI** | `/admin/AI Photo` | `/admin/ai-photo` | `tab-ai-photo` | Cấu hình Preset AI Studio (Doanh nhân, Retro, Cyberpunk) |
| **09** | **Cấu hình Trợ lý RoboNeo**| `/admin/RoboNeo` | `/admin/roboneo` | `tab-roboneo` | Thiết lập System Prompt, persona & capabilities của AI Agent |
| **10** | **Gói Thuê bao & Bảng giá** | `/admin/VIP Plans` | `/admin/vip-plans`, `/admin/vip` | `tab-vip-plans` | Quản lý SKU giá bán IAP (Yearly, Monthly, Lifetime) |
| **11** | **Đối soát Biên lai IAP** | `/admin/Transactions` | `/admin/transactions`, `/admin/billing` | `tab-transactions` | Bảng đối soát đơn hàng từ Apple App Store & Google Play |
| **12** | **Quản lý Người dùng** | `/admin/Users` | `/admin/users` | `tab-users` | Tra cứu Device ID, tài khoản VIP, lịch sử tạo ảnh |
| **13** | **Vị trí Quảng cáo (Ads)** | `/admin/Ads` | `/admin/ads` | `tab-ads` | Cấu hình mạng AdMob, Pangle, IronSource cho bản Free |
| **14** | **Kho Chìa Khóa API Vault** | `/admin/API Vault` | `/admin/api-vault`, `/admin/settings` | `tab-api-vault` | Quản lý Secret Key bên thứ 3 (DeepSeek, Runway, Kling, Gemini) |

---

## 3. CHI TIẾT TÍNH NĂNG MENU MAKEUP STYLES (`/admin/Makeup Styles`)
- **API Backend:**
  - `GET /material/makeup_list`: Lấy danh sách toàn bộ các phong cách makeup.
  - `POST /material/makeup_save`: Thêm mới hoặc cập nhật một phong cách makeup (hỗ trợ lưu màu son, loại finish, độ mờ alpha, má hồng, eyeliner, lông mi, kính áp tròng, màu tóc, phân hạng VIP).
  - `POST /material/makeup_delete`: Xóa một phong cách makeup theo ID.
- **Giao diện Trực Quan:**
  - Bảng dữ liệu hiển thị swatch màu thực tế (Color Dot tròn), mã Hex, độ đậm %, phân loại VIP Badge.
  - Khung **Live Makeup Simulator** bên phải cho phép kéo thanh trượt điều chỉnh độ đậm son môi (Alpha 0-100%) và xem trước hiệu ứng phối màu trực quan trên khuôn mặt mẫu.
  - Nút **Sao Chép JSON Engine Config** giúp lập trình viên Android sao chép ngay cấu hình JSON để nạp vào Native JNI Shaders Pipeline.
  - Modal Form thêm / sửa phong cách trực quan có Color Picker trực tiếp.

---

## 4. KẾT QUẢ KIỂM THỬ XÁC THỰC
- **Kiểm thử tự động (Python Verification Suite):**
  - `http://127.0.0.1:9999/admin/Makeup%20Styles` -> HTTP 200 OK.
  - `http://127.0.0.1:9999/admin/makeup-styles` -> HTTP 200 OK.
  - `http://127.0.0.1:9999/admin/Filters` -> HTTP 200 OK.
  - `http://127.0.0.1:9999/admin/VIP%20Plans` -> HTTP 200 OK.
  - `http://127.0.0.1:8097/healthz` -> HTTP 200 OK (Cô lập 100%).
- **Kiểm thử tương tác trình duyệt (Browser Subagent):**
  - Mở trực tiếp link `http://127.0.0.1:9999/admin/Makeup Styles` trên trình duyệt thực tế.
  - Tab "Phong cách Trang điểm" tự động sáng đèn active, thanh địa chỉ hiển thị đúng URL, breadcrumb hiển thị đúng đường dẫn.
  - Click chuyển các menu khác trong Sidebar diễn ra mượt mà tức thì, URL trên trình duyệt cập nhật tương ứng theo chuẩn SPA.
