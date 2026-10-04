// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe3f0
// Recovered Name: _Z23registerFaceDataMethodsP7_JNIEnvPv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xbe3f0 | Size: 104 bytes | SHA256: de82314fdffdd4f19c9d819b9912f82be425349d09476c0592e5d917334e61e2
// Callers: 1 | Callees: 0 | Imports: 0


void _Z23registerFaceDataMethodsP7_JNIEnvPv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0xbe3f0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xbe3f4 */ str x19, [sp, #0x10];
    /* 0xbe3f8 */ mov x29, sp;
    /* 0xbe3fc */ ldr x8, [x0];
    /* 0xbe400 */ nop ;
    /* 0xbe404 */ adr x1, #0x8aa12;
    /* 0xbe408 */ mov x19, x0;
    /* 0xbe40c */ ldr x8, [x8, #0x30];
    /* 0xbe410 */ blr x8;
    /* 0xbe414 */ cbz x0, #0xbe448;
    /* 0xbe418 */ ldr x8, [x19];
    return x0;
    return x0;
}
