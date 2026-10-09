"""Walk retained local ZIP records; never infer missing archive tail contents."""
import mmap,struct,pathlib,zlib,json,importlib.util,sys
spec=importlib.util.spec_from_file_location('search073',pathlib.Path(__file__).with_name('search.py'));m=importlib.util.module_from_spec(spec);spec.loader.exec_module(m)
records=[];issues=[];found=[]
m.candidates.extend(json.loads((m.REPORT/"02_CANDIDATES.json").read_text())["candidates"])
def parse(data,label,base=0,end=None,depth=0):
 end=len(data) if end is None else end;pos=base;count=0
 while pos+30<=end:
  if data[pos:pos+4]!=b'PK\x03\x04':
   issues.append(dict(source=label,offset=pos,reason='local chain ended',signature=bytes(data[pos:pos+4]).hex(),remaining=end-pos));break
  sig,ver,flags,comp,tm,dt,crc,cs,us,nl,el=struct.unpack_from('<IHHHHHIIIHH',data,pos)
  start=pos+30+nl+el
  if start>end:issues.append(dict(source=label,offset=pos,reason='truncated local header'));break
  name=bytes(data[pos+30:pos+30+nl]).decode('utf-8' if flags&2048 else 'cp437',errors='replace')
  available=min(cs,end-start)
  r=dict(source=label,entry=name,header_offset=pos,payload_offset=start,flags=flags,compression=comp,declared_crc32=f'{crc:08x}',declared_compressed_size=cs,declared_uncompressed_size=us,available_compressed_bytes=available,complete=available==cs)
  records.append(r);count+=1
  if flags&8 or cs==0xffffffff or us==0xffffffff:
   issues.append(dict(source=label,entry=name,reason='data descriptor or ZIP64 unsupported; no guessed next boundary'));break
  low=name.lower();nested=pathlib.PurePosixPath(low).suffix in m.EXT
  target=pathlib.PurePosixPath(low).name=='libmfxkit.so'
  if comp==0 and nested and depth<8:parse(data,label+'!'+name,start,start+available,depth+1)
  elif nested and not r['complete']:issues.append(dict(source=label+'!'+name,reason='truncated compressed nested container'))
  if target or (nested and comp!=0 and r['complete']):
   payload=bytes(data[start:start+available])
   try:
    if comp==8:payload=zlib.decompress(payload,-15)
    elif comp!=0:raise ValueError('unsupported compression')
    r.update(observed_payload_bytes=len(payload),observed_crc32=f'{zlib.crc32(payload)&0xffffffff:08x}',payload_sha256=m.sha(payload))
    if target:
     m.candidate(payload,label+'!'+name,label,name,dict(size=us,compressed_size=cs,crc32=crc,compression=comp,flags=flags));found.append(m.candidates[-1])
    if nested and comp!=0:m.archive(__import__('io').BytesIO(payload),label+'!'+name,depth+1)
   except Exception as e:issues.append(dict(source=label+'!'+name,error=repr(e)))
  if not r['complete']:
   issues.append(dict(source=label,entry=name,reason='declared local payload exceeds retained container',missing_compressed_bytes=cs-available));break
  pos=start+cs
 return count
if __name__=='__main__':
 m.guard()
 for p in [m.SEARCH/'Meitu_12.17.8_APKPure.xapk',pathlib.Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/Meitu_12.17.8_APKPure.xapk')]:
  before=m.filehash(p)
  with p.open('rb') as f:
   with mmap.mmap(f.fileno(),0,access=mmap.ACCESS_READ) as mm:parse(mm,str(p))
  after=m.filehash(p);issues.append(dict(source=str(p),sha256_before=before,sha256_after=after,unchanged=before==after))
 m.js(m.REPORT/'05_LOCAL_ZIP_RECORDS.json',dict(records=records,issues=issues,candidates=found,note='Retained local records only; absent central directory/tail prevents exhaustive container coverage.'))
 print(json.dumps(dict(local_records=len(records),candidates=len(found),issues=issues),indent=2))
