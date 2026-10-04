// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1f54
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1f54 | Size: 212 bytes | SHA256: ed735fc0bc3066af3bd0a9fd9cca7f08cb23c7215e291c40bb7f4fa189d2c9b2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetFaceIdsFromFaceMaps(J)[I (table at 0x531f88)

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI20nGetKeysFromFaceMapsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x2c1f54 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2c1f58 */ str x21, [sp, #0x10];
    /* 0x2c1f5c */ stp x20, x19, [sp, #0x20];
    /* 0x2c1f60 */ mov x29, sp;
    /* 0x2c1f64 */ ldr x8, [x0];
    /* 0x2c1f68 */ ldr w1, [x2, #0x30];
    /* 0x2c1f6c */ mov x21, x2;
    /* 0x2c1f70 */ mov x19, x0;
    /* 0x2c1f74 */ ldr x8, [x8, #0x598];
    /* 0x2c1f78 */ blr x8;
    /* 0x2c1f7c */ ldr x8, [x19];
    return x0;
}
