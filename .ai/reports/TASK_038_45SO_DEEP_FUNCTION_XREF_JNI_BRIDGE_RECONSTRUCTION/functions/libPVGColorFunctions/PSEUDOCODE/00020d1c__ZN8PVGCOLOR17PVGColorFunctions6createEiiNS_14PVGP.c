// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20d1c
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions6createEiiNS_14PVGPixelFormatEiiS1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20d1c | Size: 160 bytes | SHA256: b75db16bec4fefb2302b50677739d4450a26ce7f2d8f6605b245f0f2dd9ed187
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: _ZN8PVGCOLOR17PVGColorFunctionsC1EiiNS_14PVGPixelFormatEiiS1_, _ZdlPvRKSt9nothrow_t, _ZnwmRKSt9nothrow_t

void _ZN8PVGCOLOR17PVGColorFunctions6createEiiNS_14PVGPixelFormatEiiS1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 40 instructions
    /* 0x20d1c */ stp x29, x30, [sp, #-0x50]!;
    /* 0x20d20 */ str x25, [sp, #0x10];
    /* 0x20d24 */ stp x24, x23, [sp, #0x20];
    /* 0x20d28 */ stp x22, x21, [sp, #0x30];
    /* 0x20d2c */ stp x20, x19, [sp, #0x40];
    /* 0x20d30 */ mov x29, sp;
    /* 0x20d34 */ mov w24, w1;
    /* 0x20d38 */ adrp x1, #0x5f000;
    /* 0x20d3c */ mov w25, w0;
    /* 0x20d40 */ ldr x1, [x1, #0x508];
    /* 0x20d44 */ mov w0, #0x98;
    _ZnwmRKSt9nothrow_t();
    _ZN8PVGCOLOR17PVGColorFunctionsC1EiiNS_14PVGPixelFormatEiiS1_();
    return x0;
    _ZdlPvRKSt9nothrow_t();
    sub_54f14();
}
