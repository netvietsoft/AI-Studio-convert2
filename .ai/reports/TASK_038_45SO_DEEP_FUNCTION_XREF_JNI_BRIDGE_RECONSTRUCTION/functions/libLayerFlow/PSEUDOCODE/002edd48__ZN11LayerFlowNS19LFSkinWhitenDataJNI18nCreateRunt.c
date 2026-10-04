// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2edd48
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI18nCreateRuntimeDataEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2edd48 | Size: 28 bytes | SHA256: c6a1efec65ac43af5759cb7e2ec2a2f146e305a192f717f20c3b664b96f60de3
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x539510)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI18nCreateRuntimeDataEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x2edd48 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2edd4c */ mov x29, sp;
    /* 0x2edd50 */ mov w0, #1;
    _Znwm();
    /* 0x2edd58 */ strb wzr, [x0];
    /* 0x2edd5c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
