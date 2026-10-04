// Library: libarkernel3.so
// Function ID: libarkernel3::0xaa045c
// Recovered Name: sub_aa045c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaa045c | Size: 172 bytes | SHA256: e2fea44795c8c90bb696d7575ad23ba42d03ef319d2861d3d91f7247797e104e
// Callers: 1 | Callees: 4 | Imports: 0

// Strings referenced:
//   "NeedOptimize"
//   "SegmentMaskEdgeFactor"

void sub_aa045c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 43 instructions
    /* 0xaa045c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xaa0460 */ str x21, [sp, #0x10];
    /* 0xaa0464 */ stp x20, x19, [sp, #0x20];
    /* 0xaa0468 */ mov x29, sp;
    /* 0xaa046c */ mov x19, x0;
    /* 0xaa0470 */ mov x0, x1;
    /* 0xaa0474 */ mov x20, x1;
    sub_b693e8();
    /* 0xaa047c */ adrp x1, #0x1c7000;
    /* 0xaa0480 */ add x1, x1, #0x2fe;
    /* 0xaa0484 */ mov x0, x20;
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b67f0c();
    return x0;
}
