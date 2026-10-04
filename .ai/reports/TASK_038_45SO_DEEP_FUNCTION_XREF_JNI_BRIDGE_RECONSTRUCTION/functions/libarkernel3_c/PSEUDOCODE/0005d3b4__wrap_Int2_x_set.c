// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d3b4
// Recovered Name: _wrap_Int2_x_set
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d3b4 | Size: 20 bytes | SHA256: 0b084e9e5493d1cad2213094aa09c4c512bd4983b53181bfd14300782a40bd15
// Callers: 0 | Callees: 0 | Imports: 0


void _wrap_Int2_x_set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x5d3b4 */ cbz x0, #0x5d3c4;
    /* 0x5d3b8 */ ldr x8, [x0];
    /* 0x5d3bc */ cbz x8, #0x5d3c4;
    /* 0x5d3c0 */ str w1, [x8];
    return x0;
}
