// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e5fc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e5fc | Size: 32 bytes | SHA256: 3877c8cdbeea402d0cfb0d65c9bf6889eec3e0d5352f0d184078b2e5e3b7acae
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323TextNoteDetailInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextNoteDetailInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e5fc */ cbz x4, #0x8e60c;
    /* 0x8e600 */ mov x0, x2;
    /* 0x8e604 */ mov x1, x4;
    /* 0x8e608 */ b #0xa1870;
    /* 0x8e60c */ adrp x2, #0x6d000;
    /* 0x8e610 */ add x2, x2, #0xdc9;
    /* 0x8e614 */ mov w1, #7;
    /* 0x8e618 */ b #0x882c8;
}
