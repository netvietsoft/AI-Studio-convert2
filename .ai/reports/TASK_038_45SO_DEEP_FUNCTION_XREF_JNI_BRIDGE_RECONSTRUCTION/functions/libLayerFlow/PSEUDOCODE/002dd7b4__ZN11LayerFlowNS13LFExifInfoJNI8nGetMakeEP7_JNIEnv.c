// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dd7b4
// Recovered Name: _ZN11LayerFlowNS13LFExifInfoJNI8nGetMakeEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dd7b4 | Size: 40 bytes | SHA256: bc62d7aa0f8001318d32cd2ddabe918be6345384e7ef97860e253b7a0e1a4572
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetMake(J)Ljava/lang/String; (table at 0x537060)

jobject _ZN11LayerFlowNS13LFExifInfoJNI8nGetMakeEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2dd7b4 */ cbz x2, #0x2dd7d4;
    /* 0x2dd7b8 */ ldrb w8, [x2];
    /* 0x2dd7bc */ ldr x9, [x2, #0x10];
    /* 0x2dd7c0 */ ldr x10, [x0];
    /* 0x2dd7c4 */ tst w8, #1;
    /* 0x2dd7c8 */ csinc x1, x9, x2, ne;
    /* 0x2dd7cc */ ldr x2, [x10, #0x538];
    /* 0x2dd7d0 */ br x2;
    /* 0x2dd7d4 */ mov x0, xzr;
    return x0;
}
