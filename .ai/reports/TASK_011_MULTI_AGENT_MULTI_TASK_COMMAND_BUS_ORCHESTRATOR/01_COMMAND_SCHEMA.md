# ĐẶC TẢ LƯỢC ĐỒ LỆNH ĐIỀU PHỐI (01_COMMAND_SCHEMA.md)
# Chuẩn Giao Thức: CONVERT2_COMMAND_V2
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. MỤC TIÊU THIẾT KẾ
Lược đồ `CONVERT2_COMMAND_V2` được thiết kế nhằm thay thế hoàn toàn cấu trúc lệnh mutable single-slot cũ. Mỗi lệnh đại diện cho một đối tượng bất biến (immutable entity) độc lập, có định danh duy nhất, gắn liền với phiên bản tài liệu Task và mã băm nguồn Git, theo dõi vòng đời hoàn chỉnh từ lúc khởi tạo đến khi nghiệm thu.

---

## 2. ĐẶC TẢ CÁC TRƯỜNG DỮ LIỆU (FIELD SPECIFICATIONS)

| Tên Trường | Kiểu Dữ Liệu | Bắt Buộc | Mô Tả & Ràng Buộc |
| :--- | :---: | :---: | :--- |
| `protocol` | String | Có | Bắt buộc là `"CONVERT2_COMMAND_V2"`. |
| `command_id` | String | Có | Khóa định danh duy nhất (UUID / Timestamp based), ví dụ: `CMD_TASK_011_20261002T195000_A1B2C3`. |
| `task_id` | String | Có | Mã Task định danh chính tắc, ví dụ: `TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE`. |
| `task_revision` | String | Có | Phiên bản sửa đổi của Task Doc hoặc mã hash nội dung (ngăn ngừa duplicate). |
| `task_url` | String | Có | Đường dẫn URL chính tắc tới Task Drive Google Doc (bắt buộc HTTPS). |
| `issued_for_sha` | String | Có | Mã Git commit SHA tại thời điểm phát lệnh (đảm bảo tính đồng bộ mã nguồn). |
| `priority` | String | Có | Mức độ ưu tiên: `"CRITICAL"` (100), `"HIGH"` (80), `"NORMAL"` (50), `"LOW"` (20). |
| `priority_weight` | Integer | Có | Trọng số số học dùng để sắp xếp hàng đợi ưu tiên. |
| `dependencies` | Array[String] | Có | Danh sách các `task_id` hoặc `command_id` bắt buộc phải COMPLETED trước khi lệnh này được READY. |
| `execution_lane` | String | Có | Định danh luồng thực thi (ví dụ: `"lane_default"`, `"lane_windows_01"`, `"lane_gpu"`). |
| `allowed_paths` | Array[String] | Có | Danh sách các đường dẫn/glob pattern mà Agent được phép chỉnh sửa. Dùng để tính va chạm khóa file. |
| `locked_modules` | Array[String] | Có | Danh sách module logic bị khóa độc quyền (ví dụ: `["core-graphics"]`). |
| `anti_duplicate_key` | String | Có | Chuỗi tổng hợp `${task_id}:${task_revision}` để kiểm tra lũy đẳng. |
| `created_at` | String | Có | Dấu thời gian ISO 8601 kèm múi giờ khi lệnh được tạo. |
| `status` | String | Có | Trạng thái hiện tại của lệnh trong máy trạng thái (xem mục 3). |
| `retry_count` | Integer | Có | Số lần lệnh được phục hồi sau sự cố runner crash. |
| `lease` | Object / Null | Tùy chọn | Chứa thông tin khóa thuê quyền thực thi của runner (xem mục 4). |
| `execution_identity` | Object / Null | Tùy chọn | Chứa định danh runner, commit dispatch, GitHub Actions run_id. |
| `provenance` | Object / Null | Tùy chọn | Chứa bằng chứng nghiệm thu (target SHA, report folder, evidence hash). |

---

## 3. MÁY TRẠNG THÁI VÒNG ĐỜI LỆNH (COMMAND LIFECYCLE STATE MACHINE)

