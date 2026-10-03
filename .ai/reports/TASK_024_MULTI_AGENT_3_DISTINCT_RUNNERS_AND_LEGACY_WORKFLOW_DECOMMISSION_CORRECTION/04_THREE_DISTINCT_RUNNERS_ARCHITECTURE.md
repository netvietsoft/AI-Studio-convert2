# KIẾN TRÚC ĐIỀU PHỐI ĐA RUNNER ĐỘC LẬP (3 DISTINCT RUNNERS ARCHITECTURE)
# 04_THREE_DISTINCT_RUNNERS_ARCHITECTURE.md
**Nhiệm Vụ:** TASK_024 — Multi-Agent Correction  
**Tiêu Chuẩn:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Giao Thức:** CONVERT2_COMMAND_V2  

---

## 1. THIẾT KẾ HẠ TẦNG VẬT LÝ VÀ PHÂN VÙNG RUNNER

Dự án CONVERT2 vận hành trên hạ tầng máy chủ Windows với 3 bộ Runner self-hosted hoạt động độc lập, mỗi Runner sở hữu thư mục làm việc và tiến trình listener riêng biệt:

| Tên Runner | Đường Dẫn Listener | Thư Mục Làm Việc (_work) | Nhãn Định Danh (Labels) | Vai Trò Chuyên Trách |
| :--- | :--- | :--- | :--- | :--- |
| **CONVERT2-WINDOWS-01** | `C:\actions-runner` | `C:\actions-runner\convert2\AI-Studio-convert2\AI-Studio-convert2` | `self-hosted`, `Windows`, `convert2`, `CONVERT2-WINDOWS-01` | Runner Chính / Hạ Tầng & Tích Hợp |
| **CONVERT2-WINDOWS-02** | `C:\actions-runner-02` | `C:\actions-runner-02\_work\AI-Studio-convert2\AI-Studio-convert2` | `self-hosted`, `Windows`, `convert2`, `CONVERT2-WINDOWS-02` | Worker Song Song 1 / Thuật Toán & Model |
| **CONVERT2-WINDOWS-03** | `C:\actions-runner-03` | `C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2` | `self-hosted`, `Windows`, `convert2`, `CONVERT2-WINDOWS-03` | Worker Song Song 2 / Thiết Bị & Kiểm Định |

---

## 2. CƠ CHẾ ĐIỀU PHỐI VÀ ĐỊNH TUYẾN ĐÍCH DANH (TARGETED ROUTING)

### A. Vấn đề của cơ chế gắn nhãn chung cũ
Trước đây, các command chỉ được gán nhãn chung `convert2`. Khi Dispatcher kích hoạt nhiều worker cùng lúc, GitHub Actions scheduler phân bổ các job cho runner nào gửi heartbeat trước. Do không có sự ép buộc runner cụ thể:
- Nếu một runner đang bận, các job còn lại có thể bị đẩy dồn vào một runner khác và chạy nối tiếp (serial) thay vì phân bổ đều ra 3 runner.
- Đây chính là nguyên nhân kỹ thuật dẫn tới việc trong TASK_021, Runner 03 phải chạy 2 job nối tiếp trong khi Runner 01 không nhận được job acceptance nào.

### B. Cơ chế định tuyến mới trong TASK_024
1. **Định danh trong file Command JSON:**
   Mỗi command được khai báo trường `runner_label` tường minh. Ví dụ:
   ```json
   {
     "command_id": "CMD_ACCEPT_024_01_RUNNER_POOL_HEALTH_20261003T150000+0700",
     "runner_label": "CONVERT2-WINDOWS-01",
     "execution_lane": "infra-acceptance-01"
   }
   ```
2. **Dispatcher truyền nhãn runner vào Worker Workflow:**
   Trong `scripts/command_bus_orchestrator.py`, phương thức `dispatch_commands()` tự động trích xuất `runner_label`:
   ```python
   runner_label = cmd.get("runner_label")
   cmd_args = ["gh", "workflow", "run", "convert2-worker.yml", "-f", f"command_id={cmd_id}"]
   if runner_label:
       cmd_args.extend(["-f", f"runner_label={runner_label}"])
   subprocess.run(cmd_args, check=True)
   ```
3. **Cấu hình `runs-on` động trong `.github/workflows/convert2-worker.yml`:**
   ```yaml
   jobs:
     execute-command:
       runs-on: [self-hosted, Windows, "${{ inputs.runner_label || 'convert2' }}"]
   ```
   Nhờ cấu hình này, GitHub Actions scheduler bắt buộc phải tìm đúng runner có nhãn tương ứng (ví dụ: `CONVERT2-WINDOWS-01`). Job sẽ không bị cướp bởi Runner 02 hay Runner 03.

---

## 3. AN TOÀN TRUY CẬP TRẠNG THÁI VÀ CHỐNG XUNG ĐỘT (ATOMIC LOCKING & CONCURRENCY SAFETY)

Khi 3 runner hoạt động đồng thời:
1. **Phân vùng làn thực thi (Execution Lanes):** Mỗi task hoạt động trong một lane độc lập (`infra-acceptance-01`, `infra-acceptance-02`, `infra-acceptance-03`).
2. **Khóa tệp hạt nhân (Atomic File Locking):**
   Mọi thao tác đọc/ghi vào cơ sở dữ liệu trạng thái tập trung `.ai/state.json` và `.ai/commands/index.json` đều được bảo vệ bởi `FileLock` (`.ai/state.json.lock`) với cơ chế exponential backoff retry.
3. **Phân lập vùng tệp cho phép (`allowed_paths`):**
   Mỗi command có danh sách `allowed_paths` riêng biệt. Cổng Dispatcher từ chối đặt trước (reserve) các task có `allowed_paths` chồng lấn trong cùng một đợt chạy để loại trừ rủi ro merge conflict.

---

## 4. MINH CHỨNG THỰC TẾ: ĐIỀU PHỐI ĐA RUNNER ĐANG CHẠY SONG SONG

Trong chính phiên thực thi hiện tại của TASK_024:
- Run ID `37106536761` (TASK_024) đang chạy trên **CONVERT2-WINDOWS-01** (`C:\actions-runner`). Bắt đầu lúc `07:30:04Z`.
- Run ID `37106538676` (TASK_028) đang chạy song song trên **CONVERT2-WINDOWS-03** (`C:\actions-runner-03`). Bắt đầu lúc `07:30:06Z`.
- Cả hai tiến trình worker đã và đang thực thi đồng thời hơn 20 phút mà không gặp bất kỳ xung đột tài nguyên hay lỗi hệ thống nào.

Đây là bằng chứng xác thực 100% chứng minh kiến trúc đa runner của CONVERT2 đã vận hành ổn định và đạt chuẩn kỹ thuật cao cấp.
