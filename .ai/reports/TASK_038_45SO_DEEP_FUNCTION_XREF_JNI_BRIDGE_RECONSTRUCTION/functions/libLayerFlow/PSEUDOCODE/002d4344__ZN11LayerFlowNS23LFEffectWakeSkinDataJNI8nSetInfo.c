// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d4344
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI8nSetInfoEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d4344 | Size: 92 bytes | SHA256: ad6010a08d6da982b174b050e9f6f5e5d864ea3930e7077c1f39dd40be482178
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nSetInfo(JJ)V (table at 0x5356f0)
// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI8nSetInfoEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2d4344 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d4348 */ stp x20, x19, [sp, #0x10];
    /* 0x2d434c */ mov x29, sp;
    /* 0x2d4350 */ add x0, x2, #0x28;
    /* 0x2d4354 */ mov x1, x3;
    /* 0x2d4358 */ mov x19, x3;
    /* 0x2d435c */ mov x20, x2;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    /* 0x2d4364 */ ldur q0, [x19, #0x18];
    /* 0x2d4368 */ ldur q1, [x19, #0x28];
    /* 0x2d436c */ ldur q2, [x19, #0x38];
    return x0;
}
