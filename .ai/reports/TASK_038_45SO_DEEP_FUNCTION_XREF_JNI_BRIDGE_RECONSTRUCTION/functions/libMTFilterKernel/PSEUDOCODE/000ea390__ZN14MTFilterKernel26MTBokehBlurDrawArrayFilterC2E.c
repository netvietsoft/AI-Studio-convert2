// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xea390
// Recovered Name: _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilterC2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xea390 | Size: 72 bytes | SHA256: bcddc225e93f9966a2732c3ef5198e2146e003f0fa1f4308d6cf014f586cb008
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel26MTBokehBlurDrawArrayFilterC2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0xea390 */ stp x29, x30, [sp, #-0x20]!;
    /* 0xea394 */ str x19, [sp, #0x10];
    /* 0xea398 */ mov x29, sp;
    /* 0xea39c */ mov x19, x0;
    _ZN14MTFilterKernel17MTDrawArrayFilterC2Ev();
    /* 0xea3a4 */ adrp x8, #0x1c5000;
    /* 0xea3a8 */ movi v0.2d, #0000000000000000;
    /* 0xea3ac */ add x9, x19, #0x1c8;
    /* 0xea3b0 */ ldr x8, [x8, #0x5a8];
    /* 0xea3b4 */ add x8, x8, #0x10;
    /* 0xea3b8 */ str x8, [x19];
    return x0;
}
