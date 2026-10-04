// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df654
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI21nGetMaterialModelListEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df654 | Size: 236 bytes | SHA256: 48a313edac148ef6ec6bb8f8d774c555dc2809a1e1b06d8c3d90f4b48020ec69
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nGetMaterialModelList(J)[J (table at 0x5377c8)
// Calls external APIs: _Znam, _Znwm

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI21nGetMaterialModelListEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x2df654 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x2df658 */ str x25, [sp, #0x10];
    /* 0x2df65c */ stp x24, x23, [sp, #0x20];
    /* 0x2df660 */ stp x22, x21, [sp, #0x30];
    /* 0x2df664 */ stp x20, x19, [sp, #0x40];
    /* 0x2df668 */ mov x29, sp;
    /* 0x2df66c */ ldp x9, x8, [x2];
    /* 0x2df670 */ mov x21, x2;
    /* 0x2df674 */ mov x19, x0;
    /* 0x2df678 */ sub x8, x8, x9;
    /* 0x2df67c */ mov x9, #-0x3333333333333334;
    _Znam();
    _Znwm();
    return x0;
}
