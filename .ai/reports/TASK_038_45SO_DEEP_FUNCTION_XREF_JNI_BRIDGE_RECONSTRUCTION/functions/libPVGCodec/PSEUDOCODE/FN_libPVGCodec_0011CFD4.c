// Reconstructed Pseudocode for FN_libPVGCodec_0011CFD4 (native_setLogCallbackLevel_(I)V)
// Library: libPVGCodec.so | RVA: 0x11CFD4 | Size: 804B | Visibility: FACT

/* Imported APIs: _ZN3PVG9PVGGlobal11getInstanceEv;_ZN3PVG9PVGGlobal14setLogCallbackENSt6__ndk18functionIFviPKcEEE;pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz;__stack_chk_fail */
/* String XREFs: LogCallback;PVGCodec;F[%s  L(%d)]  T(%p):> %s get env failed;%s/%s: F[%s  L(%d)]  T(%p):> %s get env failed;PVGCodec */

int native_setLogCallbackLevel_(I)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_12B0EC(ctx);
    sub_11CF14(ctx);
    sub_12EAB4(ctx);
    _ZN3PVG9PVGGlobal11getInstanceEv(...);
    _ZN3PVG9PVGGlobal14setLogCallbackENSt6__ndk18functionIFviPKcEEE(...);
    pthread_self(...);
    __android_log_print(...);
    _ZN3PVG19logCallbackInternalEiPKcz(...);
    return 0;
}
