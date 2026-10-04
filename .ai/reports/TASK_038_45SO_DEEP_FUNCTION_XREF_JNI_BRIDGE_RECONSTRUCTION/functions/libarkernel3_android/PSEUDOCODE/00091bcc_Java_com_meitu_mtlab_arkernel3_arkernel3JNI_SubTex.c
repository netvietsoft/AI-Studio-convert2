// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91bcc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setTextPathConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91bcc | Size: 148 bytes | SHA256: e3817035b244ed39b1ccdc3641b78ebf01b7d7dfefbf55d6abbb730191bea90f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction21setTextPathConfigPathEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setTextPathConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x91bcc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x91bd0 */ stp x22, x21, [sp, #0x10];
    /* 0x91bd4 */ stp x20, x19, [sp, #0x20];
    /* 0x91bd8 */ mov x29, sp;
    /* 0x91bdc */ mov x21, x2;
    /* 0x91be0 */ cbz x4, #0x91c38;
    /* 0x91be4 */ ldr x8, [x0];
    /* 0x91be8 */ mov x1, x4;
    /* 0x91bec */ mov x2, xzr;
    /* 0x91bf0 */ mov x19, x4;
    /* 0x91bf4 */ mov x20, x0;
    _ZN8mtlabar323SubTextLayerInteraction21setTextPathConfigPathEPKc();
    return x0;
}
