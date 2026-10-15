"""Independent source, Ghidra and manifest verification for TASK_239 R1."""
import hashlib
import json
from pathlib import Path

from capstone import Cs, CS_ARCH_ARM64, CS_MODE_ARM
from elftools.dwarf.callframe import FDE
from elftools.elf.elffile import ELFFile

R = Path(__file__).resolve().parents[3]
P = R / 'RULES/REPORT/TASK_239_REPORT_R1'
sha = lambda b: hashlib.sha256(b).hexdigest()
C = json.loads((P / 'COMPLETE.json').read_text(encoding='utf8'))
M = R / '.ai/ceo/reviews/TASK_239_internal_targets.json'
T = R / 'RULES/TASK/TASK_239_SO45_INTERNAL_CONTINUATION_ACTIVE.md'
manifest = json.loads(M.read_text(encoding='utf8'))
summary = json.loads((P / 'evidence_summary.json').read_text(encoding='utf8'))
project = json.loads((P / 'source_project_index.json').read_text(encoding='utf8'))
rows = json.loads((P / 'candidate_evidence.json').read_text(encoding='utf8'))
assert C['task_id'] == 'TASK_239' and C['revision'] == 1 and C['status'] == 'COMPLETE'
assert C['research_result'] == 'PARTIAL_STATIC_RESEARCH_TWO_TIMEOUTS'
assert C['fencing_token'] == 1278 and C['lease_id'] == 'LEASE-CEO-WORKER-TASK_239-R1'
assert sha(T.read_bytes()) == C['task_sha256']
assert sha(M.read_bytes()) == C['target_manifest_sha256'] == summary['target_manifest_sha256']
assert len(C['files']) == 119 and 'PROGRESS.json' not in C['files']
assert len(rows) == len(manifest['targets']) == 11
assert len(C['code_files']) == 8 and not C.get('scratch_files')
for rel, expected in C['files'].items():
    f = P / rel
    assert f.is_file() and sha(f.read_bytes()) == expected, rel
for rel, expected in C['code_files'].items():
    f = R / rel
    assert f.is_file() and sha(f.read_bytes()) == expected, rel
source = Path(project['source_path'])
data = source.read_bytes()
assert sha(data) == C['original_so_sha256'] == manifest['source_sha256'] == project['source_sha256']
with source.open('rb') as stream:
    elf = ELFFile(stream)
    fdes = {(x.header['initial_location'], x.header['address_range'])
            for x in elf.get_dwarf_info().EH_CFI_entries() if isinstance(x, FDE)}
    loads = [x for x in elf.iter_segments() if x['p_type'] == 'PT_LOAD']
