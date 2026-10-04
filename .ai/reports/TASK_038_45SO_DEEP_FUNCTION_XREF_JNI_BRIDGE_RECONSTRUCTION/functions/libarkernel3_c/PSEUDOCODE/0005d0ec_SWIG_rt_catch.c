// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d0ec
// Recovered Name: SWIG_rt_catch
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d0ec | Size: 168 bytes | SHA256: 4276629fd893370227acaf88c22a4af5200df714f997843e8ca73d36cd18be84
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: memcpy, strcmp

void SWIG_rt_catch(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0x5d0ec */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5d0f0 */ str x21, [sp, #0x10];
    /* 0x5d0f4 */ stp x20, x19, [sp, #0x20];
    /* 0x5d0f8 */ mov x29, sp;
    /* 0x5d0fc */ adrp x20, #0x7b000;
    /* 0x5d100 */ ldr x20, [x20, #0x1b0];
    /* 0x5d104 */ cbz x0, #0x5d144;
    /* 0x5d108 */ mov x19, x0;
    /* 0x5d10c */ nop ;
    /* 0x5d110 */ adr x0, #0x49e59;
    /* 0x5d114 */ mov x1, x19;
    strcmp();
    strcmp();
    memcpy();
    return x0;
}
