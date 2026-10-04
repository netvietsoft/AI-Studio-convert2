// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8acc8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FrameInfoInterface_1setFrameInfoOption
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8acc8 | Size: 20 bytes | SHA256: 4fd35ba1ffdd420a8952c30c3b0678f46d4ce06f993e09c3a3946da036da0140
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar318FrameInfoInterface18setFrameInfoOptionE15FrameInfoOptionb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FrameInfoInterface_1setFrameInfoOption(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x8acc8 */ tst w5, #0xff;
    /* 0x8accc */ mov w1, w4;
    /* 0x8acd0 */ mov x0, x2;
    /* 0x8acd4 */ cset w2, ne;
    /* 0x8acd8 */ b #0xa06d0;
}
