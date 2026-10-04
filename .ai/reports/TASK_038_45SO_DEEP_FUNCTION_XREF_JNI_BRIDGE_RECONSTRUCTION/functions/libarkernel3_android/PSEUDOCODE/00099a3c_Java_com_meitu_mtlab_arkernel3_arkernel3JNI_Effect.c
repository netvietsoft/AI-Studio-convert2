// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99a3c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectDataListener_1onConfigurationChanged
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99a3c | Size: 168 bytes | SHA256: 081bf3d1277b4fd0d5310dce628af369403f37f60e3a4d985aff10ffe8bbe388
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectDataListener_1onConfigurationChanged(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x99a3c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x99a40 */ str x23, [sp, #0x10];
    /* 0x99a44 */ stp x22, x21, [sp, #0x20];
    /* 0x99a48 */ stp x20, x19, [sp, #0x30];
    /* 0x99a4c */ mov x29, sp;
    /* 0x99a50 */ mov x19, x6;
    /* 0x99a54 */ mov x21, x4;
    /* 0x99a58 */ mov x22, x2;
    /* 0x99a5c */ mov x20, x0;
    /* 0x99a60 */ cbz x6, #0x99a88;
    /* 0x99a64 */ ldr x8, [x20];
    return x0;
}
