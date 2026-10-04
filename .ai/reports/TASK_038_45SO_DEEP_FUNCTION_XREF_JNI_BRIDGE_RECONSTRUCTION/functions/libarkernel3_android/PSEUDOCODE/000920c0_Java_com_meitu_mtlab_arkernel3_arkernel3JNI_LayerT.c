// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x920c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableFlip
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x920c0 | Size: 28 bytes | SHA256: 4dd117339cb683343a9c238fdcb43b4977641ee628301b337cd7350a5a291736
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction13getEnableFlipEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableFlip(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x920c0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x920c4 */ mov x29, sp;
    /* 0x920c8 */ mov x0, x2;
    _ZN8mtlabar320LayerTextInteraction13getEnableFlipEv();
    /* 0x920d0 */ and w0, w0, #1;
    /* 0x920d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
