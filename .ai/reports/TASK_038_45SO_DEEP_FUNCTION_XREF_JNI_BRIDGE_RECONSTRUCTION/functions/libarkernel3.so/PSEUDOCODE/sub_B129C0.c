// Function: sub_B129C0
// RVA: 0xb129c0, Size: 248 bytes
int64_t sub_B129C0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    sub_B12AB8(...); // call internal func at 0xb12a08
    wgpuRenderPassEncoderSetVertexBuffer(...); // call imported API via PLT at 0xb12a28
    wgpuRenderPassEncoderSetIndexBuffer(...); // call imported API via PLT at 0xb12a44
    sub_B113C8(...); // call internal func at 0xb12a50
    wgpuRenderPassEncoderSetPipeline(...); // call imported API via PLT at 0xb12a5c
    wgpuRenderPassEncoderSetBindGroup(...); // call imported API via PLT at 0xb12a84
    wgpuRenderPassEncoderDrawIndexed(...); // call imported API via PLT at 0xb12aa0
    wgpuBindGroupRelease(...); // call imported API via PLT at 0xb12ab4
}
