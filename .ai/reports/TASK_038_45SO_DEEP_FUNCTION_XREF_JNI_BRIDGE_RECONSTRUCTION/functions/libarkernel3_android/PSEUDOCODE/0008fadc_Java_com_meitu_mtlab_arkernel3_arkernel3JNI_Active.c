// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fadc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fadc | Size: 28 bytes | SHA256: 78ac037ce025a861052d195526944f476e705addb047d86795b8ac188bdd2884
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324ActiveWordColorInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8fadc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8fae0 */ mov x29, sp;
    /* 0x8fae4 */ mov x0, x2;
    _ZNK8mtlabar324ActiveWordColorInterface9getEnableEv();
    /* 0x8faec */ and w0, w0, #1;
    /* 0x8faf0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
