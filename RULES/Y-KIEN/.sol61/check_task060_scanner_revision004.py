"""Read-only audit of pinned scanner intake/selection AST using in-memory fixtures."""
import ast
import copy
import hashlib
import io
import json
import re
import subprocess
import types
import zipfile
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
SOURCE = ROOT / 'scripts/autonomous_task_scanner.py'
EXPECTED = '0d8f9ce830c61367e01716661e783a038fdf383c5ae639c8d73684b5f980ff75'
source_hash = hashlib.sha256(SOURCE.read_bytes()).hexdigest()
if source_hash != EXPECTED:
    raise SystemExit('Source revision changed; reproduction is bound to ' + EXPECTED)
tree = ast.parse(SOURCE.read_text(encoding='utf-8-sig'))
fn = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'scan_for_active_task')
anchors = {57, 58, 61, 62, 67, 70, 71, 101, 104, 105}
nodes = [copy.deepcopy(n) for n in fn.body if n.lineno in anchors]
if {n.lineno for n in nodes} != anchors:
    raise SystemExit('Intake/selection AST anchors changed')
selection = compile(ast.fix_missing_locations(ast.Module(body=nodes, type_ignores=[])), 'scanner-memory-only', 'exec')
number_fn = next(n for n in tree.body if isinstance(n, ast.FunctionDef) and n.name == 'extract_task_number')
number_code = compile(ast.Module(body=[copy.deepcopy(number_fn)], type_ignores=[]), 'extract_task_number', 'exec')


class MemoryPath:
    def __init__(self, name, entries):
        self.name, self.entries = name, entries

    def __str__(self):
        return self.name

    def __truediv__(self, part):
        return MemoryPath(self.name + '/' + part, self.entries)

    def exists(self):
        return self.name in self.entries

    def stat(self):
        return types.SimpleNamespace(st_mtime=self.entries[self.name]['mtime'])


def task(n, status='ACTIVE', mtime=100, priority='NORMAL', suffix='.md', text=None):
    return dict(name=f'TASK_{n:03d}' + suffix, mtime=mtime,
                text=text or f'TASK_ID: TASK_{n:03d}\nSTATUS: {status}\nPRIORITY: {priority}')


def reproduce(label, tasks, reports=(), state=None):
    entries = {'tasks': {'names': []}, 'report': {'names': []}, 'ai': {'names': []}}
    for t in tasks:
        entries['tasks']['names'].append(t['name'])
        entries['tasks/' + t['name']] = dict(t)
    for name, mtime in reports:
        entries['report']['names'].append(name)
        entries['report/' + name] = {'mtime': mtime}
    env = dict(state=copy.deepcopy(state or {}), TASK_DIR=MemoryPath('tasks', entries),
               REPORT_DIR=MemoryPath('report', entries), AI_REPORTS_DIR=MemoryPath('ai', entries), re=re,
               os=types.SimpleNamespace(listdir=lambda p: list(entries[p.name]['names'])),
               open=lambda p, *args, **kwargs: io.StringIO(entries[p.name]['text']),
               get_docx_text=lambda p: entries[p.name]['text'])
    exec(number_code, env)
    exec(selection, env)
    return dict(case=label, input=dict(tasks=tasks, reports=list(reports), state=env['state']),
                effective_last_num=env['last_num'], selected=env['new_active'])


