# BÁO CÁO LOẠI BỎ TRIGGER TỰ ĐỘNG CỦA WORKFLOW LEGACY (DECOMMISSION)
# 03_LEGACY_WORKFLOW_DECOMMISSION.md
**Nhiệm Vụ:** TASK_024 — Multi-Agent Correction  
**Tiêu Chuẩn:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Giao Thức:** CONVERT2_COMMAND_V2  
**Đối Tượng Xử Lý:** `.github/workflows/convert2-command-bus.yml`

---

## 1. NGUYÊN DO KỸ THUẬT VÀ YÊU CẦU DECOMMISSION

Trong cấu hình ban đầu trước commit `9cbdc707`, kho mã nguồn tồn tại song song hai workflow có khả năng điều phối:
1. `convert2-dispatcher.yml`: Dispatcher thế hệ mới (Multi-Task / Multi-Runner Pool), lắng nghe push vào `.ai/commands/**`.
2. `convert2-command-bus.yml`: Monolithic Command Bus kế thừa, cũng cấu hình trigger `on.push` lắng nghe `.ai/commands/pending/**`.

Khi có một commit được tích hợp (merge) vào `main` làm thay đổi các file trong `.ai/commands/`:
- Cả hai workflow cùng được kích hoạt đồng thời.
- Cả hai cùng cố gắng đọc và sửa `.ai/state.json`, dẫn tới xung đột khóa (lock conflict) hoặc reservation token bị ghi đè.
- Minh chứng thực tế: Run `37100106868` và Run `37102081541` của `convert2-command-bus.yml` bị lỗi (`failure`) do chạy đè lên phiên điều phối của Dispatcher.

Chủ tịch Tony đã ban hành chỉ thị bắt buộc: **Loại bỏ triệt để auto-trigger của `convert2-command-bus.yml`, chỉ giữ lại cổng kích hoạt thủ công (manual `workflow_dispatch`) để dự phòng.**

---

## 2. NỘI DUNG SỬA ĐỔI FILE WORKFLOW

Tại commit `9cbdc70757270d4734ec627c3ea45bcf6d755462`, tệp `.github/workflows/convert2-command-bus.yml` đã được tinh chỉnh:

```yaml
name: CONVERT2 Agent Command Bus (Standalone Fallback)

on:
  workflow_dispatch:
    inputs:
      command_id:
        description: "Target command ID to execute (leave empty to pick highest priority pending command)"
        required: false
        type: string
        default: ""
```

**Các điểm cốt lõi đã loại bỏ:**
- Xóa bỏ hoàn toàn khối cấu hình:
  ```yaml
  # ĐÃ XÓA TRIỆT ĐỂ:
  # push:
  #   paths:
  #     - '.ai/commands/pending/**'
  ```
- Đổi tên hiển thị thành `CONVERT2 Agent Command Bus (Standalone Fallback)` nhằm phân định rõ đây là luồng phụ trợ khẩn cấp, không phải luồng điều phối chính.

---

## 3. BẰNG CHỨNG THỰC NGHIỆM: PUSH LÊN MAIN KHÔNG KÍCH HOẠT WORKFLOW CŨ

Để kiểm chứng tính hiệu quả sau khi gỡ bỏ auto-trigger, sự kiện push commit `a8fa6ef3181c81770c6e155f65c099189778bc06` lên nhánh `main` đã được ghi nhận:

### Kết Quả Truy Vấn GitHub Actions API:
```text
Run ID: 37106495219
Workflow: CONVERT2 Command Bus Dispatcher
Trigger: push (commit a8fa6ef)
Status: completed
Conclusion: success
Duration: 55s
Timestamp: 2026-10-03T07:29:12Z
```

### Kiểm Tra Workflow Legacy:
- Số lượng run của `convert2-command-bus.yml` được kích hoạt bởi commit `a8fa6ef`: **0 RUN**.
- Không có bất kỳ tiến trình nào chạy chồng lấn hay gây lỗi lock conflict trên nhánh `main`.
- Dispatcher đã hoàn thành việc rà soát và kích hoạt thành công 2 worker song song:
  - Run `37106536761` (TASK_024)
  - Run `37106538676` (TASK_028)

---

## 4. QUY TRÌNH KÍCH HOẠT THỦ CÔNG DỰ PHÒNG (MANUAL FALLBACK)

Trong trường hợp hãn hữu hệ thống Dispatcher gặp sự cố, kỹ sư vận hành có thể kích hoạt thủ công lệnh cụ thể thông qua GitHub CLI:

```powershell
gh workflow run convert2-command-bus.yml -f command_id="CMD_NAME_HERE"
```

Hoặc qua giao diện GitHub Actions UI bằng cách chọn workflow `CONVERT2 Agent Command Bus (Standalone Fallback)` và nhấn "Run workflow". Cơ chế này vừa đảm bảo an toàn tuyệt đối trong vận hành tự động, vừa giữ được năng lực phản ứng nhanh khi cần bảo trì.
