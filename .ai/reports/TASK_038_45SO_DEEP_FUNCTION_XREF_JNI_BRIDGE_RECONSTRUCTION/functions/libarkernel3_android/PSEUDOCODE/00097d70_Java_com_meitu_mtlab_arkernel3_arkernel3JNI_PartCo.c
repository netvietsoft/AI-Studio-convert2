// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97d70
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1insertCustomParamMap
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97d70 | Size: 232 bytes | SHA256: 4cd5b5f6f2bc235bdd4e833700e88aac49b980e4d6e1539712be5fe719eb599a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl20insertCustomParamMapEPKcS2_

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1insertCustomParamMap(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x97d70 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x97d74 */ stp x24, x23, [sp, #0x10];
    /* 0x97d78 */ stp x22, x21, [sp, #0x20];
    /* 0x97d7c */ stp x20, x19, [sp, #0x30];
    /* 0x97d80 */ mov x29, sp;
    /* 0x97d84 */ mov x19, x5;
    /* 0x97d88 */ mov x21, x4;
    /* 0x97d8c */ mov x22, x2;
    /* 0x97d90 */ mov x20, x0;
    /* 0x97d94 */ cbz x4, #0x97de0;
    /* 0x97d98 */ ldr x8, [x20];
    _ZN8mtlabar311PartControl20insertCustomParamMapEPKcS2_();
    return x0;
}
