// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x942f4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMaskAdditionCPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x942f4 | Size: 28 bytes | SHA256: e653348674e109aa308b002d09dbf430b85f030cfce524ff65c8aea8dd977063
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireSkinMaskAdditionCPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkinMaskAdditionCPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x942f4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x942f8 */ mov x29, sp;
    /* 0x942fc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireSkinMaskAdditionCPUEv();
    /* 0x94304 */ and w0, w0, #1;
    /* 0x94308 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
