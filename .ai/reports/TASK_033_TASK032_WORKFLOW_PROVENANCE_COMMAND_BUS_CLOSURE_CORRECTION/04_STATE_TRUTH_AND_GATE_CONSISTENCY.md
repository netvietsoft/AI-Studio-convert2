# 04 - TÍNH NHẤT QUÁN TRẠNG THÁI VÀ CÁC CỔNG NGHIỆM THU (STATE TRUTH & GATE CONSISTENCY)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_033 — TASK032 WORKFLOW PROVENANCE & COMMAND BUS CLOSURE CORRECTION`  

---

## 1. NGUYÊN TẮC BẤT BIẾN TỐI CAO: CHỐNG PASS GIẢ TẠO
Theo quy định tại `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` và bộ kiểm thử `tests/test_state_truth_and_gate_consistency.py`:
1. **Bất biến 1 (Invariant 1):** Nếu bất kỳ cổng ngoại vi nào (`confirmation_gate`, `owner_visual_gate`, `report_drive_mirror_verdict`) chưa đạt trạng thái `PASS`, trường `verdict` của hệ thống **TUYỆT ĐỐI KHÔNG ĐƯỢC LÀ PASS**.
2. **Bất biến 2 (Invariant 2):** Trực quan của Chủ tịch Tony là Ground Truth duy nhất cho kết quả nghiệm thu cuối cùng. Khi chưa có xác nhận trực quan từ Chủ tịch, hệ thống chỉ được phép ở trạng thái:
   $$\mathbf{task\_status = verdict = TECHNICAL\_PASS\_AWAITING\_OWNER\_VISUAL}$$
   và
   $$\mathbf{owner\_visual\_acceptance\_status = PENDING\_OWNER\_EVALUATION}$$
3. **Bất biến 3 (Invariant 3):** Tính nhất quán giữa các trường:
   - `task_status` không được chứa `COMPLETE` khi chưa vượt qua cổng thị giác.
   - `verdict` phản ánh đúng tính chất kỹ thuật đã xong nhưng đang đợi thẩm định thực tế.

---

## 2. KẾT QUẢ KIỂM THỬ TÍNH NHẤT QUÁN TRẠNG THÁI
Bộ kiểm thử tự động `tests/test_state_truth_and_gate_consistency.py` đã được chạy trực tiếp trên môi trường và đạt kết quả:

```
test_package_sha256_truthfulness: PASS
test_simulated_false_pass_rejection: PASS
test_task_status_verdict_coherence: PASS
test_verdict_cannot_be_pass_when_confirmation_gate_active: PASS
test_verdict_cannot_be_pass_when_report_mirror_unresolved: PASS

Total: 5/5 Tests PASS (100%)
```

---

## 3. ĐIỀU CHỈNH TRẠNG THÁI TOÀN CỤC (.ai/state.json)
Để đảm bảo truy xuất nguồn gốc chính xác:
1. `last_completed_task_id`: chuyển thành `TASK_033_TASK032_WORKFLOW_PROVENANCE_COMMAND_BUS_CLOSURE_CORRECTION_ACTIVE`.
2. `last_report_folder`: `.ai/reports/TASK_033_TASK032_WORKFLOW_PROVENANCE_COMMAND_BUS_CLOSURE_CORRECTION`.
3. `last_target_commit_sha`: `3da5ebbc22004e4d2186f87f809e270b5f7c29f2` (tuân thủ định dạng Full 40-char SHA).
4. `task_lifecycle`: bổ sung các mốc `TASK_033_DISPATCHED`, `TASK_033_EXECUTING`, `TASK_033_COMPLETED`.
5. `provenance`: cập nhật đầy đủ mã lệnh điều phối `TASK_033...`, dispatch commit `f085e808119e7f6b209f15c2269275dc4b719cdf`, runner `CONVERT2-WINDOWS-03`, GitHub Run ID `37157772171`.
6. `git`: bổ sung các mốc commit `task_031_implementation_sha`, `task_032_correction_sha`, `task_033_closure_sha`.
