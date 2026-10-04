// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91580
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getFontLibrary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91580 | Size: 68 bytes | SHA256: 0d95047a3980a93c29362e45facf5095e287c7dfe8b6ba5e9707ab1ec5b2fd00
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14getFontLibraryEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getFontLibrary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x91580 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x91584 */ str x19, [sp, #0x10];
    /* 0x91588 */ mov x29, sp;
    /* 0x9158c */ mov x19, x0;
    /* 0x91590 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction14getFontLibraryEv();
    /* 0x91598 */ cbz x0, #0x915b8;
    /* 0x9159c */ ldr x8, [x19];
    /* 0x915a0 */ mov x1, x0;
    /* 0x915a4 */ ldr x2, [x8, #0x538];
    /* 0x915a8 */ mov x0, x19;
    return x0;
}
