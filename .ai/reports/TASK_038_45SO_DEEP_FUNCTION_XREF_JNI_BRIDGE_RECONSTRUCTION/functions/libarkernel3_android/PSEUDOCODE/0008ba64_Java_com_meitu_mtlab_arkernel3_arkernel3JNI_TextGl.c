// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ba64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ba64 | Size: 28 bytes | SHA256: bdeb5d2e0ca0541dd603b40abfc7e96d85d5c45bc7131e06608cd35d8ebc986e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextGlowConfiguration9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextGlowConfiguration_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8ba64 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ba68 */ mov x29, sp;
    /* 0x8ba6c */ mov x0, x2;
    _ZNK8mtlabar321TextGlowConfiguration9getEnableEv();
    /* 0x8ba74 */ and w0, w0, #1;
    /* 0x8ba78 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
