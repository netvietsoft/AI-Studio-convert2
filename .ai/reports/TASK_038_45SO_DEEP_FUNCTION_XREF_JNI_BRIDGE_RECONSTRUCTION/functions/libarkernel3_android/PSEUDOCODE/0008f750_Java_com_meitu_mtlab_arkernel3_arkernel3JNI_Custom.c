// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f750
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnableRotate
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f750 | Size: 16 bytes | SHA256: f5f5f99c0cd9a9ee76824391f5af36c706999f8529349315ba0b971111c52e1a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324CustomTransformInterface15setEnableRotateEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnableRotate(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f750 */ tst w4, #0xff;
    /* 0x8f754 */ mov x0, x2;
    /* 0x8f758 */ cset w1, ne;
    /* 0x8f75c */ b #0xa21a0;
}
