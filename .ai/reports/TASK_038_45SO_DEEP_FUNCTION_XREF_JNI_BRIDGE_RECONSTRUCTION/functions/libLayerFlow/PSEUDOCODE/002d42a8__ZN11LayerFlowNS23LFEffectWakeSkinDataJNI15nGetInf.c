// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d42a8
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d42a8 | Size: 156 bytes | SHA256: e388bdb917ee83ef21f38ea234eb830cd3b145c3d7729f6198aeeb126c0e7423
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nGetInfoPointer(J)J (table at 0x5356d8)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x2d42a8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d42ac */ stp x20, x19, [sp, #0x10];
    /* 0x2d42b0 */ mov x29, sp;
    /* 0x2d42b4 */ mov w0, #0x80;
    /* 0x2d42b8 */ mov x19, x2;
    _Znwm();
    /* 0x2d42c0 */ mov x8, x19;
    /* 0x2d42c4 */ mov x20, x0;
    /* 0x2d42c8 */ ldrb w9, [x8, #0x28]!;
    /* 0x2d42cc */ tbnz w9, #0, #0x2d42e4;
    /* 0x2d42d0 */ ldr x9, [x8, #0x10];
    sub_2bc260();
    return x0;
    _ZdlPv();
    sub_526544();
}
