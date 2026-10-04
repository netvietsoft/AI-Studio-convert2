// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88180
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88180 | Size: 328 bytes | SHA256: 4780e427d2d27cf349f6651fef35ee8a94be5be258d48f36aed13aee975202cc
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "std::vector< mtlabar3::ColorA >::value_type const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColorA_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 82 instructions
    /* 0x88180 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88184 */ str x21, [sp, #0x10];
    /* 0x88188 */ stp x20, x19, [sp, #0x20];
    /* 0x8818c */ mov x29, sp;
    /* 0x88190 */ cbz x4, #0x881c8;
    /* 0x88194 */ mov x0, x2;
    /* 0x88198 */ mov x20, x4;
    /* 0x8819c */ mov x19, x2;
    /* 0x881a0 */ ldr x8, [x0, #0x10]!;
    /* 0x881a4 */ ldur x9, [x0, #-8];
    /* 0x881a8 */ cmp x9, x8;
    sub_9a7ec();
    _ZdlPv();
    return x0;
    sub_9a7d8();
}
