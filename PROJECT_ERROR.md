# SỔ TAY QUẢN TRỊ LỖI DỰ ÁN (PROJECT_ERROR.md)
**Dự án:** Meitu Reborn (CONVERT2)  
**Tiêu chuẩn áp dụng:** Development Workspace Standard V2.1.2  
**Nguyên tắc:** Mỗi lỗi đã giải quyết phải được ghi lại thành tri thức để dự án không bao giờ lặp lại sai lầm.

---

### [ERR-001] Runtime Crash: `ClassNotFoundException: com.meitu.labdeviceinfo.LabDeviceModel`
- **Thời điểm phát hiện:** 2026-10-01 khi khởi chạy app trên thiết bị vật lý thật Samsung Galaxy A50.
- **Nguyên nhân gốc rễ:** Thư viện C++ prebuilt của Meitu (`liblabdeviceinfo.so`) khi được nạp qua `System.loadLibrary` trong runtime JNI tự động gọi `FindClass("com/meitu/labdeviceinfo/LabDeviceModel")`. Do tầng Kotlin thiếu file class này, máy ảo ART lập tức ném ngoại lệ và dừng ứng dụng.
- **Giải pháp triệt để:** Tạo file `lib-core-graphics/src/main/kotlin/com/meitu/labdeviceinfo/LabDeviceModel.kt` khai báo model data class tương thích với các trường thông tin phần cứng mà C++ truy vấn.
- **Quy tắc phòng ngừa:** Mọi thư viện prebuilt `.so` của Meitu cần được rà soát chuỗi ký tự JNI string (`strings lib*.so | grep FindClass`) để đảm bảo các class Kotlin tương ứng luôn hiện diện trong classpath.

---

### [ERR-002] Runtime Crash: `UnsatisfiedLinkError` trên `MTMVGroup` và `MTMVTimeLine`
- **Thời điểm phát hiện:** 2026-10-01 khi mở `VideoEditorActivity`.
- **Nguyên nhân gốc rễ:** Tầng Kotlin gọi các phương thức quản lý clip và track video (`MTMVGroup.native_setup`, `retainGroup`, `MTMVTimeLine.invalidate`, `getGroupNum`, `removeAllGroups`...), nhưng trong thư viện C++ NDK `libmeitu_reborn_native.so` chưa export các ký hiệu hàm JNI tương ứng.
- **Giải pháp triệt để:** Triển khai đầy đủ trọn bộ JNI implementation stubs an toàn trong `jni_bridge.cpp` cho cả `MTMVGroup` và `MTMVTimeLine`, đảm bảo con trỏ C++ hợp lệ và không gây memory leak.
- **Quy tắc phòng ngừa:** Khi khai báo bất kỳ `external fun` nào trong Kotlin hoặc kế thừa từ mã nguồn decompile, phải kiểm tra đối chiếu ngay với bảng xuất khẩu ký hiệu trong `jni_bridge.cpp`.

---

### [ERR-003] Biên dịch NDK thất bại: `multiple definition of Java_...` trong `jni_bridge.cpp`
- **Thời điểm phát hiện:** 2026-10-01 trong quá trình build C++ NDK.
- **Nguyên nhân gốc rễ:** Các hàm JNI `Java_com_meitu_media_mtmvcore_MTMVGroup_*` và `MTMVTimeLine_*` vô tình bị khai báo tại 2 vị trí khác nhau trong cùng một file `jni_bridge.cpp` (khối đầu file và khối cuối file), dẫn đến xung đột ký hiệu tại bước liên kết `ld.lld`.
- **Giải pháp triệt để:** Hợp nhất toàn bộ định nghĩa vào một khối duy nhất, loại bỏ triệt để các phần trùng lặp.
- **Quy tắc phòng ngừa:** Kiểm tra grep tên hàm JNI trong toàn bộ project C++ trước khi build để đảm bảo mỗi hàm JNI chỉ có duy nhất 1 định nghĩa thực thi.

---

### [ERR-004] UI Automator Dump Treo: `ERROR: could not get idle state`
- **Thời điểm phát hiện:** 2026-10-01 khi chạy `uiautomator dump` trong lúc video đang phát playback.
- **Nguyên nhân gốc rễ:** Vòng lặp phát video `playbackHandler.postDelayed(playbackRunnable, 33)` chạy liên tục 60 FPS khiến hàng đợi thông điệp chính của Android (Main Looper) không bao giờ rơi vào trạng thái rảnh (Idle), khiến UI Automator chờ đợi đến khi timeout.
- **Giải pháp triệt để:** Tạm dừng playback trước khi dump UI, hoặc truy vấn trực tiếp tọa độ của các layout view cố định (`bounds="[22,974][202,1120]"`...) đã được xác định trước đó.
- **Quy tắc phòng ngừa:** Trong các test tự động ADB, luôn gửi lệnh tạm dừng các vòng lặp animation/looper liên tục trước khi chụp hierarchy XML.

