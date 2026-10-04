// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c050
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c050 | Size: 16 bytes | SHA256: 9997522acbec41f7a303f8afc5d3edb2afc56b08c626aebef6caf90adde29bf4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextStrokeConfiguration12setColorWorkEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextStrokeConfiguration_1setColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c050 */ tst w4, #0xff;
    /* 0x8c054 */ mov x0, x2;
    /* 0x8c058 */ cset w1, ne;
    /* 0x8c05c */ b #0xa0e00;
}
