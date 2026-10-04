// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ddf2c
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ddf2c | Size: 48 bytes | SHA256: 977ebfd0bd8a6b5b8c1420620db1d8791847289671da6c532bf7db83fa9f091f
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nClearFaceData(J)V (table at 0x5371b0)

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2ddf2c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ddf30 */ str x19, [sp, #0x10];
    /* 0x2ddf34 */ mov x29, sp;
    /* 0x2ddf38 */ mov x19, x2;
    /* 0x2ddf3c */ ldr x1, [x19, #0x30]!;
    /* 0x2ddf40 */ sub x0, x19, #8;
    sub_2de5dc();
    /* 0x2ddf48 */ stp x19, xzr, [x19, #-8];
    /* 0x2ddf4c */ str xzr, [x19, #8];
    /* 0x2ddf50 */ ldr x19, [sp, #0x10];
    /* 0x2ddf54 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
