// Library: libarkernel3.so
// Function ID: libarkernel3::0x9daa48
// Recovered Name: sub_9daa48
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9daa48 | Size: 2452 bytes | SHA256: 32a3155b61aac68bc173b6e6526614a8ce189761668834486d5ff4afea90ec72
// Callers: 0 | Callees: 32 | Imports: 5

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "StickerPart::RenderBackGroundFollowOldVersion fail! kSegmentMaskBody is null"
//   "a_position"
//   "mtlabar3"
//   "renderBackGroundFollowOldVersion"
//   "u_alpha"

void sub_9daa48(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 613 instructions
    /* 0x9daa48 */ stp x29, x30, [sp, #0x40];
    /* 0x9daa4c */ stp x28, x27, [sp, #0x50];
    /* 0x9daa50 */ stp x26, x25, [sp, #0x60];
    /* 0x9daa54 */ stp x24, x23, [sp, #0x70];
    /* 0x9daa58 */ stp x22, x21, [sp, #0x80];
    /* 0x9daa5c */ stp x20, x19, [sp, #0x90];
    /* 0x9daa60 */ add x29, sp, #0x40;
    /* 0x9daa64 */ sub sp, sp, #0x490;
    /* 0x9daa68 */ mrs x23, tpidr_el0;
    /* 0x9daa6c */ mov x24, x0;
    /* 0x9daa70 */ mov x0, x2;
    sub_a43064();
    sub_a576d8();
    sub_a7fc40();
    sub_a7fc40();
    sub_a82210();
    sub_a59d1c();
    sub_a59d24();
    sub_5edc30();
    sub_a43054();
    sub_a469bc();
    sub_a5a1a4();
    sub_9d9f84();
    sub_a435c4();
    sub_a695b4();
    wgpuTextureGetWidth();
    sub_a695b4();
    wgpuTextureGetHeight();
    sub_a59d1c();
    sub_a59d24();
    sub_5a3d24();
    sub_5a704c();
    sub_a43700();
    sub_a417d4();
    sub_981588();
    sub_9816ac();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_5a3d24();
    sub_9d3a64();
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
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_a59cdc();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    _ZdlPv();
    sub_5ee85c();
    return x0;
    sub_562d14();
    _ZdlPv();
    _ZdlPv();
    sub_5ee85c();
    sub_106b814();
    __stack_chk_fail();
}
