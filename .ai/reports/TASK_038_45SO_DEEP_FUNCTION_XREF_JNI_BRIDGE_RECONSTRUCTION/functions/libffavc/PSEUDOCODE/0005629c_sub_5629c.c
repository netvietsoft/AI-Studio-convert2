// Library: libffavc.so
// Function ID: libffavc::0x5629c
// Recovered Name: sub_5629c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x5629c | Size: 220 bytes | SHA256: e5f7613c1288329007d3a67b52ead46a5a0e6b87f26b89a28bd4a1e89cd444a1
// Callers: 0 | Callees: 6 | Imports: 2

// Calls external APIs: __stack_chk_fail, memset

void sub_5629c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x5629c */ stp x29, x30, [sp, #0xc0];
    /* 0x562a0 */ str x23, [sp, #0xd0];
    /* 0x562a4 */ stp x22, x21, [sp, #0xe0];
    /* 0x562a8 */ stp x20, x19, [sp, #0xf0];
    /* 0x562ac */ add x29, sp, #0xc0;
    /* 0x562b0 */ mrs x23, tpidr_el0;
    /* 0x562b4 */ mov x19, x0;
    /* 0x562b8 */ mov w0, #0x1b;
    /* 0x562bc */ ldr x8, [x23, #0x28];
    /* 0x562c0 */ mov x20, x2;
    /* 0x562c4 */ mov x21, x1;
    sub_5665c();
    sub_c67c8();
    memset();
    sub_596c8();
    sub_5678c();
    sub_57898();
    sub_d3980();
    return x0;
    __stack_chk_fail();
}
