# SoftHairFilter & Pegtop SoftLight — Bộ Hòa Trộn Màu Nhuộm Bảo Toàn Sợi
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ RVA:** `0x0009c310`  
**Biểu tượng C++:** `MTFilterKernel::CSoftHairBlending::ApplyPegtopMap(unsigned char const*, unsigned char const*, unsigned char*, int, int, float)`  
**Độ tin cậy:** `PROVEN_RAW_DISASM`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Phân Tích Công Thức Pegtop Soft Light
Thuật toán hòa trộn màu tóc không dùng Photoshop standard soft light (vốn có điểm kỳ dị đạo hàm tại $0.5$) mà triển khai công thức mượt mà Pegtop:
$$f(A, B) = egin{cases} 2AB + A^2(1 - 2B), & B < 0.5 \ 2A(1 - B) + \sqrt{A}(2B - 1), & B \ge 0.5 \end{cases}$$
Trong đó:
- $A \in [0, 1]$: Giá trị màu nền tóc sau khi triệt sắc và lọc hướng sợi LIC.
- $B \in [0, 1]$: Giá trị màu nhuộm từ bảng màu palette hoặc bản đồ gradient.
- $f(A, B)$: Giá trị điểm ảnh sau hòa trộn, bảo đảm không bị cháy sáng (blown highlights) và không bị mất chi tiết vùng tối (crushed shadows).
