// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x563700
// Recovered Name: sub_563700
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x563700 | Size: 584 bytes | SHA256: 18c6e487dd53dd67c14198399335dd04ae9b9f6443087f5e2606cf9f3d8ae7eb
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetBodySlim3DSparseData(JIII[F[F[F[F)V (table at 0x10cc740)
// Calls external APIs: memcpy

jlong sub_563700(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 146 instructions
    /* 0x563700 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x563704 */ str x25, [sp, #0x10];
    /* 0x563708 */ stp x24, x23, [sp, #0x20];
    /* 0x56370c */ stp x22, x21, [sp, #0x30];
    /* 0x563710 */ stp x20, x19, [sp, #0x40];
    /* 0x563714 */ mov x29, sp;
    /* 0x563718 */ cbz x2, #0x5638c4;
    /* 0x56371c */ tbnz w3, #0x1f, #0x5638c4;
    /* 0x563720 */ ldp x23, x8, [x2, #0xf0];
    /* 0x563724 */ mov w9, #0x37a7;
    /* 0x563728 */ movk w9, #0xe9bd, lsl #16;
    sub_563f8c();
    return x0;
    memcpy();
}
