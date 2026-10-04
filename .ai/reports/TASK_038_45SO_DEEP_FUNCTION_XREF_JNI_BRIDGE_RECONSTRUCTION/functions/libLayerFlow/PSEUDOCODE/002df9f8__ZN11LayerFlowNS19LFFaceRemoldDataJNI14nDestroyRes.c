// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df9f8
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df9f8 | Size: 84 bytes | SHA256: 1e978db80fd2090b6ed694b6756746409dfa16018188dca207cc7f50d68958a4
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroyResult(J)V (table at 0x537a08)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyResult is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2df9f8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2df9fc */ str x19, [sp, #0x10];
    /* 0x2dfa00 */ mov x29, sp;
    /* 0x2dfa04 */ mov x19, x2;
    /* 0x2dfa08 */ nop ;
    /* 0x2dfa0c */ adr x1, #0x1e9177;
    /* 0x2dfa10 */ adrp x2, #0x1d5000;
    /* 0x2dfa14 */ add x2, x2, #0x426;
    /* 0x2dfa18 */ mov w0, #6;
    /* 0x2dfa1c */ mov x3, x19;
    __android_log_print();
    _ZN18LFFaceRemoldResultD2Ev();
    return x0;
}
