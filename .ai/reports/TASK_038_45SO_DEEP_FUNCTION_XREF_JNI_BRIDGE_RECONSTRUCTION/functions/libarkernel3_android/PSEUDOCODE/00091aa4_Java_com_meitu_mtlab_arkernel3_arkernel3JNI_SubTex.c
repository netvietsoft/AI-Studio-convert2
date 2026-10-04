// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91aa4
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getCustomTag
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91aa4 | Size: 68 bytes | SHA256: 5e4dd9212f43e51bd07b2267c2aaa93ba3a342ff9856c577a9e2bf871032451d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction12getCustomTagEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getCustomTag(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x91aa4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x91aa8 */ str x19, [sp, #0x10];
    /* 0x91aac */ mov x29, sp;
    /* 0x91ab0 */ mov x19, x0;
    /* 0x91ab4 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction12getCustomTagEv();
    /* 0x91abc */ cbz x0, #0x91adc;
    /* 0x91ac0 */ ldr x8, [x19];
    /* 0x91ac4 */ mov x1, x0;
    /* 0x91ac8 */ ldr x2, [x8, #0x538];
    /* 0x91acc */ mov x0, x19;
    return x0;
}
