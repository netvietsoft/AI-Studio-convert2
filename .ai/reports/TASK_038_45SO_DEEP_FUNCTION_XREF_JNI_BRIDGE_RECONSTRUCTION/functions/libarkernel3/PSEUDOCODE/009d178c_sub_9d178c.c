// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d178c
// Recovered Name: sub_9d178c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d178c | Size: 260 bytes | SHA256: 51c557c1b1ea79baa1d4d62be5e467640409b82c1c660b5a3ee9f34e31cdeb8b
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentStrokeObjPart]"

void sub_9d178c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x9d178c */ stp x29, x30, [sp, #0x40];
    /* 0x9d1790 */ stp x22, x21, [sp, #0x50];
    /* 0x9d1794 */ stp x20, x19, [sp, #0x60];
    /* 0x9d1798 */ add x29, sp, #0x40;
    /* 0x9d179c */ mrs x22, tpidr_el0;
    /* 0x9d17a0 */ mov x21, x1;
    /* 0x9d17a4 */ mov x20, x0;
    /* 0x9d17a8 */ ldr x8, [x22, #0x28];
    /* 0x9d17ac */ stur x8, [x29, #-8];
    /* 0x9d17b0 */ adrp x8, #0x26c000;
    /* 0x9d17b4 */ add x8, x8, #0xae2;
    sub_655e30();
    _Znwm();
    sub_9d35bc();
    sub_6561ac();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
