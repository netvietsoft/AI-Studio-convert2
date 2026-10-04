// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dec4c
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dec4c | Size: 48 bytes | SHA256: 2b757147b615acdc357898bbcee3962a21fbad24349d29c1b7b4829e0f5f4aa0
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nClearFaceData(J)V (table at 0x537720)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI14nClearFaceDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2dec4c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2dec50 */ str x19, [sp, #0x10];
    /* 0x2dec54 */ mov x29, sp;
    /* 0x2dec58 */ mov x19, x2;
    /* 0x2dec5c */ ldr x1, [x19, #0x30]!;
    /* 0x2dec60 */ sub x0, x19, #8;
    sub_2e0b94();
    /* 0x2dec68 */ stp x19, xzr, [x19, #-8];
    /* 0x2dec6c */ str xzr, [x19, #8];
    /* 0x2dec70 */ ldr x19, [sp, #0x10];
    /* 0x2dec74 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
