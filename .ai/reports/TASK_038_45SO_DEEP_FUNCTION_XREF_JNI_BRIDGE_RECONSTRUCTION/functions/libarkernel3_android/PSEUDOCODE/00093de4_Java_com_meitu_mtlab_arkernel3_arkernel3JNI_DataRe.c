// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93de4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceGrayImage
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93de4 | Size: 28 bytes | SHA256: 74307205f690a57648044d363028717117585bc1fa2334ce57d90b053f05a498
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireSourceGrayImageEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceGrayImage(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93de4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93de8 */ mov x29, sp;
    /* 0x93dec */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireSourceGrayImageEv();
    /* 0x93df4 */ and w0, w0, #1;
    /* 0x93df8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
