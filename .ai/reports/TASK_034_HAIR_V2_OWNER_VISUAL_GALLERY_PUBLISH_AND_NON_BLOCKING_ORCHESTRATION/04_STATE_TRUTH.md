# 04 - XÁC LẬP CHÂN LÝ TRẠNG THÁI (STATE TRUTH)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_034 — HAIR V2 OWNER VISUAL GALLERY PUBLISH & NON-BLOCKING ORCHESTRATION`  
**Thẩm quyền:** Chủ tịch Tony (Chairman Tony)  
**Tiêu chuẩn:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Thời gian hoàn thành:** 2026-10-04 07:55:00 +07:00  

---

## 1. NGUYÊN TẮC CỐT LÕI VỀ CHÂN LÝ TRẠNG THÁI (CANONICAL RULES)
1. **Tuyệt đối không tự phong PASS (Zero Self-Certification):**
   - Chỉ duy nhất Chủ tịch Tony mới có thẩm quyền chuyển `owner_visual_acceptance_status` từ `PENDING_OWNER_EVALUATION` sang `APPROVED` hoặc `REJECTED`.
   - Hệ thống nghiêm cấm ghi `verdict: PASS` hoặc `FINAL_PASS` trước khi có sự phê chuẩn rõ ràng bằng văn bản của Chủ tịch.
2. **Trạng thái kỹ thuật chính xác:**
   - `verdict` = `TECHNICAL_PASS_AWAITING_OWNER_VISUAL`
   - `task_status` = `TECHNICAL_PASS_AWAITING_OWNER_VISUAL`
   - `owner_visual_gate` = `AWAITING_CHAIRMAN_TONY_REVIEW`
3. **Cờ máy đọc minh bạch (Machine-Readable Truth):**
   - Trường boolean `owner_visual_evidence_ready` = `true` chỉ được bật sau khi kiểm toán toàn bộ 210/210 tệp hình ảnh thực tế trên ổ cứng (Workstream A & B hoàn tất).
   - Trường `owner_visual_gallery_url` trỏ trực tiếp đến `https://github.com/netvietsoft/AI-Studio-convert2/blob/main/OWNER_VISUAL_GALLERY_HAIR_V2.md`.
   - Trường `owner_visual_gallery_path` trỏ đến `TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/index.html`.
4. **Phạm vi cổng hẹp (Scoped Gate Semantics):**
   - Trạng thái chờ Chủ tịch thẩm định chỉ áp dụng cho bước ký duyệt cuối cùng của Hair V2.
   - Các tác vụ và luồng độc lập khác (Hạ tầng, báo cáo, đồng bộ, bảo trì) hoàn toàn không bị ảnh hưởng, có thể được cấp phát (`RESERVED`) và thực thi bình thường.

---

## 2. NỘI DUNG TRẠNG THÁI THỰC TẾ TRONG `.ai/state.json`

```json
{
  "project": "CONVERT2_HAIR_COLOR_ENGINE",
  "version": "2.2.5",
  "agent_state": "IDLE_WAIT_FOR_TASK",
  "task_status": "TECHNICAL_PASS_AWAITING_OWNER_VISUAL",
  "verdict": "TECHNICAL_PASS_AWAITING_OWNER_VISUAL",
  "owner_visual_acceptance_status": "PENDING_OWNER_EVALUATION",
  "owner_visual_evidence_ready": true,
  "owner_visual_gallery_url": "https://github.com/netvietsoft/AI-Studio-convert2/blob/main/OWNER_VISUAL_GALLERY_HAIR_V2.md",
  "owner_visual_gallery_path": "TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/index.html",
  "owner_visual_gate": "AWAITING_CHAIRMAN_TONY_REVIEW",
  "last_completed_task_id": "TASK_034_HAIR_V2_OWNER_VISUAL_GALLERY_PUBLISH_AND_NON_BLOCKING_ORCHESTRATION_ACTIVE",
  "last_report_folder": ".ai/reports/TASK_034_HAIR_V2_OWNER_VISUAL_GALLERY_PUBLISH_AND_NON_BLOCKING_ORCHESTRATION"
}
```
