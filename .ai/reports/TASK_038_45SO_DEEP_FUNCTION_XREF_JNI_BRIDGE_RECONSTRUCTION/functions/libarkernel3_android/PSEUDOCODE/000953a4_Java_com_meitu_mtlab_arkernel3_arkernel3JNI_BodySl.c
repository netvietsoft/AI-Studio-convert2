// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x953a4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckStretchExistence
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x953a4 | Size: 32 bytes | SHA256: d5ee62d10428de23a6e9fd1972fae1d1567afe3aeb46a7fbbbf4a26d6d6efc8e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl34isMultiModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1isMultiModelIsNeckStretchExistence(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x953a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x953a8 */ mov x29, sp;
    /* 0x953ac */ mov x1, x4;
    /* 0x953b0 */ mov x0, x2;
    _ZN8mtlabar315BodySlimControl34isMultiModelIsNeckStretchExistenceEPNS_18FrameDataInterfaceE();
    /* 0x953b8 */ and w0, w0, #1;
    /* 0x953bc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
