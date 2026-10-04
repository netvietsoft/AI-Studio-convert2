// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9486c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyBeautyBGFilling
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9486c | Size: 28 bytes | SHA256: cbab795447fa0d2d12c29f6b40958114134803f8dee5c387003bf18a08988ceb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire26requireBodyBeautyBGFillingEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireBodyBeautyBGFilling(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9486c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94870 */ mov x29, sp;
    /* 0x94874 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire26requireBodyBeautyBGFillingEv();
    /* 0x9487c */ and w0, w0, #1;
    /* 0x94880 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
