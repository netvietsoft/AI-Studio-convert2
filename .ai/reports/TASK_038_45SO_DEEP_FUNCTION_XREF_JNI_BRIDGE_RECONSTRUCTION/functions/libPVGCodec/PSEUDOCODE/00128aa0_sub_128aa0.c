// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x128aa0
// Recovered Name: sub_128aa0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x128aa0 | Size: 520 bytes | SHA256: cfc8c6518393253c7946cc5349f5182c34ecac83b47026d7da392e0ecb9091ed
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13ac10)
// Calls external APIs: _ZN3PVG15PVGVideoToImage19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIPVGVideoToImage_native_setListener"

jlong sub_128aa0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x128aa0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x128aa4 */ str x21, [sp, #0x10];
    /* 0x128aa8 */ stp x20, x19, [sp, #0x20];
    /* 0x128aac */ mov x29, sp;
    /* 0x128ab0 */ cbz x2, #0x128b0c;
    /* 0x128ab4 */ tst w3, #0xff;
    /* 0x128ab8 */ b.eq #0x128bbc;
    /* 0x128abc */ mov w0, #0x70;
    /* 0x128ac0 */ mov x21, x1;
    /* 0x128ac4 */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG15PVGVideoToImage19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG15PVGVideoToImage19setProgressListenerEPNS_11PVGListenerE();
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
