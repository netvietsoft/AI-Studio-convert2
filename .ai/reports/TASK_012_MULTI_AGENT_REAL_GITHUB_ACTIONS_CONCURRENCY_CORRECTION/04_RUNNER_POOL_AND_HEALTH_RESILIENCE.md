# 04. KHẢO SÁT & TỰ PHỤC HỒI KIỂM ĐỊNH RUNNER POOL
# (04_RUNNER_POOL_AND_HEALTH_RESILIENCE.md)
**Nhiệm Vụ:** TASK_012 — MULTI-AGENT REAL GITHUB ACTIONS CONCURRENCY CORRECTION  
**Host:** `OSIN` (Microsoft Windows 11 Pro 64-bit)  
**Ngày:** 2026-10-03  
**Trạng Thái:** 3/3 RUNNERS ONLINE (CAPACITY: 3 CONCURRENT JOBS)

---

## 1. NGUYÊN NHÂN LỖI API 403 & CƠ CHẾ TỰ BẢO VỆ

### 1.1 Hiện tượng
Khi các tác vụ kiểm tra hạ tầng (như `test_runner_pool_health.ps1` hoặc `bootstrap_convert2_runner_pool.ps1`) chạy trong môi trường GitHub Actions tự động:
```text
gh api "repos/netvietsoft/AI-Studio-convert2/actions/runners"
HTTP 403: Resource not accessible by integration
```
Token workflow của GitHub không có quyền hạn quản trị self-hosted runner pool. Nếu không có cơ chế xử lý ngoại lệ, script sẽ nhận `null` và báo sai lệch rằng 0 runner đang online.

### 1.2 Giải pháp Fallback Cục Bộ (Local Host Inspection)
Trên máy chủ Windows `OSIN`, script kiểm tra trực tiếp:
1. Đọc file cấu hình `.runner` tại các thư mục cài đặt `C:\actions-runner*` để lấy `agentId`, `agentName`, `workFolder`.
2. Truy vấn WMI/CIM tìm tiến trình `Runner.Listener.exe` đang hoạt động tương ứng với đường dẫn.
3. Kiểm tra tiến trình con `Runner.Worker.exe` để phân định trạng thái `(BUSY)` hay `(IDLE)`.

---

## 2. HIỆN TRẠNG 3 RUNNER VẬT LÝ TRÊN MÁY CHỦ `OSIN`

Kết quả kiểm tra trực tiếp qua `scripts/bootstrap_convert2_runner_pool.ps1 -StatusOnly`:

```text
[2026-10-03 12:49:11] [INFO] ==========================================================
[2026-10-03 12:49:11] [INFO] CONVERT2 RUNNER POOL BOOTSTRAP & VALIDATION
[2026-10-03 12:49:11] [INFO] ==========================================================
[2026-10-03 12:49:11] [INFO] Validating tool dependencies...
[2026-10-03 12:49:11] [INFO]   [OK] git: D:\SetupC\Git\cmd\git.exe
[2026-10-03 12:49:11] [INFO]   [OK] python: C:\Python314\python.exe
[2026-10-03 12:49:11] [INFO]   [OK] agy: C:\Users\PC.DESKTOP-81LIH38\AppData\Local\agy\bin\agy.exe
[2026-10-03 12:49:11] [INFO]   [OK] adb (auto-resolved from Sdk): C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\platform-tools\adb.exe
[2026-10-03 12:49:11] [INFO]   [OK] gh: C:\Program Files\GitHub CLI\gh.exe
[2026-10-03 12:49:12] [INFO] Checking runner: CONVERT2-WINDOWS-01 in C:\actions-runner... [OK]
[2026-10-03 12:49:13] [INFO] Checking runner: CONVERT2-WINDOWS-02 in C:\actions-runner-02... [OK]
[2026-10-03 12:49:14] [INFO] Checking runner: CONVERT2-WINDOWS-03 in C:\actions-runner-03... [OK]
[2026-10-03 12:49:17] [INFO] ==========================================================
[2026-10-03 12:49:17] [INFO] CURRENT GITHUB ACTIONS RUNNER POOL INVENTORY
[2026-10-03 12:49:17] [INFO] ==========================================================
[2026-10-03 12:49:18] [INFO] [ONLINE] CONVERT2-WINDOWS-01 (PID: 52340) (BUSY) - Work: convert2, Label: worker-1
[2026-10-03 12:49:19] [INFO] [ONLINE] CONVERT2-WINDOWS-02 (PID: 25036) (BUSY) - Work: _work, Label: worker-2
[2026-10-03 12:49:20] [INFO] [ONLINE] CONVERT2-WINDOWS-03 (PID: 37784) (IDLE) - Work: _work, Label: worker-3
[2026-10-03 12:49:20] [INFO] ----------------------------------------------------------
[2026-10-03 12:49:20] [INFO] Summary: 3 / 3 local runners ONLINE (Capacity: 3)
[2026-10-03 12:49:20] [INFO] SUCCESS: Full capacity (3/3) active and listening for jobs.
```

---

## 3. BẢNG TỔNG HỢP NĂNG LỰC RUNNER POOL

| Runner Name | Runner ID | Đường Dẫn Cài Đặt | Thư Mục Work | Tiến Trình Listener | Trạng Thái Thực Tế |
| :--- | :---: | :--- | :--- | :---: | :---: |
| **CONVERT2-WINDOWS-01** | 2 | `C:\actions-runner` | `convert2` | PID 52340 | **ONLINE (BUSY: Task 012)** |
| **CONVERT2-WINDOWS-02** | 3 | `C:\actions-runner-02` | `_work` | PID 25036 | **ONLINE (BUSY: Task 026)** |
| **CONVERT2-WINDOWS-03** | 4 | `C:\actions-runner-03` | `_work` | PID 37784 | **ONLINE (IDLE)** |

Năng lực song song tối đa đạt 3 jobs đồng thời trên máy chủ `OSIN`.
