import cv2
import os
import re

with open(r'F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2\scratch\p0_c_integration\run_p0_c_master_evaluation.py', 'r', encoding='utf-8') as f:
    lines = f.readlines()

manifest_lines = []
capturing = False
for line in lines:
    if 'regression_manifest = [' in line:
        capturing = True
    if 'all_runs = [' in line:
        capturing = False
    if capturing:
        manifest_lines.append(line.lstrip())

code = "".join(manifest_lines)
local_vars = {}
exec(code, {}, local_vars)

all_samples = []
for pfx, m in [('sample', local_vars['regression_manifest']), 
               ('holdout', local_vars['holdout_manifest']), 
               ('edge', local_vars['edge_manifest']), 
               ('robustness', local_vars['robustness_manifest'])]:
    for item in m:
        sid, spath = item[0], item[1]
        im = cv2.imread(spath)
        if im is not None:
            h, w = im.shape[:2]
            aspect = max(float(h)/w, float(w)/h)
            s_name = f"{pfx}_{sid:02d}"
            all_samples.append((s_name, w, h, aspect))

print(f"Total samples checked: {len(all_samples)}")
between = [s for s in all_samples if 1.45 < s[3] <= 1.80]
above_180 = [s for s in all_samples if s[3] > 1.80]
print(f"Samples with aspect > 1.80 ({len(above_180)}):")
for s in above_180:
    print(f"  {s[0]}: {s[1]}x{s[2]} (aspect={s[3]:.3f})")

print(f"\nSamples with 1.45 < aspect <= 1.80 ({len(between)}):")
for s in between:
    print(f"  {s[0]}: {s[1]}x{s[2]} (aspect={s[3]:.3f})")
