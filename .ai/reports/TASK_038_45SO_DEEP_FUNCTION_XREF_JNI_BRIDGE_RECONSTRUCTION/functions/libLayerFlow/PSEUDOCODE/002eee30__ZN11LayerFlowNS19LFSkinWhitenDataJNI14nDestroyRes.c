// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eee30
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eee30 | Size: 200 bytes | SHA256: b47c0a076b6dca53182e4a50f413a49c515237d23618117f4ec8c6f24f123cc0
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nDestroyResult(J)V (table at 0x539d80)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyResult is called, addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x2eee30 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eee34 */ stp x20, x19, [sp, #0x10];
    /* 0x2eee38 */ mov x29, sp;
    /* 0x2eee3c */ mov x19, x2;
    /* 0x2eee40 */ adrp x1, #0x1e1000;
    /* 0x2eee44 */ add x1, x1, #0x361;
    /* 0x2eee48 */ adrp x2, #0x1d5000;
    /* 0x2eee4c */ add x2, x2, #0x426;
    /* 0x2eee50 */ mov w0, #6;
    /* 0x2eee54 */ mov x3, x19;
    __android_log_print();
    sub_2ec9b8();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
