// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3e9cc
// Recovered Name: sub_3e9cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3e9cc | Size: 220 bytes | SHA256: 26f30e91a41259ed6e111b698af0384e8ddbb48792716083ffd31dd3c102447c
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "AIDetectorDynamicPlugin_InitPlugin"
//   "MTMVCore"

void sub_3e9cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x3e9cc */ stp x29, x30, [sp, #0x30];
    /* 0x3e9d0 */ str x19, [sp, #0x40];
    /* 0x3e9d4 */ add x29, sp, #0x30;
    /* 0x3e9d8 */ mrs x19, tpidr_el0;
    /* 0x3e9dc */ adrp x9, #0x2f000;
    /* 0x3e9e0 */ mov x1, sp;
    /* 0x3e9e4 */ ldr x8, [x19, #0x28];
    /* 0x3e9e8 */ ldr d0, [x9, #0x8c0];
    /* 0x3e9ec */ mov w9, #3;
    /* 0x3e9f0 */ stur x8, [x29, #-8];
    /* 0x3e9f4 */ mov w8, #1;
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
