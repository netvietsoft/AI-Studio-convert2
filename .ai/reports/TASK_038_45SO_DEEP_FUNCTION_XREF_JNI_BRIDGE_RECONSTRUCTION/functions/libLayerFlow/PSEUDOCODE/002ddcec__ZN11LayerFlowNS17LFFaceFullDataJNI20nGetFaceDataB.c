// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddcec
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddcec | Size: 132 bytes | SHA256: 7f2176e4b017c467240c8b10507e83240bba0a20a293e7c423c752e1371946d3
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetFaceDataByFaceId(JI)J (table at 0x537168)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI20nGetFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x2ddcec */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddcf0 */ str x19, [sp, #0x10];
    /* 0x2ddcf4 */ mov x29, sp;
    /* 0x2ddcf8 */ ldr x8, [x2, #0x30]!;
    /* 0x2ddcfc */ cbz x8, #0x2ddd34;
    /* 0x2ddd00 */ mov x19, x2;
    /* 0x2ddd04 */ ldr w9, [x8, #0x1c];
    /* 0x2ddd08 */ cmp w9, w3;
    /* 0x2ddd0c */ add x9, x8, #8;
    /* 0x2ddd10 */ csel x9, x8, x9, ge;
    /* 0x2ddd14 */ csel x19, x8, x19, ge;
    return x0;
    _Znwm();
    return x0;
}
