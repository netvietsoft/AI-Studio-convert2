// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9416c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9416c | Size: 28 bytes | SHA256: 0aa98cfcb31432504887694bd2dd06d5ca235c0bc59705b268bbf1133b39dc68
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire15requireHandDataEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHandData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9416c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94170 */ mov x29, sp;
    /* 0x94174 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire15requireHandDataEv();
    /* 0x9417c */ and w0, w0, #1;
    /* 0x94180 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
