// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cbac4
// Recovered Name: _ZN11LayerFlowNS27LFEffectDermabrasionDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cbac4 | Size: 76 bytes | SHA256: 704b45246bf0c048536b53adc24f0456cb8a50704a81ebeb58aded115858f7f5
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533990)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModel is called,addr => %p"

jobject _ZN11LayerFlowNS27LFEffectDermabrasionDataJNI13nDestroyModelEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cbac4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cbac8 */ str x19, [sp, #0x10];
    /* 0x2cbacc */ mov x29, sp;
    /* 0x2cbad0 */ mov x19, x2;
    /* 0x2cbad4 */ nop ;
    /* 0x2cbad8 */ adr x1, #0x1e1361;
    /* 0x2cbadc */ adrp x2, #0x1e0000;
    /* 0x2cbae0 */ add x2, x2, #0x1ae;
    /* 0x2cbae4 */ mov w0, #6;
    /* 0x2cbae8 */ mov x3, x19;
    __android_log_print();
    return x0;
}
