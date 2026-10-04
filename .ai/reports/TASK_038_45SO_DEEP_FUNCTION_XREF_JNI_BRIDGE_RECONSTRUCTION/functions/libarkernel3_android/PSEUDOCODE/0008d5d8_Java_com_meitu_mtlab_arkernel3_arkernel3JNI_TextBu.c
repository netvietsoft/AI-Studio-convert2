// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d5d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d5d8 | Size: 28 bytes | SHA256: 06d4b8761373d957ea505618be9b3d94c966ad528fe25b5512f5a7cab577ee19
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextBubbleConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d5d8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d5dc */ mov x29, sp;
    /* 0x8d5e0 */ mov x0, x2;
    _ZNK8mtlabar323TextBubbleConfiguration9getEnableEv();
    /* 0x8d5e8 */ and w0, w0, #1;
    /* 0x8d5ec */ ldp x29, x30, [sp], #0x10;
    return x0;
}
