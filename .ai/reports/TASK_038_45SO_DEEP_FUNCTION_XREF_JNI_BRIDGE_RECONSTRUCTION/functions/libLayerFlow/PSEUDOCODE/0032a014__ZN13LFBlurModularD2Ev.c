// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x32a014
// Recovered Name: _ZN13LFBlurModularD2Ev
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x32a014 | Size: 68 bytes | SHA256: 42a98557c25e959184026cefe93e6034850a67945798a0b777efa86cfdc6b045
// Callers: 8 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdlPv

void _ZN13LFBlurModularD2Ev(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x32a014 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x32a018 */ str x19, [sp, #0x10];
    /* 0x32a01c */ mov x29, sp;
    /* 0x32a020 */ mov x19, x0;
    /* 0x32a024 */ ldr x0, [x0, #0x50];
    /* 0x32a028 */ cbz x0, #0x32a034;
    /* 0x32a02c */ str x0, [x19, #0x58];
    _ZdlPv();
    /* 0x32a034 */ ldrb w8, [x19, #8];
    /* 0x32a038 */ tbnz w8, #0, #0x32a048;
    /* 0x32a03c */ ldr x19, [sp, #0x10];
    return x0;
}
