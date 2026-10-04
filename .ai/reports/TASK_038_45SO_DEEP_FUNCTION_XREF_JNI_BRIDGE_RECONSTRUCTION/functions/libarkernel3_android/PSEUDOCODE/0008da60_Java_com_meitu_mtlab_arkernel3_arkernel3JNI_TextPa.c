// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8da60
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnableBend
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8da60 | Size: 28 bytes | SHA256: a7e6c1afc65516d0a57b3008be81a7df3c20c866c4e559db847508a5cfb88231
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration13getEnableBendEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnableBend(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8da60 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8da64 */ mov x29, sp;
    /* 0x8da68 */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration13getEnableBendEv();
    /* 0x8da70 */ and w0, w0, #1;
    /* 0x8da74 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
