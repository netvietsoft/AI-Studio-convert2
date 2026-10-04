// Library: libaicodec.so
// Function ID: libaicodec::0xcebc4
// Recovered Name: sub_cebc4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xcebc4 | Size: 16 bytes | SHA256: 04c80c09e1a144047b64ef4cc05e746b1b24582f9e8fb3a9436d8c3a56424c34
// Callers: 139 | Callees: 0 | Imports: 2

// Calls external APIs: _ZSt9terminatev, __cxa_begin_catch

void sub_cebc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xcebc4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xcebc8 */ mov x29, sp;
    __cxa_begin_catch();
    _ZSt9terminatev();
}
