"""Execute an owned diagnostic script and serialize actual command receipt."""
import importlib.util,pathlib,sys,subprocess
p=pathlib.Path(__file__).with_name('search.py');s=importlib.util.spec_from_file_location('s',p);m=importlib.util.module_from_spec(s);s.loader.exec_module(m)
m.guard();script=pathlib.Path(__file__).with_name(sys.argv[1]);assert script.parent==p.parent
argv=[sys.executable,'-X','utf8','-B',str(script)];started=m.now();result=subprocess.run(argv,capture_output=True);ended=m.now();stem=script.stem
m.write(m.REPORT/'raw'/f'{stem}.stdout.txt',result.stdout);m.write(m.REPORT/'raw'/f'{stem}.stderr.txt',result.stderr)
m.js(m.REPORT/'raw'/f'{stem}.receipt.json',dict(argv=argv,cwd=str(pathlib.Path.cwd()),started_at=started,ended_at=ended,exit_code=result.returncode,python_sha256=m.filehash(sys.executable),script_sha256=m.filehash(script),runner_sha256=m.filehash(__file__),stdout_sha256=m.sha(result.stdout),stderr_sha256=m.sha(result.stderr),original_sha256_before=m.original_sha,original_sha256_after=m.filehash(m.ORIGINAL)))
print(result.stdout.decode('utf-8'));print(result.stderr.decode('utf-8'));sys.exit(result.returncode)
