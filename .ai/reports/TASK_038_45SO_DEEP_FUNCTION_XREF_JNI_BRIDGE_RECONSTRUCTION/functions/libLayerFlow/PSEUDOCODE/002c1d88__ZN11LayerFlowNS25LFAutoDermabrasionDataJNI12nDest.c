// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1d88
// Recovered Name: _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1d88 | Size: 16 bytes | SHA256: 029cb400d1b87ed0197f90593d02b9dc1dab799b7e7ffab2ab85948bfaa93371
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x531e68)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x2c1d88 */ cbz x2, #0x2c1d94;
    /* 0x2c1d8c */ mov x0, x2;
    /* 0x2c1d90 */ b #0x52a280;
    return x0;
}
