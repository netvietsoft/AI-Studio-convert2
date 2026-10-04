// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x947c4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DShoulderBrace
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x947c4 | Size: 28 bytes | SHA256: 56837a8139bad4d3a0fa994b306594c8a22fd77135e231441da86881e07b2d98
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire30requireBodySlim3DShoulderBraceEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DShoulderBrace(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x947c4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x947c8 */ mov x29, sp;
    /* 0x947cc */ mov x0, x2;
    _ZNK8mtlabar311DataRequire30requireBodySlim3DShoulderBraceEv();
    /* 0x947d4 */ and w0, w0, #1;
    /* 0x947d8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
