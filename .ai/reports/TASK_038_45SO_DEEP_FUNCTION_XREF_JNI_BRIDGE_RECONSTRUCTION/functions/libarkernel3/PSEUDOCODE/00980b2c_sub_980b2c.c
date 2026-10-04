// Library: libarkernel3.so
// Function ID: libarkernel3::0x980b2c
// Recovered Name: sub_980b2c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x980b2c | Size: 1148 bytes | SHA256: 13dea62ab182cfd778686e99e89db68f7a33e3876922b50759f6708610a71580
// Callers: 0 | Callees: 25 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "u_alpha"
//   "u_mvpMatrix"
//   "u_segmentTexture"
//   "u_srcTexture"
//   "u_stickerTexture"

void sub_980b2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 287 instructions
    /* 0x980b2c */ stp x29, x30, [sp, #0x130];
    /* 0x980b30 */ stp x28, x25, [sp, #0x140];
    /* 0x980b34 */ stp x24, x23, [sp, #0x150];
    /* 0x980b38 */ stp x22, x21, [sp, #0x160];
    /* 0x980b3c */ stp x20, x19, [sp, #0x170];
    /* 0x980b40 */ add x29, sp, #0x130;
    /* 0x980b44 */ mrs x25, tpidr_el0;
    /* 0x980b48 */ ldr x8, [x25, #0x28];
    /* 0x980b4c */ stur x8, [x29, #-0x18];
    /* 0x980b50 */ ldr w8, [x0, #0x4d8];
    /* 0x980b54 */ and w8, w8, #0xfffffffe;
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_a5a1a4();
    sub_a59d1c();
    sub_a59d24();
    sub_97f13c();
    sub_657d80();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3c74();
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
    _ZdlPv();
    sub_5ee85c();
    sub_106b814();
    __stack_chk_fail();
}
