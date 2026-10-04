// Library: libarkernel3.so
// Function ID: libarkernel3::0x9dd938
// Recovered Name: sub_9dd938
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9dd938 | Size: 844 bytes | SHA256: edf3494fce05f0ec0e5b06989925480e63419c6faae8c7a8eddc7f201b7da56a
// Callers: 0 | Callees: 17 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "EaseFunctionID"
//   "EaseFunctionParameter"
//   "EaseFunctionTable"
//   "FabbyMaskType"
//   "IsDynamicMaterial"

void sub_9dd938(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 211 instructions
    /* 0x9dd938 */ stp x29, x30, [sp, #0x10];
    /* 0x9dd93c */ stp x22, x21, [sp, #0x20];
    /* 0x9dd940 */ stp x20, x19, [sp, #0x30];
    /* 0x9dd944 */ add x29, sp, #0x10;
    /* 0x9dd948 */ mrs x22, tpidr_el0;
    /* 0x9dd94c */ mov x19, x0;
    /* 0x9dd950 */ ldr x8, [x22, #0x28];
    /* 0x9dd954 */ str x8, [sp, #8];
    sub_9b0424();
    /* 0x9dd95c */ add x0, x19, #0x80;
    sub_9ddc84();
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
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_660888();
    sub_9ddda8();
    sub_9ddeb0();
    sub_9ddfac();
    sub_9de088();
    sub_9de190();
    sub_9de28c();
    sub_9de388();
    sub_9de388();
    sub_9de484();
    sub_9de560();
    sub_9de774();
    sub_a2d1c4();
    sub_9de870();
    sub_9de94c();
    return x0;
    __stack_chk_fail();
}
