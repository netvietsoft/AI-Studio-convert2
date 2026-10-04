// Function: sub_957B8C
// RVA: 0x957b8c, Size: 800 bytes
int64_t sub_957B8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuBufferRelease(...); // call imported API via PLT at 0x957be4
    wgpuBufferRelease(...); // call imported API via PLT at 0x957bf0
    sub_A834E0(...); // call internal func at 0x957c04
    sub_A8340C(...); // call internal func at 0x957c24
    void* g_2b4db8 = (void*)0x2b4db8; // global ref
    const char* s_2413ec = "mvpMatrix"; // string xref
    const char* s_250856 = "drawColor"; // string xref
    const char* s_239072 = "position"; // string xref
    sub_A69C84(...); // call internal func at 0x957cd8
    const char* s_1f6b07 = "main"; // string xref
    memset(...); // call imported API via PLT at 0x957d40
    const char* s_1b1c0d = "border_renderer"; // string xref
    wgpuDeviceCreateRenderPipeline(...); // call imported API via PLT at 0x957d8c
    wgpuRenderPassEncoderSetPipeline(...); // call imported API via PLT at 0x957da4
    sub_9166A4(...); // call internal func at 0x957dac
    wgpuRenderPassEncoderSetBindGroup(...); // call imported API via PLT at 0x957dc4
    wgpuBufferGetSize(...); // call imported API via PLT at 0x957dd0
    wgpuRenderPassEncoderSetVertexBuffer(...); // call imported API via PLT at 0x957de8
    wgpuBufferGetSize(...); // call imported API via PLT at 0x957df4
    wgpuRenderPassEncoderSetIndexBuffer(...); // call imported API via PLT at 0x957e0c
    wgpuRenderPassEncoderDrawIndexed(...); // call imported API via PLT at 0x957e28
    wgpuRenderPipelineRelease(...); // call imported API via PLT at 0x957e30
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x957e60
    void* g_2b4df8 = (void*)0x2b4df8; // global ref
    return a0;
}
