# GrayFilter (CMTFilterGrayEye) — Thuật Toán Triệt Sắc Nền & Trung Hòa Sắc Tố Tự Nhiên
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ RVA:** `0x0008ebd4`  
**Biểu tượng C++:** `MTFilterKernel::CMTFilterGrayEye::ApplyFilter(unsigned char const*, unsigned char*, int, int)`  
**Độ tin cậy:** `PROVEN_RAW_DISASM`  
**Mức độ trưởng thành:** `PSEUDOCODE_RECOVERED`  

---

## 1. Mục Đích & Nguyên Lý Quang Học
Khi nhuộm tóc trên nền tóc người châu Á (vốn có lượng sắc tố Eumelanin sẫm màu rất cao), việc áp trực tiếp màu nhuộm (đặc biệt là các màu sáng, pastel, bạch kim, vàng hồng) sẽ dẫn tới hiện tượng lem đục và ám màu đen/vàng bùn khó chịu.
`GrayFilter` thực hiện nhiệm vụ quang học:
1. Tính toán giá trị độ chói tương đối (relative luminance) theo chuẩn ITU-R BT.601:
   $$Y = 0.299 \cdot R + 0.587 \cdot G + 0.114 \cdot B$$
2. Trung hòa sắc tố màu nền của từng sợi tóc về thang xám có cùng mức năng lượng quang học:
   $$\mathbf{C}_{	ext{gray}} = [Y, Y, Y]^T$$
   $$\mathbf{C}_{	ext{neutral}} = (1 - lpha_{	ext{desat}}) \cdot \mathbf{C}_{	ext{orig}} + lpha_{	ext{desat}} \cdot \mathbf{C}_{	ext{gray}}$$
3. Bảo toàn 100% độ tương phản cục bộ của các thớ tóc, chuẩn bị lớp nền lý tưởng để đón nhận bảng màu nhuộm đa tầng.
