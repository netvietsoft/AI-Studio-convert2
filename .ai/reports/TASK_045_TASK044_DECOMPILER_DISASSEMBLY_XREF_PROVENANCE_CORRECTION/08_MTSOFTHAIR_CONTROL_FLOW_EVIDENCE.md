# TASK_045 — FORENSIC EVIDENCE: MTSOFTHAIRRENDERPIPELINE CONTROL FLOW

**Canonical Authority:** Chủ tịch Tony  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mã nguồn Nhị phân:** `libMTFilterKernel.so` (SHA-256: `94DFDFDE856A9BFD423DE4DFE0D71B6F684E0FF444BDCDDEB1FE8A2542C75EF6`)  
**Hàm Phân tích:** `MTFilterKernel::MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates`  
**Địa chỉ Bắt đầu (Entry Address):** `0x00000000000f3f58`  

---

## 1. CONTROL FLOW GRAPH & CALL SEQUENCE THỰC TẾ TRONG LÕI ARM64

Trái ngược hoàn toàn với mã giả suy đoán 4 bước của TASK_044, mã phân rã lệnh máy thực tế chứng minh quy trình kết xuất của `MTSoftHairFilter` bao gồm **5 pass tuần tự có điều kiện**:

```
[ ENTRY: 0x000f3f58 ]
         │
         ▼
[ Kiểm tra Framebuffer con trỏ 0x1e8 ] ──(NULL)──► [ Khởi tạo FBO mới tại 0xf405c ]
         │ (NON-NULL)                                      │
         ├─────────────────────────────────────────────────┘
         ▼
[ PASS 1: grayFilterToFBO ] ──────────────► bl 0x000f42fc
  Trích xuất độ xám (Luminance) từ ảnh gốc
         │
         ▼
[ PASS 2: hairMaskFilterToFBO ] ──────────► bl 0x000f4400
  (BỊ TASK_044 BỎ SÓT HOÀN TOÀN)
  Chuẩn hóa và cắt lọc mặt nạ tóc vào FBO đệm
         │
         ▼
[ PASS 3: blurHFilterToFBO ] ─────────────► bl 0x000f4528
  Làm mờ Gauss 5 điểm theo chiều ngang (Horizontal Gaussian Blur)
  Sử dụng vector Weights tại 0x8edd8 và Offsets tại 0x8edc4
         │
         ▼
[ PASS 4: blurVFilterToFBO ] ─────────────► bl 0x000f46d0
  Làm mờ Gauss 5 điểm theo chiều dọc (Vertical Gaussian Blur)
  Sử dụng vector Weights tại 0x8edd8 và Offsets tại 0x8edec
         │
         ▼
[ PASS 5: softHairFilterToFBO ] ──────────► bl 0x000f4878
  Khai hỏa Shader MTSoftHairFilter.cpp
  Tham số CGSize: width = 962.0f (0x44708000), height = 1280.0f (0x44a00000)
         │
         ▼
[ EXIT: 0x000f4058 ] (Stack guard check -> ret)
```

---

## 2. TRÍCH ĐOẠN LỆNH MÁY PHÂN RÃ CHỨNG MINH 5 LƯỢT GỌI HÀM

Trích đoạn nguyên văn từ lệnh `llvm-objdump -d` tại địa chỉ `0x000f3fa0` đến `0x000f4028`:

