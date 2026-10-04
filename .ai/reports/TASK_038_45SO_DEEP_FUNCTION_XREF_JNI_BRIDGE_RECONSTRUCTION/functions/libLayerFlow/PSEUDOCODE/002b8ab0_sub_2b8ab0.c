// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8ab0
// Recovered Name: sub_2b8ab0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2b8ab0 | Size: 232 bytes | SHA256: 810c0aa8e590a88f9aeaeb11675380a5d9ca7a63c18a029de7e905c79f881833
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "Can't find class(%s)"
//   "Can't register method for class(%s)"
//   "mtik_"

void sub_2b8ab0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 58 instructions
    /* 0x2b8ab0 */ stp x29, x30, [sp, #0xa0];
    /* 0x2b8ab4 */ stp x20, x19, [sp, #0xb0];
    /* 0x2b8ab8 */ add x29, sp, #0xa0;
    /* 0x2b8abc */ mrs x20, tpidr_el0;
    /* 0x2b8ac0 */ nop ;
    /* 0x2b8ac4 */ adr x1, #0x1e2975;
    /* 0x2b8ac8 */ ldr x8, [x20, #0x28];
    /* 0x2b8acc */ mov x19, x0;
    /* 0x2b8ad0 */ stur x8, [x29, #-8];
    /* 0x2b8ad4 */ ldr x8, [x0];
    /* 0x2b8ad8 */ ldr x8, [x8, #0x30];
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
