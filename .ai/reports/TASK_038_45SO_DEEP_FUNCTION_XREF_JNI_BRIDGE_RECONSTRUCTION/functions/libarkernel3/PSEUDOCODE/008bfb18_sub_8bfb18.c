// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bfb18
// Recovered Name: sub_8bfb18
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bfb18 | Size: 1160 bytes | SHA256: 6f0b97b3a5f1ff00e1fc1392542c83305b197aaf71290eaa07fafdee79d533ad
// Callers: 0 | Callees: 29 | Imports: 12

// Calls external APIs: __stack_chk_fail, memset, wgpuBindGroupRelease, wgpuBufferGetSize, wgpuDeviceCreateRenderPipeline, wgpuRenderPassEncoderDraw, wgpuRenderPassEncoderDrawIndexed, wgpuRenderPassEncoderSetBindGroup, wgpuRenderPassEncoderSetIndexBuffer, wgpuRenderPassEncoderSetPipeline, wgpuRenderPassEncoderSetVertexBuffer, wgpuRenderPipelineRelease
// Strings referenced:
//   "main"
//   "makeup_hair_part"

void sub_8bfb18(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 290 instructions
    /* 0x8bfb18 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x8bfb1c */ stp x28, x27, [sp, #0x10];
    /* 0x8bfb20 */ stp x26, x25, [sp, #0x20];
    /* 0x8bfb24 */ stp x24, x23, [sp, #0x30];
    /* 0x8bfb28 */ stp x22, x21, [sp, #0x40];
    /* 0x8bfb2c */ stp x20, x19, [sp, #0x50];
    /* 0x8bfb30 */ mov x29, sp;
    /* 0x8bfb34 */ sub sp, sp, #0x220;
    /* 0x8bfb38 */ mrs x26, tpidr_el0;
    /* 0x8bfb3c */ mov x19, x0;
    /* 0x8bfb40 */ ldr x8, [x26, #0x28];
    sub_a6a3d8();
    sub_a69d30();
    sub_911024();
    sub_a5a1a4();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43064();
    sub_a576d8();
    sub_a43054();
    sub_a469bc();
    sub_a469bc();
    sub_8bd2ec();
    sub_8bf018();
    sub_8be244();
    sub_a69c84();
    sub_a59cf4();
    memset();
    sub_9fdf80();
    wgpuDeviceCreateRenderPipeline();
    sub_a59cc4();
    sub_9fdf90();
    sub_9fe578();
    wgpuRenderPassEncoderSetPipeline();
    wgpuRenderPassEncoderSetBindGroup();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    sub_a5a194();
    sub_913344();
    wgpuRenderPassEncoderSetIndexBuffer();
    sub_913344();
    wgpuRenderPassEncoderDrawIndexed();
    sub_9131b0();
    sub_913304();
    sub_913344();
    sub_a59d1c();
    sub_a59d24();
    sub_a59fa4();
    sub_913334();
    wgpuRenderPassEncoderDraw();
    sub_9131b0();
    sub_913334();
    sub_a59d1c();
    sub_a59d24();
    sub_a5a0a0();
    wgpuRenderPipelineRelease();
    wgpuBindGroupRelease();
    return x0;
    __stack_chk_fail();
}
