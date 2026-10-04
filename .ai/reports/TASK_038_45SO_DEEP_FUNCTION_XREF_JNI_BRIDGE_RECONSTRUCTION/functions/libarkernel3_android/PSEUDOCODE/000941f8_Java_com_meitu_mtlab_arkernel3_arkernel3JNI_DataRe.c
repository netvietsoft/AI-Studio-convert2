// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x941f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x941f8 | Size: 28 bytes | SHA256: 345e1ac019ff91d662e0129ba2a7dfd3e12b3ca79573732576085ce293aa9c31
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireBodyMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x941f8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x941fc */ mov x29, sp;
    /* 0x94200 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireBodyMaskAdditionCPUEv();
    /* 0x94208 */ and w0, w0, #1;
    /* 0x9420c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
