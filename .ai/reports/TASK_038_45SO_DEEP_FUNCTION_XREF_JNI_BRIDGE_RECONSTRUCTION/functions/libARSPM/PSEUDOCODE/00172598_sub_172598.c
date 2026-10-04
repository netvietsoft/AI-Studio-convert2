// Library: libARSPM.so
// Function ID: libARSPM::0x172598
// Recovered Name: sub_172598
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x172598 | Size: 116 bytes | SHA256: 6b891a79690540580eba45b9ac3416971e7bb24d4ca99be12929b4155191406d
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "rects-blur"

void sub_172598(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x172598 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x17259c */ str x19, [sp, #0x10];
    /* 0x1725a0 */ mov x29, sp;
    /* 0x1725a4 */ mov x19, x0;
    /* 0x1725a8 */ ldr x0, [x0, #0x78];
    /* 0x1725ac */ adrp x8, #0x4f6000;
    /* 0x1725b0 */ add x8, x8, #0xe20;
    /* 0x1725b4 */ mov w1, #1;
    /* 0x1725b8 */ str x8, [x19];
    sub_136bb0();
    /* 0x1725c0 */ mov x0, x19;
    return x0;
    return x0;
    return x0;
    return x0;
}
