// Library: libarkernel3.so
// Function ID: libarkernel3::0x9ee624
// Recovered Name: sub_9ee624
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ee624 | Size: 440 bytes | SHA256: 3773a2745972178bfbcccf1e459be04e86327316633c1d725a0dbf48499a80a0
// Callers: 1 | Callees: 16 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, wgpuTextureCreateView, wgpuTextureGetFormat, wgpuTextureViewRelease
// Strings referenced:
//   "segment_thresholding"

void sub_9ee624(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x9ee624 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x9ee628 */ stp x28, x25, [sp, #0x10];
    /* 0x9ee62c */ stp x24, x23, [sp, #0x20];
    /* 0x9ee630 */ stp x22, x21, [sp, #0x30];
    /* 0x9ee634 */ stp x20, x19, [sp, #0x40];
    /* 0x9ee638 */ mov x29, sp;
    /* 0x9ee63c */ sub sp, sp, #0x1c0;
    /* 0x9ee640 */ mrs x25, tpidr_el0;
    /* 0x9ee644 */ mov x23, x3;
    /* 0x9ee648 */ mov x22, x2;
    /* 0x9ee64c */ ldr x8, [x25, #0x28];
    wgpuTextureCreateView();
    sub_9fe4f4();
    sub_a00a24();
    sub_a00f28();
    sub_a7fc40();
    sub_a82200();
    sub_a01144();
    sub_a01274();
    sub_a0127c();
    sub_a01284();
    sub_a0128c();
    sub_a012ac();
    wgpuTextureGetFormat();
    sub_a0126c();
    _Znwm();
    sub_a00d3c();
    sub_a0179c();
    _ZdlPv();
    sub_a00c0c();
    wgpuTextureViewRelease();
    return x0;
    __stack_chk_fail();
    sub_562d14();
    sub_562d14();
}
