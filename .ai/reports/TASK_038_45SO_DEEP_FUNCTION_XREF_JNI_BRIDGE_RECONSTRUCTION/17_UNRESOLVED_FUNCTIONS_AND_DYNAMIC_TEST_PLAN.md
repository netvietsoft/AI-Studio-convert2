# TASK_038 — UNRESOLVED FUNCTIONS & DYNAMIC TEST PLAN

1. **libmfxkit.so Corrupted Section Headers:** Binary header `e_shoff` points past EOF. Handled via program header PT_LOAD fallback.
2. **Dynamic RegisterNatives Runtime Plan:** For obfuscated tables, instrument `libart.so!RegisterNatives` on Samsung Galaxy A07 to log runtime class/method pairs dynamically.
