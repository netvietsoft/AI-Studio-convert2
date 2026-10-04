// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee5c4
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetWakeSkinPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee5c4 | Size: 68 bytes | SHA256: 31324f9009bda7839e43638f028a5853753d2a7c333955310eb26c7352356df0
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetWakeSkinPointer(J)J (table at 0x539810)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetWakeSkinPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x2ee5c4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ee5c8 */ str x19, [sp, #0x10];
    /* 0x2ee5cc */ mov x29, sp;
    /* 0x2ee5d0 */ mov w0, #0x58;
    /* 0x2ee5d4 */ mov x19, x2;
    _Znwm();
    /* 0x2ee5dc */ ldp q0, q1, [x19, #0x10];
    /* 0x2ee5e0 */ stp q0, q1, [x0];
    /* 0x2ee5e4 */ ldp q1, q0, [x19, #0x40];
    /* 0x2ee5e8 */ ldr x8, [x19, #0x60];
    /* 0x2ee5ec */ ldr q2, [x19, #0x30];
    return x0;
}
