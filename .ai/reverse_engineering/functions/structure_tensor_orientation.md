# LFDenseHairModular::processStructureTensor
**Thư viện:** `libLayerFlow.so`  
**Địa chỉ offset:** `0x000245a0`  
**Vai trò:** Tính toán ma trận ten-xơ cấu trúc góc kép  

### 1. Công thức Toán học Ten-xơ Cấu trúc Góc Kép
$$J = \begin{bmatrix} J_{xx} & J_{xy} \\ J_{xy} & J_{yy} \end{bmatrix}$$
Góc hướng dòng chảy sợi tóc $\theta$:
$$\theta = \frac{1}{2} \operatorname{atan2}(2 J_{xy}, J_{xx} - J_{yy})$$
