// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x121fd8
// Recovered Name: sub_121fd8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x121fd8 | Size: 520 bytes | SHA256: f618d7297f7a378b83806d3c965eac00d61bee3bcbbddce198a625092c11af62
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13a898)
// Calls external APIs: _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZN3PVG8PVGCodec19setProgressListenerEPNS_11PVGListenerE, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIPVGCodec_native_setListener"

jlong sub_121fd8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x121fd8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x121fdc */ str x21, [sp, #0x10];
    /* 0x121fe0 */ stp x20, x19, [sp, #0x20];
    /* 0x121fe4 */ mov x29, sp;
    /* 0x121fe8 */ cbz x2, #0x122044;
    /* 0x121fec */ tst w3, #0xff;
    /* 0x121ff0 */ b.eq #0x1220f4;
    /* 0x121ff4 */ mov w0, #0x70;
    /* 0x121ff8 */ mov x21, x1;
    /* 0x121ffc */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG8PVGCodec19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG8PVGCodec19setProgressListenerEPNS_11PVGListenerE();
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
