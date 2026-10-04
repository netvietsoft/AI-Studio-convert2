// Reconstructed Pseudocode for FN_libPVGCodec_000CA9C8 (PVG::PVGImageTranscode::transcode(std::__ndk1::basic_string<char, std::__ndk1::char_traits<char>, std::__ndk1::allocator<char>> const&))
// Library: libPVGCodec.so | RVA: 0xCA9C8 | Size: 6528B | Visibility: FACT

/* Imported APIs: _ZN8PVGIMAGE10PVGContextC1Ev;_ZN8PVGIMAGE13PVGImageCodec12dequeueFrameEPPNS_8PVGFrameE;pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz;_ZN8PVGIMAGE13PVGImageCodec12receiveFrameEPNS_8PVGFrameE;_ZNK8PVGIMAGE8PVGFrame8getWidthEv;_ZNK8PVGIMAGE8PVGFrame9getHeightEv;_ZNK8PVGIMAGE8PVGFrame9getFormatEv;_ZNK8PVGIMAGE8PVGFrame13getColorRangeEv */
/* String XREFs: PVGCodec;F[%s  L(%d)]  T(%p):> C[PVGImageTranscode(%p)]  _pvgImageCodecReader dequeueFram;transcode;%s/%s: F[%s  L(%d)]  T(%p):> C[PVGImageTranscode(%p)]  _pvgImageCodecReader dequ;PVGCodec */

int PVG__PVGImageTranscode__transcode(std____ndk1__basic_string<char,_std____ndk1__char_traits<char>,_std____ndk1__allocator<char>>_const&)(void* ctx) {
    // Function prologue: set up stack frame
    sub_6D564(ctx);
    sub_6D564(ctx);
    sub_6D564(ctx);
    sub_6D564(ctx);
    sub_CC348(ctx);
    _ZN8PVGIMAGE10PVGContextC1Ev(...);
    _ZN8PVGIMAGE13PVGImageCodec12dequeueFrameEPPNS_8PVGFrameE(...);
    pthread_self(...);
    __android_log_print(...);
    _ZN3PVG19logCallbackInternalEiPKcz(...);
    return 0;
}
