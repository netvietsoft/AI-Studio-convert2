// Function: sub_A74B5C
// RVA: 0xa74b5c, Size: 600 bytes
int64_t sub_A74B5C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_CC4F44(...); // call internal at 0xa74bcc
    sub_A7FC40(...); // call internal at 0xa74bd8
    sub_A81778(...); // call internal at 0xa74bdc
    wgpuDeviceCreateCommandEncoder(...); // call PLT API at 0xa74bf0
    sub_A74DB4(...); // call internal at 0xa74c04
    sub_A7FC40(...); // call internal at 0xa74c20
    sub_A82200(...); // call internal at 0xa74c24
    wgpuDeviceCreateBindGroup(...); // call PLT API at 0xa74c50
    wgpuCommandEncoderBeginRenderPass(...); // call PLT API at 0xa74c98
    sub_A7FC40(...); // call internal at 0xa74ca4
    sub_A82220(...); // call internal at 0xa74ca8
    wgpuRenderPassEncoderSetPipeline(...); // call PLT API at 0xa74cb8
    wgpuRenderPassEncoderSetBindGroup(...); // call PLT API at 0xa74cd0
    wgpuBufferGetSize(...); // call PLT API at 0xa74cd8
    wgpuRenderPassEncoderSetVertexBuffer(...); // call PLT API at 0xa74cf0
    wgpuRenderPassEncoderDraw(...); // call PLT API at 0xa74d08
    wgpuRenderPassEncoderEnd(...); // call PLT API at 0xa74d10
    wgpuBindGroupRelease(...); // call PLT API at 0xa74d18
    sub_CC4F44(...); // call internal at 0xa74d28
    sub_A7FC88(...); // call internal at 0xa74d34
    sub_A76B9C(...); // call internal at 0xa74d44
    wgpuCommandEncoderFinish(...); // call PLT API at 0xa74d50
    sub_A7FC40(...); // call internal at 0xa74d5c
    sub_A821F8(...); // call internal at 0xa74d60
    wgpuQueueSubmit(...); // call PLT API at 0xa74d6c
    wgpuCommandEncoderRelease(...); // call PLT API at 0xa74d74
    wgpuCommandBufferRelease(...); // call PLT API at 0xa74d7c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xa74dac
    sub_562D14(...); // call internal at 0xa74db0
}
