"""Correct an editorial baseline-state ambiguity before any review acceptance."""
import json
import acquire as a

docs=a.ROOT/'Docs/Reconstruction/References/storytold'
old='NO_VERIFIED_COUNTERPART trong baseline hiện đã nghiệm thu'
new='NO_VERIFIED_COUNTERPART trong phạm vi chứng cứ đã kiểm tra; TASK063 vẫn BLOCKED'
for p in [docs/'COMPARISON_MAP.md',a.REPORT/'03_COMPARISON_MAP.md']:
    text=p.read_text(encoding='utf-8'); assert old in text
    a.write(p,text.replace(old,new).encode('utf-8'))
a.jwrite(a.REPORT/'04_INDEX_ARTIFACTS.json',{str(p.relative_to(a.ROOT)).replace('\\','/'):a.sha(p.read_bytes()) for p in docs.iterdir() if p.is_file()})
a.write(a.REPORT/'05_EDITORIAL_CORRECTION.md',b'The original index wording implied an accepted baseline. Corrected before acceptance: TASK063 remains BLOCKED; comparison concerns inspected evidence only. No SO45 verdict changed. Producer chain acquire.py -> finalize.py -> correct_index.py.\n')
c=json.loads((a.REPORT/'COMPLETE.json').read_text())
c['files']={str(p.relative_to(a.REPORT)).replace('\\','/'):a.sha(p.read_bytes()) for p in a.REPORT.rglob('*') if p.is_file() and p.name not in ['COMPLETE.json','PROGRESS.json']}
c['code_files'].append('scripts/task068_storytold_reference/correct_index.py')
a.jwrite(a.REPORT/'COMPLETE.json',c)
print('Corrected index baseline wording; re-frozen manifest before acceptance.')
