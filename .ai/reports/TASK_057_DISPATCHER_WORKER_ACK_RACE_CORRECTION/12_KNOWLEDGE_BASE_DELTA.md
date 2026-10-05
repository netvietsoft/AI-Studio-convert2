# 12_KNOWLEDGE_BASE_DELTA.md — PHẦN GIA TĂNG KHO TRI THỨC ĐIỀU PHỐI TỰ ĐỘNG
**Thẩm quyền:** Chủ tịch Tony (Chairman)  
**Task ID:** `TASK_057_DISPATCHER_WORKER_ACK_RACE_AND_CONTINUOUS_EXECUTION_CORRECTION_ACTIVE`  
**Thời gian lập:** `2026-10-05T07:24:40.312086+07:00`  

---

## 1. BÀI HỌC VẬN HÀNH ĐIỀU PHỐI (ORCHESTRATION LEARNINGS)

### A. Phối Hợp Bất Đồng Bộ Giữa Dispatcher Trên Mây và Self-Hosted Worker
1. **Hiện tượng:** Khi kích hoạt `gh workflow run`, GitHub Actions tiếp nhận yêu cầu gần như tức thì, nhưng việc phân bổ self-hosted runner có thể mất từ 30s đến 90s tùy thuộc vào trạng thái bận của máy runner và thời gian tải git repo.
2. **Kinh nghiệm:** Không bao giờ được dùng cơ chế timeout cố định ngắn (như 90s) để suy diễn rằng worker đã chết và tự ý rollback trạng thái về `PENDING`.
3. **Giải pháp chuẩn hóa:**
   - Worker phải chủ động gửi handshake (Step 5A push to main) ngay khi claim xong và trước khi chạy tác vụ nặng.
   - Dispatcher phải truy vấn trạng thái thực của run trên GitHub API trước khi kết luận thất bại. Nếu worker đang `in_progress` hoặc `queued`, phải bảo lưu trạng thái `RESERVED` để ngăn chặn double-dispatch.

### B. Tính Lũy Đẳng Trong Vòng Đời Command (Idempotent Lifecycle)
1. Trong môi trường phân tán, các worker có thể bị khởi động lại hoặc retry. Hàm `claim_command` và `start_command` phải hỗ trợ tiếp tục (resume) nếu runner yêu cầu trùng khớp với bên đang nắm giữ lease.
2. Việc chấp nhận `IDEMPOTENT_CLAIM` và `IDEMPOTENT_START` giúp ngăn ngừa hiện tượng runner tự bắn vào chân mình khi gặp sự cố mạng tạm thời.

### C. Quản Lý Đường Dẫn Phân Phối Báo Cáo (Report Package Distribution)
1. Tệp bàn giao kết quả cuối cùng (`CONVERT2_TASK*.zip` và `*.sha256`) cần được xem là tệp hòa giải dùng chung (`SHARED_RECONCILED_PATHS`) để không bị chặn bởi cổng kiểm duyệt đường dẫn nghiêm ngặt của Serial Integrator.
