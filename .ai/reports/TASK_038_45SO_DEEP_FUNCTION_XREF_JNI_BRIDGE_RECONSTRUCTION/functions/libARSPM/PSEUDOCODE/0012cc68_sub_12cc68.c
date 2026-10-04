// Library: libARSPM.so
// Function ID: libARSPM::0x12cc68
// Recovered Name: sub_12cc68
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x12cc68 | Size: 412 bytes | SHA256: d086ecd2a20889f74b06c656a378e55f2213c59ba6a6fc36c4d8193f5e0bf8d8
// Callers: 0 | Callees: 11 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_12cc68(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 103 instructions
    /* 0x12cc68 */ stp x29, x30, [sp, #0x48];
    /* 0x12cc6c */ str x25, [sp, #0x58];
    /* 0x12cc70 */ stp x24, x23, [sp, #0x60];
    /* 0x12cc74 */ stp x22, x21, [sp, #0x70];
    /* 0x12cc78 */ stp x20, x19, [sp, #0x80];
    /* 0x12cc7c */ add x29, sp, #0x48;
    /* 0x12cc80 */ mrs x24, tpidr_el0;
    /* 0x12cc84 */ mov w19, wzr;
    /* 0x12cc88 */ ldr x8, [x24, #0x28];
    /* 0x12cc8c */ cmp w2, #1;
    /* 0x12cc90 */ stur x8, [x29, #-0x10];
    sub_16814c();
    sub_1ea858();
    sub_1e9970();
    sub_145ed8();
    sub_13fca8();
    sub_46b27c();
    sub_12ce04();
    sub_1e9be0();
    sub_12cf04();
    sub_167cb0();
    return x0;
    sub_12cf04();
    sub_167cb0();
    sub_4eccd4();
    __stack_chk_fail();
}
