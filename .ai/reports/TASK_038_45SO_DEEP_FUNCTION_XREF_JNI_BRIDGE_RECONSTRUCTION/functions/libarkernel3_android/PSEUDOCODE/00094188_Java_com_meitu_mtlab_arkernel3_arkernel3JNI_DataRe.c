// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94188
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandDataAdditionLimitMaxHandCount
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94188 | Size: 28 bytes | SHA256: 2ecb445d6f2f3ab3caba9aa0c92d38f3be02ee5338c0f1b49400c6a2b345c248
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire40requireHandDataAdditionLimitMaxHandCountEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandDataAdditionLimitMaxHandCount(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94188 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9418c */ mov x29, sp;
    /* 0x94190 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire40requireHandDataAdditionLimitMaxHandCountEv();
    /* 0x94198 */ mov w0, w0;
    /* 0x9419c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
