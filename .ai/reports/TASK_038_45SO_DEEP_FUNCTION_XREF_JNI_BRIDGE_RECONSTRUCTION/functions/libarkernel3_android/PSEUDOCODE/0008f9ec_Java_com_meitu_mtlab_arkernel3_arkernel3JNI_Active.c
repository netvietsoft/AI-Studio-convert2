// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f9ec
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setSecondColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f9ec | Size: 32 bytes | SHA256: 2c5c046793252068d6e0b7a716a74a6f2a33c0ec396a61cf0fe57ca5fb8e159b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar321ActiveWordBgInterface14setSecondColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1setSecondColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f9ec */ cbz x4, #0x8f9fc;
    /* 0x8f9f0 */ mov x0, x2;
    /* 0x8f9f4 */ mov x1, x4;
    /* 0x8f9f8 */ b #0xa2320;
    /* 0x8f9fc */ adrp x2, #0x6d000;
    /* 0x8fa00 */ add x2, x2, #0xdc9;
    /* 0x8fa04 */ mov w1, #7;
    /* 0x8fa08 */ b #0x882c8;
}
