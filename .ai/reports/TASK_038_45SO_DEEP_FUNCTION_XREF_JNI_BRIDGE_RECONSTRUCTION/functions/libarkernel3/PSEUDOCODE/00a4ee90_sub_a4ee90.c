// Library: libarkernel3.so
// Function ID: libarkernel3::0xa4ee90
// Recovered Name: sub_a4ee90
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa4ee90 | Size: 1260 bytes | SHA256: eee6c746b8789e1dcb5db03129f069cf626f42719ad98759e95af025d3dc4a24
// Callers: 0 | Callees: 15 | Imports: 5

// Calls external APIs: _ZN5image11DetailImageIhEC2Ejjj, _ZdaPv, _Znam, __stack_chk_fail, memset
// Strings referenced:
//   "getCropSegmentMask"
//   "mtlabar3"

void sub_a4ee90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 315 instructions
    /* 0xa4ee90 */ stp x29, x30, [sp, #0xc0];
    /* 0xa4ee94 */ stp x28, x27, [sp, #0xd0];
    /* 0xa4ee98 */ stp x26, x25, [sp, #0xe0];
    /* 0xa4ee9c */ stp x24, x23, [sp, #0xf0];
    /* 0xa4eea0 */ stp x22, x21, [sp, #0x100];
    /* 0xa4eea4 */ stp x20, x19, [sp, #0x110];
    /* 0xa4eea8 */ add x29, sp, #0xc0;
    /* 0xa4eeac */ str x7, [sp, #0x30];
    /* 0xa4eeb0 */ mrs x20, tpidr_el0;
    /* 0xa4eeb4 */ mov x25, x0;
    /* 0xa4eeb8 */ mov x0, x8;
    sub_d1a6ac();
    sub_a434b4();
    sub_8a2204();
    sub_d1a5a4();
    sub_a434a8();
    sub_a434a8();
    sub_cccfe0();
    _Znam();
    memset();
    sub_d1a554();
    sub_d1a54c();
    sub_d1a588();
    sub_d1a624();
    _ZN5image11DetailImageIhEC2Ejjj();
    sub_d1a4f0();
    sub_d1a6fc();
    sub_d1a564();
    sub_b9acb8();
    _ZN5image11DetailImageIhEC2Ejjj();
    sub_d1a4f0();
    sub_d1a6fc();
    sub_d1a564();
    memset();
    _ZdaPv();
    return x0;
    sub_d1a6fc();
    sub_106b814();
    __stack_chk_fail();
}
