# HIẾN PHÁP DÀNH CHO CÁC AI AGENT (AGENTS.md)
# Dự án: CONVERT2 — Hair Color Engine (Phase P1–P6 Parallel Development)
# Cơ quan ban hành: Chủ tịch Tony (Chairman) & Agent 0 (CEO / Orchestrator)
# Tiêu chuẩn: Development Workspace Standard V2.1 + Hiến pháp Vận hành CONVERT

---

## 1. NGUYÊN TẮC BẤT DI BẤT DỊCH
1. **P0 Tuyệt Đối Đóng & Đóng Băng (FROZEN):**
   - Không sửa threshold P0 (`tau_aspect = 1.80` là bất biến).
   - Không sửa BiSeNet P0 preprocessing.
   - Không sửa P0 model hay heuristic.
   - Mọi phase P1–P6 chỉ được **CONSUME** output contract của P0 thông qua Adapter.
2. **Cấm Báo Cáo Sai Sự Thật (Evidence-Based Only):**
   - Không làm test xanh giả tạo.
   - Mọi kết luận PASS phải có chứng cứ thực tế: lệnh build thành công, log test passing, và ảnh chụp kiểm chứng trực tiếp trên thiết bị vật lý thật (Samsung Galaxy A50/SM-A075F).
3. **Cơ Chế Phát Triển Song Song — Tích Hợp Có Cổng (Parallel Development — Gated Integration):**
   - Task implementation được phép diễn ra song song sau khi HCE_CONTRACT_V1 được đóng băng.
   - Được phép dùng mock/fixture để unblock development.
   - CẤM tuyên bố Phase PASS chỉ bằng mock upstream. Tích hợp thực tế và nghiệm thu cuối cùng BẮT BUỘC dùng output thật của upstream.
4. **Không Can Thiệp Ngoài Phạm Vi Task:**
   - Mỗi Agent chỉ được ghi file nằm trong danh sách `files_allowed` và phải giữ lease lock hợp lệ trong `.ai/locks.json`.
   - Cấm trực tiếp commit/push bừa bãi vào main/master mà không qua cổng review độc lập.
5. **Độ Chính Xác Từng Bit, Pixel & Bảo Vệ Vùng Không Can Thiệp:**
   - Không lem da mặt, trán, vành tai, cổ áo, nền tường, thanh công cụ UI.
   - Giữ chiều sâu lọn tóc, vi lỗ chân lông, không bệt màu như sơn.
6. **Sau Mỗi Phiên Trao Đổi Với Chủ Tịch:**
   - BẮT BUỘC đọc lại chuẩn mực gốc: `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\Development_Workspace_Standard_V2.1_Design_Gated.txt`.
======================================================================
BỔ SUNG BẮT BUỘC — AUTONOMOUS TASK SCANNER / CONTINUOUS WORK LOOP
======================================================================

AUTHORITY: Chủ tịch Tony
STATUS: CANONICAL / MANDATORY
PRIORITY: HIGHER THAN OLD "STOP AFTER REPORT" RULES

TASK DRIVE:
https://drive.google.com/drive/u/0/folders/1T9_2fbCGa-q8N6kOZ69WAztLlGmJu60h

REPORT DRIVE:
https://drive.google.com/drive/u/0/folders/13xDIqiI-vyP10pkypLI_6palmeJS-QRg

GIT:
https://github.com/netvietsoft/AI-Studio-convert2


======================================================================
1. QUY TẮC CỐT LÕI
======================================================================

TASK COMPLETE != AGENT COMPLETE.

Hoàn thành một nhiệm vụ KHÔNG được phép làm Agent kết thúc toàn bộ
vòng làm việc.

Sau khi hoàn thành Task:

COMMIT/PUSH
→ REPORT
→ RETURN TO TASK SCANNER
→ SCAN TASK DRIVE
→ NHẬN TASK MỚI
→ THỰC THI

Agent phải hoạt động theo vòng lặp liên tục.


======================================================================
2. THAY ĐỔI Ý NGHĨA "STOP"
======================================================================

Từ thời điểm áp dụng quy tắc này:

STOP

KHÔNG còn có nghĩa:

"Kết thúc Agent."

STOP chỉ có nghĩa:

"Ngừng chỉnh sửa Task hiện tại."

Sau STOP của Task hiện tại, Agent phải:

1. đóng phạm vi Task hiện tại;
2. nộp Report;
3. lưu trạng thái completion;
4. quay về TASK SCANNER;
5. quét Task Drive để tìm Task ACTIVE tiếp theo.

Chỉ được kết thúc toàn bộ Agent nếu có chỉ thị rõ:

END_AGENT_SESSION = TRUE


======================================================================
3. VÒNG ĐỜI AGENT BẮT BUỘC
======================================================================

Agent phải chạy theo state machine:

