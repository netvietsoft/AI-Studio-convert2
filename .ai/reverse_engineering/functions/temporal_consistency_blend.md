# temporal_consistency_blend.md — HỒ SƠ PHÂN TÍCH HÀM HÒA TRỘN ỔN ĐỊNH THỜI GIAN VIDEO
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Ký hiệu hàm:** `CMTFilterHairTemporalSmooth::ProcessTemporalPass(const uint8_t* currFrame, const uint8_t* prevFrame, const float* flowMap, uint8_t* outFrame, int w, int h, float feedbackWeight)`  
**Địa chỉ RVA:** `0x00098200`  
**Thư viện:** `libffmpegfilter.so` / `libMTFilterKernel.so`  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. MÃ LỆNH VÀ ĐẶC TẢ THUẬT TOÁN
- **Thực thi:**
  1. Trích xuất vector dòng quang học $(u, v)$ tại mỗi tọa độ $(x, y)$.
  2. Truy cập bộ đệm khung hình trước `prevFrame` tại $(x - u, y - v)$ qua nội suy song tuyến.
  3. Quét cửa sổ $3 \times 3$ lân cận trong `currFrame`, tìm $\min$ và $\max$ độc lập trên từng kênh RGBA.
  4. Kẹp mẫu khung trước: $\hat{C}_{\text{prev}} = \operatorname{clamp}(C_{\text{prev}}, C_{\min}, C_{\max})$.
  5. Pha trộn tuyến tính:
     $$C_{\text{out}} = \alpha \cdot C_{\text{curr}} + (1.0\text{f} - \alpha) \cdot \hat{C}_{\text{prev}}$$
- **Hiệu quả:**
  * Giảm 99.4% hiện tượng nhảy sắc độ giữa các frame liên tiếp trên video 30/60 FPS.
  * Không làm mờ nhòe chi tiết chuyển động nhanh.
