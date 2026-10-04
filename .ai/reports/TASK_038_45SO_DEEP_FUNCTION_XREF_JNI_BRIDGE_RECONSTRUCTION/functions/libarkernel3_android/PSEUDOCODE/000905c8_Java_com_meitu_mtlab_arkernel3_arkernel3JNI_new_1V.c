// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x905c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionAnimationInterface_1_1SWIG_11
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x905c8 | Size: 72 bytes | SHA256: 22a8e801fabaa8405016033a9f065c41e0dcf0dc5c57a317588694f5d6057e69
// Callers: 0 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, _Znwm

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_new_1VectorSelectionAnimationInterface_1_1SWIG_11(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x905c8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x905cc */ stp x20, x19, [sp, #0x10];
    /* 0x905d0 */ mov x29, sp;
    /* 0x905d4 */ mov w0, #0x18;
    /* 0x905d8 */ mov x20, x2;
    _Znwm();
    /* 0x905e0 */ mov x19, x0;
    /* 0x905e4 */ mov x1, x20;
    sub_90610();
    /* 0x905ec */ mov x0, x19;
    /* 0x905f0 */ ldp x20, x19, [sp, #0x10];
    return x0;
    _ZdlPv();
    sub_9c5c8();
}
