// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93854
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextNoteDetail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93854 | Size: 132 bytes | SHA256: c2aaac26cb0693f1206595da2c11caa9a4cfe7c369666802d33354cfbdb61581
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils19parseTextNoteDetailEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextNoteDetail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x93854 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x93858 */ stp x22, x21, [sp, #0x10];
    /* 0x9385c */ stp x20, x19, [sp, #0x20];
    /* 0x93860 */ mov x29, sp;
    /* 0x93864 */ cbz x2, #0x938b0;
    /* 0x93868 */ ldr x8, [x0];
    /* 0x9386c */ mov x19, x2;
    /* 0x93870 */ mov x1, x2;
    /* 0x93874 */ mov x2, xzr;
    /* 0x93878 */ mov x20, x0;
    /* 0x9387c */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils19parseTextNoteDetailEPKc();
    _ZN8mtlabar39TextUtils19parseTextNoteDetailEPKc();
    return x0;
}
