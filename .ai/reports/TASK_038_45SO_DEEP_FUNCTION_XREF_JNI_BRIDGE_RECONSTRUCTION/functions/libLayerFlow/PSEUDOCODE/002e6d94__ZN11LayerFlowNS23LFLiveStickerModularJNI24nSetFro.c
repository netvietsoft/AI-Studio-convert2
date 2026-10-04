// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2e6d94
// Recovered Name: _ZN11LayerFlowNS23LFLiveStickerModularJNI24nSetFromMTIKMaterialInfoEP7_JNIEnvP8_jobjectlS4_
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2e6d94 | Size: 84 bytes | SHA256: 54a915529b9d04d07fb24c1974d3f5393b051ee53a33c482eef3bc2a4a1005cb
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nSetFromMTIKMaterialInfo(JLjava/lang/Object;)Z (table at 0x538740)
// Calls external APIs: _ZN12MTImageKitNS19MTIKParamConvertJni19getMTIKMaterialInfoEP7_JNIEnvP8_jobjectRNS_17CMTIKMaterialInfoE, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z
// Strings referenced:
//   "iklf"
//   "jniLiveStickerModular<%s:%d> jni convert fail."
//   "nSetFromMTIKMaterialInfo"

jobject _ZN11LayerFlowNS23LFLiveStickerModularJNI24nSetFromMTIKMaterialInfoEP7_JNIEnvP8_jobjectlS4_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2e6d94 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2e6d98 */ mov x29, sp;
    /* 0x2e6d9c */ mov x1, x3;
    /* 0x2e6da0 */ add x2, x2, #0x48;
    _ZN12MTImageKitNS19MTIKParamConvertJni19getMTIKMaterialInfoEP7_JNIEnvP8_jobjectRNS_17CMTIKMaterialInfoE();
    /* 0x2e6da8 */ tbz w0, #0, #0x2e6db8;
    /* 0x2e6dac */ mov w0, #1;
    /* 0x2e6db0 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x2e6db8 */ adrp x0, #0x1d9000;
    /* 0x2e6dbc */ add x0, x0, #0x93c;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
}
