// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x952f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1enforceSigModelData
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x952f4 | Size: 16 bytes | SHA256: a5e6dd9544b984dff0399e8dfdab12331d9da31d42f80c90911a46b46d78de66
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar315BodySlimControl19enforceSigModelDataEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControl_1enforceSigModelData(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x952f4 */ tst w4, #0xff;
    /* 0x952f8 */ mov x0, x2;
    /* 0x952fc */ cset w1, ne;
    /* 0x95300 */ b #0xa4440;
}
