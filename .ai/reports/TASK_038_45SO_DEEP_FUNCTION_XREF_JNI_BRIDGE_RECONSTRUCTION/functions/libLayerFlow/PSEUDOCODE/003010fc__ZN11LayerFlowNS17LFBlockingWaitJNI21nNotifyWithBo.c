// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3010fc
// Recovered Name: _ZN11LayerFlowNS17LFBlockingWaitJNI21nNotifyWithBoolResultEP7_JNIEnvP7_jclassllh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3010fc | Size: 20 bytes | SHA256: 0e76e05861ac30c3a62d53026597e17fbcdcdf0344c96e6da5713b4543f7d291
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nNotifyWithBoolResult(JJZ)V (table at 0x53be00)

jobject _ZN11LayerFlowNS17LFBlockingWaitJNI21nNotifyWithBoolResultEP7_JNIEnvP7_jclassllh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x3010fc */ tst w4, #0xff;
    /* 0x301100 */ mov x1, x3;
    /* 0x301104 */ mov x0, x2;
    /* 0x301108 */ cset w2, ne;
    /* 0x30110c */ b #0x4418f8;
}
