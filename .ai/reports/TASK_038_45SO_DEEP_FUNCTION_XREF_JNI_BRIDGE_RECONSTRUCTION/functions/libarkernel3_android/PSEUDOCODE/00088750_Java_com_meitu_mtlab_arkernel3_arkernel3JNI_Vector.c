// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x88750
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x88750 | Size: 272 bytes | SHA256: 3b90c046d3d6458078e11bb6eda8e2e4350568b2e94d431d3d82fd27f1c5a941
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "std::vector< mtlabar3::Color >::value_type const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorColor_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 68 instructions
    /* 0x88750 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x88754 */ str x21, [sp, #0x10];
    /* 0x88758 */ stp x20, x19, [sp, #0x20];
    /* 0x8875c */ mov x29, sp;
    /* 0x88760 */ cbz x4, #0x88790;
    /* 0x88764 */ mov x0, x2;
    /* 0x88768 */ mov x20, x4;
    /* 0x8876c */ mov x19, x2;
    /* 0x88770 */ ldr x8, [x0, #0x10]!;
    /* 0x88774 */ ldur x9, [x0, #-8];
    /* 0x88778 */ cmp x9, x8;
    sub_9a8b4();
    _ZdlPv();
    return x0;
    sub_9a8a0();
}
