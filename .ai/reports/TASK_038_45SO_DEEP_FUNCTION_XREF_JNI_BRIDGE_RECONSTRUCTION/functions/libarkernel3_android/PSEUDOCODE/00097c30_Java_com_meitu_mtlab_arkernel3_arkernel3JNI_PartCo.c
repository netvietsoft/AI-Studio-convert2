// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97c30
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamKey
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97c30 | Size: 72 bytes | SHA256: a5ab58f8cb4165538a48a32408ac5de17c301ce63e7ada9eee11d2162ec5b24c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311PartControl17getCustomParamKeyEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamKey(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x97c30 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x97c34 */ str x19, [sp, #0x10];
    /* 0x97c38 */ mov x29, sp;
    /* 0x97c3c */ mov x1, x4;
    /* 0x97c40 */ mov x19, x0;
    /* 0x97c44 */ mov x0, x2;
    _ZNK8mtlabar311PartControl17getCustomParamKeyEm();
    /* 0x97c4c */ cbz x0, #0x97c6c;
    /* 0x97c50 */ ldr x8, [x19];
    /* 0x97c54 */ mov x1, x0;
    /* 0x97c58 */ ldr x2, [x8, #0x538];
    return x0;
}
