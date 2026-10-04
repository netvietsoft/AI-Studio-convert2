// Library: libhiai.so
// Function ID: libhiai::0x26fe4
// Recovered Name: sub_26fe4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x26fe4 | Size: 120 bytes | SHA256: 76066ddd63b9151f80f839ca2a27ed8f114407e714c560cb4643225773473d9d
// Callers: 1 | Callees: 0 | Imports: 3

// Calls external APIs: _ZN4hiai10BaseBufferC1EPhmb, _Znwm, _ZnwmRKSt9nothrow_t

void sub_26fe4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x26fe4 */ stp x30, x23, [sp, #-0x30]!;
    /* 0x26fe8 */ stp x22, x21, [sp, #0x10];
    /* 0x26fec */ stp x20, x19, [sp, #0x20];
    /* 0x26ff0 */ mov x22, x1;
    /* 0x26ff4 */ adrp x1, #0x72000;
    /* 0x26ff8 */ mov x23, x0;
    /* 0x26ffc */ ldr x1, [x1, #0xfe8];
    /* 0x27000 */ mov w0, #0x50;
    /* 0x27004 */ mov x21, x2;
    /* 0x27008 */ mov x19, x8;
    _ZnwmRKSt9nothrow_t();
    _ZN4hiai10BaseBufferC1EPhmb();
    _Znwm();
    return x0;
}
