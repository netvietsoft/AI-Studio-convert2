// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x937d0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextLayerConfig
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x937d0 | Size: 132 bytes | SHA256: da98b078769a05dc97f3197732501d89642592bc2a6c626e8e9e3e21d2cca642
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39TextUtils20parseTextLayerConfigEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextUtils_1parseTextLayerConfig(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x937d0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x937d4 */ stp x22, x21, [sp, #0x10];
    /* 0x937d8 */ stp x20, x19, [sp, #0x20];
    /* 0x937dc */ mov x29, sp;
    /* 0x937e0 */ cbz x2, #0x9382c;
    /* 0x937e4 */ ldr x8, [x0];
    /* 0x937e8 */ mov x19, x2;
    /* 0x937ec */ mov x1, x2;
    /* 0x937f0 */ mov x2, xzr;
    /* 0x937f4 */ mov x20, x0;
    /* 0x937f8 */ ldr x8, [x8, #0x548];
    _ZN8mtlabar39TextUtils20parseTextLayerConfigEPKc();
    _ZN8mtlabar39TextUtils20parseTextLayerConfigEPKc();
    return x0;
}
