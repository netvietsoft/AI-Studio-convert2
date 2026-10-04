// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93418
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getVisibility
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93418 | Size: 28 bytes | SHA256: 67eb565c9c924fbf0437a7d0eaf99631d86d0fcf8f9867bcf3077d815cd1c118
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction13getVisibilityEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getVisibility(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93418 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9341c */ mov x29, sp;
    /* 0x93420 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction13getVisibilityEv();
    /* 0x93428 */ and w0, w0, #1;
    /* 0x9342c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
