# mapping/ — Bộ ánh xạ cấu trúc từ mã dịch ngược Meitu

Thư mục chứa **ánh xạ dữ kiện cấu trúc** (không chứa thân hàm thừa thãi) trích từ
`SOURCE/jadx_src/sources/` (APK Meitu 12.17.8 / com.mt.mtxx.mtxx, jadx decompile).

## Ranh giới sử dụng

- Được dùng: tên package/class, chữ ký native method, danh sách `loadLibrary`,
  ánh xạ class Java → file Kotlin gốc (`@Metadata`), thống kê dex.
- Không được dùng: thân hàm (implementation) của mã `com.meitu.*` / `com.mt.*` / `com.mtxx.*` khi chưa có phê duyệt.
  Mã tham chiếu mới phải được chuẩn hóa theo Clean Kotlin Architecture.

## Artifacts (tái tạo bằng `python scan_sources.py`)

| File | Nội dung |
| :--- | :--- |
| `01_package_map.md` | Phân loại third-party vs độc quyền (55,781 classes), cây package, thống kê JNI |
| `02_class_inventory.json` | 55,781 class độc quyền: path, dex nguồn, kích thước, FQCN |
| `03_jni_bridge.json` | 1,068 class JNI, 22,276 native method, 45 thư viện `.so` |
| `03_jni_bridge.md` | Bảng chữ ký JNI dạng đọc được — đặc tả cho clean-room wrappers |
| `04_kotlin_structure.json` | 241 file `.kt` gốc ← tập class dịch ngược + method tương ứng |
| `_utils_struct.json` | 12 utility struct mapping chuyên biệt cho các lớp tiện ích |
| `05_module_filters.md` | Kế hoạch convert module Filters & MTFilter Core (Pass 0) |

## Ghi chú kỹ thuật

- Nhóm `com/meitu/*` và `com/mt/*` giữ nguyên tên package và method signature cho JNI bindings.
- 50,685 file third-party (androidx, com.google, okhttp3, retrofit2, bytedance, tencent, ...) nằm ngoài
  phạm vi — khai báo qua Gradle Version Catalog, không đưa vào mã nguồn.

## QUYẾT ĐỊNH 2026-09-24 (Chủ tịch) — CHẾ ĐỘ CONVERT DỰ ÁN MEITU

Chủ tịch chốt nguyên tắc chỉ đạo cho **dự án Meitu Reborn**:

1. **Bước 1 — CONVERT**: được phép chuyển **thân hàm** từ `SOURCE/jadx_src/sources` sang Kotlin/Java của dự án mới (giữ nguyên hành vi), **không** còn bắt buộc clean-room cứng nhắc.
2. **Bước 2 — DEV MỚI**: chỉ bắt đầu sau khi có bản convert chạy được; lúc đó mới có mapping/oracle để so và phát triển tiếp.
3. **Điều kiện kỹ thuật giữ nguyên**: mọi class convert phải ghi **nguồn file:dòng** vào đầu file; bỏ qua class do annotation processor sinh (`*_Factory`, `*_MembersInjector`, `$sam$`, lambda synthetic).
4. **Bản quyền**: mã vẫn là tài sản của Meitu — chỉ dùng theo quyền Chủ tịch xác lập; khi phát hành/thương mại hoá cần rà soát pháp lý (ghi ở `reference/README.md`).

*(Mục "Ranh giới sử dụng" phía trên là luật cũ, chỉ còn áp dụng cho các artifact đã sinh trước ngày này.)*
