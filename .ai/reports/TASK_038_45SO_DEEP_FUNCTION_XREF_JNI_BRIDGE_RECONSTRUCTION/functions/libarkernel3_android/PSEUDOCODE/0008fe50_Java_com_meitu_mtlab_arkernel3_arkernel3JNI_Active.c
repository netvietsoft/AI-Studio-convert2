// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8fe50
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getFontLibrary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8fe50 | Size: 64 bytes | SHA256: 0f1844fa28e1520ef75c4cd66817d4a79e535c83b59624d292bb65301c59e60e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324ActiveWordStyleInterface14getFontLibraryEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordStyleInterface_1getFontLibrary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8fe50 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8fe54 */ str x19, [sp, #0x10];
    /* 0x8fe58 */ mov x29, sp;
    /* 0x8fe5c */ mov x19, x0;
    /* 0x8fe60 */ mov x0, x2;
    _ZNK8mtlabar324ActiveWordStyleInterface14getFontLibraryEv();
    /* 0x8fe68 */ ldr x8, [x19];
    /* 0x8fe6c */ ldrb w9, [x0];
    /* 0x8fe70 */ ldr x10, [x0, #0x10];
    /* 0x8fe74 */ tst w9, #1;
    /* 0x8fe78 */ ldr x2, [x8, #0x538];
}
