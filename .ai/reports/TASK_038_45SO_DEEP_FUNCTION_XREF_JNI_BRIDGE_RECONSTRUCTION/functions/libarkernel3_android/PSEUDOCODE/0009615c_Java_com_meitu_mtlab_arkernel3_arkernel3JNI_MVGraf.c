// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9615c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setIsInBrushDrawing
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9615c | Size: 16 bytes | SHA256: 194d7a85b7778f64af7633db0647a2ad640000011d81b15dd96b57c177ff4088
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVGraffitiPenControl19setIsInBrushDrawingEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVGraffitiPenControl_1setIsInBrushDrawing(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x9615c */ tst w4, #0xff;
    /* 0x96160 */ mov x0, x2;
    /* 0x96164 */ cset w1, ne;
    /* 0x96168 */ b #0xa4bf0;
}
