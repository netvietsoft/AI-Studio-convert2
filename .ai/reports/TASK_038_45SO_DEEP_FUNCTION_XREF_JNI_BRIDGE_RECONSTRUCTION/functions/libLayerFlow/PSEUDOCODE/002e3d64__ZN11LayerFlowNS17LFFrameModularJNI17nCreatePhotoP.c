// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e3d64
// Recovered Name: _ZN11LayerFlowNS17LFFrameModularJNI17nCreatePhotoPieceEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e3d64 | Size: 36 bytes | SHA256: ea05ccfdaee672461565c87689138efbecf0e539eb3c62c17df4fc3464ad3382
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x537f30)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS17LFFrameModularJNI17nCreatePhotoPieceEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2e3d64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e3d68 */ mov x29, sp;
    /* 0x2e3d6c */ mov w0, #0x40;
    _Znwm();
    /* 0x2e3d74 */ movi v0.2d, #0000000000000000;
    /* 0x2e3d78 */ stp q0, q0, [x0];
    /* 0x2e3d7c */ stp q0, q0, [x0, #0x20];
    /* 0x2e3d80 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
