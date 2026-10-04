// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93444
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setScissorRect
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93444 | Size: 36 bytes | SHA256: 647db6a77b44243e3e7f39aa6a0cf8425fd8db6e27ebebfcaa8ee0f125aafde3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction14setScissorRectENS_5RectIE
// Strings referenced:
//   "Attempt to dereference null mtlabar3::RectI"

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1setScissorRect(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x93444 */ cbz x4, #0x93458;
    /* 0x93448 */ ldp x1, x8, [x4];
    /* 0x9344c */ mov x0, x2;
    /* 0x93450 */ mov x2, x8;
    /* 0x93454 */ b #0xa37e0;
    /* 0x93458 */ adrp x2, #0x6d000;
    /* 0x9345c */ add x2, x2, #0xb40;
    /* 0x93460 */ mov w1, #7;
    /* 0x93464 */ b #0x882c8;
}
