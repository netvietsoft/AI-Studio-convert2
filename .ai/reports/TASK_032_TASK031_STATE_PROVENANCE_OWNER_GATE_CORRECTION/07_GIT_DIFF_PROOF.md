# 07 - BẰNG CHỨNG KIỂM TOÁN GIT DIFF VÀ BẢO VỆ MÃ NGUỒN C++ (GIT DIFF PROOF)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_032 — TASK031 STATE/PROVENANCE TRUTH & OWNER VISUAL GATE CORRECTION`  

---

## 1. YÊU CẦU BẢO TOÀN THUẬT TOÁN HAIRPIPELINEV2
Theo chỉ thị bắt buộc số 6 trong TASK_032:
> *"HairPipelineV2 functional diff must remain zero during this provenance/state correction."*

Nhiệm vụ `TASK_032` là nhiệm vụ hiệu chỉnh sự thật trạng thái, nguồn gốc và cổng nghiệm thu (Provenance, State Truth & Gate Correction). Tuyệt đối không can thiệp, không sửa đổi logic, không thay đổi tham số quang học trong lõi C++ Native.

---

## 2. BẰNG CHỨNG KIỂM TOÁN LÕI C++ NATIVE GRAPHICS ENGINE
Thực thi kiểm tra toàn bộ cây thư mục mã nguồn C++ Core:

```powershell
git diff origin/main -- lib-core-graphics/
```

**Kết quả trả về:**
```text
(0 dòng thay đổi — Hoàn toàn sạch và nguyên vẹn)
```

Kiểm tra thêm toàn bộ thư mục C++ khác:
- `lib-ai-engine/`: 0 diff
- `lib-photo-editor/`: 0 diff
- `lib-video-engine/`: 0 diff
- `lib-roboneo/`: 0 diff

---

## 3. DANH SÁCH CÁC TỆP ĐƯỢC ĐIỀU CHỈNH TRONG PHẠM VI TASK_032
Mọi thay đổi trong phiên làm việc này chỉ giới hạn nghiêm ngặt trong phạm vi siêu dữ liệu và báo cáo kiểm toán được ủy quyền:
1. `.ai/reports/TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE/`:
   - `01_MASTER_REPORT.md` (Cập nhật dung lượng 200,228,766 bytes, APK SHA-256 `8F23EAF6...`, commit nguồn `beaa5fe385cc...`)
   - `02_APK_PROVENANCE_AND_BUILD_EVIDENCE.md` (Cập nhật dung lượng, SHA-256, commit nguồn và dumpsys thật)
   - `06_EXECUTION_TIMING_LOG.json` (Đồng bộ từ `raw/execution_timing_log.json` với độ trễ thật)
   - `09_FINAL_MASTER_VERDICT.md` (Xác lập `TECHNICAL_PASS_AWAITING_OWNER_VISUAL`)
   - `raw/sm_a075f_device_proof.txt` (Khôi phục dữ liệu gốc `8F23EAF6...`)
   - `raw/sm_a507fn_device_proof.txt` (Khôi phục dữ liệu gốc `8F23EAF6...`)
   - `TASK_031_EVIDENCE_MANIFEST.sha256` (Tái tạo manifest)
   - `CONVERT2_TASK031_REPORT_PACKAGE.zip` (Đóng gói lại)
2. `.ai/state/tasks/`:
   - `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_AND_FINAL_APK_TEST_ACTIVE.json`
   - `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_FINAL_APK_TEST_ACTIVE.json`
   - `TASK_032_TASK031_STATE_PROVENANCE_OWNER_GATE_CORRECTION_ACTIVE.json` (Mới)
3. `.ai/commands/`:
   - `completed/TASK_032_TASK031_STATE_PROVENANCE_OWNER_GATE_CORRECTION_20261004T050000+0700.json` (Mới)
   - `history/TASK_032_TASK031_STATE_PROVENANCE_OWNER_GATE_CORRECTION_20261004T050000+0700.json` (Mới)
   - `index.json` (Cập nhật)
4. `.ai/state.json`:
   - Cập nhật `verdict: "TECHNICAL_PASS_AWAITING_OWNER_VISUAL"`
   - Cập nhật `task_status: "TECHNICAL_PASS_AWAITING_OWNER_VISUAL"`
   - Bổ sung `task_032_summary`
5. `TASK_LOG.md`:
   - Ghi nhận nhật ký phiên hoàn thành `TASK_032`.
6. `.ai/reports/TASK_032_TASK031_STATE_PROVENANCE_OWNER_GATE_CORRECTION/`:
   - Toàn bộ hồ sơ báo cáo kiểm toán của nhiệm vụ.
