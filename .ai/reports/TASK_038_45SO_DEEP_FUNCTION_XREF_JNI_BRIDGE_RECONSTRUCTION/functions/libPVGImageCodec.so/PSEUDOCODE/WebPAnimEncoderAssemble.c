// Function: WebPAnimEncoderAssemble
// RVA: 0x4933c8, Size: 564 bytes
int64_t WebPAnimEncoderAssemble(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_491740(...); // call internal at 0x4933f4
    const char* str = "ERROR assembling: NULL input";
    sub_492604(...); // call internal at 0x493410
    const char* str = "ERROR: No frames to assemble";
    sub_492604(...); // call internal at 0x493438
    sub_49266C(...); // call internal at 0x4934c0
    sub_492A28(...); // call internal at 0x4934ec
    WebPMuxSetCanvasSize(...); // call PLT API at 0x493520
    WebPMuxSetAnimationParams(...); // call PLT API at 0x493548
    WebPMuxAssemble(...); // call PLT API at 0x49356c
    sub_4935FC(...); // call internal at 0x4935a4
    const char* str = "ERROR assembling WebP";
    sub_493828(...); // call internal at 0x4935e0
    return a0;
}
