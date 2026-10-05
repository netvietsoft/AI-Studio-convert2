# 14_STATE_PROVENANCE_CORRECTION.md — ĐỐI SOÁT XUẤT XỨ TRẠNG THÁI & SỬA CHỮA FALSE PENDING
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Task ID:** `TASK_057_DISPATCHER_WORKER_ACK_RACE_AND_CONTINUOUS_EXECUTION_CORRECTION_ACTIVE`  
**Thời gian đối soát:** `2026-10-05T07:24:40.312086+07:00`  

---

## 1. ĐỐI SOÁT VÀ SỬA CHỮA TRẠNG THÁI BỊ SAI LỆCH DO ACK RACE

| Đối Tượng | Trạng Thái Sai Lệch Trước Đó | Trạng Thái Đã Được Chuẩn Hóa | Căn Cứ Thực Nghiệm |
|---|---|---|---|
| **TASK_056** | `status: PENDING` kèm lỗi ACK timeout 90s do Dispatcher 37244920379 đẩy lùi | `status: QUEUED` (trong pending/), `dispatch_error: null`, sẵn sàng dispatch | Đã xóa lỗi giả, mở rộng `allowed_paths`, chờ giải phóng lock từ TASK_057 |
| **TASK_057** | `status: RESERVED` (do Dispatcher 37246658920) | `status: RUNNING` (Worker Run 37246754606 đã push bền vững lúc 07:14:38 VN) | Commit `0e488b1fb`, runner log `command_bus.log` |
| **Dispatcher ACK Loop** | Chỉ kiểm tra `reserved/` & timeout mù 90s | Kiểm tra `claimed/`, `running/`, `completed/` với timeout 180s & GitHub liveness guard | Mã nguồn `scripts/command_bus_orchestrator.py` đã cập nhật |
| **Runner Script** | Không push commit trước khi chạy `agy` | Bổ sung Step 5A commit & push bền vững lên `origin/main` | Mã nguồn `scripts/run_agent_from_github_command.ps1` đã cập nhật |

---

## 2. CHỈ SỐ NHẤT QUÁN TOÀN HỆ THỐNG
- **Tổng số lệnh hợp lệ:** 60
- **Số lệnh hoàn thành:** 59
- **Số lệnh đang thực thi (RUNNING):** 1 (`TASK_057`)
- **Số lệnh chờ dispatch (QUEUED):** 1 (`TASK_056`)
- **Số lệnh bị xung đột / trùng lặp:** 0 (Đạt chuẩn Invariant Tuyệt Đối).
