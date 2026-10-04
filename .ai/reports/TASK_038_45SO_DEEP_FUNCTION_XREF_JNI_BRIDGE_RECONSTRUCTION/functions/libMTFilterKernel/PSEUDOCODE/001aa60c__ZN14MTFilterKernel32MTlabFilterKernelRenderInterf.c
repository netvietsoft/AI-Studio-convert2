// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1aa60c
// Recovered Name: _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface18setHairSegmentDataEPhii
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1aa60c | Size: 84 bytes | SHA256: a589712c4fcecded20ebdcd506fb9325cd9dce635378fd88c810be35e476fd9a
// Callers: 0 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel32MTlabFilterKernelRenderInterface18setHairSegmentDataEPhii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x1aa60c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1aa610 */ str x21, [sp, #0x10];
    /* 0x1aa614 */ stp x20, x19, [sp, #0x20];
    /* 0x1aa618 */ mov x29, sp;
    /* 0x1aa61c */ ldr x0, [x0, #8];
    /* 0x1aa620 */ mov w19, w3;
    /* 0x1aa624 */ mov w20, w2;
    /* 0x1aa628 */ mov x21, x1;
    _ZN14MTFilterKernel23MTlabFilterKernelRender10getContextEv();
    /* 0x1aa630 */ ldr x8, [x0, #0x188];
    /* 0x1aa634 */ mov x1, x21;
}
