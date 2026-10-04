// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97ae4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartSummary
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97ae4 | Size: 68 bytes | SHA256: 3073aeb1b11f2fc0635be12de7b70f1d755bb8d75bdd7491be38d65c343ee62a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl14getPartSummaryEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartSummary(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x97ae4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x97ae8 */ str x19, [sp, #0x10];
    /* 0x97aec */ mov x29, sp;
    /* 0x97af0 */ mov x19, x0;
    /* 0x97af4 */ mov x0, x2;
    _ZN8mtlabar311PartControl14getPartSummaryEv();
    /* 0x97afc */ cbz x0, #0x97b1c;
    /* 0x97b00 */ ldr x8, [x19];
    /* 0x97b04 */ mov x1, x0;
    /* 0x97b08 */ ldr x2, [x8, #0x538];
    /* 0x97b0c */ mov x0, x19;
    return x0;
}
