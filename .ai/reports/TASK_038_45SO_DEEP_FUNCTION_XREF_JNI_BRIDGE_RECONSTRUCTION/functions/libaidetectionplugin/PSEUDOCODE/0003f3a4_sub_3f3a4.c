// Library: libaidetectionplugin.so
// Function ID: libaidetectionplugin::0x3f3a4
// Recovered Name: sub_3f3a4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3f3a4 | Size: 16 bytes | SHA256: dcdfa0d370d4ea33a3266f259f87e0db0be5927f858c4daad4fdc05a5f82ee36
// Callers: 25 | Callees: 0 | Imports: 2

// Calls external APIs: _ZSt9terminatev, __cxa_begin_catch

void sub_3f3a4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x3f3a4 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3f3a8 */ mov x29, sp;
    __cxa_begin_catch();
    _ZSt9terminatev();
}
