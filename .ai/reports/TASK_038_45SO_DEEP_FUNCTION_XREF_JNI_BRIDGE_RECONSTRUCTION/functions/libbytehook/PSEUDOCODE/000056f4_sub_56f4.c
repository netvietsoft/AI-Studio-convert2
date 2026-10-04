// Library: libbytehook.so
// Function ID: libbytehook::0x56f4
// Recovered Name: sub_56f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x56f4 | Size: 24 bytes | SHA256: ff0b7b87ff200d6904c7c3ca4b9328e4a2acd47d6bd7d73f80c74e304c01c0f0
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: free

void sub_56f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x56f4 */ mov x8, x0;
    /* 0x56f8 */ ldr x0, [x8], #0x18;
    /* 0x56fc */ cmp x0, x8;
    /* 0x5700 */ b.ne #0x5708;
    return x0;
    /* 0x5708 */ b #0xd260;
}
