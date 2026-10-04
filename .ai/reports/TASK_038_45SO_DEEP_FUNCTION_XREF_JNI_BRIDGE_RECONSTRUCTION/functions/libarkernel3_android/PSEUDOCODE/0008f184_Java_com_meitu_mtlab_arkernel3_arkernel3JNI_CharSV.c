// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f184
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f184 | Size: 16 bytes | SHA256: c6631a48289a00f4639f6cf8b504bb03d0535dded2194035eb30df47b862c41f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326CharSVGBackgroundInterface11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8f184 */ tst w4, #0xff;
    /* 0x8f188 */ mov x0, x2;
    /* 0x8f18c */ cset w1, ne;
    /* 0x8f190 */ b #0xa1f50;
}
