// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94850
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DTrapezius
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94850 | Size: 28 bytes | SHA256: b1d1e65da58093ad40489e20b399666592be8bbe9d48081a6e635b590207f373
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireBodySlim3DTrapeziusEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DTrapezius(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94850 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94854 */ mov x29, sp;
    /* 0x94858 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireBodySlim3DTrapeziusEv();
    /* 0x94860 */ and w0, w0, #1;
    /* 0x94864 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
