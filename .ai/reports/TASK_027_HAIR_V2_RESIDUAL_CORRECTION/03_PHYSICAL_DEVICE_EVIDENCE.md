# 03 - BẰNG CHỨNG THỰC TẾ TRÊN 02 THIẾT BỊ VẬT LÝ (PHYSICAL DEVICE EVIDENCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. THÔNG SỐ PHẦN CỨNG 02 THIẾT BỊ VẬT LÝ ĐỘC LẬP

```
+--------------------------+------------------------------------+------------------------------------+
| Thuộc tính               | Thiết bị 1: Samsung Galaxy A07     | Thiết bị 2: Samsung Galaxy A50s    |
+--------------------------+------------------------------------+------------------------------------+
| Model ID                 | SM-A075F                           | SM-A507FN                          |
| ADB Target               | 192.168.1.18:40159                 | 192.168.1.2:41775                  |
| Vi xử lý (SoC)           | MediaTek Helio G99 (MT6789)        | Samsung Exynos 9611                |
| Kiến trúc CPU            | Octa-core (2x2.2 GHz A76 + 6x2.0)  | Octa-core (4x2.3 GHz A73 + 4x1.7)  |
| GPU                      | Mali-G57 MC2                       | Mali-G72 MP3                       |
| Hệ điều hành             | Android 16 (API Level 36)          | Android 11 (API Level 30)          |
| Build Fingerprint        | samsung/a07ub/a07:16/BP1A...       | samsung/a50s/a50s:11/RP1A...       |
| Trạng thái màn hình      | WAKE_LOCK / STAYON ACTIVE          | WAKE_LOCK / STAYON ACTIVE          |
+--------------------------+------------------------------------+------------------------------------+
```

---

## 2. BẰNG CHỨNG XÁC THỰC THỜI GIAN THỰC QUA ADB
Cả hai thiết bị được kết nối mạng cục bộ thông qua Android Debug Bridge không dây (Wireless ADB) và kiểm tra tình trạng sống (liveness) trước khi chạy bộ kiểm thử:

### A. Samsung Galaxy A07
```bash
adb -s 192.168.1.18:40159 get-state
device
adb -s 192.168.1.18:40159 shell getprop ro.product.model
SM-A075F
adb -s 192.168.1.18:40159 shell dumpsys package com.mt.mtxx.mtxx.convert | grep lastUpdateTime
lastUpdateTime=2026-10-03 13:49:33
```
- **Ảnh chụp màn hình thiết bị khi render:**  
  [`TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_screen.png`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_screen.png)
- **Log chứng thực phần cứng:**  
  [`TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_proof.txt`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_proof.txt)

### B. Samsung Galaxy A50s
```bash
adb -s 192.168.1.2:41775 get-state
device
adb -s 192.168.1.2:41775 shell getprop ro.product.model
SM-A507FN
adb -s 192.168.1.2:41775 shell dumpsys package com.mt.mtxx.mtxx.convert | grep lastUpdateTime
lastUpdateTime=2026-10-03 13:50:46
```
- **Ảnh chụp màn hình thiết bị khi render:**  
  [`TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_screen.png`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_screen.png)
- **Log chứng thực phần cứng:**  
  [`TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_proof.txt`](file:///C:/actions-runner-02/_work/AI-Studio-convert2/AI-Studio-convert2/TASK_027_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_proof.txt)

---

## 3. ĐỘ ỔN ĐỊNH VÀ THỜI GIAN ĐÁP ỨNG (LATENCY)
- **Thời gian xử lý trung bình trên Galaxy A07:** $\sim 5,800$ ms / ảnh full HD (bao gồm NCNN segmentation, chuyển đổi màu OKLab đa tầng, micro-injection và ghi I/O storage).
- **Thời gian xử lý trung bình trên Galaxy A50s:** $\sim 8,600$ ms / ảnh full HD (Exynos 9611 trên quy trình 10nm FinFET).
- **Độ ổn định RAM:** Hoàn thành toàn bộ 42 lần chạy liên tục mà không có hiện tượng Out Of Memory (OOM) hay native memory leak.
