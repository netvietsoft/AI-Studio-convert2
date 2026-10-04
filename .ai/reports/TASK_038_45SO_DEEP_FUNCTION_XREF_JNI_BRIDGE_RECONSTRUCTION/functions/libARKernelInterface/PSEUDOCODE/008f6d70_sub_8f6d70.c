// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8f6d70
// Recovered Name: sub_8f6d70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8f6d70 | Size: 1560 bytes | SHA256: 4f24e1325ad5e30b05b88ed7520ed17f64ea0987c2ef5f0a093caa98283c11ae
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Adaptive"
//   "AdaptiveScale"
//   "BgOptimize"
//   "Debug"
//   "Degree"

void sub_8f6d70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 390 instructions
    /* 0x8f6d70 */ stp x29, x30, [sp, #0x20];
    /* 0x8f6d74 */ str x23, [sp, #0x30];
    /* 0x8f6d78 */ stp x22, x21, [sp, #0x40];
    /* 0x8f6d7c */ stp x20, x19, [sp, #0x50];
    /* 0x8f6d80 */ add x29, sp, #0x20;
    /* 0x8f6d84 */ mrs x23, tpidr_el0;
    /* 0x8f6d88 */ mov x21, x1;
    /* 0x8f6d8c */ mov x19, x0;
    /* 0x8f6d90 */ ldr x8, [x23, #0x28];
    /* 0x8f6d94 */ stur x8, [x29, #-8];
    sub_61bfa0();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5a8d1c();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8d1c();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8de8();
    sub_5a8da0();
    sub_5a8de8();
    return x0;
    __stack_chk_fail();
    return x0;
}
