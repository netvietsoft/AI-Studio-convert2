// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1aa5ec
// Recovered Name: _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17isNeedHairSegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1aa5ec | Size: 32 bytes | SHA256: b6af60b851ec91b21be041a7e74c807d6505943e1ce257cd49f9ce4af7f2edad
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface17isNeedHairSegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x1aa5ec */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1aa5f0 */ mov x29, sp;
    /* 0x1aa5f4 */ ldr x0, [x0, #8];
    _ZN14MTFilterKernel23MTlabFilterKernelRender10getContextEv();
    /* 0x1aa5fc */ ldr x8, [x0, #0x188];
    /* 0x1aa600 */ ldrb w0, [x8, #0x1ab];
    /* 0x1aa604 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
