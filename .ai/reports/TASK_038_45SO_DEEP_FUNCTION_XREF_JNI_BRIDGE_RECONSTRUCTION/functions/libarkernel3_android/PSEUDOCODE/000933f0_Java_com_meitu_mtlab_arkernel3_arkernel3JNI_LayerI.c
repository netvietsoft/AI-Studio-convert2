// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x933f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getTimestamp
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x933f0 | Size: 24 bytes | SHA256: 4095542a360e35bc1d229df1340934907078955a6137ff11feabe1ac76d8f4ca
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction12getTimestampEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getTimestamp(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x933f0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x933f4 */ mov x29, sp;
    /* 0x933f8 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction12getTimestampEv();
    /* 0x93400 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
