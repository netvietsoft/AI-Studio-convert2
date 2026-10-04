// Library: libAIModelSearchKit.so
// Function ID: libAIModelSearchKit::0x727d0
// Recovered Name: sub_727d0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x727d0 | Size: 144 bytes | SHA256: 54d74778929aebcc1c4ccd4429c65283312efe5afbb0628e47e6afd23ca23dfb
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZN13aimodelsearch21initializeClassLoaderEP7_JNIEnv, __stack_chk_fail

void sub_727d0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x727d0 */ stp x29, x30, [sp, #0x10];
    /* 0x727d4 */ stp x20, x19, [sp, #0x20];
    /* 0x727d8 */ add x29, sp, #0x10;
    /* 0x727dc */ mrs x19, tpidr_el0;
    /* 0x727e0 */ adrp x9, #0xfc000;
    /* 0x727e4 */ mov w2, #6;
    /* 0x727e8 */ ldr x8, [x19, #0x28];
    /* 0x727ec */ ldr x9, [x9, #0xfa8];
    /* 0x727f0 */ mov w20, #6;
    /* 0x727f4 */ mov x1, sp;
    /* 0x727f8 */ movk w2, #1, lsl #16;
    return x0;
    _ZN13aimodelsearch21initializeClassLoaderEP7_JNIEnv();
    __stack_chk_fail();
}