dis = Cs(CS_ARCH_ARM64, CS_MODE_ARM)
source_bytes = source_words = c_like = raw_full = corrected = timeout = 0
for row, target in zip(rows, manifest['targets']):
    idx = row['global_zero_based_index']
    assert idx == target['global_index']
    va = int(target['elf_va'], 16)
    n = target['size_bytes']
    off = int(target['file_offset'], 16)
    assert row['elf_va'] == target['elf_va'] and row['size_bytes'] == n
    assert (va, n) in fdes
    assert any(seg['p_vaddr'] <= va and va+n <= seg['p_vaddr']+seg['p_filesz']
               and off == seg['p_offset']+va-seg['p_vaddr'] for seg in loads)
    body = data[off:off+n]
    assert sha(body) == target['body_sha256'] == row['source_body_sha256']
    assembly = json.loads((P / row['source_assembly']).read_text(encoding='utf8'))
    assert assembly['source_body_sha256'] == sha(body) and assembly['fde_exact_match']
    ins = list(dis.disasm(body, va))
    assert len(ins) == n//4 == target['instruction_slots'] == row['source_instruction_words_verified']
    assert len(assembly['instructions']) == len(ins)
    for observed, recorded in zip(ins, assembly['instructions']):
        assert observed.address == int(recorded['elf_va'], 16)
        assert observed.bytes.hex() == recorded['word_hex']
        assert f'{observed.mnemonic} {observed.op_str}'.strip() == recorded['assembly']
    raw = json.loads((P / row['raw_output']).read_text(encoding='utf8'))
    fresh = json.loads((P / row['fresh_output']).read_text(encoding='utf8'))
    for x in (raw, fresh):
        assert x['index'] == row['one_based_ghidra_row']
        assert x['elf_va'] == target['elf_va'] and x['size_bytes'] == n
        assert x['ghidra_memory_sha256'] == sha(body)
        assert x['instruction_slots'] == len(ins)
        assert x['fde_byte_membership_count'] <= n
        assert x['extra_body_address_count'] == 0 and x['other_function_byte_count'] == 0
    assert raw['fde_byte_membership_count'] == fresh['fde_byte_membership_count'] == row['raw_membership_bytes']
    raw_full += raw['fde_byte_membership_count'] == n
    if row['correction_output']:
        corr = json.loads((P / row['correction_output']).read_text(encoding='utf8'))
        assert corr['index'] == row['one_based_ghidra_row']
        assert corr['memory_sha256'] == sha(body)
        assert corr['corrected_function_fde_membership_count'] == n
        assert corr['memory_unchanged_after_rollback']
        # Ghidra's same-session function cache was not restored; the separately
        # reopened project must instead reproduce the pre-correction body.
        assert not corr['same_session_function_metadata_restored']
        assert corr['original_function_fde_membership_count'] == raw['fde_byte_membership_count']
        assert row['transient_full_fde_membership_bytes'] == n
        corrected += 1
        effective = corr
    else:
        assert row['transient_full_fde_membership_bytes'] is None
        effective = raw
    assert bool(effective['c_like_nonempty']) == row['effective_c_like_nonempty']
    if effective['c_like_nonempty']:
        assert effective['c_like_text'].strip()
        c_like += 1
    else:
        assert idx in (3134, 3285) and 'timeout' in row['decompile_error'].lower()
        timeout += 1
    source_bytes += n
    source_words += len(ins)
assert (source_bytes, source_words, raw_full, corrected, c_like, timeout) == (86800, 21700, 3, 8, 9, 2)
assert C['original_fde_candidate_bodies_verified'] == summary['targets_verified'] == 11
assert C['original_instruction_words_verified'] == summary['original_ARM64_words_verified'] == source_words
assert C['nonempty_c_like_outputs'] == summary['nonempty_c_like_outputs'] == c_like
assert C['timed_out_global_indices'] == summary['timed_out_global_indices'] == [3134, 3285]
assert summary['ordinary_provenance_recheck_count'] == 11
for i in range(1, 12):
    receipt = json.loads((P / f'ghidra_batch{i}_command.json').read_text(encoding='utf8'))
    fresh_receipt = json.loads((P / f'ghidra_fresh_batch{i}_command.json').read_text(encoding='utf8'))
    for x in (receipt, fresh_receipt):
        assert x['exit_code'] == 0 and x['max_cpu'] == 1 and x['max_heap'] == '1G'
        assert x.get('max_decompile_seconds_per_candidate', x.get('max_per_decompile_seconds')) == 15
retry = json.loads((P / 'ghidra_correction_retry_command.json').read_text(encoding='utf8'))
assert retry['exit_code'] == 0 and retry['max_cpu'] == 1 and retry['max_heap'] == '1G'
assert retry['project_metadata_unchanged']
assert sha((R / 'scripts/task_239_codex_internal/ExtractInternal239.java').read_bytes()) == receipt['script_sha256']
assert sha((R / 'scripts/task_239_codex_internal/RepairMembership239.java').read_bytes()) == retry['script_sha256']
failed = json.loads((P / 'ghidra_correction_command.json').read_text(encoding='utf8'))
assert failed['status'] == 'PARTIAL_OUTPUT' and failed['output_files'] == 0
assert summary['first_correction_attempt'] == 'FAILED_GUARD_NO_OUTPUT_PRESERVED'
report = (P / '01_MASTER_REPORT.md').read_text(encoding='utf8')
assert 'PARTIAL' in report and '3134' in report and '3285' in report
print(json.dumps({'task':'TASK_239','report_files':len(C['files']),'source_bodies':11,
                  'source_bytes':source_bytes,'source_words':source_words,
                  'raw_full':raw_full,'corrected_full':corrected,'c_like':c_like,'timeouts':timeout}))
