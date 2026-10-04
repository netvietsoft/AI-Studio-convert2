// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98488
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getBGMPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98488 | Size: 68 bytes | SHA256: e5cfc6c6f6a0bf3993fc4e5abc8af0ca978e78b56abb5234e218408653c3070d
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar310EffectData10getBGMPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_EffectData_1getBGMPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x98488 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9848c */ str x19, [sp, #0x10];
    /* 0x98490 */ mov x29, sp;
    /* 0x98494 */ mov x19, x0;
    /* 0x98498 */ mov x0, x2;
    _ZN8mtlabar310EffectData10getBGMPathEv();
    /* 0x984a0 */ cbz x0, #0x984c0;
    /* 0x984a4 */ ldr x8, [x19];
    /* 0x984a8 */ mov x1, x0;
    /* 0x984ac */ ldr x2, [x8, #0x538];
    /* 0x984b0 */ mov x0, x19;
    return x0;
}
