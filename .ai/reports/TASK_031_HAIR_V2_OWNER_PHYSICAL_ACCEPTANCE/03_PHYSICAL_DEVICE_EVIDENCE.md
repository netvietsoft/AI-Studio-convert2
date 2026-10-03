# 03 - BẰNG CHỨNG THỰC THI TRÊN 02 THIẾT BỊ VẬT LÝ (PHYSICAL DEVICE EVIDENCE)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_031_HAIR_V2_OWNER_PHYSICAL_ACCEPTANCE_FINAL_APK_TEST_ACTIVE`  

---

## 1. CẤU HÌNH PHẦN CỨNG 02 THIẾT BỊ
```text
+--------------------------+------------------------------------+------------------------------------+
| Thuộc tính               | Thiết bị 1: Samsung Galaxy A07     | Thiết bị 2: Samsung Galaxy A50s    |
+--------------------------+------------------------------------+------------------------------------+
| Model ID                 | SM-A075F                           | SM-A507FN                          |
| ADB Target               | 192.168.1.18:40159                 | 192.168.1.2:41775                  |
| Vi xử lý (SoC)           | MediaTek Helio G99 (MT6789)        | Samsung Exynos 9611                |
| GPU                      | Mali-G57 MC2                       | Mali-G72 MP3                       |
| Hệ điều hành             | Android 16 (API Level 36)          | Android 11 (API Level 30)          |
| Màn hình                 | STAYON ACTIVE / WAKE_LOCK          | STAYON ACTIVE / WAKE_LOCK          |
| Trạng thái kết nối       | ONLINE / DEVICE ATTACHED           | ONLINE / DEVICE ATTACHED           |
+--------------------------+------------------------------------+------------------------------------+
```

---

## 2. BẰNG CHỨNG XÁC THỰC THỜI GIAN THỰC VÀ SCREENSHOT
- **Ảnh chụp màn hình Galaxy A07:**  
  [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_screen.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_screen.png)
- **Log chứng thực phần cứng Galaxy A07:**  
  [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_proof.txt`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a075f_device_proof.txt)
- **Ảnh chụp màn hình Galaxy A50s:**  
  [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_screen.png`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_screen.png)
- **Log chứng thực phần cứng Galaxy A50s:**  
  [`TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_proof.txt`](file:///C:\actions-runner-03\_work\AI-Studio-convert2\AI-Studio-convert2\TASK_031_HAIR_PHYSICAL_DEVICE_VISUAL_GALLERY/00_DEVICE_PROOF/sm_a507fn_device_proof.txt)

---

## 3. THỜI GIAN ĐÁP ỨNG VÀ ĐỘ ỔN ĐỊNH
- Toàn bộ 42 lần render diễn ra liên tục, không xảy ra hiện tượng OOM (Out Of Memory), crash, hay ANR.
- Độ trễ render trung bình:
  - Galaxy A07 (Helio G99): ~5.6 giây / ảnh full HD (bao gồm NCNN segmentation, guided filter, multi-layer color transfer, storage I/O).
  - Galaxy A50s (Exynos 9611): ~8.4 giây / ảnh full HD.
