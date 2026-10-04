// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x946c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHuman3D
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x946c8 | Size: 28 bytes | SHA256: c024c36b21bd599988c5de86b7b2c4fc1d25db2e276da54fd186c9b9b590ff9b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire14requireHuman3DEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHuman3D(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x946c8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x946cc */ mov x29, sp;
    /* 0x946d0 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire14requireHuman3DEv();
    /* 0x946d8 */ and w0, w0, #1;
    /* 0x946dc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
