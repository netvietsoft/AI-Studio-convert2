// Library: libarkernel3.so
// Function ID: libarkernel3::0x9dc2a0
// Recovered Name: sub_9dc2a0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9dc2a0 | Size: 2700 bytes | SHA256: b2bd682cb443f94bbb4dd08dd82ad40b9877297435700521c7c828dff1261fe3
// Callers: 0 | Callees: 29 | Imports: 5

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "u_alpha"
//   "u_grayImage"
//   "u_mvpMatrix"
//   "u_segmentTexture"
//   "u_srcTexture"

void sub_9dc2a0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 675 instructions
    /* 0x9dc2a0 */ stp x29, x30, [sp, #0x40];
    /* 0x9dc2a4 */ stp x28, x27, [sp, #0x50];
    /* 0x9dc2a8 */ stp x26, x25, [sp, #0x60];
    /* 0x9dc2ac */ stp x24, x23, [sp, #0x70];
    /* 0x9dc2b0 */ stp x22, x21, [sp, #0x80];
    /* 0x9dc2b4 */ stp x20, x19, [sp, #0x90];
    /* 0x9dc2b8 */ add x29, sp, #0x40;
    /* 0x9dc2bc */ sub sp, sp, #0x4a0;
    /* 0x9dc2c0 */ mrs x25, tpidr_el0;
    /* 0x9dc2c4 */ mov x19, x0;
    /* 0x9dc2c8 */ mov x22, x2;
    sub_a43064();
    sub_a576d8();
    sub_a5a1a4();
    sub_a59d1c();
    sub_a59d24();
    sub_a695b4();
    wgpuTextureGetWidth();
    sub_a695b4();
    wgpuTextureGetHeight();
    sub_5a3d24();
    sub_5a3d24();
    sub_657dc0();
    sub_5a3d24();
    sub_657df0();
    sub_657dd8();
    sub_981588();
    sub_9816ac();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_657d80();
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
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_9d72a8();
    sub_a43064();
    sub_a576d8();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_a7fc40();
    sub_a7fc40();
    sub_a82210();
    sub_a59d1c();
    sub_a59d24();
    sub_5edc30();
    sub_9d9f84();
    sub_a59cdc();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    sub_5ee85c();
    return x0;
    sub_562d14();
    sub_5ee85c();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
