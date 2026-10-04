// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bc790
// Recovered Name: sub_8bc790
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bc790 | Size: 248 bytes | SHA256: f1227ee4a632eb76e7fbb366af1f398cb7e7d5db8b39f876206f676a17021124
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::HairBeautyType]"

void sub_8bc790(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 62 instructions
    /* 0x8bc790 */ stp x29, x30, [sp, #0x110];
    /* 0x8bc794 */ stp x28, x21, [sp, #0x120];
    /* 0x8bc798 */ stp x20, x19, [sp, #0x130];
    /* 0x8bc79c */ add x29, sp, #0x110;
    /* 0x8bc7a0 */ mrs x20, tpidr_el0;
    /* 0x8bc7a4 */ movi v0.2d, #0000000000000000;
    /* 0x8bc7a8 */ nop ;
    /* 0x8bc7ac */ adr x9, #0x8c01d8;
    /* 0x8bc7b0 */ ldr x8, [x20, #0x28];
    /* 0x8bc7b4 */ mov x19, x0;
    /* 0x8bc7b8 */ mov x3, x2;
    sub_664ba4();
    sub_65616c();
    sub_a2d518();
    sub_664ce0();
    return x0;
    sub_664ce0();
    sub_65616c();
    sub_106b814();
    __stack_chk_fail();
}
