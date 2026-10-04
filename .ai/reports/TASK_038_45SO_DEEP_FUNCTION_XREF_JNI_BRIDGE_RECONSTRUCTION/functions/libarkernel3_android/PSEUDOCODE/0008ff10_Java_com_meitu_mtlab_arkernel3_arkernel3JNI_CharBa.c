// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ff10
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setOffset
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ff10 | Size: 32 bytes | SHA256: b64e7c7baa332ac2aaf72be761f7ca6e583ef70b88f2cfc7a6bc4f507dd3e414
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323CharBackgroundInterface9setOffsetERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setOffset(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ff10 */ cbz x4, #0x8ff20;
    /* 0x8ff14 */ mov x0, x2;
    /* 0x8ff18 */ mov x1, x4;
    /* 0x8ff1c */ b #0xa2600;
    /* 0x8ff20 */ adrp x2, #0x6d000;
    /* 0x8ff24 */ add x2, x2, #0xb14;
    /* 0x8ff28 */ mov w1, #7;
    /* 0x8ff2c */ b #0x882c8;
}
