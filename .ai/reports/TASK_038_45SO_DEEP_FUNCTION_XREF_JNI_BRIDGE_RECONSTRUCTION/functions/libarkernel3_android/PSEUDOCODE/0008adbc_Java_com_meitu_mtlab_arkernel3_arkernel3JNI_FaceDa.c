// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8adbc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceData_1setFaceRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8adbc | Size: 32 bytes | SHA256: 69e32f3fceacc287eb9e53f5fe1b8ee91eec906f96f1d635eb45506b54968750
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar38FaceData11setFaceRectERKNS_6Rect2FE
// Strings referenced:
//   "mtlabar3::Rect2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceData_1setFaceRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8adbc */ cbz x4, #0x8adcc;
    /* 0x8adc0 */ mov x0, x2;
    /* 0x8adc4 */ mov x1, x4;
    /* 0x8adc8 */ b #0xa0790;
    /* 0x8adcc */ adrp x2, #0x6e000;
    /* 0x8add0 */ add x2, x2, #0x79f;
    /* 0x8add4 */ mov w1, #7;
    /* 0x8add8 */ b #0x882c8;
}
