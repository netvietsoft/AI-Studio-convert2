# CẤU HÌNH GITHUB ACTIONS ĐA LUỒNG & BÁO CÁO DUNG LƯỢNG TRUNG THỰC (03_GITHUB_ACTIONS_MULTI_LANE.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. THIẾT KẾ WORKFLOW ĐA LUỒNG (.github/workflows/convert2-command-bus.yml)

Để hiện thực hóa mô hình Multi-Agent / Multi-Task, cấu hình CI/CD GitHub Actions được nâng cấp với các đặc tính kỹ thuật vượt trội:

```yaml
name: CONVERT2 Agent Command Bus

on:
  push:
    branches: [main]
    paths:
      - ".ai/commands/pending/**"
      - ".ai/commands/NEXT_COMMAND.json"
      - "scripts/command_bus_orchestrator.py"
  workflow_dispatch:
    inputs:
      command_id:
        description: "Specific Command ID to execute (leave empty to pick highest priority ready command)"
        required: false
        type: string
        default: ""
      execution_lane:
        description: "Execution Lane"
        required: false
        type: string
        default: "default"
      force_rerun:
        description: "Force execution regardless of existing completion"
        required: false
        type: boolean
        default: false

permissions:
  contents: write
  pull-requests: write

concurrency:
  group: convert2-command-bus-${{ inputs.execution_lane || 'default' }}
  cancel-in-progress: false

jobs:
  execute-command:
    runs-on: [self-hosted, Windows, convert2]
    timeout-minutes: 120
    ...
```

---

## 2. NGUYÊN TẮC CÁCH LY CONCURRENCY GIỮA CÁC LANE

### 2.1. Khắc Phục Lỗi Tự Triệt Tiêu (No Cancellation Across Lanes)
- **Vấn đề cũ:** Nếu toàn bộ workflow dùng chung `concurrency: group: convert2-agent-command-bus`, mọi lệnh mới phát sinh sẽ lập tức hủy bỏ hoặc chặn đứng tiến trình đang chạy của lane khác.
- **Giải pháp V2:** Phân vùng nhóm đồng thời động theo execution lane:
  `group: convert2-command-bus-${{ inputs.execution_lane || 'default' }}`
  với cờ bất biến:
  `cancel-in-progress: false`
- **Kết quả:** Lệnh thuộc `lane_windows_01` và lệnh thuộc `lane_gpu` chạy song song hoàn toàn độc lập, không triệt tiêu nhau, tối ưu hóa năng lực máy tính phần cứng thực tế.

---

## 3. THU THẬP & LIÊN KẾT ĐỊNH DANH THỰC THI (EXECUTION IDENTITY PROVENANCE)

Mỗi lần một workflow GitHub Actions khởi chạy, script runner `scripts/run_agent_from_github_command.ps1` tự động trích xuất và liên kết chặt chẽ bộ 5 thông số định danh:
1. `github_run_id`: Định danh duy nhất của lượt chạy GitHub Actions (truy xuất từ biến môi trường `$env:GITHUB_RUN_ID`).
2. `workflow_url`: Đường dẫn trực tiếp tới console log:
   `${GITHUB_SERVER_URL}/${GITHUB_REPOSITORY}/actions/runs/${GITHUB_RUN_ID}`
3. `dispatch_commit_sha`: Mã commit HEAD chính xác tại thời điểm lệnh được phát đi (`git rev-parse HEAD`).
4. `runner_lane`: Phân vùng lane mà runner phụ trách.
5. `timestamps`: Thời điểm bắt đầu (`started_at`) và thời điểm hoàn tất (`finished_at`).

Bộ định danh này được ghi trực tiếp vào trường `execution_identity` của file lệnh và lưu bền vững vào `.ai/commands/running/<command_id>.json`.

---

## 4. BÁO CÁO DUNG LƯỢNG TRUNG THỰC (HONEST CAPACITY REPORTING)

Một trong những yêu cầu nghiêm ngặt nhất của Chủ tịch Tony là:
> **"Runner capacity limitations must be reported honestly as QUEUED, not RUNNING."**

### 4.1. Cơ Chế Báo Cáo Trạng Thái
- Nếu runner capacity đã đạt ngưỡng (ví dụ: tối đa 2 agents/lane trên phần cứng Windows thật) hoặc tài nguyên đang bị khóa bởi tác vụ khác:
- Trạng thái của lệnh **bắt buộc** ghi là `QUEUED` (kèm trường `queue_reason`).
- **Tuyệt đối cấm:** Báo cáo lệnh là `RUNNING` khi runner thực tế đang phải chờ rảnh tài nguyên.
- Khi một tác vụ trước hoàn thành hoặc giải phóng lease, Orchestrator mới tái tính toán và chuyển trạng thái từ `QUEUED` sang `READY` -> `CLAIMED` -> `RUNNING`.
