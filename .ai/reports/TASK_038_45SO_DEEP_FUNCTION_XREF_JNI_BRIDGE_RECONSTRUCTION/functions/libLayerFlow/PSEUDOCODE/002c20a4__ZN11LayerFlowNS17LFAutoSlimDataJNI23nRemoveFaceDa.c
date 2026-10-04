// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c20a4
// Recovered Name: _ZN11LayerFlowNS17LFAutoSlimDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c20a4 | Size: 196 bytes | SHA256: d60de77a49021f73c6db6cb69637d882f581e1655c5cf82112a4163d00d3ef8c
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nRemoveFaceDataByFaceId(JI)V (table at 0x531fb8)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS17LFAutoSlimDataJNI23nRemoveFaceDataByFaceIdEP7_JNIEnvP7_jclassli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x2c20a4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c20a8 */ str x19, [sp, #0x10];
    /* 0x2c20ac */ mov x29, sp;
    /* 0x2c20b0 */ mov x8, x2;
    /* 0x2c20b4 */ ldr x0, [x8, #0x28]!;
    /* 0x2c20b8 */ cbz x0, #0x2c20f8;
    /* 0x2c20bc */ mov x9, x8;
    /* 0x2c20c0 */ mov x10, x0;
    /* 0x2c20c4 */ ldr w11, [x10, #0x1c];
    /* 0x2c20c8 */ cmp w11, w3;
    /* 0x2c20cc */ add x11, x10, #8;
    return x0;
    sub_2c23f4();
}
