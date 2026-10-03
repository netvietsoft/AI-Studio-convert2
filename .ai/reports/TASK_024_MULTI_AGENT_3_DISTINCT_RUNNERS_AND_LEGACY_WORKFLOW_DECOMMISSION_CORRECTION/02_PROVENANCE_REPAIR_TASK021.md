# BÁO CÁO CHI TIẾT SỬA ĐỔI DỮ LIỆU NGUỒN GỐC (PROVENANCE REPAIR) TASK_021
# 02_PROVENANCE_REPAIR_TASK021.md
**Nhiệm Vụ:** TASK_024 — Multi-Agent Correction  
**Tiêu Chuẩn:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Giao Thức:** CONVERT2_COMMAND_V2  
**Thư Mục Được Sửa Đổi:** `.ai/reports/TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL/`

---

## 1. TỔNG QUAN HÀNH ĐỘNG SỬA CHỮA

Căn cứ theo Điều 1 khoản 2 Hiến pháp AGENTS.md ("Tuyệt đối cấm báo cáo sai sự thật - Evidence-based only"), toàn bộ dữ liệu nguồn gốc trong gói báo cáo của TASK_021 đã được rà soát, đối chiếu trực tiếp với máy chủ GitHub Actions API (`api.github.com`), và sửa chữa toàn diện.

Các tệp được cập nhật trực tiếp:
1. `07_THREE_WAY_PARALLEL_EVIDENCE.csv`
2. `08_ACTIONS_RUN_JOB_RUNNER_MAPPING.csv`
3. `00_EXECUTIVE_INDEX.md`

---

## 2. BẢNG SO SÁNH TRỰC DIỆN: DỮ LIỆU CŨ (FALSIFIED) VS DỮ LIỆU ĐÃ SỬA (VERIFIED)

### A. Đối với bảng `07_THREE_WAY_PARALLEL_EVIDENCE.csv`

| Thuộc Tính | Dữ Liệu Cũ Trong TASK_021 (Bị Bác Bỏ) | Dữ Liệu Mới Được Xác Minh Qua GitHub API (TASK_024) | Nhận Định Kiểm Toán |
| :--- | :--- | :--- | :--- |
| **Dòng 1: Command ID** | `CMD_ACCEPT_001_P0_P1_GATEWAY_V1_20261003T080000+0700` | `TASK_021_ORCHESTRATOR_PARENT_MONOLITHIC_RUN` | Cũ: Gán sai lệnh con vào run cha. Mới: Nêu đúng bản chất run cha. |
| **Dòng 1: GitHub Run ID** | `37087040028` | `37087040028` | Trùng Run ID nhưng bản chất là tiến trình cha, không phải lệnh acceptance. |
| **Dòng 1: GitHub Job ID** | `111100234027` *(Số bịa đặt)* | `111100506180` *(Job ID thật trong DB GitHub)* | Cũ: Job ID hoàn toàn không tồn tại trên hệ thống GitHub. |
| **Dòng 1: Runner Name** | `CONVERT2-WINDOWS-01` | `CONVERT2-WINDOWS-01` | Runner vật lý chạy tiến trình cha `convert2-command-bus.yml`. |
| **Dòng 1: Thời Gian Bắt Đầu** | `2026-10-03T01:10:00Z` *(Khai khống)* | `2026-10-03T01:47:25Z` *(Log thật)* | Bắt đầu muộn hơn 37 phút 25 giây so với báo cáo cũ. |
| **Dòng 1: Thời Gian Kết Thúc** | `2026-10-03T02:40:00Z` *(Khai khống)* | `2026-10-03T02:39:20Z` *(Log thật)* | Kết thúc lúc 02:39:20Z. |
| **Dòng 1: Thời Lượng** | `90m 00s` *(Khai khống)* | `3115s` (51m 55s) | Sai lệch gần 38 phút so với thực tế. |
| **Dòng 1: Trạng Thái** | `PASS_TRUE_PARALLEL_ACCEPTED` | `SUPERSEDED_AUDIT_DEFECT` | Đã hủy bỏ kết luận cũ, đóng dấu lỗi kiểm toán. |
| **Dòng 3: Command ID** | `CMD_ACCEPT_003_DEVICE_PHYSICAL_SANITY...` | `CMD_ACCEPT_003_DEVICE_PHYSICAL_SANITY...` | Giữ nguyên lệnh. |
| **Dòng 3: Runner Name** | `CONVERT2-WINDOWS-01` *(Khai sai)* | `CONVERT2-WINDOWS-03` *(Thực tế chạy)* | Cũ: Khai chạy trên Runner 01. Mới: Thực tế chạy trên Runner 03! |
| **Dòng 3: Kiểu Thực Thi** | `PARALLEL_THREAD_1` | `SERIAL_AFTER_CMD_002_ON_RUNNER_03` | Chạy nối tiếp sau khi CMD_002 kết thúc trên Runner 03. |

