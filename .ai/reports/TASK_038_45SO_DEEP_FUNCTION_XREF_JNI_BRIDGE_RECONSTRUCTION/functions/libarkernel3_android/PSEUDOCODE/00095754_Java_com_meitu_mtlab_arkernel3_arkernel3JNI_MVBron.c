// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95754
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVBronzersPenControl_1setCurrentPenID
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95754 | Size: 148 bytes | SHA256: fcfca932b2791623a18ead4e3c6af318297a1b54734c4304a813a9b4116e9605
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320MVBronzersPenControl15setCurrentPenIDEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MVBronzersPenControl_1setCurrentPenID(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x95754 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x95758 */ stp x22, x21, [sp, #0x10];
    /* 0x9575c */ stp x20, x19, [sp, #0x20];
    /* 0x95760 */ mov x29, sp;
    /* 0x95764 */ mov x21, x2;
    /* 0x95768 */ cbz x4, #0x957c0;
    /* 0x9576c */ ldr x8, [x0];
    /* 0x95770 */ mov x1, x4;
    /* 0x95774 */ mov x2, xzr;
    /* 0x95778 */ mov x19, x4;
    /* 0x9577c */ mov x20, x0;
    _ZN8mtlabar320MVBronzersPenControl15setCurrentPenIDEPKc();
    return x0;
}
