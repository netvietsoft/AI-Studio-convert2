// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ac00
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ChannelTextureDataInterface_1getChannelTextureWidth
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ac00 | Size: 32 bytes | SHA256: e27c81dba228d8202fb222d2602b6f581726c296ab9b0f111755a8c7dd254503
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327ChannelTextureDataInterface22getChannelTextureWidthENS_21MultiInputChannelTypeE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ChannelTextureDataInterface_1getChannelTextureWidth(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ac00 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ac04 */ mov x29, sp;
    /* 0x8ac08 */ mov w1, w4;
    /* 0x8ac0c */ mov x0, x2;
    _ZNK8mtlabar327ChannelTextureDataInterface22getChannelTextureWidthENS_21MultiInputChannelTypeE();
    /* 0x8ac14 */ mov w0, w0;
    /* 0x8ac18 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
