// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95678
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1removeItem
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95678 | Size: 32 bytes | SHA256: 45348e642dd3a5ef7dc3361f0f06b4880f5a30ba6f334f991556856f5add8203
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316PickColorControl10removeItemEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1removeItem(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x95678 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9567c */ mov x29, sp;
    /* 0x95680 */ mov x1, x4;
    /* 0x95684 */ mov x0, x2;
    _ZN8mtlabar316PickColorControl10removeItemEm();
    /* 0x9568c */ and w0, w0, #1;
    /* 0x95690 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
