// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a31c
// Recovered Name: sub_90a31c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a31c | Size: 144 bytes | SHA256: 696adbe330a78a6602e7dfed650a115373e8571e6e713f4d76a9e51b48c75d67
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_5"
//   "pNX"

void sub_90a31c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x90a31c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a320 */ str x19, [sp, #0x10];
    /* 0x90a324 */ mov x29, sp;
    /* 0x90a328 */ mov x19, x0;
    /* 0x90a32c */ mov w0, #0x18;
    _Znwm();
    /* 0x90a334 */ ldur q0, [x19, #8];
    /* 0x90a338 */ adrp x8, #0x1078000;
    /* 0x90a33c */ add x8, x8, #0x940;
    /* 0x90a340 */ str x8, [x0];
    /* 0x90a344 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
