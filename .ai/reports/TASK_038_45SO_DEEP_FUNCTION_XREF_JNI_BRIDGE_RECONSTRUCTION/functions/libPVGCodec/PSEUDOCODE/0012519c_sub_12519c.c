// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x12519c
// Recovered Name: sub_12519c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x12519c | Size: 228 bytes | SHA256: 038564038228a9bce3e2e897d192937a7786e211138f98930647bd33e6bf0719
// Callers: 0 | Callees: 0 | Imports: 6

// Dynamic Registration: native_finalize(J)I (table at 0x13aa48)
// Calls external APIs: _ZN3PVG17PVGImageTranscode5closeEv, _ZN3PVG17PVGImageTranscodeD1Ev, _ZN3PVG19logCallbackInternalEiPKcz, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "%s/%s: F[%s, L(%d)], T(%p):> get null native object"
//   "F[%s, L(%d)], T(%p):> get null native object"
//   "JNIPVGImageTranscode_native_finalize"
//   "PVGCodec"

jlong sub_12519c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x12519c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1251a0 */ str x19, [sp, #0x10];
    /* 0x1251a4 */ mov x29, sp;
    /* 0x1251a8 */ cbz x2, #0x1251d8;
    /* 0x1251ac */ mov x0, x2;
    /* 0x1251b0 */ mov x19, x2;
    _ZN3PVG17PVGImageTranscode5closeEv();
    /* 0x1251b8 */ mov x0, x19;
    _ZN3PVG17PVGImageTranscodeD1Ev();
    /* 0x1251c0 */ mov x0, x19;
    _ZdlPv();
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    _ZN3PVG19logCallbackInternalEiPKcz();
    return x0;
}
