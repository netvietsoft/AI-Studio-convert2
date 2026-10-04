// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95344
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckSlimExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95344 | Size: 32 bytes | SHA256: 743c320da9cd55c545cd0593a167aa10601911773b289baf1fcc7306c762445e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl29isSigModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckSlimExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95344 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95348 */ mov x29, sp;
    /* 0x9534c */ mov x1, x4;
    /* 0x95350 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl29isSigModelIsNeckSlimExistenceEPNS_18FrameDataInterfaceE();
    /* 0x95358 */ and w0, w0, #1;
    /* 0x9535c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
