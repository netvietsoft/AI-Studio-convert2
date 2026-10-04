// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1aa50c
// Recovered Name: _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface18setBodySegmentDataEPhiiii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1aa50c | Size: 92 bytes | SHA256: 59c491255f7be2aaaaee094b34c863aa8a89f4f868e5383b0dcae5d5e0aab65f
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface18setBodySegmentDataEPhiiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x1aa50c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x1aa510 */ str x23, [sp, #0x10];
    /* 0x1aa514 */ stp x22, x21, [sp, #0x20];
    /* 0x1aa518 */ stp x20, x19, [sp, #0x30];
    /* 0x1aa51c */ mov x29, sp;
    /* 0x1aa520 */ ldr x0, [x0, #8];
    /* 0x1aa524 */ mov w19, w5;
    /* 0x1aa528 */ mov w20, w4;
    /* 0x1aa52c */ mov w21, w3;
    /* 0x1aa530 */ mov w22, w2;
    /* 0x1aa534 */ mov x23, x1;
    _ZN14MTFilterKernel23MTlabFilterKernelRender10getContextEv();
}
