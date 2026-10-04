// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x90764
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionAnimationInterface_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x90764 | Size: 220 bytes | SHA256: 1fdcda7a6ee7f6ee0ddf3dd8011ff636b94f0b78bace257f5f6af68ba40ccc27
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionAnimationInterface_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x90764 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x90768 */ str x21, [sp, #0x10];
    /* 0x9076c */ stp x20, x19, [sp, #0x20];
    /* 0x90770 */ mov x29, sp;
    /* 0x90774 */ mov x0, x2;
    /* 0x90778 */ mov x19, x2;
    /* 0x9077c */ mov x20, x4;
    /* 0x90780 */ ldr x8, [x0, #0x10]!;
    /* 0x90784 */ ldur x21, [x0, #-8];
    /* 0x90788 */ cmp x21, x8;
    /* 0x9078c */ b.hs #0x90798;
    sub_9bc80();
    _ZdlPv();
    return x0;
    sub_9bc6c();
}
