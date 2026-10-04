// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9424c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9424c | Size: 28 bytes | SHA256: 2261a6ef2c3537a29fa534ceb6fb10e419e03a64a0843023883ce77c28c8e072
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHairMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9424c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94250 */ mov x29, sp;
    /* 0x94254 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv();
    /* 0x9425c */ and w0, w0, #1;
    /* 0x94260 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
