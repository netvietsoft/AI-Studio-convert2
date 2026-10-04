// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x5632e8
// Recovered Name: sub_5632e8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x5632e8 | Size: 180 bytes | SHA256: a73a90ba85025c260be1c2e29a04e9ecd35dd0df3204c352766fecc80c44ece2
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nativeSetBodySlim3DCount(JII)V (table at 0x10cc6f8)
// Calls external APIs: _ZdlPv

jlong sub_5632e8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 45 instructions
    /* 0x5632e8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x5632ec */ str x21, [sp, #0x10];
    /* 0x5632f0 */ stp x20, x19, [sp, #0x20];
    /* 0x5632f4 */ mov x29, sp;
    /* 0x5632f8 */ cbz x2, #0x56338c;
    /* 0x5632fc */ cmp w3, #8;
    /* 0x563300 */ b.hi #0x56338c;
    /* 0x563304 */ mov w8, #0x18;
    /* 0x563308 */ mov x10, #-0x5555555555555556;
    /* 0x56330c */ umaddl x0, w3, w8, x2;
    /* 0x563310 */ movk x10, #0xaaab;
    _ZdlPv();
    _ZdlPv();
    return x0;
}
