// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df914
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI16nDestroyMaterialEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df914 | Size: 76 bytes | SHA256: 503f19e06901af8d0fd004cb86dc9caa5158c90653c8400bb3711a207922c8c2
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x537870)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyMaterial is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI16nDestroyMaterialEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2df914 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2df918 */ str x19, [sp, #0x10];
    /* 0x2df91c */ mov x29, sp;
    /* 0x2df920 */ mov x19, x2;
    /* 0x2df924 */ nop ;
    /* 0x2df928 */ adr x1, #0x1e9177;
    /* 0x2df92c */ adrp x2, #0x1d6000;
    /* 0x2df930 */ add x2, x2, #0x8e9;
    /* 0x2df934 */ mov w0, #6;
    /* 0x2df938 */ mov x3, x19;
    __android_log_print();
    return x0;
}
