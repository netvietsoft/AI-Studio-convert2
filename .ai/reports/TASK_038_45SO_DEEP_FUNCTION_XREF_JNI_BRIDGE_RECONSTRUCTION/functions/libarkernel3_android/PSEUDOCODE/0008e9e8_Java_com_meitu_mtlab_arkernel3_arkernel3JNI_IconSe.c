// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e9e8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setColor
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e9e8 | Size: 32 bytes | SHA256: 4f2f2b555f8646f015d5b53065bdec5735ecbceed1123ea12ea6116bc7f591b0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar326IconSequenceColorInterface8setColorERKNS_6ColorAE
// Strings referenced:
//   "mtlabar3::ColorA const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceColorInterface_1setColor(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8e9e8 */ cbz x4, #0x8e9f8;
    /* 0x8e9ec */ mov x0, x2;
    /* 0x8e9f0 */ mov x1, x4;
    /* 0x8e9f4 */ b #0xa1a90;
    /* 0x8e9f8 */ adrp x2, #0x6d000;
    /* 0x8e9fc */ add x2, x2, #0xdc9;
    /* 0x8ea00 */ mov w1, #7;
    /* 0x8ea04 */ b #0x882c8;
}
