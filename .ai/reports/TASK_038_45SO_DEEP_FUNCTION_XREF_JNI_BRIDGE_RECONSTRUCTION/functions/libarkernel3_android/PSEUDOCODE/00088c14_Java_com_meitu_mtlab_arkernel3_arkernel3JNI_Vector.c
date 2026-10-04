// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88c14
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88c14 | Size: 260 bytes | SHA256: 9577ae54564c85e0c30b1e7331cbb1c9dfc7f9a8fc408ab5dcdf4f4cf829ffe6
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "std::vector< mtlabar3::Float2 >::value_type const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorPoint2F_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x88c14 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88c18 */ str x21, [sp, #0x10];
    /* 0x88c1c */ stp x20, x19, [sp, #0x20];
    /* 0x88c20 */ mov x29, sp;
    /* 0x88c24 */ cbz x4, #0x88c50;
    /* 0x88c28 */ mov x0, x2;
    /* 0x88c2c */ mov x20, x4;
    /* 0x88c30 */ mov x19, x2;
    /* 0x88c34 */ ldr x8, [x0, #0x10]!;
    /* 0x88c38 */ ldur x21, [x0, #-8];
    /* 0x88c3c */ cmp x21, x8;
    sub_9a93c();
    _ZdlPv();
    return x0;
    sub_9a928();
}
