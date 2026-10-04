// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x9150
// Recovered Name: sub_9150
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9150 | Size: 20 bytes | SHA256: 41f9be841acd1982df44094c55c3ed4577eb81a26ffc08d1237e27b6c04e54e2
// Callers: 0 | Callees: 1 | Imports: 0

// Strings referenced:
//   "core"

void sub_9150(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x9150 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9154 */ mov x29, sp;
    /* 0x9158 */ adrp x1, #0x2000;
    /* 0x915c */ add x1, x1, #0xe6a;
    sub_90b0();
}
