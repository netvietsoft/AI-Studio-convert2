// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94230
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94230 | Size: 28 bytes | SHA256: 489d5b9558e90810b3f87c04b9d0d9c411b8835e6f5904f3535855ff7bbf470e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireHairMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94230 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94234 */ mov x29, sp;
    /* 0x94238 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireHairMaskEv();
    /* 0x94240 */ and w0, w0, #1;
    /* 0x94244 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
