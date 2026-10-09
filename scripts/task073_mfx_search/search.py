"""TASK_073 bounded read-only search; never execute or overwrite native inputs."""
import os,sys,json,time,hashlib,datetime,pathlib,stat,struct,zlib,zipfile,io,csv,subprocess
ROOT=pathlib.Path.cwd()
REPORT=ROOT/'RULES/REPORT/TASK_073_REPORT_R1'
SEARCH=pathlib.Path('F:/APP/Image/com.mt.mtxx.mtxx')
ORIGINAL=pathlib.Path('F:/CONVERT/com.mt.mtxx.mtxx/SOURCE/extracted_native_libs/lib/arm64-v8a/libmfxkit.so')
TASK=ROOT/'RULES/TASK/TASK_073_MFXKIT_COMPLETE_INPUT_SEARCH_ACTIVE.md'
TASKSHA='b08a48df685ee3c9621577eb5015aa7fa87c928c914c1a0022bc0cecb0fc3829'
ACTOR='dde5055c-14d8-4831-bfa7-1c7cca30a3b7'
NATIVE='01a11e65-991a-7813-8b40-727f4e4a991c'
STANDARD='10968894cdf48a10e64671eb81969e563b40f834a8a8ab16a4ecdc479e9fc85f'
EXT={'.apk','.zip','.apks','.xapk','.aab'}
def now():return datetime.datetime.now(datetime.timezone.utc).isoformat()
def sha(b):return hashlib.sha256(b).hexdigest()
def filehash(p):
 h=hashlib.sha256()
 with open(p,'rb') as f:
  for b in iter(lambda:f.read(4*1024*1024),b''):h.update(b)
 return h.hexdigest()
def guard():
 c=json.loads((ROOT/'.ai/ceo/state.json').read_text(encoding='utf-8-sig'))['claims']['TASK_073:r1']
 l=next(x for x in json.loads((ROOT/'.ai/locks.json').read_text(encoding='utf-8-sig'))['active_locks'] if x['lease_id']==c['lease_id'])
 binding=json.loads((ROOT/'.ai/ceo/config.json').read_text(encoding='utf-8-sig'))['claim_bindings'][ACTOR]
 assert c['task_sha']==TASKSHA==filehash(TASK) and c['agent_id']==ACTOR and c['fencing_token']==1021 and c['dispatch_binding_verified']
 assert binding['native_session_id']==NATIVE==os.environ['CODEX_THREAD_ID'] and binding['task_id']=='TASK_073' and binding['revision']==1
 assert l['status']=='ACTIVE' and l['task_revision']==1 and l['fencing_token']==1021 and l['task_sha']==TASKSHA
 assert time.time()<c['expiry'] and datetime.datetime.fromisoformat(l['expiry'])>datetime.datetime.now(datetime.timezone.utc)
 flag=ROOT/'.ai/ceo/END_AGENT_SESSION.flag'
 assert not flag.exists() or flag.read_text().strip().upper()!='TRUE'
 return c
def write(p,b):
 guard();p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(b if isinstance(b,bytes) else b.encode('utf-8'))
