// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8de7c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getFontLibrary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8de7c | Size: 64 bytes | SHA256: c6c0e8f0d4422e4e0baf79089d718890754ad0440e39e845750c6c15660fbaff
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionHighlightInterface14getFontLibraryEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1getFontLibrary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8de7c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8de80 */ str x19, [sp, #0x10];
    /* 0x8de84 */ mov x29, sp;
    /* 0x8de88 */ mov x19, x0;
    /* 0x8de8c */ mov x0, x2;
    _ZNK8mtlabar327SelectionHighlightInterface14getFontLibraryEv();
    /* 0x8de94 */ ldr x8, [x19];
    /* 0x8de98 */ ldrb w9, [x0];
    /* 0x8de9c */ ldr x10, [x0, #0x10];
    /* 0x8dea0 */ tst w9, #1;
    /* 0x8dea4 */ ldr x2, [x8, #0x538];
}
