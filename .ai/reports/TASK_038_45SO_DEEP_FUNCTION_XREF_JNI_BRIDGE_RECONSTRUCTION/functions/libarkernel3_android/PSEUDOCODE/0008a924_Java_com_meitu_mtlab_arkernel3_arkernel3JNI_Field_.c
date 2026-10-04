// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a924
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1setValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a924 | Size: 32 bytes | SHA256: 9424f7f8c2faf99ad619454df83f1fec876228f24de6deea911944d71dfae537
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar35Field8setValueERKNS_14ParameterValueE
// Strings referenced:
//   "mtlabar3::ParameterValue const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1setValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8a924 */ cbz x4, #0x8a934;
    /* 0x8a928 */ mov x0, x2;
    /* 0x8a92c */ mov x1, x4;
    /* 0x8a930 */ b #0xa0510;
    /* 0x8a934 */ adrp x2, #0x6e000;
    /* 0x8a938 */ add x2, x2, #0x608;
    /* 0x8a93c */ mov w1, #7;
    /* 0x8a940 */ b #0x882c8;
}
