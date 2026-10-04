// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1eebc
// Recovered Name: sub_1eebc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1eebc | Size: 16 bytes | SHA256: 275ac5c2724da82b75725b53f874b2c1f054944851c197524c6c1ff1e227db05
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: ff_make_format_list

void sub_1eebc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x1eebc */ mov w9, #-1;
    /* 0x1eec0 */ mov x0, sp;
    /* 0x1eec4 */ stp w8, w9, [sp];
    /* 0x1eec8 */ b #0x3cfc0;
}
