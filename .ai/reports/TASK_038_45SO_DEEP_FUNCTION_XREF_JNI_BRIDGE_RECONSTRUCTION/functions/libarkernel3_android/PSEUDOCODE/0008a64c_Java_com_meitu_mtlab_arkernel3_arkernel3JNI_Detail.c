// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a64c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailCategory_1getDisplayName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a64c | Size: 68 bytes | SHA256: bd9cc37ce891ca2dd38a73e9c3a195b5c880f861930af660982676fcffc4127f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar314DetailCategory14getDisplayNameEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailCategory_1getDisplayName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x8a64c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a650 */ str x19, [sp, #0x10];
    /* 0x8a654 */ mov x29, sp;
    /* 0x8a658 */ mov x19, x0;
    /* 0x8a65c */ mov x0, x2;
    _ZNK8mtlabar314DetailCategory14getDisplayNameEv();
    /* 0x8a664 */ cbz x0, #0x8a684;
    /* 0x8a668 */ ldr x8, [x19];
    /* 0x8a66c */ mov x1, x0;
    /* 0x8a670 */ ldr x2, [x8, #0x538];
    /* 0x8a674 */ mov x0, x19;
    return x0;
}
