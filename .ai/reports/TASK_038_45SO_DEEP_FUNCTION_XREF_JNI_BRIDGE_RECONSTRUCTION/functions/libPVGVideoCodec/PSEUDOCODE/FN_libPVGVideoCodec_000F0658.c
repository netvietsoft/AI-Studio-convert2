// Reconstructed Pseudocode for FN_libPVGVideoCodec_000F0658 (sub_F0658)
// Library: libPVGVideoCodec.so | RVA: 0xF0658 | Size: 9308B | Visibility: HIGH_CONFIDENCE

/* Imported APIs: pthread_self;__android_log_print;_ZdlPv;_ZNSt6__ndk15mutex4lockEv;_ZNSt6__ndk15mutex6unlockEv;_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc;_ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc;strlen;_Znwm;memmove */
/* String XREFs: PVGVideoAVICodec;[%s(%d)]:> (%ld):> [>>>start]index:%dMediaHandleContext:%p  stream:%p  frame que;androidMediaDecodeThread;%s/PVGVideoAVICodec: [%s(%d)]:> (%ld):> [>>>start]index:%dMediaHandleContext:%p ;androidMediaDecodeThread */

int sub_F0658(void* ctx) {
    // Function prologue: set up stack frame
    sub_D5218(ctx);
    sub_D66F8(ctx);
    sub_B15B8(ctx);
    sub_D66F8(ctx);
    sub_B0F58(ctx);
    pthread_self(...);
    __android_log_print(...);
    _ZdlPv(...);
    _ZNSt6__ndk15mutex4lockEv(...);
    _ZNSt6__ndk15mutex6unlockEv(...);
    return 0;
}
