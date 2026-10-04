// Library: libarkernel3.so
// Function ID: libarkernel3::0x9db3ec
// Recovered Name: sub_9db3ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9db3ec | Size: 1932 bytes | SHA256: d576d699b24603f176305e3566185430a1669666b3d50193986833c599f360fd
// Callers: 0 | Callees: 29 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuTextureGetFormat
// Strings referenced:
//   "u_alpha"
//   "u_grayImage"
//   "u_mvpMatrix"
//   "u_segmentTexture"
//   "u_srcTexture"

void sub_9db3ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 483 instructions
    /* 0x9db3ec */ stp x29, x30, [sp, #0x40];
    /* 0x9db3f0 */ stp x28, x27, [sp, #0x50];
    /* 0x9db3f4 */ stp x26, x25, [sp, #0x60];
    /* 0x9db3f8 */ stp x24, x23, [sp, #0x70];
    /* 0x9db3fc */ stp x22, x21, [sp, #0x80];
    /* 0x9db400 */ stp x20, x19, [sp, #0x90];
    /* 0x9db404 */ add x29, sp, #0x40;
    /* 0x9db408 */ sub sp, sp, #0x3a0;
    /* 0x9db40c */ mrs x8, tpidr_el0;
    /* 0x9db410 */ mov x20, x0;
    /* 0x9db414 */ mov x0, x2;
    sub_a43054();
    sub_a469bc();
    sub_a5a1a4();
    sub_a7fc40();
    sub_a7fc40();
    sub_a82210();
    sub_a59d1c();
    sub_a59d24();
    sub_5edc30();
    sub_9d9f84();
    sub_a43700();
    sub_a417b8();
    sub_a417d4();
    sub_9816ac();
    sub_5a3d24();
    sub_a59d1c();
    sub_a59d24();
    sub_9816ac();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_a695e4();
    sub_9d3c74();
    _ZdlPv();
    sub_a695b4();
    wgpuTextureGetFormat();
    sub_5604d4();
    sub_9d3e64();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_a59cc4();
    sub_9d3c74();
    _ZdlPv();
    sub_9d72a8();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_a43064();
    sub_a576d8();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_a59cdc();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    sub_5ee85c();
    return x0;
    sub_562d14();
    _ZdlPv();
    sub_5ee85c();
    sub_106b814();
    __stack_chk_fail();
}
