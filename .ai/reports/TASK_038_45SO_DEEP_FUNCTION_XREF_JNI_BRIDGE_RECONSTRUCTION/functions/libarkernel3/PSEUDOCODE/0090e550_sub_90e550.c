// Library: libarkernel3.so
// Function ID: libarkernel3::0x90e550
// Recovered Name: sub_90e550
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x90e550 | Size: 1892 bytes | SHA256: fbfde043e4e7c61614adb06079051298f06cae02dead96ee83ee1909bfbf6c1c
// Callers: 0 | Callees: 31 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "3dLightEffect"
//   "BlendMode"
//   "COLOR_MASK"
//   "Cheek"
//   "Contour"

void sub_90e550(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 473 instructions
    /* 0x90e550 */ stp x29, x30, [sp, #0x10];
    /* 0x90e554 */ stp x28, x27, [sp, #0x20];
    /* 0x90e558 */ stp x26, x25, [sp, #0x30];
    /* 0x90e55c */ stp x24, x23, [sp, #0x40];
    /* 0x90e560 */ stp x22, x21, [sp, #0x50];
    /* 0x90e564 */ stp x20, x19, [sp, #0x60];
    /* 0x90e568 */ add x29, sp, #0x10;
    /* 0x90e56c */ mrs x24, tpidr_el0;
    /* 0x90e570 */ mov x19, x0;
    /* 0x90e574 */ ldr x8, [x24, #0x28];
    /* 0x90e578 */ str x8, [sp, #8];
    sub_9b0424();
    sub_864560();
    sub_90ecb4();
    sub_90ed84();
    sub_90ed84();
    sub_90ed84();
    sub_90ed84();
    sub_90ef74();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f044();
    sub_90f234();
    sub_90f304();
    sub_90f304();
    sub_90f304();
    sub_90f304();
    sub_90f304();
    sub_90f304();
    sub_90f4f4();
    sub_90f5fc();
    sub_90f6f8();
    sub_90f6f8();
    sub_90f6f8();
    sub_90f7f4();
    sub_90f8f0();
    sub_90f9ec();
    sub_90fae8();
    sub_90fae8();
    sub_90f7f4();
    sub_90fbe4();
    sub_90fce0();
    sub_90f8f0();
    sub_a2d4dc();
    sub_a2d510();
    sub_90fddc();
    sub_90fee4();
    sub_90ffe0();
    sub_9100e8();
    sub_776c24();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_776cf4();
    sub_9101e4();
    sub_9104fc();
    sub_9105f4();
    sub_9106d0();
    sub_9107cc();
    sub_9108c8();
    return x0;
    __stack_chk_fail();
}
