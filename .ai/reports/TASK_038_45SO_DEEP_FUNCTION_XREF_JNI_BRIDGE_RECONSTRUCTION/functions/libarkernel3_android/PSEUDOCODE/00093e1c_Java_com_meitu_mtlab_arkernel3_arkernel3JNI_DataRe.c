// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e1c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceImageGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e1c | Size: 28 bytes | SHA256: 49c1e17cd2cf1e7143dd3b2fa4837a3ac965ad33f694e0df15e7f0fde3e56e32
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire21requireSourceImageGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSourceImageGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e1c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e20 */ mov x29, sp;
    /* 0x93e24 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire21requireSourceImageGPUEv();
    /* 0x93e2c */ and w0, w0, #1;
    /* 0x93e30 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
