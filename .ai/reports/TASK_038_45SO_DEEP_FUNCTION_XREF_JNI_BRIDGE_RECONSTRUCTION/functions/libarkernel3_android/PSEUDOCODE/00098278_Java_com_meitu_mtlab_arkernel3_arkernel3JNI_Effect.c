// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98278
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getCustomParamValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98278 | Size: 72 bytes | SHA256: ae65998afbb12d98854913389612db4f8d5c5535f24d221ff176fa0d9e05c8ec
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar310EffectData19getCustomParamValueEm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getCustomParamValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x98278 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9827c */ str x19, [sp, #0x10];
    /* 0x98280 */ mov x29, sp;
    /* 0x98284 */ mov x1, x4;
    /* 0x98288 */ mov x19, x0;
    /* 0x9828c */ mov x0, x2;
    _ZNK8mtlabar310EffectData19getCustomParamValueEm();
    /* 0x98294 */ cbz x0, #0x982b4;
    /* 0x98298 */ ldr x8, [x19];
    /* 0x9829c */ mov x1, x0;
    /* 0x982a0 */ ldr x2, [x8, #0x538];
    return x0;
}
