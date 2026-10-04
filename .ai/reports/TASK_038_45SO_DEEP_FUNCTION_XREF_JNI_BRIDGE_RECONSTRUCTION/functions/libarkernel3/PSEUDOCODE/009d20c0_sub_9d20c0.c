// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d20c0
// Recovered Name: sub_9d20c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d20c0 | Size: 1872 bytes | SHA256: b70725bff98464684609a90a865d9f5599dab15b5b1283f5373048ee03b35cc3
// Callers: 0 | Callees: 37 | Imports: 10

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuBufferGetConstMappedRange, wgpuBufferRelease, wgpuBufferUnmap, wgpuCommandEncoderCopyTextureToBuffer, wgpuDeviceCreateBuffer, wgpuTextureGetFormat, wgpuTextureGetHeight, wgpuTextureGetWidth
// Strings referenced:
//   "SegmentStrokeObjPart mask downsample"
//   "SegmentStrokeObjPart mask readback"
//   "a_Position"
//   "a_UV"
//   "s_materialMap"

void sub_9d20c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 468 instructions
    /* 0x9d20c0 */ stp x29, x30, [sp, #0x20];
    /* 0x9d20c4 */ stp x28, x27, [sp, #0x30];
    /* 0x9d20c8 */ stp x26, x25, [sp, #0x40];
    /* 0x9d20cc */ stp x24, x23, [sp, #0x50];
    /* 0x9d20d0 */ stp x22, x21, [sp, #0x60];
    /* 0x9d20d4 */ stp x20, x19, [sp, #0x70];
    /* 0x9d20d8 */ add x29, sp, #0x20;
    /* 0x9d20dc */ sub sp, sp, #0x2b0;
    /* 0x9d20e0 */ mrs x20, tpidr_el0;
    /* 0x9d20e4 */ ldr x8, [x20, #0x28];
    /* 0x9d20e8 */ stur x8, [x29, #-0x38];
    sub_a6a3d8();
    sub_a43064();
    sub_a576d8();
    wgpuTextureGetFormat();
    sub_aa2a10();
    sub_aa192c();
    wgpuTextureGetWidth();
    wgpuTextureGetHeight();
    sub_a7fc40();
    sub_5aa23c();
    sub_a7fc40();
    sub_a7fc40();
    sub_a82210();
    sub_5edc30();
    sub_9fdf90();
    sub_9d36ac();
    sub_9d3bd4();
    sub_9d2810();
    sub_9d2810();
    sub_9d3a64();
    sub_9d3a64();
    sub_9d288c();
    sub_9d3b6c();
    sub_5604d4();
    sub_9d3e64();
    _ZdlPv();
    sub_5604d4();
    sub_9d3c74();
    _ZdlPv();
    sub_9d3f44();
    sub_9d3a44();
    sub_9d3f34();
    sub_9d3a5c();
    sub_a7fc40();
    sub_9d3f68();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_9d379c();
    sub_5ee85c();
    sub_9fe5a4();
    sub_9fdf80();
    wgpuDeviceCreateBuffer();
    wgpuCommandEncoderCopyTextureToBuffer();
    sub_9fe8fc();
    sub_9fdf88();
    sub_9d2908();
    wgpuBufferGetConstMappedRange();
    sub_560034();
    wgpuBufferUnmap();
    wgpuBufferRelease();
    sub_f6789c();
    sub_f678d8();
    _ZdlPv();
    wgpuBufferUnmap();
    wgpuBufferRelease();
    sub_5ab304();
    return x0;
    _ZdlPv();
    sub_562d14();
    sub_562d14();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_9d379c();
    sub_5ee85c();
    sub_5ab304();
    sub_106b814();
    __stack_chk_fail();
}
