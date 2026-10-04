// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2de1fc
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2de1fc | Size: 188 bytes | SHA256: b3d420a91b6140bd180cdd52073912afc9359947513fa5831e3b067655c95f2c
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroyResult(J)V (table at 0x5375b8)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyResult is called, addr => %p"

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x2de1fc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2de200 */ stp x20, x19, [sp, #0x10];
    /* 0x2de204 */ mov x29, sp;
    /* 0x2de208 */ mov x19, x2;
    /* 0x2de20c */ nop ;
    /* 0x2de210 */ adr x1, #0x1e9177;
    /* 0x2de214 */ adrp x2, #0x1d5000;
    /* 0x2de218 */ add x2, x2, #0x426;
    /* 0x2de21c */ mov w0, #6;
    /* 0x2de220 */ mov x3, x19;
    __android_log_print();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
