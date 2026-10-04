// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a6c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1getValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a6c0 | Size: 544 bytes | SHA256: 76c7af163df34578ec1ad7133573e9821013d0260f132256ccb1c0a9b5e6881f
// Callers: 0 | Callees: 3 | Imports: 5

// Calls external APIs: _ZNK8mtlabar35Field8getValueEv, _ZdlPv, _Znwm, __stack_chk_fail, memcpy

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Field_1getValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 136 instructions
    /* 0x8a6c0 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x8a6c4 */ str x28, [sp, #0x10];
    /* 0x8a6c8 */ stp x22, x21, [sp, #0x20];
    /* 0x8a6cc */ stp x20, x19, [sp, #0x30];
    /* 0x8a6d0 */ mov x29, sp;
    /* 0x8a6d4 */ sub sp, sp, #0x210;
    /* 0x8a6d8 */ mrs x21, tpidr_el0;
    /* 0x8a6dc */ movi v0.2d, #0000000000000000;
    /* 0x8a6e0 */ mov x0, x2;
    /* 0x8a6e4 */ ldr x8, [x21, #0x28];
    /* 0x8a6e8 */ add x20, sp, #0x100;
    _ZNK8mtlabar35Field8getValueEv();
    memcpy();
    _Znwm();
    sub_9ae94();
    memcpy();
    _ZdlPv();
    return x0;
    sub_9ae94();
    memcpy();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_8a8e0();
    sub_9c5c8();
    __stack_chk_fail();
}
