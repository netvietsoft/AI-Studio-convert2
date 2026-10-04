// Library: libarkernel3.so
// Function ID: libarkernel3::0x882374
// Recovered Name: sub_882374
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x882374 | Size: 2996 bytes | SHA256: 7b2016cc854b5078fcec65fb75c3778e4b55224b1d41d3f952e7f822c6b1cb95
// Callers: 1 | Callees: 56 | Imports: 11

// Calls external APIs: _ZdlPv, __stack_chk_fail, wgpuBindGroupRelease, wgpuBufferGetSize, wgpuDeviceCreateRenderPipeline, wgpuRenderPassEncoderDrawIndexed, wgpuRenderPassEncoderSetBindGroup, wgpuRenderPassEncoderSetIndexBuffer, wgpuRenderPassEncoderSetPipeline, wgpuRenderPassEncoderSetVertexBuffer, wgpuRenderPipelineRelease
// Strings referenced:
//   "MergeRenderPipeline"
//   "a_Position"
//   "a_SrcUV"
//   "a_UV"
//   "a_makeupAdaptUV"

void sub_882374(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 749 instructions
    /* 0x882374 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x882378 */ stp x28, x27, [sp, #0x10];
    /* 0x88237c */ stp x26, x25, [sp, #0x20];
    /* 0x882380 */ stp x24, x23, [sp, #0x30];
    /* 0x882384 */ stp x22, x21, [sp, #0x40];
    /* 0x882388 */ stp x20, x19, [sp, #0x50];
    /* 0x88238c */ mov x29, sp;
    /* 0x882390 */ sub sp, sp, #0x400;
    /* 0x882394 */ mrs x20, tpidr_el0;
    /* 0x882398 */ mov x21, x0;
    /* 0x88239c */ mov x22, x2;
    sub_a6a3d8();
    sub_a59d1c();
    sub_a59d24();
    sub_aa2a10();
    sub_aa1c78();
    sub_a43a4c();
    sub_913334();
    sub_65e39c();
    sub_9131b0();
    sub_913334();
    sub_a43a94();
    sub_9e4fe0();
    sub_9131b0();
    sub_913334();
    sub_aa29c8();
    sub_a8ad80();
    sub_9131f4();
    sub_913334();
    sub_aa29c8();
    sub_a8ad80();
    sub_91327c();
    sub_913334();
    sub_aa29c8();
    sub_a8ad80();
    sub_a69af4();
    sub_aa29c8();
    sub_a8ad80();
    sub_913304();
    sub_913344();
    sub_aa29c8();
    sub_a8b058();
    sub_a69af4();
    sub_a69c84();
    sub_a69c84();
    sub_a69c84();
    sub_a69c84();
    sub_a59cf4();
    sub_916300();
    sub_881e90();
    sub_763e98();
    sub_881e90();
    sub_763e98();
    sub_881e90();
    sub_aa2af4();
    sub_aa5b4c();
    sub_aa2af4();
    sub_aa5b4c();
    sub_9164ac();
    sub_9164ac();
    sub_881e90();
    sub_9164ac();
    sub_881e90();
    sub_916418();
    sub_a69bbc();
    sub_881e90();
    sub_916418();
    sub_a69bbc();
    sub_916188();
    sub_881e90();
    sub_916384();
    sub_881e90();
    sub_916384();
    sub_8832a8();
    sub_a7fc40();
    sub_a82230();
    sub_a7fc40();
    sub_a82200();
    sub_916b24();
    sub_881e90();
    sub_cccfe0();
    sub_a59cac();
    sub_a7fc40();
    sub_a82200();
    sub_916b24();
    sub_aa29c8();
    sub_a8a22c();
    sub_a5c178();
    sub_a43054();
    sub_a4725c();
    sub_a434b4();
    sub_a4edf8();
    sub_a7fc40();
    sub_a82238();
    sub_a7fc40();
    sub_a82200();
    sub_916b24();
    sub_a69bbc();
    sub_a43a54();
    sub_a7fc40();
    sub_a82238();
    sub_a7fc40();
    sub_a82200();
    sub_916b24();
    sub_9168f0();
    sub_9166a4();
    sub_a7fc40();
    sub_a81778();
    wgpuDeviceCreateRenderPipeline();
    sub_a5a1a4();
    sub_a59cc4();
    sub_9fdf90();
    wgpuRenderPassEncoderSetPipeline();
    wgpuRenderPassEncoderSetBindGroup();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetVertexBuffer();
    wgpuBufferGetSize();
    wgpuRenderPassEncoderSetIndexBuffer();
    sub_913344();
    wgpuRenderPassEncoderDrawIndexed();
    wgpuRenderPipelineRelease();
    wgpuBindGroupRelease();
    sub_9131f4();
    sub_913304();
    sub_913344();
    sub_a59eb4();
    sub_a59d2c();
    sub_a5a194();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
