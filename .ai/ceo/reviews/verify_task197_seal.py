import collections
import hashlib
import json
from pathlib import Path


root = Path(__file__).resolve().parents[3]
report = root / 'RULES/REPORT/TASK_197_REPORT_R1'
seal_path = report / 'COMPLETE.json'
seal = json.loads(seal_path.read_text(encoding='utf-8'))
result = {'seal_sha256': hashlib.sha256(seal_path.read_bytes()).hexdigest(), 'fields': list(seal)}
for key in ('files', 'code_files', 'scratch_files'):
    mapping = seal.get(key, {})
    base = report if key == 'files' else root
    bad = [name for name, digest in mapping.items() if not (base / name).is_file() or hashlib.sha256((base / name).read_bytes()).hexdigest() != digest]
    result[key] = {'count': len(mapping), 'bad': bad[:10], 'groups': dict(collections.Counter(name.split('/')[0] for name in mapping))}
print(json.dumps(result, indent=2))
