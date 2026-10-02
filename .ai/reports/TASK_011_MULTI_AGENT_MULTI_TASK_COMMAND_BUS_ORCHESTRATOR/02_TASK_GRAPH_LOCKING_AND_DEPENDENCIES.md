# ĐỒ THỊ NHIỆM VỤ, KHÓA TÀI NGUYÊN & QUẢN TRỊ PHỤ THUỘC (02_TASK_GRAPH_LOCKING_AND_DEPENDENCIES.md)
# Nhiệm Vụ: TASK_011 — MULTI-AGENT / MULTI-TASK COMMAND BUS ORCHESTRATOR
**Dự án:** CONVERT2 — Meitu Reborn  
**Thẩm quyền:** Chủ tịch Tony & Agent 0 (CEO / Orchestrator)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  

---

## 1. MÔ HÌNH ĐỒ THỊ NHIỆM VỤ (DAG - DIRECTED ACYCLIC GRAPH)

Hệ thống `CommandBusOrchestrator` tổ chức các nhiệm vụ dưới dạng đồ thị có hướng không chu trình (DAG). Mỗi nút là một Command, và các cạnh có hướng biểu diễn quan hệ phụ thuộc (`dependencies`).

### 1.1. Giải Thuật Đánh Giá Sẵn Sàng (Ready Set Computation)
Khi quét hàng đợi, Orchestrator duyệt toàn bộ danh sách lệnh có trạng thái `PENDING`, `QUEUED` hoặc `WAITING_DEPENDENCY`:
1. **Sắp xếp theo thứ tự ưu tiên:**
   - Trọng số ưu tiên giảm dần: `CRITICAL (100)` > `HIGH (80)` > `NORMAL (50)` > `LOW (20)`.
   - Thời điểm tạo `created_at` tăng dần (FIFO trong cùng mức ưu tiên).
2. **Kiểm tra phụ thuộc (Dependency Gate):**
   - Lệnh con $C_{down}$ chỉ được kích hoạt nếu **toàn bộ** mã lệnh hoặc mã task trong mảng `dependencies` đã đạt trạng thái `COMPLETED` hoặc `AUDITED_PASS`.
   - Nếu còn ít nhất một phụ thuộc chưa hoàn thành: $C_{down}$ bị chuyển sang trạng thái `WAITING_DEPENDENCY` và ghi nhận `blocked_by_dependencies`.
3. **Kiểm tra xung đột khóa (Lock Collision Gate):**
   - Đối chiếu tài nguyên của ứng viên với toàn bộ các lệnh đang `CLAIMED` hoặc `RUNNING`.
   - Nếu phát hiện trùng module hoặc trùng đường dẫn: Ứng viên bị chuyển sang trạng thái `QUEUED` và ghi nhận `queue_reason`.
4. **Kiểm tra dung lượng luồng thực thi (Lane Capacity Gate):**
   - Mỗi execution lane có hạn ngạch runner đồng thời tối đa (mặc định: 2 runners/lane).
   - Nếu số lệnh đang active trong lane đã chạm ngưỡng: Lệnh tiếp theo chuyển sang `QUEUED` (báo cáo trung thực, không mạo danh `RUNNING`).

---

## 2. CƠ CHẾ KHÓA TÀI NGUYÊN (RESOURCE LOCKING)

Hệ thống áp dụng cơ chế khóa hai tầng: **Khóa Phân Cụm Module (Module Lock)** và **Khóa Đường Dẫn File Chi Tiết (Path Overlap Lock)**.

### 2.1. Khóa Phân Cụm Module (Module Locks)
Mỗi lệnh có thể định danh các phân hệ logic mà nó sở hữu:
- `infra`: Các script điều phối, quy chuẩn, GitHub Actions workflows.
- `core-graphics`: Mã nguồn C++ Native (`lib-core-graphics/src/main/cpp/*`).
- `photo-editor`: Module ứng dụng chỉnh sửa ảnh Kotlin/Java.
- `video-engine`: Lõi biên tập và render video timeline.
- `billing`: Hệ thống Google Play / Meitu VIP Billing.

**Quy tắc:** Hai lệnh có giao tập `locked_modules` khác rỗng ($\mathcal{M}_1 \cap \mathcal{M}_2 \neq \emptyset$) **TUYỆT ĐỐI KHÔNG ĐƯỢC CHẠY SONG SONG**.

### 2.2. Khóa Đường Dẫn File Chi Tiết (Path Overlap Detection)
Giải thuật `paths_conflict(p1, p2)` kiểm soát va chạm từng đường dẫn:
```python
def paths_conflict(p1: str, p2: str) -> bool:
    p1 = normalize_path_pattern(p1)
    p2 = normalize_path_pattern(p2)
    if p1 == p2:
        return True
    p1_clean = p1.rstrip('/*')
    p2_clean = p2.rstrip('/*')
    if p1_clean == p2_clean:
        return True
    if p1.endswith('/*') or p1.endswith('/**'):
        prefix = p1.split('/*')[0].split('/**')[0]
        if p2 == prefix or p2.startswith(prefix + '/'):
            return True
    if p2.endswith('/*') or p2.endswith('/**'):
        prefix = p2.split('/*')[0].split('/**')[0]
        if p1 == prefix or p1.startswith(prefix + '/'):
            return True
    if fnmatch.fnmatch(p1, p2) or fnmatch.fnmatch(p2, p1):
        return True
    return False
```
Ví dụ thực tế:
- `lib-core-graphics/*` xung đột với `lib-core-graphics/src/jni_bridge.cpp` -> **CONFLICT (SERIALIZED)**.
- `lib-photo-editor/*` không xung đột với `lib-video-engine/*` -> **INDEPENDENT (PARALLEL PASS)**.

---

## 3. CHIẾN LƯỢC CÔ LẬP WORKTREE & BRANCH CHO MULTI-AGENT

Nhằm ngăn chặn tình trạng nhiều Agent đồng thời push commit gây xung đột mã nguồn trên nhánh `main`:
1. **Phạm vi Infrastructure:** Các lệnh cập nhật `.ai/commands/*`, `.ai/state/*`, `.ai/reports/*` được điều phối qua cơ chế khóa FileLock nguyên tử trên nhánh làm việc chính thức.
2. **Phạm vi Mã Nguồn Tính Năng (Feature Code):**
   - Mỗi Agent nhận một nhánh riêng biệt: `feature/<task_id>`.
   - Sử dụng Git Worktree riêng biệt (`worktrees/<task_id>/`) để tránh can thiệp file nháp của nhau.
   - Chỉ khi toàn bộ kiểm thử và thẩm định độc lập PASS, Orchestrator mới thực hiện Fast-forward hoặc Squash Merge vào `main`.
3. **Cấm Tuyệt Đối Can Thiệp Vùng Đóng Băng:**
   - Các file thuộc P0 (`tau_aspect = 1.80`, BiSeNet preprocessing, model weights) được khóa cứng bằng `files_forbidden` trong `locks.json`.
