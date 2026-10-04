// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8d6c
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI27nGetFaceRegionSwitchPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8d6c | Size: 52 bytes | SHA256: 05c02c1ab07ba82b813fb1c170054fe9797b9dd6be7df74605e887356a7be88a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetFaceRegionSwitchPointer(J)J (table at 0x533200)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI27nGetFaceRegionSwitchPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2c8d6c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c8d70 */ str x19, [sp, #0x10];
    /* 0x2c8d74 */ mov x29, sp;
    /* 0x2c8d78 */ mov w0, #5;
    /* 0x2c8d7c */ mov x19, x2;
    _Znwm();
    /* 0x2c8d84 */ ldr w8, [x19];
    /* 0x2c8d88 */ ldrb w9, [x19, #4];
    /* 0x2c8d8c */ str w8, [x0];
    /* 0x2c8d90 */ strb w9, [x0, #4];
    /* 0x2c8d94 */ ldr x19, [sp, #0x10];
    return x0;
}
