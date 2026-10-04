// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9354c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setEnableDepth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9354c | Size: 16 bytes | SHA256: b4dd30c6b772c863092359827096d840331d37b15a0b83baaab271deb029aaed
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction14setEnableDepthEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setEnableDepth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9354c */ tst w4, #0xff;
    /* 0x93550 */ mov x0, x2;
    /* 0x93554 */ cset w1, ne;
    /* 0x93558 */ b #0xa3880;
}
