// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92c64
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92c64 | Size: 68 bytes | SHA256: f738014eeebec5ce754f456346dd1bc98a7f153e7dae726b47b5866c3a98d6ec
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction13getConfigPathEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x92c64 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x92c68 */ str x19, [sp, #0x10];
    /* 0x92c6c */ mov x29, sp;
    /* 0x92c70 */ mov x19, x0;
    /* 0x92c74 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction13getConfigPathEv();
    /* 0x92c7c */ cbz x0, #0x92c9c;
    /* 0x92c80 */ ldr x8, [x19];
    /* 0x92c84 */ mov x1, x0;
    /* 0x92c88 */ ldr x2, [x8, #0x538];
    /* 0x92c8c */ mov x0, x19;
    return x0;
}
