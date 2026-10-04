// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2b8bc0
// Recovered Name: sub_2b8bc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2b8bc0 | Size: 92 bytes | SHA256: a0f2bda3f54a7b4aeee4045b07e24e9807a03b8dc9de52aef4a27937f0d917d9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_2b8bc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2b8bc0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2b8bc4 */ str x19, [sp, #0x10];
    /* 0x2b8bc8 */ mov x29, sp;
    /* 0x2b8bcc */ ldrb w8, [x2, #0x18];
    /* 0x2b8bd0 */ mov x19, x2;
    /* 0x2b8bd4 */ tbnz w8, #0, #0x2b8bf4;
    /* 0x2b8bd8 */ ldrb w8, [x19];
    /* 0x2b8bdc */ tbnz w8, #0, #0x2b8c04;
    /* 0x2b8be0 */ mov x0, x19;
    /* 0x2b8be4 */ ldr x19, [sp, #0x10];
    /* 0x2b8be8 */ ldp x29, x30, [sp], #0x20;
    return x0;
    _ZdlPv();
    _ZdlPv();
}
