# TASK_045 — UNRESOLVED STATIC BINARY LIMITATIONS

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  

---

## 1. GIỚI HẠN NHỊ PHÂN STRIPPED & ĐIỀU PHỐI ĐỘNG (DYNAMIC DISPATCH)
1. **Lược bỏ Bảng Ký hiệu Tĩnh (`.symtab`):**  
   Cả 45/45 thư viện .so của nhà cung cấp đã bị lược bỏ toàn bộ `.symtab`. Chỉ các hàm được xuất khẩu (`.dynsym`) hoặc có tên trong bảng vtable C++ RTTI mới có thể phục hồi tên demangled. Hơn 85% các hàm nội bộ chỉ có địa chỉ bù trừ (`offset`) mà không có tên hàm gốc.
2. **Con trỏ Hàm Ảo (Indirect Calls via Registers - `blr`):**  
   Trong các thư viện đồ họa lớn (`libMTFilterKernel.so`, `libarkernel3.so`), nhiều hàm kết xuất gọi qua con trỏ ảo trong struct (`blr x8`). Các liên kết này không thể xác định tĩnh 100% bằng objdump mà phụ thuộc vào trạng thái khởi tạo runtime của context C++.

## 2. GIỚI HẠN CÔNG CỤ DECOMPILER TRÊN MÁY RUNNER
1. **Không cài đặt Ghidra / radare2 / IDA:**  
   Máy `CONVERT2-WINDOWS-02` không có sẵn môi trường Ghidra Headless hoặc IDA Pro.
2. **Biện pháp Tuân thủ Trung thực:**  
   Tuân thủ nghiêm ngặt Điều 2 của TASK_045: Ghi nhận sự thiếu vắng công cụ decompiler, sử dụng 100% phân rã lệnh máy thực tế (LLVM objdump) kết hợp dựng đồ thị luồng điều khiển (CFG) và trích xuất chuỗi mã nguồn GLSL nhúng. Tuyệt đối không bịa đặt output decompiler.

## 3. PHẠM VI BẢO VỆ PHÁP LÝ & AN TOÀN (EXCLUSIONS)
6 thư viện bảo mật và DRM được đóng băng và loại trừ khỏi quy trình phân rã chi tiết theo Điều 11:
- `libdexvmp.so` (Anti-Tamper)
- `libMtlabSign.so` (HMAC Request Signer)
- `libhttpelf.so` (Network Packet Cryptor)
- `libCtaApiLib.so` (Privacy Compliance)
- `libfile_lock_pgl.so` (Pangolin DRM Lock)
- `libbuffer_pgl.so` (Pangolin DRM Buffer)
