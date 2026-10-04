// Function: sub_94BB40
// RVA: 0x94bb40, Size: 596 bytes
int64_t sub_94BB40(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x94bb7c
    memset(...); // call imported API via PLT at 0x94bb94
    const char* s_1ef3cb = "a_position"; // string xref
    sub_A69C84(...); // call internal func at 0x94bbbc
    const char* s_263e94 = "a_texCoord"; // string xref
    sub_A69C84(...); // call internal func at 0x94bbe0
    const char* s_1f6b07 = "main"; // string xref
    const char* s_18df75 = "mv_frames"; // string xref
    wgpuDeviceCreateRenderPipeline(...); // call imported API via PLT at 0x94bc9c
    const char* s_1b8ac2 = "s_materialMap"; // string xref
    sub_916B24(...); // call internal func at 0x94bcd0
    sub_9168F0(...); // call internal func at 0x94bcdc
    wgpuRenderPassEncoderSetPipeline(...); // call imported API via PLT at 0x94bcf4
    wgpuRenderPassEncoderSetBindGroup(...); // call imported API via PLT at 0x94bd0c
    wgpuRenderPassEncoderSetVertexBuffer(...); // call imported API via PLT at 0x94bd2c
    wgpuRenderPassEncoderDraw(...); // call imported API via PLT at 0x94bd48
    wgpuRenderPipelineRelease(...); // call imported API via PLT at 0x94bd50
    wgpuBindGroupRelease(...); // call imported API via PLT at 0x94bd58
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x94bd88
    sub_94BB40(...); // call internal func at 0x94bd90
}
