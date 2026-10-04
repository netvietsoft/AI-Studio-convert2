// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95384
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckStretchExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95384 | Size: 32 bytes | SHA256: 10a6149a33f6612dc8ce9bbffd4abd88bbfc7f5d62230a419ee5bb0f76eb8d47
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl32isSigModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckStretchExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95384 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95388 */ mov x29, sp;
    /* 0x9538c */ mov x1, x4;
    /* 0x95390 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl32isSigModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE();
    /* 0x95398 */ and w0, w0, #1;
    /* 0x9539c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
