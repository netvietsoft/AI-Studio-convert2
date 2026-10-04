// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x12229c
// Recovered Name: _ZN14MTFilterKernel18CMTBokehBlurFilterD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x12229c | Size: 200 bytes | SHA256: 1000bcbe60288e1ecee33b8b7a67a7674dd23cd0ea9428945252fea1fd464ca6
// Callers: 1 | Callees: 3 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN14MTFilterKernel18CMTBokehBlurFilterD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x12229c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1222a0 */ stp x20, x19, [sp, #0x10];
    /* 0x1222a4 */ mov x29, sp;
    /* 0x1222a8 */ adrp x8, #0x1c5000;
    /* 0x1222ac */ mov x19, x0;
    /* 0x1222b0 */ ldr x8, [x8, #0x830];
    /* 0x1222b4 */ ldr x20, [x0, #0xf8];
    /* 0x1222b8 */ add x8, x8, #0x10;
    /* 0x1222bc */ str x8, [x0];
    /* 0x1222c0 */ cbz x20, #0x1222d4;
    /* 0x1222c4 */ mov x0, x20;
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
    _ZN14MTFilterKernel18CMTBokehBlurFilter25ReleaseFramebufferTextureEv();
    sub_c0b38();
}
