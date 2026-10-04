// Library: libPVGColorFunctions.so
// Function ID: libPVGColorFunctions::0x20c9c
// Recovered Name: _ZN8PVGCOLOR17PVGColorFunctions6createENS_14PVGPixelFormatES1_
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x20c9c | Size: 128 bytes | SHA256: 0f7af45f1c777aad7f0f18976d8210f5d7d94442bb020de11f88de4c986bb92c
// Callers: 0 | Callees: 1 | Imports: 3

// Calls external APIs: _ZN8PVGCOLOR17PVGColorFunctionsC1EiiNS_14PVGPixelFormatEiiS1_, _ZdlPvRKSt9nothrow_t, _ZnwmRKSt9nothrow_t

void _ZN8PVGCOLOR17PVGColorFunctions6createENS_14PVGPixelFormatES1_(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x20c9c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x20ca0 */ str x21, [sp, #0x10];
    /* 0x20ca4 */ stp x20, x19, [sp, #0x20];
    /* 0x20ca8 */ mov x29, sp;
    /* 0x20cac */ mov w20, w1;
    /* 0x20cb0 */ adrp x1, #0x5f000;
    /* 0x20cb4 */ mov w21, w0;
    /* 0x20cb8 */ ldr x1, [x1, #0x508];
    /* 0x20cbc */ mov w0, #0x98;
    _ZnwmRKSt9nothrow_t();
    /* 0x20cc4 */ mov x19, x0;
    _ZN8PVGCOLOR17PVGColorFunctionsC1EiiNS_14PVGPixelFormatEiiS1_();
    return x0;
    _ZdlPvRKSt9nothrow_t();
    sub_54f14();
}