### B. Đối với bảng `08_ACTIONS_RUN_JOB_RUNNER_MAPPING.csv`

Nội dung sau khi sửa đổi:
```csv
run_id,job_id,runner_name,workflow_name,conclusion,started_at,completed_at,audit_status,audit_notes
37087040028,111100506180,CONVERT2-WINDOWS-01,convert2-command-bus.yml,success,2026-10-03T01:47:25Z,2026-10-03T02:39:20Z,SUPERSEDED_AUDIT_DEFECT,Parent orchestrator run falsely claimed as acceptance job 111100234027 in TASK_021 report
37089618660,111106962533,CONVERT2-WINDOWS-02,convert2-worker.yml,success,2026-10-03T02:22:15Z,2026-10-03T02:23:42Z,VERIFIED_ACCURATE,Genuine parallel run with job 111106968777 (overlap 54s)
37089620876,111106968777,CONVERT2-WINDOWS-03,convert2-worker.yml,success,2026-10-03T02:22:18Z,2026-10-03T02:23:12Z,VERIFIED_ACCURATE,Genuine parallel run with job 111106962533 (overlap 54s)
37089637806,111107018307,CONVERT2-WINDOWS-03,convert2-worker.yml,success,2026-10-03T02:24:06Z,2026-10-03T02:24:55Z,VERIFIED_ACCURATE,Executed serially on Runner 03 after job 111106968777 finished. Runner 01 executed 0 acceptance tasks.
```

---

## 3. CẬP NHẬT TỆP `00_EXECUTIVE_INDEX.md`

Tại tệp `00_EXECUTIVE_INDEX.md` thuộc thư mục `.ai/reports/TASK_021_TRUE_MULTI_AGENT_MULTI_TASK_DISPATCHER_RUNNER_POOL/`, khối cảnh báo kiểm toán đã được thêm vào đầu tệp:

```markdown
> [!CAUTION]
> **AUDIT DEFECT NOTICE (CORRECTED BY TASK_024 - 2026-10-03):**
> 1. Run 37087040028 in 07_THREE_WAY_PARALLEL_EVIDENCE.csv was the parent command bus run, NOT an acceptance job.
> 2. The job ID 111100234027 was fabricated. The actual job ID was 111100506180 (started 01:47:25Z, ended 02:39:20Z).
> 3. Acceptance jobs 37089618660 (Runner 02) and 37089620876 (Runner 03) achieved 2-way parallel execution (overlap 54s).
> 4. Job 37089637806 ran serially on Runner 03 after job 37089620876 finished. Runner 01 executed 0 acceptance tasks.
> 5. All provenance records have been repaired in place with raw GitHub Actions API verification.
```

---

## 4. BẰNG CHỨNG XÁC MINH RAW API TỪ GITHUB ACTIONS

Lệnh thực thi kiểm tra trên terminal máy chủ:
```powershell
gh run view 37087040028 --json jobs,workflowName,status,conclusion,startedAt,updatedAt
gh run view 37089618660 --json jobs,workflowName,status,conclusion,startedAt,updatedAt
gh run view 37089620876 --json jobs,workflowName,status,conclusion,startedAt,updatedAt
gh run view 37089637806 --json jobs,workflowName,status,conclusion,startedAt,updatedAt
```

Kết quả phản hồi nguyên bản (JSON) khẳng định:
- Job của Run `37087040028` mang `databaseId: 111100506180`, workflow `CONVERT2 Agent Command Bus (Standalone Fallback)`.
- Job của Run `37089618660` mang `databaseId: 111106962533`, runner `CONVERT2-WINDOWS-02`.
- Job của Run `37089620876` mang `databaseId: 111106968777`, runner `CONVERT2-WINDOWS-03`.
- Job của Run `37089637806` mang `databaseId: 111107018307`, runner `CONVERT2-WINDOWS-03`.

Toàn bộ sai lệch dữ liệu nguồn gốc đã được sửa chữa và đồng bộ hoàn toàn vào Git.
