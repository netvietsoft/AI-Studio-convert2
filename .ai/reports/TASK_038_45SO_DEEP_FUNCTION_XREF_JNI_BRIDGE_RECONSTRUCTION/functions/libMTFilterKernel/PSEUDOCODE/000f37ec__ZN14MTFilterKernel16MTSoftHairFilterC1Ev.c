// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xf37ec
// Recovered Name: _ZN14MTFilterKernel16MTSoftHairFilterC1Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xf37ec | Size: 80 bytes | SHA256: f5750e2c3a9acac4cebfce0b2871369dfaf37a093551c6acdbad7221dbd11892
// Callers: 1 | Callees: 1 | Imports: 0


void _ZN14MTFilterKernel16MTSoftHairFilterC1Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0xf37ec */ stp x29, x30, [sp, #-0x20]!;
    /* 0xf37f0 */ str x19, [sp, #0x10];
    /* 0xf37f4 */ mov x29, sp;
    /* 0xf37f8 */ mov x19, x0;
    _ZN14MTFilterKernel17MTDrawArrayFilterC2Ev();
    /* 0xf3800 */ adrp x8, #0x1c5000;
    /* 0xf3804 */ movi v0.2d, #0000000000000000;
    /* 0xf3808 */ add x9, x19, #0x1c8;
    /* 0xf380c */ ldr x8, [x8, #0x5f8];
    /* 0xf3810 */ add x8, x8, #0x10;
    /* 0xf3814 */ str x8, [x19];
    return x0;
}
