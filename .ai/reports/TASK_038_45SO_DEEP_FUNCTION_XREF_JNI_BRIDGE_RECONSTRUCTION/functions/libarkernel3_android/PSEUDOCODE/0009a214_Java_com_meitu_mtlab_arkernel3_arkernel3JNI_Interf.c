// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a214
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1onUTF8Characters
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a214 | Size: 148 bytes | SHA256: f7bb68dbce19320fb833d9f43e94d014df27a98e5e3b77b82778e0e016e24301
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface16onUTF8CharactersEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1onUTF8Characters(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x9a214 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x9a218 */ stp x22, x21, [sp, #0x10];
    /* 0x9a21c */ stp x20, x19, [sp, #0x20];
    /* 0x9a220 */ mov x29, sp;
    /* 0x9a224 */ mov x21, x2;
    /* 0x9a228 */ cbz x4, #0x9a280;
    /* 0x9a22c */ ldr x8, [x0];
    /* 0x9a230 */ mov x1, x4;
    /* 0x9a234 */ mov x2, xzr;
    /* 0x9a238 */ mov x19, x4;
    /* 0x9a23c */ mov x20, x0;
    _ZN8mtlabar39Interface16onUTF8CharactersEPKc();
    return x0;
}
