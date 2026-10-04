// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df740
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI21nSetMaterialModelListEP7_JNIEnvP7_jclasslP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df740 | Size: 256 bytes | SHA256: 9395f2e92f3372a93f43f88ba268ded12d6e0ad2f16f0f4b20a0bd50d31f620b
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetMaterialModelList(J[J)V (table at 0x5377e0)

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI21nSetMaterialModelListEP7_JNIEnvP7_jclasslP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x2df740 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2df744 */ str x23, [sp, #0x10];
    /* 0x2df748 */ stp x22, x21, [sp, #0x20];
    /* 0x2df74c */ stp x20, x19, [sp, #0x30];
    /* 0x2df750 */ mov x29, sp;
    /* 0x2df754 */ ldr x8, [x0];
    /* 0x2df758 */ mov x1, x3;
    /* 0x2df75c */ mov x19, x3;
    /* 0x2df760 */ mov x20, x0;
    /* 0x2df764 */ mov x21, x2;
    /* 0x2df768 */ ldr x8, [x8, #0x558];
    sub_2e2540();
}
