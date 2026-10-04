# Thuật Toán Nội Suy Màu Khối 3D LUT Chuẩn Adobe .CUBE
**Phân hệ:** P1 Color & LUT Engine  

### 1. Nội suy 3 đoạn (Trilinear Interpolation)
$$C(r, g, b) = \sum_{i,j,k \in \{0,1\}} (1 - |r - i|)(1 - |g - j|)(1 - |b - k|) \cdot \text{LUT}[i, j, k]$$
Bảo đảm chuyển màu mượt mà, không giật bậc thang.
