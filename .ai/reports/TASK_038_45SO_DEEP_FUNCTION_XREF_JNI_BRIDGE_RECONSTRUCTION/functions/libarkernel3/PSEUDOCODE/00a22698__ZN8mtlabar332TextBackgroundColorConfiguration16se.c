// Library: libarkernel3.so
// Function ID: libarkernel3::0xa22698
// Recovered Name: _ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendYEf
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xa22698 | Size: 64 bytes | SHA256: 350b03492cae1e8da321a6a978fe6bc08652d4cde75e4a16daa454b0f9862dee
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN8mtlabar332TextBackgroundColorConfiguration16setMarginExtendYEf(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0xa22698 */ ldr s1, [x0, #0x4c];
    /* 0xa2269c */ fcvt d2, s0;
    /* 0xa226a0 */ adrp x8, #0x287000;
    /* 0xa226a4 */ fcvt d1, s1;
    /* 0xa226a8 */ fabd d1, d1, d2;
    /* 0xa226ac */ ldr d2, [x8, #0x318];
    /* 0xa226b0 */ fcmp d1, d2;
    /* 0xa226b4 */ b.ls #0xa226d4;
    /* 0xa226b8 */ ldr x8, [x0];
    /* 0xa226bc */ str s0, [x0, #0x4c];
    /* 0xa226c0 */ cbz x8, #0xa226d4;
    return x0;
}
