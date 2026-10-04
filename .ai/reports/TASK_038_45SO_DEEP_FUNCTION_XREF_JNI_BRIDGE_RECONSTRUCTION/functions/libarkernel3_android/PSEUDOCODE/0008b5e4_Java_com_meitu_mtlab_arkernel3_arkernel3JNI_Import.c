// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b5e4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportImageData_1path_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b5e4 | Size: 172 bytes | SHA256: c70ce83dc0c1aa432d353fefc360639be050d62b30ed1680448cbf24b6200531
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZdaPv, _Znam, strcpy, strlen

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportImageData_1path_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x8b5e4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8b5e8 */ stp x22, x21, [sp, #0x10];
    /* 0x8b5ec */ stp x20, x19, [sp, #0x20];
    /* 0x8b5f0 */ mov x29, sp;
    /* 0x8b5f4 */ mov x19, x4;
    /* 0x8b5f8 */ mov x21, x2;
    /* 0x8b5fc */ mov x20, x0;
    /* 0x8b600 */ cbz x4, #0x8b628;
    /* 0x8b604 */ ldr x8, [x20];
    /* 0x8b608 */ mov x0, x20;
    /* 0x8b60c */ mov x1, x19;
    _ZdaPv();
    strlen();
    _Znam();
    strcpy();
    return x0;
}
