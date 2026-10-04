// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xea8ec
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter16updateParametersEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xea8ec | Size: 664 bytes | SHA256: 77fe792705882840c18d4a717eeaba6c04f589f2014d06490cc7119640ce1e6b
// Callers: 1 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilter16updateParametersEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 166 instructions
    /* 0xea8ec */ ldp x8, x9, [x0, #0x108];
    /* 0xea8f0 */ cmp x8, x9;
    /* 0xea8f4 */ b.eq #0xeab80;
    /* 0xea8f8 */ mov x10, #0x616d;
    /* 0xea8fc */ mov x11, #0x6968;
    /* 0xea900 */ mov x15, #0x616d;
    /* 0xea904 */ mov x16, #0x626b;
    /* 0xea908 */ mov x1, #0x616d;
    /* 0xea90c */ movk x10, #0x6b73, lsl #16;
    /* 0xea910 */ movk x11, #0x6867, lsl #16;
    /* 0xea914 */ fmov d3, #5.00000000;
    return x0;
}
