// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f4f0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getText
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f4f0 | Size: 64 bytes | SHA256: 20925b3083849363a8cb3abf36e20e6ccdd509f5581da4a9ee193b2072d2a903
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar331TextInactiveTextConfigInterface7getTextEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextInactiveTextConfigInterface_1getText(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8f4f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8f4f4 */ str x19, [sp, #0x10];
    /* 0x8f4f8 */ mov x29, sp;
    /* 0x8f4fc */ mov x19, x0;
    /* 0x8f500 */ mov x0, x2;
    _ZNK8mtlabar331TextInactiveTextConfigInterface7getTextEv();
    /* 0x8f508 */ ldr x8, [x19];
    /* 0x8f50c */ ldrb w9, [x0];
    /* 0x8f510 */ ldr x10, [x0, #0x10];
    /* 0x8f514 */ tst w9, #1;
    /* 0x8f518 */ ldr x2, [x8, #0x538];
}
