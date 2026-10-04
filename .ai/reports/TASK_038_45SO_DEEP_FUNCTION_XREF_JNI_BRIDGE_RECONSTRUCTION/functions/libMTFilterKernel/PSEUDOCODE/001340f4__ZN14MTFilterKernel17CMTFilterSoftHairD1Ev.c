// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1340f4
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHairD1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1340f4 | Size: 200 bytes | SHA256: adf4473cf88326f0d2b7cefb03e82d0a45cfc4b5d6330f77321fa7ed7fa152c7
// Callers: 1 | Callees: 3 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel17CMTFilterSoftHairD1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x1340f4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1340f8 */ stp x20, x19, [sp, #0x10];
    /* 0x1340fc */ mov x29, sp;
    /* 0x134100 */ adrp x8, #0x1c5000;
    /* 0x134104 */ mov x19, x0;
    /* 0x134108 */ ldr x8, [x8, #0x8c0];
    /* 0x13410c */ ldr x20, [x0, #0xf8];
    /* 0x134110 */ add x8, x8, #0x10;
    /* 0x134114 */ str x8, [x0];
    /* 0x134118 */ cbz x20, #0x13412c;
    /* 0x13411c */ mov x0, x20;
    _ZN14MTFilterKernel10CGLProgramD2Ev();
    _ZdlPv();
    _ZN14MTFilterKernel10CGLProgramD2Ev();
    _ZdlPv();
    _ZN14MTFilterKernel10CGLProgramD2Ev();
    _ZdlPv();
    _ZN14MTFilterKernel10CGLProgramD2Ev();
    _ZdlPv();
    _ZN14MTFilterKernel10CGLProgramD2Ev();
    _ZdlPv();
    _ZN14MTFilterKernel17CMTFilterSoftHair25ReleaseFramebufferTextureEv();
    sub_c0b38();
}
