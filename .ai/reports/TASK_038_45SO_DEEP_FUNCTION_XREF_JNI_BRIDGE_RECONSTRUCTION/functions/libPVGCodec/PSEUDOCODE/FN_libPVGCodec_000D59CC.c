// Reconstructed Pseudocode for FN_libPVGCodec_000D59CC (PVG::PVGMaskTranscode::PVGSetProgressListener(void (*)(void*), void (*)(void*), void (*)(void*, double, double), void (*)(void*, double, double), void (*)(void*)))
// Library: libPVGCodec.so | RVA: 0xD59CC | Size: 516B | Visibility: FACT

/* Imported APIs: pthread_self;__android_log_print;_ZN3PVG19logCallbackInternalEiPKcz;_Znwm;_ZN3PVG6PVGRefC2Ev;_ZdlPv;_ZNSt6__ndk119__thread_local_dataEv;pthread_setspecific;_ZNSt6__ndk115__thread_structD1Ev;__stack_chk_fail */
/* String XREFs: PVGCodec;F[%s  L(%d)]  T(%p):> PVG Processing Listener is already create!;PVGSetProgressListener;%s/%s: F[%s  L(%d)]  T(%p):> PVG Processing Listener is already create!;PVGCodec */

int PVG__PVGMaskTranscode__PVGSetProgressListener(void_(*)(void*),_void_(*)(void*),_void_(*)(void*,_double,_double),_void_(*)(void*,_double,_double),_void_(*)(void*))(void* ctx) {
    // Function prologue: set up stack frame
    sub_12EAB4(ctx);
    sub_D5BD0(ctx);
    sub_12EAB4(ctx);
    pthread_self(...);
    __android_log_print(...);
    _ZN3PVG19logCallbackInternalEiPKcz(...);
    _Znwm(...);
    _ZN3PVG6PVGRefC2Ev(...);
    return 0;
}
