// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a3d0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1render
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a3d0 | Size: 28 bytes | SHA256: aec5e379557785aa4bae8b280aefc4452944e5e60aee029066d79001e7d89189
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface6renderEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1render(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9a3d0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9a3d4 */ mov x29, sp;
    /* 0x9a3d8 */ mov x0, x2;
    _ZN8mtlabar39Interface6renderEv();
    /* 0x9a3e0 */ and w0, w0, #1;
    /* 0x9a3e4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
