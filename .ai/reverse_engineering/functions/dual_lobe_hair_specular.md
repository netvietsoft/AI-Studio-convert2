# dual_lobe_hair_specular.md — HỒ SƠ PHÂN TÍCH HÀM TÍNH TOÁN ÁNH KIM LỌN TÓC ĐA THÙY
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Ký hiệu hàm:** `LayerFlow::EvaluateDualLobe(const float* tangentField, const float* lightVec, const float* viewVec, float* outSpecularR, float* outSpecularTRT, int pixelCount)`  
**Địa chỉ RVA:** `0x0007b420`  
**Thư viện:** `libLayerFlow.so` (Build-ID: `9166d17d6c8c5a7ba9047760806b5fe63866e48b`)  
**Trạng thái Pháp lý:** **RULE 11 CLEAN-ROOM SPECIFICATION**  

---

## 1. MÃ LỆNH VÀ ĐẶC TẢ THUẬT TOÁN ARM64
- **Cơ chế tính toán:**
  1. Nạp vector tiếp tuyến sợi tóc $\mathbf{T} = (\cos \theta, \sin \theta, 0)$ thu được từ Stage 4 (Ten-xơ cấu trúc góc kép).
  2. Tính tích vô hướng $\sin \theta_i = \mathbf{T} \cdot \mathbf{L}$ và $\sin \theta_r = \mathbf{T} \cdot \mathbf{V}$ bằng lệnh `FMUL.4s` và `FADD.4s`.
  3. Lệch góc biểu bì:
     $$\theta_{h, R} = \theta_h - 0.055\text{f}, \quad \theta_{h, TRT} = \theta_h + 0.110\text{f}$$
  4. Lũy thừa Gauss nhanh (Fast Gaussian Exponentiation via Taylor Series hoặc texture lookup LUT 1D 256x1).
- **Kết quả xuất xưởng:**
  * `outSpecularR`: Độ sáng ánh bạc phản xạ lớp vảy ngoài.
  * `outSpecularTRT`: Độ sáng ánh kim màu phản xạ lõi sợi tóc.
