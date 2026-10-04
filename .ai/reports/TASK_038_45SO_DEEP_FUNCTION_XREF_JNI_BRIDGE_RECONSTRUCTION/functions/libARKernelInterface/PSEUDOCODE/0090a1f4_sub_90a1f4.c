// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a1f4
// Recovered Name: sub_90a1f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a1f4 | Size: 148 bytes | SHA256: e700f9b7e5c22a984de18735573c6219cc06a36ecb41db77354a105fb5073703
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_3"
//   "pNX"

void sub_90a1f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a1f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a1f8 */ str x19, [sp, #0x10];
    /* 0x90a1fc */ mov x29, sp;
    /* 0x90a200 */ mov x19, x0;
    /* 0x90a204 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a20c */ ldur q0, [x19, #8];
    /* 0x90a210 */ adrp x8, #0x1078000;
    /* 0x90a214 */ add x8, x8, #0x840;
    /* 0x90a218 */ str x8, [x0];
    /* 0x90a21c */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
