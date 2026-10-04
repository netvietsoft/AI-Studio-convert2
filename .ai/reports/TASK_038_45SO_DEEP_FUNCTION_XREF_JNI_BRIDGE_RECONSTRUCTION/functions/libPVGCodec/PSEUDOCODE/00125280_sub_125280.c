// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x125280
// Recovered Name: sub_125280
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x125280 | Size: 520 bytes | SHA256: cdec07af9c9c6a1ce57058c991dc038416dace0e6b555a60692fe7fa627fb273
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13aa60)
// Calls external APIs: _ZN3PVG17PVGImageTranscode19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIPVGImageTranscode_native_setListener"

jlong sub_125280(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x125280 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x125284 */ str x21, [sp, #0x10];
    /* 0x125288 */ stp x20, x19, [sp, #0x20];
    /* 0x12528c */ mov x29, sp;
    /* 0x125290 */ cbz x2, #0x1252ec;
    /* 0x125294 */ tst w3, #0xff;
    /* 0x125298 */ b.eq #0x12539c;
    /* 0x12529c */ mov w0, #0x70;
    /* 0x1252a0 */ mov x21, x1;
    /* 0x1252a4 */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG17PVGImageTranscode19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG17PVGImageTranscode19setProgressListenerEPNS_11PVGListenerE();
    return x0;
    _ZN3PVG6PVGRef7releaseEv();
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZdlPv();
    sub_12eab4();
}
