// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e86c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e86c | Size: 64 bytes | SHA256: 421f47d761151b6db4ccf17a0e178fadae909801e0680eedda5724c905e28be2
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar322SelectionNoteInterface13getConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionNoteInterface_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8e86c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8e870 */ str x19, [sp, #0x10];
    /* 0x8e874 */ mov x29, sp;
    /* 0x8e878 */ mov x19, x0;
    /* 0x8e87c */ mov x0, x2;
    _ZNK8mtlabar322SelectionNoteInterface13getConfigPathEv();
    /* 0x8e884 */ ldr x8, [x19];
    /* 0x8e888 */ ldrb w9, [x0];
    /* 0x8e88c */ ldr x10, [x0, #0x10];
    /* 0x8e890 */ tst w9, #1;
    /* 0x8e894 */ ldr x2, [x8, #0x538];
}
