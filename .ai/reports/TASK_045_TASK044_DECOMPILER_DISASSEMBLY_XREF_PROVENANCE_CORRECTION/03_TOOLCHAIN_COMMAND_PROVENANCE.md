# TASK_045 — TOOLCHAIN & STATIC FORENSICS COMMAND PROVENANCE

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Máy Runner Thực thi:** `CONVERT2-WINDOWS-02` (Physical Windows 10/11 Host)  
**Thời điểm Thực thi:** 2026-10-04T13:49:30.191563+07:00  

---

## 1. DANH MỤC CÔNG CỤ & PHIÊN BẢN CHÍNH THỨC

Mọi dữ liệu kiểm toán tĩnh tại TASK_045 được sinh ra từ chuỗi công cụ chính thức của Google Android NDK r28 kết hợp thư viện phân tích nhị phân mã nguồn mở:

| Thành phần | Đường dẫn Nhị phân Thực tế trên Máy | Phiên bản & Bản dựng (Exact Version) | Kiến trúc Target |
|---|---|---|---|
| **llvm-objdump** | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-objdump.exe` | **LLVM 19.0.1** (build `llvm-r530567/out/llvm-project/llvm 97a699bf4812a18fb657c2779f5296a4ab2694d2`) | aarch64 / arm64-v8a (Little-Endian) |
| **llvm-readelf** | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-readelf.exe` | **LLVM 19.0.1** | aarch64 / ELF64 |
| **llvm-nm** | `C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-nm.exe` | **LLVM 19.0.1** | aarch64 / Dynamic Symbols |
| **Capstone Disassembler** | Python module `capstone` (ARM64 engine) | **Capstone 5.0.3** | ARM64 Instruction Decoding |
| **pyelftools** | Python module `elftools` | **pyelftools 0.32** | ELF64 / Relocation Parser |
| **Decompiler Status** | Ghidra Headless / radare2 / IDA Pro | **NOT INSTALLED** trên runner vật lý | Ghi nhận trung thực; sử dụng Disassembly + CFG/Xrefs |

---

## 2. CÚ PHÁP LỆNH THỰC THI CHUẨN MỰC (EXACT COMMANDS)

### Lệnh 1: Phân rã Lệnh máy Thực thi (Disassembly Extraction)
```powershell
& "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-objdump.exe" `
  -d -C --no-show-raw-insn "<PATH_TO_SO>" > "raw/<SO_NAME>/disassembly.txt"
```

### Lệnh 2: Khảo sát Tiêu đề ELF & Cấu trúc Phân đoạn (ELF Sections)
```powershell
& "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-readelf.exe" `
  -h -S -d "<PATH_TO_SO>"
```

### Lệnh 3: Khảo sát Bảng Định vị Động & Cầu nối Gọi ngoài (Relocations)
```powershell
& "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-readelf.exe" `
  -r "<PATH_TO_SO>" > "raw/<SO_NAME>/readelf_relocs.txt"
```

### Lệnh 4: Trích xuất Bảng Ký hiệu Động Giải mã (Demangled Symbols)
```powershell
& "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-nm.exe" `
  -D -C "<PATH_TO_SO>" > "raw/<SO_NAME>/nm_dynamic_demangled.txt"
```

### Lệnh 5: Khảo sát Chi tiết Vùng Địa chỉ Hàm Trọng yếu (Targeted Function Disassembly)
```powershell
& "C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\28.2.13676358\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-objdump.exe" `
  -d --start-address=0xf3800 --stop-address=0xf4bf0 "libMTFilterKernel.so"
```
