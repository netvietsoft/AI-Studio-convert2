// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8aeb0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceDataInterface_1setDetectSize
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8aeb0 | Size: 32 bytes | SHA256: 32c6f43f4a5cae675b52dc770eefcd0c10339d2f3b23823a540022788fc9e4a2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar317FaceDataInterface13setDetectSizeERKNS_5SizeFE
// Strings referenced:
//   "mtlabar3::Size2 const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceDataInterface_1setDetectSize(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8aeb0 */ cbz x4, #0x8aec0;
    /* 0x8aeb4 */ mov x0, x2;
    /* 0x8aeb8 */ mov x1, x4;
    /* 0x8aebc */ b #0xa08a0;
    /* 0x8aec0 */ adrp x2, #0x6e000;
    /* 0x8aec4 */ add x2, x2, #0x302;
    /* 0x8aec8 */ mov w1, #7;
    /* 0x8aecc */ b #0x882c8;
}
