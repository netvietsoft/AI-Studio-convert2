// Library: libPVGLive.so
// Function ID: libPVGLive::0x27788
// Recovered Name: sub_27788
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x27788 | Size: 64 bytes | SHA256: 4bfd66fa1fa3af422549cd230eaaf84d66d450a65ba5ad5cd552f9762b2c3d9f
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: _ZdlPv

void sub_27788(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x27788 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2778c */ str x19, [sp, #0x10];
    /* 0x27790 */ mov x29, sp;
    /* 0x27794 */ mov x19, x0;
    sub_27724();
    /* 0x2779c */ mov x0, x19;
    /* 0x277a0 */ ldr x19, [sp, #0x10];
    /* 0x277a4 */ ldp x29, x30, [sp], #0x20;
    /* 0x277a8 */ b #0x904e0;
    /* 0x277ac */ mov x8, x0;
    /* 0x277b0 */ cmp w2, #1;
}
