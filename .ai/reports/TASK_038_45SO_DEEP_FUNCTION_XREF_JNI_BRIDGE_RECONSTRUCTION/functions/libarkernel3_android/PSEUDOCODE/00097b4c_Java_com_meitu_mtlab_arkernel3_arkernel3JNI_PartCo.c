// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97b4c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isAlready
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97b4c | Size: 28 bytes | SHA256: e816475efa8d1da6b28cff4dbb76781647c9cb4344842760eb28e3038b786238
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl9isAlreadyEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isAlready(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x97b4c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x97b50 */ mov x29, sp;
    /* 0x97b54 */ mov x0, x2;
    _ZN8mtlabar311PartControl9isAlreadyEv();
    /* 0x97b5c */ and w0, w0, #1;
    /* 0x97b60 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
