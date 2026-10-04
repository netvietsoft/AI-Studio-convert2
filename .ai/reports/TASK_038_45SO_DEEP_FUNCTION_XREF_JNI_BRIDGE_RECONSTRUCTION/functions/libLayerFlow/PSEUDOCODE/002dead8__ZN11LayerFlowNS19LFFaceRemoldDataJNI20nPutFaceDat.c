// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dead8
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dead8 | Size: 372 bytes | SHA256: 19b6df5e29e3b2655df926dc0ff6de87969079b347ce97f595ad399f86fb95d7
// Callers: 0 | Callees: 3 | Imports: 1

// Dynamic Registration: nPutFaceDataByFaceId(JIJ)V (table at 0x537708)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI20nPutFaceDataByFaceIdEP7_JNIEnvP7_jclasslil(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 93 instructions
    /* 0x2dead8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x2deadc */ stp x24, x23, [sp, #0x10];
    /* 0x2deae0 */ stp x22, x21, [sp, #0x20];
    /* 0x2deae4 */ stp x20, x19, [sp, #0x30];
    /* 0x2deae8 */ mov x29, sp;
    /* 0x2deaec */ mov x23, x2;
    /* 0x2deaf0 */ mov x19, x4;
    /* 0x2deaf4 */ mov x21, x2;
    /* 0x2deaf8 */ ldr x8, [x23, #0x30]!;
    /* 0x2deafc */ mov w22, w3;
    /* 0x2deb00 */ cbnz x8, #0x2deb18;
    _Znwm();
    sub_2bc34c();
    _ZNSt6__ndk16vectorI23FaceRemoldMaterialParamNS_9allocatorIS1_EEE18__assign_with_sizeB8ne180000IPS1_S6_EEvT_T0_l();
    _ZNSt6__ndk16vectorINS_3mapINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEENS0_IiNS5_IiEEEENS_4lessIS7_EENS5_INS_4pairIKS7_S9_EEEEEENS5_ISG_EEE18__assign_with_sizeB8ne180000IPSG_SK_EEvT_T0_l();
    return x0;
}
