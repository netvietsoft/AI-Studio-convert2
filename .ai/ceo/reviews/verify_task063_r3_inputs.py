"""Read-only source audit; writes only the CEO's independent receipt."""
from pathlib import Path
import hashlib, struct, zlib, json, csv, datetime
r = Path(__file__).resolve().parents[3]
src = Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE')
package = src / 'Meitu_12.17.8_APKPure.xapk'
started = datetime.datetime.now(datetime.timezone.utc).isoformat()
data = package.read_bytes()
entries = []
offset = 0
while True:
    idx = data.find(b'PK\x03\x04', offset)
    if idx < 0: break
    offset = idx + 4
    if idx + 30 > len(data): continue
    fields = struct.unpack_from('<IHHHHHIIIHH', data, idx)
    _, version, flags, method, mtime, mdate, crc, compressed, declared, nlen, elen = fields
    nameend = idx + 30 + nlen
    begin = nameend + elen
    if nameend > len(data) or begin > len(data): continue
    name = data[idx+30:nameend].decode('utf-8', errors='replace')
    if not (name.startswith('lib/arm64-v8a/') and name.endswith('.so')): continue
    assert flags == 0 and method == 0 and compressed == declared
    complete = begin + declared <= len(data)
    payload = data[begin:min(begin+declared, len(data))]
    file = src / 'extracted_native_libs/lib/arm64-v8a' / Path(name).name
    extracted = file.read_bytes()
    row = {'name':Path(name).name,'header_offset':idx,'payload_offset':begin,'flags':flags,
           'compression':method,'declared_bytes':declared,'available_bytes':len(payload),
           'complete':complete,'missing_bytes':declared-len(payload),
           'declared_crc32':f'{crc:08x}','available_crc32':f'{zlib.crc32(payload)&0xffffffff:08x}',
           'available_sha256':hashlib.sha256(payload).hexdigest(),'extracted_bytes':len(extracted),
           'extracted_sha256':hashlib.sha256(extracted).hexdigest(),'byte_equal':payload==extracted}
    assert row['byte_equal']
    if complete: assert len(payload)==declared and row['available_crc32']==row['declared_crc32']
    entries.append(row)
assert len(entries)==45 and len({x['name'] for x in entries})==45
assert sum(x['complete'] for x in entries)==44
csvrows = {x['library']:x for x in csv.DictReader((r/'RULES/REPORT/TASK_063_REPORT_R3/02_SO45_INPUT_MANIFEST.csv').open(encoding='utf-8'))}
for x in entries:
    assert csvrows[x['name']]['sha256']==x['extracted_sha256']
    assert int(csvrows[x['name']]['bytes'])==x['extracted_bytes']
receipt = {'command':'python -X utf8 -B .ai/ceo/reviews/verify_task063_r3_inputs.py',
           'started_at':started,'ended_at':datetime.datetime.now(datetime.timezone.utc).isoformat(),
           'exit_code':0,'package_path':str(package),'package_bytes':len(data),
           'package_sha256':hashlib.sha256(data).hexdigest(),'entries':entries,
           'scope':'Observed localheaders/payloads, not wholecontainer completeness or transport cause',
           'input_full_exists':(src/'input_full').exists()}
(r/'.ai/ceo/receipts/TASK_063_R3_input_validation.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'complete_crc_and_byte_matches':44,'all45manifest_size_sha_match':True,
                  'incomplete':[x for x in entries if not x['complete']],
                  'package_sha256':receipt['package_sha256'],'exit_code':0}))
