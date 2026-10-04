// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dda44
// Recovered Name: _ZN11LayerFlowNS17LFFaceFullDataJNI8nDestroyEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dda44 | Size: 120 bytes | SHA256: ba161350257ec30711f94f4ad8514d88a0d9a433a26c3e248d45ddb987eeeced
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5370c0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "LFFaceFullDataJNI#nDestroy try delete ptr %p"

jobject _ZN11LayerFlowNS17LFFaceFullDataJNI8nDestroyEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x2dda44 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2dda48 */ str x19, [sp, #0x10];
    /* 0x2dda4c */ mov x29, sp;
    /* 0x2dda50 */ mov x19, x2;
    /* 0x2dda54 */ nop ;
    /* 0x2dda58 */ adr x1, #0x1e9177;
    /* 0x2dda5c */ adrp x2, #0x1ec000;
    /* 0x2dda60 */ add x2, x2, #0xb36;
    /* 0x2dda64 */ mov w0, #6;
    /* 0x2dda68 */ mov x3, x19;
    __android_log_print();
    sub_2de5dc();
    _ZdlPv();
    return x0;
}
