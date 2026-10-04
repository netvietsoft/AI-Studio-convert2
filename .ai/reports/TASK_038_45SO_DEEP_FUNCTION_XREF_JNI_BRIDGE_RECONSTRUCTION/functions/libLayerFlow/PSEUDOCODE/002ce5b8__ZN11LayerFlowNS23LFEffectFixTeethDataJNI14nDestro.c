// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce5b8
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI14nDestroyParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce5b8 | Size: 76 bytes | SHA256: 0f8d6293c6a73768ab831b9620beffeaae3a7e4578bb2c518eacaa50b5d73a87
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5341f0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyParams is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI14nDestroyParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2ce5b8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ce5bc */ str x19, [sp, #0x10];
    /* 0x2ce5c0 */ mov x29, sp;
    /* 0x2ce5c4 */ mov x19, x2;
    /* 0x2ce5c8 */ nop ;
    /* 0x2ce5cc */ adr x1, #0x1e1361;
    /* 0x2ce5d0 */ adrp x2, #0x1ee000;
    /* 0x2ce5d4 */ add x2, x2, #0xb3e;
    /* 0x2ce5d8 */ mov w0, #6;
    /* 0x2ce5dc */ mov x3, x19;
    __android_log_print();
    return x0;
}
