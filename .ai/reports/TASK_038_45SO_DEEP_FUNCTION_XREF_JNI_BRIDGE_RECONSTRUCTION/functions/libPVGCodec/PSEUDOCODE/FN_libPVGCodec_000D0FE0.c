// Reconstructed Pseudocode for FN_libPVGCodec_000D0FE0 (PVG::PVGMaskTranscode::audio_encode_thread(PVG::PVGMaskTranscode*))
// Library: libPVGCodec.so | RVA: 0xD0FE0 | Size: 2516B | Visibility: FACT

/* Imported APIs: _ZNSt6__ndk15mutex4lockEv;puts;_ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE;_ZNSt6__ndk15mutex6unlockEv;_Znwm;memset;printf;_ZNK8PVGVIDEO13PVGAudioFrame12getSamplesNbEv;memmove;_ZN8PVGVIDEO14PVGPCMTransferC1Ev */
/* String XREFs: _pvgVideoCodecReader is nullptr;_pvgVideoCodecReader dequeue audio frame falied (error code:%d);[PVGVideo2Pass(%p)]  Pass 1 failed;audio encode thread pause;audio process end */

int PVG__PVGMaskTranscode__audio_encode_thread(PVG__PVGMaskTranscode*)(void* ctx) {
    // Function prologue: set up stack frame
    sub_7540C(ctx);
    sub_7540C(ctx);
    sub_7540C(ctx);
    sub_12EAB4(ctx);
    _ZNSt6__ndk15mutex4lockEv(...);
    puts(...);
    _ZNSt6__ndk118condition_variable4waitERNS_11unique_lockINS_5mutexEEE(...);
    _ZNSt6__ndk15mutex6unlockEv(...);
    _Znwm(...);
    return 0;
}
