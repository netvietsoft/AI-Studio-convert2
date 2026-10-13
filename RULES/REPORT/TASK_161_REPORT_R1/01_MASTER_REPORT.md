# TASK_161 R1 - Manis and NPU adapter export map

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**.

## Observed

- `libManis.so` SHA-256 `19daf9b4b1718c843169d68391e99a27d10bd3cece52226c887c3ab9b93dddc2`: 287 defined nonzero `.dynsym` names, 266 distinct VAs; 266 source PT_LOAD body hashes, 266 Ghidra memory body hashes, 266 C-like bodies, 2/2 chunks, 266 fully listed bodies, 108 C-warning bodies. 27 spread ordinary records checked.
- `libmanis_npu_adapter.so` SHA-256 `99a9a4b161b9797d7cf621e93a51a7df408f80c84e652bbc6724eef7e71ca6f3`: 1,003 defined nonzero `.dynsym` names, 996 distinct VAs; 996 source PT_LOAD body hashes, 996 Ghidra memory body hashes, 996 C-like bodies, 4/4 chunks, 541 fully listed bodies, 546 C-warning bodies. 100 spread ordinary records checked.

## Limits

Export C-like text and aligned assembly are static research evidence. Non-exported functions, linked providers, model data, ABI semantics and real device outputs remain unverified. Decompiler warnings and partial listings are enumerated in each worker_source_verification.json. No product Phase PASS, V4/P7 authorization, self-review, commit or push.
