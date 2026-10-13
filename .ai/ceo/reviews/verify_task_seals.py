"""CEO exact hash/inventory check for a numbered research report."""

import collections
import hashlib
import json
import sys
from pathlib import Path


root = Path(__file__).resolve().parents[3]
number = int(sys.argv[1])
report = root / f'RULES/REPORT/TASK_{number}_REPORT_R1'
seal_path = report / 'COMPLETE.json'
seal = json.loads(seal_path.read_text(encoding='utf8'))
result = {'task': number, 'seal_sha256': hashlib.sha256(seal_path.read_bytes()).hexdigest()}
for key in ('files', 'code_files', 'scratch_files', 'scratch_project_files'):
    if key not in seal:
        continue
    mapping = seal[key]
    base = report if key == 'files' else (root / f'RESEARCH_WORK/TASK_{number}_R1/ghidra_project'
                                         if key == 'scratch_project_files' else root)
    bad = [name for name, digest in mapping.items() if not (base / name).is_file()
           or hashlib.sha256((base / name).read_bytes()).hexdigest() != digest]
    result[key] = {'count': len(mapping), 'bad': bad[:10],
                   'groups': dict(collections.Counter(name.split('/')[0] for name in mapping))}
actual = {p.relative_to(report).as_posix() for p in report.rglob('*') if p.is_file()}
result['unlisted_report_files'] = sorted(actual - set(seal.get('files', {})) - {'COMPLETE.json', 'PROGRESS.json', 'PROGRESS.md'})
result['missing_report_files'] = sorted(set(seal.get('files', {})) - actual)
print(json.dumps(result, indent=2))
