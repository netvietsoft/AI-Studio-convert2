// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edf00
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edf00 | Size: 144 bytes | SHA256: 00391c7f7cbb54a526b800db6578bf232f49989766ff6335e6aa7eae4fd1778a
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x5395d0)
// Calls external APIs: _ZdlPv, _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x2edf00 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2edf04 */ stp x20, x19, [sp, #0x10];
    /* 0x2edf08 */ mov x29, sp;
    /* 0x2edf0c */ ldr x8, [x2, #0x30]!;
    /* 0x2edf10 */ cbz x8, #0x2edf48;
    /* 0x2edf14 */ mov x19, x2;
    /* 0x2edf18 */ ldr w9, [x8, #0x20];
    /* 0x2edf1c */ cmp w9, w3;
    /* 0x2edf20 */ add x9, x8, #8;
    /* 0x2edf24 */ csel x9, x8, x9, ge;
    /* 0x2edf28 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    _ZN14SkinWhitenInfoC2ERKS_();
    return x0;
    _ZdlPv();
    sub_526544();
}
