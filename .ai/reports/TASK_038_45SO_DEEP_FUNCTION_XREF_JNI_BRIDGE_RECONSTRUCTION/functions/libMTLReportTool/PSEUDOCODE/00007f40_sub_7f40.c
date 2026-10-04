// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7f40
// Recovered Name: sub_7f40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7f40 | Size: 120 bytes | SHA256: 890de58189afbfeea565782e36bfc55dd8ce3b47fc3142d1b678e5e693cb44dc
// Callers: 4 | Callees: 1 | Imports: 2

// Calls external APIs: _Znwm, memmove

void sub_7f40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x7f40 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x7f44 */ stp x22, x21, [sp, #0x10];
    /* 0x7f48 */ stp x20, x19, [sp, #0x20];
    /* 0x7f4c */ mov x29, sp;
    /* 0x7f50 */ mov x20, x2;
    /* 0x7f54 */ mov x19, x1;
    /* 0x7f58 */ cmp x2, #0x16;
    /* 0x7f5c */ mov x21, x0;
    /* 0x7f60 */ b.hi #0x7f70;
    /* 0x7f64 */ lsl w8, w20, #1;
    /* 0x7f68 */ strb w8, [x21], #1;
    _Znwm();
    sub_7eac();
}
