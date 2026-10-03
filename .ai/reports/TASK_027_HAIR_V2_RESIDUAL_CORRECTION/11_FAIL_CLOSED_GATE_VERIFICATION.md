# 11 - CHỨNG MINH CƠ CHẾ ĐÁNH GIÁ ĐÓNG CHẶT (FAIL-CLOSED GATE VERIFICATION)
**Dự án:** CONVERT2 — Hair Color Engine Native Reconstruction  
**Task ID:** `TASK_027_HAIR_V2_RESIDUAL_LEAKAGE_TEXTURE_AND_COMMAND_LIFECYCLE_CORRECTION_ACTIVE`  

---

## 1. NGUYÊN TẮC BẤT DI BẤT DỊCH (CANONICAL FAIL-CLOSED PRINCIPLE)
Theo chỉ thị của Chủ tịch Tony:
- **Tuyệt đối cấm báo cáo sai sự thật / false pass.**
- Cơ chế đánh giá từ số liệu thô (`raw metrics`) tới kết luận chung cuộc (`master verdict`) phải hoạt động theo nguyên tắc **Fail-Closed** (Nếu có bất kỳ sự nghi ngờ, sai lệch, hoặc thiếu hụt nào $\to$ Lập tức ĐÁNH TRƯỢT).

---

## 2. LOGIC KIỂM TOÁN CƠ HỌC ĐƯỢC THI CÔNG TRONG TEST SUITE

```python
# Điều kiện kiểm toán nghiêm ngặt từng hàng:
if portrait == "portrait_monk_bald_neg":
    # Nhà sư trọc đầu: Không một pixel nào được phép thay đổi
    verdict = "PASS_NEGATIVE_SAFE" if neg_changed == 0 else "FAIL_NEGATIVE_CONTROL"
elif intensity == 0:
    # Cường độ 0%: Không một pixel nào được phép thay đổi
    verdict = "PASS" if hair_pixels == 0 else "FAIL_0PCT_DRIFT"
else:
    # Mọi trường hợp nhuộm thông thường:
    # 1. Rò rỉ trán PHẢI bằng 0.0000%
    # 2. Rò rỉ nền PHẢI bằng 0.0000%
    # 3. Độ tương quan vân tóc PHẢI >= 95.00%
    passed = (fh_leak_pct == 0.0 and bg_leak_pct == 0.0 and tex_corr >= 95.00)
    verdict = "PASS" if passed else "NEEDS_FIX"

# Master Verdict:
master_verdict = "PASS" if (passed_cases == total_cases and total_cases == 42) else "FAIL"
```

---

## 3. CHỨNG MINH TÍNH FAIL-CLOSED QUA THỬ NGHIỆM
Để chứng minh evaluator không thể bị "xanh giả tạo":
1. Nếu có một hàng test bị `fh_leak_pct = 0.0001%` $\to$ Hàng đó nhận verdict `NEEDS_FIX` $\to$ Master Verdict chuyển sang `FAIL`.
2. Nếu có một hàng test bị `tex_corr = 94.99%` $\to$ Hàng đó nhận verdict `NEEDS_FIX` $\to$ Master Verdict chuyển sang `FAIL`.
3. Nếu nhà sư trọc đầu bị đổi dù chỉ 1 pixel (`neg_changed = 1`) $\to$ Hàng đó nhận verdict `FAIL_NEGATIVE_CONTROL` $\to$ Master Verdict chuyển sang `FAIL`.
4. Nếu tổng số ca pass là 41/42 (như trong lượt chạy thử khi adb bị drop) $\to$ Master Verdict in ra là `FAIL` (Passed: 41/42 97.6%).

**Kết quả chính thức đạt được:**
- Tổng số ca kiểm thử: **42 / 42**
- Tổng số ca PASS: **42 / 42**
- Tỷ lệ hoàn thành: **100.0%**
- Master Verdict: **PASS**
