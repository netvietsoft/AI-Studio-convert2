# QUY CHUẨN HOẠT ĐỘNG WORKSPACE (Docs/rules.md)
# Tiêu chuẩn: Development Workspace Standard V2.1.2

---

## 1. QUẢN TRỊ TRẠNG THÁI & LOCK
- Mọi Agent có thao tác ghi phải acquire lease trong `.ai/locks.json` trước khi thực thi.
- Mỗi lease có `lease_id`, `expiry`, `fencing_token`, và `files_allowed`.
- Khi lease hết hạn hoặc bị hủy, Agent phải dừng thao tác ghi ngay lập tức.
- Shared headers / contracts chỉ do Agent 1 (Architect) hoặc Agent 0 (CEO / Orchestrator) chỉnh sửa.

---

## 2. PHÂN CÔNG VAI TRÒ
- **Agent 0 (CEO / Orchestrator):** Quản lý task graph, phân rã task, điều phối, quyết định cuối cùng.
- **Agent 1 (Architect):** Kiểm định kiến trúc downstream, đóng băng contract `HCE_CONTRACT_V1.md`.
- **Implementation Agents (P1-P6):** Lập trình các module tương ứng theo contract và phạm vi file cho phép.
- **Integration Agent:** Hợp nhất luồng cross-phase trong integration worktree.
- **Tester Agent:** Kiểm thử độc lập, không trực tiếp sửa mã nguồn production.
- **Reviewer Agent:** Thẩm định độc lập trước khi mở cổng nghiệm thu.

---

## 3. CHÍNH SÁCH MOCK VÀ NGHIỆM THU
- Mọi artifact sinh ra từ mock phải được gắn nhãn `upstream_source = MOCK`.
- Chỉ các artifact sinh ra từ luồng tích hợp thật mới được gắn nhãn `upstream_source = REAL`.
- Phase final PASS chỉ được công nhận khi validation dùng 100% `upstream_source = REAL`.
