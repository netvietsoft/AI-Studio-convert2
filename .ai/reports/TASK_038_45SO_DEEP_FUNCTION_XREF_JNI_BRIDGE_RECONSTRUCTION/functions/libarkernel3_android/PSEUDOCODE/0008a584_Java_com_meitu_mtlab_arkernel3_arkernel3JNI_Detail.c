// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a584
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailEnumeration_1getElementDisplayName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a584 | Size: 72 bytes | SHA256: e7a938e29f3c1d2914071870c8c8df75f9d8d00969f8c9fc5c476a500914efdd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar317DetailEnumeration21getElementDisplayNameEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailEnumeration_1getElementDisplayName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8a584 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a588 */ str x19, [sp, #0x10];
    /* 0x8a58c */ mov x29, sp;
    /* 0x8a590 */ mov x1, x4;
    /* 0x8a594 */ mov x19, x0;
    /* 0x8a598 */ mov x0, x2;
    _ZNK8mtlabar317DetailEnumeration21getElementDisplayNameEm();
    /* 0x8a5a0 */ cbz x0, #0x8a5c0;
    /* 0x8a5a4 */ ldr x8, [x19];
    /* 0x8a5a8 */ mov x1, x0;
    /* 0x8a5ac */ ldr x2, [x8, #0x538];
    return x0;
}
