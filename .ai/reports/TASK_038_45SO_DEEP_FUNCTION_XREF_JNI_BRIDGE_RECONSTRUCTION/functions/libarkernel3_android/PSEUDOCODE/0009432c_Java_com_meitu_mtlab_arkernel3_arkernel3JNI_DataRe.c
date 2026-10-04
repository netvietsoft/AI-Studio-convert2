// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9432c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9432c | Size: 28 bytes | SHA256: 55485186c0323824c35e99f94cc67a87f4468d2250a3c16530247f5dc7ed36d7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireHeadMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9432c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94330 */ mov x29, sp;
    /* 0x94334 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireHeadMaskEv();
    /* 0x9433c */ and w0, w0, #1;
    /* 0x94340 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
