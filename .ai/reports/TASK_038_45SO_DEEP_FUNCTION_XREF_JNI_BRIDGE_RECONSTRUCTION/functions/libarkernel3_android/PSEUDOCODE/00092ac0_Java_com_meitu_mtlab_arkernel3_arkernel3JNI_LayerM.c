// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92ac0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92ac0 | Size: 68 bytes | SHA256: 09ee4904bc18fcf060d7d26e9f08b885f82b7127053d7d46ed328de224dd4029
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerMaskInteraction13getConfigPathEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerMaskInteraction_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x92ac0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x92ac4 */ str x19, [sp, #0x10];
    /* 0x92ac8 */ mov x29, sp;
    /* 0x92acc */ mov x19, x0;
    /* 0x92ad0 */ mov x0, x2;
    _ZN8mtlabar320LayerMaskInteraction13getConfigPathEv();
    /* 0x92ad8 */ cbz x0, #0x92af8;
    /* 0x92adc */ ldr x8, [x19];
    /* 0x92ae0 */ mov x1, x0;
    /* 0x92ae4 */ ldr x2, [x8, #0x538];
    /* 0x92ae8 */ mov x0, x19;
    return x0;
}
