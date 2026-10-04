# FUNCTION SPECIFICATION: MTAnisotropicSpecularShader (0x0009d180)
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ nạp:** `0x0009d180`  
**Ký hiệu:** `_ZN7meitu25MTAnisotropicSpecularShader9RenderPassEPNS_12RenderContextE`  
**GNU Build-ID:** `05d25f33b47237df48aab961ae026386d69fa8eb`  
**Mã băm SHA-256:** `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`  

---

## 1. THÔNG SỐ VÀO RA (I/O)
- `inTexture`: FBO chứa ảnh tóc đã qua hòa trộn Pegtop SoftLight (`s_texture`).
- `inTangentMap`: Texture 2D chứa vector tiếp tuyến tóc $(\cos \phi, \sin \phi)$ trích xuất từ 21-tap LIC (`s_tangent_map`).
- `inHairMask`: Texture 2D chứa alpha mặt nạ tóc sau làm mềm biên (`s_hair_mask`).
- `uShineIntensity`: Giá trị float $[0.0, 1.0]$ điều khiển độ sáng phản quang lọn tóc.
- `uLightDir`: Vector 3 chiều $[0.3, 0.5, 0.8]$ biểu diễn hướng ánh sáng môi trường.

---

## 2. CALLER & CALLEE
- **Caller:** `MTSoftHairFilter::DrawAllPasses` (0x000f3f58) tại Pass 4.
- **Callee:** `glUniform1f`, `glDrawElements`, `meitu::gl::BindFBO`.

---

## 3. PHÂN ĐOẠN KHÍCH LỆ VÀ ĐÁNH GIÁ ĐỘ TRƯỞNG THÀNH
- **Maturity:** `LOGIC_RECOVERED` -> `PSEUDOCODE_RECOVERED`.
- **Confidence:** `PROVEN` (Trích xuất từ chuỗi FBO và bảng lệnh GLSL nhúng).
