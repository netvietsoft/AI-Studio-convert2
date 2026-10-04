// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0x1340ac
// Recovered Name: _ZN14MTFilterKernel17CMTFilterSoftHairC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1340ac | Size: 72 bytes | SHA256: d23a5f8afba992d04d961633cea612d39529b060e7bcb94f6f522a245c7f3ed1
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel17CMTFilterSoftHairC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x1340ac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x1340b0 */ str x19, [sp, #0x10];
    /* 0x1340b4 */ mov x29, sp;
    /* 0x1340b8 */ mov x19, x0;
    _ZN14MTFilterKernel16CMTDynamicFilterC1Ev();
    /* 0x1340c0 */ adrp x8, #0x1c5000;
    /* 0x1340c4 */ movi v0.2d, #0000000000000000;
    /* 0x1340c8 */ ldr x8, [x8, #0x8c0];
    /* 0x1340cc */ str wzr, [x19, #0x148];
    /* 0x1340d0 */ str xzr, [x19, #0x138];
    /* 0x1340d4 */ add x8, x8, #0x10;
    return x0;
}
