// Library: libarkernel3.so
// Function ID: libarkernel3::0x9564c4
// Recovered Name: sub_9564c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9564c4 | Size: 1072 bytes | SHA256: 8ac99037011b573f5c15e4022bea5c8ca5f5d5a1fe343a19f2e9add3ac593aef
// Callers: 0 | Callees: 5 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "BlendColor"
//   "BlendColorBurn"
//   "BlendColorDodge"
//   "BlendDarken"
//   "BlendDarkerColor"

void sub_9564c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 268 instructions
    /* 0x9564c4 */ stp x29, x30, [sp, #0x10];
    /* 0x9564c8 */ stp x22, x21, [sp, #0x20];
    /* 0x9564cc */ stp x20, x19, [sp, #0x30];
    /* 0x9564d0 */ add x29, sp, #0x10;
    /* 0x9564d4 */ mrs x22, tpidr_el0;
    /* 0x9564d8 */ adrp x1, #0x221000;
    /* 0x9564dc */ add x1, x1, #0x2ac;
    /* 0x9564e0 */ ldr x8, [x22, #0x28];
    /* 0x9564e4 */ mov x19, x0;
    /* 0x9564e8 */ str x8, [sp, #8];
    sub_9568f4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_9569c4();
    sub_956bb4();
    sub_956cbc();
    sub_956db8();
    return x0;
    __stack_chk_fail();
}
