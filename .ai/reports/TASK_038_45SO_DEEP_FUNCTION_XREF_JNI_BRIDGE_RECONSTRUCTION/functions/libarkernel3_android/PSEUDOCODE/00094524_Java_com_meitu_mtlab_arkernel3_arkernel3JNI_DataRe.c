// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94524
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionHuman
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94524 | Size: 28 bytes | SHA256: f3507109e981a0c1aff6e5624ff72537e1020be31b42b451688fd3cd2cf155fd
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire24requireBodyAdditionHumanEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyAdditionHuman(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94524 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94528 */ mov x29, sp;
    /* 0x9452c */ mov x0, x2;
    _ZNK8mtlabar311DataRequire24requireBodyAdditionHumanEv();
    /* 0x94534 */ and w0, w0, #1;
    /* 0x94538 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
