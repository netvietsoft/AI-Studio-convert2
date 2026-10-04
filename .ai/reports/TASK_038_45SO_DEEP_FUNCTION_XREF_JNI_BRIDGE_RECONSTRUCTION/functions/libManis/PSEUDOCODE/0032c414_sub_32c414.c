// Library: libManis.so
// Function ID: libManis::0x32c414
// Recovered Name: sub_32c414
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32c414 | Size: 44 bytes | SHA256: 77f726dcd612910fc6b7f790e61d10dc631e48e2d7242e1bbcb02089c17ef832
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZdaPv

void sub_32c414(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x32c414 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x32c418 */ str x19, [sp, #0x10];
    /* 0x32c41c */ mov x29, sp;
    /* 0x32c420 */ mov x19, x0;
    /* 0x32c424 */ ldr x0, [x0];
    /* 0x32c428 */ cbz x0, #0x32c434;
    _ZdaPv();
    /* 0x32c430 */ str xzr, [x19];
    /* 0x32c434 */ ldr x19, [sp, #0x10];
    /* 0x32c438 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
