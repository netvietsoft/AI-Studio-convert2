// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a288
// Recovered Name: sub_90a288
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a288 | Size: 148 bytes | SHA256: c21d60410eb03616711cb97f66de8504ff619fdebe494159867f45a921e07aa1
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_4"
//   "pNX"

void sub_90a288(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a288 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a28c */ str x19, [sp, #0x10];
    /* 0x90a290 */ mov x29, sp;
    /* 0x90a294 */ mov x19, x0;
    /* 0x90a298 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a2a0 */ ldur q0, [x19, #8];
    /* 0x90a2a4 */ adrp x8, #0x1078000;
    /* 0x90a2a8 */ add x8, x8, #0x8c0;
    /* 0x90a2ac */ str x8, [x0];
    /* 0x90a2b0 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
