// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98638
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onPublicParamConfigurationLoadFinish
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98638 | Size: 148 bytes | SHA256: a35a545a09e4623f93f601cf131c63da45856cf9ceb1c2bcf4ea3ccfef511e2b
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InterfaceListener_1onPublicParamConfigurationLoadFinish(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x98638 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9863c */ stp x22, x21, [sp, #0x10];
    /* 0x98640 */ stp x20, x19, [sp, #0x20];
    /* 0x98644 */ mov x29, sp;
    /* 0x98648 */ mov x19, x4;
    /* 0x9864c */ mov x21, x2;
    /* 0x98650 */ mov x20, x0;
    /* 0x98654 */ cbz x4, #0x9867c;
    /* 0x98658 */ ldr x8, [x20];
    /* 0x9865c */ mov x0, x20;
    /* 0x98660 */ mov x1, x19;
    return x0;
}
