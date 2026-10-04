// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce6d4
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI20nDestroyRepairParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce6d4 | Size: 76 bytes | SHA256: 92c77188516e9b825ba563c6a0572485ce951b56029a6b6673b0a44728a85e10
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534310)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyRepairParams is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI20nDestroyRepairParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2ce6d4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ce6d8 */ str x19, [sp, #0x10];
    /* 0x2ce6dc */ mov x29, sp;
    /* 0x2ce6e0 */ mov x19, x2;
    /* 0x2ce6e4 */ nop ;
    /* 0x2ce6e8 */ adr x1, #0x1e1361;
    /* 0x2ce6ec */ adrp x2, #0x1cd000;
    /* 0x2ce6f0 */ add x2, x2, #0x356;
    /* 0x2ce6f4 */ mov w0, #6;
    /* 0x2ce6f8 */ mov x3, x19;
    __android_log_print();
    return x0;
}
