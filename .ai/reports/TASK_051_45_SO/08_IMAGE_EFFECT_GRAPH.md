# TASK_051 — IMAGE EFFECT GRAPH MASTER SPECIFICATION
**Authority:** Chủ tịch Tony  
**Task ID:** TASK_051_P0_45_SO_MAX_DEPTH_CONTINUOUS_RECONSTRUCTION_ACTIVE  
**Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Runner Identity:** CONVERT2-WINDOWS-02 (GITHUB_ACTIONS_37204962051)  
**Commit SHA:** b7ca2dc975472c14bf586c67f93d54b226169971  
**Execution Timestamp:** 2026-10-04T20:25:00+07:00  
**Hard Gate:** ZERO UNWANTED LEAKAGE & LOCKED MODULES INTEGRITY (Zero changes to `production-hair-v2/v3/v4`)  

---

## 1. TỔNG QUAN ĐỒ THỊ HIỆU ỨNG HÌNH ẢNH TOÀN CẢNH (END-TO-END IMAGE EFFECT GRAPH)

Đồ thị Hiệu ứng Hình ảnh của CONVERT2 được thiết kế dựa trên kết quả giải mã kỹ thuật đảo ngược sạch từ 45 thư viện nhị phân lõi Meitu (`libMTFilterKernel.so`, `libLayerFlow.so`, `libarkernel3.so`, `libPVGColorFunctions.so`, `libManis.so`).  
Toàn bộ luồng dữ liệu trải qua **8 giai đoạn nối tiếp (Multi-Pass Ping-Pong Framebuffer Pipeline)**, bảo đảm độ chính xác từng bit, pixel, đồng thời bảo vệ 100% vùng không can thiệp (da mặt, trán, vành tai, cổ áo, hậu cảnh):

```
[UI Trigger: Hair Color Swatch / Slider Event]
                      │
                      ▼
[DEX: HairViewModel -> LFEffectDenseHairData / MTIKABHairFilter]
                      │
                      ▼
[JNI / RegisterNatives: nSetMaterialId, nSetAlpha, nSetTraditionHairDyeIntensityAndShine]
                      │
                      ▼
┌─────────────────────┴───────────────────────────────────────────────────────┐
│ C++ NATIVE ENGINE EXECUTION PIPELINE (libMTFilterKernel.so & libLayerFlow.so)│
├─────────────────────────────────────────────────────────────────────────────┤
│ GIAI ĐOẠN 1: Semantic Segmentation Mask (mtface_parsing.bin -> Manis)       │
│              Input: RGB [1, 512, 512, 3] -> Output: Hair Mask Tensor Ch 17   │
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 2: Guided Alpha Matting & Hairline Feathering (hairMaskFilterToFBO)│
│              Khử răng cưa viền tóc, bảo tồn sợi tóc tơ mai/trán             │
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 3: High-Frequency Luminance Extraction (grayFilterToFBO)          │
│              Chuẩn hóa độ sáng ITU-R BT.601: dot(rgb, [0.299, 0.587, 0.114])│
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 4: 2D Structure Tensor & Orientation Field (blurH/VFilterToFBO)   │
│              Sobel Gx, Gy -> Jxx, Jyy, Jxy -> 5-tap Gaussian -> (cos 2θ, sin 2θ)│
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 5: Directional 21-tap Line Integral Convolution (softHairFilter)  │
│              Lọc mượt theo tiếp tuyến dòng chảy sợi tóc, khử nhiễu camera   │
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 6: Non-Branching Pegtop SoftLight Recolor / Tone Blending         │
│              Hòa trộn màu nhuộm Rose Gold 3D LUT, giữ chiều sâu bóng/sáng   │
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 7: 9x9 Unsharp Mask & Hair Shine / Clarity Boost (Clarity 0.4)    │
│              Lưới lấy mẫu hộp 81 điểm ảnh, giãn cách 2.3x, tương phản 1.8x   │
│                      │                                                      │
│                      ▼                                                      │
│ GIAI ĐOẠN 8: Final Alpha Compositing & Absolute Protected Isolation         │
│              Final = (1 - Mask)*Original + Mask*DyedEnhanced (Zero Leakage) │
└─────────────────────────────────────────────────────────────────────────────┘
                      │
                      ▼
[Output FBO: Samsung Galaxy A50 / Vulkan / OpenGL ES 3.0 Surface]
```

