// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95364
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckSlimExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95364 | Size: 32 bytes | SHA256: 1042fc7328f1edd81e9bae0dc0541172a61b23290017e4623f4c5d60a6eada89
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl31isMultiModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckSlimExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95364 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95368 */ mov x29, sp;
    /* 0x9536c */ mov x1, x4;
    /* 0x95370 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl31isMultiModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE();
    /* 0x95378 */ and w0, w0, #1;
    /* 0x9537c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
