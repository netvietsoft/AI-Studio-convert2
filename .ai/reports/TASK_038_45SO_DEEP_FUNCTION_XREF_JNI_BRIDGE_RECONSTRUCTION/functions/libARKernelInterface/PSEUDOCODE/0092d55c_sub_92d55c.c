// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x92d55c
// Recovered Name: sub_92d55c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x92d55c | Size: 3828 bytes | SHA256: 10956130a8d66bd7a65c68009425a02298fb45f2c79ad9bb8d69ac3d94692076
// Callers: 0 | Callees: 6 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "BPRequire"
//   "EnableAIKit"
//   "EnableARImageTracking"
//   "EnableARInstantPlacement"
//   "EnableARPlane"

void sub_92d55c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 957 instructions
    /* 0x92d55c */ stp x29, x30, [sp, #0xc0];
    /* 0x92d560 */ stp x28, x27, [sp, #0xd0];
    /* 0x92d564 */ stp x26, x25, [sp, #0xe0];
    /* 0x92d568 */ stp x24, x23, [sp, #0xf0];
    /* 0x92d56c */ stp x22, x21, [sp, #0x100];
    /* 0x92d570 */ stp x20, x19, [sp, #0x110];
    /* 0x92d574 */ add x29, sp, #0xc0;
    /* 0x92d578 */ mrs x24, tpidr_el0;
    /* 0x92d57c */ mov x19, x0;
    /* 0x92d580 */ mov x20, x1;
    /* 0x92d584 */ ldr x8, [x24, #0x28];
    sub_58f19c();
    _ZdlPv();
    sub_92ea50();
    sub_59c57c();
    _ZdlPv();
    sub_59c57c();
    _ZdlPv();
    sub_5c09e0();
    _ZdlPv();
    sub_5a09f4();
    _ZdlPv();
    sub_61e868();
    _ZdlPv();
}
