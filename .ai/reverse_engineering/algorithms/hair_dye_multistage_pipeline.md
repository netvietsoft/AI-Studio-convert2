# Thuật Toán Nhuộm Tóc Đa Tầng 8 Giai Đoạn (Hair Dye Multi-Stage Pipeline)
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Mức độ Hoàn Thiện:** `CLEANROOM_SPEC_VERIFIED`  

---

## 1. Phương Trình Toán Học Tổng Thể
$$\mathbf{I}_{	ext{final}}(x, y) = (1 - M(x, y)) \cdot \mathbf{I}_{	ext{orig}}(x, y) + M(x, y) \cdot \mathbf{\Psi}(x, y)$$
Trong đó:
- $M(x, y) \in [0, 1]$: Mặt nạ tóc đã làm mềm biên sau lọc BiSeNet Class 17.
- $\mathbf{\Psi}(x, y)$: Hàm tổng hợp quang học đa giai đoạn:
  $$\mathbf{\Psi}(x, y) = 	ext{LUT}_{3D} \Big( 	ext{Pegtop} ig( 	ext{LIC}_{21}(\mathbf{I}_{	ext{neutral}}, 	heta), \mathbf{C}_{	ext{dye}} ig) + \mathbf{S}_{	ext{specular}}(	heta, \mathbf{L}) \Big)$$
