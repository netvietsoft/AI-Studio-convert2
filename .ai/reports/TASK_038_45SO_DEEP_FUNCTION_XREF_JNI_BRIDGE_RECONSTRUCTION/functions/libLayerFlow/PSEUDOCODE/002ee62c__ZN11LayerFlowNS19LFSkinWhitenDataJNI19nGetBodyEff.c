// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee62c
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetBodyEffectStepsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee62c | Size: 128 bytes | SHA256: 3772565abf077db197be9452b44264a5d6d894df1f2b69cac5793768afec7247
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetBodyEffectSteps(J)[I (table at 0x539840)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetBodyEffectStepsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x2ee62c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2ee630 */ str x23, [sp, #0x10];
    /* 0x2ee634 */ stp x22, x21, [sp, #0x20];
    /* 0x2ee638 */ stp x20, x19, [sp, #0x30];
    /* 0x2ee63c */ mov x29, sp;
    /* 0x2ee640 */ ldp x23, x22, [x2, #0x98];
    /* 0x2ee644 */ mov x20, x2;
    /* 0x2ee648 */ ldr x8, [x0];
    /* 0x2ee64c */ mov x19, x0;
    /* 0x2ee650 */ subs x9, x22, x23;
    /* 0x2ee654 */ ldr x8, [x8, #0x598];
    return x0;
}
