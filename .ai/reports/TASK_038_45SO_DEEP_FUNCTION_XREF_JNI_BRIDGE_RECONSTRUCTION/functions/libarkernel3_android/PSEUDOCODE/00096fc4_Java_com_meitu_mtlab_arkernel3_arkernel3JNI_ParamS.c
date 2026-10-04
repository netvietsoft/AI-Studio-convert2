// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x96fc4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1getDefaultValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x96fc4 | Size: 28 bytes | SHA256: d69c6727dc2eb0e490f583b25af5bbbad2731885ae0441c694b123611784b969
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311ParamSwitch15getDefaultValueEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ParamSwitch_1getDefaultValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x96fc4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x96fc8 */ mov x29, sp;
    /* 0x96fcc */ mov x0, x2;
    _ZNK8mtlabar311ParamSwitch15getDefaultValueEv();
    /* 0x96fd4 */ and w0, w0, #1;
    /* 0x96fd8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