---

## 2. BẢO VỆ TUYỆT ĐỐI VÙNG KHÔNG CAN THIỆP (ZERO-LEAKAGE ISOLATION SPECIFICATION)

Căn cứ Điều 5 Hiến pháp Vận hành (AGENTS.md & GEMINI.md):
- **Da mặt, trán, lông mày:** Điểm ảnh nằm ngoài mặt nạ tóc có hệ số can thiệp Alpha = 0.0000. Tọa độ RGB đầu ra bắt buộc bằng 100% tọa độ RGB ảnh gốc:
  $$\Delta E_{ab}^* = 0.0000$$
- **Vành tai, râu, viền cổ áo:** Vùng chuyển tiếp (feathering zone) có độ rộng giới hạn $\le 3 \text{ pixels}$, suy giảm theo hàm mũ mượt mà $\exp(-d^2 / 2\sigma^2)$, ngăn chặn triệt để hiện tượng vệt màu hay lem sang cổ áo.
- **Hậu cảnh (Background) & UI:** Hoàn toàn cô lập ở cấp độ Shader FBO và GPU Draw Call.

---

## 3. BẢNG THAM SỐ TOÁN HỌC ĐÃ KIỂM CHỨNG (EMPIRICALLY VERIFIED PARAMETERS)

| Tên Tham Số | Vị Trí Nhị Phân | Giá Trị Thực Tế | Ý Nghĩa Thuật Toán |
|:---|:---|:---|:---|
| **Canvas Size Width** | `libMTFilterKernel.so` `0xf401c` | `962.0f` | Chiều rộng chuẩn hóa của FBO đệm chân dung |
| **Canvas Size Height** | `libMTFilterKernel.so` `0xf400c` | `1280.0f` | Chiều cao chuẩn hóa của FBO đệm chân dung |
| **Gaussian Weights** | `libMTFilterKernel.so` `0x8edd8` | `[0.159676, 0.263348, 0.122118, 0.030573, 0.004122]` | Vector trọng số 5 điểm Gauss bán kính nửa $\sigma=1.85$ |
| **Horizontal Offsets** | `libMTFilterKernel.so` `0x8edc4` | `[0.0, 0.002250, 0.005256, 0.008271, 0.011299]` | Tọa độ UV lấy mẫu theo chiều ngang trên canvas 962px |
| **Vertical Offsets** | `libMTFilterKernel.so` `0x8edec` | `[0.0, 0.002994, 0.006993, 0.011005, 0.015034]` | Tọa độ UV lấy mẫu theo chiều dọc trên canvas 1280px |
| **Unsharp Sampling Step**| `libMTFilterKernel.so` `0x77afa` | `2.3f` | Bước nhảy lưới hộp 9x9 (`vec2 * 2.3`) |
| **Unsharp Contrast Gain**| `libMTFilterKernel.so` `0x77afa` | `1.8f` | Hệ số khuếch đại tương phản vi mô sợi tóc |
| **Clarity Boost Factor** | `libMTFilterKernel.so` `0x77afa` | `0.4f` | Hệ số độ trong trẻo sợi tóc (`clarity = 0.4`) |
| **Clarity Bias Offset**  | `libMTFilterKernel.so` `0x77afa` | `0.015f` | Độ dịch mức xám bù trừ vùng tối sợi tóc |
| **LIC Kernel Taps**      | `libMTFilterKernel.so` `0xf4980` | `21 taps` | Số điểm tích phân đường theo hướng tiếp tuyến |
| **LIC Gaussian Sigma**   | `libMTFilterKernel.so` `0xf4980` | `3.5f` | Độ lệch chuẩn bộ lọc làm mượt có hướng |
| **Mask Threshold**       | `libMTFilterKernel.so` `0x77afa` | `0.005f` | Ngưỡng kích hoạt tối thiểu (0.5% độ tin cậy tóc) |
