// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f8ac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f8ac | Size: 28 bytes | SHA256: a25785f3e594251f0679d08890860245c3345a8544157751f7a85eaeb6b1957c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321ActiveWordBgInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ActiveWordBgInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f8ac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f8b0 */ mov x29, sp;
    /* 0x8f8b4 */ mov x0, x2;
    _ZNK8mtlabar321ActiveWordBgInterface9getEnableEv();
    /* 0x8f8bc */ and w0, w0, #1;
    /* 0x8f8c0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
