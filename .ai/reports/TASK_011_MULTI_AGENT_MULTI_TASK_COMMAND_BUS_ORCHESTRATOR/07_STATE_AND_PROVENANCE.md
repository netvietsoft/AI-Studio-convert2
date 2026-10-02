# QUẢN TRỊ TRẠNG THÁI PHÂN TÁN & BẢO TOÀN NGUỒN GỐC CHỨNG CỨ (07_STATE_AND_PROVENANCE.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. PHÂN RÃ TRẠNG THÁI: CHẤM DỨT FILE ĐƠN ĐỘC DUY NHẤT
Trước TASK_011, file `.ai/state.json` là nơi lưu trữ toàn bộ trạng thái tiến độ của dự án. Khi nhiều tác vụ chạy đồng thời, việc các Agent cùng mở, đọc và ghi đè `.ai/state.json` sẽ dẫn đến lỗi **Lost Update** chí mạng (Agent này vô tình xóa mất trạng thái của Agent kia).

### 1.1. Kiến Trúc Trạng Thái Hai Tầng (Two-Tier State Hierarchy)
1. **Tầng 1: Per-Task Durable State (`.ai/state/tasks/<task_id>.json`)**
   - Mỗi Task sở hữu một file trạng thái chuyên biệt và độc lập tuyệt đối.
   - Chỉ Agent được cấp lease hợp lệ cho task đó mới có quyền cập nhật file này.
   - Chứa toàn bộ lịch sử chi tiết: thời điểm tạo, thời điểm claim, runner nhận việc, commit dispatch, run_id, commit target nghiệm thu, báo cáo.
2. **Tầng 2: Aggregate Global State (`.ai/state.json`)**
   - Đóng vai trò bản chỉ mục cô đọng (Compact Aggregate Index) cho Orchestrator và Chủ tịch Tony tra cứu nhanh.
   - Mọi thao tác cập nhật vào `.ai/state.json` bắt buộc đi qua cơ chế khóa tệp Reentrant FileLock nguyên tử.
   - Orchestrator thực hiện reconcile tổng hợp từ các file per-task, bảo toàn trọn vẹn dữ liệu của mọi task đang active.

---

## 2. NGUYÊN TẮC BẤT DI BẤT DỊCH VỀ PHÂN TÁCH GIAI ĐOẠN

Quy chuẩn 07 Master Standard quy định rõ ràng:
$$\text{READY} \neq \text{EXECUTED}$$
$$\text{CREATED} \neq \text{DISPATCHED}$$
$$\text{DISPATCHED} \neq \text{EXECUTING}$$

| Trạng Thái | Điều Kiện Xác Lập Thực Tế | Điều Cấm Đoán |
| :--- | :--- | :--- |
| **CREATED** | Task doc xuất hiện trên Task Drive Google Doc | CẤM báo cáo là "Agent đang chạy" |
| **DISPATCHED** | Lệnh đã được ghi vào Command Bus và commit push lên Git | CẤM coi là đã thực thi xong |
| **RUNNING** | Runner/Agent đã claim lease và ghi nhận `started_at` kèm `dispatch_commit_sha` | CẤM mạo danh CPU fallback là GPU running |
| **COMPLETED** | Báo cáo đầy đủ, commit nghiệm thu đã push, bằng chứng đã lưu | CẤM đánh dấu hoàn thành nếu thiếu target SHA hoặc report |

---

## 3. RÀNG BUỘC NGUỒN GỐC CHỨNG CỨ (PROVENANCE ENFORCEMENT)

Hàm `complete_command()` áp dụng các chốt chặn (Hard Guards) tuyệt đối trước khi cho phép một lệnh chuyển sang trạng thái `COMPLETED`:
1. **Target Commit SHA Check:** Mã commit SHA của mã nguồn/bằng chứng sau khi thực thi bắt buộc phải có độ dài $\ge 7$ ký tự và tồn tại trong Git tree.
2. **Report Folder Check:** Đường dẫn thư mục báo cáo `.ai/reports/<TASK_DIR>` bắt buộc phải được khai báo rõ ràng.
3. **Execution Identity Linkage:** Mã commit khởi tạo (`dispatch_commit_sha`) và định danh thực thi (`github_run_id` hoặc runner identity) bắt buộc phải gắn kết với lệnh.
4. **Evidence Manifest Hash:** Mã băm SHA-256 của bảng tổng mục bằng chứng thực nghiệm được lưu trữ để phục vụ công tác thanh tra (Audit).

Nếu bất kỳ điều kiện nào không thỏa mãn, hàm `complete_command()` lập tức từ chối và trả về lỗi, ngăn chặn triệt để hành vi báo cáo khống khi chưa có chứng cứ thực tế.
