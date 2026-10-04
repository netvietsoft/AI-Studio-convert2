// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94348
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94348 | Size: 28 bytes | SHA256: 21bbd42159312002f9a594a59b9311363828c3ef2f8c4481caa2ccf572eb3a14
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireHeadMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireHeadMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94348 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9434c */ mov x29, sp;
    /* 0x94350 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireHeadMaskAdditionCPUEv();
    /* 0x94358 */ and w0, w0, #1;
    /* 0x9435c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
