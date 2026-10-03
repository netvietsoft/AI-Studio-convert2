# ĐẶC TẢ BỘ BA LỆNH KIỂM ĐỊNH CHẤP NHẬN (ACCEPTANCE COMMANDS SPECIFICATION)
# 05_ACCEPTANCE_COMMANDS_SPECIFICATION.md
**Nhiệm Vụ:** TASK_024 — Multi-Agent Correction  
**Tiêu Chuẩn:** Development Workspace Standard V2.1.2 & 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Giao Thức:** CONVERT2_COMMAND_V2  
**Thư Mục Lưu Trữ:** `.ai/commands/pending/`

---

## 1. MỤC TIÊU BỘ LỆNH KIỂM ĐỊNH

Nhằm phục vụ đợt nghiệm thu thực tế 3-way parallel execution ngay sau khi TASK_024 được merge vào nhánh `main`, hệ thống đã thiết lập 3 lệnh kiểm định chấp nhận độc lập tuyệt đối về tài nguyên, làn thực thi và đường dẫn file, đồng thời gán nhãn đích danh cho 3 Runner vật lý khác nhau.

---

## 2. CHI TIẾT ĐẶC TẢ TỪNG COMMAND

### A. Command 1: Kiểm Tra Sức Khỏe Runner Pool (Runner 01)
- **File:** `.ai/commands/pending/CMD_ACCEPT_024_01_RUNNER_POOL_HEALTH_20261003T150000+0700.json`
- **Command ID:** `CMD_ACCEPT_024_01_RUNNER_POOL_HEALTH_20261003T150000+0700`
- **Task ID:** `TASK_024_ACCEPTANCE_01_RUNNER_POOL_HEALTH`
- **Target Runner:** `CONVERT2-WINDOWS-01`
- **Execution Lane:** `infra-acceptance-01`
- **Độ Ưu Tiên:** 95
- **Tài Nguyên Khóa (`locked_modules`):** `["acceptance-runner-01"]`
- **Phạm Vi Cho Phép (`allowed_paths`):**
  - `.ai/reports/acceptance/TASK_024_01/**`
  - `.ai/state/tasks/TASK_024_ACCEPTANCE_01*`
- **Mục Tiêu:** Xác nhận Runner 01 tiếp nhận job sau khi hoàn thành nhiệm vụ điều phối và hòa nhập nhánh chính.

### B. Command 2: Kiểm Tra Tính Xác Thực Nguồn Gốc (Runner 02)
- **File:** `.ai/commands/pending/CMD_ACCEPT_024_02_EVIDENCE_PROVENANCE_20261003T150000+0700.json`
- **Command ID:** `CMD_ACCEPT_024_02_EVIDENCE_PROVENANCE_20261003T150000+0700`
- **Task ID:** `TASK_024_ACCEPTANCE_02_EVIDENCE_PROVENANCE`
- **Target Runner:** `CONVERT2-WINDOWS-02`
- **Execution Lane:** `infra-acceptance-02`
- **Độ Ưu Tiên:** 95
- **Tài Nguyên Khóa (`locked_modules`):** `["acceptance-runner-02"]`
- **Phạm Vi Cho Phép (`allowed_paths`):**
  - `.ai/reports/acceptance/TASK_024_02/**`
  - `.ai/state/tasks/TASK_024_ACCEPTANCE_02*`
- **Mục Tiêu:** Kiểm định các file đối chiếu nguồn gốc và dữ liệu GitHub API trên môi trường Runner 02.

### C. Command 3: Kiểm Tra Kết Nối Thiết Bị Vật Lý (Runner 03)
- **File:** `.ai/commands/pending/CMD_ACCEPT_024_03_DEVICE_CONNECTIVITY_20261003T150000+0700.json`
- **Command ID:** `CMD_ACCEPT_024_03_DEVICE_CONNECTIVITY_20261003T150000+0700`
- **Task ID:** `TASK_024_ACCEPTANCE_03_DEVICE_CONNECTIVITY`
- **Target Runner:** `CONVERT2-WINDOWS-03`
- **Execution Lane:** `infra-acceptance-03`
- **Độ Ưu Tiên:** 95
- **Tài Nguyên Khóa (`locked_modules`):** `["acceptance-runner-03"]`
- **Phạm Vi Cho Phép (`allowed_paths`):**
  - `.ai/reports/acceptance/TASK_024_03/**`
  - `.ai/state/tasks/TASK_024_ACCEPTANCE_03*`
- **Mục Tiêu:** Kiểm tra trạng thái kết nối ADB và thiết bị kiểm thử vật lý (Samsung Galaxy A50) trên Runner 03.

---

## 3. KẾT QUẢ ĐÁNH GIÁ TẬP LỆNH SẴN SÀNG (READY SET EVALUATION)

Lệnh kiểm tra thực thi trên workspace:
```powershell
python scripts/command_bus_orchestrator.py rebuild-index
python scripts/command_bus_orchestrator.py ready
```

**Kết quả ghi nhận:**
- Cả 3 command đều thỏa mãn các điều kiện tiên quyết:
  1. Dependencies rỗng (`[]`).
  2. Execution lanes hoàn toàn tách biệt: `infra-acceptance-01`, `infra-acceptance-02`, `infra-acceptance-03`.
  3. Locked modules không xung đột: `acceptance-runner-01`, `acceptance-runner-02`, `acceptance-runner-03`.
  4. Allowed paths không giao nhau.
- Kết luận: Thuật toán lập lịch của Orchestrator đánh giá **CẢ 3 COMMAND CÙNG ĐẠT TRẠNG THÁI READY ĐỒNG THỜI**.

---

## 4. QUY TRÌNH KÍCH HOẠT TỰ ĐỘNG TẠI CỔNG TÍCH HỢP

Khi TASK_024 hoàn thành:
1. Agent nộp báo cáo và kết thúc lượt chạy hiện tại.
2. Script tích hợp tuần tự (`convert2-integrator.yml`) thực hiện merge branch `agent/TASK_024_...` vào nhánh `main`.
3. Sự kiện push vào `main` kích hoạt `convert2-dispatcher.yml`.
4. Dispatcher quét thư mục `.ai/commands/pending/`, nhận diện 3 command sẵn sàng, chuyển sang `reserved/` và phát lệnh `gh workflow run convert2-worker.yml` với nhãn runner tương ứng.
5. Cả 3 Runner 01, Runner 02, Runner 03 cùng lúc nhận job và bắt đầu thực thi song song thực sự.
