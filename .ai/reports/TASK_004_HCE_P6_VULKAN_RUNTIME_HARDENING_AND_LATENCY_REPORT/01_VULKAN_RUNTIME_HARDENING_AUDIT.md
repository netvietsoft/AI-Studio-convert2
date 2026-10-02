# KIỂM CHỨNG KỸ THUẬT RUNTIME HARDENING VULKAN P6 (TASK_004)

**Task ID:** `TASK_004_HCE_P6_VULKAN_RUNTIME_HARDENING_AND_LATENCY`  
**Governing Standard:** `07_AGENT_AUTONOMOUS_EXECUTION_MASTER_STANDARD`  
**Target Code:**
- [`lib-core-graphics/src/main/cpp/include/hair/hair_gpu_backend.h`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/lib-core-graphics/src/main/cpp/include/hair/hair_gpu_backend.h)
- [`lib-core-graphics/src/main/cpp/src/hair/hair_gpu_backend.cpp`](file:///F:/CONVERT/com.mt.mtxx.mtxx/CONVERT2/lib-core-graphics/src/main/cpp/src/hair/hair_gpu_backend.cpp)

---

## 1. MỤC 1: QUẢN LÝ TÍNH NHẤT QUÁN BỘ NHỚ (MEMORY COHERENCY)

### Vấn đề trước đây (Commit 62b4f1c):
- `findMemoryType()` rơi vào fallback chỉ chọn `VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT` khi không có `HOST_COHERENT`.
- Mã nguồn cũ không gọi `vkFlushMappedMemoryRanges` sau khi upload và không gọi `vkInvalidateMappedMemoryRanges` trước khi readback, dẫn đến nguy cơ cache coherency không đồng bộ trên phần cứng non-coherent.

### Giải pháp kỹ thuật được triển khai:
1. Thêm struct `VulkanBufferResource` bao gồm cờ `bool isHostCoherent` và con trỏ `void* mappedPtr`.
2. Hàm `findMemoryType(..., bool* outIsCoherent)` phát hiện chính xác liệu memory type được chọn có hỗ trợ coherency phần cứng hay không.
3. Trong `executeVulkanCompute()`:
   - Khi upload: Nếu bất kỳ buffer nào trong số `mBufIn`, `mBufFeat0`, `mBufFeat1` có `!isHostCoherent`, phát lệnh `vkFlushMappedMemoryRanges` với `VK_WHOLE_SIZE`.
   - Khi download: Nếu `mBufOut` có `!isHostCoherent`, phát lệnh `vkInvalidateMappedMemoryRanges` trước khi `memcpy` kết quả sang `output.dstPixels`.

---

## 2. MỤC 2: BAO PHỦ MÃ TRẢ VỀ (VKRESULT COVERAGE)

### Kiểm tra đầy đủ 100% các API Vulkan:
Mọi lệnh gọi API Vulkan trong `initVulkan()` và `executeVulkanCompute()` hiện đều được kiểm tra `VkResult`:
1. `vkCreateInstance`: Kiểm tra và hủy an toàn nếu thất bại.
2. `vkEnumeratePhysicalDevices`: Kiểm tra số lượng thiết bị và mã lỗi.
3. `vkCreateDevice`: Kiểm tra mã lỗi.
4. `vkCreateCommandPool`: Kiểm tra mã lỗi.
5. `vkCreateShaderModule`: Kiểm tra mã lỗi.
6. `vkCreateDescriptorSetLayout`: Kiểm tra mã lỗi.
7. `vkCreatePipelineLayout`: Kiểm tra mã lỗi.
8. `vkCreateComputePipelines`: Kiểm tra mã lỗi.
9. `vkCreateDescriptorPool`: Kiểm tra mã lỗi.
10. `vkCreateBuffer`: Kiểm tra mã lỗi.
11. `vkAllocateMemory`: Kiểm tra mã lỗi.
12. `vkBindBufferMemory`: Kiểm tra mã lỗi.
13. `vkMapMemory`: Kiểm tra mã lỗi.
14. `vkAllocateDescriptorSets`: Kiểm tra mã lỗi.
15. `vkAllocateCommandBuffers`: Kiểm tra mã lỗi.
16. `vkBeginCommandBuffer`: Kiểm tra mã lỗi.
17. `vkEndCommandBuffer`: Kiểm tra mã lỗi.
18. `vkCreateFence`: Kiểm tra mã lỗi.
19. `vkResetFences`: Kiểm tra mã lỗi.
20. `vkQueueSubmit`: Kiểm tra mã lỗi.
21. `vkWaitForFences`: Kiểm tra mã lỗi và timeout 5 giây.
22. `vkFlushMappedMemoryRanges`: Kiểm tra mã lỗi.
23. `vkInvalidateMappedMemoryRanges`: Kiểm tra mã lỗi.

---

## 3. MỤC 3: DỌN DẸP TÀI NGUYÊN TẬN GỐC (RESOURCE CLEANUP & ZERO LEAKS)

- Mọi đường rẽ nhánh early-return khi gặp lỗi đều gọi dọn dẹp tài nguyên tương ứng:
  - `initVulkan()` gọi `cleanupVulkan()` nếu bất kỳ bước khởi tạo nào thất bại, hủy toàn bộ handles đã tạo theo thứ tự ngược lại.
  - `executeVulkanCompute()` ghi nhận chi tiết mã lỗi vào `mLastTrace`, chuyển cờ `fallbackTriggered = true`, và trả về `false` một cách an toàn mà không làm rò rỉ buffer hoặc memory.
  - `cleanupVulkan()` gọi `destroyPersistentBuffers()`, chờ `vkDeviceWaitIdle(mDevice)`, sau đó hủy pipeline, pipeline layout, descriptor set layout, shader module, pools, device và instance.

---

## 4. MỤC 4: ĐỘ AN TOÀN ĐA LUỒNG (THREAD SAFETY)

- Singleton `HairGpuBackend` được bảo vệ bằng `mutable std::recursive_mutex mBackendMutex;`.
- Tất cả các hàm công khai (`executePipeline`, `executeVulkanCompute`, `detectCapabilities`, `runParityBenchmark`, `getLastDispatchTrace`, `getDeviceInfo`) đều khóa mutex trước khi truy cập state.
- Tuân thủ tuyệt đối quy tắc đồng bộ ngoài (external synchronization) của Vulkan: Không có hai luồng nào ghi vào `mCommandPool`, `mDescriptorPool` hay bộ đệm persistent cùng một lúc.

---

## 5. MỤC 5: TRUNG THỰC VỀ NĂNG LỰC PHẦN CỨNG (CAPABILITY TRUTHFULNESS)

- Trước đây: `dedicatedVideoMemoryBytes = 1024 * 1024 * 512` (gán cứng 512MB).
- Hiện tại: Truy vấn trực tiếp từ `VkPhysicalDeviceMemoryProperties`:
  ```cpp
  size_t totalDeviceLocal = 0;
  for (uint32_t i = 0; i < mMemProperties.memoryHeapCount; ++i) {
      if (mMemProperties.memoryHeaps[i].flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT) {
          totalDeviceLocal += static_cast<size_t>(mMemProperties.memoryHeaps[i].size);
      }
  }
  mCaps.dedicatedVideoMemoryBytes = totalDeviceLocal;
  ```
- Trạng thái `isThermalThrottled = false` được quy định rõ là giá trị đo đạc baseline unthrottled khi chưa kích hoạt dịch vụ cảm biến nhiệt độ hệ điều hành Android.
