// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bf98
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bf98 | Size: 16 bytes | SHA256: 99ba9f17121ad573dcbb99a1c7e8bfa2fce0b60db45db217028087b23791d5c9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextStrokeConfiguration11setEditableEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8bf98 */ tst w4, #0xff;
    /* 0x8bf9c */ mov x0, x2;
    /* 0x8bfa0 */ cset w1, ne;
    /* 0x8bfa4 */ b #0xa0dc0;
}
