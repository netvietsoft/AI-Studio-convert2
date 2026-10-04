// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b6ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportVideoData_1path_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b6ac | Size: 172 bytes | SHA256: 329036248ddafc0aa5d97dd31f903876ff26c433a9255ee9dc96f90b83e13afd
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _ZdaPv, _Znam, strcpy, strlen

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportVideoData_1path_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0x8b6ac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x8b6b0 */ stp x22, x21, [sp, #0x10];
    /* 0x8b6b4 */ stp x20, x19, [sp, #0x20];
    /* 0x8b6b8 */ mov x29, sp;
    /* 0x8b6bc */ mov x19, x4;
    /* 0x8b6c0 */ mov x21, x2;
    /* 0x8b6c4 */ mov x20, x0;
    /* 0x8b6c8 */ cbz x4, #0x8b6f0;
    /* 0x8b6cc */ ldr x8, [x20];
    /* 0x8b6d0 */ mov x0, x20;
    /* 0x8b6d4 */ mov x1, x19;
    _ZdaPv();
    strlen();
    _Znam();
    strcpy();
    return x0;
}
