// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d838
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d838 | Size: 28 bytes | SHA256: 94f6ac8887c832cca46cd542175b298c43512da47fcecc80358497dc7132fe39
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d838 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d83c */ mov x29, sp;
    /* 0x8d840 */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration9getEnableEv();
    /* 0x8d848 */ and w0, w0, #1;
    /* 0x8d84c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
