# 01_MASTER_REPORT.md — BÁO CÁO ĐIỀU HÀNH & GIẢI TRÌNH KHẮC PHỤC ACK RACE
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Cơ quan thực hiện:** CEO / Agent 0 (Orchestrator)  
**Tiêu chuẩn Vận hành:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Task ID:** `TASK_057_DISPATCHER_WORKER_ACK_RACE_AND_CONTINUOUS_EXECUTION_CORRECTION_ACTIVE`  
**Command ID:** `TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_20261005T065500+0700`  
**Thời gian báo cáo:** `2026-10-05T07:24:40.312086+07:00`  

---

## 1. TỔNG QUAN SỰ CỐ VÀ BỐI CẢNH TÁI HIỆN

Trong quá trình điều phối tự động giữa Dispatcher và Worker ở Task 056, hệ thống quan sát thấy hiện tượng chạy đua xác nhận (Dispatcher/Worker ACK race):
- **Dispatcher Run ID:** `37244920379` (khởi chạy lúc `2026-10-04T23:45:45Z`).
- **Thời điểm đặt trước (Reservation):** Commit `75ef9591cba33583705d9c42f3e17df5502da3a2` lúc `23:47:09Z`.
- **Worker Run ID:** `37245007835` (kích hoạt qua `workflow_dispatch` lúc `23:47:11Z`).
- **Hành vi lỗi:**
  1. Worker nhận việc trên runner `actions-runner-02`, kiểm tra mã nguồn lúc `23:46:35Z`, thực hiện claim nội bộ lúc `23:46:36Z` và chuyển trạng thái sang RUNNING cục bộ lúc `23:46:37Z`.
  2. Tuy nhiên, runner script cũ **không đẩy commit xác nhận (ACK commit) lên nhánh `origin/main`** trước khi tiến hành thực thi dài hạn với `agy`. Thay vào đó, runner chuyển ngay sang nhánh cô lập `agent/TASK_056...`.
  3. Phía Dispatcher chạy trên GitHub-hosted Ubuntu runner kiểm tra `origin/main` trong vòng 90 giây. Do không nhận được commit cập nhật nào từ Worker trên `origin/main`, lúc `23:48:47Z` (sau 98.2 giây), Dispatcher xác định timeout và **tự động đẩy commit `70fbccc6c` đưa command về lại trạng thái `PENDING`** với lỗi:
     `Worker ACK timeout after workflow_dispatch: no durable lease/execution_identity CLAIM observed within 90s`.
  4. Hậu quả: Worker thực tế vẫn đang miệt mài chạy trên nhánh `agent/TASK_056...` suốt 14 phút (hoàn tất lúc `00:00:18Z`), trong khi trạng thái trên `main` bị gán sai thành `PENDING`. Hiện tượng này dẫn tới trạng thái bất nhất nghiêm trọng: một Worker đang chạy hợp lệ nhưng command lại bị xem là `PENDING` và có nguy cơ bị Dispatcher chu kỳ sau kích hoạt Worker thứ hai gây xung đột tài nguyên.

---

## 2. PHÂN TÍCH NGUYÊN NHÂN GỐC (ROOT CAUSES)

Kiểm toán hệ thống đã xác định 5 nguyên nhân gốc rễ:

1. **Thiếu bước công bố xác nhận bền vững (Pre-Execution Remote ACK Push):**
   Trong `run_agent_from_github_command.ps1`, hành động `claim` và `start` chỉ ghi đè file JSON trong thư mục làm việc cục bộ. Worker không có bước đẩy cam kết (lease + execution_identity) lên `origin/main` trước khi phân nhánh tác vụ.
2. **Cơ chế Timeout mù (Blind 90s Timeout without Worker Liveness Check):**
   Trong `command_bus_orchestrator.py` hàm `dispatch_commands`, Dispatcher chỉ đợi đúng 90 giây và nếu không thấy file đổi trên git thì lập tức rollback về `PENDING`. Dispatcher không hề truy vấn API GitHub Actions để xác thực xem worker workflow có đang thực sự chạy (`in_progress`) hay đang xếp hàng (`queued`) hay không.
3. **Tra cứu thư mục thiếu sót trong vòng lặp ACK:**
   Hàm `dispatch_commands` tìm kiếm file trong thư mục `reserved/` và kỳ vọng thấy status `CLAIMED` hoặc `RUNNING`. Nhưng theo quy tắc đơn trạng thái, `claim_command` đã di chuyển file ra khỏi `reserved/` sang `claimed/` rồi `running/`. Khi file biến mất khỏi `reserved/`, vòng lặp chỉ kiểm tra `running/` và `completed/`, bỏ sót trạng thái `claimed/`.
4. **Cổng kiểm tra đường dẫn Integrator quá chặt (BLOCKED_UNAUTHORIZED_PATH):**
   Khi Worker hoàn thành và gửi nhánh để Serial Integrator gộp, Integrator từ chối vì tệp gói báo cáo gốc (`CONVERT2_TASK*.zip`, `*.sha256`) và kho tri thức tái dựng (`.ai/reverse_engineering/**`, `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md`) không nằm trong `allowed_paths` hoặc `SHARED_RECONCILED_PATHS`.
5. **Thiếu cơ chế tiếp nhận lũy tiến / tái phục hồi (Idempotent Recovery):**
   Hàm `claim_command` và `start_command` từ chối thẳng thừng nếu command đã ở trạng thái `RUNNING` thay vì cho phép cùng một runner tiếp tục thực thi an toàn (idempotent resume).

---

## 3. GIẢI PHÁP KIẾN TRÚC ĐÃ TRIỂN KHAI VÀ BẢO CHỨNG

