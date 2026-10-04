// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x1590
// Recovered Name: _Z8readFulliPal
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1590 | Size: 132 bytes | SHA256: 55a23ae1e443055a06cc2d83ca325369026db06f5e2518bdd86b7e5636c2cfca
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: __errno, __read_chk

void _Z8readFulliPal(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x1590 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x1594 */ stp x22, x21, [sp, #0x10];
    /* 0x1598 */ stp x20, x19, [sp, #0x20];
    /* 0x159c */ mov x29, sp;
    /* 0x15a0 */ mov x19, x2;
    /* 0x15a4 */ cbz x2, #0x15fc;
    /* 0x15a8 */ mov x21, x1;
    /* 0x15ac */ mov w22, w0;
    /* 0x15b0 */ mov x20, x19;
    /* 0x15b4 */ b #0x15cc;
    __errno();
    __read_chk();
    return x0;
}
