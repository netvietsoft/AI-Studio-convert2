// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a52c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailEnumeration_1getDisplayName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a52c | Size: 68 bytes | SHA256: edb28efd76111756ea36b9cb602c4e248fac9eb3761a1b8985d97a3f209384ad
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar317DetailEnumeration14getDisplayNameEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DetailEnumeration_1getDisplayName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x8a52c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a530 */ str x19, [sp, #0x10];
    /* 0x8a534 */ mov x29, sp;
    /* 0x8a538 */ mov x19, x0;
    /* 0x8a53c */ mov x0, x2;
    _ZNK8mtlabar317DetailEnumeration14getDisplayNameEv();
    /* 0x8a544 */ cbz x0, #0x8a564;
    /* 0x8a548 */ ldr x8, [x19];
    /* 0x8a54c */ mov x1, x0;
    /* 0x8a550 */ ldr x2, [x8, #0x538];
    /* 0x8a554 */ mov x0, x19;
    return x0;
}
