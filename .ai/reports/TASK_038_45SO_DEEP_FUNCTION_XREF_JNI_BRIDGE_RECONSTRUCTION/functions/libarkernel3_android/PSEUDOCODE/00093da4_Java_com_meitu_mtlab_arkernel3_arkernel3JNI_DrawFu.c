// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93da4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1drawFrame
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93da4 | Size: 64 bytes | SHA256: 92d92969639b0c6e46e52c475a1f15fc74a39b5939d6dc12159bafffc0ee5a03
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DrawFunctionCallback_1drawFrame(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x93da4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93da8 */ mov x29, sp;
    /* 0x93dac */ ldr x10, [x2];
    /* 0x93db0 */ ldr w8, [x29, #0x18];
    /* 0x93db4 */ mov x9, x5;
    /* 0x93db8 */ ldr w5, [x29, #0x20];
    /* 0x93dbc */ mov x3, x7;
    /* 0x93dc0 */ mov x0, x2;
    /* 0x93dc4 */ ldr x10, [x10, #0x30];
    /* 0x93dc8 */ mov x1, x4;
    /* 0x93dcc */ mov x2, x9;
    return x0;
}
