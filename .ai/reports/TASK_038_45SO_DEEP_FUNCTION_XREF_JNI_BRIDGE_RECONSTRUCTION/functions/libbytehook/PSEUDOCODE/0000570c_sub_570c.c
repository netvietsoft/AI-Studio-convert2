// Library: libbytehook.so
// Function ID: libbytehook::0x570c
// Recovered Name: sub_570c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x570c | Size: 108 bytes | SHA256: fc61cc359c1ffcf556364f2954cd9c566d9886fa9dbe8613d1113893621e3faa
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: dlclose, dlopen, dlsym
// Strings referenced:
//   "__cfi_slowpath"
//   "__cfi_slowpath_diag"
//   "libdl.so"

void sub_570c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0x570c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5710 */ stp x20, x19, [sp, #0x10];
    /* 0x5714 */ mov x29, sp;
    /* 0x5718 */ adrp x0, #0x2000;
    /* 0x571c */ add x0, x0, #0x350;
    /* 0x5720 */ mov w1, #2;
    dlopen();
    /* 0x5728 */ cbz x0, #0x576c;
    /* 0x572c */ adrp x1, #0x2000;
    /* 0x5730 */ add x1, x1, #0x5c6;
    /* 0x5734 */ mov x19, x0;
    dlsym();
    dlsym();
    return x0;
}
