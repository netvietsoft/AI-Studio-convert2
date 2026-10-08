"""One bounded TASK067 R2 causal reproduction; never imports R3 main."""
import ast, copy, csv, datetime, hashlib, io, json, os, re, struct, subprocess, sys, zipfile, zlib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
OUT = ROOT / 'RULES/REPORT/TASK_067_REPORT_R2'
RAW = OUT / 'raw'
SOURCE = ROOT.parent / 'SOURCE'
STANDARD = '10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
def now(): return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(b): return hashlib.sha256(b).hexdigest()
def fsha(p):
    h=hashlib.sha256()
    with open(p,'rb') as f:
        for b in iter(lambda:f.read(1048576),b''): h.update(b)
    return h.hexdigest()
def guard():
    leases=json.loads((ROOT/'.ai/locks.json').read_text(encoding='utf-8-sig'))['active_locks']
    lease=next(x for x in leases if x['lease_id']=='LEASE-CEO-WORKER-TASK_067-R2')
    assert lease['status']=='ACTIVE' and lease['fencing_token']==1013
    assert datetime.datetime.fromisoformat(lease['expiry'])>datetime.datetime.now(datetime.timezone.utc)
def write(p,b):
    guard(); p.parent.mkdir(parents=True,exist_ok=True); p.write_bytes(b)
def jwrite(p,obj): write(p,json.dumps(obj,ensure_ascii=False,indent=2).encode('utf-8'))
def binding(p): return {'path':str(p),'sha256':fsha(p),'bytes':p.stat().st_size}
def run(cmd,label,inputs):
    start=now(); p=subprocess.run(cmd,capture_output=True); end=now()
    a=RAW/(label+'.stdout'); b=RAW/(label+'.stderr'); write(a,p.stdout); write(b,p.stderr)
    return {'command':cmd,'started_at':start,'ended_at':end,'exit_code':p.returncode,
            'tool':binding(Path(cmd[0])),'inputs':[binding(x) for x in inputs],
            'stdout':binding(a),'stderr':binding(b)}

