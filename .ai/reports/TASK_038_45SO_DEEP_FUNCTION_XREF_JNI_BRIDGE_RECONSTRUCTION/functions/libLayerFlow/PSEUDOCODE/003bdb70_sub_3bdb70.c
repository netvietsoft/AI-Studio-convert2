// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bdb70
// Recovered Name: sub_3bdb70
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3bdb70 | Size: 256 bytes | SHA256: 1cc63ebbf6019c93eb769789bb42bf2978de1f1a755fa65d16d9562eef8c25be
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "Can't find class(%s)"
//   "Can't register method for class(%s)"
//   "com/layer/flow/plugin/LFBlurResourceData"
//   "mtik_"

void sub_3bdb70(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x3bdb70 */ stp x29, x30, [sp, #0xe0];
    /* 0x3bdb74 */ stp x20, x19, [sp, #0xf0];
    /* 0x3bdb78 */ add x29, sp, #0xe0;
    /* 0x3bdb7c */ mrs x20, tpidr_el0;
    /* 0x3bdb80 */ adrp x1, #0x1d3000;
    /* 0x3bdb84 */ add x1, x1, #0x27;
    /* 0x3bdb88 */ ldr x8, [x20, #0x28];
    /* 0x3bdb8c */ mov x19, x0;
    /* 0x3bdb90 */ stur x8, [x29, #-8];
    /* 0x3bdb94 */ ldr x8, [x0];
    /* 0x3bdb98 */ ldr x8, [x8, #0x30];
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
