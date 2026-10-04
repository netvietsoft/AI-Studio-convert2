// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f1338
// Recovered Name: _ZN11LayerFlowNS34LFStraightLegsAIGCRequestResultJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f1338 | Size: 208 bytes | SHA256: 848c9edb498f8c23f50b6b7a1434442fe2cbe4422d9bedf41f58e5a05d37d9c8
// Callers: 0 | Callees: 1 | Imports: 3

// Dynamic Registration: nDestroy(J)V (table at 0x53a588)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, __android_log_print
// Strings referenced:
//   "LFStraightLegsAIGCRequestResultJNI::nDestroy addr => %p"
//   "iklf_"

jobject _ZN11LayerFlowNS34LFStraightLegsAIGCRequestResultJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x2f1338 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2f133c */ stp x22, x21, [sp, #0x10];
    /* 0x2f1340 */ stp x20, x19, [sp, #0x20];
    /* 0x2f1344 */ mov x29, sp;
    /* 0x2f1348 */ mov x19, x2;
    /* 0x2f134c */ adrp x1, #0x1e1000;
    /* 0x2f1350 */ add x1, x1, #0x361;
    /* 0x2f1354 */ adrp x2, #0x1d6000;
    /* 0x2f1358 */ add x2, x2, #0xa66;
    /* 0x2f135c */ mov w0, #6;
    /* 0x2f1360 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    _ZdlPv();
}
