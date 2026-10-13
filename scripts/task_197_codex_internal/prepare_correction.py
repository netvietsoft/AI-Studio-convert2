"""Pin only observed, other-function-free Ghidra body gaps for transient replay."""
from __future__ import annotations

import json

from common import REPORT, SCRATCH, atomic_bytes, check_lease, now, write_json


def main() -> None:
    check_lease()
    index = json.loads((REPORT / 'source_project_index.json').read_text(encoding='utf-8'))
    rows = []
    for ordinal, source in enumerate(index['selected_candidate_rows']):
        number = source['index']
        batch = 1 if ordinal < 31 else 2
        path = REPORT / f'ghidra_raw_batch{batch}' / f"{number:03d}_{int(source['elf_va'], 16):x}.json"
        raw = json.loads(path.read_text(encoding='utf-8'))
        if (source['other_fde_overlap'] or source['export_body_overlap'] or
                raw['other_function_byte_count'] != 0 or
                raw['extra_body_address_count'] != 0):
            raise RuntimeError(f'candidate {number} has ambiguous/other owner overlap')
        if raw['fde_byte_membership_count'] < source['size_bytes']:
            if (not raw['existing_exact_function_start'] or
                    raw['existing_function_contains_nonstart'] or
                    raw['temporary_function_created_and_rolled_back'] or
                    raw['missing_analyzed_instruction_count'] <= 0):
                raise RuntimeError(f'candidate {number} gap is not safe for transient correction')
            rows.append(source)
    expected = [285, 299, 300, 305, 306, 307]
    if [r['index'] for r in rows] != expected:
        raise RuntimeError('observed correction set changed')
    path = SCRATCH / 'correction_targets.tsv'
    atomic_bytes(path, ''.join(
        f"{r['index']}\t{r['elf_va']}\t{r['size_bytes']}\t{r['source_body_sha256']}\n"
        for r in rows).encode('ascii'))
    write_json(REPORT / 'correction_preflight.json', {
        'task_id': 'TASK_197', 'revision': 1, 'generated_at': now(),
        'target_indices': expected, 'source_overlap_fde': 0,
        'source_overlap_export': 0, 'other_function_byte_overlap': 0,
        'target_count': len(rows),
        'reason': 'Pre-existing same-entry function metadata omits original FDE bytes; '
                  'transient reconstruction is rolled back in a read-only copied project.'})
    print(json.dumps({'correction_candidates': expected, 'count': len(rows)}))


if __name__ == '__main__':
    main()

