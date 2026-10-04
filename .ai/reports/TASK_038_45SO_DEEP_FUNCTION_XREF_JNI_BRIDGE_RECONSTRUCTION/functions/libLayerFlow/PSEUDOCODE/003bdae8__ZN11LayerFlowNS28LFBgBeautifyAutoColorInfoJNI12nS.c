// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bdae8
// Recovered Name: _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI12nSetEndColorEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bdae8 | Size: 132 bytes | SHA256: d6e748d96c3b1826a01296e3459e84c9f39700832584aba913d23771354fd7b4
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetEndColor(JI)V (table at 0x53ff28)

jobject _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI12nSetEndColorEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x3bdae8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3bdaec */ stp x20, x19, [sp, #0x10];
    /* 0x3bdaf0 */ mov x29, sp;
    /* 0x3bdaf4 */ mov x20, x2;
    /* 0x3bdaf8 */ mov w19, w3;
    /* 0x3bdafc */ ldp x8, x9, [x20, #0x18]!;
    /* 0x3bdb00 */ sub x10, x9, x8;
    /* 0x3bdb04 */ asr x9, x10, #2;
    /* 0x3bdb08 */ cmp x9, #3;
    /* 0x3bdb0c */ b.hi #0x3bdb28;
    /* 0x3bdb10 */ mov w8, #4;
    sub_2c5ac4();
    return x0;
}
