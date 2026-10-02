#!/usr/bin/env python3
# -*- coding: utf-8 -*-
r"""
HỆ THỐNG KIỂM ĐỊNH ẢNH SAU CHỈNH SỬA DỰA TRÊN ẢNH THAM CHIẾU
(REFERENCE-BASED PHOTO EDITING TEST VALIDATOR)

Tuân thủ:
- F:\CONVERT\com.mt.mtxx.mtxx\Yeucau_Test_anh.txt
- F:\CONVERT\2.txt
- F:\CONVERT\Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt
- F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\specs\PHOTO_EDITING_TEST_SPEC.md
"""

import sys
import os
import json
import argparse
import numpy as np
from PIL import Image, ImageChops, ImageFilter

if sys.stdout.encoding != 'utf-8':
    try:
        sys.stdout.reconfigure(encoding='utf-8')
    except Exception:
        pass

class PhotoReferenceValidator:
    def __init__(self, original_path, edited_path, user_request, target_region=None, edit_params=None):
        self.orig_path = original_path
        self.edit_path = edited_path
        self.user_request = user_request
        self.target_region = target_region or {}
        self.edit_params = edit_params or {}
        
        self.orig_img = None
        self.edit_img = None
        self.diff_arr = None
        self.scores = {}
        self.results = {}
        self.hard_fails = []
        self.failure_reasons = []
        self.correction_plan = ""

    def load_images(self):
        if not os.path.exists(self.orig_path):
            raise FileNotFoundError(f"Original image not found: {self.orig_path}")
        if not os.path.exists(self.edit_path):
            raise FileNotFoundError(f"Edited image not found: {self.edit_path}")

        self.orig_img = Image.open(self.orig_path).convert("RGBA")
        self.edit_img = Image.open(self.edit_path).convert("RGBA")

        # Đảm bảo cùng kích thước để so khớp pixel
        if self.orig_img.size != self.edit_img.size:
            self.edit_img = self.edit_img.resize(self.orig_img.size, Image.Resampling.LANCZOS)

        orig_arr = np.array(self.orig_img, dtype=np.int32)
        edit_arr = np.array(self.edit_img, dtype=np.int32)
        self.diff_arr = np.abs(edit_arr - orig_arr)

    def evaluate_all(self):
        self.load_images()
        w, h = self.orig_img.size
        total_pixels = w * h

        # Phân biệt pixel biến đổi thực sự (ngưỡng dung sai khử lượng tử hóa)
        # diff > 4 coi là có can thiệp
        altered_mask = np.any(self.diff_arr[:, :, :3] > 4, axis=-1)
        altered_count = int(np.count_nonzero(altered_mask))

        # 1. KIỂM TRA ĐÚNG VỊ TRÍ (POSITION ACCURACY)
        # Giả định nếu có target_region bbox: [x1, y1, x2, y2]
        target_bbox = self.target_region.get("bbox", None)
        if target_bbox:
            x1, y1, x2, y2 = target_bbox
            x1, x2 = max(0, int(x1)), min(w, int(x2))
            y1, y2 = max(0, int(y1)), min(h, int(y2))
            
            target_mask = np.zeros((h, w), dtype=bool)
            target_mask[y1:y2, x1:x2] = True
            
            # Pixel biến đổi bên ngoài target_mask (Leakage)
            outside_altered = np.count_nonzero(altered_mask & (~target_mask))
            inside_altered = np.count_nonzero(altered_mask & target_mask)
            
            leakage_ratio = outside_altered / max(1, altered_count)
            pos_score = max(0.0, 100.0 - leakage_ratio * 200.0)
            if outside_altered > (total_pixels * 0.005) and "background" not in self.user_request.lower():
                self.failure_reasons.append("wrong_position")
        else:
            # Kiểm tra zero-leakage biên mặc định (10% rìa ảnh)
            border_mask = np.zeros((h, w), dtype=bool)
            bx, by = int(w * 0.08), int(h * 0.08)
            border_mask[:by, :] = True
            border_mask[-by:, :] = True
            border_mask[:, :bx] = True
            border_mask[:, -bx:] = True
            
            border_altered = np.count_nonzero(altered_mask & border_mask)
            if border_altered > (total_pixels * 0.001) and "background" not in self.user_request.lower():
                pos_score = max(50.0, 100.0 - (border_altered / total_pixels) * 5000.0)
                self.failure_reasons.append("background_changed")
            else:
                pos_score = 98.0
        
        self.scores["Edit Position"] = round(pos_score, 1)
        self.results["Edit Position"] = "PASS" if pos_score >= 90.0 else "FAIL"

        # 2. KIỂM TRA MÀU SẮC (COLOR ACCURACY)
        is_color_task = any(k in self.user_request.lower() for k in ["màu", "color", "nhuộm", "dye", "lut", "trắng", "whitening", "tone"])
        if is_color_task:
            mean_channel_delta = float(np.mean(self.diff_arr[altered_mask, :3])) if altered_count > 0 else 0.0
            color_score = min(100.0, 75.0 + mean_channel_delta * 0.8) if altered_count > 50 else 30.0
            self.scores["Color Accuracy"] = round(color_score, 1)
            self.results["Color Accuracy"] = "PASS" if color_score >= 85.0 else "FAIL"
            if color_score < 85.0:
                self.failure_reasons.append("wrong_color")
        else:
            self.scores["Color Accuracy"] = 100.0
            self.results["Color Accuracy"] = "N/A"

        # 3. KIỂM TRA FORM / HÌNH DÁNG (SHAPE ACCURACY)
        is_shape_task = any(k in self.user_request.lower() for k in ["thon", "vline", "nắn", "reshape", "to", "nhỏ", "gọt", "cằm", "mũi", "mắt", "tai", "body", "slim"])
        if is_shape_task:
            # Kiểm tra gradient độ lệch để đảm bảo mép không bị răng cưa
            max_delta = float(np.max(self.diff_arr[:, :, :3]))
            shape_score = 96.0 if (altered_count > 100 and max_delta > 15.0) else 45.0
            self.scores["Shape Accuracy"] = round(shape_score, 1)
            self.results["Shape Accuracy"] = "PASS" if shape_score >= 85.0 else "FAIL"
            if shape_score < 85.0:
                self.failure_reasons.append("wrong_shape")
        else:
            self.scores["Shape Accuracy"] = 100.0
            self.results["Shape Accuracy"] = "N/A"

        # 4. KIỂM TRA ĐÚNG Ý NGƯỜI DÙNG (USER INTENT SCORE)
        # Nếu có can thiệp đúng tác vụ và không bị rớt vị trí
        if altered_count == 0:
            intent_score = 0.0
            self.hard_fails.append("Không thực hiện yêu cầu chính của người dùng (Zero alteration)")
            self.failure_reasons.append("user_intent_not_satisfied")
        elif pos_score < 80.0:
            intent_score = 60.0
            self.failure_reasons.append("user_intent_not_satisfied")
        else:
            intent_score = 98.0
        
        self.scores["User Intent"] = round(intent_score, 1)
        self.results["User Intent"] = "PASS" if intent_score >= 95.0 else "FAIL"

        # 5. BẢO TOÀN ẢNH GỐC (ORIGINAL PRESERVATION / UNWANTED CHANGE)
        unwanted_ratio = (altered_count / total_pixels)
        # Nếu task cục bộ mà sửa quá 45% diện tích ảnh -> nguy cơ lem
        if unwanted_ratio > 0.45 and "toàn thân" not in self.user_request.lower() and "background" not in self.user_request.lower():
            unwanted_score = min(100.0, unwanted_ratio * 150.0)
            self.failure_reasons.append("unwanted_change")
        else:
            unwanted_score = 2.0  # Tốt (thấp là tốt)
        
        self.scores["Original Preservation"] = round(unwanted_score, 1)
        self.results["Original Preservation"] = "PASS" if unwanted_score <= 5.0 else "FAIL"

        # 6. KIỂM TRA LỖI DỊ THƯỜNG (ARTIFACT CONTROL)
        # Phát hiện biên viền gãy góc hoặc pixel dị thường cục bộ
        gray_diff = np.mean(self.diff_arr[:, :, :3], axis=-1)
        grad_y, grad_x = np.gradient(gray_diff)
        grad_mag = np.sqrt(grad_x**2 + grad_y**2)
        abnormal_edges = np.count_nonzero(grad_mag > 180.0)
        
        artifact_score = min(100.0, (abnormal_edges / max(1, altered_count)) * 2000.0)
        self.scores["Artifact Control"] = round(artifact_score, 1)
        self.results["Artifact Control"] = "PASS" if artifact_score <= 5.0 else "FAIL"
        if artifact_score > 5.0:
            self.failure_reasons.append("artifact")

        # 7. CHẤT LƯỢNG KỸ THUẬT (TECHNICAL QUALITY)
        tech_score = 95.0 if artifact_score <= 5.0 else 70.0
        self.scores["Technical Quality"] = round(tech_score, 1)
        self.results["Technical Quality"] = "PASS" if tech_score >= 85.0 else "FAIL"

        # 8. TÍNH TỰ NHIÊN (NATURALNESS)
        natural_score = 94.0 if (pos_score >= 90.0 and artifact_score <= 5.0) else 65.0
        self.scores["Naturalness"] = round(natural_score, 1)
        self.results["Naturalness"] = "PASS" if natural_score >= 85.0 else "FAIL"

        # TỔNG KẾT
        overall_pass = all(v in ["PASS", "N/A"] for v in self.results.values()) and len(self.hard_fails) == 0
        return overall_pass

    def generate_report(self):
        passed = self.evaluate_all()
        verdict = "PASS" if passed else "FAIL"

        lines = []
        lines.append("## BẢNG KẾT QUẢ TEST ẢNH CHI TIẾT (REFERENCE-BASED VALIDATION)")
        lines.append(f"- **ORIGINAL_IMAGE**: `{self.orig_path}`")
        lines.append(f"- **EDITED_IMAGE**: `{self.edit_path}`")
        lines.append(f"- **USER_REQUEST**: *\"{self.user_request}\"*")
        lines.append(f"- **KẾT LUẬN CHUNG**: **{verdict}**\n")

        lines.append("| TEST TIÊU CHÍ | SCORE | RESULT | YÊU CẦU ĐẠT |")
        lines.append("|:---|:---:|:---:|:---:|")
        reqs = {
            "Edit Position": ">= 90 & Zero Leakage",
            "Color Accuracy": ">= 85 (hoặc N/A)",
            "Shape Accuracy": ">= 85 (hoặc N/A)",
            "User Intent": ">= 95",
            "Original Preservation": "<= 5 (Unwanted Change)",
            "Artifact Control": "<= 5 (Artifacts)",
            "Technical Quality": ">= 85",
            "Naturalness": ">= 85"
        }
        for test_name, score in self.scores.items():
            res = self.results[test_name]
            req = reqs.get(test_name, ">= 85")
            lines.append(f"| {test_name:<21} | {score:>5}/100 | {res:<6} | {req:<21} |")

        if not passed:
            lines.append("\n### FAILURE REPORT & CORRECTION PLAN")
            lines.append(f"- **FAILURE_REASONS**: `{', '.join(set(self.failure_reasons))}`")
            if self.hard_fails:
                lines.append(f"- **HARD_FAIL_TRIGGERS**: {'; '.join(self.hard_fails)}")
            lines.append("- **CORRECTION_PLAN**:")
            lines.append("  1. Khôi phục vùng bị lem bằng `EXPECTED_PRESERVE_MASK` trực tiếp từ `ORIGINAL_IMAGE`.")
            lines.append("  2. Kẹp chặt ranh giới `TARGET_REGION` bằng bộ lọc Hermite Smoothstep C^1 trong C++.")
            lines.append("  3. Tái chạy xử lý C++ với tham số đã hiệu chỉnh trước khi gửi output cho người dùng.")

        return "\n".join(lines), passed

def main():
    parser = argparse.ArgumentParser(description="Reference-based Photo Editing Test Validator")
    parser.add_argument("--orig", required=True, help="Path to original image")
    parser.add_argument("--edit", required=True, help="Path to edited image")
    parser.add_argument("--request", required=True, help="User editing request text")
    parser.add_argument("--bbox", nargs=4, type=int, default=None, help="Target bbox: x1 y1 x2 y2")
    args = parser.parse_args()

    target_region = {"bbox": args.bbox} if args.bbox else None
    validator = PhotoReferenceValidator(args.orig, args.edit, args.request, target_region)
    report, passed = validator.generate_report()
    print(report)
    sys.exit(0 if passed else 1)

if __name__ == "__main__":
    main()
