// Library: libarkernel3.so
// Function ID: libarkernel3::0x55f014
// Recovered Name: sub_55f014
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55f014 | Size: 1736 bytes | SHA256: 2f338c538185fa8be5d8fec04291ff4796effb2d4110e7ba9f1ad0ec1b655fcd
// Callers: 0 | Callees: 31 | Imports: 19

// Calls external APIs: _ZdlPv, __stack_chk_fail, memset, wgpuBindGroupRelease, wgpuBufferGetSize, wgpuDeviceCreateBindGroup, wgpuDeviceCreateRenderPipeline, wgpuDeviceCreateSampler, wgpuRenderPassEncoderDraw, wgpuRenderPassEncoderDrawIndexed, wgpuRenderPassEncoderSetBindGroup, wgpuRenderPassEncoderSetBlendConstant, wgpuRenderPassEncoderSetIndexBuffer, wgpuRenderPassEncoderSetPipeline, wgpuRenderPassEncoderSetVertexBuffer, wgpuRenderPassEncoderSetViewport, wgpuRenderPipelineRelease, wgpuSamplerReference, wgpuSamplerRelease
// Strings referenced:
//   "EncodePass"
//   "main"

void sub_55f014(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 434 instructions
    /* 0x55f014 */ stp x29, x30, [sp, #0x180];
    /* 0x55f018 */ stp x28, x27, [sp, #0x190];
    /* 0x55f01c */ stp x26, x25, [sp, #0x1a0];
    /* 0x55f020 */ stp x24, x23, [sp, #0x1b0];
    /* 0x55f024 */ stp x22, x21, [sp, #0x1c0];
    /* 0x55f028 */ stp x20, x19, [sp, #0x1d0];
    /* 0x55f02c */ add x29, sp, #0x180;
    /* 0x55f030 */ str x1, [sp, #0x28];
    /* 0x55f034 */ mrs x20, tpidr_el0;
    /* 0x55f038 */ mov x22, x0;
    /* 0x55f03c */ ldr x8, [x20, #0x28];
    sub_565168();
    sub_a6a3d8();
    sub_a69d30();
    sub_5647e0();
    sub_55f6dc();
    sub_5647e0();
    sub_55f750();
    sub_5647e0();
    sub_564808();
    sub_a69c84();
    _ZdlPv();
    sub_565170();
    sub_56a074();
    memset();
    sub_564698();
    sub_56a0cc();
    sub_56a0d4();
    sub_56a0f8();
    sub_9fdf80();
    wgpuDeviceCreateRenderPipeline();
    _ZdlPv();
    _ZdlPv();
    sub_9fe578();
    wgpuRenderPassEncoderSetPipeline();
    sub_565170();
    sub_56a0dc();
    wgpuRenderPassEncoderSetBlendConstant();
    wgpuRenderPassEncoderSetViewport();
    sub_a69d30();
    sub_a69e68();
    sub_55f7e8();
    sub_aa29c8();
    sub_a8aaa8();
    _ZdlPv();
    sub_55ff94();
    sub_a6a3b4();
    sub_562578();
    sub_56b384();
    sub_56ab4c();
    sub_a81778();
    wgpuDeviceCreateSampler();
    sub_a82238();
    sub_a82200();
    wgpuSamplerReference();
    sub_9fdf80();
    wgpuDeviceCreateBindGroup();
    wgpuSamplerRelease();
    _ZdlPv();
    wgpuRenderPassEncoderSetBindGroup();
    sub_5647e0();
    sub_564808();
    sub_564808();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    _ZdlPv();
    _ZdlPv();
    sub_5647e0();
    sub_5647fc();
    sub_5647fc();
    sub_5647fc();
    wgpuRenderPassEncoderSetIndexBuffer();
    sub_5647fc();
    wgpuRenderPassEncoderDrawIndexed();
    wgpuRenderPassEncoderDraw();
    wgpuRenderPipelineRelease();
    wgpuBindGroupRelease();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
