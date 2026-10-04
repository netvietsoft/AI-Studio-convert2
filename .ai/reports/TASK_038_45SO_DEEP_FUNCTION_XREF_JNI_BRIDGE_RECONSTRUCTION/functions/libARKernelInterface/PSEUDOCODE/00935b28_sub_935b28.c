// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x935b28
// Recovered Name: sub_935b28
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x935b28 | Size: 144 bytes | SHA256: ff0a78f3a095d39543d7240be6284c91b74c699b996db90c2e7a72e4140ee946
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm
// Strings referenced:
//   "ZN8arkernel30CoreSegmentAnimatedPartControl17PrepareToolsParamEvE3$_0"
//   "pNX"

void sub_935b28(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x935b28 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x935b2c */ str x19, [sp, #0x10];
    /* 0x935b30 */ mov x29, sp;
    /* 0x935b34 */ mov x19, x0;
    /* 0x935b38 */ mov w0, #0x18;
    _Znwm();
    /* 0x935b40 */ ldur q0, [x19, #8];
    /* 0x935b44 */ adrp x8, #0x107a000;
    /* 0x935b48 */ add x8, x8, #0x958;
    /* 0x935b4c */ str x8, [x0];
    /* 0x935b50 */ stur q0, [x0, #8];
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
