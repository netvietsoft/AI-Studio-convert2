// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a958
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1getChildByName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a958 | Size: 148 bytes | SHA256: 5a22a75b58a71c8076e7cce2e7d6e3146d24e736a4eee4d5b955edf6b71aeb77
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar35Field14getChildByNameEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1getChildByName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x8a958 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8a95c */ stp x22, x21, [sp, #0x10];
    /* 0x8a960 */ stp x20, x19, [sp, #0x20];
    /* 0x8a964 */ mov x29, sp;
    /* 0x8a968 */ mov x21, x2;
    /* 0x8a96c */ cbz x4, #0x8a9c0;
    /* 0x8a970 */ ldr x8, [x0];
    /* 0x8a974 */ mov x1, x4;
    /* 0x8a978 */ mov x2, xzr;
    /* 0x8a97c */ mov x19, x4;
    /* 0x8a980 */ mov x20, x0;
    _ZN8mtlabar35Field14getChildByNameEPKc();
    _ZN8mtlabar35Field14getChildByNameEPKc();
    return x0;
}
