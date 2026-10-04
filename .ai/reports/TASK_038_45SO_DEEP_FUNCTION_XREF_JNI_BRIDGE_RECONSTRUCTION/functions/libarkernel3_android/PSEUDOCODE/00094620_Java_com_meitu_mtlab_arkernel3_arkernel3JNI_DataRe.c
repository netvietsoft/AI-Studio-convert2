// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94620
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARInstantPlacement
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94620 | Size: 28 bytes | SHA256: 863a594d63cdf80031ab67d11f66f7b77764fea0f6a52b36a55a05f1f7251cc9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire25requireARInstantPlacementEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireARInstantPlacement(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94620 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94624 */ mov x29, sp;
    /* 0x94628 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire25requireARInstantPlacementEv();
    /* 0x94630 */ and w0, w0, #1;
    /* 0x94634 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
