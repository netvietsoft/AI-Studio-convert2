"""Independent read-only source reproduction; writes only CEO receipts under its lease."""
from pathlib import Path
import datetime, hashlib, json, struct, subprocess, sys, zipfile
from fractions import Fraction as F
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from controller import Controller, file_sha, iso

root = Path(__file__).resolve().parents[3]
c = Controller(root)
source = root.parent / 'SOURCE'
start = iso(c.clock())
apk = source / 'com.mt.mtxx.mtxx.apk'
receipt = {'started_at': start, 'command': 'python -X utf8 -B .ai/ceo/reviews/verify_task063_r2_critical.py',
           'script_sha256': file_sha(Path(__file__)), 'apk': str(apk), 'apk_sha256': file_sha(apk), 'shaders': []}
with zipfile.ZipFile(apk) as z:
    for entry, decoded_name in [
        ('assets/ARKernelBuiltin/Shaders/MTFilter_HairMaskMix.fs', 'ARKernelBuiltin_Shaders_MTFilter_HairMaskMix.fs'),
        ('assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs', 'ARKernelBuiltin_Shaders_HairSoft_MTFilter_PsSoftLightr.fs')]:
        encrypted = z.read(entry)
        key = bytes.fromhex('7c34b93a')
        decoded = bytes(b ^ key[i % 4] for i, b in enumerate(encrypted))
        prior = root / '.ai/reconstruction/evidence/TASK_061/decoded_shaders' / decoded_name
        receipt['shaders'].append({'entry': entry, 'raw_sha256': hashlib.sha256(encrypted).hexdigest(),
            'decoded_sha256': hashlib.sha256(decoded).hexdigest(), 'prior_path': str(prior),
            'prior_sha256': file_sha(prior), 'byte_equal': decoded == prior.read_bytes(),
            'decoded_text': decoded.decode('utf-8', errors='backslashreplace'), 'xor_key': key.hex()})
    model_names = [n for n in z.namelist() if 'mtface_parsing' in n or n.endswith('/NE.manis')]
    receipt['model_assets'] = [{'entry': n, 'bytes': len(z.read(n)), 'sha256': hashlib.sha256(z.read(n)).hexdigest()} for n in model_names]

native = source / 'extracted_native_libs/lib/arm64-v8a/libMTFilterKernel.so'
blob = native.read_bytes()
receipt['native'] = {'path': str(native), 'sha256': hashlib.sha256(blob).hexdigest(), 'tables': {}}
for offset in [0x8fd28, 0x8fd3c, 0x8fd50, 0x8edc4, 0x8edd8, 0x8edec]:
    receipt['native']['tables'][hex(offset)] = [{'offset': hex(offset + 4*i), 'float32': struct.unpack_from('<f', blob, offset+4*i)[0],
        'bytes_le': blob[offset+4*i:offset+4*i+4].hex()} for i in range(5)]
body = root / '.ai/reconstruction/evidence/TASK_061/ghidra_decompiled/libMTFilterKernel.so_decompiled.txt'
lines = body.read_text(encoding='utf-8', errors='replace').splitlines()
receipt['body'] = {'path': str(body), 'sha256': file_sha(body), 'anchors': {str(i): lines[i-1] for i in list(range(23492,23498)) + list(range(23597,23606))}}
A, B = F(1,16), F(3,4)
D = ((16*A-12)*A+4)*A
w3c = A+(2*B-1)*(D-A)
shader = 2*A*(1-B)+F(1,4)*(2*B-1)
receipt['math'] = {'A': str(A), 'B': str(B), 'D': str(D), 'w3c': str(w3c), 'w3c_decimal': float(w3c),
                   'shader': str(shader), 'shader_decimal': float(shader), 'difference': str(shader-w3c)}
aurora = source / 'extracted_assets/assets/MTAurora.bundle/Shaders/hairmask_blur.fs.spirv'
tool_cfg = json.loads((root/'RULES/REPORT/TASK_063_REPORT_R2/06_TOOLCHAIN_AND_HEARTBEAT_RECEIPTS.json').read_text())
spirv_dis = Path(tool_cfg['toolchains']['spirv_dis']['path'])
command = [str(spirv_dis), '--raw-id', str(aurora)]
tool_start = iso(c.clock())
proc = subprocess.run(command, capture_output=True)
receipt['aurora'] = {'path': str(aurora), 'sha256': file_sha(aurora), 'tool_sha256': file_sha(spirv_dis),
    'command': command, 'started_at': tool_start, 'ended_at': iso(c.clock()), 'exit_code': proc.returncode,
    'stdout_sha256': hashlib.sha256(proc.stdout).hexdigest(), 'stderr_sha256': hashlib.sha256(proc.stderr).hexdigest()}
receipt['ended_at'] = iso(c.clock())
receipt['exit_code'] = 0
out = root / '.ai/ceo/receipts/TASK_063_R2_critical'
with c.transaction() as (registry, state):
    for name, payload in [('critical_source_reproduction.json', json.dumps(receipt, ensure_ascii=False, indent=2).encode()),
                          ('aurora.spvasm.stdout', proc.stdout), ('aurora.spvasm.stderr', proc.stderr)]:
        dest = out/name
        c.authorized(c.ceo_lease(registry), dest)
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_bytes(payload)
    print(json.dumps({'receipt': str(out/'critical_source_reproduction.json'), 'shaders_equal': [r['byte_equal'] for r in receipt['shaders']],
                      'math': receipt['math'], 'spirv_exit': proc.returncode}))
