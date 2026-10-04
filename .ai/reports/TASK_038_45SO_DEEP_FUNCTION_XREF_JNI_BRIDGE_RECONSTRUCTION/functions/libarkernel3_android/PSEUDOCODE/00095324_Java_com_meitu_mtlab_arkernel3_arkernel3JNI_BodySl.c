// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95324
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95324 | Size: 32 bytes | SHA256: 98e96c6d6ed9d4553b211ba395970a097a10fa3abab6634a3ebaa50ef107f21c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl27isMultiModelIsNeckExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95324 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95328 */ mov x29, sp;
    /* 0x9532c */ mov x1, x4;
    /* 0x95330 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl27isMultiModelIsNeckExistenceEPNS_18FrameDataInterfaceE();
    /* 0x95338 */ and w0, w0, #1;
    /* 0x9533c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
