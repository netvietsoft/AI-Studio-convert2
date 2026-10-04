// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a3f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1isATheLatest
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a3f4 | Size: 28 bytes | SHA256: 56c6814c96d8811c6b7d5f9c81bccd66b63edab94fd2653869bbd6686d1bd988
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface12isATheLatestEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1isATheLatest(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9a3f4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9a3f8 */ mov x29, sp;
    /* 0x9a3fc */ mov x0, x2;
    _ZN8mtlabar39Interface12isATheLatestEv();
    /* 0x9a404 */ and w0, w0, #1;
    /* 0x9a408 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
