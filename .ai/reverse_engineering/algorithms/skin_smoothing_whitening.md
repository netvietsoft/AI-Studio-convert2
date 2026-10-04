# Thuật Toán Làm Mịn Da Song Phương & Bảo Tồn Lỗ Chân Lông
**Phân hệ:** P1 Face Beauty Engine  

### 1. Lọc song phương bảo tồn kết cấu vi mô (Bilateral Filter)
$$I_{smooth}(p) = \frac{1}{W_p} \sum_{q \in \Omega} I(q) f_r(\|I(p) - I(q)\|) g_s(\|p - q\|)$$
Giữ lại $>75\%$ kết cấu lỗ chân lông vi mô (micro-pores) theo tiêu chuẩn hiến pháp GEMINI.md.
