// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x943f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x943f0 | Size: 28 bytes | SHA256: 59a26d80bdbdab1c0f9511e940090924c98d726649d5a04e3579616e2bf0a455
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireFaceContourMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x943f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x943f4 */ mov x29, sp;
    /* 0x943f8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire33requireFaceContourMaskAdditionCPUEv();
    /* 0x94400 */ and w0, w0, #1;
    /* 0x94404 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
