// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94460
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMaskAdditionGPU
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94460 | Size: 28 bytes | SHA256: 95ef4c1c6f8746401eaf49beb7149827dde8675b61bafcc3a3577d38daea83fe
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire27requireClothMaskAdditionGPUEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireClothMaskAdditionGPU(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94460 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94464 */ mov x29, sp;
    /* 0x94468 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire27requireClothMaskAdditionGPUEv();
    /* 0x94470 */ and w0, w0, #1;
    /* 0x94474 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
