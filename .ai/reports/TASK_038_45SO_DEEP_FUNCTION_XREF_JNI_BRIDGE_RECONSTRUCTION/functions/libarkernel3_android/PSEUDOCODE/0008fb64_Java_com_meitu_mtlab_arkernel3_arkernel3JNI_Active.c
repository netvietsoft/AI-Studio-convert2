// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fb64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fb64 | Size: 32 bytes | SHA256: 23a299a718ca9e8e82918fdcfa7bc150c5387a585bbb88ef2b13b3dd7a0961b1
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324ActiveWordColorInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordColorInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8fb64 */ cbz x4, #0x8fb74;
    /* 0x8fb68 */ mov x0, x2;
    /* 0x8fb6c */ mov x1, x4;
    /* 0x8fb70 */ b #0xa24d0;
    /* 0x8fb74 */ adrp x2, #0x6d000;
    /* 0x8fb78 */ add x2, x2, #0xdc9;
    /* 0x8fb7c */ mov w1, #7;
    /* 0x8fb80 */ b #0x882c8;
}
