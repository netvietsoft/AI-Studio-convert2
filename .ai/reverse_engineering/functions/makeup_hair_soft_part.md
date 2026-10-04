# MakeupHairSoftPart — Bộ Hòa Trộn Mềm Viền Chân Tóc & Vùng Tiếp Giáp Da
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ RVA:** `0x000a12e0`  
**Biểu tượng C++:** `MTFilterKernel::CMakeupHairMatcher::BlendScalpHairline(unsigned char const*, unsigned char const*, unsigned char*, int, int)`  
**Độ tin cậy:** `STRONG_INFERENCE`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Cơ Chế Chống Lem Vùng Biên Chân Tóc
Vấn đề nan giải nhất của thuật toán nhuộm tóc là đường ranh giới cắt sắc nhọn tại trán, thái dương, mang tai và cổ áo.
`MakeupHairSoftPart` giải quyết bằng quy trình 3 bước:
1. Tính khoảng cách có hướng (Signed Distance Field - SDF) từ ranh giới mặt nạ tóc ra ngoài $8$ pixels.
2. Áp dụng hàm suy giảm làm mềm hàm mũ bậc 3 (Hermite smoothstep):
   $$lpha_{	ext{feather}} = \operatorname{smoothstep}(0.0, 1.0, rac{	ext{dist} - d_{	ext{inner}}}{d_{	ext{outer}} - d_{	ext{inner}}})$$
3. Phối trộn sắc thái da trán tự nhiên với các sợi tóc con (baby hair) siêu nhỏ, bảo đảm không tạo ra viền bẩn hay lem da mặt.
