// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b7bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1ImportStickerData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b7bc | Size: 28 bytes | SHA256: c1a737f03f55299a0cacc21f26a566e22352cc821664f9122794e565754c16d0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1ImportStickerData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8b7bc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8b7c0 */ mov x29, sp;
    /* 0x8b7c4 */ mov w0, #0x10;
    _Znwm();
    /* 0x8b7cc */ stp xzr, xzr, [x0];
    /* 0x8b7d0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
