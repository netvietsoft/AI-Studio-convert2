"""Task-owned discovery index and source-provenance package; no product integration."""
import json
from pathlib import Path
import acquire as a

ROOT, REPORT, BASE = a.ROOT, a.REPORT, a.BASE
DOCS = ROOT / 'Docs/Reconstruction/References/storytold'
assert not (REPORT / 'COMPLETE.json').exists(), 'Frozen candidate already exists'
manifest = json.loads((REPORT / '02_SOURCE_MANIFEST.json').read_text(encoding='utf-8'))
catalog = []
modules = {
 'photocraft': ['crates/paint/src/lib.rs','crates/algo/src/matting.rs','crates/ops/src/lib.rs','crates/color/src/blend.rs','crates/compose/src/lib.rs'],
 'lightcraft': ['crates/pipeline/src/colorops.rs','crates/pipeline/src/lut.rs','crates/develop/src/settings.rs'],
 'filmcraft': ['crates/color/src/lut.rs','crates/edit/src/lib.rs'],
}
for s in manifest['sources']:
    records = {v['path']: v for v in s['files']}
    selected = []
    for rel in modules[s['name']] + [v['path'] for v in s['license_files']]:
        p = BASE / s['name'] / rel
        assert a.sha(p.read_bytes()) == records[rel]['sha256']
        selected.append({'path': str(p.relative_to(ROOT)).replace('\\','/'), 'sha256': records[rel]['sha256'],
                         'upstream': 'https://github.com/storytold/'+s['name']+'/blob/'+s['commit']+'/'+rel})
    catalog.append({'repository': s['name'], 'commit': s['commit'], 'selected_modules_and_licenses': selected})
mapping = '''# Đối chiếu nguồn Storytold với SO45

Phân loại: UPSTREAM_OPEN_SOURCE_REFERENCE. Đây là nguồn bên ngoài để tham khảo và so sánh; nguồn Meitu vẫn ở .ai/reconstruction/evidence. Không thay ledger, P0 hoặc cổng V4.

| Module nguồn | Chứng cứ Meitu / phạm vi | Quan hệ hiện đã xác minh |
|---|---|---|
| PhotoCraft color/src/blend.rs, soft_light_ps | RULES/REPORT/TASK_067_REPORT_R2/raw/C2.decoded.fs; APK assets/ARKernelBuiltin/Shaders/HairSoft/MTFilter_PsSoftLightr.fs | Hai biểu thức theo kênh tương đương đại số khi A,B trong0..1. PhotoCraft clamp trước sqrt; shader Meitu mix theo uniform alpha và xuất alpha1. Parity toàn pixel, alpha, không gian màu và rounding vẫn UNKNOWN. Cả hai khác nhánh W3C với A nhỏ. |
| PhotoCraft algo/src/matting.rs | .ai/reconstruction/evidence/TASK_061/ghidra_decompiled/libMTFilterKernel.so_decompiled.txt; native blur entry0x2344e8 theo CEO receipt | Guided-filter refinement là ứng viên cùng miền xử lý mask, không phải bản khôi phục kernel blur Meitu. Input/quality/parity cần thử riêng sau Adapter P0. |
| PhotoCraft paint/src/lib.rs, ops/src/lib.rs, compose/src/lib.rs | NO_VERIFIED_COUNTERPART trong baseline hiện đã nghiệm thu | Tham khảo brush, history chia sẻ tile, layer/mask ở tầng editor. Không suy diễn đối ứng từ tên libLayerFlow. |
| LightCraft colorops/settings/LUT, FilmCraft color/LUT | NO_VERIFIED_COUNTERPART; TASK064C vẫn PLANNED | Bổ sung chỉnh màu/preset; app hiện có nativeApply3DLut. Không thay đường LUT chỉ vì trùng tên thuật toán. |
| FilmCraft edit/src/lib.rs | NO_VERIFIED_COUNTERPART; TASK064E vẫn PLANNED | Nguồn tham khảo logic timeline nếu cần video, chưa chứng minh codec/Android parity. |

Chứng cứ đã có: SHA native libMTFilterKernel.so f938fe73095fceba72875d1ab42f8aeb6a9f31f3933831bec070404c0e7ecac4; body60b92fa0235d27cc37d088107f4ad9735fe2d2eecf15047bd36d63dc32a7d3cb. C2 decoded69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14. Kết quả Fraction mẫu A1/16,B3/4: Meitu/PhotoCraft5/32; W3C69/512; chênh11/512. Đây là kiểm đại số, không phải Android pixel benchmark.
'''
assert a.sha((ROOT/'RULES/REPORT/TASK_067_REPORT_R2/raw/C2.decoded.fs').read_bytes()) == '69eb6db94958c599c01f432208dd47d5fd64a397e47b8b6c7ea0163fd1855d14'
pc=json.loads((ROOT/'.ai/ceo/receipts/TASK_063_R3_critical/critical_source_reproduction.json').read_text())
for key in ['native','body']:
    assert a.sha(Path(pc[key]['path']).read_bytes()) == pc[key]['sha256']
