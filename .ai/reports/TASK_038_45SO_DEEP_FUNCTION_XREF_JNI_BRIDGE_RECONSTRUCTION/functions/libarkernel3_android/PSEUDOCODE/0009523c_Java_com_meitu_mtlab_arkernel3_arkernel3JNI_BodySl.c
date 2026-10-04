// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9523c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControlInstance_1getEffectIsEffective
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9523c | Size: 28 bytes | SHA256: b2fb90b3378c2c2d02ffdb22b7a8f561e8220f95ef12e5b504e8d3c2e71da448
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323BodySlimControlInstance20getEffectIsEffectiveEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimControlInstance_1getEffectIsEffective(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9523c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95240 */ mov x29, sp;
    /* 0x95244 */ mov x0, x2;
    _ZN8mtlabar323BodySlimControlInstance20getEffectIsEffectiveEv();
    /* 0x9524c */ and w0, w0, #1;
    /* 0x95250 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
