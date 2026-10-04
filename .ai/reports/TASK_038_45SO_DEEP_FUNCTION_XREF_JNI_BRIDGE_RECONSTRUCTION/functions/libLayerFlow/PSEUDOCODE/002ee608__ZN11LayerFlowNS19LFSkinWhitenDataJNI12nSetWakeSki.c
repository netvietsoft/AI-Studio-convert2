// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee608
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nSetWakeSkinEP7_JNIEnvP7_jclassll
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee608 | Size: 36 bytes | SHA256: f36ad315fab9ae0ef4ec01ba868b56a4eff62a72c7df07bcd469ad2949be64a9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetWakeSkin(JJ)V (table at 0x539828)

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI12nSetWakeSkinEP7_JNIEnvP7_jclassll(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2ee608 */ ldp q1, q0, [x3];
    /* 0x2ee60c */ stp q1, q0, [x2, #0x10];
    /* 0x2ee610 */ ldp q2, q0, [x3, #0x30];
    /* 0x2ee614 */ ldr x8, [x3, #0x50];
    /* 0x2ee618 */ ldr q1, [x3, #0x20];
    /* 0x2ee61c */ str x8, [x2, #0x60];
    /* 0x2ee620 */ stp q2, q0, [x2, #0x40];
    /* 0x2ee624 */ str q1, [x2, #0x30];
    return x0;
}
