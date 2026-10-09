"""Freeze exact diagnostic manifest; no self-approval or commit."""
import pathlib,json,ast,importlib.util,hashlib,sys
sp=importlib.util.spec_from_file_location('m',pathlib.Path(__file__).with_name('search.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m);m.guard()
for p in pathlib.Path(__file__).parent.glob('*.py'):ast.parse(p.read_text(encoding='utf-8-sig'))
result=json.loads((m.REPORT/'08_FINAL_RESULTS.json').read_text());assert result['coverage_complete'] is False and len(result['candidates'])==3
assert m.filehash(m.ORIGINAL)==result['original']['sha256_before']
files={p.relative_to(m.REPORT).as_posix():m.filehash(p) for p in sorted(m.REPORT.rglob('*')) if p.is_file() and p.name not in ('COMPLETE.json','PROGRESS.json','PROGRESS.md')}
code={p.relative_to(m.ROOT).as_posix():m.filehash(p) for p in sorted(pathlib.Path(__file__).parent.glob('*.py'))}
man=dict(schema_version='2.1.2',task_id='TASK_073',revision=1,status='COMPLETE',standard_sha256=m.STANDARD,files=files,code_files=code,agent_id=m.ACTOR,native_session_id=m.NATIVE,fencing_token=1021,diagnostic_conclusion=result['conclusion'],coverage_status=result['coverage_status'],review_status='REVIEW_CANDIDATE_AWAITING_CEO',completed_at=m.now())
m.js(m.REPORT/'COMPLETE.json',man)
assert all(m.filehash(m.REPORT/k)==v for k,v in files.items())
assert all(m.filehash(m.ROOT/k)==v for k,v in code.items())
print(json.dumps(dict(status='REVIEW_CANDIDATE_AWAITING_CEO',manifest_sha256=m.filehash(m.REPORT/'COMPLETE.json'),report_files=len(files),code_files=len(code),original_unchanged=True,completed_at=man['completed_at']),indent=2))
