// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bda20
// Recovered Name: _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI14nSetStartColorEP7_JNIEnvP8_jobjectli
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bda20 | Size: 132 bytes | SHA256: ce75357635fbd48f89639587b5d16d73857f86975a835833b4696d97bec6cef9
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetStartColor(JI)V (table at 0x53fef8)

jobject _ZN11LayerFlowNS28LFBgBeautifyAutoColorInfoJNI14nSetStartColorEP7_JNIEnvP8_jobjectli(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x3bda20 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x3bda24 */ stp x20, x19, [sp, #0x10];
    /* 0x3bda28 */ mov x29, sp;
    /* 0x3bda2c */ ldp x8, x9, [x2];
    /* 0x3bda30 */ mov w19, w3;
    /* 0x3bda34 */ sub x9, x9, x8;
    /* 0x3bda38 */ asr x10, x9, #2;
    /* 0x3bda3c */ cmp x10, #3;
    /* 0x3bda40 */ b.hi #0x3bda60;
    /* 0x3bda44 */ mov w8, #4;
    /* 0x3bda48 */ mov x0, x2;
    sub_2c5ac4();
    return x0;
}
