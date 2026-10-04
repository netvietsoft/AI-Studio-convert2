// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x86fd8
// Recovered Name: sub_86fd8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x86fd8 | Size: 20 bytes | SHA256: 40e13fd2f9b569b6f4c248a9643a3502de6acf2cf914bf7932cadf57b2544efd
// Callers: 2 | Callees: 1 | Imports: 0

// Strings referenced:
//   "basic_string"

void sub_86fd8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x86fd8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x86fdc */ mov x29, sp;
    /* 0x86fe0 */ adrp x0, #0x6e000;
    /* 0x86fe4 */ add x0, x0, #0x3d9;
    sub_86fec();
}
