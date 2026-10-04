// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x919f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setWrap
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x919f8 | Size: 16 bytes | SHA256: 3d74c67fc159ff1f4ddb8250ba2ef384e29b7a0063de08952978b4bb40a3a54c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction7setWrapEb

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setWrap(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x919f8 */ tst w4, #0xff;
    /* 0x919fc */ mov x0, x2;
    /* 0x91a00 */ cset w1, ne;
    /* 0x91a04 */ b #0xa2980;
}
