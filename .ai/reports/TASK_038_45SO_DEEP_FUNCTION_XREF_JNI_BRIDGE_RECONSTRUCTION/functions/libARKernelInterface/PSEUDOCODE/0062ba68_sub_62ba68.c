// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x62ba68
// Recovered Name: sub_62ba68
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x62ba68 | Size: 468 bytes | SHA256: d0c6e2cb9aba7b6f9bd2123b32f26ef337d948f7e6179d547d8a956c623e9cf4
// Callers: 0 | Callees: 6 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "HairBeautyNoFace"
//   "HairType"
//   "MakeupConfigure"

void sub_62ba68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 117 instructions
    /* 0x62ba68 */ stp x29, x30, [sp, #0x10];
    /* 0x62ba6c */ stp x28, x27, [sp, #0x20];
    /* 0x62ba70 */ stp x26, x25, [sp, #0x30];
    /* 0x62ba74 */ stp x24, x23, [sp, #0x40];
    /* 0x62ba78 */ stp x22, x21, [sp, #0x50];
    /* 0x62ba7c */ stp x20, x19, [sp, #0x60];
    /* 0x62ba80 */ add x29, sp, #0x10;
    /* 0x62ba84 */ mrs x27, tpidr_el0;
    /* 0x62ba88 */ mov x22, x1;
    /* 0x62ba8c */ mov x19, x0;
    /* 0x62ba90 */ ldr x8, [x27, #0x28];
    sub_627368();
    sub_5a8d1c();
    sub_5a8d04();
    sub_5a8de8();
    sub_59fc70();
    sub_a19264();
    return x0;
    __stack_chk_fail();
}
