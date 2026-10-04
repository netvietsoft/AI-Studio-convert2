// Library: libarkernel3.so
// Function ID: libarkernel3::0x76dce0
// Recovered Name: sub_76dce0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x76dce0 | Size: 280 bytes | SHA256: 9c61ca2168675b7789d04a42be291eaa86363cfd33538e1a3d0f840968609cc1
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "ARName"
//   "EnableFace"
//   "EnableFood"
//   "EnableGyroscope"
//   "EnableHand"

void sub_76dce0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x76dce0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x76dce4 */ str x19, [sp, #0x10];
    /* 0x76dce8 */ mov x29, sp;
    /* 0x76dcec */ mov x19, x0;
    sub_9b0424();
    /* 0x76dcf4 */ adrp x1, #0x250000;
    /* 0x76dcf8 */ add x1, x1, #0x79c;
    /* 0x76dcfc */ add x0, x19, #0x80;
    sub_76ddf8();
    /* 0x76dd04 */ adrp x2, #0x25e000;
    /* 0x76dd08 */ add x2, x2, #0x699;
    sub_76e00c();
    sub_76e108();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e204();
    sub_76e300();
}
