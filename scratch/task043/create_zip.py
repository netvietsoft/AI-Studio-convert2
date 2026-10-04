import os
import zipfile
import hashlib

REPORT_DIR = r'.ai\reports\TASK_043_TASK042_BENCHMARK_PROVENANCE_AND_TRUE_DEVICE_AB_CORRECTION'
ZIP_PATH = r'CONVERT2_TASK043_REPORT_PACKAGE.zip'

if os.path.exists(ZIP_PATH):
    os.remove(ZIP_PATH)

with zipfile.ZipFile(ZIP_PATH, 'w', zipfile.ZIP_DEFLATED) as zf:
    for root, dirs, files in os.walk(REPORT_DIR):
        for f in files:
            full_path = os.path.join(root, f)
            rel_path = os.path.relpath(full_path, REPORT_DIR)
            zf.write(full_path, rel_path)

h = hashlib.sha256()
with open(ZIP_PATH, 'rb') as f:
    while c := f.read(65536): h.update(c)
sha = h.hexdigest().upper()

with open(ZIP_PATH + '.sha256', 'w') as f:
    f.write(f'{sha}  {ZIP_PATH}\n')

print(f'Created {ZIP_PATH} ({os.path.getsize(ZIP_PATH)} bytes)')
print(f'SHA256: {sha}')
