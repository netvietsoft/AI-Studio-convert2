// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f194
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f194 | Size: 28 bytes | SHA256: 2578ab0ea9d173f8eb80846f715c47a863387fe387b5b2013cc1cbe62d4cf093
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326CharSVGBackgroundInterface11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f194 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f198 */ mov x29, sp;
    /* 0x8f19c */ mov x0, x2;
    _ZNK8mtlabar326CharSVGBackgroundInterface11getEditableEv();
    /* 0x8f1a4 */ and w0, w0, #1;
    /* 0x8f1a8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
