// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x947fc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DButtLift
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x947fc | Size: 28 bytes | SHA256: 29545884f36f3f7c85d646e4ff258261191b7ce778aae13b5061763c9cd76c14
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire25requireBodySlim3DButtLiftEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodySlim3DButtLift(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x947fc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94800 */ mov x29, sp;
    /* 0x94804 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire25requireBodySlim3DButtLiftEv();
    /* 0x9480c */ and w0, w0, #1;
    /* 0x94810 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
