// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x944ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBody
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x944ec | Size: 28 bytes | SHA256: 15fae2fe989376897843be6e0649727a6314863b7d383e4df3ebc5ef746369c7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire11requireBodyEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBody(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x944ec */ stp x29, x30, [sp, #-0x10]!;
    /* 0x944f0 */ mov x29, sp;
    /* 0x944f4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire11requireBodyEv();
    /* 0x944fc */ and w0, w0, #1;
    /* 0x94500 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
