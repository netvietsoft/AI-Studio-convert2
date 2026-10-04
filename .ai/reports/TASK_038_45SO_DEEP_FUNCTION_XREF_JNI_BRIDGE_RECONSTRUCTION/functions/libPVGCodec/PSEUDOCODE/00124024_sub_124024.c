// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x124024
// Recovered Name: sub_124024
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x124024 | Size: 520 bytes | SHA256: a4460d3c6724a50af27be25f1b011e871f7b0fb13ab2576c14e1743fc95bb59c
// Callers: 0 | Callees: 3 | Imports: 7

// Dynamic Registration: native_setListener(JZ)I (table at 0x13a9a0)
// Calls external APIs: _ZN3PVG18PVGFormatTranscode19setProgressListenerEPNS_11PVGListenerE, _ZN3PVG19logCallbackInternalEiPKcz, _ZN3PVG6PVGRef7releaseEv, _ZdlPv, _Znwm, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "%s/%s: F[%s, L(%d)], T(%p):> listener setObj failed"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> listener setObj failed"
//   "JNIPVGFormatTranscode_native_setListener"

jlong sub_124024(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 130 instructions
    /* 0x124024 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x124028 */ str x21, [sp, #0x10];
    /* 0x12402c */ stp x20, x19, [sp, #0x20];
    /* 0x124030 */ mov x29, sp;
    /* 0x124034 */ cbz x2, #0x124090;
    /* 0x124038 */ tst w3, #0xff;
    /* 0x12403c */ b.eq #0x124140;
    /* 0x124040 */ mov w0, #0x70;
    /* 0x124044 */ mov x21, x1;
    /* 0x124048 */ mov x20, x2;
    _Znwm();
    sub_11c7b8();
    sub_11cc8c();
    _ZN3PVG18PVGFormatTranscode19setProgressListenerEPNS_11PVGListenerE();
    _ZN3PVG6PVGRef7releaseEv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
    _ZN3PVG18PVGFormatTranscode19setProgressListenerEPNS_11PVGListenerE();
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
