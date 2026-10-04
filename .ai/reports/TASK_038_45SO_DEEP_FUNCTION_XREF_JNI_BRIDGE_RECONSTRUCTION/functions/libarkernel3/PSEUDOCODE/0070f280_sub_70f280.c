// Library: libarkernel3.so
// Function ID: libarkernel3::0x70f280
// Recovered Name: sub_70f280
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x70f280 | Size: 1080 bytes | SHA256: 98b1538d714006f59dca8f61933db6985996517c0847c25085473ab7128a7b11
// Callers: 0 | Callees: 14 | Imports: 5

// Calls external APIs: __stack_chk_fail, wgpuBufferGetSize, wgpuTextureCreateView, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "a_position"
//   "a_texcoord"
//   "s_texture"
//   "u_blurSize"
//   "u_mvpMatrix"

void sub_70f280(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 270 instructions
    /* 0x70f280 */ stp x29, x30, [sp, #0x20];
    /* 0x70f284 */ stp x28, x27, [sp, #0x30];
    /* 0x70f288 */ stp x26, x25, [sp, #0x40];
    /* 0x70f28c */ stp x24, x23, [sp, #0x50];
    /* 0x70f290 */ stp x22, x21, [sp, #0x60];
    /* 0x70f294 */ stp x20, x19, [sp, #0x70];
    /* 0x70f298 */ add x29, sp, #0x20;
    /* 0x70f29c */ sub sp, sp, #0x2c0;
    /* 0x70f2a0 */ mrs x27, tpidr_el0;
    /* 0x70f2a4 */ mov x23, x0;
    /* 0x70f2a8 */ mov x0, x2;
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_a7fc40();
    sub_5aa23c();
    wgpuTextureCreateView();
    sub_9fdf90();
    sub_6f1fc0();
    sub_6f24b4();
    sub_6f22f0();
    sub_6f22f0();
    wgpuBufferGetSize();
    sub_6f215c();
    wgpuBufferGetSize();
    sub_6f215c();
    wgpuBufferGetSize();
    sub_6f2660();
    sub_6f2650();
    sub_6f2674();
    sub_9fdf90();
    sub_6f1fc0();
    sub_6f24b4();
    sub_6f22f0();
    sub_6f22f0();
    wgpuBufferGetSize();
    sub_6f215c();
    wgpuBufferGetSize();
    sub_6f215c();
    wgpuBufferGetSize();
    sub_6f2660();
    sub_6f2650();
    sub_6f2674();
    sub_6f20c0();
    sub_6f20c0();
    sub_5ab304();
    return x0;
    sub_562d14();
    sub_6f20c0();
    sub_6f20c0();
    sub_5ab304();
    sub_106b814();
    __stack_chk_fail();
}
