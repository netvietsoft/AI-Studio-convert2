// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e708
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setPadding
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e708 | Size: 32 bytes | SHA256: 85752b129c4a148def64bdd828a10ce12bd47fc8ae1279e75cf2dfbb5b21a1f6
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface10setPaddingERKNSt6__ndk16vectorIfNS1_9allocatorIfEEEE
// Strings referenced:
//   "std::vector< float > const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setPadding(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e708 */ cbz x4, #0x8e718;
    /* 0x8e70c */ mov x0, x2;
    /* 0x8e710 */ mov x1, x4;
    /* 0x8e714 */ b #0xa18f0;
    /* 0x8e718 */ adrp x2, #0x6e000;
    /* 0x8e71c */ add x2, x2, #0x665;
    /* 0x8e720 */ mov w1, #7;
    /* 0x8e724 */ b #0x882c8;
}