completed61 = {'last_completed_task_id': 'TASK_061'}
results = [
    reproduce('Empty completion record forced to 60 hides TASK059', [task(59)]),
    reproduce('INACTIVE admitted', [task(64, status='INACTIVE')]),
    reproduce('Matching MD/DOCX yield two candidates', [task(61), task(61, suffix='.docx')]),
    reproduce('Newer NORMAL ahead of P0', [task(61, mtime=100, priority='P0'), task(62, mtime=200)]),
    reproduce('Partial fix: revised task 111, report 100 selected', [task(61, mtime=111)], [('TASK_061_REPORT', 100)], completed61),
    reproduce('Revision within 10 seconds hidden', [task(61, mtime=105)], [('TASK_061_REPORT', 100)], completed61),
    reproduce('Changed task content with preserved mtime hidden', [task(61, text='TASK_ID: TASK_061\nSTATUS: ACTIVE\nSCOPE: revised')], [('TASK_061_REPORT', 100)], completed61),
    reproduce('Empty TASK100 report raises watermark and hides uncompleted TASK063', [task(63)], [('TASK_100_REPORT', 10)]),
    reproduce('TASK100 named ordinary file also raises watermark', [task(63)], [('TASK_100_note.txt', 10)]),
    reproduce('Lifecycle COMPLETED key valued False hides TASK061', [task(61)], state={'task_lifecycle': {'TASK_061_COMPLETED': False}}),
    reproduce('Report directory touch hides revised task', [task(61, mtime=200)], [('TASK_061_REPORT', 300)], completed61),
    reproduce('Filename prefix TASK061 incorrectly matches TASK610 report', [task(61, mtime=111)], [('TASK_610_REPORT', 100)], completed61),
    reproduce('Same completed revision still selected despite matching completion mtime', [task(61, mtime=111)], [('TASK_061_REPORT', 100)], {'last_completed_task_id': 'TASK_061', 'last_completed_task_modified_time': 111}),
    reproduce('ARCHIVED ACTIVE document not excluded', [dict(task(64), name='ARCHIVED_TASK_064.md')]),
]
expected = [[], ['TASK_064'], ['TASK_061', 'TASK_061'], ['TASK_062', 'TASK_061'],
            ['TASK_061'], [], [], [], [], [], [], ['TASK_061'], ['TASK_061'], ['ARCHIVED_TASK_064']]
for result, selected in zip(results, expected):
    actual = [c['task_id'] for c in result['selected']]
    if actual != selected:
        raise SystemExit(f'Unexpected reproduction: {result["case"]}: {actual}')

report = ROOT / 'RULES/REPORT/TASK_060_REPORT'
manifest = []
for line in (report / '08_RAW_EVIDENCE_MANIFEST.sha256').read_text(encoding='utf-8-sig').splitlines():
    claimed, name = line.split(None, 1)
    p = report / name.strip().replace('\\', '/')
    actual = hashlib.sha256(p.read_bytes()).hexdigest() if p.is_file() else 'MISSING'
    manifest.append(dict(path=name, sha256=actual, matches=actual.lower() == claimed.lower()))
package = report / 'CONVERT2_TASK060_REPORT_PACKAGE.zip'
claimed = (report / 'CONVERT2_TASK060_REPORT_PACKAGE.zip.sha256').read_text().split()[0]
with zipfile.ZipFile(package) as z:
    archive = dict(crc_bad=z.testzip(), entries=len(z.namelist()), sha256=hashlib.sha256(package.read_bytes()).hexdigest())
archive['matches_sidecar'] = archive['sha256'].lower() == claimed.lower()
commit = subprocess.run(['git', 'cat-file', '-e', '997a1fda67c82367d4fc88db8477d6ba56ba7c6e^{commit}'], cwd=ROOT, capture_output=True)
standard = ROOT / 'Development_Workspace_Standard_V2.1_Design_Gated 29-9-2026.txt'
standard_bytes = standard.read_bytes()
print(json.dumps(dict(at=datetime.now(timezone.utc).isoformat(), source_sha256=source_hash,
    checker_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(), ast_anchors=sorted(anchors),
    scope='Intake and selection AST in memory only; no AGY main/log/state writes, generators, scheduler or runner',
    selection_results=results, manifest=manifest, archive=archive,
    freeze_exists=(report / 'FREEZE.sha256').exists(), report_commit_resolves_locally=commit.returncode == 0,
    standard=dict(path=str(standard), bytes_read=len(standard_bytes), sha256=hashlib.sha256(standard_bytes).hexdigest())),
    ensure_ascii=False, indent=2))
