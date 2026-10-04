// Library: libarkernel3.so
// Function ID: libarkernel3::0xadac8c
// Recovered Name: sub_adac8c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xadac8c | Size: 2568 bytes | SHA256: 0f2c992b5b4177bb685b626a2f2c35078cae65cb01c87fbbc81db6fe4a9a4f21
// Callers: 0 | Callees: 32 | Imports: 4

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, wgpuTextureGetFormat
// Strings referenced:
//   ">&"
//   "GaussianGlowLayer_blend"
//   "GaussianGlowLayer_blur1_x"
//   "GaussianGlowLayer_blur1_y"
//   "GaussianGlowLayer_blur2_x"

void sub_adac8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 642 instructions
    /* 0xadac8c */ stp x29, x30, [sp, #0x40];
    /* 0xadac90 */ stp x28, x27, [sp, #0x50];
    /* 0xadac94 */ stp x26, x25, [sp, #0x60];
    /* 0xadac98 */ stp x24, x23, [sp, #0x70];
    /* 0xadac9c */ stp x22, x21, [sp, #0x80];
    /* 0xadaca0 */ stp x20, x19, [sp, #0x90];
    /* 0xadaca4 */ add x29, sp, #0x40;
    /* 0xadaca8 */ sub sp, sp, #0x510;
    /* 0xadacac */ mrs x20, tpidr_el0;
    /* 0xadacb0 */ mov x24, x0;
    /* 0xadacb4 */ ldr x8, [x20, #0x28];
    sub_a6a3d8();
    sub_a6a3d8();
    sub_b2a63c();
    sub_b2a644();
    sub_b2a63c();
    sub_b2a644();
    sub_a7fc40();
    sub_5aa23c();
    sub_a7fc40();
    sub_5aa23c();
    sub_aa29c8();
    sub_a8ad80();
    sub_aa29c8();
    sub_a8ad80();
    sub_a02a88();
    sub_5b92c8();
    sub_5b92c8();
    sub_5b92c8();
    sub_5b92c8();
    sub_5b92c8();
    _Znwm();
    sub_a02ca0();
    _Znwm();
    sub_a02ca0();
    sub_a02ea0();
    sub_a02e88();
    sub_79aa8c();
    _ZdlPv();
    _ZdlPv();
    sub_a02bec();
    sub_b02560();
    sub_9fdf90();
    sub_6981fc();
    sub_5b9390();
    wgpuTextureGetFormat();
    sub_a02ea8();
    sub_9fdf90();
    sub_6981fc();
    sub_5b9390();
    sub_a02ea8();
    sub_9fdf90();
    sub_6981fc();
    sub_5b9390();
    wgpuTextureGetFormat();
    sub_a02ea8();
    sub_9fdf90();
    sub_6981fc();
    sub_5b9390();
    wgpuTextureGetFormat();
    sub_a02ea8();
    sub_b037f4();
    sub_aee818();
    sub_aee8f4();
    sub_5a3d24();
    sub_5a3d24();
    sub_aa29c8();
    sub_a8ad80();
    sub_aa29c8();
    sub_a8ad80();
    sub_9fdf90();
    sub_a02a88();
    sub_a69d40();
    sub_6981fc();
    sub_6981fc();
    sub_adb694();
    sub_adb694();
    sub_5b92c8();
    sub_aa2af4();
    sub_aa5b4c();
    sub_5b930c();
    _Znwm();
    sub_a02ca0();
    _Znwm();
    sub_a02ca0();
    sub_a02ea0();
    sub_a02e88();
    sub_a02e80();
    sub_a02ea8();
    _ZdlPv();
    _ZdlPv();
    sub_a02bec();
    sub_5ab304();
    sub_5ab304();
    sub_a02bec();
    return x0;
    sub_a6a3d8();
    sub_a6a3d8();
    _ZdlPv();
    sub_a02bec();
    _ZdlPv();
    _ZdlPv();
    sub_562d14();
    sub_562d14();
    sub_a02bec();
    sub_5ab304();
    sub_5ab304();
    sub_106b814();
    __stack_chk_fail();
}