```
                 [CREATE]
                    │
                    ▼
               ┌─────────┐
               │ PENDING │
               └────┬────┘
                    │
         ┌──────────┴──────────┐
         ▼ (Unmet Deps)        ▼ (Lock Conflict / Over Capacity)
┌────────────────────┐   ┌────────┐
│ WAITING_DEPENDENCY │   │ QUEUED │
└────────┬───────────┘   └───┬────┘
         │ (Deps Done)       │ (Locks Cleared & Capacity Available)
         └──────────┬────────┘
                    ▼
               ┌─────────┐
               │  READY  │
               └────┬────┘
                    │
                    ▼ (Runner Claim via FileLock)
               ┌─────────┐
               │ CLAIMED │──────┐ (Lease Expired without Heartbeat)
               └────┬────┘      │
                    │           ▼
                    │    ┌───────────────────┐
                    │    │ STALE_RECOVERABLE │
                    │    └─────────┬─────────┘
                    │              │ (Auto Recover -> PENDING)
                    │              ▼
                    │        [Back to PENDING]
                    ▼ (Start with Git SHA & Run ID)
               ┌─────────┐
               │ RUNNING │──────┘
               └────┬────┘
                    │
        ┌───────────┴───────────┐
        ▼ (Success + Evidence)   ▼ (Error / Abort)
  ┌───────────┐           ┌────────┐
  │ COMPLETED │           │ FAILED │
  └───────────┘           └────────┘
```

---

## 4. VÍ DỤ TÀI LIỆU LỆNH MẪU (CANONICAL EXAMPLES)

### 4.1. Trạng Thái Khởi Tạo (Pending)
```json
{
  "protocol": "CONVERT2_COMMAND_V2",
  "command_id": "CMD_TASK_011_20261002T195000_A1B2C3",
  "task_id": "TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE",
  "task_revision": "2026-10-02T19:50:00+07:00",
  "task_url": "https://docs.google.com/document/d/10rb1eU56r22pk4dSjRnFdvE-tzG2Yvhnigx6sT_E81E/edit",
  "issued_for_sha": "aff0fa47da21a2f226ec8cca6301749092186d4f",
  "priority": "HIGH",
  "priority_weight": 80,
  "dependencies": [],
  "execution_lane": "default",
  "allowed_paths": [
    "scripts/*",
    ".github/workflows/*",
    ".ai/commands/*",
    ".ai/reports/TASK_011*"
  ],
  "locked_modules": [
    "infra",
    "orchestrator"
  ],
  "anti_duplicate_key": "TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE:2026-10-02T19:50:00+07:00",
  "created_at": "2026-10-02T19:50:00+07:00",
  "status": "PENDING",
  "retry_count": 0,
  "lease": null,
  "execution_identity": null,
  "provenance": null
}
```

### 4.2. Trạng Thái Đang Thực Thi (Running)
```json
{
  "protocol": "CONVERT2_COMMAND_V2",
  "command_id": "CMD_TASK_011_20261002T195000_A1B2C3",
  "task_id": "TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE",
  "status": "RUNNING",
  "lease": {
    "lease_token": "9e1c2b3d4f5a6b7c8d9e0f1a2b3c4d5e",
    "lease_holder": "GITHUB_ACTIONS_182938475",
    "leased_at": "2026-10-02T19:52:00+07:00",
    "lease_expires_at": "2026-10-02T20:22:00+07:00",
    "heartbeat_at": "2026-10-02T20:00:00+07:00"
  },
  "execution_identity": {
    "dispatch_commit_sha": "aff0fa47da21a2f226ec8cca6301749092186d4f",
    "github_run_id": "182938475",
    "workflow_url": "https://github.com/netvietsoft/AI-Studio-convert2/actions/runs/182938475",
    "runner_lane": "default",
    "started_at": "2026-10-02T19:52:05+07:00",
    "finished_at": null,
    "conclusion": "RUNNING"
  }
}
```

### 4.3. Trạng Thái Hoàn Thành Nghiệm Thu (Completed)
```json
{
  "protocol": "CONVERT2_COMMAND_V2",
  "command_id": "CMD_TASK_011_20261002T195000_A1B2C3",
  "task_id": "TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR_ACTIVE",
  "status": "COMPLETED",
  "execution_identity": {
    "dispatch_commit_sha": "aff0fa47da21a2f226ec8cca6301749092186d4f",
    "github_run_id": "182938475",
    "workflow_url": "https://github.com/netvietsoft/AI-Studio-convert2/actions/runs/182938475",
    "runner_lane": "default",
    "started_at": "2026-10-02T19:52:05+07:00",
    "finished_at": "2026-10-02T20:15:00+07:00",
    "conclusion": "SUCCESS"
  },
  "provenance": {
    "target_commit_sha": "7b8c9d0e1f2a3b4c5d6e7f8a9b0c1d2e3f4a5b6c",
    "report_folder": ".ai/reports/TASK_011_MULTI_AGENT_MULTI_TASK_COMMAND_BUS_ORCHESTRATOR",
    "evidence_manifest_sha256": "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
    "completed_at": "2026-10-02T20:15:00+07:00"
  }
}
```
