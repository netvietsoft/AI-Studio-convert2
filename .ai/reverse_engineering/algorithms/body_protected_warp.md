# Thuật Toán Biến Dạng Cơ Thể Moving Least Squares Có Bảo Vệ Nền
**Phân hệ:** P1 Body Beauty Engine  

### 1. Moving Least Squares (MLS) Deformation
$$f(v) = (v - p_*) M + q_*$$
Trọng số khoảng cách: $w_i = \frac{1}{\|p_i - v\|^{2\alpha}}$.  
Điểm neo cố định (boundary anchors) giữ cho lưới nền không bị méo lệch dù cơ thể được nắn bóp cục bộ.
