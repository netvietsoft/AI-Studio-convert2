// Library: libarkernel3.so
// Function ID: libarkernel3::0xaec69c
// Recovered Name: sub_aec69c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaec69c | Size: 1692 bytes | SHA256: 481bc64dd6748c4c32f61ef2ce4c1421907ff515f2d35195e674d0938c13d2d3
// Callers: 0 | Callees: 21 | Imports: 6

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail, memmove, wgpuTextureRelease, wgpuTextureViewRelease
// Strings referenced:
//   "a_position"
//   "a_texCoord"
//   "res/bodymovin/blur.fs"
//   "res/bodymovin/blur.vs"
//   "u_pixelSize"

void sub_aec69c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 423 instructions
    /* 0xaec69c */ stp x29, x30, [sp, #0x170];
    /* 0xaec6a0 */ stp x28, x27, [sp, #0x180];
    /* 0xaec6a4 */ stp x26, x25, [sp, #0x190];
    /* 0xaec6a8 */ stp x24, x23, [sp, #0x1a0];
    /* 0xaec6ac */ stp x22, x21, [sp, #0x1b0];
    /* 0xaec6b0 */ stp x20, x19, [sp, #0x1c0];
    /* 0xaec6b4 */ add x29, sp, #0x170;
    /* 0xaec6b8 */ mrs x27, tpidr_el0;
    /* 0xaec6bc */ mov w26, w3;
    /* 0xaec6c0 */ mov x23, x2;
    /* 0xaec6c4 */ ldr x8, [x27, #0x28];
    sub_aec5ec();
    sub_9fe4f4();
    sub_65884c();
    sub_659130();
    sub_5604d4();
    sub_a7fc58();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_560420();
    memmove();
    sub_ccc064();
    sub_5604d4();
    sub_a7b364();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _Znwm();
    _Znwm();
    _Znwm();
    sub_9d36ac();
    sub_9d3a44();
    sub_9d3f5c();
    sub_9d3f44();
    sub_9d3a64();
    sub_9d3a64();
    sub_9d3bd4();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    sub_9fe4f4();
    sub_9d3bd4();
    sub_9d3a5c();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_a7fc40();
    sub_9d3f68();
    wgpuTextureViewRelease();
    wgpuTextureRelease();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