def main():
    guard(); started=now()
    generator=ROOT/'scripts/task063_r3/generate_deliverables_r3.py'
    text=generator.read_text(encoding='utf-8'); lines=text.splitlines(); tree=ast.parse(text)
    anchors=[]
    def fragment(node,label):
        s='\n'.join(lines[node.lineno-1:node.end_lineno])+'\n'
        p=RAW/(label+'.source.txt'); write(p,s.encode())
        anchors.append({'label':label,'original':binding(generator),'start_line':node.lineno,
                        'end_line':node.end_lineno,'fragment':binding(p)})
        return node
    defs={n.name:n for n in tree.body if isinstance(n,ast.FunctionDef)}
    # Compile only audited pure helpers, never main or module top-level code.
    selected=[fragment(defs[n],n) for n in ['sha256_bytes','crc32_bytes','parse_zip_entries']]
    ns={'hashlib':hashlib,'zlib':zlib,'struct':struct,'Path':Path}
    exec(compile(ast.Module(body=selected,type_ignores=[]),str(generator),'exec'),ns)
    assignments={n.targets[0].id:n for n in tree.body if isinstance(n,ast.Assign) and isinstance(n.targets[0],ast.Name)}
    for key in ['INS_RE','ARITH_MNEMONICS']:
        node=fragment(assignments[key],key)
        exec(compile(ast.Module(body=[node],type_ignores=[]),str(generator),'exec'),dict(ns,re=re),ns)
    branch=next(n for n in ast.walk(defs['main']) if isinstance(n,ast.If) and ast.unparse(n.test)=="ce['complete']")
    match=next(n for n in ast.walk(defs['main']) if isinstance(n,ast.Assign) and ast.unparse(n.targets[0])=='byte_match')
    fragment(match,'actual_byte_match'); fragment(branch,'actual_status_branch')
    code=compile(ast.Module(body=[match,branch],type_ignores=[]),str(generator),'exec')
    def old(ce,disk):
        e={'ce':ce,'disk_data':disk,'info':{'bytes':len(disk)},'c_data':ce['data_offset'],
           'c_avail':ce['available_bytes'],'c_decl':ce['declared_bytes']}
        exec(code,e); return {'byte_match':e['byte_match'],'status':e['c_status'],'note':e['trunc_note']}
    def reference(ce,disk,compressed):
        reasons=[]
        if ce['flags']!=0: reasons.append('UNSUPPORTED_FLAGS')
        if ce['method']!=0: reasons.append('UNSUPPORTED_COMPRESSION')
        if compressed!=ce['declared_bytes']: reasons.append('STORED_SIZE_INCONSISTENT')
        if ce['payload_bytes']!=disk: reasons.append('PAYLOAD_NOT_EQUAL')
        if len(disk)!=ce['available_bytes']: reasons.append('DISK_AVAILABLE_SIZE_MISMATCH')
        if ce['complete'] and ce['available_crc32']!=ce['declared_crc32']: reasons.append('CRC_MISMATCH')
        status='REJECTED' if reasons else ('EXACT_PAYLOAD_MATCH' if ce['complete'] else 'PARTIAL_PREFIX_MATCH_TAIL_UNKNOWN')
        return {'status':status,'reasons':reasons,'complete_crc_checked':ce['complete'],
                'partial_crc_note':None if ce['complete'] else 'Full declared CRC cannot be checked on a prefix'}
    container=SOURCE/'Meitu_12.17.8_APKPure.xapk'; blob=container.read_bytes()
    ns['open']=lambda *a,**k:io.BytesIO(blob)
    entries,sz,h=ns['parse_zip_entries'](container)
    cases=[]; controls=[]
    for name in ['libaicodec.so','libmfxkit.so']:
        ce=entries[name]; diskp=SOURCE/'extracted_native_libs/lib/arm64-v8a'/name; disk=diskp.read_bytes()
        off=ce['header_offset']; header=blob[off:ce['data_offset']]; compressed=struct.unpack_from('<I',header,18)[0]
        controls.append({'name':name,'input':binding(diskp),'header_offset':off,'data_offset':ce['data_offset'],
                         'header_hex':header.hex(),'declared_compressed':compressed,
                         'entry':{k:v for k,v in ce.items() if k!='payload_bytes'}})
        # Actual parser on exact local header/payload bytes, offset rebased to zero for memory tests.
        original_slice=header+ce['payload_bytes']
        variants=[('positive',None,None),('payload_byte',None,None),('declared_crc',14,'crc'),
                  ('flags',6,'flags'),('method',8,'method'),('compressed_size',18,'size'),('declared_size',22,'size')]
        for label,pos,kind in variants:
            mem=bytearray(original_slice)
            if label=='payload_byte': mem[len(header)+64]^=1
            elif kind=='crc': struct.pack_into('<I',mem,pos,struct.unpack_from('<I',mem,pos)[0]^1)
            elif kind=='flags': struct.pack_into('<H',mem,pos,1)
            elif kind=='method': struct.pack_into('<H',mem,pos,8)
            elif kind=='size': struct.pack_into('<I',mem,pos,struct.unpack_from('<I',mem,pos)[0]+1)
            ns['open']=lambda *a,**k:io.BytesIO(mem)
            parsed,_,_=ns['parse_zip_entries'](Path('IN_MEMORY_ONLY'))
            got=parsed[name]; comp=struct.unpack_from('<I',mem,18)[0]
            cases.append({'input':name,'case':label,'mutation_offset_in_slice':pos if pos is not None else (len(header)+64 if label=='payload_byte' else None),
                          'memory_slice_sha256':sha(mem),'original_slice_sha256':sha(original_slice),
                          'parser_complete':got['complete'],'parser_declared':got['declared_bytes'],
                          'parser_available':got['available_bytes'],'declared_crc':got['declared_crc32'],
                          'available_crc':got['available_crc32'],'old':old(got,disk),'reference':reference(got,disk,comp)})
    input_result={'container':binding(container),'controls':controls,'cases':cases,
                  'mutation_policy':'Original bytes never changed; BytesIO runs original AST-extracted parser; header coordinates rebased only for memory slices'}
    jwrite(RAW/'input_cases.json',input_result)
    # Strict no-raw-insn syntax parser; rejects invalid address/mnemonic and labels.
    good=re.compile(r'^\s*([0-9a-fA-F]+):\s+([a-zA-Z][a-zA-Z0-9.]*)\s*(.*)$')
    def parse(line):
        m=good.fullmatch(line)
        return {'address':int(m[1],16),'mnemonic':m[2].lower(),'operands':m[3]} if m and int(m[1],16)%4==0 else None
    samples=[]
    for name in ['libaicodec.so','libaidetectionplugin.so','libPVGColorFunctions.so','libMTLReportTool.so','libManis.so']:
        p=ROOT/'RULES/REPORT/TASK_063_REPORT_R3/raw'/('objdump_'+name+'.stdout.txt')
        ls=p.read_text(encoding='utf-8').splitlines(); parsed=[(i,l,parse(l)) for i,l in enumerate(ls,1) if parse(l)]
        oldmatches=[ns['INS_RE'].match(l) for l in ls]; oldmatches=[m for m in oldmatches if m]
        examples=[{'line':i,'literal':l,'parsed':v} for i,l,v in parsed[:4]]
        arithmetic=[{'line':i,'literal':l,'parsed':v} for i,l,v in parsed if v['mnemonic'] in ns['ARITH_MNEMONICS']]
        samples.append({'library':name,'retained':binding(p),'lines':len(ls),'old_instructions':len(oldmatches),
                        'old_arithmetic':sum(m[1].lower() in ns['ARITH_MNEMONICS'] for m in oldmatches),
                        'reference_instructions':len(parsed),'reference_arithmetic':len(arithmetic),
                        'noninstruction_text_lines':len(ls)-len(parsed),'examples':examples,'arithmetic_examples':arithmetic[:10],
                        'scope':'PARTIAL_FIRST_1500_LINES; no conclusion about whole-library arithmetic',
                        'historical_command_start_end_exit':'UNKNOWN; not reconstructed from file mtime'})
    malformed=['nothex: add x0, x1, x2','00000000000ce7a0 <.text>:','ce7a0: ???','ce7a0: 12345678 add x0','ce7a1: add x0','Disassembly of section .text:','']
    parser_tests=[{'literal':l,'parsed':parse(l),'expected':None} for l in malformed]
    assert all(x['parsed'] is None for x in parser_tests)
    assert [(s['reference_instructions'],s['reference_arithmetic']) for s in samples]==[(1470,8),(1464,0),(1450,0),(1466,0),(1494,0)]
    jwrite(RAW/'parser_cases.json',{'samples':samples,'malformed_checks':parser_tests})
    # Original APK C2 bytes and literal model path; historical critical report is compared as text.
    apk=SOURCE/'com.mt.mtxx.mtxx.apk'; report=ROOT/'RULES/REPORT/TASK_063_REPORT_R3/05_CRITICAL_CLAIM_CHECKS.md'
    c2entry='assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs'
    with zipfile.ZipFile(apk) as z:
        encrypted=z.read(c2entry); key=bytes.fromhex('7c34b93a'); decoded=bytes(v^key[i%4] for i,v in enumerate(encrypted))
        models=[{'entry':n,'bytes':len(z.read(n)),'sha256':sha(z.read(n))} for n in z.namelist() if n.endswith('/NE.manis')]
        false_path='assets/vlaimodel/libmtface/models/NE.manis'
        missing=false_path not in z.namelist()
    write(RAW/'C2.original_encrypted.bin',encrypted); write(RAW/'C2.decoded.fs',decoded)
    rlines=report.read_text(encoding='utf-8').splitlines()
    mismatch=[{'line':i,'literal':l} for i,l in enumerate(rlines,1) if 'blendColor' in l or '303' in l or 'NE.manis' in l]
    readelf=Path(r'C:\Users\PC.DESKTOP-81LIH38\AppData\Local\Android\Sdk\ndk\26.1.10909125\toolchains\llvm\prebuilt\windows-x86_64\bin\llvm-readelf.exe')
    manis=SOURCE/'extracted_native_libs/lib/arm64-v8a/libManis.so'
    receipt=run([str(readelf),'-Ws',str(manis)],'manis_readelf',[manis])
    assert receipt['exit_code']==0
    symbols=[]
    for i,l in enumerate((RAW/'manis_readelf.stdout').read_text(encoding='utf-8').splitlines(),1):
        p=l.split()
        if len(p)>=8 and p[0].rstrip(':').isdigit() and p[6]!='UND' and int(p[1],16)!=0:
            symbols.append({'line':i,'name':p[7],'literal':l})
    hits=[s for s in symbols if 'manis' in s['name'].lower()]
    assert len(symbols)==303 and len(hits)==288
    critical={'apk':binding(apk),'C2':{'entry':c2entry,'raw_sha256':sha(encrypted),'decoded_sha256':sha(decoded),
                 'literal_anchors':[{'line':i,'literal':l} for i,l in enumerate(decoded.decode().splitlines(),1) if 'SoftLight' in l or 'return' in l],
                 'contains_invented_blendColor':b'blendColor' in decoded},
              'R3_report':binding(report),'R3_mismatch_anchors':mismatch,'model_assets':models,'nonexistent_path':false_path,
              'nonexistent_path_confirmed':missing,'manis_command':receipt,'defined_nonzero_total':len(symbols),
              'manis_name_hits':len(hits),'keyword_match_policy':'case-insensitive substring in actual defined nonzero names',
              'manis_hit_lines':hits}
    assert b'SoftLight_Fcn' in decoded and b'blendColor' not in decoded and missing
    # Explicit reuse, not a new claim of rerunning the CEO critical command.
    prior=ROOT/'.ai/ceo/receipts/TASK_063_R3_critical/critical_source_reproduction.json'
    pc=json.loads(prior.read_text()); reused={'receipt':binding(prior),'mode':'HASH_BOUND_REUSE; historical command times retained, not worker execution',
          'historical_started_at':pc['started_at'],'historical_ended_at':pc['ended_at'],'historical_exit_code':pc['exit_code'],
          'math':pc['math'],'native':pc['native'],'body':pc['body'],'current_input_matches':{}}
    for k in ['native','body']:
        p=Path(pc[k]['path']); reused['current_input_matches'][k]=fsha(p)==pc[k]['sha256']; assert reused['current_input_matches'][k]
    assert pc['math']['w3c']=='69/512' and pc['math']['shader']=='5/32' and pc['math']['difference']=='11/512'
    assert sum(len(v) for v in pc['native']['tables'].values())==30
    assert any('002344e8' in l for l in pc['body']['anchors'].values())
    critical['known_good_controls']=reused
    metadata=Path(r'F:\TOOLS\ghidra_12.1.4_PUBLIC\Ghidra\application.properties')
    critical['ghidra_metadata']={'source':binding(metadata),'literal_version_lines':[l for l in metadata.read_text().splitlines() if 'version' in l or 'build' in l]}
    heartbeat=ROOT/'.ai/ceo/receipts/TASK_063_R3_additional_validation.json'
    critical['heartbeat_reuse']={'source':binding(heartbeat),'data':json.loads(heartbeat.read_text()),
        'limits':'Historical receipt reuse only. Registration/busy/failed statuses do not establish successful continuous scans; current provider status UNKNOWN.'}
    jwrite(RAW/'critical_cases.json',critical); jwrite(RAW/'source_anchors.json',anchors)
    # Regression outcomes are measured against expected diagnostic distinctions, never baseline PASS.
    checks={'complete_positive':cases[0]['reference']['status']=='EXACT_PAYLOAD_MATCH',
       'complete_mutations_reference_rejected':all(c['reference']['status']=='REJECTED' for c in cases[1:7]),
       'old_accepts_corrupt_payload':cases[1]['old']['status']=='EXACT_PAYLOAD_MATCH' and not cases[1]['old']['byte_match'],
       'partial_positive_tail_unknown':cases[7]['reference']['status']=='PARTIAL_PREFIX_MATCH_TAIL_UNKNOWN',
       'partial_payload_reference_rejected':cases[8]['reference']['status']=='REJECTED',
       'partial_crc_not_falsely_proven':not cases[9]['reference']['complete_crc_checked'],
       'five_real_parser_counts':True,'malformed_lines_rejected':True,'C2_literal_diff':True,'Manis_288_vs_303':True,
       'known_good_hash_bound_controls':all(reused['current_input_matches'].values())}
    assert all(checks.values()), checks
    result={'schema_version':'2.1.2','task_id':'TASK_067','revision':2,'classification':'OBSERVED causal diagnostic only',
            'started_at':started,'ended_at':now(),'command':'python -X utf8 -B scripts/task067_diagnostic_r2/diagnose.py',
            'script':binding(Path(__file__)),'fencing_token':1013,'input_status':input_result,
            'retained_parser':{'samples':samples,'malformed_checks':parser_tests},'critical_provenance':critical,
            'source_anchors':anchors,'regression_checks':checks,'exit_code':0,
            'UNKNOWN':['original R3 per-command timestamps/exits not serialized','model architecture/runtime/producer/defaults','mfx tail and truncation cause','current provider availability/continuous heartbeat delivery']}
    jwrite(OUT/'02_DIAGNOSTIC_RESULTS.json',result)
    print(json.dumps({'diagnostic_checks':checks,'results':str(OUT/'02_DIAGNOSTIC_RESULTS.json'),'elapsed_scope':'one diagnostic execution'},ensure_ascii=False))

if __name__=='__main__': main()
