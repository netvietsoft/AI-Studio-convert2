// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95158
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimEffectState_1getDistEffectState
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95158 | Size: 36 bytes | SHA256: f842019d3f6a36853dd186f5cfc06b7c78790ec916e686a6729b879824851be8
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar319BodySlimEffectState18getDistEffectStateENS_19BodySlimControlTypeEl

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_BodySlimEffectState_1getDistEffectState(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x95158 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9515c */ mov x29, sp;
    /* 0x95160 */ mov w1, w4;
    /* 0x95164 */ mov x0, x2;
    /* 0x95168 */ mov x2, x5;
    _ZN8mtlabar319BodySlimEffectState18getDistEffectStateENS_19BodySlimControlTypeEl();
    /* 0x95170 */ and w0, w0, #1;
    /* 0x95174 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
