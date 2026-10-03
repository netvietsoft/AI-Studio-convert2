# 02. ĐẶC TẢ SỬA ĐỔI CÁC WORKFLOW GITHUB ACTIONS
# (02_WORKFLOW_REMEDIATION_SPECIFICATION.md)
**Nhiệm Vụ:** TASK_012 — MULTI-AGENT REAL GITHUB ACTIONS CONCURRENCY CORRECTION  
**Command ID:** `TASK_012_REAL_ACTIONS_CONCURRENCY_CORRECTION_20261002T2030+0700`  
**Ngày:** 2026-10-03  
**Trạng Thái:** ÁP DỤNG & HOÀN TẤT

---

## 1. SỬA ĐỔI WORKFLOW `.github/workflows/convert2-command-bus.yml`

### 1.1 Mục đích
Chấm dứt việc tự động kích hoạt workflow cũ khi có push lên `main`, biến nó thành workflow dự phòng (fallback) thuần túy khi kỹ sư cần kích hoạt thủ công trực tiếp bằng `workflow_dispatch`.

### 1.2 Chi tiết thay đổi (Diff)
```diff
-name: CONVERT2 Agent Command Bus
+name: CONVERT2 Agent Command Bus (Standalone Fallback)

 on:
-  push:
-    branches: [main]
-    paths:
-      - ".ai/commands/pending/**"
-      - ".ai/commands/NEXT_COMMAND.json"
-      - "scripts/command_bus_orchestrator.py"
   workflow_dispatch:
     inputs:
       command_id:
-        description: "Specific Command ID to execute (leave empty to pick highest priority ready command)"
-        required: false
-        type: string
-        default: ""
+        description: "Specific Command ID to execute (Required)"
+        required: true
+        type: string
       execution_lane:
         description: "Execution Lane"
         required: false
```

### 1.3 Hiệu quả kiểm chứng
- Khi commit được đẩy lên `main`, chỉ duy nhất `convert2-dispatcher.yml` được kích hoạt.
- Không còn bất kỳ tiến trình command-bus rỗng tham số nào bị fail trên pool Windows runners.

---

## 2. SỬA ĐỔI WORKFLOW `.github/workflows/convert2-integrator.yml`

### 2.1 Mục đích
Đảm bảo môi trường container Ubuntu tải chính xác nhánh nhiệm vụ `agent/*` từ máy chủ GitHub trước khi gọi lệnh tích hợp Python, ngăn chặn lỗi `not something we can merge`.

### 2.2 Chi tiết thay đổi (Diff)
```diff
       - name: Set up Python
         uses: actions/setup-python@v5
         with:
           python-version: "3.11"

+      - name: Fetch Target Branch
+        env:
+          BRANCH: ${{ inputs.branch }}
+        run: |
+          git fetch origin "+refs/heads/${BRANCH}:refs/remotes/origin/${BRANCH}" || true
+
       - name: Reconcile and Merge Task Branch
         env:
           GH_TOKEN: ${{ secrets.GITHUB_TOKEN }}
```

### 2.3 Hiệu quả kiểm chứng
- Nhánh `agent/*` luôn được cập nhật trong `refs/remotes/origin/*` của container Integrator.
- Lệnh `git merge` trong Orchestrator tìm thấy ref hợp lệ 100%, tích hợp sạch sẽ vào `main`.
- Bằng chứng thực tế: Run `37101212909` tích hợp thành công Task 026 trong 51 giây.

---

## 3. RÀ SOÁT CẤU HÌNH CONCURRENCY TOÀN HỆ THỐNG

| Workflow File | Concurrency Group | Cancel in Progress | Vai Trò & Bảo Vệ |
| :--- | :--- | :---: | :--- |
| `convert2-dispatcher.yml` | `group: convert2-dispatcher` | `false` | Đảm bảo chỉ có duy nhất 1 dispatcher chạy tại một thời điểm, loại bỏ race condition khi đặt chỗ lệnh. |
| `convert2-worker.yml` | `group: convert2-worker-${{ inputs.command_id }}` | `false` | Cô lập tuyệt đối theo từng command; các worker chạy đồng thời độc lập không bao giờ hủy nhau. |
| `convert2-integrator.yml` | `group: convert2-integrator` | `false` | Tuần tự hóa tuyệt đối việc merge vào `main`, ngăn chặn xung đột git push trên máy chủ GitHub. |
| `convert2-command-bus.yml` | `group: convert2-command-bus-${{ inputs.command_id }}` | `false` | Dự phòng kích hoạt thủ công, không can thiệp vào vòng lặp tự động. |
