// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e928
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e928 | Size: 28 bytes | SHA256: 2123ebbf542688964df21954115c83e73e31e007069750627d6ebc59745efa29
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar322SelectionNoteInterface19getDisplayInASRTimeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8e928 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8e92c */ mov x29, sp;
    /* 0x8e930 */ mov x0, x2;
    _ZNK8mtlabar322SelectionNoteInterface19getDisplayInASRTimeEv();
    /* 0x8e938 */ and w0, w0, #1;
    /* 0x8e93c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
