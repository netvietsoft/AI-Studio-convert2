// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x897250
// Recovered Name: sub_897250
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x897250 | Size: 256 bytes | SHA256: 21e5701d96d8f368027041cda78188d807f864a5241b424b8ab8a9b9a02327b3
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "ZN8arkernel19CoreHairPartControl7PrepareEvE3$_1"

void sub_897250(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x897250 */ stp x29, x30, [sp, #0x20];
    /* 0x897254 */ stp x22, x21, [sp, #0x30];
    /* 0x897258 */ stp x20, x19, [sp, #0x40];
    /* 0x89725c */ add x29, sp, #0x20;
    /* 0x897260 */ mrs x20, tpidr_el0;
    /* 0x897264 */ ldr x8, [x20, #0x28];
    /* 0x897268 */ stur x8, [x29, #-8];
    /* 0x89726c */ ldr x21, [x0, #8];
    /* 0x897270 */ ldr x8, [x21, #0x20];
    /* 0x897274 */ cbz x8, #0x897300;
    /* 0x897278 */ mov x19, x0;
    _ZdlPv();
    return x0;
    __stack_chk_fail();
    return x0;
    return x0;
}
