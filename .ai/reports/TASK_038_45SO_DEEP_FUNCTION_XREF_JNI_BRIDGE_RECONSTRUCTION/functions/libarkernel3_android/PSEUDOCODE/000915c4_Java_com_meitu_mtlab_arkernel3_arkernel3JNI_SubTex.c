// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x915c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setFontLibrary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x915c4 | Size: 148 bytes | SHA256: 5f0bdbeedacaa5156931a785a9529f15ad12a4d76151179fdb64ce15f8bd2a9c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction14setFontLibraryEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1setFontLibrary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x915c4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x915c8 */ stp x22, x21, [sp, #0x10];
    /* 0x915cc */ stp x20, x19, [sp, #0x20];
    /* 0x915d0 */ mov x29, sp;
    /* 0x915d4 */ mov x21, x2;
    /* 0x915d8 */ cbz x4, #0x91630;
    /* 0x915dc */ ldr x8, [x0];
    /* 0x915e0 */ mov x1, x4;
    /* 0x915e4 */ mov x2, xzr;
    /* 0x915e8 */ mov x19, x4;
    /* 0x915ec */ mov x20, x0;
    _ZN8mtlabar323SubTextLayerInteraction14setFontLibraryEPKc();
    return x0;
}
