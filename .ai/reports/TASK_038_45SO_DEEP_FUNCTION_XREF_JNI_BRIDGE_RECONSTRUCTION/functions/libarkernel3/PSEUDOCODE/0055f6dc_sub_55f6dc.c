// Library: libarkernel3.so
// Function ID: libarkernel3::0x55f6dc
// Recovered Name: sub_55f6dc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55f6dc | Size: 116 bytes | SHA256: e034c6c66a7d0719f0af1f34115ad769e435c9e98ad093a7547aa0a9389025db
// Callers: 3 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, memset

void sub_55f6dc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0x55f6dc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x55f6e0 */ str x21, [sp, #0x10];
    /* 0x55f6e4 */ stp x20, x19, [sp, #0x20];
    /* 0x55f6e8 */ mov x29, sp;
    /* 0x55f6ec */ stp xzr, xzr, [x0];
    /* 0x55f6f0 */ str xzr, [x0, #0x10];
    /* 0x55f6f4 */ cbz x1, #0x55f720;
    /* 0x55f6f8 */ mov x20, x1;
    /* 0x55f6fc */ mov x19, x0;
    sub_5601e4();
    /* 0x55f704 */ ldr x21, [x19, #8];
    memset();
    return x0;
    _ZdlPv();
    sub_106b814();
}
