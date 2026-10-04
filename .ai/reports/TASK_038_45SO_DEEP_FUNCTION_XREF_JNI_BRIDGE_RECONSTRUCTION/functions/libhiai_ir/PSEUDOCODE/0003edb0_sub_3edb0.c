// Library: libhiai_ir.so
// Function ID: libhiai_ir::0x3edb0
// Recovered Name: sub_3edb0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3edb0 | Size: 136 bytes | SHA256: 28b2411c922a6e470cf0c78bc76af34ae69a42808902543c994b2e57143e91f4
// Callers: 136 | Callees: 1 | Imports: 3

// Calls external APIs: _Znwm, memmove, strlen

void sub_3edb0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 34 instructions
    /* 0x3edb0 */ str x30, [sp, #-0x30]!;
    /* 0x3edb4 */ stp x22, x21, [sp, #0x10];
    /* 0x3edb8 */ stp x20, x19, [sp, #0x20];
    /* 0x3edbc */ mov x19, x0;
    /* 0x3edc0 */ mov x0, x1;
    /* 0x3edc4 */ mov x21, x1;
    strlen();
    /* 0x3edcc */ cmn x0, #0x10;
    /* 0x3edd0 */ b.hs #0x3ee30;
    /* 0x3edd4 */ mov x20, x0;
    /* 0x3edd8 */ cmp x0, #0x17;
    _Znwm();
    memmove();
    return x0;
    sub_42a8c();
}
