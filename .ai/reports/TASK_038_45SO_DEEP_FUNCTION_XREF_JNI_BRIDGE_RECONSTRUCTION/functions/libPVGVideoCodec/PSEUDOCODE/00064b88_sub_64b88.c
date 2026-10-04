// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x64b88
// Recovered Name: sub_64b88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x64b88 | Size: 16 bytes | SHA256: 6d1e8647d963858886134fd2656c9052e5267dc3d82f650bc52e69643c363ede
// Callers: 111 | Callees: 0 | Imports: 2

// Calls external APIs: _ZSt9terminatev, __cxa_begin_catch

void sub_64b88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x64b88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x64b8c */ mov x29, sp;
    __cxa_begin_catch();
    _ZSt9terminatev();
}
