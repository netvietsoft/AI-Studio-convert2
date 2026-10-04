// Function: sub_9156FC
// RVA: 0x9156fc, Size: 808 bytes
int64_t sub_9156FC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuBufferGetSize(...); // call imported API via PLT at 0x915734
    sub_5AA110(...); // call internal func at 0x915748
    const char* s_2413ec = "mvpMatrix"; // string xref
    const char* s_250856 = "drawColor"; // string xref
    wgpuQueueWriteBuffer(...); // call imported API via PLT at 0x9157b0
    wgpuBufferGetSize(...); // call imported API via PLT at 0x9157ec
    wgpuDeviceCreateBindGroup(...); // call imported API via PLT at 0x91581c
    const char* s_239072 = "position"; // string xref
    sub_A69C84(...); // call internal func at 0x91583c
    const char* s_1f6b07 = "main"; // string xref
    memset(...); // call imported API via PLT at 0x9158c0
    wgpuDeviceCreateRenderPipeline(...); // call imported API via PLT at 0x915900
    wgpuRenderPassEncoderSetPipeline(...); // call imported API via PLT at 0x915918
    wgpuRenderPassEncoderSetBindGroup(...); // call imported API via PLT at 0x915930
    wgpuBufferGetSize(...); // call imported API via PLT at 0x91593c
    wgpuRenderPassEncoderSetVertexBuffer(...); // call imported API via PLT at 0x915954
    wgpuRenderPassEncoderSetIndexBuffer(...); // call imported API via PLT at 0x915970
    wgpuRenderPassEncoderDrawIndexed(...); // call imported API via PLT at 0x91598c
    wgpuRenderPipelineRelease(...); // call imported API via PLT at 0x915994
    wgpuBindGroupRelease(...); // call imported API via PLT at 0x91599c
    _ZdlPv(...); // call imported API via PLT at 0x9159ac
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x915a04
    __stack_chk_fail(...); // call imported API via PLT at 0x915a20
}
