// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x8db570
// Recovered Name: sub_8db570
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8db570 | Size: 332 bytes | SHA256: f6be6a7659f62e9bd3b99ac5c589d1323ecaa65d1969f83793f2221d3b3ff59d
// Callers: 0 | Callees: 6 | Imports: 3

// Calls external APIs: _ZdaPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "Hair model error!! Check the model"
//   "arkernel"

void sub_8db570(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 83 instructions
    /* 0x8db570 */ stp x29, x30, [sp, #0x10];
    /* 0x8db574 */ stp x22, x21, [sp, #0x20];
    /* 0x8db578 */ stp x20, x19, [sp, #0x30];
    /* 0x8db57c */ add x29, sp, #0x10;
    /* 0x8db580 */ mrs x22, tpidr_el0;
    /* 0x8db584 */ mov x20, x1;
    /* 0x8db588 */ mov x19, x0;
    /* 0x8db58c */ ldr x8, [x22, #0x28];
    /* 0x8db590 */ mov x2, xzr;
    /* 0x8db594 */ str x8, [sp, #8];
    /* 0x8db598 */ ldrb w8, [x1];
    sub_5a6f40();
    sub_c5b978();
    _ZdaPv();
    sub_76be58();
    sub_76bf84();
    sub_8d7270();
    sub_5a6b20();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
