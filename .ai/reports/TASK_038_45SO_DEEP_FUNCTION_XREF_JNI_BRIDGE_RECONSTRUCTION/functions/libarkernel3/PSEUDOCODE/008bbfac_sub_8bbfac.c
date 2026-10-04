// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bbfac
// Recovered Name: sub_8bbfac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bbfac | Size: 204 bytes | SHA256: 8bec3e1cb336e7db39b02b1fcc3dac4c4cc3d7fdf0980122f4043ff95fbebc21
// Callers: 0 | Callees: 3 | Imports: 3

// Calls external APIs: _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::HairBeautyType]"

void sub_8bbfac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x8bbfac */ stp x29, x30, [sp, #0x20];
    /* 0x8bbfb0 */ str x23, [sp, #0x30];
    /* 0x8bbfb4 */ stp x22, x21, [sp, #0x40];
    /* 0x8bbfb8 */ stp x20, x19, [sp, #0x50];
    /* 0x8bbfbc */ add x29, sp, #0x20;
    /* 0x8bbfc0 */ mrs x22, tpidr_el0;
    /* 0x8bbfc4 */ mov x20, x0;
    /* 0x8bbfc8 */ mov w0, #0x58;
    /* 0x8bbfcc */ ldr x8, [x22, #0x28];
    /* 0x8bbfd0 */ mov x21, x1;
    /* 0x8bbfd4 */ stur x8, [x29, #-8];
    _Znwm();
    sub_a2e28c();
    sub_663b28();
    return x0;
    _ZdlPv();
    sub_106b814();
    __stack_chk_fail();
}
