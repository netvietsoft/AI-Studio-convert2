// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95304
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95304 | Size: 32 bytes | SHA256: bfc28ebfad629fef5867fd195548d4e6e1c3aaf4f3ca902dbff5ec667bfdcb86
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl25isSigModelIsNeckExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isSigModelIsNeckExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95304 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95308 */ mov x29, sp;
    /* 0x9530c */ mov x1, x4;
    /* 0x95310 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl25isSigModelIsNeckExistenceEPNS_18FrameDataInterfaceE();
    /* 0x95318 */ and w0, w0, #1;
    /* 0x9531c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
