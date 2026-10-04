// Library: libARSPM.so
// Function ID: libARSPM::0x352458
// Recovered Name: sub_352458
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x352458 | Size: 152 bytes | SHA256: ea86d566f88d897ed16be96791d7a2be144716fd8885bc96f701e96a1a0249ad
// Callers: 0 | Callees: 3 | Imports: 1

// Calls external APIs: _ZdlPv
// Strings referenced:
//   "AAHairlineOp"

void sub_352458(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x352458 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x35245c */ str x21, [sp, #0x10];
    /* 0x352460 */ stp x20, x19, [sp, #0x20];
    /* 0x352464 */ mov x29, sp;
    /* 0x352468 */ mov x19, x0;
    /* 0x35246c */ add x0, x0, #0x90;
    sub_37d23c();
    /* 0x352474 */ ldrsw x8, [x19, #0x88];
    /* 0x352478 */ cbz w8, #0x3524a0;
    /* 0x35247c */ mov w9, #0x50;
    /* 0x352480 */ ldr x20, [x19, #0x80];
    sub_18d3dc();
    sub_2666f8();
    return x0;
}
