// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f6f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnablePosition
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f6f8 | Size: 16 bytes | SHA256: 4f93f59dc05d071fdabe53830f6efef92c1aedfc7799e75fc7a664a2f3b69f2b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324CustomTransformInterface17setEnablePositionEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setEnablePosition(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f6f8 */ tst w4, #0xff;
    /* 0x8f6fc */ mov x0, x2;
    /* 0x8f700 */ cset w1, ne;
    /* 0x8f704 */ b #0xa2160;
}
