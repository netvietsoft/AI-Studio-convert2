// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f77c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setPosition
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f77c | Size: 32 bytes | SHA256: 3689d2242829efe584568b77327b94f40a99901e1f80814a9dae7ed37df5802a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar324CustomTransformInterface11setPositionERKNS_6Float3E
// Strings referenced:
//   "mtlabar3::Point3F const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1setPosition(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8f77c */ cbz x4, #0x8f78c;
    /* 0x8f780 */ mov x0, x2;
    /* 0x8f784 */ mov x1, x4;
    /* 0x8f788 */ b #0xa21c0;
    /* 0x8f78c */ adrp x2, #0x6e000;
    /* 0x8f790 */ add x2, x2, #0x1a9;
    /* 0x8f794 */ mov w1, #7;
    /* 0x8f798 */ b #0x882c8;
}
