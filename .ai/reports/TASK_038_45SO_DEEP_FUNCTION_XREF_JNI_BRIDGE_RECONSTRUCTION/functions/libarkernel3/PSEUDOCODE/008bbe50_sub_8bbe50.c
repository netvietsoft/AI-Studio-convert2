// Library: libarkernel3.so
// Function ID: libarkernel3::0x8bbe50
// Recovered Name: sub_8bbe50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8bbe50 | Size: 344 bytes | SHA256: 33493ad77d9d54cec59e9f8501f293eb74f7236b11ecb735825617d5dcd85696
// Callers: 0 | Callees: 8 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "Color"
//   "HairType"
//   "LookupTable"
//   "MakeupConfigure"
//   "Material"

void sub_8bbe50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 86 instructions
    /* 0x8bbe50 */ stp x29, x30, [sp, #0x20];
    /* 0x8bbe54 */ stp x22, x21, [sp, #0x30];
    /* 0x8bbe58 */ stp x20, x19, [sp, #0x40];
    /* 0x8bbe5c */ add x29, sp, #0x20;
    /* 0x8bbe60 */ mrs x22, tpidr_el0;
    /* 0x8bbe64 */ mov x19, x0;
    /* 0x8bbe68 */ ldr x8, [x22, #0x28];
    /* 0x8bbe6c */ stur x8, [x29, #-8];
    sub_90e54c();
    /* 0x8bbe74 */ adrp x1, #0x278000;
    /* 0x8bbe78 */ add x1, x1, #0x614;
    sub_8bbfa8();
    sub_8bc078();
    sub_8bc078();
    sub_8bc078();
    sub_8bc078();
    sub_8bc078();
    sub_8bc268();
    sub_8bc47c();
    sub_8bc578();
    sub_8bc78c();
    sub_8bc888();
    return x0;
    __stack_chk_fail();
}
