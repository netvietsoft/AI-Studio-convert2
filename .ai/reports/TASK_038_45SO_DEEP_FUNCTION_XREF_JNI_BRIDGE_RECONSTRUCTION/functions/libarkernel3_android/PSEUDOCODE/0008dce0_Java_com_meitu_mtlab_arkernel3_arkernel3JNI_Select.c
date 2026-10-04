// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dce0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setDisplayInASRTime
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dce0 | Size: 16 bytes | SHA256: 98742dfcaa3d147ed2f89b11344211ce79062ad6c23c97e016e996790b338df4
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface19setDisplayInASRTimeEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setDisplayInASRTime(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8dce0 */ tst w4, #0xff;
    /* 0x8dce4 */ mov x0, x2;
    /* 0x8dce8 */ cset w1, ne;
    /* 0x8dcec */ b #0xa12d0;
}
