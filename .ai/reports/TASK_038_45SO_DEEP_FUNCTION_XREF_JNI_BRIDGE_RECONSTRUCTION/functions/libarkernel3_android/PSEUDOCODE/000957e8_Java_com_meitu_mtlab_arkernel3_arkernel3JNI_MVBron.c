// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x957e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVBronzersPenControl_1isEnableFacialProtection
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x957e8 | Size: 16 bytes | SHA256: ebe2204c6a8379412ab7ab3970e38607742f0a5aff29b98acddab2b9e25b95a5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVBronzersPenControl24isEnableFacialProtectionEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVBronzersPenControl_1isEnableFacialProtection(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x957e8 */ tst w4, #0xff;
    /* 0x957ec */ mov x0, x2;
    /* 0x957f0 */ cset w1, ne;
    /* 0x957f4 */ b #0xa47f0;
}
