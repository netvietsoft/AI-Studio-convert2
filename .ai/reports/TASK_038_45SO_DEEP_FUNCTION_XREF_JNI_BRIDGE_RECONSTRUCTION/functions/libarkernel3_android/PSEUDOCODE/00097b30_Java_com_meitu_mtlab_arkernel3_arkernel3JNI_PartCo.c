// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97b30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isError
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97b30 | Size: 28 bytes | SHA256: 6f04138b11fd6ecc004ae376337cd689475c724a40eac2b8e8905e371069ffe1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl7isErrorEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isError(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x97b30 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x97b34 */ mov x29, sp;
    /* 0x97b38 */ mov x0, x2;
    _ZN8mtlabar311PartControl7isErrorEv();
    /* 0x97b40 */ and w0, w0, #1;
    /* 0x97b44 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
