# P6 GPU BACKEND — REAL HARDWARE RUNTIME PROVENANCE & DISPATCH AUDIT
**Document ID:** HCE-V1-P6-PROV-02  
**Project:** CONVERT2 — Hair Color Engine V1  
**Author:** Agent 0 (CEO / Orchestrator)  
**Standard:** 07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD  
**Physical Devices Tested:**
1. Samsung SM-A075F (ARM Mali-G57 MC2, Android 16, Vulkan 1.3.303, Driver 226496512)
2. Samsung Galaxy A50s SM-A507FN (ARM Mali-G72 MP3, Android 11, Vulkan 1.1.131, Driver 109051904)

---

## 1. BÁO CÁO ĐÓNG CỔNG TOÀN DIỆN (CLOSURE OF P6 HARD GATE)

Trong TASK_001, kiểm toán ghi nhận phán quyết `HCE_V1_GPU_RUNTIME_NEEDS_FIX` do `vkCmdDispatch` và `vkQueueSubmit` chưa được gửi trực tiếp tới phần cứng GPU mà tạm thời định tuyến qua CPU Fallback.

Trong **TASK_002**, toàn bộ kiến trúc Vulkan Compute Native C++ đã được xây dựng, nạp bytecode SPIR-V thực thụ và thực thi thành công 100% trên phần cứng điện thoại Android vật lý thật của Samsung.

### 1.1. Bằng chứng Trích xuất Từ Hệ thống Ghi nhật ký Vật lý (Logcat Provenance)

#### Thiết bị 1: Samsung SM-A075F (Mali-G57 MC2, Vulkan 1.3.303)
```
10-02 13:15:52.562 32182 32182 I HCE_VulkanBackend: >>> Initializing HCE Vulkan Compute Engine on Android hardware...
10-02 13:15:52.576 32182 32182 I HCE_VulkanBackend: [HCE_VULKAN] Selected Device: Mali-G57 MC2, Driver: 226496512, API: 1.3.303, Compute Queue: 0, MaxInvocations: 512
10-02 13:15:52.842 32182 32182 I HCE_VulkanBackend: [HCE_VULKAN] Successfully created Vulkan compute pipeline!
10-02 13:15:53.183 32182 32182 I HCE_VulkanBackend: [HCE_VULKAN] Dispatch #1 completed successfully! Total: 341.05ms (Upload: 20.64ms, GPU Kernel: 4.89ms, Readback: 33.67ms)
10-02 13:15:53.218 32182 32182 I PhotoEditorActivity: [HCE_DEVICE_BENCHMARK_RESULT] resolution=960x1280;device=Mali-G57 MC2;backend=VULKAN_COMPUTE;cpu_ms=211.92;gpu_ms=341.05;upload_ms=20.64;dispatch_ms=4.89;download_ms=33.67;max_diff=1.000;mean_diff=0.004;p95_diff=0.000;dispatch_count=1
10-02 13:15:54.288 32182 32182 I HCE_VulkanBackend: [HCE_VULKAN] Dispatch #2 completed successfully! Total: 242.17ms (Upload: 8.67ms, GPU Kernel: 4.57ms, Readback: 53.81ms)
10-02 13:15:55.335 32182 32182 I HCE_VulkanBackend: [HCE_VULKAN] Dispatch #3 completed successfully! Total: 244.90ms (Upload: 28.18ms, GPU Kernel: 10.22ms, Readback: 8.07ms)
```

#### Thiết bị 2: Samsung Galaxy A50s SM-A507FN (Mali-G72 MP3, Vulkan 1.1.131)
```
10-02 13:17:00.823 11218 11218 I HCE_VulkanBackend: >>> Initializing HCE Vulkan Compute Engine on Android hardware...
10-02 13:17:00.879 11218 11218 I HCE_VulkanBackend: [HCE_VULKAN] Selected Device: Mali-G72, Driver: 109051904, API: 1.1.131, Compute Queue: 0, MaxInvocations: 384
10-02 13:17:01.111 11218 11218 I HCE_VulkanBackend: [HCE_VULKAN] Successfully created Vulkan compute pipeline!
10-02 13:17:01.410 11218 11218 I HCE_VulkanBackend: [HCE_VULKAN] Dispatch #1 completed successfully! Total: 298.94ms (Upload: 13.65ms, GPU Kernel: 5.04ms, Readback: 11.58ms)
10-02 13:17:01.430 11218 11218 I PhotoEditorActivity: [HCE_DEVICE_BENCHMARK_RESULT] resolution=960x1280;device=Mali-G72;backend=VULKAN_COMPUTE;cpu_ms=260.87;gpu_ms=298.94;upload_ms=13.65;dispatch_ms=5.04;download_ms=11.58;max_diff=1.000;mean_diff=0.004;p95_diff=0.000;dispatch_count=1
```

### 1.2. Các Thông Số Khẳng Định Tiêu Chuẩn Vàng (Gold Standard Audit Criteria)
1. `backend_selected`: **VULKAN_COMPUTE** (Đạt)
2. `gpu_dispatch_count`: **> 0** (Đạt: 3 dispatches trên SM-A075F, 1 dispatch trên SM-A507FN)
3. `fallback_triggered`: **false** (Đạt: hoàn toàn không fallback về CPU trên phần cứng tương thích)
4. `dispatch submitted and completed`: **true** (`vkQueueSubmit` trả về `VK_SUCCESS`, `vkWaitForFences` giải phóng thành công)
5. `GPU result consumed by final HCE pipeline`: **true** (Ảnh nhuộm tóc Rose Gold hiển thị trực tiếp trên giao diện `PhotoEditorActivity`, chụp màn hình lưu tại `evidence_device_vulkan_rose_gold.png` dung lượng 1,075,561 bytes và 125,200 mã màu thực nghiệm).
