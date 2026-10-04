// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ac7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MainTextureDataInterface_1getTextureWidth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ac7c | Size: 28 bytes | SHA256: 01dfa668d058e9c77b3558ba5a44b5fd7ad3aded4e2778e84377d42801319406
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324MainTextureDataInterface15getTextureWidthEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MainTextureDataInterface_1getTextureWidth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ac7c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ac80 */ mov x29, sp;
    /* 0x8ac84 */ mov x0, x2;
    _ZNK8mtlabar324MainTextureDataInterface15getTextureWidthEv();
    /* 0x8ac8c */ mov w0, w0;
    /* 0x8ac90 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
