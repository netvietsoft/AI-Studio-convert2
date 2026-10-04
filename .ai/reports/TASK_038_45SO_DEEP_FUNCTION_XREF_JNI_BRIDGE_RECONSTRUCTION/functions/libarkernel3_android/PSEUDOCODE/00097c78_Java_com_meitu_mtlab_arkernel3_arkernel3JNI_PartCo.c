// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97c78
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97c78 | Size: 72 bytes | SHA256: 5d160ff8bd650d396d305b75061cd21ccf43dd11befb31c49580b80b1caa9e1b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311PartControl19getCustomParamValueEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getCustomParamValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x97c78 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x97c7c */ str x19, [sp, #0x10];
    /* 0x97c80 */ mov x29, sp;
    /* 0x97c84 */ mov x1, x4;
    /* 0x97c88 */ mov x19, x0;
    /* 0x97c8c */ mov x0, x2;
    _ZNK8mtlabar311PartControl19getCustomParamValueEm();
    /* 0x97c94 */ cbz x0, #0x97cb4;
    /* 0x97c98 */ ldr x8, [x19];
    /* 0x97c9c */ mov x1, x0;
    /* 0x97ca0 */ ldr x2, [x8, #0x538];
    return x0;
}