### A. Bổ sung Bước 5A (Durable Worker ACK) trong Runner Script
Trong `scripts/run_agent_from_github_command.ps1`:
Ngay sau khi lệnh chuyển sang `RUNNING` với đầy đủ `lease_token`, `dispatch_commit_sha`, `github_run_id`:
```powershell
if ($env:GITHUB_RUN_ID) {
    Write-RunnerLog "Persisting durable worker ACK to remote main before task execution..."
    git add ".ai/commands" ".ai/state" ".ai/state.json"
    git commit -m "chore(command-bus): durable worker ACK for $targetCmdId [run $env:GITHUB_RUN_ID]" --allow-empty
    git pull --rebase origin main
    git push origin HEAD:main
    Write-RunnerLog "Durable worker ACK is visible on remote main."
}
```
Chứng cứ thực tế: Trên Dispatcher Run `37246658920`, Dispatcher đã phát hiện ngay lập tức xác nhận này từ Worker Run `37246754606`:
`[DISPATCH_ACK] Worker advanced TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_20261005T065500+0700 to running.`
`[DISPATCH_OK] Dispatched and acknowledged TASK_057_DISPATCHER_WORKER_ACK_RACE_CORRECTION_20261005T065500+0700.`

### B. Mở rộng ACK Timeout lên 180s & Bảo vệ Liveness chống False PENDING
Trong `scripts/command_bus_orchestrator.py`:
1. Mở rộng thời gian chờ từ 90s lên 180s để đáp ứng thời gian khởi động của self-hosted runner.
2. Kiểm tra toàn diện cả 3 thư mục: `claimed/`, `running/`, `completed/`.
3. Trước khi thực hiện bất kỳ hành động rollback nào, Dispatcher bắt buộc truy vấn `gh run list --workflow=convert2-worker.yml`. Nếu Worker đang `in_progress` hoặc `queued`, Dispatcher **TUYỆT ĐỐI KHÔNG ROLLBACK** về `PENDING`, bảo lưu lệnh đặt trước và ghi nhận:
   `[DISPATCH_PENDING_GUARD] Worker run is in_progress/queued in GitHub Actions. Preserving reservation to prevent false coexistence with PENDING.`

### C. Triển khai Tính Idempotent cho Claim & Start
1. `claim_command`: Nếu runner hiện tại chính là bên đang nắm giữ lease (`lease_holder == runner_identity`), hàm trả về `IDEMPOTENT_CLAIM` thành công thay vì báo lỗi.
2. `start_command`: Nếu command đã ở `RUNNING` với đúng `lease_token`, trả về `IDEMPOTENT_START` thành công.
3. Runner script `run_agent_from_github_command.ps1` chấp nhận cả `CLAIMED` lẫn `IDEMPOTENT_CLAIM`, `RUNNING` lẫn `IDEMPOTENT_START`.

### D. Cập nhật Quy chuẩn Đường dẫn Tái Hòa Nhập (SHARED_RECONCILED_PATHS)
Bổ sung vào `SHARED_RECONCILED_PATHS` và `is_shared_reconciled_path`:
- Các gói nén báo cáo: `convert2_task*.zip`, `convert2_task*.zip.sha256`.
- Sổ ghi nhận tri thức: `acquirements.md`, `acquirement.md`, `standards.txt`.
Đồng thời, cập nhật `allowed_paths` của `TASK_056` bao gồm `.ai/reverse_engineering/**`, `REVERSE_ENGINEERING_KNOWLEDGE_INDEX.md`, và các gói zip báo cáo để Serial Integrator không còn bị nghẽn đường dẫn.

---

## 4. CHỨNG MINH THỰC NGHIỆM VÀ KẾT QUẢ TEST SUITE

1. Đã bổ sung 3 ca kiểm thử hồi quy nghiêm ngặt vào `tests/test_command_bus_lifecycle_invariants.py`:
   - `test_idempotent_claim_and_start_for_same_runner`: Kiểm tra tính lũy đẳng của claim/start.
   - `test_claim_recovers_from_false_pending`: Kiểm tra khả năng tự sửa chữa và tái xác lập quyền sở hữu của Worker khi command bị rollback sai lệch.
   - `test_shared_reconciled_path_deliverables`: Kiểm tra xác nhận tự động các tệp báo cáo nén và tài liệu học hỏi.
2. Kết quả chạy kiểm thử toàn bộ:
   ```
   Ran 9 tests in 0.363s
   OK
   ```
3. Đơn trạng thái (Single State Lifecycle):
   `python scripts/command_bus_orchestrator.py validate-lifecycle` -> `[PASS] All command lifecycle invariants satisfied: each command in strictly one directory.`

---

## 5. TÌNH TRẠNG TASK_056 VÀ SẴN SÀNG ĐIỀU PHỐI LIÊN TỤC

- Lệnh `TASK_056_SO45_CONTINUOUS_DEEP_IMAGE_EFFECT_GRAPH_20261005T063200+0700` đã được dọn sạch `dispatch_error`.
- Bổ sung đầy đủ `allowed_paths` cho phần kết quả phân tích phòng sạch SO45.
- Trạng thái hiện tại: `QUEUED` chờ giải phóng khóa phân vùng tóc (`production-hair-v2/v3/v4`) từ TASK_057.
- Ngay khi TASK_057 được tích hợp hoàn tất, khóa module được mở, TASK_056 sẽ lập tức chuyển sang `READY` và được Dispatcher chu kỳ tiếp theo kích hoạt một cách minh bạch, an toàn và không còn nguy cơ gặp race condition.
