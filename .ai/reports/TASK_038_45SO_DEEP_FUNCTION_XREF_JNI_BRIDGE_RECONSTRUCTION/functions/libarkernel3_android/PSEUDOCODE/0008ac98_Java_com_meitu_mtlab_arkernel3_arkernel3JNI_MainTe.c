// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ac98
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MainTextureDataInterface_1getTextureHeight
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ac98 | Size: 28 bytes | SHA256: 0075e340bafd08e811d448faf6f9337295849bc63b74cd404b3e68566d881a7f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324MainTextureDataInterface16getTextureHeightEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MainTextureDataInterface_1getTextureHeight(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ac98 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ac9c */ mov x29, sp;
    /* 0x8aca0 */ mov x0, x2;
    _ZNK8mtlabar324MainTextureDataInterface16getTextureHeightEv();
    /* 0x8aca8 */ mov w0, w0;
    /* 0x8acac */ ldp x29, x30, [sp], #0x10;
    return x0;
}
