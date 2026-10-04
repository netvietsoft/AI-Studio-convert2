// Reconstructed Pseudocode for FN_libPVGCodec_0011D2F8 (native_setLogCallback_(Lcom/meitu/media/PVGCodec/IProcessor$LogCallback;)V)
// Library: libPVGCodec.so | RVA: 0x11D2F8 | Size: 1036B | Visibility: FACT

/* Imported APIs: _ZN3PVG9PVGGlobal11getInstanceEv;_ZN3PVG9PVGGlobal14setLogCallbackENSt6__ndk18functionIFviPKcEEE;pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz;__stack_chk_fail */
/* String XREFs: com/meitu/media/PVGCodec/IProcessor$LogCallback;log;(ILjava/lang/String;)V;JNIIProcess_native_setLogCallback;PVGCodec */

int native_setLogCallback_(Lcom/meitu/media/PVGCodec/IProcessor$LogCallback;)V(void* ctx) {
    // Function prologue: set up stack frame
    sub_12EAB4(ctx);
    _ZN3PVG9PVGGlobal11getInstanceEv(...);
    _ZN3PVG9PVGGlobal14setLogCallbackENSt6__ndk18functionIFviPKcEEE(...);
    pthread_self(...);
    __android_log_print(...);
    _ZN3PVG19logCallbackInternalEiPKcz(...);
    return 0;
}
