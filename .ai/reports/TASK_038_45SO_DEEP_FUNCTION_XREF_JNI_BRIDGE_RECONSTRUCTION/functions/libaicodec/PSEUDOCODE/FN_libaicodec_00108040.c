// Reconstructed Pseudocode for FN_libaicodec_00108040 (native_native_getVideoFrame_(JJ[Ljava/nio/ByteBuffer;[I[J[I[Z)I)
// Library: libaicodec.so | RVA: 0x108040 | Size: 896B | Visibility: FACT

/* Imported APIs: _ZNK7MMCodec13MTMediaReader12getMediaInfoEv;_ZN7MMCodec13MTMediaReader13getVideoFrameElNS_10ReadOptionERNS_10VideoFrameERNS_9FrameInfoE;__android_log_print;_ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz;__stack_chk_fail */
/* String XREFs: MTMV_AICodec;[%s(%d)]:> get nativeObject error;com_meitu_media_FlyMediaReader_getVideoFrame;%s/MTMV_AICodec: [%s(%d)]:> get nativeObject error;com_meitu_media_FlyMediaReader_getVideoFrame */

int native_native_getVideoFrame_(JJ[Ljava/nio/ByteBuffer;[I[J[I[Z)I(void* ctx) {
    // Function prologue: set up stack frame
    sub_CEBC4(ctx);
    sub_1F00EC(ctx);
    sub_CEBC4(ctx);
    _ZNK7MMCodec13MTMediaReader12getMediaInfoEv(...);
    _ZN7MMCodec13MTMediaReader13getVideoFrameElNS_10ReadOptionERNS_10VideoFrameERNS_9FrameInfoE(...);
    __android_log_print(...);
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...);
    __stack_chk_fail(...);
    return 0;
}
