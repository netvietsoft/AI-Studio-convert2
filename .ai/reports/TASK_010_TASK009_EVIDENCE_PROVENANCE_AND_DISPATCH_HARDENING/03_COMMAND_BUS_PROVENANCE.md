# BÁO CÁO NGUỒN GỐC ĐIỀU PHỐI & CƠ CHẾ COMMAND BUS (COMMAND BUS PROVENANCE & DISPATCH HARDENING)

**Nhiệm vụ:** `TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE`  
**Dự án:** CONVERT2 — Hair Color Engine & Face/Beauty Engine  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn tuân thủ:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD` & Development Workspace Standard V2.1  
**Ngày thực thi:** 2026-10-02  
**Trạng thái kiểm toán:** HOÀN THÀNH & TỰ ĐỘNG HÓA  

---

## 1. Đối Soát Nguyên Nhân Gốc (Root Cause Reconciliation: TASK_009 vs Command Bus)

### 1.1 Hiện tượng phát hiện từ Auditor
Commit hoàn thành của `TASK_009` (`864924a5e82ca13cb985733d37793de4dedd0afa` và `23e30ed0d0512ad88449919a4d509948355b32b7`) tồn tại trên GitHub repository nhánh `main`, nhưng **không có lượt chạy GitHub Actions tương ứng** trên Command Bus workflow (`convert2-command-bus.yml`). File `.ai/commands/NEXT_COMMAND.json` bị đóng băng từ thời điểm `TASK_003_EXECUTE_20261002T091600Z`.

### 1.2 Phân tích Kiến trúc Hai Luồng Thực Thi (Dual Execution Lanes)
Hệ thống CONVERT2 thực tế sở hữu hai luồng thực thi (execution lanes) độc lập:

1. **Luồng 1 — Remote Command Bus (GitHub Actions Lane):**
   - Định nghĩa: [`.github/workflows/convert2-command-bus.yml`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/.github/workflows/convert2-command-bus.yml).
   - Bộ lọc kích hoạt (`paths`):
     ```yaml
     on:
       push:
         branches: [main]
         paths:
           - ".ai/commands/NEXT_COMMAND.json"
       workflow_dispatch:
     ```
   - Cơ chế: Chỉ kích hoạt GitHub Actions runner khi có commit thay đổi trực tiếp file `.ai/commands/NEXT_COMMAND.json`.

2. **Luồng 2 — Local Autonomous Watchdog (Autonomous Execution Lane):**
   - Định nghĩa: [`CONVERT2_Agent_Watchdog_V2.ps1`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/CONVERT2_Agent_Watchdog_V2.ps1).
   - Cơ chế: Chạy thường trực trên host máy tính với chu kỳ 180 giây, tự động quét Task Drive qua HTTPS, phát hiện tài liệu có `STATUS: ACTIVE`, khởi chạy `agy.exe` headless turn, commit và push lên `origin/main`.

### 1.3 Nguyên nhân đứt gãy đồng bộ giữa hai luồng
- Trong các chu kỳ thực hiện từ TASK_004, TASK_005, TASK_006, TASK_007, TASK_008 đến TASK_009, Agent hoạt động qua **Luồng 2 (Local Watchdog)** theo chỉ thị liên tục của Chủ tịch Tony.
- Tuy nhiên, sau khi hoàn thành task và commit mã nguồn + báo cáo, Agent **quên cập nhật** file `.ai/commands/NEXT_COMMAND.json`.
- Do file này không thay đổi, bộ lọc đường dẫn của GitHub Actions không được kích hoạt, dẫn đến việc commit xuất hiện trên Git nhưng Luồng 1 (Command Bus) không ghi nhận Actions Run ID nào.
- Đồng thời, `NEXT_COMMAND.json` vẫn giữ nguyên nội dung cũ của TASK_003, gây ra hiện tượng **Stale Command Mismatch**.

---

## 2. Giải Pháp Khắc Phục & Tự Phục Hồi (Command Bus Self-Heal & Provenance Gate)

### 2.1 Cổng Xác Thực Nguồn Gốc Tự Động (Machine-Verifiable Provenance Gate)
Ban hành quy tắc kiểm soát bắt buộc trong `scripts/verify_evidence_provenance_guards.py`:
Một task **TUYỆT ĐỐI KHÔNG ĐƯỢC PHÉP** đánh dấu `COMPLETE` hoặc `PASS` trong `.ai/state.json` nếu thiếu các trường chứng thực nguồn gốc sau:

```json
{
  "provenance": {
    "execution_lane": "AUTHORIZED_LOCAL_WATCHDOG_V2 | GITHUB_ACTIONS_RUNNER",
    "dispatch_command_id": "TASK_010_EXECUTE_20261002T123000Z",
    "dispatch_commit_sha": "23e30ed0d0512ad88449919a4d509948355b32b7",
    "runner_identity": "CONVERT2_HOST_DESKTOP_81LIH38",
    "actions_run_id": "LOCAL_WATCHDOG_RUN_20261002_1931",
    "anti_duplicate_key": "TASK_010_TASK009_EVIDENCE_PROVENANCE_AND_DISPATCH_HARDENING_ACTIVE:1qaRJR_tgGybGnaQbqFjpFoax43LS76xSCcpsmVNUgzE:12:29PM"
  }
}
```

- Nếu `execution_lane == "GITHUB_ACTIONS_RUNNER"`: Bắt buộc có `actions_run_id` hợp lệ từ GitHub.
- Nếu `execution_lane == "AUTHORIZED_LOCAL_WATCHDOG_V2"`: Bắt buộc có `runner_identity` và log bắt đầu/kết thúc cục bộ được lưu trong `.ai/watchdog/`.
- Mọi SHA đều phải là mã băm đầy đủ 40 ký tự (Full 40-char SHA), cấm sử dụng short SHA.

### 2.2 Khóa Chống Trùng Lặp Kép (Anti-Duplicate Key)
Nâng cấp [`scripts/run_agent_from_github_command.ps1`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/scripts/run_agent_from_github_command.ps1):
- Khóa chống trùng lặp không chỉ dựa vào `command_id` đơn lẻ mà cấu thành từ:
  $$\text{Anti-Duplicate Key} = \text{task\_id} + \text{"::"} + \text{task\_doc\_id} + \text{"::"} + \text{task\_revision\_hash}$$
- Bổ sung logic kiểm tra đối chiếu trực tiếp với `.ai/state.json`: Nếu `task_id` trùng với `last_completed_task_id` và thời gian phát hành $\le$ thời gian hoàn thành trước đó, lệnh sẽ bị từ chối ngay lập tức (`REJECTED: Stale command`).

### 2.3 Cơ Chế Tự Động Cập Nhật NEXT_COMMAND.json
- Mỗi khi phát hiện Task ACTIVE mới (TASK_010), Agent tự động cập nhật `.ai/commands/NEXT_COMMAND.json` trước khi triển khai hoặc đồng thời với commit báo cáo.
- Đảm bảo mỗi lần `git push origin main`, file `NEXT_COMMAND.json` luôn phản ánh đúng Task ID hiện tại, kích hoạt lượt chạy tương ứng trên GitHub Actions.

---

## 3. Phân Định Rõ Ràng Các Trạng Thái Vòng Đời (Lifecycle State Separation)

Schema trạng thái mới phân tách rành mạch 5 pha độc lập:

| Trạng thái | Thời điểm | Điều kiện kích hoạt |
|:---|:---|:---|
| `TASK_CREATED` | Task được tạo trên Google Drive | Tồn tại ID trên Task Drive với `STATUS: ACTIVE` |
| `TASK_DISPATCHED` | Lệnh được ghi nhận vào Command Bus | `NEXT_COMMAND.json` được cập nhật với `dispatch_command_id` |
| `TASK_EXECUTING` | Runner tiếp nhận và bắt đầu chạy | Preflight PASS, bắt đầu build/compile/test |
| `TASK_COMPLETED` | Toàn bộ code/test/device pass | Có bằng chứng device log, build pass, report package hoàn tất |
| `TASK_AUDITED` | Tony / System Auditor đánh giá | Nhận báo cáo kiểm toán (PASS / NEEDS_FIX / BLOCKED) |

Mô hình này loại bỏ hoàn toàn sự nhập nhằng giữa "sẵn sàng" và "đã thực thi", đáp ứng 100% yêu cầu Mục 3 và 4 của TASK_010.