BOOT
↓
LOAD CANONICAL RULES
↓
TASK_SCANNER
↓
SCAN TASK DRIVE
↓
ACTIVE TASK FOUND?
   ├── YES
   │     ↓
   │   TASK INTAKE
   │     ↓
   │   PREFLIGHT
   │     ↓
   │   EXECUTE
   │     ↓
   │   TEST
   │     ↓
   │   BENCHMARK / VALIDATE
   │     ↓
   │   COMMIT + PUSH
   │     ↓
   │   REPORT
   │     ↓
   │   SAVE COMPLETION STATE
   │     ↓
   │   RETURN TO TASK_SCANNER
   │
   └── NO
         ↓
       IDLE_WAIT_FOR_TASK
         ↓
       WAIT
         ↓
       SCAN AGAIN


======================================================================
4. TASK SCANNER LÀ VÒNG LẶP THƯỜNG TRỰC
======================================================================

Agent phải tự quét Task Drive.

Không cần Tony nhắn:

- "có task mới"
- "đọc task"
- "làm tiếp đi"
- "quét thư mục đi"

Agent tự chịu trách nhiệm phát hiện Task mới.


======================================================================
5. TẦN SUẤT QUÉT
======================================================================

Khi không tìm thấy Task mới:

STATE = IDLE_WAIT_FOR_TASK

Chờ khoảng:

60 seconds

sau đó:

SCAN TASK DRIVE AGAIN.

Tiếp tục:

WAIT → SCAN → WAIT → SCAN

cho đến khi phát hiện Task ACTIVE mới.

Không busy-loop liên tục.

Không spam log.

Không spam Tony khi không có Task mới.


======================================================================
6. CÁCH PHÁT HIỆN TASK
======================================================================

Mỗi lần scan Task Drive:

1. Liệt kê toàn bộ file/folder Task.

2. Bỏ qua:

LEGACY_*
SUPERSEDED_*
ARCHIVED_*

3. Tìm các tài liệu có dạng:

TASK_*

4. Đọc metadata/nội dung Task.

5. Chỉ nhận Task có:

STATUS: ACTIVE

6. Kiểm tra:

TASK_ID
ASSIGNEE
PRIORITY
DEPENDENCIES
SCOPE
MODIFIED_TIME

7. Nếu hợp lệ:

CLAIM TASK
→ PREFLIGHT
→ EXECUTE.

Không hỏi Tony xin phép lại.


======================================================================
7. ACTIVE TASK = AUTHORIZATION
======================================================================

STATUS: ACTIVE

đồng nghĩa:

EXECUTION AUTHORIZED.

Agent phải triển khai ngay sau preflight.

Cấm:

"Xin Chủ tịch Tony xác nhận để bắt đầu."

"Có cho phép tôi làm Task này không?"

"Tôi đã đọc xong, xin chờ chỉ đạo."

"Có muốn tôi tiếp tục không?"

Đây là lỗi:

UNNECESSARY_RECONFIRMATION


======================================================================
8. CHỐNG CHẠY LẠI TASK CŨ
======================================================================

Agent phải lưu trạng thái cục bộ, ví dụ:

.ai/state.json

Tối thiểu:

{
  "last_completed_task_id": "...",
  "last_completed_task_modified_time": "...",
  "last_report_folder": "...",
  "last_target_commit_sha": "...",
  "last_scan_time": "...",
  "agent_state": "IDLE_WAIT_FOR_TASK"
}

Nếu:

TASK_ID giống Task đã hoàn thành

VÀ

Task modified_time không đổi

thì:

SKIP_ALREADY_COMPLETED_TASK.

Không được chạy lại Task cũ.


======================================================================
9. TASK ĐƯỢC CẬP NHẬT
======================================================================

Nếu:

TASK_ID giống Task cũ

NHƯNG

modified_time mới hơn completion record

VÀ

STATUS vẫn ACTIVE

thì coi đây là:

UPDATED_TASK_REVISION.

Agent phải:

READ AGAIN
→ DIFF TASK REQUIREMENTS
→ EXECUTE NEW REQUIREMENTS.

Không bỏ qua chỉ vì Task ID giống.


======================================================================
10. NẾU CÓ NHIỀU TASK ACTIVE
======================================================================

Agent chọn theo thứ tự:

ASSIGNED TO CURRENT AGENT
→ PRIORITY cao hơn
→ DEPENDENCY đã thỏa
→ TASK_SEQUENCE nhỏ hơn
→ CREATED_TIME sớm hơn.

Không tự chạy hai Task xung đột cùng lúc.

Nếu không xung đột và kiến trúc cho phép parallel execution,
Orchestrator có thể phân công sang Agent khác.


======================================================================
11. SAU KHI HOÀN THÀNH TASK
======================================================================

Agent phải tự thực hiện:

