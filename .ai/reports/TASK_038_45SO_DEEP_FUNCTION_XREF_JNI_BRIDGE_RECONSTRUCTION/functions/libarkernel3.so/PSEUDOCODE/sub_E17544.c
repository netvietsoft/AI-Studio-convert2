// Function: sub_E17544
// RVA: 0xe17544, Size: 508 bytes
int64_t sub_E17544(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E17CA4(...); // call internal at 0xe17584
    sub_E3B4CC(...); // call internal at 0xe1758c
    sub_E3ABBC(...); // call internal at 0xe17590
    const char* str = "FRenderContext::waitScreenHost::tempBuffer";
    wgpuDeviceCreateBuffer(...); // call PLT API at 0xe175cc
    sub_E3B57C(...); // call internal at 0xe175e4
    wgpuCommandEncoderCopyTextureToBuffer(...); // call PLT API at 0xe1762c
    sub_E177FC(...); // call internal at 0xe17634
    wgpuQueueOnSubmittedWorkDone(...); // call PLT API at 0xe17650
    wgpuQueueSubmit(...); // call PLT API at 0xe17668
    wgpuBufferGetSize(...); // call PLT API at 0xe17678
    wgpuBufferMapAsync(...); // call PLT API at 0xe17698
    wgpuQueueSubmit(...); // call PLT API at 0xe176b4
    wgpuBufferGetSize(...); // call PLT API at 0xe176c4
    wgpuBufferGetConstMappedRange(...); // call PLT API at 0xe176d4
    wgpuBufferGetSize(...); // call PLT API at 0xe176e4
    memcpy(...); // call PLT API at 0xe176f4
    wgpuBufferUnmap(...); // call PLT API at 0xe176fc
    wgpuBufferDestroy(...); // call PLT API at 0xe17704
    wgpuBufferRelease(...); // call PLT API at 0xe1770c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe1773c
}
