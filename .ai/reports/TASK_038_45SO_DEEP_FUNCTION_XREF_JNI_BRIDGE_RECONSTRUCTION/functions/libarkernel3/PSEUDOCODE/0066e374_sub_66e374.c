// Library: libarkernel3.so
// Function ID: libarkernel3::0x66e374
// Recovered Name: sub_66e374
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x66e374 | Size: 772 bytes | SHA256: af749139ff07f7b8776892dce6ac63c93c42987a8643ca6d418f6e1c19f81e66
// Callers: 0 | Callees: 12 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "CloseEyeRotateAngle"
//   "FilterType"
//   "LowerEyeLash"
//   "ORGBA"
//   "OpenCloseRotateAngleRange"

void sub_66e374(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 193 instructions
    /* 0x66e374 */ stp x29, x30, [sp, #0x10];
    /* 0x66e378 */ stp x22, x21, [sp, #0x20];
    /* 0x66e37c */ stp x20, x19, [sp, #0x30];
    /* 0x66e380 */ add x29, sp, #0x10;
    /* 0x66e384 */ mrs x22, tpidr_el0;
    /* 0x66e388 */ mov x19, x0;
    /* 0x66e38c */ ldr x8, [x22, #0x28];
    /* 0x66e390 */ str x8, [sp, #8];
    sub_6734cc();
    /* 0x66e398 */ adrp x1, #0x1da000;
    /* 0x66e39c */ add x1, x1, #0x9b9;
    sub_66e678();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e748();
    sub_66e938();
    sub_66ec50();
    sub_66ed4c();
    sub_66ee48();
    sub_66ef44();
    sub_66f040();
    sub_66ed4c();
    sub_66ec50();
    sub_66ed4c();
    sub_66ed4c();
    sub_66f13c();
    sub_a2d4dc();
    sub_a2d510();
    return x0;
    __stack_chk_fail();
}
