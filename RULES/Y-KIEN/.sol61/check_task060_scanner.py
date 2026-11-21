"""Read-only reviewer reproduction: isolated scanner selection AST, no AGY main/log/dispatch."""
import ast, copy, hashlib, json, re, subprocess, types, zipfile
from datetime import datetime, timezone
from pathlib import Path
ROOT = Path(__file__).resolve().parents[3]
SOURCE = ROOT / 'scripts/autonomous_task_scanner.py'
EXPECTED = 'c61db0126e0829c3f5c1355963f81875e536c105217a35707861866efa2208a0'
source_hash = hashlib.sha256(SOURCE.read_bytes()).hexdigest()
if source_hash != EXPECTED:
    raise SystemExit('Source revision changed; this reproduction is bound to ' + EXPECTED)
tree = ast.parse(SOURCE.read_text(encoding='utf-8-sig'))
fn = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'scan_for_active_task')
nodes = [copy.deepcopy(n) for n in fn.body if n.lineno in {57, 58, 59, 93, 96, 97}]
if len(nodes) != 6:
    raise SystemExit('Selection anchors changed')
selection = compile(ast.fix_missing_locations(ast.Module(body=nodes, type_ignores=[])), 'scanner-selection-memory-only', 'exec')
number_fn = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'extract_task_number')
number_code = compile(ast.Module(body=[copy.deepcopy(number_fn)], type_ignores=[]), 'extract_task_number', 'exec')
class Directory:
    def __init__(self, name): self.name = name
    def exists(self): return True

def candidate(n, status='ACTIVE', mtime=1, suffix='', priority='NORMAL'):
    return dict(task_num=n, task_id=f'TASK_{n:03d}{suffix}', status=status, mtime=mtime, priority=priority)

def reproduce(label, last, candidates, report_names):
    env = dict(state={'last_completed_task_id': last}, candidates=candidates,
               REPORT_DIR=Directory('report'), AI_REPORTS_DIR=Directory('ai'), re=re,
               os=types.SimpleNamespace(listdir=lambda d: report_names if d.name == 'report' else []))
    exec(number_code, env)
    exec(selection, env)
    return dict(case=label, effective_last_num=env['last_num'], selected=[c['task_id'] for c in env['new_active']])

results = [
    reproduce('INACTIVE admitted', 'TASK_060', [candidate(62, 'INACTIVE')], []),
    reproduce('Updated completed TASK061 hidden by report directory', 'TASK_061', [candidate(61, mtime=999)], ['TASK_061_REPORT']),
    reproduce('Matching MD/DOCX double candidates', 'TASK_060', [candidate(61, suffix='.md'), candidate(61, suffix='.docx')], []),
    reproduce('Newest lower priority ahead of P0', 'TASK_060', [candidate(61, mtime=1, priority='P0'), candidate(62, mtime=2)], []),
    reproduce('Empty completion record forced to 60', '', [candidate(59)], []),
]
report = ROOT / 'RULES/REPORT/TASK_060_REPORT'
manifest = []
for line in (report / '08_RAW_EVIDENCE_MANIFEST.sha256').read_text(encoding='utf-8-sig').splitlines():
    claimed, name = line.split(None, 1)
    path = report / name.strip().replace('\\', '/')
    actual = hashlib.sha256(path.read_bytes()).hexdigest() if path.is_file() else 'MISSING'
    manifest.append(dict(path=name, sha256=actual, matches=actual.lower() == claimed.lower()))
package = report / 'CONVERT2_TASK060_REPORT_PACKAGE.zip'
claimed = (report / 'CONVERT2_TASK060_REPORT_PACKAGE.zip.sha256').read_text().split()[0]
with zipfile.ZipFile(package) as z:
    archive = dict(crc_bad=z.testzip(), entries=len(z.namelist()), sha256=hashlib.sha256(package.read_bytes()).hexdigest())
archive['matches_sidecar'] = archive['sha256'].lower() == claimed.lower()
commit = subprocess.run(['git', 'cat-file', '-e', '997a1fda67c82367d4fc88db8477d6ba56ba7c6e^{commit}'], cwd=ROOT, capture_output=True)
print(json.dumps(dict(at=datetime.now(timezone.utc).isoformat(), source_sha256=source_hash,
    scope='Only isolated selection AST and hash/CRC/local Git object reads; no scanner main, AGY generator, runner or filesystem mutation',
    selection_results=results, manifest=manifest, archive=archive,
    freeze_exists=(report / 'FREEZE.sha256').exists(), report_commit_resolves_locally=commit.returncode == 0), ensure_ascii=False, indent=2))
