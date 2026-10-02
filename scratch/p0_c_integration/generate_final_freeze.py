import hashlib
import os
import csv

files = [
    ('PRODUCTION_CODE', 'lib-core-graphics/src/main/cpp/include/hair_matting_engine.h'),
    ('PRODUCTION_CODE', 'lib-core-graphics/src/main/cpp/src/hair_matting_engine.cpp'),
    ('PRODUCTION_CODE', 'lib-core-graphics/src/main/cpp/include/ai/bisenet_face_parser.h'),
    ('PRODUCTION_CODE', 'lib-core-graphics/src/main/cpp/src/ai/bisenet_face_parser.cpp'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_PREINTEGRATION_FREEZE_VERIFICATION.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_TASK_GRAPH.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_PRODUCTION_DIFF_MAP.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_HAIR_MATTE_OUTPUT_CONTRACT.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_JNI_API_AUDIT.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_PRODUCTION_REGRESSION_METRICS.csv'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_CANDIDATE_VS_PRODUCTION_PARITY.csv'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_DEVICE_BENCHMARK.csv'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_TEST_REPORT.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_REVIEW_REPORT.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/P0_C_ROLLBACK_PLAN.md'),
    ('INTEGRATION_EVIDENCE', 'scratch/p0_c_integration/run_p0_c_master_evaluation.py')
]

manifest_rows = [['category', 'relative_path', 'byte_size', 'sha256']]
sha256_lines = []

base_dir = r'F:\CONVERT\com.mt.mtxx.mtxx\CONVERT2'

for cat, rel in files:
    full_path = os.path.join(base_dir, rel)
    with open(full_path, 'rb') as f:
        data = f.read()
    h = hashlib.sha256(data).hexdigest()
    sz = len(data)
    norm_rel = rel.replace('\\', '/')
    manifest_rows.append([cat, norm_rel, str(sz), h])
    sha256_lines.append(f"{h}  {norm_rel}")

manifest_path = os.path.join(base_dir, 'scratch', 'p0_c_integration', 'P0_FINAL_PRODUCTION_MANIFEST.csv')
with open(manifest_path, 'w', newline='', encoding='utf-8') as f:
    writer = csv.writer(f)
    writer.writerows(manifest_rows)

freeze_path = os.path.join(base_dir, 'scratch', 'p0_c_integration', 'P0_FINAL_FREEZE.sha256')
with open(freeze_path, 'w', encoding='utf-8') as f:
    f.write('\n'.join(sha256_lines) + '\n')

print(f"Wrote manifest: {manifest_path}")
print(f"Wrote freeze sha256: {freeze_path}")
for line in sha256_lines:
    print(line)
