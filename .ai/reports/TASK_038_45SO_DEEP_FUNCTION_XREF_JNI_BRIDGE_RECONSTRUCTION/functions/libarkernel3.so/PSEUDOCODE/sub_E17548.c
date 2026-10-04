// Function: sub_E17548
// RVA: 0xe17548, Size: 504 bytes
int64_t sub_E17548(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E17CA4(...); // call internal func at 0xe17584
    sub_E3ABBC(...); // call internal func at 0xe17590
    const char* s_282823 = "FRenderContext::waitScreenHost::tempBuffer"; // string xref
    wgpuDeviceCreateBuffer(...); // call imported API via PLT at 0xe175cc
    wgpuCommandEncoderCopyTextureToBuffer(...); // call imported API via PLT at 0xe1762c
    sub_E177FC(...); // call internal func at 0xe17634
    wgpuQueueOnSubmittedWorkDone(...); // call imported API via PLT at 0xe17650
    wgpuQueueSubmit(...); // call imported API via PLT at 0xe17668
    wgpuBufferGetSize(...); // call imported API via PLT at 0xe17678
    wgpuBufferMapAsync(...); // call imported API via PLT at 0xe17698
    wgpuQueueSubmit(...); // call imported API via PLT at 0xe176b4
    wgpuBufferGetSize(...); // call imported API via PLT at 0xe176c4
    wgpuBufferGetConstMappedRange(...); // call imported API via PLT at 0xe176d4
    wgpuBufferGetSize(...); // call imported API via PLT at 0xe176e4
    memcpy(...); // call imported API via PLT at 0xe176f4
    wgpuBufferUnmap(...); // call imported API via PLT at 0xe176fc
    wgpuBufferDestroy(...); // call imported API via PLT at 0xe17704
    wgpuBufferRelease(...); // call imported API via PLT at 0xe1770c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xe1773c
}
