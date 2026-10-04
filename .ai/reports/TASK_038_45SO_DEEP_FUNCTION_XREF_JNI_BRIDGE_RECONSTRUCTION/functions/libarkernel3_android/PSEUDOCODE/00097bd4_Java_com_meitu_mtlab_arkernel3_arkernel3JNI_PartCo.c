// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97bd4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1setApply
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97bd4 | Size: 16 bytes | SHA256: 267be9150d2147f32cca7e3bc0333cd8052648ab5f3d72a8e7b319a2494ecdcf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl8setApplyEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1setApply(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x97bd4 */ tst w4, #0xff;
    /* 0x97bd8 */ mov x0, x2;
    /* 0x97bdc */ cset w1, ne;
    /* 0x97be0 */ b #0xa5310;
}
