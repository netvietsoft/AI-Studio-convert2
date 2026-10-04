// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f348
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getCharSVGBackgroundPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f348 | Size: 64 bytes | SHA256: 7566cc0ed2764089e4c7c0acad0393082ab7d99a0e68d4c28546d4724b31f1e3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326CharSVGBackgroundInterface24getCharSVGBackgroundPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getCharSVGBackgroundPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8f348 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8f34c */ str x19, [sp, #0x10];
    /* 0x8f350 */ mov x29, sp;
    /* 0x8f354 */ mov x19, x0;
    /* 0x8f358 */ mov x0, x2;
    _ZNK8mtlabar326CharSVGBackgroundInterface24getCharSVGBackgroundPathEv();
    /* 0x8f360 */ ldr x8, [x19];
    /* 0x8f364 */ ldrb w9, [x0];
    /* 0x8f368 */ ldr x10, [x0, #0x10];
    /* 0x8f36c */ tst w9, #1;
    /* 0x8f370 */ ldr x2, [x8, #0x538];
}
