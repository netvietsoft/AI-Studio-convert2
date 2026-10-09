"""Discover validated retained local-header candidates in damaged ZIP; coverage remains partial."""
import mmap,struct,pathlib,zlib,json,importlib.util
sp=importlib.util.spec_from_file_location('m',pathlib.Path(__file__).with_name('search.py'));m=importlib.util.module_from_spec(sp);sp.loader.exec_module(m)
headers=[];found=[];sources=[]
m.candidates.extend(json.loads((m.REPORT/'02_CANDIDATES.json').read_text())['candidates'])
for p in [m.SEARCH/'Meitu_12.17.8_APKPure.xapk',pathlib.Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/Meitu_12.17.8_APKPure.xapk')]:
 before=m.filehash(p)
 with p.open('rb') as f:
  with mmap.mmap(f.fileno(),0,access=mmap.ACCESS_READ) as b:
   pos=0
   while True:
    pos=b.find(b'PK\x03\x04',pos)
    if pos<0:break
    off=pos;pos+=4
    if off+30>len(b):continue
    v=struct.unpack_from('<IHHHHHIIIHH',b,off);sig,ver,flags,comp,tm,dt,crc,cs,us,nl,el=v
    start=off+30+nl+el
    if not 0<nl<4096 or start>len(b) or ver>63 or comp not in (0,8):continue
    name=bytes(b[off+30:off+30+nl])
    if b'\0' in name:continue
    try:name=name.decode('utf-8')
    except UnicodeError:continue
    r=dict(source=str(p),entry=name,header_offset=off,payload_offset=start,flags=flags,compression=comp,declared_crc32=f'{crc:08x}',declared_compressed_size=cs,declared_uncompressed_size=us,available_compressed_bytes=min(cs,len(b)-start),interpretation='signature-discovered header; not exhaustive ZIP directory')
    headers.append(r)
    if pathlib.PurePosixPath(name.lower()).name!='libmfxkit.so':continue
    if flags&8 or cs==0xffffffff or us==0xffffffff:r['status']='UNKNOWN_UNSUPPORTED_HEADER';continue
    payload=bytes(b[start:start+min(cs,len(b)-start)])
    try:
     if comp==8:payload=zlib.decompress(payload,-15)
     m.candidate(payload,str(p)+'!'+name+'@'+str(off),str(p),name,dict(size=us,compressed_size=cs,crc32=crc,compression=comp,flags=flags));found.append(m.candidates[-1]);r['candidate_id']=m.candidates[-1]['id']
    except Exception as e:r['error']=repr(e)
 sources.append(dict(path=str(p),sha256_before=before,sha256_after=m.filehash(p)))
m.js(m.REPORT/'06_RETAINED_HEADER_DISCOVERY.json',dict(headers=headers,candidates=found,sources=sources,coverage_complete=False,reason='Both original and bounded XAPK lack readable central directory. Signature header discovery cannot prove missing contents absent.'))
print(json.dumps(dict(header_count=len(headers),candidate_count=len(found),candidates=[{k:v for k,v in c.items() if k!='elf'} for c in found]),indent=2))
