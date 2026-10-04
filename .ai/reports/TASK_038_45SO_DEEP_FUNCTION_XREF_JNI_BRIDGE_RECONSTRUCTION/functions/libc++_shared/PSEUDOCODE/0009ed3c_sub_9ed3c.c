// Library: libc++_shared.so
// Function ID: libc++_shared::0x9ed3c
// Recovered Name: sub_9ed3c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ed3c | Size: 52 bytes | SHA256: d52e4955363801899592ad9a7a1e222acd2799df51c433c1d3a88ed177388bc0
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: _ZNSt20bad_array_new_lengthD1Ev, _ZNSt8bad_castC1Ev

void sub_9ed3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x9ed3c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x9ed40 */ str x19, [sp, #0x10];
    /* 0x9ed44 */ mov x29, sp;
    /* 0x9ed48 */ mov w0, #8;
    _ZNSt8bad_castC1Ev();
    /* 0x9ed50 */ mov x19, x0;
    _ZNSt20bad_array_new_lengthD1Ev();
    /* 0x9ed58 */ adrp x1, #0x141000;
    /* 0x9ed5c */ adrp x2, #0x141000;
    /* 0x9ed60 */ mov x0, x19;
    /* 0x9ed64 */ ldr x1, [x1, #0x9a0];
    sub_132758();
}
