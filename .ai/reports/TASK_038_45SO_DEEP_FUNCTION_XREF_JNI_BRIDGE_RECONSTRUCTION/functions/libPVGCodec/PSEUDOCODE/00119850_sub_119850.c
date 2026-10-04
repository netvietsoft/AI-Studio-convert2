// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x119850
// Recovered Name: sub_119850
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x119850 | Size: 520 bytes | SHA256: f9ca201d47f79283e021efff8a7942ca60ebfc17d20e21def4cdada91c28cbd7
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13a0d8)
// Calls external APIs: _ZN3PVG17PVGAudioExtractor19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIAudioExtractor_native_setListener"

jlong sub_119850(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x119850 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x119854 */ str x21, [sp, #0x10];
    /* 0x119858 */ stp x20, x19, [sp, #0x20];
    /* 0x11985c */ mov x29, sp;
    /* 0x119860 */ cbz x2, #0x1198bc;
    /* 0x119864 */ tst w3, #0xff;
    /* 0x119868 */ b.eq #0x11996c;
    /* 0x11986c */ mov w0, #0x70;
    /* 0x119870 */ mov x21, x1;
    /* 0x119874 */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG17PVGAudioExtractor19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG17PVGAudioExtractor19setProgressListenerEPNS_11PVGListenerE();
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
