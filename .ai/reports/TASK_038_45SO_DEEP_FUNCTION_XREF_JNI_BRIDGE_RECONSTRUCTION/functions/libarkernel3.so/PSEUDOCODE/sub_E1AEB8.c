// Function: sub_E1AEB8
// RVA: 0xe1aeb8, Size: 512 bytes
int64_t sub_E1AEB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "main";
    memset(...); // call PLT API at 0xe1af7c
    wgpuDeviceCreateRenderPipeline(...); // call PLT API at 0xe1afd8
    wgpuDeviceCreateBindGroup(...); // call PLT API at 0xe1b010
    wgpuRenderPassEncoderSetPipeline(...); // call PLT API at 0xe1b020
    wgpuBufferGetSize(...); // call PLT API at 0xe1b02c
    wgpuRenderPassEncoderSetVertexBuffer(...); // call PLT API at 0xe1b044
    wgpuRenderPassEncoderSetBindGroup(...); // call PLT API at 0xe1b05c
    wgpuRenderPassEncoderDraw(...); // call PLT API at 0xe1b074
    wgpuRenderPipelineRelease(...); // call PLT API at 0xe1b07c
    wgpuBindGroupRelease(...); // call PLT API at 0xe1b084
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe1b0b4
}
