// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddca0
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddca0 | Size: 76 bytes | SHA256: 0bc7d2afb3af853fb5c606d4d1541827f8bb28104d97535e117e2de3e7bb2fa4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFaceIdsFromFaceMaps(J)[I (table at 0x537150)

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2ddca0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddca4 */ stp x20, x19, [sp, #0x10];
    /* 0x2ddca8 */ mov x29, sp;
    /* 0x2ddcac */ ldr x8, [x0];
    /* 0x2ddcb0 */ ldr w1, [x2, #0x38];
    /* 0x2ddcb4 */ mov x19, x0;
    /* 0x2ddcb8 */ ldr x8, [x8, #0x598];
    /* 0x2ddcbc */ blr x8;
    /* 0x2ddcc0 */ ldr x8, [x19];
    /* 0x2ddcc4 */ mov x20, x0;
    /* 0x2ddcc8 */ mov x0, x19;
    return x0;
}
