// Function: sub_70CCE0
// RVA: 0x70cce0, Size: 360 bytes
int64_t sub_70CCE0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_A7FC40(...); // call internal at 0x70cd0c
    sub_5AA23C(...); // call internal at 0x70cd28
    sub_63C174(...); // call internal at 0x70cd54
    sub_5AB304(...); // call internal at 0x70cd68
    sub_A7FC40(...); // call internal at 0x70cdb4
    sub_A81778(...); // call internal at 0x70cdb8
    wgpuDeviceCreateCommandEncoder(...); // call PLT API at 0x70cdc0
    wgpuCommandEncoderBeginRenderPass(...); // call PLT API at 0x70cdcc
    wgpuRenderPassEncoderEnd(...); // call PLT API at 0x70cdd0
    const char* str = "Command buffer";
    wgpuCommandEncoderFinish(...); // call PLT API at 0x70cde8
    wgpuCommandEncoderRelease(...); // call PLT API at 0x70cdf4
    sub_A7FC40(...); // call internal at 0x70cdfc
    sub_A821F8(...); // call internal at 0x70ce00
    wgpuQueueSubmit(...); // call PLT API at 0x70ce0c
    wgpuCommandBufferRelease(...); // call PLT API at 0x70ce14
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x70ce40
    sub_562D14(...); // call internal at 0x70ce44
}
