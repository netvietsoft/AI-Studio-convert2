// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x99e68
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1deleteConfiguration
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x99e68 | Size: 32 bytes | SHA256: 714cede93221c7c7dae04ddc8890aea0e98a93d173861e61d1837e91ae1fa3c7
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface19deleteConfigurationEPNS_10EffectDataE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1deleteConfiguration(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x99e68 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x99e6c */ mov x29, sp;
    /* 0x99e70 */ mov x1, x4;
    /* 0x99e74 */ mov x0, x2;
    _ZN8mtlabar39Interface19deleteConfigurationEPNS_10EffectDataE();
    /* 0x99e7c */ and w0, w0, #1;
    /* 0x99e80 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
