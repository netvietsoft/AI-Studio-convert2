// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9181c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setColorA
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9181c | Size: 32 bytes | SHA256: 80d4517b084fcf5c8939c3968c0613f03a70117a95de6528bcf0b3a954a00579
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction9setColorAERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setColorA(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x9181c */ cbz x4, #0x9182c;
    /* 0x91820 */ mov x0, x2;
    /* 0x91824 */ mov x1, x4;
    /* 0x91828 */ b #0xa2820;
    /* 0x9182c */ adrp x2, #0x6d000;
    /* 0x91830 */ add x2, x2, #0xdc9;
    /* 0x91834 */ mov w1, #7;
    /* 0x91838 */ b #0x882c8;
}
