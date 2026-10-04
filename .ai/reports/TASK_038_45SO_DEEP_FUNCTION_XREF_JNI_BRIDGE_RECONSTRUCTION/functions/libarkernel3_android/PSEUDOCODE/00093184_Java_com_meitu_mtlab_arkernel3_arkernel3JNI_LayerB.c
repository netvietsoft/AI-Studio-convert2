// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93184
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getAreaLimit
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93184 | Size: 28 bytes | SHA256: 94cf9b9f196bc279c385f758d7cb81d25d8610667803f98bebec147918d0a81f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar322LayerBorderInteraction12getAreaLimitEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerBorderInteraction_1getAreaLimit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93184 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93188 */ mov x29, sp;
    /* 0x9318c */ mov x0, x2;
    _ZN8mtlabar322LayerBorderInteraction12getAreaLimitEv();
    /* 0x93194 */ and w0, w0, #1;
    /* 0x93198 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
