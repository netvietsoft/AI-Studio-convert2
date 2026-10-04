// Library: liblabdeviceinfo.so
// Function ID: liblabdeviceinfo::0x9120
// Recovered Name: sub_9120
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9120 | Size: 48 bytes | SHA256: 0f7fa7fc49ceb9960f9ca5d08dd5bbba6b930891ccac70dac3c292061db007ef
// Callers: 1 | Callees: 0 | Imports: 0


void sub_9120(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x9120 */ adrp x8, #0x26000;
    /* 0x9124 */ ldrb w8, [x8, #0x3d0];
    /* 0x9128 */ cbz w8, #0x9150;
    /* 0x912c */ adrp x8, #0x26000;
    /* 0x9130 */ adrp x9, #0x26000;
    /* 0x9134 */ mov w10, w0;
    /* 0x9138 */ ldr x8, [x8, #0x3e0];
    /* 0x913c */ ldr w9, [x9, #0x424];
    /* 0x9140 */ add x8, x8, x10, lsl #6;
    /* 0x9144 */ cmp w9, w0;
    /* 0x9148 */ csel x0, x8, xzr, hi;
    return x0;
}
