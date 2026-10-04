// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e84f8
// Recovered Name: _ZN11LayerFlowNS18LFMakeUpModularJNI14nClearFaceDataEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e84f8 | Size: 48 bytes | SHA256: 1702fef969accab915613a5ca98745ab52db82e92ebd52267af1b885f932257a
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nClearFaceData(J)V (table at 0x538ba8)

jobject _ZN11LayerFlowNS18LFMakeUpModularJNI14nClearFaceDataEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x2e84f8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e84fc */ str x19, [sp, #0x10];
    /* 0x2e8500 */ mov x29, sp;
    /* 0x2e8504 */ mov x19, x2;
    /* 0x2e8508 */ ldr x1, [x19, #0x30]!;
    /* 0x2e850c */ sub x0, x19, #8;
    sub_2ea590();
    /* 0x2e8514 */ stp x19, xzr, [x19, #-8];
    /* 0x2e8518 */ str xzr, [x19, #8];
    /* 0x2e851c */ ldr x19, [sp, #0x10];
    /* 0x2e8520 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
