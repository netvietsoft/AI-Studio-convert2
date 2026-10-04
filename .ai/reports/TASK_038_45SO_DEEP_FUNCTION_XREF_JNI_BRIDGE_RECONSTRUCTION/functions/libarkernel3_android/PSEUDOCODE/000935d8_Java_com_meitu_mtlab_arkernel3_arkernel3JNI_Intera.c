// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x935d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InteractionInterface_1resizeCanvas
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x935d8 | Size: 32 bytes | SHA256: 45a49cfaa905c3b1d4cad9738838f025b74e7656aa138ccef7cb677a54ce66f5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320InteractionInterface12resizeCanvasERKNS_14CanvasPropertyE
// Strings referenced:
//   "mtlabar3::CanvasProperty const & reference is null"

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_InteractionInterface_1resizeCanvas(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x935d8 */ cbz x4, #0x935e8;
    /* 0x935dc */ mov x0, x2;
    /* 0x935e0 */ mov x1, x4;
    /* 0x935e4 */ b #0xa38f0;
    /* 0x935e8 */ adrp x2, #0x6d000;
    /* 0x935ec */ add x2, x2, #0xdf4;
    /* 0x935f0 */ mov w1, #7;
    /* 0x935f4 */ b #0x882c8;
}