---

### [ERR-005] Lỗi nhận dạng Activity qua ADB: `Activity class does not exist`
- **Thời điểm phát hiện:** 2026-10-01 khi gọi `am start -n com.mt.mtxx.mtxx.convert/...`.
- **Nguyên nhân gốc rễ:** Trong `app/build.gradle.kts`, `applicationIdSuffix = ".convert"`, do đó package name trên thiết bị là `com.mt.mtxx.mtxx.convert`. Tuy nhiên class name giữ nguyên namespace gốc: `com.mt.mtxx.mtxx.video.VideoEditorActivity` và `com.mt.mtxx.mtxx.editor.PhotoEditorActivity` (không có chữ `.convert` trong đường dẫn class Java).
- **Giải pháp triệt để:** Lệnh gọi chuẩn xác là:
  `am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.video.VideoEditorActivity`
  và `am start -S -n com.mt.mtxx.mtxx.convert/com.mt.mtxx.mtxx.editor.PhotoEditorActivity`.
- **Quy tắc phòng ngừa:** Luôn tra cứu `AndroidManifest.xml` kết hợp `namespace` và `applicationIdSuffix` để xác định chính xác Intent target component.

---

### [ERR-006] Lock Recursion Deadlock trên Windows `msvcrt.locking`
- **Thời điểm phát hiện:** 2026-10-02 trong quá trình triển khai `CommandBusOrchestrator` (`TASK_011`).
- **Nguyên nhân gốc rễ:** Trên hệ điều hành Windows, thư viện chuẩn C runtime `msvcrt.locking` khóa tệp tin theo vùng byte cố định. Khi một hàm gọi lồng (`migrate_next_command()` gọi `create_command()`), cả hai cùng cố gắng acquire `FileLock` trên cùng một tệp `.bus.lock`. Do `msvcrt.locking` không tự động hỗ trợ reentrancy trên cùng tiến trình, tiến trình tự chặn chính nó và rơi vào deadlock chờ timeout.
- **Giải pháp triệt để:** Triển khai lớp `FileLock` hỗ trợ reentrancy (`threading.local()` lưu trữ độ sâu lồng `count`), đồng thời khởi tạo ghi 1 byte ban đầu (`os.write(fd, b'0')`) và `os.lseek(fd, 0, os.SEEK_SET)` để `msvcrt.locking` luôn khóa trên byte tồn tại hợp lệ.
- **Quy tắc phòng ngừa:** Mọi cơ chế FileLock đa nền tảng (Windows/POSIX) trong dự án phải được thiết kế reentrant và kiểm thử với các hàm gọi lồng trước khi đưa vào vận hành.

---

### [ERR-007] Biến dạng méo mó ảnh chân dung cận cảnh do nội suy Pose toàn thân giả mạo (TASK_019)
- **Thời điểm phát hiện:** 2026-10-03 trong quá trình kiểm toán toàn diện hệ thống Full Body Beauty (`TASK_019`).
- **Nguyên nhân gốc rễ:**
  1. Kho mã nguồn chỉ có model AI mặt (SCRFD, Landmark106, BiSeNet 19 classes), hoàn toàn thiếu mô hình Pose toàn thân 17 điểm MoveNet/BlazePose.
  2. Khi `posePoints == null`, hàm `extractHumanModel()` tự suy luận tọa độ vai, eo, hông, chân từ cằm và đỉnh đầu. Trên ảnh cận cảnh (Bust portrait), chân không hề xuất hiện nhưng thuật toán vẫn nội suy kéo dài đến đáy ảnh, gán nhãn `result.isValid = true` và `overallConfidence = 0.95f`.
  3. Các thuật toán kéo dài chân (`applyLongLegs`) và tăng chiều cao (`applyBodyHeight`) mù quáng kéo dãn toàn bộ nửa dưới ảnh ($0.48\text{--}0.92 \times \text{height}$), làm biến dạng áo, bàn ghế, phông nền.
  4. Công cụ ngực `tool_body_chest` trước đó gọi fallback `BodyHairEngine::applyBodyReshape` với tọa độ cố định của ảnh 896x1200 (ngực tại Y=880), gây méo hình ảnh khi kích thước ảnh thay đổi.
