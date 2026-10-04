// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8baac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8baac | Size: 16 bytes | SHA256: 549accb67800a1980405f951032de04efda80114747b5075ba8b99674bc91597
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321TextGlowConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8baac */ tst w4, #0xff;
    /* 0x8bab0 */ mov x0, x2;
    /* 0x8bab4 */ cset w1, ne;
    /* 0x8bab8 */ b #0xa0b30;
}
