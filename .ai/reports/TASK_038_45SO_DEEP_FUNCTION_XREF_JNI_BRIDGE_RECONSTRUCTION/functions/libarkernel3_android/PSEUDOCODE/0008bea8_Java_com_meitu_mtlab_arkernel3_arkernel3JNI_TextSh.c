// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8bea8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getColorWork
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8bea8 | Size: 28 bytes | SHA256: e499e77c038a0ab097cba8679795a11bbc1adf6a308996751c0171d365d17f0f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextShadowConfiguration12getColorWorkEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextShadowConfiguration_1getColorWork(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8bea8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8beac */ mov x29, sp;
    /* 0x8beb0 */ mov x0, x2;
    _ZNK8mtlabar323TextShadowConfiguration12getColorWorkEv();
    /* 0x8beb8 */ and w0, w0, #1;
    /* 0x8bebc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