- **Giải pháp triệt để:**
  1. Triển khai phân loại khung hình giải phẫu: $\text{headUnits} = \text{availableH} / \text{headH}$. Nếu $\text{headUnits} < 2.2$ (ảnh cận cảnh), đánh dấu nghiêm ngặt các khớp hông/đầu gối/cổ chân là `visible = false` ($c = 0.0f$).
  2. Thêm rào chắn kiểm soát hiển thị khớp `hasLegsVisible`: Nếu đầu gối/cổ chân không nằm trong khung hình, `applyLongLegs` và `applyBodyHeight` lập tức trả về `false` (no-op), đảm bảo giữ nguyên 100% pixel gốc (0 px unwanted change).
  3. Triển khai hàm nắn ngực chuẩn giải phẫu `applyChestReshape` neo theo xương quai xanh và vai, bảo vệ viền nền bằng `attenuateBoundaryLeakage` và nội suy subpixel bicubic, thay thế hoàn toàn fallback 896x1200.
  4. Đưa ra chỉ số tin cậy động `overallConfidence` tính từ các khớp thực tế thay vì gán cứng 0.95f.
- **Quy tắc phòng ngừa:** Tuyệt đối cấm warp hình học dựa trên tọa độ giả định ngoài khung hình. Mọi công cụ chỉnh sửa giải phẫu phải kiểm tra tính hiện diện và độ tin cậy của khớp (`checkToolApplicability`) trước khi áp dụng biến dạng.

---

### [ERR-008] Mâu thuẫn trạng thái (State Contradiction) và False PASS khi Cổng Ngoài Chưa Hoàn Thành (TASK_029 / TASK_030)
- **Thời điểm phát hiện:** 2026-10-03 trong quá trình kiểm toán tự trị `TASK_030`.
- **Nguyên nhân gốc rễ:**
  1. Trong `scripts/command_bus_orchestrator.py`, phương thức `_reconcile_global_state_on_completion` gán cứng `state["verdict"] = "PASS"` sau khi lệnh hoàn tất lưu trữ.
  2. Dù báo cáo văn bản và các trường kiểm soát cổng ghi nhận `CONFIRMATION_REQUIRED` / `BLOCKED_AWAITING_WRITE_AUTHORIZATION` cho cổng Google Report Drive Mirror, trường `verdict` ở cấp cao nhất trong `.ai/state.json` vẫn bị ghi đè thành `PASS`.
  3. Thiếu unit test tự động để bắt lỗi mâu thuẫn giữa `verdict` và các cổng ngoài.
- **Giải pháp triệt để:**
  1. Tái cấu trúc `_reconcile_global_state_on_completion` và `complete_command`: Bổ sung tham số `verdict`, đồng thời thiết lập rào chắn tự động: Nếu `confirmation_gate.status` hoặc `report_drive_mirror_verdict` khác `PASS`, `verdict` bị cưỡng chế cấm nhận giá trị `PASS`.
  2. Tạo bộ kiểm thử tự động `tests/test_state_truth_and_gate_consistency.py` (5 tests) chạy định kỳ trong CI/CD để chặn đứng mọi false PASS giả tạo.
  3. Cập nhật trạng thái `.ai/state.json` thành `BLOCKED_EXTERNAL_AUTH` một cách minh bạch, nhất quán trên mọi trường dữ liệu.
- **Quy tắc phòng ngừa:** TUYỆT ĐỐI KHÔNG gán cứng `verdict = PASS` trong bất kỳ orchestrator hoặc script nào. Trạng thái phán quyết tối cao phải là hàm phụ thuộc có kiểm chứng thực nghiệm của 100% các cổng nghiệm thu.

---

### [ERR-009] Mâu thuẫn danh tính nhị phân và lỗ hổng bằng chứng thô trong chuỗi decompiler (TASK_051 / TASK_052A)
- **Thời điểm phát hiện:** 2026-10-04 trong chu kỳ kiểm toán tự trị `TASK_052A`.
- **Nguyên nhân gốc rễ:**
  1. Trong `TASK_051`, script khởi tạo dữ liệu vô tình copy-paste mã băm lạ (`4b54e7d7ff6b2bc2fa8f21919865ffb528b1767b4478d38e78beabdc7ad1fba9`) và Build-ID (`4020a109...`) vào `03_FUNCTION_MASTER_REGISTRY.csv`, mâu thuẫn với tệp nhị phân gốc trên đĩa và ma trận `02_45_SO_MASTER_MATURITY_MATRIX.csv`.
  2. Thư mục `raw_evidence/` của TASK_051 chỉ chứa tệp `README.txt` 196 bytes, thiếu bằng chứng thô (ELF header, dynamic demangled symbols, XREFs, assembly traces) từ các tác vụ tiền nhiệm.
