// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90bd0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90bd0 | Size: 220 bytes | SHA256: 38c19a27136e027b6fd2e018dea081381ff7e4023945d6cc4a845a6eba3b607c
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionNoteInterface_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x90bd0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x90bd4 */ str x21, [sp, #0x10];
    /* 0x90bd8 */ stp x20, x19, [sp, #0x20];
    /* 0x90bdc */ mov x29, sp;
    /* 0x90be0 */ mov x0, x2;
    /* 0x90be4 */ mov x19, x2;
    /* 0x90be8 */ mov x20, x4;
    /* 0x90bec */ ldr x8, [x0, #0x10]!;
    /* 0x90bf0 */ ldur x21, [x0, #-8];
    /* 0x90bf4 */ cmp x21, x8;
    /* 0x90bf8 */ b.hs #0x90c04;
    sub_9bd08();
    _ZdlPv();
    return x0;
    sub_9bcf4();
}
