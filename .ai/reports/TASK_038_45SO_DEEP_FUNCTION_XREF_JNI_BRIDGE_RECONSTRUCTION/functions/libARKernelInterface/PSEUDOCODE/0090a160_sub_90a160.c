// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a160
// Recovered Name: sub_90a160
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a160 | Size: 148 bytes | SHA256: 564316e970a877a3c45a7f7f44467df705b0e62e77b886909a71263889e541fd
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_2"
//   "pNX"

void sub_90a160(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a160 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a164 */ str x19, [sp, #0x10];
    /* 0x90a168 */ mov x29, sp;
    /* 0x90a16c */ mov x19, x0;
    /* 0x90a170 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a178 */ ldur q0, [x19, #8];
    /* 0x90a17c */ adrp x8, #0x1078000;
    /* 0x90a180 */ add x8, x8, #0x7c0;
    /* 0x90a184 */ str x8, [x0];
    /* 0x90a188 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
