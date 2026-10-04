// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95c14
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setUseArrowHead
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95c14 | Size: 16 bytes | SHA256: 609e558992d6b94563e4a0ac533765345043779846048637ba1190c6c54f0b96
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310BrushCache15setUseArrowHeadEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BrushCache_1setUseArrowHead(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x95c14 */ tst w4, #0xff;
    /* 0x95c18 */ mov x0, x2;
    /* 0x95c1c */ cset w1, ne;
    /* 0x95c20 */ b #0xa4a80;
}