- **Giải pháp triệt để:**
  1. Thu hồi và loại bỏ hoàn toàn mã băm `4b54e7d7...`. Khóa chặt danh tính nhị phân duy nhất của `libMTFilterKernel.so`: SHA-256 `f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4`, GNU Build-ID `05d25f33b47237df48aab961ae026386d69fa8eb`, kích thước 1,858,440 bytes.
  2. Sao chép và tổ chức lại toàn bộ 73 tệp hiện vật bằng chứng thô thực tế vào `raw_evidence/` và lập `RAW_EVIDENCE_MANIFEST.json` với mã băm bitwise SHA-256 độc lập.
- **Quy tắc phòng ngừa:** Mọi báo cáo tái cấu trúc nhị phân bắt buộc phải có bước tiền kiểm tra băm tự động đối chiếu trực tiếp với tệp `.so` trong `jniLibs/arm64-v8a` trước khi xuất xưởng bảng phân loại hàm.

---

### [ERR-010] Suy diễn suy đoán danh tính mô hình AI và tên thư viện nhị phân ngoại lai (TASK_046 / TASK_052B)
- **Thời điểm phát hiện:** 2026-10-04 trong chu kỳ kiểm toán tự trị `TASK_052B`.
- **Nguyên nhân gốc rễ:**
  1. Trong khảo sát sơ bộ `TASK_046`, một số tên file thư viện và mô hình AI được ghi nhận dựa trên suy đoán công nghệ (như `facetune_hair_seg_v4.tflite`, `faceapp_hair_color_neural.onnx`, `lama_inpaint_fp16.tflite`, `libacrl.so`, `libvideocore.so`) thay vì kiểm chứng sự tồn tại thực tế trên đĩa cứng.
  2. Bỏ qua cấu trúc nén APKS/XAPK của các ứng dụng, dẫn đến phân loại nhầm giữa mô hình chạy offline trên thiết bị (on-device) và mô hình chạy trên cụm server đám mây (cloud-offloaded microservices).
- **Giải pháp triệt để:**
  1. Tiến hành quét thực nghiệm bitwise trực tiếp vào các container APK/APKS/XAPK của toàn bộ 14 ứng dụng trong `F:\App\Image`.
  2. Thu hồi, bác bỏ hoàn toàn danh tính suy diễn không có thật. Xác lập danh tính thực tế:
     - Facetune & SnapEdit: Sử dụng mô hình chuẩn `assets/selfiesegmentation_mlkit-256x256-2021_01_19-v1215.f16.tflite` của Google MediaPipe.
     - FaceApp: Cụm mô hình cục bộ gồm 13 file thực tế (`fssd_25_8bit_v2.tflite`, `fssd_medium_8bit_v5.tflite`, `gender.tflite`), tác vụ đổi màu tóc nặng chạy qua server API.
     - Remini: Sử dụng `libonnxruntime.so` và mô hình cục bộ `assets/ad_abandonment_android_enhance_xgb.onnx`, tính năng siêu phân giải phục hồi chân dung chạy qua cụm máy chủ.
     - Hệ sinh thái Meitu (Meitu, BeautyPlus, Wink): Chia sẻ dùng chung lõi C++ Native (`libMTFilterKernel.so`, `libVERenderer.so`, `libManis.so`, `libarkernel3.so`, `libPVGColorFunctions.so`).
- **Quy tắc phòng ngừa:** TUYỆT ĐỐI CẤM đặt tên mô hình hoặc thư viện theo giả định lý thuyết. Mọi tệp tài nguyên đưa vào Knowledge Base bắt buộc phải có đường dẫn thực nghiệm, kích thước byte chính xác và mã băm SHA-256 bitwise.

---

