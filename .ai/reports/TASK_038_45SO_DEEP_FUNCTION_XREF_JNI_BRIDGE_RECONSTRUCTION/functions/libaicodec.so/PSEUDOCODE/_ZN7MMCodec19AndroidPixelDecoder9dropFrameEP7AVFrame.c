// Function: MMCodec::AndroidPixelDecoder::dropFrame(AVFrame*)
// RVA: 0x1021f8, Size: 124 bytes
int64_t _ZN7MMCodec19AndroidPixelDecoder9dropFrameEP7AVFrame(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x10223c
    _ZN7_JNIEnv13CallIntMethodEP8_jobjectP10_jmethodIDz(...); // call imported API via PLT at 0x102254
    _ZdlPv(...); // call imported API via PLT at 0x10225c
    av_frame_unref(...); // call imported API via PLT at 0x102270
}
