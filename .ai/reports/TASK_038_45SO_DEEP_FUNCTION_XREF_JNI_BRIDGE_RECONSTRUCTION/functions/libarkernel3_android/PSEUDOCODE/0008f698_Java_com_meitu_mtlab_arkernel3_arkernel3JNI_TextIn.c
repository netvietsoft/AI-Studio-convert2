// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f698
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getAnimationConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f698 | Size: 64 bytes | SHA256: bb703885d6297d1a702584fac685cbbad30b4dfc1ac9dddf0826215fadb4f023
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar331TextInactiveTextConfigInterface22getAnimationConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getAnimationConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8f698 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8f69c */ str x19, [sp, #0x10];
    /* 0x8f6a0 */ mov x29, sp;
    /* 0x8f6a4 */ mov x19, x0;
    /* 0x8f6a8 */ mov x0, x2;
    _ZNK8mtlabar331TextInactiveTextConfigInterface22getAnimationConfigPathEv();
    /* 0x8f6b0 */ ldr x8, [x19];
    /* 0x8f6b4 */ ldrb w9, [x0];
    /* 0x8f6b8 */ ldr x10, [x0, #0x10];
    /* 0x8f6bc */ tst w9, #1;
    /* 0x8f6c0 */ ldr x2, [x8, #0x538];
}