def js(p,x):write(p,json.dumps(x,indent=2,ensure_ascii=False)+'\n')
def progress(m,**kw):js(REPORT/'PROGRESS.json',dict(schema_version='2.1.2',task_id='TASK_073',revision=1,agent_id=ACTOR,native_session_id=NATIVE,fencing_token=1021,time=now(),milestone=m,**kw))
def elf(b):
 r={'valid':False,'bounds_errors':[],'program_headers':[],'section_headers':[],'build_id':None,'soname':None}
 try:
  if b[:4]!=b'\x7fELF':raise ValueError('not ELF')
  cl=b[4];en={1:'<',2:'>'}[b[5]];r.update(elf_class=cl,endian=b[5],machine=struct.unpack_from(en+'H',b,18)[0])
  fmt='HHIQQQIHHHHHH' if cl==2 else 'HHIIIIIHHHHHH'
  h=struct.unpack_from(en+fmt,b,16)
  typ,mach,ver,entry,phoff,shoff,flags,ehsize,phents,phnum,shents,shnum,shstr=h
  r.update(type=typ,abi='arm64-v8a' if cl==2 and mach==183 else ('armeabi-v7a' if cl==1 and mach==40 else 'OTHER'),header=dict(phoff=phoff,shoff=shoff,phentsize=phents,phnum=phnum,shentsize=shents,shnum=shnum,shstrndx=shstr,ehsize=ehsize))
  if phnum==65535 or (shnum==0 and shoff) or shstr==65535:raise ValueError('extended ELF numbering unsupported')
  def bound(label,off,size):
   ok=0<=off<=len(b) and 0<=size<=len(b)-off
   if not ok:r['bounds_errors'].append(dict(label=label,offset=off,size=size,available=len(b)))
   return ok
  bound('ELF header',0,ehsize)
  pmin=56 if cl==2 else 32;smin=64 if cl==2 else 40
  if phents<pmin and phnum:raise ValueError('undersized program entry')
  if shents<smin and shnum:raise ValueError('undersized section entry')
  if bound('program table',phoff,phents*phnum):
   for i in range(phnum):
    v=struct.unpack_from(en+('IIQQQQQQ' if cl==2 else 'IIIIIIII'),b,phoff+i*phents)
    if cl==2:t,f,o,va,pa,fs,ms,a=v
    else:t,o,va,pa,fs,ms,f,a=v
    ok=bound('segment '+str(i),o,fs)
    r['program_headers'].append(dict(index=i,type=t,flags=f,offset=o,vaddr=va,filesz=fs,memsz=ms,bounded=ok))
  if bound('section table',shoff,shents*shnum):
   for i in range(shnum):
    v=struct.unpack_from(en+('IIQQQQIIQQ' if cl==2 else 'IIIIIIIIII'),b,shoff+i*shents)
    n,t,f,a,o,s,link,info,align,ents=v
    ok=True if t==8 else bound('section '+str(i),o,s)
    r['section_headers'].append(dict(index=i,name_offset=n,type=t,offset=o,size=s,link=link,entsize=ents,bounded=ok))
   if shstr<len(r['section_headers']):
    ss=r['section_headers'][shstr];names=b[ss['offset']:ss['offset']+ss['size']] if ss['bounded'] else b''
    for s in r['section_headers']:s['name']=names[s['name_offset']:].split(b'\0',1)[0].decode('utf-8','replace')
  # Read notes and dynamic strings from bounded segments, without loading code.
  for p in r['program_headers']:
   if not p['bounded']:continue
   if p['type']==4:
    pos=p['offset'];end=pos+p['filesz']
    while pos+12<=end:
     ns,ds,t=struct.unpack_from(en+'III',b,pos);pos+=12
     name=b[pos:pos+ns];pos+=(ns+3)&~3
     desc=b[pos:pos+ds];pos+=(ds+3)&~3
     if pos<=end and name.rstrip(b'\0')==b'GNU' and t==3:r['build_id']=desc.hex()
   if p['type']==2:
    vals={};step=16 if cl==2 else 8
    for pos in range(p['offset'],p['offset']+p['filesz']-step+1,step):
     tag,val=struct.unpack_from(en+('qQ' if cl==2 else 'iI'),b,pos)
     if tag==0:break
     vals[tag]=val
    if 5 in vals and 14 in vals:
     for load in r['program_headers']:
      if load['type']==1 and load['bounded'] and load['vaddr']<=vals[5]<load['vaddr']+load['filesz']:
       off=load['offset']+vals[5]-load['vaddr']+vals[14];lim=load['offset']+load['filesz']
       if off<lim:r['soname']=b[off:lim].split(b'\0',1)[0].decode('utf-8','replace')
  r['valid']=not r['bounds_errors'] and typ==3 and bool(phnum) and bool(shnum)
 except Exception as e:r['error']=str(e)
 return r
inventory=[];candidates=[];errors=[];limits=[];entries=[]
original=ORIGINAL.read_bytes();original_sha=sha(original)
def candidate(b,source,container=None,entry=None,declared=None):
 e=elf(b);crc=zlib.crc32(b)&0xffffffff;prefix=len(b)>=len(original) and b[:len(original)]==original
 mismatch=next((i for i,(a,c) in enumerate(zip(original,b)) if a!=c),None)
 if e.get('elf_class')!=2 or e.get('machine')!=183:status='INVALID' if not e.get('elf_class') else 'DIFFERENT_BUILD'
 elif not e['valid']:status='PARTIAL' if e['bounds_errors'] else 'INVALID'
 elif prefix and len(b)==1354736 and crc==0x4302c04c:status='SAME_BUILD_FULL_PREFIX_AND_CRC_MATCH'
 elif prefix and len(b)<1354736:status='PARTIAL'
 else:status='DIFFERENT_BUILD'
 r=dict(id=len(candidates)+1,source_path=source,container=container,entry=entry,payload_bytes=len(b),payload_sha256=sha(b),payload_crc32=f'{crc:08x}',declared=declared,retained_prefix_bytes=len(original),all_retained_prefix_equal=prefix,first_mismatch=mismatch,original_declared_size_match=len(b)==1354736,original_declared_crc_match=crc==0x4302c04c,classification=status,elf=e)
 if declared:r['archive_size_crc_match']=len(b)==declared['size'] and crc==declared['crc32']
 dest=REPORT/'evidence'/f'candidate_{r["id"]:03d}_{sha(b)[:12]}.so';write(dest,b);r['evidence_copy']=dest.relative_to(REPORT).as_posix();candidates.append(r)
 print('Candidate',r['id'],status,source,flush=True)
 progress('Candidate measured',candidate_count=len(candidates),latest_classification=status)
