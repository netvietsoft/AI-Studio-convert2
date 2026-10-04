// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93328
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setOriginalSize
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93328 | Size: 32 bytes | SHA256: 0a61f9cb0c303aa4e24a3322677458b91ae6e778f2a7523b6af1c05790cec086
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction15setOriginalSizeENS_5SizeFE
// Strings referenced:
//   "Attempt to dereference null mtlabar3::SizeF"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setOriginalSize(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x93328 */ cbz x4, #0x93338;
    /* 0x9332c */ ldp s0, s1, [x4];
    /* 0x93330 */ mov x0, x2;
    /* 0x93334 */ b #0xa3740;
    /* 0x93338 */ adrp x2, #0x6e000;
    /* 0x9333c */ add x2, x2, #0x6fa;
    /* 0x93340 */ mov w1, #7;
    /* 0x93344 */ b #0x882c8;
}
