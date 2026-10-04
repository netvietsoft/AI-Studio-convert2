// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5c11fc
// Recovered Name: sub_5c11fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5c11fc | Size: 880 bytes | SHA256: 113b9047ebd0ef9cda4e92aea497d81d0f5aa2a1d57665908fe059417203cc4c
// Callers: 0 | Callees: 10 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "Blur"
//   "BoldWidth"
//   "Editable"
//   "Enable"
//   "ORGBA"

void sub_5c11fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 220 instructions
    /* 0x5c11fc */ stp x29, x30, [sp, #0x30];
    /* 0x5c1200 */ stp x22, x21, [sp, #0x40];
    /* 0x5c1204 */ stp x20, x19, [sp, #0x50];
    /* 0x5c1208 */ add x29, sp, #0x30;
    /* 0x5c120c */ mrs x22, tpidr_el0;
    /* 0x5c1210 */ mov x21, x0;
    /* 0x5c1214 */ mov x19, x1;
    /* 0x5c1218 */ ldr x8, [x22, #0x28];
    /* 0x5c121c */ stur x8, [x29, #-8];
    /* 0x5c1220 */ ldr x8, [x0];
    /* 0x5c1224 */ ldr x8, [x8, #0xa8];
    sub_5a8cfc();
    sub_5c9b38();
    sub_5a8de8();
    sub_5a8de8();
    sub_5cb124();
    sub_5cb47c();
    sub_dad750();
    sub_dad814();
    _ZdlPv();
    sub_5a8de8();
    sub_5cb124();
    sub_5cb47c();
    sub_daca1c();
    sub_daca8c();
    _ZdlPv();
    sub_5a8da0();
    sub_5a8da0();
    return x0;
    __stack_chk_fail();
}
