// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94818
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DAbundantBreasts
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94818 | Size: 28 bytes | SHA256: 7c9380d4496053c9a0ec4a060127936414517f8b0fe07f96eee4aa6f8a998877
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire32requireBodySlim3DAbundantBreastsEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DAbundantBreasts(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94818 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9481c */ mov x29, sp;
    /* 0x94820 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire32requireBodySlim3DAbundantBreastsEv();
    /* 0x94828 */ and w0, w0, #1;
    /* 0x9482c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
