// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97cc0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamValueWithKey
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97cc0 | Size: 176 bytes | SHA256: e95003cf0447d1c1968cde647efc383df7ae90372409aa667e3a4c890ea7573a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311PartControl26getCustomParamValueWithKeyEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamValueWithKey(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x97cc0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x97cc4 */ stp x22, x21, [sp, #0x10];
    /* 0x97cc8 */ stp x20, x19, [sp, #0x20];
    /* 0x97ccc */ mov x29, sp;
    /* 0x97cd0 */ mov x19, x4;
    /* 0x97cd4 */ mov x22, x2;
    /* 0x97cd8 */ mov x20, x0;
    /* 0x97cdc */ cbz x4, #0x97d08;
    /* 0x97ce0 */ ldr x8, [x20];
    /* 0x97ce4 */ mov x0, x20;
    /* 0x97ce8 */ mov x1, x19;
    _ZNK8mtlabar311PartControl26getCustomParamValueWithKeyEPKc();
    return x0;
}
