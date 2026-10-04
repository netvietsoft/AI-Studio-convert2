# CONVERT2 — TECHNICAL EFFECT DOSSIER: PROTECTED BODY RESHAPE
**Authority:** Chủ tịch Tony | **Task:** TASK_047 | **Status:** PROVEN / EVIDENCE-BACKED

## 1. NGUYÊN LÝ KHÓA NỀN TUYỆT ĐỐI (ZERO BACKGROUND DISTORTION)
Nghiên cứu từ `libMTBeautyEngine.so` (`MTBeautyEngine::LiquifyWithProtectionMask`):
Biến dạng điểm ảnh được điều chế bằng mặt nạ cơ thể người `M_body`:
$$\Delta \vec{p}_{\text{effective}} = \Delta \vec{p} \cdot \left( 1 - \left( \frac{\|\vec{p} - \vec{c}\|}{R} \right)^2 \right)^3 \cdot M_{\text{body}}(\vec{p})$$
- Trong vùng cơ thể (`M_body = 1.0`): Lực kéo đạt 100%.
- Trong vùng nền (`M_body = 0.0`): Vector dịch chuyển bằng 0 tuyệt đối, nền gạch và tường không bị méo.

## 2. MA TRẬN BẰNG CHỨNG THỰC TẾ
- Shaders: `body_mesh_warp.vs`
- JNI Bridge: `Java_com_meitu_beauty_BodyEngineJNI_nativeDeformMesh`
- Độ tin cậy: **PROVEN**