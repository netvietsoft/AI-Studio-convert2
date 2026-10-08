const fs=require('node:fs'),path=require('node:path'),Module=require('node:module'),crypto=require('node:crypto'),assert=require('node:assert/strict');
const esbuild=require('C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/esbuild');
const actual='C:/Users/PC.DESKTOP-81LIH38/AppData/Roaming/npm/node_modules/@getpaseo/cli/node_modules/@getpaseo/server/dist/server/builtin-plugins/antigravity-provider/server/internal/session.ts';
const source=process.argv[2],mode=process.argv[3];
(async()=>{
 const bytes=fs.readFileSync(source);
 const build=await esbuild.build({stdin:{contents:bytes.toString('utf8'),resolveDir:path.dirname(actual),sourcefile:actual,loader:'ts'},bundle:true,platform:'node',format:'cjs',write:false,logLevel:'silent'});
 const mod=new Module(actual+'.bounded-fixture.cjs',module);mod.filename=actual+'.bounded-fixture.cjs';mod.paths=Module._nodeModulePaths(path.dirname(actual));mod._compile(build.outputFiles[0].text,mod.filename);
 const Session=mod.exports.Session, rows=[];let unhandled=[];
 const observe=e=>unhandled.push({code:e.code??null,message:String(e.message??e)});process.on('unhandledRejection',observe);
 try {
  for(const spec of [{name:'success',reject:false},{name:'exit255',reject:true,code:255},{name:'exit128',reject:true,code:128},{name:'unexpected_error',reject:true},{name:'stale_success',reject:false,stale:true},{name:'stale_rejection',reject:true,code:255,stale:true}]) {
   const events=[],start=unhandled.length;let called=0;
   const error=Object.assign(new Error('CONTROLLED_CLEANUP_FAILURE'),spec.code===undefined?{}:{code:spec.code});
   const driver={stop(reason){assert.equal(reason,'interrupt');called++;return spec.reject?Promise.reject(error):Promise.resolve()}};
   const session=Object.create(Session.prototype);session.state={type:'idle',driver};session.options={id:'TASK071_DISPOSABLE_FIXTURE_ONLY',emit:e=>events.push(e)};
   session.retire(driver);if(spec.stale)session.state={type:'closed'};
   await new Promise(resolve=>setTimeout(resolve,35));
   assert.equal(called,1);
   const failures=events.filter(e=>e.type==='session.runtime_failed');const actualUnhandled=unhandled.length-start;
   if(mode==='before') {assert.equal(actualUnhandled,spec.reject?1:0);assert.equal(failures.length,0)}
   else {assert.equal(mode,'after');assert.equal(actualUnhandled,0);assert.equal(failures.length,spec.reject?1:0);if(spec.reject){assert.equal(failures[0].error.code,'PROCESS_CLEANUP_FAILED');assert.match(failures[0].error.message,/CONTROLLED_CLEANUP_FAILURE/);if(spec.code!==undefined)assert.match(failures[0].error.message,new RegExp(String(spec.code)))}}
   assert.equal(session.state.type,spec.stale?'closed':spec.reject?'stopping':'dormant');
   rows.push({case:spec.name,cleanup_call_count:called,unhandled_rejections:actualUnhandled,runtime_failures:failures,state:session.state.type,result:'EXPECTED_OBSERVATION_VERIFIED'});
  }
 }finally{process.off('unhandledRejection',observe)}
 console.log(JSON.stringify({fixture_scope:'Actual bundled Session.prototype with fake Driver only; no AGY/taskkill/daemon launched',source,source_sha256:crypto.createHash('sha256').update(bytes).digest('hex'),mode,cases:rows,all_expectations_verified:true}));
})().catch(e=>{console.error(e.stack||e);process.exitCode=1});
