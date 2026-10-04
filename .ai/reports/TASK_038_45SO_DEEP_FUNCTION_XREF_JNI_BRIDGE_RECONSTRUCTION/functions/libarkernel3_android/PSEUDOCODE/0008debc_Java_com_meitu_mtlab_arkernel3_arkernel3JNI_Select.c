// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8debc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setCustomizeStyle
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8debc | Size: 16 bytes | SHA256: c80c4ace41478a27d57840f5071f6a9ea49c07017dca12670fcf521924a8e812
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface17setCustomizeStyleEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setCustomizeStyle(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8debc */ tst w4, #0xff;
    /* 0x8dec0 */ mov x0, x2;
    /* 0x8dec4 */ cset w1, ne;
    /* 0x8dec8 */ b #0xa1370;
}
