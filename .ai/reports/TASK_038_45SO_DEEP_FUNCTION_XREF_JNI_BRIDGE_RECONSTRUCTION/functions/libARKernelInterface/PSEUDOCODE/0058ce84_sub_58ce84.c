// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58ce84
// Recovered Name: sub_58ce84
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58ce84 | Size: 440 bytes | SHA256: 932468cf95ff32e52fbf5754842d736ee705e9b0788bc0f767fb7722dd268f4e
// Callers: 0 | Callees: 5 | Imports: 4

// Calls external APIs: _ZdlPv, __android_log_print, __dynamic_cast, __stack_chk_fail
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

void sub_58ce84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 110 instructions
    /* 0x58ce84 */ stp x29, x30, [sp, #0x40];
    /* 0x58ce88 */ str x21, [sp, #0x50];
    /* 0x58ce8c */ stp x20, x19, [sp, #0x60];
    /* 0x58ce90 */ add x29, sp, #0x40;
    /* 0x58ce94 */ mrs x21, tpidr_el0;
    /* 0x58ce98 */ ldr x8, [x21, #0x28];
    /* 0x58ce9c */ stur x8, [x29, #-8];
    /* 0x58cea0 */ cbz x2, #0x58cf98;
    /* 0x58cea4 */ mov x0, x2;
    /* 0x58cea8 */ mov x20, x3;
    /* 0x58ceac */ mov x19, x2;
    sub_8e0920();
    __dynamic_cast();
    sub_55dce4();
    sub_570f58();
    sub_892554();
    _ZdlPv();
    _ZdlPv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_1042be4();
    __stack_chk_fail();
}
