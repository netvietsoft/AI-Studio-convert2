// Library: libKKMusicFX.so
// Function ID: libKKMusicFX::0x2e464
// Recovered Name: sub_2e464
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e464 | Size: 52 bytes | SHA256: b1aac1b2e386f0338bd1677aabefcabda1afbfc0a623344bf696714d1a95a726
// Callers: 9 | Callees: 0 | Imports: 3

// Calls external APIs: _ZNSt20bad_array_new_lengthC1Ev, __cxa_allocate_exception, __cxa_throw

void sub_2e464(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2e464 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2e468 */ str x19, [sp, #0x10];
    /* 0x2e46c */ mov x29, sp;
    /* 0x2e470 */ mov w0, #8;
    __cxa_allocate_exception();
    /* 0x2e478 */ mov x19, x0;
    _ZNSt20bad_array_new_lengthC1Ev();
    /* 0x2e480 */ adrp x1, #0x81000;
    /* 0x2e484 */ adrp x2, #0x81000;
    /* 0x2e488 */ mov x0, x19;
    /* 0x2e48c */ ldr x1, [x1, #0xce0];
    __cxa_throw();
}
