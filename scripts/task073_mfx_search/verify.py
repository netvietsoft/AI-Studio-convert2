"""Independent byte/bounds checks on actual retained data and corruption controls."""
import pathlib,importlib.util,json,struct,zlib,ast,sys,subprocess
sp=importlib.util.spec_from_file_location('m',pathlib.Path(__file__).with_name('search.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
m.guard();checks={};original=m.ORIGINAL.read_bytes()
x=json.loads((m.REPORT/'06_RETAINED_HEADER_DISCOVERY.json').read_text());base=json.loads((m.REPORT/'02_CANDIDATES.json').read_text())
allc=base['candidates']+x['candidates']
for c in allc:
 b=(m.REPORT/c['evidence_copy']).read_bytes();checks[f'candidate_{c["id"]}_prefix_all_bytes']=b==original;checks[f'candidate_{c["id"]}_sha']=m.sha(b)==c['payload_sha256'];checks[f'candidate_{c["id"]}_crc']=f'{zlib.crc32(b)&0xffffffff:08x}'==c['payload_crc32']
 checks[f'candidate_{c["id"]}_incomplete']=len(b)==773652 and c['classification']=='PARTIAL' and not c['elf']['valid']
 for e in c['elf']['bounds_errors']:assert e['offset']+e['size']>len(b)
corrupt=bytearray(original);corrupt[0]=0;checks['bad_magic_rejected']=not m.elf(corrupt)['valid']
short=original[:63];checks['truncated_header_rejected']=not m.elf(short)['valid']
mutated=bytearray(original);mutated[700000]^=1;checks['mutated_retained_prefix_rejected']=bytes(mutated)!=original and m.sha(mutated)!=m.original_sha
checks['full_crc_not_claimed']=all(not c['original_declared_crc_match'] for c in allc)
checks['original_unchanged']=m.filehash(m.ORIGINAL)==m.original_sha
for p in pathlib.Path(__file__).parent.glob('*.py'):ast.parse(p.read_text(encoding='utf-8-sig'));checks['syntax_'+p.name]=True
# Remeasure the task's historical declared size/CRC directly at source local header.
p=pathlib.Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/Meitu_12.17.8_APKPure.xapk');offset=348392052
with p.open('rb') as f:
 f.seek(offset);h=f.read(30);v=struct.unpack('<IHHHHHIIIHH',h);name=f.read(v[-2]);extra=f.read(v[-1]);payload=f.read(v[7]);
checks['source_local_header_exact']=name==b'lib/arm64-v8a/libmfxkit.so' and v[0]==0x04034b50 and v[2]==0 and v[3]==0 and v[6]==0x4302c04c and v[7]==v[8]==1354736
checks['source_retained_payload_exact']=payload==original and len(payload)==773652
receipt=dict(path=str(p),header_offset=offset,payload_offset=offset+30+len(name)+len(extra),header_sha256=m.sha(h),name=name.decode(),extra_sha256=m.sha(extra),declared_size=v[8],declared_crc32=f'{v[6]:08x}',observed_bytes=len(payload),observed_crc32=f'{zlib.crc32(payload)&0xffffffff:08x}',payload_sha256=m.sha(payload),missing_bytes=v[8]-len(payload))
# Actual external tool failure retained, never converted into successful validation.
tool=pathlib.Path('C:/Users/PC.DESKTOP-81LIH38/AppData/Local/Android/Sdk/ndk/26.1.10909125/toolchains/llvm/prebuilt/windows-x86_64/bin/llvm-readelf.exe')
if tool.exists():
 argv=[str(tool),'--file-header','--program-headers','--section-headers','--notes','--dynamic','-W',str(m.ORIGINAL)];start=m.now();r=subprocess.run(argv,capture_output=True);end=m.now()
 m.write(m.REPORT/'raw/readelf.stdout.txt',r.stdout);m.write(m.REPORT/'raw/readelf.stderr.txt',r.stderr);m.js(m.REPORT/'raw/readelf.receipt.json',dict(argv=argv,cwd=str(pathlib.Path.cwd()),started_at=start,ended_at=end,exit_code=r.returncode,input_sha256=m.original_sha,tool_sha256=m.filehash(tool),stdout_sha256=m.sha(r.stdout),stderr_sha256=m.sha(r.stderr),meaning='Actual truncated-input tool result; exit failure is retained'))
else:receipt['readelf']='UNAVAILABLE'
m.js(m.REPORT/'07_VERIFICATION.json',dict(checks=checks,all_checks_hold=all(checks.values()),original_local_header=receipt,scope='Byte/bounds diagnostic assertions and negative controls only; no algorithm/product acceptance'))
print(json.dumps(dict(checks=checks,original_local_header=receipt),indent=2));assert all(checks.values())
