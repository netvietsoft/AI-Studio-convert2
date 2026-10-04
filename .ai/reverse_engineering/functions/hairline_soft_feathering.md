# FUNCTION SPECIFICATION: MakeupHairSoftPart_Feather (0x000a2410)
**Thư viện:** `libMTFilterKernel.so`  
**Địa chỉ nạp:** `0x000a2410`  
**Ký hiệu:** `_ZN7meitu24MakeupHairSoftPartFilter16FeatherEdgeAlphaEPNS_12RenderContextE`  
**GNU Build-ID:** `05d25f33b47237df48aab961ae026386d69fa8eb`  
**Mã băm SHA-256:** `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`  

---

## 1. MÔ TẢ CHỨC NĂNG
Hàm tính toán trọng số hòa trộn biên tiếp giáp da - tóc tại chân tóc, vành tai và cổ áo. Sử dụng ma trận trọng số Gauss 5 điểm bất đối xứng theo phương vuông góc với tiếp tuyến biên để tạo chuyển tiếp mềm mại tự nhiên, triệt tiêu viền đen (dark halo) và bảo vệ tuyệt đối vùng da mặt không can thiệp.

---

## 2. DỮ LIỆU ĐẦU VÀO VÀ ĐẦU RA
- `srcHairMask`: Texture mặt nạ nhị phân hoặc thô BiSeNet Class 17.
- `srcFaceSkinMask`: Texture mặt nạ da mặt Class 1.
- `outFeatheredMask`: FBO chứa mặt nạ alpha chính xác từng pixel với dải chuyển tiếp $\sigma = 1.25\text{ px}$.

---

## 3. CALLER & CALLEE
- **Caller:** `MakeupHairSoftPart::ProcessHairSoftEdge` (0x000a12e0).
- **Callee:** `meitu::math::GaussianKernel1D`, `glDrawArrays`.
