// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x942bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x942bc | Size: 28 bytes | SHA256: d5aa7897247eecfca1d724ae4d0956774d9b3b142ca83e054b9218fe91451a16
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire25requireSkyMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSkyMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x942bc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x942c0 */ mov x29, sp;
    /* 0x942c4 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire25requireSkyMaskAdditionGPUEv();
    /* 0x942cc */ and w0, w0, #1;
    /* 0x942d0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