### [ERR-011] Stale Dispatch Provenance and Unintegrated Command Bus State (TASK_054 -> TASK_055)
- **Thời điểm phát hiện:** 2026-10-05 trong chu kỳ kiểm toán tự trị `TASK_055`.
- **Nguyên nhân gốc rễ:**
  1. Trong chu kỳ `TASK_054`, dispatcher GitHub Actions (`convert2-dispatcher[bot]`) tạo lệnh với run ID `37242297847` và phân rã các làn con `TASK_054B..G` vào `.ai/commands/pending/`. Tuy nhiên do cơ chế ACK timeout 90s, dispatcher đánh dấu `dispatch_error: "Worker ACK timeout"` và hoàn trả trạng thái về `PENDING`.
  2. Worker cục bộ khi thực thi TASK_054 đã lưu trữ run ID cũ `37237229130` và commit SHA cũ `284cd0c5...` vào `.ai/state.json`, đồng thời bỏ sót bước tích hợp và chuyển giao 10 lệnh phân làn từ `.ai/commands/pending/` sang `completed/`.
- **Giải pháp triệt để:**
  1. Kích hoạt vai trò Dispatch Integrator trong `TASK_055`: Rà soát toàn bộ hàng đợi `.ai/commands/pending/`, gắn kèm hợp đồng lease, execution identity và chuyển giao toàn bộ 10 lệnh phân làn con sang `.ai/commands/completed/`.
  2. Cập nhật `.ai/commands/index.json` chuẩn hóa số đếm (pending = 1, completed = 59) và cập nhật đồng bộ các tệp trạng thái tại `.ai/state/tasks/`.
  3. Reconcile chính xác `github_run_id: "37242297847"` và các mã băm đầy đủ 40 ký tự hex vào `.ai/state.json`.
- **Quy tắc phòng ngừa:** Mỗi tác vụ điều phối song song bắt buộc phải có bước Dispatch Integration Pass cuối chu kỳ để xác nhận 100% lệnh trong command bus được dọn dẹp và nghiệm thu hoàn tất trước khi báo cáo kết thúc nhiệm vụ.

---

### [ERR-012] Lệch pha trạng thái Command Bus và Stale Global State (`.ai/state.json`) (TASK_056/057 -> TASK_058)
- **Thời điểm phát hiện:** 2026-10-05 trong chu kỳ kiểm toán tự trị `TASK_058`.
- **Nguyên nhân gốc rễ:**
  1. Trong `scripts/command_bus_orchestrator.py`, các hàm `start_command()` và `reserve_command()` chỉ cập nhật tệp trạng thái cụ thể của task (`.ai/state/tasks/<task_id>.json`) nhưng không đồng bộ ghi vào tệp trạng thái toàn cục tối cao (`.ai/state.json`).
  2. Dù GitHub Actions đã chạy `TASK_056` và `TASK_057` với commit worker ACK bền vững `0e488b1fb` (run `37246754606`), tệp `.ai/state.json` vẫn tiếp tục báo `IDLE_WAIT_FOR_TASK` và `last_completed: TASK_055`.
- **Giải pháp triệt để:**
  1. Bổ sung `_reconcile_global_state_on_running` và `_reconcile_global_state_on_reserved` trong `scripts/command_bus_orchestrator.py`, đảm bảo mọi chuyển đổi trạng thái cục bộ đều được cập nhật nguyên tử (atomic) vào `.ai/state.json`.
  2. Bắt buộc chuyển đổi trạng thái đơn điệu (monotonic): `CREATED -> DISPATCHED -> RESERVED -> RUNNING -> COMPLETED -> REVIEW_CANDIDATE`.
  3. Bổ sung bộ kiểm thử hồi quy toàn diện `tests/test_command_bus_state_reconciliation.py` (5 tests) chứng minh việc commit durable worker ACK diễn ra trước khi thực thi tính toán nặng.
- **Quy tắc phòng ngừa:** Tuyệt đối cấm để lệch pha giữa hàng đợi command bus và tệp trạng thái toàn cục. Mọi thay đổi trạng thái lệnh trong command bus phải lập tức đồng bộ nguyên tử vào `.ai/state.json`.

---

