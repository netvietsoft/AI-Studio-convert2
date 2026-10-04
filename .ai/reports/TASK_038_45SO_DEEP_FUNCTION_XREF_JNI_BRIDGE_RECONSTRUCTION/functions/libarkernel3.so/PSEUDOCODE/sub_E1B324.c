// Function: sub_E1B324
// RVA: 0xe1b324, Size: 548 bytes
int64_t sub_E1B324(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuDeviceGetQueue(...); // call PLT API at 0xe1b358
    wgpuDeviceReference(...); // call PLT API at 0xe1b37c
    memset(...); // call PLT API at 0xe1b394
    const char* str = "RenderContext::generateMipmap::layout";
    wgpuDeviceCreateBindGroupLayout(...); // call PLT API at 0xe1b3d0
    const char* str = "RenderContext::generateMipmap::vert";
    const char* str = "main";
    wgpuDeviceCreateShaderModule(...); // call PLT API at 0xe1b424
    const char* str = "RenderContext::generateMipmap::frag";
    wgpuDeviceCreateShaderModule(...); // call PLT API at 0xe1b470
    const char* str = "RenderContext::generateMipmap::vertex";
    wgpuDeviceCreateBuffer(...); // call PLT API at 0xe1b4a8
    wgpuBufferGetMappedRange(...); // call PLT API at 0xe1b4b8
    memcpy(...); // call PLT API at 0xe1b4c8
    wgpuBufferUnmap(...); // call PLT API at 0xe1b4d0
    const char* str = "RenderContext::generateMipmap::sampler";
    wgpuDeviceCreateSampler(...); // call PLT API at 0xe1b510
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe1b540
    sub_562D14(...); // call internal at 0xe1b544
}
