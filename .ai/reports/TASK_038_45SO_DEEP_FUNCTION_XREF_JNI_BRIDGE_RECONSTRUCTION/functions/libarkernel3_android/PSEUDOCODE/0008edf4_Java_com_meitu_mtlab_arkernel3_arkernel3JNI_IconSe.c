// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8edf4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setPaddingZero
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8edf4 | Size: 16 bytes | SHA256: f243809de92ae7f5414f7a081b678960e0f3c188364100586b7291cc493e97a2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceStyleInterface14setPaddingZeroEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1setPaddingZero(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8edf4 */ tst w4, #0xff;
    /* 0x8edf8 */ mov x0, x2;
    /* 0x8edfc */ cset w1, ne;
    /* 0x8ee00 */ b #0xa1c50;
}