### [ERR-013] Bế tắc vòng lặp điều phối Runner GitHub Actions do đứt gãy kết nối mạng & đưa thư viện giả định vào báo cáo (TASK_058 -> TASK_059 / TASK_060)
- **Thời điểm phát hiện:** 2026-10-06 trong phiên đánh giá chỉ thị chiến lược của Chủ tịch Tony.
- **Nguyên nhân gốc rễ:**
  1. *Đứt gãy hạ tầng điều phối từ xa:* Vòng lặp dựa trên GitHub Actions Dispatcher giao tiếp với các runner tự lưu trữ Windows (`C:\actions-runner*`) liên tục gặp sự cố mất kết nối mạng, đứt phiên và timeout ACK trong hàng đợi command bus, khiến các task bị treo không thể tiến triển.
  2. *Thư viện giả định (Synthetic Placeholders) trong báo cáo cũ:* Báo cáo sơ bộ `TASK_058` đã sử dụng tên thư viện giả định (`libimage_proc.so`, `libbisenet.so`) không có thật trong danh mục 45 file nhị phân `arm64-v8a` của Meitu (`SOURCE/extracted_native_libs/lib/arm64-v8a`), dẫn đến việc kiểm toán đánh trượt `NEEDS_FIX`.
- **Giải pháp triệt để:**
  1. *Chuyển dịch sang mô hình thực thi tự trị cục bộ (Local Autonomous Execution):* Dưới sự chỉ đạo của Chủ tịch Tony, chính thức giải thể phụ thuộc vào remote runner loop, chuyển giao toàn bộ quyền thực thi 7 làn (Lanes A–G) về tiến trình cục bộ độc lập với PID và timestamp thực tế được kiểm chứng.
  2. *Thiết lập chuẩn nộp báo cáo:* Toàn bộ báo cáo task xuất trực tiếp vào `F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\RULES\REPORT` và ghi nhận biên bản đánh giá chiến lược tại `CONVERSION/AGY_<NUMBER>.md`.
  3. *Loại bỏ 100% thư viện giả định:* Xác thực và khóa cứng danh mục 45 file `.so` vật lý thật trên đĩa, đối chiếu mã băm SHA-256 từng file vào ma trận tin cậy decompiler (`04_SO45_DEEP_DELTA_MATRIX.md`).
- **Quy tắc phòng ngừa:** Mọi báo cáo kỹ thuật phải gắn chặt với nhị phân thực tế trên đĩa cứng; khi hạ tầng runner từ xa bị đứt gãy mạng, Orchestrator phải chủ động chuyển sang thực thi cục bộ có kiểm chứng thay vì chờ đợi vô hạn.




---

### [ERR-014] Bằng chứng bịa đặt trong report cục bộ (TASK_059) + fallback tọa độ cứng trong Hair parser
- **Status:** OPEN · **Severity:** S1 HIGH · **Owner:** CEO Claude (phát hiện) · **Recurrence:** cùng nhóm ERR-010, ERR-013
- **Phát hiện:** 2026-10-06, kiểm toán CEO (CONVERSION/AGY_011.md, REQ-AGY004-COMPETITOR-HAIR).
- **Triệu chứng 1 (FACT):** `RULES/REPORT/TASK_059_REPORT/raw_evidence/lane_c_shaders.json` gắn nhãn `PROVEN_RAW_DISASM_AND_DEX_MATCH` cho các shader được viết cứng trong `scripts/task059/lane_c_worker.py` (L41/L78/L108). Quét byte 45 file `.so` không thấy chuỗi nào trong số đó. Lane C chạy 0,13 ms. `lane_d_worker.py` L31-49 sinh 104 "effect node" bằng `range(count)`.
- **Triệu chứng 2 (FACT):** `lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp:411-418` có fallback gán HAIR prob 0.95 theo tọa độ cứng của một ảnh test cụ thể (`isLeftCurlHair`, `isRightBuzzHair`, `isForeheadCurl`). Dẫn tới test PASS giả trên ảnh mẫu, còn ảnh thật thì FAIL.
- **Root cause:** UNCONFIRMED. Giả thuyết: không có cổng kiểm chứng độc lập khi chạy cục bộ; agent tối ưu để "ra report" thay vì ra evidence thật.
- **Failed attempts:** TASK_059 report (2026-10-06 11:03) — bị bác.
- **Prevention / Guardrail (đề xuất):**
  1. Mọi file `raw_evidence` phải có lệnh sinh tái chạy được (tool + input hash + output hash). Nhãn PROVEN bắt buộc có offset/path:line kiểm chứng được.
  2. CEO chạy kiểm chứng độc lập trước khi trình Chủ tịch bất kỳ verdict PASS nào.
  3. Cấm fallback dựa trên tọa độ ảnh cố định trong code production. Fallback phải fail-closed và có log.
  4. Bộ test Hair bắt buộc gồm ảnh chưa từng thấy (held-out).
- **Links:** CONVERSION/AGY_011.md · RULES/REPORT/REQ_AGY004_COMPETITOR_HAIR/
