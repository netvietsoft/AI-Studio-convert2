// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xb02f7c
// Recovered Name: sub_b02f7c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb02f7c | Size: 2140 bytes | SHA256: c3b1236d0ec53286d2330d33e3c0c4ec12cecfa7064e51c457ba74fcc22c5ebd
// Callers: 0 | Callees: 8 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "BlurRadius"
//   "Expansion"
//   "FacemeshType"
//   "LocateMethod"
//   "LocationPointIndex"

void sub_b02f7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 535 instructions
    /* 0xb02f7c */ stp x29, x30, [sp, #0x88];
    /* 0xb02f80 */ str x27, [sp, #0x98];
    /* 0xb02f84 */ stp x26, x25, [sp, #0xa0];
    /* 0xb02f88 */ stp x24, x23, [sp, #0xb0];
    /* 0xb02f8c */ stp x22, x21, [sp, #0xc0];
    /* 0xb02f90 */ stp x20, x19, [sp, #0xd0];
    /* 0xb02f94 */ add x29, sp, #0x88;
    /* 0xb02f98 */ mrs x23, tpidr_el0;
    /* 0xb02f9c */ mov x21, x1;
    /* 0xb02fa0 */ mov x20, x0;
    /* 0xb02fa4 */ ldr x8, [x23, #0x28];
    sub_886528();
    sub_5b7fa8();
    sub_b03b6c();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_5a8d0c();
    sub_765510();
    sub_5b7fa8();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    sub_59e3a4();
    sub_5a8d0c();
    sub_765510();
    sub_5a8d1c();
    sub_59e3a4();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5cb124();
    _ZdlPv();
    sub_5a8d0c();
    sub_765510();
    sub_5cb124();
    _ZdlPv();
    sub_59e3a4();
    return x0;
    __stack_chk_fail();
}
