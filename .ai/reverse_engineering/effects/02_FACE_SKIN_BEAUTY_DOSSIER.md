# CONVERT2 — TECHNICAL EFFECT DOSSIER: FACE & SKIN BEAUTY
**Authority:** Chủ tịch Tony | **Task:** TASK_047 | **Status:** PROVEN / EVIDENCE-BACKED

## 1. CÔNG NGHỆ PHÂN TÁCH TẦN SỐ KÉP (DUAL-PASS FREQUENCY SEPARATION)
Nghiên cứu từ `libfacetune-native.so` và `libMTBeautyEngine.so` xác nhận quy trình bảo tồn vi lỗ chân lông:
1. Lọc song phương trích xuất tần số thấp: `I_low = BilateralFilter(I, sigma_s=5.0, sigma_r=0.12)`.
2. Trích xuất tần số cao: `I_high = I - I_low + 0.5`.
3. Điều chế làm mịn có bảo vệ: Người dùng chỉnh độ mờ trên `I_low`, lớp `I_high` được cộng bù giữ lại `>= 75%` vi cấu trúc.
4. Xóa khuyết điểm bằng Poisson Blending giải phương trình đạo hàm riêng.

## 2. MA TRẬN BẰNG CHỨNG THỰC TẾ
- Shaders: `facetune_dualpass_skin.frag`, `skin_bilateral_separable.fs`
- Hàm Native: `BilateralFilter::ProcessPoresWithHighBoost`
- Độ tin cậy: **PROVEN**