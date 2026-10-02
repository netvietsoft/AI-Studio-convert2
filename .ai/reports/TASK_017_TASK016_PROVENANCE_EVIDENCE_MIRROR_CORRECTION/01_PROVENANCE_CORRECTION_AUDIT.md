# BIÊN BẢN HIỆU ĐÍNH NGUỒN GỐC GIT COMMIT VÀ TIẾN TRÌNH RUNNER ACTIONS
## 01_PROVENANCE_CORRECTION_AUDIT.md
**Nhiệm vụ:** TASK_017_TASK016_PROVENANCE_EVIDENCE_MIRROR_CORRECTION_ACTIVE  
**Dự án:** CONVERT2 — Face & Beauty Engine  
**Cơ quan ban hành:** Chủ tịch Tony  

---

### 1. NGUỒN GỐC GIT COMMIT (COMMIT PROVENANCE)

#### A. Vấn đề phát hiện
Trong hồ sơ nghiệm thu TASK_016 trước đây, giá trị `target_commit_sha` được ghi nhận trong `.ai/state.json` và `.ai/commands/completed/TASK_016_EXECUTE_*.json` là:
`f5502dd71b0ea1797e8841da3675a6c3826ddae7`.

Khi kiểm tra với Git repository:
- Chuỗi 7 ký tự đầu `f5502dd` thực sự tương ứng với commit triển khai TASK_016.
- Tuy nhiên, 33 ký tự hex phía sau bị ghi sai (do công cụ tiền nhiệm phỏng đoán hoặc sinh chuỗi băm nhân tạo thay vì gọi `git rev-parse`).

#### B. Kết quả thẩm định thực tế bằng Git Engine
```bash
$ git rev-parse f5502dd
f5502ddcbf86db6e95f4ca02f5029bac1f1a99a6
```

Thông tin chi tiết commit:
- **Full SHA:** `f5502ddcbf86db6e95f4ca02f5029bac1f1a99a6`
- **Tác giả:** Thuy <andreathuydung@gmail.com>
- **Thời gian:** Sat Oct 3 00:00:35 2026 +0700
- **Tiêu đề:** `feat(task-016): specialized visual retest for ears and beard features`
- **Các tệp thay đổi:** 13 files, 405 insertions(+), 48 deletions(-)
  - `lib-core-graphics/src/main/cpp/src/landmark_fusion.cpp`
  - `app/src/main/kotlin/com/mt/mtxx/mtxx/editor/PhotoEditorActivity.kt`
  - Báo cáo và bằng chứng trong `.ai/reports/TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_VISUAL_RETEST/`

#### C. Hành động khắc phục
Đã cập nhật đồng bộ toàn bộ chuỗi băm chính xác `f5502ddcbf86db6e95f4ca02f5029bac1f1a99a6` tại:
1. `.ai/state.json` (thuộc tính `last_target_commit_sha` và `provenance.target_commit_sha`)
2. `.ai/commands/completed/TASK_016_EXECUTE_20261002T235400+0700.json`
3. `.ai/commands/history/TASK_016_EXECUTE_20261002T235400+0700.json`
4. `.ai/state/tasks/TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_VISUAL_RETEST.json`
5. `.ai/reports/TASK_016_FACE_BEAUTY_EAR_BEARD_SPECIALIZED_VISUAL_RETEST/07_MEMORY_HANDOFF.md`

---

### 2. NGUỒN GỐC TIẾN TRÌNH ACTIONS (ACTIONS PROVENANCE DISENTANGLEMENT)

#### A. Vấn đề phát hiện
Hồ sơ TASK_016 cũ gán:
```json
"runner_identity": "GITHUB_ACTIONS_37028118019",
"actions_run_id": "37028118019"
```
Khi tra cứu GitHub API (`gh run list`), Run ID `37028118019` thực chất là tiến trình của **TASK_015** (chạy lúc `2026-10-02T15:36:01Z` cho commit `7148fec`). Đây là sự nhầm lẫn chéo tác vụ (cross-task identifier mismatch).

#### B. Dữ liệu thực tế từ GitHub API
| Actions Run ID | Commit SHA | Tiêu đề commit | Thời điểm push (UTC) | Kết luận điều tra |
|:---:|:---:|:---|:---:|:---|
| `37028118019` | `7148fec` | `chore(command-bus): dispatch TASK_015 eye brow landmark correction` | 2026-10-02T15:36:01Z | **Thuộc về TASK_015** (không được dùng cho TASK_016) |
| `37037134655` | `3401a1c` | `chore(command-bus): dispatch TASK_016 ear beard specialized visual re...` | 2026-10-02T16:54:43Z | **Dispatch attempt của TASK_016** (Trạng thái: FAILURE do thiếu secrets runner) |
| *Cục bộ* | `3401a1c` | *AGENT_WATCHDOG_V2 Local Autonomous Recovery Turn* | 2026-10-02T17:00:00Z | **Tiến trình thực thi thực tế của TASK_016** |
| `37039843854` | `41757eb` | `chore(command-bus): record TASK_016 specialized retest completion and...` | 2026-10-02T17:18:43Z | **Push CI Run ghi nhận kết quả TASK_016** (Trạng thái: SUCCESS) |

#### C. Hành động khắc phục
Đã tái cấu trúc trường `provenance` trong `.ai/state.json`:
- `runner_identity`: `"AGENT_WATCHDOG_V2_LOCAL"`
- `dispatch_attempt_run_id`: `"37037134655"` (ghi nhận dispatch lỗi rõ ràng)
- `dispatch_status`: `"DISPATCH_FAILED_RECOVERED_LOCALLY"`
- `recovery_runner`: `"AGENT_WATCHDOG_V2"`
- `post_completion_run_id`: `"37039843854"`
- Xóa bỏ triệt để định danh `37028118019` khỏi toàn bộ metadata của TASK_016.
