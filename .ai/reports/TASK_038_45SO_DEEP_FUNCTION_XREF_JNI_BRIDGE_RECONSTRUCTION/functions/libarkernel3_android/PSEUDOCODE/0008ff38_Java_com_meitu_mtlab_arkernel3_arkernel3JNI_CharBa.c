// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ff38
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setScale
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ff38 | Size: 32 bytes | SHA256: d5d0929d4eccddef9163934707c69282504daceea55e05ec8a439e814470d851
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323CharBackgroundInterface8setScaleERKNS_6Float2E
// Strings referenced:
//   "mtlabar3::Point2F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharBackgroundInterface_1setScale(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ff38 */ cbz x4, #0x8ff48;
    /* 0x8ff3c */ mov x0, x2;
    /* 0x8ff40 */ mov x1, x4;
    /* 0x8ff44 */ b #0xa2620;
    /* 0x8ff48 */ adrp x2, #0x6d000;
    /* 0x8ff4c */ add x2, x2, #0xb14;
    /* 0x8ff50 */ mov w1, #7;
    /* 0x8ff54 */ b #0x882c8;
}
