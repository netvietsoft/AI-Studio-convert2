// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fbac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fbac | Size: 28 bytes | SHA256: a27d0316bee06e8486713581ed30b5e502db8d0c9887eab5b3a24b001b7fd7b1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324ActiveWordStyleInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8fbac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8fbb0 */ mov x29, sp;
    /* 0x8fbb4 */ mov x0, x2;
    _ZNK8mtlabar324ActiveWordStyleInterface9getEnableEv();
    /* 0x8fbbc */ and w0, w0, #1;
    /* 0x8fbc0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
