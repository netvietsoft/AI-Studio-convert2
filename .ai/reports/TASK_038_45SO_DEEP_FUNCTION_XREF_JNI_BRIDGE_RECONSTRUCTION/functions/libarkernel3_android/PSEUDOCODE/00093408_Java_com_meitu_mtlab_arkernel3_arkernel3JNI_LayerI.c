// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93408
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setVisibility
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93408 | Size: 16 bytes | SHA256: fa821b177dfb48a983d0d259f2c60bf5961a073b924a4d6204cac9459ceb25fa
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction13setVisibilityEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setVisibility(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x93408 */ tst w4, #0xff;
    /* 0x9340c */ mov x0, x2;
    /* 0x93410 */ cset w1, ne;
    /* 0x93414 */ b #0xa37a0;
}
