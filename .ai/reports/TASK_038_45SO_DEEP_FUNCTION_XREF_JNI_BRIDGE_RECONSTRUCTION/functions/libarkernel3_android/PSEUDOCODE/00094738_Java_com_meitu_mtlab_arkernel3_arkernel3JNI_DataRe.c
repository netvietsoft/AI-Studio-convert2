// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94738
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireOutStandingMask
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94738 | Size: 28 bytes | SHA256: 1c00a3905216e874a40f0408ea7b2c6a2ca2d8285d87b251c49ef2bf7d56a4ca
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire22requireOutStandingMaskEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireOutStandingMask(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94738 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9473c */ mov x29, sp;
    /* 0x94740 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire22requireOutStandingMaskEv();
    /* 0x94748 */ and w0, w0, #1;
    /* 0x9474c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
