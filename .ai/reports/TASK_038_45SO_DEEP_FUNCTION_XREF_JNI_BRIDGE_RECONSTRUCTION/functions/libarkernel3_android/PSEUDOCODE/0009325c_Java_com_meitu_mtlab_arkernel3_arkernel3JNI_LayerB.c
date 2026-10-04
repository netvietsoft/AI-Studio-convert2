// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9325c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1calcBorderVertexPosition
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9325c | Size: 64 bytes | SHA256: bb208e800ee5bab5eee5df9551834fa1564faaf131598670bc81c2030815ac98
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction24calcBorderVertexPositionENS_6Float2Eff
// Strings referenced:
//   "Attempt to dereference null mtlabar3::Point2F"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1calcBorderVertexPosition(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x9325c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93260 */ mov x29, sp;
    /* 0x93264 */ cbz x4, #0x93280;
    /* 0x93268 */ fmov s3, s1;
    /* 0x9326c */ fmov s2, s0;
    /* 0x93270 */ mov x0, x2;
    /* 0x93274 */ ldp s0, s1, [x4];
    _ZN8mtlabar322LayerBorderInteraction24calcBorderVertexPositionENS_6Float2Eff();
    /* 0x9327c */ b #0x93294;
    /* 0x93280 */ adrp x2, #0x6d000;
    /* 0x93284 */ add x2, x2, #0xd55;
    sub_882c8();
    return x0;
}
