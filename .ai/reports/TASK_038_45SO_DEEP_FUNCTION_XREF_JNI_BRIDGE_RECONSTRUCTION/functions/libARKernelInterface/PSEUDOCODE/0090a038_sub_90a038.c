// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a038
// Recovered Name: sub_90a038
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a038 | Size: 148 bytes | SHA256: 43b5289e6ba9c4c1d19f41f4f633635e0d10c9f5b50a5fc4dbf4991b46df2d2c
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_0"
//   "pNX"

void sub_90a038(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a038 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a03c */ str x19, [sp, #0x10];
    /* 0x90a040 */ mov x29, sp;
    /* 0x90a044 */ mov x19, x0;
    /* 0x90a048 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a050 */ ldur q0, [x19, #8];
    /* 0x90a054 */ adrp x8, #0x1078000;
    /* 0x90a058 */ add x8, x8, #0x6c0;
    /* 0x90a05c */ str x8, [x0];
    /* 0x90a060 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
