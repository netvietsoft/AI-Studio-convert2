// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8ec48
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1getFontLibrary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8ec48 | Size: 64 bytes | SHA256: 4d82fdecf5289cbd1a2f58afe97946556ff73bedf718158802a1d5debf36958a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326IconSequenceStyleInterface14getFontLibraryEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1getFontLibrary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8ec48 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8ec4c */ str x19, [sp, #0x10];
    /* 0x8ec50 */ mov x29, sp;
    /* 0x8ec54 */ mov x19, x0;
    /* 0x8ec58 */ mov x0, x2;
    _ZNK8mtlabar326IconSequenceStyleInterface14getFontLibraryEv();
    /* 0x8ec60 */ ldr x8, [x19];
    /* 0x8ec64 */ ldrb w9, [x0];
    /* 0x8ec68 */ ldr x10, [x0, #0x10];
    /* 0x8ec6c */ tst w9, #1;
    /* 0x8ec70 */ ldr x2, [x8, #0x538];
}
