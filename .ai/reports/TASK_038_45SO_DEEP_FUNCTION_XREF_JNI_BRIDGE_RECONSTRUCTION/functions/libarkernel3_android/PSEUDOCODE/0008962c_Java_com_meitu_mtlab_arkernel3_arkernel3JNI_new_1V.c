// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8962c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorInt_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8962c | Size: 72 bytes | SHA256: 8e13450d3b4b7019974ae33521794862a7af7cff3c9e46d56111dbc821582b4b
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorInt_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x8962c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x89630 */ stp x20, x19, [sp, #0x10];
    /* 0x89634 */ mov x29, sp;
    /* 0x89638 */ mov w0, #0x18;
    /* 0x8963c */ mov x20, x2;
    _Znwm();
    /* 0x89644 */ mov x19, x0;
    /* 0x89648 */ mov x1, x20;
    sub_89674();
    /* 0x89650 */ mov x0, x19;
    /* 0x89654 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
