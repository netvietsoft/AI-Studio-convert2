// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x897c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x897c8 | Size: 224 bytes | SHA256: bf42af747cb20e1c19ebf093a4c89e55d3bdbe201d44f9da3ecaaa03370090ba
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorInt_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x897c8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x897cc */ str x21, [sp, #0x10];
    /* 0x897d0 */ stp x20, x19, [sp, #0x20];
    /* 0x897d4 */ mov x29, sp;
    /* 0x897d8 */ mov x8, x2;
    /* 0x897dc */ mov x19, x2;
    /* 0x897e0 */ mov w20, w4;
    /* 0x897e4 */ ldr x10, [x8, #0x10]!;
    /* 0x897e8 */ ldur x9, [x8, #-8];
    /* 0x897ec */ cmp x9, x10;
    /* 0x897f0 */ b.hs #0x89800;
    sub_9af60();
    _ZdlPv();
    return x0;
    sub_9af4c();
}
