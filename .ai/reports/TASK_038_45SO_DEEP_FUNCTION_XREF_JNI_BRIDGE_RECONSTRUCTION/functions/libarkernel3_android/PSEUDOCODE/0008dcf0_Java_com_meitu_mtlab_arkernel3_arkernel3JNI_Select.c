// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dcf0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dcf0 | Size: 28 bytes | SHA256: 7672a663efb5b451d9f5548817318e7749cbd4b15ccfe197d959ca3d982658e8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface19getDisplayInASRTimeEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8dcf0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8dcf4 */ mov x29, sp;
    /* 0x8dcf8 */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface19getDisplayInASRTimeEv();
    /* 0x8dd00 */ and w0, w0, #1;
    /* 0x8dd04 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
