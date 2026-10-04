// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x122de4
// Recovered Name: sub_122de4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x122de4 | Size: 36 bytes | SHA256: a88944f303720408790553ff518b4613e14a8ec63d750408c3cf13136961f4b7
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_seekGetFrame(JD)I (table at 0x13a910)
// Calls external APIs: _ZN3PVG8PVGCodec12seekGetFrameEd

jlong sub_122de4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x122de4 */ cbz x2, #0x122e08;
    /* 0x122de8 */ mov x8, #0x400000000000;
    /* 0x122dec */ mov x0, x2;
    /* 0x122df0 */ movk x8, #0x408f, lsl #48;
    /* 0x122df4 */ fmov d1, x8;
    /* 0x122df8 */ fdiv d0, d0, d1;
    /* 0x122dfc */ fcvt s0, d0;
    /* 0x122e00 */ fcvt d0, s0;
    /* 0x122e04 */ b #0x133c30;
}
