// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d2b50
// Recovered Name: _ZN11LayerFlowNS15CLFNetHeaderJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d2b50 | Size: 72 bytes | SHA256: 31b127073ee5337477d89aa15079580cf2a044a27c36f545c532aad80986d72b
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x541e38)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS15CLFNetHeaderJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x3d2b50 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3d2b54 */ mov x29, sp;
    /* 0x3d2b58 */ mov w0, #0x120;
    _Znwm();
    /* 0x3d2b60 */ movi v0.2d, #0000000000000000;
    /* 0x3d2b64 */ add x8, x0, #0x110;
    /* 0x3d2b68 */ stp xzr, xzr, [x0, #0x110];
    /* 0x3d2b6c */ stp xzr, x8, [x0, #0x100];
    /* 0x3d2b70 */ stp q0, q0, [x0];
    /* 0x3d2b74 */ stp q0, q0, [x0, #0x20];
    /* 0x3d2b78 */ stp q0, q0, [x0, #0x40];
    return x0;
}
