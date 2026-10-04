// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f724
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnableScale
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f724 | Size: 16 bytes | SHA256: 44e7cfb18704d859f97d4c6ba5a5eb30503d96e9d1795747d5298465ffa3dca0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324CustomTransformInterface14setEnableScaleEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnableScale(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f724 */ tst w4, #0xff;
    /* 0x8f728 */ mov x0, x2;
    /* 0x8f72c */ cset w1, ne;
    /* 0x8f730 */ b #0xa2180;
}
