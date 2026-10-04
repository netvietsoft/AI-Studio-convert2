// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x938d8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseJsonNoteDetail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x938d8 | Size: 132 bytes | SHA256: 31bc72609ee39c1550051e224c7bfd4973e0183dbc5b55d53650e3fcbf2549bf
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils19parseJsonNoteDetailEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseJsonNoteDetail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x938d8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x938dc */ stp x22, x21, [sp, #0x10];
    /* 0x938e0 */ stp x20, x19, [sp, #0x20];
    /* 0x938e4 */ mov x29, sp;
    /* 0x938e8 */ cbz x2, #0x93934;
    /* 0x938ec */ ldr x8, [x0];
    /* 0x938f0 */ mov x19, x2;
    /* 0x938f4 */ mov x1, x2;
    /* 0x938f8 */ mov x2, xzr;
    /* 0x938fc */ mov x20, x0;
    /* 0x93900 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils19parseJsonNoteDetailEPKc();
    _ZN8mtlabar39TextUtils19parseJsonNoteDetailEPKc();
    return x0;
}
