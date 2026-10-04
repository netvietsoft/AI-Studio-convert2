// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x586cc0
// Recovered Name: sub_586cc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x586cc0 | Size: 860 bytes | SHA256: 19edc0a4dd72f3386b3dff82905c3fb13a37ce710640d7c737b8f4c85c6874fd
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "bColorWork"
//   "blur"
//   "com/meitu/mtlab/arkernelinterface/interaction/ARKernelTextInteraction$ARKernelTextShadowConfig"
//   "editable"
//   "enable"

void sub_586cc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 215 instructions
    /* 0x586cc0 */ stp x29, x30, [sp, #0x60];
    /* 0x586cc4 */ str x27, [sp, #0x70];
    /* 0x586cc8 */ stp x26, x25, [sp, #0x80];
    /* 0x586ccc */ stp x24, x23, [sp, #0x90];
    /* 0x586cd0 */ stp x22, x21, [sp, #0xa0];
    /* 0x586cd4 */ stp x20, x19, [sp, #0xb0];
    /* 0x586cd8 */ add x29, sp, #0x60;
    /* 0x586cdc */ mrs x25, tpidr_el0;
    /* 0x586ce0 */ ldr x8, [x25, #0x28];
    /* 0x586ce4 */ str x8, [sp, #0x28];
    /* 0x586ce8 */ cbz x2, #0x586fc8;
    return x0;
    sub_581efc();
    __stack_chk_fail();
}
