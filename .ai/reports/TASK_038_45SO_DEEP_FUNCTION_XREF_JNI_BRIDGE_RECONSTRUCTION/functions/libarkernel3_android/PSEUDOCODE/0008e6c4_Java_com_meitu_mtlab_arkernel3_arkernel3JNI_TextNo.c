// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e6c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableOpacity
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e6c4 | Size: 28 bytes | SHA256: 3afe5d0ab23a2713337b9e02550a1e5335657161719672e0255206ee40dd82e0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextNoteDetailInterface16getEnableOpacityEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1getEnableOpacity(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e6c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e6c8 */ mov x29, sp;
    /* 0x8e6cc */ mov x0, x2;
    _ZNK8mtlabar323TextNoteDetailInterface16getEnableOpacityEv();
    /* 0x8e6d4 */ and w0, w0, #1;
    /* 0x8e6d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
