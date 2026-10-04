// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7df0
// Recovered Name: sub_7df0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7df0 | Size: 188 bytes | SHA256: d0dd4812050587ef5c47473d55ffd9d83244572cafbed10dc44d0c85408fdc5b
// Callers: 8 | Callees: 1 | Imports: 3

// Calls external APIs: _Znwm, memmove, strlen

void sub_7df0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x7df0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x7df4 */ stp x22, x21, [sp, #0x10];
    /* 0x7df8 */ stp x20, x19, [sp, #0x20];
    /* 0x7dfc */ mov x29, sp;
    /* 0x7e00 */ mov x19, x0;
    /* 0x7e04 */ mov x0, x1;
    /* 0x7e08 */ mov x21, x1;
    strlen();
    /* 0x7e10 */ cmn x0, #0x10;
    /* 0x7e14 */ b.hs #0x7e74;
    /* 0x7e18 */ mov x20, x0;
    _Znwm();
    memmove();
    return x0;
    sub_7eac();
    return x0;
}
