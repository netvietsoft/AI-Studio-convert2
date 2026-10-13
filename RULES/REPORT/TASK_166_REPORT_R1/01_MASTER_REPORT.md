# TASK_166 R1 - AI model, detection and hiai export map

Status: **BOUNDED_RESEARCH_CANDIDATE awaiting independent CEO review**.

## Observed

- `libAIModelKit.so` SHA-256 `96eb16089da9b1b797928a73ec4b4ddd27c43bc557940c96ca167cf657a89b9c`: 144 defined nonzero `.dynsym` names, 130 distinct VAs; 130 source PT_LOAD body hashes, 130 Ghidra memory body hashes, 130 C-like bodies, 1/1 chunks, 109 fully listed bodies, 33 C-warning bodies. 13 spread ordinary records checked.
- `libaidetectionplugin.so` SHA-256 `910ef898f457cac694080829b8f7b219ae6cc696f5adebe90beca9a70c0deda8`: 477 defined nonzero `.dynsym` names, 436 distinct VAs; 436 source PT_LOAD body hashes, 436 Ghidra memory body hashes, 436 C-like bodies, 2/2 chunks, 318 fully listed bodies, 196 C-warning bodies. 44 spread ordinary records checked.
- `libhiai.so` SHA-256 `30a096c17346403d98a32a1a4d0762fa8e220f6c40e65aec9460cdfd6c7418ee`: 366 defined nonzero `.dynsym` names, 343 distinct VAs; 343 source PT_LOAD body hashes, 343 Ghidra memory body hashes, 343 C-like bodies, 2/2 chunks, 343 fully listed bodies, 184 C-warning bodies. 35 spread ordinary records checked.

## Limits

Export C-like text and aligned assembly are static research evidence. Non-exported functions, linked providers, model data, ABI semantics and real device outputs remain unverified. Decompiler warnings and partial listings are enumerated in each worker_source_verification.json. No product Phase PASS, V4/P7 authorization, self-review, commit or push.
