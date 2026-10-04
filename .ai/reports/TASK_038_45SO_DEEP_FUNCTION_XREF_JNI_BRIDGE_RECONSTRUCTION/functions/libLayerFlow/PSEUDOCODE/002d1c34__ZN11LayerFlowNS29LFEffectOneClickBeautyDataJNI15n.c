// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d1c34
// Recovered Name: _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d1c34 | Size: 104 bytes | SHA256: 939c18e4991a9232b7041f236c869d5ef7e0d3213496ab54afd6120961a0cf47
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nGetInfoPointer(J)J (table at 0x5349b8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS29LFEffectOneClickBeautyDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x2d1c34 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d1c38 */ str x19, [sp, #0x10];
    /* 0x2d1c3c */ mov x29, sp;
    /* 0x2d1c40 */ mov w0, #0x60;
    /* 0x2d1c44 */ mov x19, x2;
    _Znwm();
    /* 0x2d1c4c */ ldur q0, [x19, #0x28];
    /* 0x2d1c50 */ str q0, [x0];
    /* 0x2d1c54 */ ldur q0, [x19, #0x64];
    /* 0x2d1c58 */ ldur q1, [x19, #0x58];
    /* 0x2d1c5c */ ldur q2, [x19, #0x38];
    sub_5263b0();
    return x0;
}
