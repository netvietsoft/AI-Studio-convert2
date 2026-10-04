// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8d51f8
// Recovered Name: sub_8d51f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8d51f8 | Size: 736 bytes | SHA256: cf8be7e5503f6ec6f8f061085e32b9663bb952c8e692c6ffea42d1c79f832f97
// Callers: 0 | Callees: 7 | Imports: 3

// Calls external APIs: _ZdaPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "Hair model error!! Check the model!!"
//   "arkernel"

void sub_8d51f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 184 instructions
    /* 0x8d51f8 */ stp x29, x30, [sp, #0x50];
    /* 0x8d51fc */ str x21, [sp, #0x60];
    /* 0x8d5200 */ stp x20, x19, [sp, #0x70];
    /* 0x8d5204 */ add x29, sp, #0x50;
    /* 0x8d5208 */ mrs x21, tpidr_el0;
    /* 0x8d520c */ mov x19, x0;
    /* 0x8d5210 */ add x0, sp, #8;
    /* 0x8d5214 */ ldr x8, [x21, #0x28];
    /* 0x8d5218 */ stur x8, [x29, #-8];
    sub_5e6220();
    /* 0x8d5220 */ add x0, sp, #8;
    sub_5e6260();
    sub_5a6f40();
    sub_c5b978();
    _ZdaPv();
    sub_76bf84();
    sub_76e710();
    sub_76e710();
    sub_5a6f40();
    sub_c5b978();
    _ZdaPv();
    sub_76bf84();
    sub_5a6b20();
    __android_log_print();
    sub_5a6f40();
    sub_c5b978();
    _ZdaPv();
    sub_76bf84();
    return x0;
    __stack_chk_fail();
}
