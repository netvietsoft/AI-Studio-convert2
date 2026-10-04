// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94428
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94428 | Size: 28 bytes | SHA256: cf7af7b7cf60eef5bb1043ebfc88a7343a9bc5268395b076abbb5966d51eef44
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire16requireClothMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94428 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9442c */ mov x29, sp;
    /* 0x94430 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire16requireClothMaskEv();
    /* 0x94438 */ and w0, w0, #1;
    /* 0x9443c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
