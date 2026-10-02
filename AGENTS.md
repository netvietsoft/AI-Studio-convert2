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
