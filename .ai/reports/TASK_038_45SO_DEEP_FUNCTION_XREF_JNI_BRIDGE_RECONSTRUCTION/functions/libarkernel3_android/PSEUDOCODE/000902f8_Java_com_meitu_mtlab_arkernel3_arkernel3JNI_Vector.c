// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x902f8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x902f8 | Size: 220 bytes | SHA256: 6744fd563b9dce70e716b3bcb44f5bc4b464dc02f05c6909a7f40565dd173d35
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorSelectionHighlightInterface_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x902f8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x902fc */ str x21, [sp, #0x10];
    /* 0x90300 */ stp x20, x19, [sp, #0x20];
    /* 0x90304 */ mov x29, sp;
    /* 0x90308 */ mov x0, x2;
    /* 0x9030c */ mov x19, x2;
    /* 0x90310 */ mov x20, x4;
    /* 0x90314 */ ldr x8, [x0, #0x10]!;
    /* 0x90318 */ ldur x21, [x0, #-8];
    /* 0x9031c */ cmp x21, x8;
    /* 0x90320 */ b.hs #0x9032c;
    sub_9bbf8();
    _ZdlPv();
    return x0;
    sub_9bbe4();
}
