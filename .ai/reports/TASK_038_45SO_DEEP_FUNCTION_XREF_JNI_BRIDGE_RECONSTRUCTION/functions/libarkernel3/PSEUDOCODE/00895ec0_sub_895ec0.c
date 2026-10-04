// Library: libarkernel3.so
// Function ID: libarkernel3::0x895ec0
// Recovered Name: sub_895ec0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x895ec0 | Size: 3112 bytes | SHA256: e1bb23519dbed89e81a98f0b7c5f910a739e979cbf7401f4d68090e8957f6144
// Callers: 0 | Callees: 23 | Imports: 14

// Calls external APIs: _ZdlPv, __stack_chk_fail, memset, wgpuBindGroupRelease, wgpuBufferGetSize, wgpuDeviceCreateBindGroup, wgpuDeviceCreateRenderPipeline, wgpuRenderPassEncoderDraw, wgpuRenderPassEncoderDrawIndexed, wgpuRenderPassEncoderSetBindGroup, wgpuRenderPassEncoderSetIndexBuffer, wgpuRenderPassEncoderSetPipeline, wgpuRenderPassEncoderSetVertexBuffer, wgpuRenderPipelineRelease
// Strings referenced:
//   "MakeupBlendModeDrawable vertex attribute overflow."
//   "drawViewport"
//   "main"
//   "makeup_blend_mode_depth_prepass"
//   "makeup_blend_mode_drawable"

void sub_895ec0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 778 instructions
    /* 0x895ec0 */ stp x29, x30, [sp, #0x30];
    /* 0x895ec4 */ stp x28, x27, [sp, #0x40];
    /* 0x895ec8 */ stp x26, x25, [sp, #0x50];
    /* 0x895ecc */ stp x24, x23, [sp, #0x60];
    /* 0x895ed0 */ stp x22, x21, [sp, #0x70];
    /* 0x895ed4 */ stp x20, x19, [sp, #0x80];
    /* 0x895ed8 */ add x29, sp, #0x30;
    /* 0x895edc */ sub sp, sp, #0x500;
    /* 0x895ee0 */ mrs x23, tpidr_el0;
    /* 0x895ee4 */ mov x19, x0;
    /* 0x895ee8 */ mov w26, w3;
    sub_a6a3d8();
    sub_a69d30();
    sub_a69d30();
    sub_5aa110();
    sub_aa2af4();
    sub_aa5b4c();
    sub_a69d40();
    sub_a69d40();
    sub_a69d40();
    sub_a69d40();
    sub_a69d40();
    sub_a69d40();
    sub_aa29c8();
    sub_a8aaa8();
    memset();
    sub_a69d38();
    sub_a69f54();
    sub_a69d30();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a7fc40();
    sub_a82230();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82230();
    sub_a69bbc();
    sub_a69f8c();
    sub_a7fc40();
    sub_a82200();
    sub_a7fc40();
    sub_a82238();
    sub_9fdf80();
    wgpuDeviceCreateBindGroup();
    sub_a69af4();
    sub_cccfe0();
    sub_a69c84();
    memset();
    sub_a7fc40();
    sub_a82210();
    sub_9fdf80();
    wgpuDeviceCreateRenderPipeline();
    sub_9fdf80();
    wgpuDeviceCreateRenderPipeline();
    sub_9fe578();
    wgpuRenderPassEncoderSetPipeline();
    wgpuRenderPassEncoderSetBindGroup();
    sub_a69af4();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuRenderPassEncoderSetIndexBuffer();
    wgpuRenderPassEncoderDrawIndexed();
    wgpuRenderPassEncoderDraw();
    wgpuRenderPassEncoderSetPipeline();
    wgpuRenderPassEncoderSetIndexBuffer();
    wgpuRenderPassEncoderDrawIndexed();
    wgpuRenderPassEncoderDraw();
    wgpuRenderPipelineRelease();
    wgpuRenderPipelineRelease();
    wgpuBindGroupRelease();
    _ZdlPv();
    return x0;
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
