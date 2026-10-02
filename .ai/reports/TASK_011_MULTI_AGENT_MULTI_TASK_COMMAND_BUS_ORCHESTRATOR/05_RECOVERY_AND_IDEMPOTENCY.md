# CƠ CHẾ PHỤC HỒI SỰ CỐ & TÍNH LŨY ĐẲNG TUYỆT ĐỐI (05_RECOVERY_AND_IDEMPOTENCY.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. NGUYÊN TẮC BẤT BIẾN: CHỐNG NHÂN BẢN & CHỐNG CHẠY LẶP
Trong môi trường thực thi tự hành dài hạn (Headless Autonomous Execution), lỗi mạng, mất điện, máy chủ khởi động lại hoặc runner timeout là những rủi ro thường trực.
Hai lỗi vận hành nguy hiểm nhất cần triệt tiêu là:
1. **Silent Duplication (Nhân bản ngầm):** Khi runner bị ngắt, hệ thống tự động sinh thêm lệnh mới song song khiến hai runner cùng can thiệp một tác vụ.
2. **Infinite Retry Loop (Vòng lặp thử lại vô hạn):** Lặp đi lặp lại một tác vụ lỗi mà không ghi nhận lịch sử thất bại.

---

## 2. GIẢI THUẬT PHỤC HỒI KHÓA THUÊ QUÁ HẠN (STALE LEASE RECOVERY)

### 2.1. Định Nghĩa Khóa Quá Hạn (Stale Lease)
Khi một runner nhận quyền thực thi qua `claim_command()`, một hợp đồng thuê (lease) có thời hạn được tạo lập:
- `lease_token`: Mã UUID bí mật cấp riêng cho runner.
- `leased_at`: Thời điểm bắt đầu thuê.
- `lease_expires_at`: Hạn chót của hợp đồng thuê (mặc định: 1800 giây = 30 phút).
- `heartbeat_at`: Thời điểm runner gửi tín hiệu duy trì sự sống gần nhất.

Một lệnh bị coi là **Stale Lease** khi:
$$\text{Current UTC Time} > \text{lease\_expires\_at}$$
và trạng thái của lệnh vẫn đang nằm ở `CLAIMED` hoặc `RUNNING`.

### 2.2. Quy Trình Thu Hồi Xác Định (Deterministic Recovery Flow)
Hàm `recover_stale_leases()` hoạt động theo quy trình nghiêm ngặt:
1. **Quét thư mục `claimed/` và `running/`:** Đọc toàn bộ các file lệnh JSON.
2. **Kiểm tra hạn dùng:** Nếu quá hạn và không có cập nhật báo cáo:
3. **Thu hồi lệnh về hàng đợi PENDING:**
   - Di chuyển nguyên tử file JSON từ `claimed/` hoặc `running/` về lại `.ai/commands/pending/<command_id>.json`.
   - Xóa bỏ trường `lease` (đặt về `null`), vô hiệu hóa `lease_token` cũ.
   - Tăng biến đếm `retry_count += 1`.
   - Ghi nhật ký phục hồi chi tiết vào trường `stale_recovery_record`:
     ```json
     "stale_recovery_record": {
       "recovered_at": "2026-10-02T20:14:42+07:00",
       "previous_holder": "crashed-runner-01",
       "expired_at": "2026-10-02T20:10:00+07:00",
       "attempt": 1
     }
     ```
4. **Cập nhật per-task state:** Ghi rõ thời điểm phục hồi vào `.ai/state/tasks/<task_id>.json`.
5. **Cập nhật lại Index:** Báo cáo chính xác số lượng lệnh pending để vòng quét Watchdog tiếp theo điều phối an toàn.

---

## 3. CƠ CHẾ LŨY ĐẲNG DỰA TRÊN KHÓA CHỐNG TRÙNG (ANTI-DUPLICATE KEY)

Khóa chống trùng được tính toán theo công thức bất biến:
$$\text{anti\_duplicate\_key} = \text{task\_id} + \text{":"} + \text{task\_revision}$$

### 3.1. Hành Vi Xử Lý Trùng Lặp (Idempotent Duplicate Rejection)
Khi tiếp nhận yêu cầu `create_command()`:
- Orchestrator duyệt toàn bộ cơ sở dữ liệu lệnh hiện hành (`pending`, `claimed`, `running`, `completed`).
- Nếu tồn tại một lệnh có cùng `anti_duplicate_key` và trạng thái nằm trong nhóm đang xử lý hoặc đã hoàn tất:
  -> **TỪ CHỐI THẲNG THỪNG (DUPLICATE_REJECTED)**.
  -> Không tạo thêm file, không ghi đè, không phát lệnh dư thừa.

### 3.2. Xử Lý Khi Có Bản Sửa Đổi Mới Của Task (Updated Revision)
- Nếu Task trên Google Drive được Chủ tịch Tony cập nhật (ví dụ: `task_revision` thay đổi từ `rev_1` sang `rev_2` do modified time mới hơn):
- Khóa chống trùng mới sẽ là: `TASK_XXX:rev_2`.
- Khóa này hoàn toàn khác biệt với `TASK_XXX:rev_1`, do đó hệ thống tự động chấp thuận tạo một chu trình thực thi mới để đáp ứng yêu cầu sửa đổi mà không bị nhầm lẫn với bản cũ đã hoàn tất.
