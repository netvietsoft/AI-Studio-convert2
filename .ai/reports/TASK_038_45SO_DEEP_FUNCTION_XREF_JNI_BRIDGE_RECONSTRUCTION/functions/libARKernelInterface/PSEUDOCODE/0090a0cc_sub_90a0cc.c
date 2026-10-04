// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a0cc
// Recovered Name: sub_90a0cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a0cc | Size: 148 bytes | SHA256: 2dec0196a1f5db8af229146f1fb72791d577843f06b78b5e5c7d7df5670c4ba6
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_1"
//   "pNX"

void sub_90a0cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a0cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a0d0 */ str x19, [sp, #0x10];
    /* 0x90a0d4 */ mov x29, sp;
    /* 0x90a0d8 */ mov x19, x0;
    /* 0x90a0dc */ mov w0, #0x18;
    _Znwm();
    /* 0x90a0e4 */ ldur q0, [x19, #8];
    /* 0x90a0e8 */ adrp x8, #0x1078000;
    /* 0x90a0ec */ add x8, x8, #0x740;
    /* 0x90a0f0 */ str x8, [x0];
    /* 0x90a0f4 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
