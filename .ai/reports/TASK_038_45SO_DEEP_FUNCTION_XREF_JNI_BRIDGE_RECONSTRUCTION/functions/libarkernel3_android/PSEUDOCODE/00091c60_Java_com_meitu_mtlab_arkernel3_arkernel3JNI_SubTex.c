// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91c60
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getTextPathConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91c60 | Size: 68 bytes | SHA256: 394beef89dc1ee6feb06e1412f5b0d513c919614581f6b4226668c47c2bfaad4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction21getTextPathConfigPathEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getTextPathConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x91c60 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x91c64 */ str x19, [sp, #0x10];
    /* 0x91c68 */ mov x29, sp;
    /* 0x91c6c */ mov x19, x0;
    /* 0x91c70 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction21getTextPathConfigPathEv();
    /* 0x91c78 */ cbz x0, #0x91c98;
    /* 0x91c7c */ ldr x8, [x19];
    /* 0x91c80 */ mov x1, x0;
    /* 0x91c84 */ ldr x2, [x8, #0x538];
    /* 0x91c88 */ mov x0, x19;
    return x0;
}