IMPLEMENT
→ BUILD
→ TEST
→ VALIDATE
→ COMMIT
→ PUSH
→ REPORT
→ VERIFY REPORT PACKAGE
→ SAVE COMPLETION STATE

Sau đó KHÔNG được kết thúc.

Phải ngay lập tức:

RETURN TO TASK_SCANNER.


======================================================================
12. REPORT KHÔNG PHẢI ĐIỂM KẾT THÚC
======================================================================

Sai:

TASK
→ WORK
→ REPORT
→ EXIT

Đúng:

TASK
→ WORK
→ REPORT
→ TASK_SCANNER
→ NEXT TASK


======================================================================
13. KHÔNG ĐƯỢC TỰ TẠO NHIỆM VỤ
======================================================================

Khi không có Task ACTIVE:

Agent không được:

- tự sửa code;
- tự mở Phase mới;
- tự chọn việc mới;
- tự tạo Task kỹ thuật;
- tự mở P7;
- tự refactor ngoài scope.

Agent chỉ:

IDLE
→ WAIT
→ SCAN TASK DRIVE.


======================================================================
14. VÒNG PHỐI HỢP TONY ↔ AGENT
======================================================================

Chu trình chuẩn:

Tony/System Audit
        ↓
ghi Task vào TASK DRIVE
        ↓
Agent Task Scanner phát hiện
        ↓
Agent triển khai
        ↓
commit/push GitHub
        ↓
Agent ghi REPORT DRIVE
        ↓
Tony/System Audit tự phát hiện Report
        ↓
audit
        ↓
ghi Task tiếp theo
        ↓
Agent Task Scanner tự phát hiện
        ↓
tiếp tục vòng mới.

Không cần Tony kích hoạt Agent thủ công giữa các vòng.


======================================================================
15. TRẠNG THÁI AGENT
======================================================================

Các trạng thái hợp lệ:

BOOTING

SCANNING_TASKS

TASK_PREFLIGHT

TASK_EXECUTING

TESTING

REPORTING

RETURNING_TO_SCANNER

IDLE_WAIT_FOR_TASK

BLOCKED_REQUIRES_TONY_DECISION

Không được chuyển sang:

FINISHED

chỉ vì một Task đã hoàn thành.


======================================================================
16. CHỈ ĐƯỢC DỪNG TOÀN BỘ KHI
======================================================================

Chỉ kết thúc toàn bộ vòng Agent nếu:

END_AGENT_SESSION = TRUE

hoặc hệ thống runtime bắt buộc kết thúc phiên.

Nếu runtime chỉ hỗ trợ one-shot execution và tự đóng sau một Task,
phải có Supervisor/Orchestrator bên ngoài tự khởi động lại Agent vào:

TASK_SCANNER

để tiếp tục quét Task Drive.


======================================================================
17. WATCHDOG
======================================================================

Nếu Agent đang IDLE:

mỗi ~60 giây:

SCAN TASK DRIVE.

Nếu Task mới xuất hiện:

IDLE_WAIT_FOR_TASK
→ SCANNING_TASKS
→ TASK_PREFLIGHT
→ TASK_EXECUTING.

Không yêu cầu thao tác thủ công của Tony.


======================================================================
18. LỖI QUY TRÌNH
======================================================================

Nếu Agent:

hoàn thành Task
→ nộp Report
→ dừng luôn
→ không quay lại scanner

thì ghi:

WORKFLOW_FAILURE_TASK_SCANNER_NOT_RESUMED


======================================================================
19. MEMORY RULE BẮT BUỘC
======================================================================

Agent phải luôn nhớ:

TASK COMPLETE != AGENT COMPLETE.

STOP TASK != STOP AGENT.

REPORT SUBMITTED != WORKFLOW FINISHED.

Workflow duy nhất:

SCAN
→ EXECUTE
→ REPORT
→ SCAN
→ EXECUTE
→ REPORT
→ SCAN...


======================================================================
20. EXECUTION LOOP — PSEUDOCODE
======================================================================

while AGENT_ENABLED:

    tasks = scan(TASK_DRIVE)

    task = select_active_uncompleted_task(tasks)

    if task exists:

        read(task)

        preflight(task)

        if preflight_pass:

            execute(task)

            test(task)

            validate(task)

            if source_changed:
                commit()
                push()

            submit_report()

            save_completion_state()

            continue

    else:

        state = IDLE_WAIT_FOR_TASK

        wait(60 seconds)

        continue


======================================================================
FINAL DIRECTIVE
======================================================================

Agent không được hoạt động theo mô hình:

ONE TASK → EXIT.

Agent phải hoạt động theo mô hình:

TASK SCANNER
→ TASK
→ EXECUTION
→ REPORT
→ TASK SCANNER
→ TASK
→ EXECUTION
→ REPORT
→ ...

Đây là vòng vận hành mặc định cho tới khi Chủ tịch Tony ra lệnh dừng
toàn bộ hệ thống.
======================================================================
