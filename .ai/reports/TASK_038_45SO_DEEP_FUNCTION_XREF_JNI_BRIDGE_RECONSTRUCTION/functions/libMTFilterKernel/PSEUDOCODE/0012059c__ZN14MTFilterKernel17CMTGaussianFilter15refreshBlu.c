// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x12059c
// Recovered Name: _ZN14MTFilterKernel17CMTGaussianFilter15refreshBlurSizeEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x12059c | Size: 356 bytes | SHA256: 7ef34c00fab329385dece2239e9dfdce7c588afd428f8908c6488f15765faee3
// Callers: 1 | Callees: 1 | Imports: 3

// Calls external APIs: _ZdlPv, __stack_chk_fail, memcpy

void _ZN14MTFilterKernel17CMTGaussianFilter15refreshBlurSizeEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 89 instructions
    /* 0x12059c */ stp x29, x30, [sp, #-0x60]!;
    /* 0x1205a0 */ str x28, [sp, #0x10];
    /* 0x1205a4 */ stp x26, x25, [sp, #0x20];
    /* 0x1205a8 */ stp x24, x23, [sp, #0x30];
    /* 0x1205ac */ stp x22, x21, [sp, #0x40];
    /* 0x1205b0 */ stp x20, x19, [sp, #0x50];
    /* 0x1205b4 */ mov x29, sp;
    /* 0x1205b8 */ sub sp, sp, #0x230;
    /* 0x1205bc */ mrs x20, tpidr_el0;
    /* 0x1205c0 */ ldr x8, [x20, #0x28];
    /* 0x1205c4 */ stur x8, [x29, #-8];
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE25__init_copy_ctor_externalEPKcm();
    memcpy();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
