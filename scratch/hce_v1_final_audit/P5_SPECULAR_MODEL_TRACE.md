# P5 ANISOTROPIC SPECULAR ENGINE — MODEL TRACE & DISCLOSURE
**Document ID:** HCE-V1-P5-TRACE-01  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** Development Workspace Standard V2.1  
**Status:** AUDITED (SCOPE QUALIFIED)  

---

## 1. LÀM RÕ CẤP ĐỘ TRIỂN KHAI MÔ HÌNH (ISSUE E7 DISCLOSURE)
1. **Định danh chính xác mô hình:** Triển khai trong file `hair_anisotropic_specular_engine.cpp` là:
   **"Mô hình xấp xỉ Thùy R bất đẳng hướng cảm hứng từ Marschner (Marschner-inspired R-lobe anisotropic highlight approximation)"**.
2. **Khẳng định kiểm toán:** Đây **KHÔNG PHẢI** là mô hình Marschner 3D đầy đủ (vốn yêu cầu ray-tracing tán xạ đa thùy $R, TT, TRT$ xuyên qua lớp tủy và biểu bì sợi tóc).
3. **Loại bỏ overclaim:**
   - Cấm dùng từ *"Full Marschner model"*.
   - Khẳng định *"Loại bỏ hoàn toàn bóng nhờn kiểu mũ bảo hiểm (helmet shine)"* được chuẩn hóa thành: *"Loại bỏ bóng nhờn kiểu mũ bảo hiểm trên toàn bộ 62 mẫu canonical đã kiểm thử nhờ căn chỉnh vệt sáng theo hướng tiếp tuyến P1"*.

---

## 2. TRẢI VẾT MÃ NGUỒN C++ THỰC TẾ (SOURCE CODE TRACE)
Vị trí file: `lib-core-graphics/src/main/cpp/src/hair/hair_anisotropic_specular_engine.cpp`  
Hàm thực thi: `HairAnisotropicSpecularEngine::applySpecular(...)` (Dòng 30–110)

Công thức toán học thực thi:
$$I_{\text{specular}}(x, y) = k_s \cdot \exp\left( -\frac{(\theta_h - \alpha_r)^2}{2 \beta_r^2} \right) \cdot \cos(\phi_d / 2) \cdot M_{\text{highlight}}(x, y)$$
*Trong đó:*
- $\theta_h$: Góc giữa vector nửa hướng sáng và vector tiếp tuyến sợi tóc $\mathbf{t}_{\text{P1}}$.
- $\alpha_r$: Góc nghiêng vảy biểu bì tóc (Cuticle tilt angle, mặc định $-3.0^\circ$).
- $\beta_r$: Độ rộng góc phân kỳ của thùy phản xạ R (Lobe roughness width, mặc định $8.5^\circ$).
- $k_s$: Hệ số phản xạ điện môi Fresnel (Dielectric specular intensity).
- Neo giữ điểm sáng (Highlight Anchor): Điểm sáng chỉ xuất hiện tại vùng tóc có tương phản ánh sáng thực tế từ pha P3 ($M_{\text{highlight}} > 0$).
