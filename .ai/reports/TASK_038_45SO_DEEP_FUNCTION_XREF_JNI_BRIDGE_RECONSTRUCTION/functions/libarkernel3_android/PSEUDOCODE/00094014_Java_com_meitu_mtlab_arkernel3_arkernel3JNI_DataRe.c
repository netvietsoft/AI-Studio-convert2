// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94014
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionMakeupAdapt
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94014 | Size: 28 bytes | SHA256: abbdb3abd20327af535d69758338162183f0ca5dc2ac519db50f659e159063cf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire34requireFaceDataAdditionMakeupAdaptEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceDataAdditionMakeupAdapt(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94014 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94018 */ mov x29, sp;
    /* 0x9401c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire34requireFaceDataAdditionMakeupAdaptEv();
    /* 0x94024 */ and w0, w0, #1;
    /* 0x94028 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