def archive(handle,chain,depth=0):
 if depth>8:limits.append(dict(source=chain,reason='nested depth >8'));return
 guard()
 try:
  with zipfile.ZipFile(handle) as z:
   infos=z.infolist();inventory.append(dict(path=chain,kind='archive',status='directory_read',entries=len(infos)))
   for inf in infos:
    name=inf.filename;low=name.lower();ext=pathlib.PurePosixPath(low).suffix
    iscandidate=pathlib.PurePosixPath(low).name=='libmfxkit.so'
    nested=ext in EXT
    entries.append(dict(container=chain,entry=name,size=inf.file_size,compressed_size=inf.compress_size,crc32=f'{inf.CRC:08x}',compression=inf.compress_type,flags=inf.flag_bits,status='candidate' if iscandidate else ('nested_container' if nested else 'name_inspected')))
    if inf.is_dir() or not (iscandidate or nested):continue
    if inf.file_size>1024*1024*1024:limits.append(dict(source=chain+'!'+name,reason='payload >1GiB'));continue
    try:
     data=z.read(inf)
     decl=dict(size=inf.file_size,compressed_size=inf.compress_size,crc32=inf.CRC,compression=inf.compress_type,flags=inf.flag_bits)
     if iscandidate:candidate(data,chain+'!'+name,chain,name,decl)
     if nested:archive(io.BytesIO(data),chain+'!'+name,depth+1)
    except Exception as e:errors.append(dict(source=chain+'!'+name,error=repr(e)))
 except Exception as e:errors.append(dict(source=chain,error=repr(e)))
def walk(p):
 try:
  st=p.lstat()
  if st.st_file_attributes & stat.FILE_ATTRIBUTE_REPARSE_POINT:inventory.append(dict(path=str(p),kind='reparse',status='excluded_no_follow'));return
  if p.is_dir():
   inventory.append(dict(path=str(p),kind='directory',status='enumerated'))
   with os.scandir(p) as it:
    for d in it:walk(pathlib.Path(d.path))
  else:
   kind='candidate' if p.name.lower()=='libmfxkit.so' else ('archive' if p.suffix.lower() in EXT else 'other')
   r=dict(path=str(p),kind=kind,size=st.st_size,status='name_inspected');inventory.append(r)
   if kind in ('candidate','archive'):
    before=filehash(p);r['sha256_before']=before
    if kind=='candidate':candidate(p.read_bytes(),str(p))
    else:archive(p,str(p))
    r['sha256_after']=filehash(p);r['unchanged']=before==r['sha256_after']
 except Exception as e:errors.append(dict(source=str(p),error=repr(e)))
def run():
 guard();progress('Bounded filesystem/container scan started',root=str(SEARCH));walk(SEARCH)
 result=dict(schema_version='2.1.2',task_id='TASK_073',revision=1,search_root=str(SEARCH),original=dict(path=str(ORIGINAL),bytes=len(original),sha256_before=original_sha,sha256_after=filehash(ORIGINAL),crc32=f'{zlib.crc32(original)&0xffffffff:08x}',elf=elf(original)),candidates=candidates,errors=errors,limits=limits,coverage_complete=not errors and not limits,inventory_count=len(inventory),archive_entry_count=len(entries))
 result['conclusion']='COMPATIBLE_INPUT_FOUND' if any(c['classification']=='SAME_BUILD_FULL_PREFIX_AND_CRC_MATCH' for c in candidates) else ('INCOMPLETE_COVERAGE' if errors or limits else ('NO_COMPATIBLE_INPUT' if candidates else 'NOT_FOUND'))
 js(REPORT/'02_CANDIDATES.json',result);js(REPORT/'03_INVENTORY.json',inventory);js(REPORT/'04_ARCHIVE_ENTRIES.json',entries)
 fields=['id','source_path','payload_bytes','payload_sha256','payload_crc32','classification','all_retained_prefix_equal','original_declared_size_match','original_declared_crc_match']
 out=io.StringIO();w=csv.DictWriter(out,fields,extrasaction='ignore');w.writeheader();w.writerows(candidates);write(REPORT/'02_CANDIDATES.csv',out.getvalue())
 progress('Bounded scan and candidate integrity finished',conclusion=result['conclusion'],coverage_complete=result['coverage_complete'],candidates=len(candidates),errors=len(errors),limits=len(limits))
 print(json.dumps({k:result[k] for k in ('conclusion','coverage_complete','inventory_count','archive_entry_count')},indent=2),flush=True)
if __name__=='__main__':run()
