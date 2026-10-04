// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d194
// Recovered Name: sub_5d194
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5d194 | Size: 52 bytes | SHA256: 8301ce609042837a2c1e2e95db8e12bab23648541faa827ce352877aec7d12f7
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: memcpy

void sub_5d194(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x5d194 */ adrp x8, #0x82000;
    /* 0x5d198 */ adrp x10, #0x82000;
    /* 0x5d19c */ ldr x9, [x8, #0x248];
    /* 0x5d1a0 */ ldr x10, [x10, #0x250];
    /* 0x5d1a4 */ cmp x9, x10;
    /* 0x5d1a8 */ b.eq #0x5d1c4;
    /* 0x5d1ac */ adrp x0, #0x7b000;
    /* 0x5d1b0 */ sub x1, x9, #0x100;
    /* 0x5d1b4 */ mov w2, #0x100;
    /* 0x5d1b8 */ ldr x0, [x0, #0x1a8];
    /* 0x5d1bc */ str x1, [x8, #0x248];
    return x0;
}
