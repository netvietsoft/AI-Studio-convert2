"""CEO independent retained-output, corpus, model and scheduler checks; no worker writes."""
import csv, hashlib, json, pathlib, re, subprocess, sys, zipfile
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso

root = pathlib.Path(__file__).resolve().parents[3]
c = Controller(root)
started = iso(c.clock())
report = root / 'RULES/REPORT/TASK_063_REPORT_R3'
rows = list(csv.DictReader((report/'03_EXISTING_EVIDENCE_AUDIT.csv').open(encoding='utf-8-sig')))
mnemonics = {'fadd','fsub','fmul','fdiv','fmla','fmls','fneg','fabs','fsqrt','fcvtzs','fcvtzu','scvtf','ucvtf','fmax','fmin','madd','msub','sdiv','udiv'}
ins = re.compile(r'^\s*[0-9a-f]+:\s+([a-z][a-z0-9.]*)\b', re.I)
symbol = re.compile(r'^\s*\d+:\s+([0-9a-f]+)\s+(\d+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(\S+)\s+(.*)$', re.I)
data = {'command': 'python -X utf8 -B .ai/ceo/reviews/verify_task063_r3_additional.py',
        'script_sha256': file_sha(pathlib.Path(__file__)), 'started_at': started,
        'scope': 'Retained R3 outputs; actual original APK; existing TASK061 corpus; native schedule records',
        'ordinary_retained_samples': [], 'historical_bodies': [], 'keyword_scope': [], 'schedules': []}
for row in rows:
    name = row['library']
    raw = report/'raw'/f'objdump_{name}.stdout.txt'
    instructions = [m.group(1).lower() for line in raw.read_text(encoding='utf-8-sig').splitlines() if (m := ins.match(line))]
    data['ordinary_retained_samples'].append({'library': name, 'raw_path': raw.relative_to(root).as_posix(),
        'raw_sha256': file_sha(raw), 'retained_instruction_count': len(instructions),
        'retained_arithmetic_count': sum(m in mnemonics for m in instructions),
        'reported_instruction_count': row['sampled_instruction_lines'], 'reported_arithmetic_count': row['sampled_arithmetic_count']})
    hist = root/'.ai/reconstruction/evidence/TASK_061/ghidra_decompiled'/f'{name}_decompiled.txt'
    if hist.is_file():
        data['historical_bodies'].append({'library': name, 'path': hist.relative_to(root).as_posix(),
            'sha256': file_sha(hist), 'lines': len(hist.read_bytes().splitlines()),
            'reported_path': row['historical_decompiled_path'], 'reported_relevance': row['decompiled_body_relevance']})
    readelf = report/'raw'/f'readelf_{name}.stdout.txt'
    symbols = [m.groups() for line in readelf.read_text(encoding='utf-8-sig').splitlines() if (m := symbol.match(line))]
    hits = [s for s in symbols if 'manis' in s[6].lower()]
    data['keyword_scope'].append({'library': name, 'readelf_raw_sha256': file_sha(readelf),
        'reported_status': row['readelf_status'], 'bisenet_symbol_hits': sum('bisenet' in s[6].lower() for s in symbols),
        'manis_all_symbol_hits': len(hits), 'manis_defined_nonzero_hits': sum(s[5] != 'UND' and int(s[0],16) != 0 for s in hits),
        'manis_import_hits': sum(s[5] == 'UND' for s in hits)})
apk = root.parent/'SOURCE/com.mt.mtxx.mtxx.apk'
data['original_apk_sha256'] = file_sha(apk)
with zipfile.ZipFile(apk) as z:
    names = z.namelist()
    selected = [n for n in names if 'mtface_parsing' in n or n.endswith('/NE.manis')]
    data['model_assets'] = [{'entry': n, 'bytes': len(z.read(n)), 'sha256': hashlib.sha256(z.read(n)).hexdigest()} for n in selected]
data['false_report_NE_entry_exists'] = 'assets/vlaimodel/libmtface/models/NE.manis' in names
tool = pathlib.Path(json.loads((report/'06_TOOLCHAIN_AND_HEARTBEAT_RECEIPTS.json').read_text())['toolchains']['llvm_readelf']['path'])
data['independent_reruns'] = []
rerun_payloads = []
for name in ('libaicodec.so','libaidetectionplugin.so','libPVGColorFunctions.so','libMTLReportTool.so','libManis.so','libMTFilterKernel.so'):
    source = root.parent/'SOURCE/extracted_native_libs/lib/arm64-v8a'/name
    args = [str(tool), '-lW' if name == 'libMTFilterKernel.so' else '--dyn-syms', *([] if name == 'libMTFilterKernel.so' else ['-W']), str(source)]
    start = iso(c.clock())
    p = subprocess.run(args, capture_output=True)
    finish = iso(c.clock())
    stem = 'TASK_063_R3_samples/'+name
    data['independent_reruns'].append({'library': name, 'command': args, 'started_at': start, 'ended_at': finish,
        'exit_code': p.returncode, 'input_sha256': file_sha(source), 'tool_sha256': file_sha(tool),
        'stdout_sha256': hashlib.sha256(p.stdout).hexdigest(), 'stderr_sha256': hashlib.sha256(p.stderr).hexdigest(),
        'stdout_path': '.ai/ceo/receipts/'+stem+'.stdout', 'stderr_path': '.ai/ceo/receipts/'+stem+'.stderr'})
    rerun_payloads.extend([(stem+'.stdout', p.stdout), (stem+'.stderr', p.stderr)])
for sid in ('9ed2909e','068c797c'):
    path = pathlib.Path.home()/'.paseo/schedules'/f'{sid}.json'
    obj = json.loads(path.read_text(encoding='utf-8'))
    data['schedules'].append({'id': sid, 'path': str(path), 'sha256': file_sha(path), 'observed_at': iso(c.clock()),
        'target': obj['target'], 'status': obj['status'], 'recent_runs': [{k: run.get(k) for k in ('id','scheduledFor','startedAt','endedAt','status','agentId')} | {'error_excerpt': (run.get('error') or '')[-600:]} for run in obj.get('runs', [])[-5:]]})
data['ended_at'] = iso(c.clock())
data['exit_code'] = 0
with c.transaction() as (registry, state):
    for rel, payload in rerun_payloads:
        dest = root/'.ai/ceo/receipts'/rel
        c.authorized(c.ceo_lease(registry), dest)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(payload)
    c.replace_json(root/'.ai/ceo/receipts/TASK_063_R3_additional_validation.json', data, registry)
print(json.dumps({'instructions_nonzero': sum(x['retained_instruction_count']>0 for x in data['ordinary_retained_samples']),
    'arithmetic_nonzero': sum(x['retained_arithmetic_count']>0 for x in data['ordinary_retained_samples']),
    'historical_bodies': len(data['historical_bodies']), 'false_absence_claims': sum(x['reported_path'].startswith('None') for x in data['historical_bodies']),
    'manis': next(x for x in data['keyword_scope'] if x['library']=='libManis.so'),
    'false_NE_path_exists': data['false_report_NE_entry_exists']}))
