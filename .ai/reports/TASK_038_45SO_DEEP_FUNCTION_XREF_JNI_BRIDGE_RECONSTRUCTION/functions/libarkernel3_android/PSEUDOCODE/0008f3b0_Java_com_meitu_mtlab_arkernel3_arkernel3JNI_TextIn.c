// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f3b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f3b0 | Size: 28 bytes | SHA256: 0d08111a8d8460183ea8e0c36fb860727a8c092d1cb8a519bc9c71f15d55b6bf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar331TextInactiveTextConfigInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f3b0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f3b4 */ mov x29, sp;
    /* 0x8f3b8 */ mov x0, x2;
    _ZNK8mtlabar331TextInactiveTextConfigInterface9getEnableEv();
    /* 0x8f3c0 */ and w0, w0, #1;
    /* 0x8f3c4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
