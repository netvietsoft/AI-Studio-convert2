// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92bd0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92bd0 | Size: 148 bytes | SHA256: a0c3e7ca73dc7c392b9f7647f86ef19e6086538248c3e78f93419e2cfdbdfa55
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction13setConfigPathEPKc

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1setConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x92bd0 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x92bd4 */ stp x22, x21, [sp, #0x10];
    /* 0x92bd8 */ stp x20, x19, [sp, #0x20];
    /* 0x92bdc */ mov x29, sp;
    /* 0x92be0 */ mov x21, x2;
    /* 0x92be4 */ cbz x4, #0x92c3c;
    /* 0x92be8 */ ldr x8, [x0];
    /* 0x92bec */ mov x1, x4;
    /* 0x92bf0 */ mov x2, xzr;
    /* 0x92bf4 */ mov x19, x4;
    /* 0x92bf8 */ mov x20, x0;
    _ZN8mtlabar325LayerAnimationInteraction13setConfigPathEPKc();
    return x0;
}
