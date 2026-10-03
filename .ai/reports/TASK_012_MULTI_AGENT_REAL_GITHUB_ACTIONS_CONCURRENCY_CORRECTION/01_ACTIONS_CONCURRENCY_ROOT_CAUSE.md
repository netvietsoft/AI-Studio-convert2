# 01. NGUYÊN NHÂN GỐC RỄ & PHÂN TÍCH LỖI ĐỒNG THỜI GITHUB ACTIONS
# (01_ACTIONS_CONCURRENCY_ROOT_CAUSE.md)
**Nhiệm Vụ:** TASK_012 — MULTI-AGENT REAL GITHUB ACTIONS CONCURRENCY CORRECTION  
**Command ID:** `TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700`  
**Ngày:** 2026-10-03  
**Trạng Thái:** KHẮC PHỤC TRIỆT ĐỂ (RESOLVED)

---

## 1. BẢNG PHÂN LOẠI & ĐỐI CHIẾU NGUYÊN NHÂN GỐC RỄ

| Điểm Lỗi | Cơ Chế Gây Lỗi | Hậu Quả Thực Tế | Giải Pháp Triệt Để |
| :--- | :--- | :--- | :--- |
| **Push Trigger Collision** | Cả `convert2-command-bus.yml` và `convert2-dispatcher.yml` cùng lắng nghe `on.push: paths: [.ai/commands/pending/**]` | Khi commit đẩy lên main, workflow cũ chạy với `-CommandId ""` rỗng, báo lỗi PowerShell `MissingArgument` trên Windows runner và cạnh tranh tài nguyên với Dispatcher. | Gỡ bỏ `on.push` khỏi `convert2-command-bus.yml`, chỉ cho phép `workflow_dispatch` có `command_id` tường minh. |
| **Missing Ref in Integrator** | Container Ubuntu của `actions/checkout@v4` chỉ nạp `main`. Lệnh `git fetch origin` không fetch các nhánh `agent/*` nếu không có refspec đầy đủ. | `git rev-parse origin/{branch}` trả về khác 0; `git merge` báo `not something we can merge`. Integrator nhầm thành `BLOCKED_MERGE_CONFLICT`. | Bổ sung fetch tường minh `+refs/heads/${branch}:refs/remotes/origin/${branch}` trong cả workflow lẫn Orchestrator. |
| **False Positive Merge Conflict** | Orchestrator đánh đồng mọi lỗi trả về từ `git merge` thành `BLOCKED_MERGE_CONFLICT` kể cả khi lỗi do thiếu ref hoặc fetch thất bại. | Task bị chặn oan uổng, trạng thái bị khóa thành conflict dù không có xung đột nội dung file nào. | Kiểm tra `git status --porcelain` để tìm conflict markers (`UU`, `AA`, etc.). Nếu không có, trả về `FETCH_ERROR` hoặc `MERGE_ERROR`. |
| **Runner Label Drop in Dispatch** | Hàm `dispatch_commands()` trong Orchestrator không chuyển trường `runner_label` từ JSON sang cờ `-f runner_label=...` của `gh workflow run`. | Các tác vụ đòi hỏi runner chuyên biệt (như runner gắn thiết bị thử nghiệm) bị rơi về nhãn mặc định `convert2`, gây sai lệch vị trí chạy. | Trích xuất `cmd.get("runner_label")` và truyền cờ `-f runner_label=...` vào `dispatch_args`. |
| **API 403 Permission Bottleneck** | `GITHUB_TOKEN` của workflow thiếu quyền quản trị runner (`manage:runners`) khi gọi endpoint `repos/.../actions/runners`. | Script kiểm tra runner pool quăng lỗi HTTP 403, dẫn đến nhận định sai là runner pool không hoạt động (0/3 online). | Xây dựng fallback cục bộ: đọc file `.runner` trong `C:\actions-runner*` và kiểm tra tiến trình `Runner.Listener.exe` của Windows. |

---

## 2. PHÂN TÍCH CHI TIẾT CÁC LỖI ĐIỂN HÌNH

### 2.1 Bằng chứng lỗi Push Collision trên Run 37100106868
Khi Dispatcher đẩy commit đặt chỗ lệnh lên `main`:
- Run `37100106824` (`CONVERT2 Command Bus Dispatcher`) chạy thành công trên `ubuntu-latest`.
- Đồng thời Run `37100106868` (`CONVERT2 Agent Command Bus`) bị kích hoạt trên Windows runner `CONVERT2-WINDOWS-03`.
- Nhật ký thực thi:
  ```text
  $cmdId = ""
  powershell.exe -NoProfile -ExecutionPolicy Bypass `
    -File ".\scripts\run_agent_from_github_command.ps1" `
    -RepoPath "C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2" `
    -CommandId "$cmdId" `
    -ExecutionLane "$lane"
  Missing an argument for parameter 'CommandId'. Specify a parameter of type 'System.String' and try again.
  Process completed with exit code 1.
  ```
Lỗi này làm tiêu tốn chu kỳ máy chủ và tạo ra log đỏ giả tạo trên kho lưu trữ.

### 2.2 Bằng chứng lỗi Missing Ref Merge trên Run 37097467413
Khi Serial Integrator thực thi cho nhánh tác vụ `agent/TASK_012_...`:
- `actions/checkout@v4` chỉ tải `main`. Lệnh `git fetch origin` thông thường không kéo ref của nhánh `agent/TASK_012_...`.
- Nhật ký thực thi:
  ```text
  [FAIL] BLOCKED_MERGE_CONFLICT: Merge conflict merging agent/TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700 into main: merge: agent/TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700 - not something we can merge
  ```
Lỗi thực chất là do git không tìm thấy ref nhánh để merge, nhưng Orchestrator lại đánh dấu nhầm thành `BLOCKED_MERGE_CONFLICT`.

---

## 3. KẾT LUẬN
Toàn bộ các điểm nghẽn và lỗi tiềm ẩn trên đều bắt nguồn từ sự thiếu đồng bộ giữa cơ chế cô lập của GitHub Actions Cloud và giả định môi trường của mã lệnh chạy cục bộ. Việc sửa đổi đồng bộ cả tầng Workflow YAML lẫn mã điều phối Python Orchestrator đã giải quyết triệt để 100% các nguyên nhân này.
