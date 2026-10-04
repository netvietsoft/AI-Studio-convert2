// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94700
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSpaceNormal
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94700 | Size: 28 bytes | SHA256: 814de4e9bed14ed026a8f4c31beadd286f7efa68458de859bcd4a4c798c3f71d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire18requireSpaceNormalEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireSpaceNormal(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94700 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94704 */ mov x29, sp;
    /* 0x94708 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire18requireSpaceNormalEv();
    /* 0x94710 */ and w0, w0, #1;
    /* 0x94714 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
