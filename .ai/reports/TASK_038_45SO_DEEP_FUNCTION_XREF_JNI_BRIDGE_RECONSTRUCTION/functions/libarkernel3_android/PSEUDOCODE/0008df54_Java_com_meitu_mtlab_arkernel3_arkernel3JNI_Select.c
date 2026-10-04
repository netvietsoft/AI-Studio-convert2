// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8df54
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8df54 | Size: 32 bytes | SHA256: e76523a6a12075e6e4ce07e7710bbf159620f1aae4b9e593ad3f33b65c43512c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8df54 */ cbz x4, #0x8df64;
    /* 0x8df58 */ mov x0, x2;
    /* 0x8df5c */ mov x1, x4;
    /* 0x8df60 */ b #0xa13a0;
    /* 0x8df64 */ adrp x2, #0x6d000;
    /* 0x8df68 */ add x2, x2, #0xdc9;
    /* 0x8df6c */ mov w1, #7;
    /* 0x8df70 */ b #0x882c8;
}
