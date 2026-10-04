// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d040
// Recovered Name: sub_58d040
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58d040 | Size: 440 bytes | SHA256: 5085e119bd1eb99622f7d9b3f4f1a5219318f14fd1288233d1ea8f0c6f04dcb6
// Callers: 0 | Callees: 5 | Imports: 4

// Calls external APIs: _ZdlPv, __android_log_print, __dynamic_cast, __stack_chk_fail
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

void sub_58d040(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x58d040 */ stp x29, x30, [sp, #0x40];
    /* 0x58d044 */ str x21, [sp, #0x50];
    /* 0x58d048 */ stp x20, x19, [sp, #0x60];
    /* 0x58d04c */ add x29, sp, #0x40;
    /* 0x58d050 */ mrs x21, tpidr_el0;
    /* 0x58d054 */ ldr x8, [x21, #0x28];
    /* 0x58d058 */ stur x8, [x29, #-8];
    /* 0x58d05c */ cbz x2, #0x58d154;
    /* 0x58d060 */ mov x0, x2;
    /* 0x58d064 */ mov x20, x3;
    /* 0x58d068 */ mov x19, x2;
    sub_8e0920();
    __dynamic_cast();
    sub_55dce4();
    sub_570f58();
    sub_8925ec();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_1042be4();
    __stack_chk_fail();
}
