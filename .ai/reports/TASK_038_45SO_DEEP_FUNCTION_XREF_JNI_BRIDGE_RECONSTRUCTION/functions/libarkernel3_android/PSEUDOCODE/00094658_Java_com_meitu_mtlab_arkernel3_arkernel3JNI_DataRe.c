// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94658
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCG
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94658 | Size: 28 bytes | SHA256: cc2515c6931c25bc73bd152be6ff510a74e08c149b4cc6cce6853ced85ff2ac9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire9requireCGEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireCG(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94658 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9465c */ mov x29, sp;
    /* 0x94660 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire9requireCGEv();
    /* 0x94668 */ and w0, w0, #1;
    /* 0x9466c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
