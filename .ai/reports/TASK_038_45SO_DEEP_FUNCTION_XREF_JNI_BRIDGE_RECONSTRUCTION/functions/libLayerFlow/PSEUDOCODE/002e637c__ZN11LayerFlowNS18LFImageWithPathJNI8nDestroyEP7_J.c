// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e637c
// Recovered Name: _ZN11LayerFlowNS18LFImageWithPathJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e637c | Size: 156 bytes | SHA256: 02f79b1cca77b30eb846e0cad865ea7877370924aa86cedac113bb464c7c8686
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroy(J)V (table at 0x538320)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "LFImageWithPathJNI::nDestroy addr => %p"
//   "iklf_"

jobject _ZN11LayerFlowNS18LFImageWithPathJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x2e637c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e6380 */ stp x20, x19, [sp, #0x10];
    /* 0x2e6384 */ mov x29, sp;
    /* 0x2e6388 */ mov x19, x2;
    /* 0x2e638c */ adrp x1, #0x1e1000;
    /* 0x2e6390 */ add x1, x1, #0x361;
    /* 0x2e6394 */ adrp x2, #0x1d5000;
    /* 0x2e6398 */ add x2, x2, #0x728;
    /* 0x2e639c */ mov w0, #6;
    /* 0x2e63a0 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    sub_5263e0();
    return x0;
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
}
