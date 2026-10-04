// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c28a4
// Recovered Name: _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c28a4 | Size: 212 bytes | SHA256: ed735fc0bc3066af3bd0a9fd9cca7f08cb23c7215e291c40bb7f4fa189d2c9b2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFaceIdsFromFaceMaps(J)[I (table at 0x5321c8)

jobject _ZN11LayerFlowNS25LFAutoWrinkleCleanDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x2c28a4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c28a8 */ str x21, [sp, #0x10];
    /* 0x2c28ac */ stp x20, x19, [sp, #0x20];
    /* 0x2c28b0 */ mov x29, sp;
    /* 0x2c28b4 */ ldr x8, [x0];
    /* 0x2c28b8 */ ldr w1, [x2, #0x30];
    /* 0x2c28bc */ mov x21, x2;
    /* 0x2c28c0 */ mov x19, x0;
    /* 0x2c28c4 */ ldr x8, [x8, #0x598];
    /* 0x2c28c8 */ blr x8;
    /* 0x2c28cc */ ldr x8, [x19];
    return x0;
}
