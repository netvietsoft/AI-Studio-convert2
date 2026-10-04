// Library: libMTLReportTool.so
// Function ID: libMTLReportTool::0x7f10
// Recovered Name: sub_7f10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7f10 | Size: 48 bytes | SHA256: 5d993be529005c1317241743ddc4d9ccc44b7f9a71d818e40a9fc67e45ca6418
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt11logic_errorC2EPKc

void sub_7f10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x7f10 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x7f14 */ str x19, [sp, #0x10];
    /* 0x7f18 */ mov x29, sp;
    /* 0x7f1c */ mov x19, x0;
    _ZNSt11logic_errorC2EPKc();
    /* 0x7f24 */ adrp x8, #0x15000;
    /* 0x7f28 */ ldr x8, [x8, #0x190];
    /* 0x7f2c */ add x8, x8, #0x10;
    /* 0x7f30 */ str x8, [x19];
    /* 0x7f34 */ ldr x19, [sp, #0x10];
    /* 0x7f38 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
