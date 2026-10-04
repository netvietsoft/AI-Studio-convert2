// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d79c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getHorizontalEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d79c | Size: 28 bytes | SHA256: 5716dad266177fe32e26222fb9a0e14dd5dbeb776fd835f5e34c5f2f5328c359
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar325TextEditableConfiguration21getHorizontalEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextEditableConfiguration_1getHorizontalEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d79c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d7a0 */ mov x29, sp;
    /* 0x8d7a4 */ mov x0, x2;
    _ZNK8mtlabar325TextEditableConfiguration21getHorizontalEditableEv();
    /* 0x8d7ac */ and w0, w0, #1;
    /* 0x8d7b0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
