// Library: libarkernel3.so
// Function ID: libarkernel3::0x925850
// Recovered Name: sub_925850
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x925850 | Size: 708 bytes | SHA256: 89256f527e2312128c507f9c3b0856077958db466496cef36da3c4aa423518f9
// Callers: 0 | Callees: 16 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "BRONZER_NONE"
//   "Blend"
//   "BlendPath"
//   "BronzersPenConfigure"
//   "BrushColor"

void sub_925850(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 177 instructions
    /* 0x925850 */ stp x29, x30, [sp, #0x10];
    /* 0x925854 */ stp x22, x21, [sp, #0x20];
    /* 0x925858 */ stp x20, x19, [sp, #0x30];
    /* 0x92585c */ add x29, sp, #0x10;
    /* 0x925860 */ mrs x22, tpidr_el0;
    /* 0x925864 */ mov x19, x0;
    /* 0x925868 */ ldr x8, [x22, #0x28];
    /* 0x92586c */ str x8, [sp, #8];
    sub_9b0424();
    /* 0x925874 */ adrp x1, #0x1ea000;
    /* 0x925878 */ add x1, x1, #0x359;
    sub_925b14();
    sub_925be4();
    sub_925be4();
    sub_925be4();
    sub_925be4();
    sub_925be4();
    sub_925be4();
    sub_925be4();
    sub_925dd4();
    sub_925edc();
    sub_925fd8();
    sub_9260d4();
    sub_9260d4();
    sub_9260d4();
    sub_9260d4();
    sub_9260d4();
    sub_9261d0();
    sub_925edc();
    sub_9262cc();
    sub_9262cc();
    sub_9262cc();
    sub_a2d510();
    sub_9263c8();
    sub_9265dc();
    sub_9266d8();
    sub_9267d4();
    sub_9268d0();
    sub_9269cc();
    return x0;
    __stack_chk_fail();
}
