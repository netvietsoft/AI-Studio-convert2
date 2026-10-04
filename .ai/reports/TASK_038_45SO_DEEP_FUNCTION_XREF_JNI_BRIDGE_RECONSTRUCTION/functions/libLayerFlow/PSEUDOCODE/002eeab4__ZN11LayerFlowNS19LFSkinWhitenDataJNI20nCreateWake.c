// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eeab4
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nCreateWakeSkinParamEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eeab4 | Size: 116 bytes | SHA256: c36e871de9fd949f07f1413f79225bda405cffa5d5629a3f7c4d6563ecab941a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x539930)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nCreateWakeSkinParam is called, addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nCreateWakeSkinParamEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x2eeab4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eeab8 */ str x19, [sp, #0x10];
    /* 0x2eeabc */ mov x29, sp;
    /* 0x2eeac0 */ mov w0, #0x58;
    _Znwm();
    /* 0x2eeac8 */ movi v0.2d, #0000000000000000;
    /* 0x2eeacc */ mov w8, #-1;
    /* 0x2eead0 */ mov x19, x0;
    /* 0x2eead4 */ str w8, [x0];
    /* 0x2eead8 */ mov w8, #0x64;
    /* 0x2eeadc */ adrp x1, #0x1e1000;
    __android_log_print();
    return x0;
}
