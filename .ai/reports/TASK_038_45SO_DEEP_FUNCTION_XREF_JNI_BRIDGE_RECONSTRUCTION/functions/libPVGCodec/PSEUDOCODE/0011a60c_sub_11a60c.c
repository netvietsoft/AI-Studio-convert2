// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x11a60c
// Recovered Name: sub_11a60c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x11a60c | Size: 520 bytes | SHA256: cac9c7e7c7820891e41e0500507cd8ec7310a0a220eaea5d17fafb69911dd57d
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13a168)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG22PVGAudioNoiseReduction19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIAudioNoiseReduction_native_setListener"

jlong sub_11a60c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x11a60c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x11a610 */ str x21, [sp, #0x10];
    /* 0x11a614 */ stp x20, x19, [sp, #0x20];
    /* 0x11a618 */ mov x29, sp;
    /* 0x11a61c */ cbz x2, #0x11a678;
    /* 0x11a620 */ tst w3, #0xff;
    /* 0x11a624 */ b.eq #0x11a728;
    /* 0x11a628 */ mov w0, #0x70;
    /* 0x11a62c */ mov x21, x1;
    /* 0x11a630 */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG22PVGAudioNoiseReduction19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG22PVGAudioNoiseReduction19setProgressListenerEPNS_11PVGListenerE();
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
