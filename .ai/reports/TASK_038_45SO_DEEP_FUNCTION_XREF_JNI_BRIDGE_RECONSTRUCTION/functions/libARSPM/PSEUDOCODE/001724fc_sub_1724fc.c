// Library: libARSPM.so
// Function ID: libARSPM::0x1724fc
// Recovered Name: sub_1724fc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1724fc | Size: 156 bytes | SHA256: 83476af5208a33cc09a506508e385f31feafdb9b2d9120f89a28af14645f35e4
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "rrect-blur"

void sub_1724fc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x1724fc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x172500 */ str x19, [sp, #0x10];
    /* 0x172504 */ mov x29, sp;
    /* 0x172508 */ mov x19, x0;
    /* 0x17250c */ ldr x0, [x0, #0x90];
    /* 0x172510 */ adrp x8, #0x4f6000;
    /* 0x172514 */ add x8, x8, #0xdd0;
    /* 0x172518 */ mov w1, #1;
    /* 0x17251c */ str x8, [x19];
    sub_136bb0();
    /* 0x172524 */ mov x0, x19;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
