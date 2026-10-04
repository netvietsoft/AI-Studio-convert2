// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ac20
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ChannelTextureDataInterface_1getChannelTextureHeight
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ac20 | Size: 32 bytes | SHA256: 4eacab97ef7704e456d70277185c09eb704bd697c72f5e8d4a60e24b609fd966
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327ChannelTextureDataInterface23getChannelTextureHeightENS_21MultiInputChannelTypeE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ChannelTextureDataInterface_1getChannelTextureHeight(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8ac20 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ac24 */ mov x29, sp;
    /* 0x8ac28 */ mov w1, w4;
    /* 0x8ac2c */ mov x0, x2;
    _ZNK8mtlabar327ChannelTextureDataInterface23getChannelTextureHeightENS_21MultiInputChannelTypeE();
    /* 0x8ac34 */ mov w0, w0;
    /* 0x8ac38 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