readme = '''# Kho nguồn Storytold cạnh SO45

Đã tải PhotoCraft, LightCraft, FilmCraft về .ai/reconstruction/reference_sources/storytold. Ba checkout cố định commit, có đầy đủ2695 file tracked (79949717 byte), không có LFS pointer hoặc submodule. Nguồn Meitu nằm cạnh đó tại .ai/reconstruction/evidence.

| Repo | Commit | Nguồn local |
|---|---|---|
| PhotoCraft | 452672765d91acef793bae654e6a29cf10fa5df2 | [Mã nguồn](../../../../.ai/reconstruction/reference_sources/storytold/photocraft) |
| LightCraft | 629e39380e296f588c64cd9c0053a8edc3528f36 | [Mã nguồn](../../../../.ai/reconstruction/reference_sources/storytold/lightcraft) |
| FilmCraft | 61238bf8fc129077fe2b7982550303be49f55a93 | [Mã nguồn](../../../../.ai/reconstruction/reference_sources/storytold/filmcraft) |

[Bảng đối chiếu](COMPARISON_MAP.md) · [Module và hash](REFERENCE_CATALOG.json) · [Manifest đầy đủ](../../../../RULES/REPORT/TASK_068_REPORT_R1/02_SOURCE_MANIFEST.json).

UPSTREAM_OPEN_SOURCE_REFERENCE: chưa ghép production, chưa build/benchmark Android, không thay chứng cứ khai thác45SO. Giữ nguyên LICENSE-MIT/LICENSE-APACHE, NOTICE/ATTRIBUTION. License model/font/asset/dependency và branding phải kiểm riêng. ArtCraft không được nhập vào bộ này. Không tự pull/update commit, chạy script upstream hoặc cài dependencies trong giai đoạn tham chiếu.
'''
a.write(DOCS/'README.md', readme.encode('utf-8'))
a.write(DOCS/'COMPARISON_MAP.md', mapping.encode('utf-8'))
a.jwrite(DOCS/'REFERENCE_CATALOG.json', {'classification':'UPSTREAM_OPEN_SOURCE_REFERENCE','sources':catalog})
a.write(REPORT/'03_COMPARISON_MAP.md', mapping.encode('utf-8'))
receipts=json.loads((REPORT/'raw/command_receipts.json').read_text())
assert len(receipts)==24 and all(r['exit_code']==0 for r in receipts)
for r in receipts:
    for field in ['stdout','stderr']:
        assert a.sha((ROOT/r[field+'_path']).read_bytes()) == r[field+'_sha256']
summary = '# TASK068 source acquisition report\n\nAll three pinned upstream Git sources acquired and every materialized tracked file matched the original Git blob. 2695 tracked files,79949717 bytes; no LFS pointers or submodules.24 actual Git commands exit0 with retained stdout/stderr/times. No build/runtime/pixel parity assertion.\n\nDiscovery index: Docs/Reconstruction/References/storytold/README.md. Sources sibling to SO45 evidence, explicit external-reference classification. LICENSE files retained. Actual executor CEO root lease1014; reviewers are real read-only collaboration agents, never attributed as download workers. No production/P0/ledger writes. Awaiting independent final review; no commit/push yet.\n'
a.write(REPORT/'01_MASTER_REPORT.md', summary.encode())
a.jwrite(REPORT/'04_INDEX_ARTIFACTS.json', {str(p.relative_to(ROOT)).replace('\\','/'):a.sha(p.read_bytes()) for p in DOCS.iterdir() if p.is_file()})
files={str(p.relative_to(REPORT)).replace('\\','/'):a.sha(p.read_bytes()) for p in REPORT.rglob('*') if p.is_file() and p.name not in ['COMPLETE.json','PROGRESS.json']}
a.jwrite(REPORT/'PROGRESS.json', {'schema_version':'2.1.2','task_id':'TASK_068','revision':1,'status':'REVIEW_CANDIDATE_AWAITING_CEO','milestone':'SOURCES_AND_COMPARISON_INDEX_FROZEN','updated_at':a.now(),'fencing_token':1014})
a.jwrite(REPORT/'COMPLETE.json', {'schema_version':'2.1.2','task_id':'TASK_068','revision':1,'status':'COMPLETE','standard_sha256':manifest['standard_sha256'],'files':files,'code_files':['scripts/task068_storytold_reference/acquire.py','scripts/task068_storytold_reference/finalize.py']})
print('TASK068 reference sources and discovery index frozen for independent review.')
