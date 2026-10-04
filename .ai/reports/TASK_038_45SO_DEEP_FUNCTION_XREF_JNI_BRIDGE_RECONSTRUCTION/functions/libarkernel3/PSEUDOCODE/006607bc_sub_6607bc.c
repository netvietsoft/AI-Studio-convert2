// Library: libarkernel3.so
// Function ID: libarkernel3::0x6607bc
// Recovered Name: sub_6607bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6607bc | Size: 204 bytes | SHA256: a3334696e972b3a027900aabef00084811737d8eb9c5bafd5ec5b12f5f9ea3f5
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentMaskType]"

void sub_6607bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x6607bc */ stp x29, x30, [sp, #0x20];
    /* 0x6607c0 */ str x23, [sp, #0x30];
    /* 0x6607c4 */ stp x22, x21, [sp, #0x40];
    /* 0x6607c8 */ stp x20, x19, [sp, #0x50];
    /* 0x6607cc */ add x29, sp, #0x20;
    /* 0x6607d0 */ mrs x22, tpidr_el0;
    /* 0x6607d4 */ mov x20, x0;
    /* 0x6607d8 */ mov w0, #0x58;
    /* 0x6607dc */ ldr x8, [x22, #0x28];
    /* 0x6607e0 */ mov x21, x1;
    /* 0x6607e4 */ stur x8, [x29, #-8];
    _Znwm();
    sub_a2e28c();
    sub_663b28();
    return x0;
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
