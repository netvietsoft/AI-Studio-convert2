# 03 - BẰNG CHỨNG ĐIỀU PHỐI VÀ THỰC THI COMMAND BUS (COMMAND BUS DISPATCH & WORKER PROVENANCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Nhiệm vụ:** `TASK_033 — TASK032 WORKFLOW PROVENANCE & COMMAND BUS CLOSURE CORRECTION`  

---

## 1. CHUỖI ĐIỀU PHỐI CHUẨN MỰC THEO ĐIỀU XXV CỦA HIẾN PHÁP
Theo Điều XXV của `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`:
$$\text{TASK\_CREATED} \longrightarrow \text{TASK\_DISPATCHED} \longrightarrow \text{TASK\_EXECUTING / COMPLETED}$$
Không một tác vụ nào được xem là đang chạy nếu chưa có luồng GitHub Actions/Command Bus tương ứng.

Chuỗi điều phối thực tế của TASK_033 được thiết lập như sau:
1. **Khởi tạo và Đưa vào hàng đợi (Enqueue):**
   - Commit: `ca303f232cc376c957d93a4fb8b52003d80d9d67` ("chore(command-bus): enqueue TASK_033 TASK_032 provenance closure").
   - Tập tin: `.ai/commands/pending/TASK_033_TASK032_WORKFLOW_PROVENANCE_CLOSURE_20261004T052000+0700.json`.
2. **Hòa giải và Cập nhật chỉ mục (Reconciliation):**
   - Commit: `410f1936e788bc55959ad2634d0b13cf14a13d7e` ("chore(command-bus): reconcile stale state before dispatch [run 37157700576]").
3. **Đặt trước tài nguyên điều phối (Reservation):**
   - Commit: `f085e808119e7f6b209f15c2269275dc4b719cdf` ("chore(command-bus): reserve 1 command(s) for dispatch [run 37157700576]").
   - Runner label: `CONVERT2-WINDOWS-03`.
   - Execution lane: `task032-provenance-closure`.
   - Reservation token: `c45fb6d8fb8b4eb8b136c9d8742dda92`.
4. **Xác nhận điều phối (Persist Dispatch Outcome):**
   - Commit: `5cb07a2669650fed5d3f0058d9df12aa3114ca2d` ("chore(command-bus): persist dispatch outcome [run 37157700576]").
   - Dispatcher Run ID: `37157700576`.
   - Workflow name: `CONVERT2 Command Bus Dispatcher`.
5. **Tiếp nhận và Chuyển trạng thái RUNNING (Worker Lease & Start):**
   - GitHub Actions Run ID: `37157772171`.
   - Workflow name: `CONVERT2 Agent Worker`.
   - Job ID: `111304692810` (`execute-command`).
   - Runner Host: `CONVERT2-WINDOWS-03`.
   - Lease Token: `c10558f21ad24bc895b0cdd883adefb7`.
   - Nhánh cách ly: `agent/TASK_033_TASK032_WORKFLOW_PROVENANCE_CLOSURE_20261004T052000+0700`.

---

## 2. BẢNG THÔNG SỐ ĐỊNH DANH THỰC THI (EXECUTION IDENTITY)
| Thuộc tính | Giá trị kiểm chứng | Ghi chú |
|:---|:---|:---|
| **Command ID** | `TASK_033_TASK032_WORKFLOW_PROVENANCE_CLOSURE_20261004T052000+0700` | Định danh lệnh bất biến |
| **Task ID** | `TASK_033_TASK032_WORKFLOW_PROVENANCE_COMMAND_BUS_CLOSURE_CORRECTION_ACTIVE` | Khóa tác vụ |
| **Dispatcher Run ID** | `37157700576` | GitHub Actions Dispatcher |
| **Dispatcher Commit SHA** | `f085e808119e7f6b209f15c2269275dc4b719cdf` | Commit chứa lệnh đặt trước |
| **Worker Run ID** | `37157772171` | GitHub Actions Worker |
| **Worker Job ID** | `111304692810` | ID công việc thực thi |
| **Workflow URL** | `https://github.com/netvietsoft/AI-Studio-convert2/actions/runs/37157772171` | Đường dẫn kiểm chứng GitHub |
| **Runner Label** | `CONVERT2-WINDOWS-03` | Máy trạm Runner chính thức |
| **Execution Lane** | `task032-provenance-closure` | Phân làn xử lý độc lập |
| **Branch cách ly** | `agent/TASK_033_TASK032_WORKFLOW_PROVENANCE_CLOSURE_20261004T052000+0700` | Ngăn chặn conflict |
| **Locked Modules** | `["command-bus-provenance"]` | Khóa chống xung đột tài nguyên |
| **Allowed Paths** | `.ai/reports/**`, `.ai/state/**`, `.ai/commands/**`, `.ai/state.json`, `TASK_LOG.md` | Giới hạn can thiệp an toàn |
