// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3234
// Recovered Name: _ZN11LayerFlowNS23LFEffectSlimmingDataJNI12nDestroyDataEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3234 | Size: 192 bytes | SHA256: 869a327b8805a6b8253e05611544104edf0f7f147fd9d069bdf9a5d15483abf0
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroyData(J)V (table at 0x534eb0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyData is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectSlimmingDataJNI12nDestroyDataEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x2d3234 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2d3238 */ str x21, [sp, #0x10];
    /* 0x2d323c */ stp x20, x19, [sp, #0x20];
    /* 0x2d3240 */ mov x29, sp;
    /* 0x2d3244 */ mov x19, x2;
    /* 0x2d3248 */ nop ;
    /* 0x2d324c */ adr x1, #0x1e1361;
    /* 0x2d3250 */ adrp x2, #0x1e5000;
    /* 0x2d3254 */ add x2, x2, #0xdde;
    /* 0x2d3258 */ mov w0, #6;
    /* 0x2d325c */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
}
