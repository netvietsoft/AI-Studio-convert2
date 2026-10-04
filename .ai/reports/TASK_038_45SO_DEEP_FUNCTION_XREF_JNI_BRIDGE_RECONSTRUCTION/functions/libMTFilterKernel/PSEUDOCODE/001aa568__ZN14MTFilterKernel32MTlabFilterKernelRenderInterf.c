// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1aa568
// Recovered Name: _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17isNeedSkinSegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1aa568 | Size: 32 bytes | SHA256: 4876e794e9074747625b348163e273c93aa830b4564d2a16bba23239f6a4dc85
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17isNeedSkinSegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x1aa568 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1aa56c */ mov x29, sp;
    /* 0x1aa570 */ ldr x0, [x0, #8];
    _ZN14MTFilterKernel23MTlabFilterKernelRender10getContextEv();
    /* 0x1aa578 */ ldr x8, [x0, #0x188];
    /* 0x1aa57c */ ldrb w0, [x8, #0x1aa];
    /* 0x1aa580 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
