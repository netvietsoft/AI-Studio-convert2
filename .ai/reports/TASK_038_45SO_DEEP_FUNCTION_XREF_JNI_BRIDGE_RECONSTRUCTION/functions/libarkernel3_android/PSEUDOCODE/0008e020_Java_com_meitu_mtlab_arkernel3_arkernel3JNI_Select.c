// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e020
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setStrikeThrough
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e020 | Size: 16 bytes | SHA256: 76344d26718571aff4aef849d2a031abd5c4cb40fb7a980c38fbc9ccc6c89ca0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar327SelectionHighlightInterface16setStrikeThroughEb

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionHighlightInterface_1setStrikeThrough(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8e020 */ tst w4, #0xff;
    /* 0x8e024 */ mov x0, x2;
    /* 0x8e028 */ cset w1, ne;
    /* 0x8e02c */ b #0xa1430;
}
