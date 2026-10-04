// Library: libarkernel3.so
// Function ID: libarkernel3::0x796b58
// Recovered Name: sub_796b58
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x796b58 | Size: 280 bytes | SHA256: 7e937131c1a7c19445dd29bb65d8a6937574a87c623747106173bc347d6d5e26
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "BlurRadius"
//   "Expansion"
//   "FacemeshParameters"
//   "FacemeshType"
//   "LocateMethod"

void sub_796b58(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 70 instructions
    /* 0x796b58 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x796b5c */ stp x20, x19, [sp, #0x10];
    /* 0x796b60 */ mov x29, sp;
    /* 0x796b64 */ mov x19, x0;
    sub_815d2c();
    /* 0x796b6c */ adrp x1, #0x216000;
    /* 0x796b70 */ add x1, x1, #0x4b2;
    /* 0x796b74 */ add x0, x19, #0x80;
    sub_796c70();
    /* 0x796b7c */ adrp x2, #0x1f8000;
    /* 0x796b80 */ add x2, x2, #0x58a;
    sub_796d78();
    sub_796e54();
    sub_796e54();
    sub_796f50();
    sub_796f50();
    sub_796f50();
    sub_79702c();
    sub_79702c();
    sub_79702c();
}
