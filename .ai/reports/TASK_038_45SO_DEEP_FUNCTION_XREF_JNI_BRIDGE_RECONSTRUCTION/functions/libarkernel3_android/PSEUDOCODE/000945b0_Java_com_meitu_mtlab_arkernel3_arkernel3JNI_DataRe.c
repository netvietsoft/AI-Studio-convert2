// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x945b0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARPointCloud
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x945b0 | Size: 28 bytes | SHA256: b310aea64a8ae4641a9554f4b5358001cfbdef958ef64d09ca06ffa236d5089f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire19requireARPointCloudEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARPointCloud(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x945b0 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x945b4 */ mov x29, sp;
    /* 0x945b8 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire19requireARPointCloudEv();
    /* 0x945c0 */ and w0, w0, #1;
    /* 0x945c4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
