# optical_flow_temporal_hair_stabilizer.md — BỘ LỌC ỔN ĐỊNH MÀU NHUỘM THEO THỜI GIAN QUA DÒNG QUANG HỌC (TEMPORAL CONSISTENCY)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Phân hệ:** Core C++ Native Video/Image Engine / Temporal Anti-Flicker  
**Thư viện tham chiếu:** `libffmpegfilter.so` (0x00090000 - 0x000b5000), `libMTFilterKernel.so`  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. VẤN ĐỀ HIỆN TƯỢNG NHẤP NHÁY (TEMPORAL JITTER & FLICKER)
Khi xử lý video hoặc chuỗi khung hình camera preview (Live Preview 60 FPS), mạng nơ-ron phân đoạn mặt nạ tóc và thuật toán tính toán ten-xơ cấu trúc có thể dao động nhẹ từ khung hình $t-1$ sang khung hình $t$ do nhiễu hạt cảm biến (sensor noise). Sự dao động sub-pixel này gây ra hiện tượng nhấp nháy màu nhuộm (color flickering / boiling artifacts) gây khó chịu cho người dùng.

Để giải quyết vấn đề này, động cơ sử dụng bộ lọc ổn định nhất quán thời gian dựa trên **Dòng Quang Học (Optical Flow Reprojection)** kết hợp với cơ chế **Kẹp Lịch Sử (Neighborhood History Clamping)**.

---

## 2. KIẾN TRÚC VÀ CÔNG THỨC TOÁN HỌC

1. **Ước lượng Vector Chuyển Động Dòng Quang Học:**
   Với mỗi điểm ảnh $\mathbf{p} = (x, y)$ tại khung hình hiện tại $t$, tính vector chuyển động $\mathbf{v}(\mathbf{p}) = (u, v)$ trỏ về vị trí tương ứng tại khung hình trước $t-1$:
   $$\mathbf{p}_{\text{prev}} = \mathbf{p} - \mathbf{v}(\mathbf{p})$$

2. **Tái Lấy Mẫu Khung Hình Trước (History Reprojection):**
   $$C_{\text{history}} = \text{SampleBilinear}(F_{t-1}, \mathbf{p}_{\text{prev}})$$

3. **Kẹp Vùng Giá Trị Màu (Neighborhood Color Clamping):**
   Để tránh hiện tượng bóng ma (ghosting artifacts) khi người chuyển động quá nhanh hoặc tóc bị che khuất, xây dựng hộp bao màu (Color Bounding Box) tại lân cận $3 \times 3$ của điểm ảnh hiện tại:
   $$\mathbf{C}_{\min} = \min_{q \in \mathcal{N}_3(\mathbf{p})} C_t(q), \quad \mathbf{C}_{\max} = \max_{q \in \mathcal{N}_3(\mathbf{p})} C_t(q)$$
   $$\hat{C}_{\text{history}} = \operatorname{clamp}(C_{\text{history}}, \mathbf{C}_{\min}, \mathbf{C}_{\max})$$

4. **Hòa Trộn Tích Lũy Thời Gian (Temporal Accumulation):**
   $$C_{\text{stabilized}}(\mathbf{p}) = \gamma \cdot C_t(\mathbf{p}) + (1 - \gamma) \cdot \hat{C}_{\text{history}}$$
   Trong đó hệ số phản hồi $\gamma \in [0.15, 0.25]$ được điều chỉnh động theo độ lớn gia tốc chuyển động $\|\mathbf{v}(\mathbf{p})\|$.

---

## 3. LỢI ÍCH TRÊN THIẾT BỊ DI ĐỘNG (GALAXY A50 / HELIO G99)
- Giữ vững 60 FPS mượt mà cho camera live preview và video recording.
- Màu tóc không bị trôi hay giật viền khi người dùng lắc đầu hoặc xoay camera.
- 100% tuân thủ tiêu chuẩn không lem da trán và bảo vệ tuyệt đối vùng không can thiệp.
