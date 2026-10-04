// Library: libarkernel3.so
// Function ID: libarkernel3::0x666340
// Recovered Name: sub_666340
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x666340 | Size: 644 bytes | SHA256: e057f7af3fcd189a30c85c606f0a8bb58d145201d892f10af697301484ef2e4f
// Callers: 0 | Callees: 10 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "3DSkyBox part"
//   "BackPath"
//   "BlendFunc"
//   "BottomPath"
//   "EMTextures"

void sub_666340(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 161 instructions
    /* 0x666340 */ stp x29, x30, [sp, #0x10];
    /* 0x666344 */ stp x22, x21, [sp, #0x20];
    /* 0x666348 */ stp x20, x19, [sp, #0x30];
    /* 0x66634c */ add x29, sp, #0x10;
    /* 0x666350 */ mrs x22, tpidr_el0;
    /* 0x666354 */ mov x19, x0;
    /* 0x666358 */ ldr x8, [x22, #0x28];
    /* 0x66635c */ str x8, [sp, #8];
    sub_9b0424();
    /* 0x666364 */ add x0, x19, #0x80;
    sub_6665c4();
    sub_6607b8();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_6667ec();
    sub_6668f4();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_6669f0();
    sub_666aec();
    sub_666aec();
    sub_6669f0();
    sub_666aec();
    sub_666be8();
    sub_666ce4();
    return x0;
    __stack_chk_fail();
}
