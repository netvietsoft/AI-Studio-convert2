// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96fa8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1getCurrentValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96fa8 | Size: 28 bytes | SHA256: ffe182ff7174ee139d939ffe27ef28eb6de87b002fa0f5aed1d5301096008b14
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311ParamSwitch15getCurrentValueEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1getCurrentValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96fa8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96fac */ mov x29, sp;
    /* 0x96fb0 */ mov x0, x2;
    _ZNK8mtlabar311ParamSwitch15getCurrentValueEv();
    /* 0x96fb8 */ and w0, w0, #1;
    /* 0x96fbc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
