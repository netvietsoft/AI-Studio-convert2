// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1299a8
// Recovered Name: sub_1299a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1299a8 | Size: 520 bytes | SHA256: b3fba59c2062d9accb97ef7f1b6da92dadd47e06a8edfc420660b0bef0d02f13
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13acb8)
// Calls external APIs: _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIPVGWaterMark_native_setListener"

jlong sub_1299a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x1299a8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1299ac */ str x21, [sp, #0x10];
    /* 0x1299b0 */ stp x20, x19, [sp, #0x20];
    /* 0x1299b4 */ mov x29, sp;
    /* 0x1299b8 */ cbz x2, #0x129a14;
    /* 0x1299bc */ tst w3, #0xff;
    /* 0x1299c0 */ b.eq #0x129ac4;
    /* 0x1299c4 */ mov w0, #0x70;
    /* 0x1299c8 */ mov x21, x1;
    /* 0x1299cc */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG12PVGWaterMark19setProgressListenerEPNS_11PVGListenerE();
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