```arm64
   f3fa0: aa1403e0     mov     x0, x20          ; this (MTSoftHairFilter*)
   f3fa4: aa1503e1     mov     x1, x21          ; vertices pointer
   f3fa8: aa1603e3     mov     x3, x22          ; textureCoordinates pointer
   f3fac: 940000d4     bl      0xf42fc          ; === CALL PASS 1: grayFilterToFBO ===
   f3fb0: f940f683     ldr     x3, [x20, #0x1e8]; load input FBO
   f3fb4: f940fe84     ldr     x4, [x20, #0x1f8]; load hairMask FBO
   f3fb8: aa1403e0     mov     x0, x20          ; this
   f3fbc: aa1503e1     mov     x1, x21          ; vertices
   f3fc0: 94000110     bl      0xf4400          ; === CALL PASS 2: hairMaskFilterToFBO ===
   f3fc4: f940fe83     ldr     x3, [x20, #0x1f8]; load masked FBO
   f3fc8: f9410684     ldr     x4, [x20, #0x208]; load blurH FBO
   f3fcc: aa1403e0     mov     x0, x20          ; this
   f3fd0: aa1503e1     mov     x1, x21          ; vertices
   f3fd4: 94000155     bl      0xf4528          ; === CALL PASS 3: blurHFilterToFBO ===
   f3fd8: f9410683     ldr     x3, [x20, #0x208]; load blurH FBO
   f3fdc: f9410e84     ldr     x4, [x20, #0x218]; load blurV FBO
   f3fe0: aa1403e0     mov     x0, x20          ; this
   f3fe4: aa1503e1     mov     x1, x21          ; vertices
   f3fe8: 940001ba     bl      0xf46d0          ; === CALL PASS 4: blurVFilterToFBO ===
   f3fec: f9403288     ldr     x8, [x20, #0x60] ; context
   f3ff0: f9410e89     ldr     x9, [x20, #0x218]; blurV FBO texture
   f3ff4: aa1403e0     mov     x0, x20          ; this
   f3ff8: b9400ec3     ldr     w3, [x22, #0xc]  ; texture ID
   f3ffc: aa1503e1     mov     x1, x21          ; vertices
   f4000: aa1303e6     mov     x6, x19          ; target Framebuffer
   f4004: f940c508     ldr     x8, [x8, #0x188] ; parameter struct
   f4008: b9400d24     ldr     w4, [x9, #0xc]   ; blur texture ID
   f400c: 52a89409     mov     w9, #0x44a00000  ; IEEE 754: 1280.0f (Height)
   f4010: 1e270121     fmov    s1, w9           ; s1 = 1280.0f
   f4014: b9405105     ldr     w5, [x8, #0x50]  ; mode flag
   f4018: 52900008     mov     w8, #0x8000
   f401c: 72a88e08     movk    w8, #0x4470, lsl #16 ; IEEE 754: 962.0f (Width)
   f4020: 1e270100     fmov    s0, w8           ; s0 = 962.0f
   f4024: 94000215     bl      0xf4878          ; === CALL PASS 5: softHairFilterToFBO ===
```

---

## 3. THÔNG SỐ BỘ LỌC GAUSS THỰC TẾ TRONG LÕI C++

Tại hàm `blurHFilterToFBO` (`0x000f4528`), các vector trọng số và độ dịch chuyển được nạp trực tiếp từ phân đoạn dữ liệu `.rodata`:

| Thông số | Địa chỉ Nhị phân | Giá trị Trích xuất | Ý nghĩa Thuật toán |
|---|---|---|---|
| **Weights Vector** | `0x0008edd8` | `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]` | 5 trọng số của hàm Gauss nửa bán kính (suy biến từ $\sigma pprox 1.85$). |
| **Horizontal Offsets** | `0x0008edc4` | `[0.0, 0.002250, 0.005256, 0.008271, 0.011299]` | Tọa độ lấy mẫu UV chuẩn hóa trên chiều rộng 962px. |
| **Vertical Offsets** | `0x0008edec` | `[0.0, 0.002994, 0.006993, 0.011005, 0.015034]` | Tọa độ lấy mẫu UV chuẩn hóa trên chiều cao 1280px. |
| **Uniform Names** | `0x8d0e5` & `0x736e0` | `"Weights"`, `"Offsets"` | Tên chuỗi uniform nạp vào `GPUImageProgram`. |

**Bác bỏ hoàn toàn:** Tuyên bố của TASK_044 về `u_blurRadius = 2.5f` là suy diễn không có căn cứ. Lõi C++ của Meitu sử dụng bảng tra trọng số Gauss 5 điểm tĩnh được tối ưu hóa cho độ phân giải chân dung chuẩn.
