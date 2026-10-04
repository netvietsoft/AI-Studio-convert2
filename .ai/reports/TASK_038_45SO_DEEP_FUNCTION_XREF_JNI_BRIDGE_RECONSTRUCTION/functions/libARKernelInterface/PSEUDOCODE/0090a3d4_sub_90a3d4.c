// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x90a3d4
// Recovered Name: sub_90a3d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90a3d4 | Size: 148 bytes | SHA256: d0a85a95a25f4476694308221b22b994a62b92e0646aad7f12218cddf4814b19
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel23CoreHairSoftPartControl17PrepareToolsParamEvE3$_6"
//   "pNX"

void sub_90a3d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x90a3d4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x90a3d8 */ str x19, [sp, #0x10];
    /* 0x90a3dc */ mov x29, sp;
    /* 0x90a3e0 */ mov x19, x0;
    /* 0x90a3e4 */ mov w0, #0x18;
    _Znwm();
    /* 0x90a3ec */ ldur q0, [x19, #8];
    /* 0x90a3f0 */ adrp x8, #0x1078000;
    /* 0x90a3f4 */ add x8, x8, #0xa40;
    /* 0x90a3f8 */ str x8, [x0];
    /* 0x90a3fc */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
