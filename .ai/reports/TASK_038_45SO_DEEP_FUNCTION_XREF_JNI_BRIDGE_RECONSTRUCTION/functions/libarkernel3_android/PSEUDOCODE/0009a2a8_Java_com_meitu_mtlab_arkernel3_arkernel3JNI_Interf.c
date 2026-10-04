// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a2a8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1postMessage
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a2a8 | Size: 256 bytes | SHA256: 0f4f580f333f87b6d18b0154d1e9696cc8dc83b150755c7c5ac492860705c50e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface11postMessageEPKcS2_b

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1postMessage(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x9a2a8 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x9a2ac */ str x25, [sp, #0x10];
    /* 0x9a2b0 */ stp x24, x23, [sp, #0x20];
    /* 0x9a2b4 */ stp x22, x21, [sp, #0x30];
    /* 0x9a2b8 */ stp x20, x19, [sp, #0x40];
    /* 0x9a2bc */ mov x29, sp;
    /* 0x9a2c0 */ mov w23, w6;
    /* 0x9a2c4 */ mov x19, x5;
    /* 0x9a2c8 */ mov x21, x4;
    /* 0x9a2cc */ mov x22, x2;
    /* 0x9a2d0 */ mov x20, x0;
    _ZN8mtlabar39Interface11postMessageEPKcS2_b();
    return x0;
}
