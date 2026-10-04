# MTSoftHairFilter::renderToTextureWithVerticesAndTextureCoordinates
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ offset:** `0x000f3f58`  
**Kích thước hàm:** 896 bytes (ARM64)  
**Quyền sở hữu:** P0 Core Hair Color Engine  

### 1. Phân tích Luồng Điều Khiển (Control Flow Graph)
Hàm điều phối chuỗi 5 FBO passes tuần tự:
1. `grayFilterToFBO` (offset `0x000f42fc`): Trích xuất Luminance.
2. `hairMaskFilterToFBO` (offset `0x000f4400`): Cắt lọc mặt nạ tóc và làm mềm biên.
3. `blurHFilterToFBO` (offset `0x000f4528`): Tách lọc Gauss 1D nằm ngang.
4. `blurVFilterToFBO` (offset `0x000f46d0`): Tách lọc Gauss 1D thẳng đứng.
5. `softHairFilterToFBO` (offset `0x000f4878`): Hòa trộn Pegtop SoftLight và Unsharp Mask với canvas `962.0f x 1280.0f`.
