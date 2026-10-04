// Library: libarkernel3.so
// Function ID: libarkernel3::0x69666c
// Recovered Name: sub_69666c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x69666c | Size: 428 bytes | SHA256: 539a9912534088285de7a9e0dd55d08141f7def17783668b6a47a4995154ef61
// Callers: 0 | Callees: 6 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "FabbyMaskType"
//   "Segment mask body"
//   "Segment mask body reverse"
//   "Segment mask face"
//   "Segment mask face reverse"

void sub_69666c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 107 instructions
    /* 0x69666c */ stp x29, x30, [sp, #0x10];
    /* 0x696670 */ stp x22, x21, [sp, #0x20];
    /* 0x696674 */ stp x20, x19, [sp, #0x30];
    /* 0x696678 */ add x29, sp, #0x10;
    /* 0x69667c */ mrs x22, tpidr_el0;
    /* 0x696680 */ mov x19, x0;
    /* 0x696684 */ ldr x8, [x22, #0x28];
    /* 0x696688 */ str x8, [sp, #8];
    sub_68d824();
    /* 0x696690 */ adrp x1, #0x1b8000;
    /* 0x696694 */ add x1, x1, #0xa30;
    sub_6607b8();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_696818();
    sub_696a2c();
    sub_a2d1c4();
    return x0;
    __stack_chk_fail();
}
