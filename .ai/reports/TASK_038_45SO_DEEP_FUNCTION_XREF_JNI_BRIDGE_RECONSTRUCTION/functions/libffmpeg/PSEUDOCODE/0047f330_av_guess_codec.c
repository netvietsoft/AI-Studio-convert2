// Library: libffmpeg.so
// Function ID: libffmpeg::0x47f330
// Recovered Name: av_guess_codec
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x47f330 | Size: 144 bytes | SHA256: 65bb78b36b4f7039f90f9eb350499cd4d9248344695d3529f8a19ac5ba5df637
// Callers: 0 | Callees: 0 | Imports: 2

// Calls external APIs: av_guess_format, av_match_name
// Strings referenced:
//   "segment"
//   "ssegment"

void av_guess_codec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 36 instructions
    /* 0x47f330 */ stp x30, x21, [sp, #-0x20]!;
    /* 0x47f334 */ stp x20, x19, [sp, #0x10];
    /* 0x47f338 */ ldr x1, [x0];
    /* 0x47f33c */ mov x19, x0;
    /* 0x47f340 */ adrp x0, #0x9b000;
    /* 0x47f344 */ add x0, x0, #0x526;
    /* 0x47f348 */ mov w20, w4;
    /* 0x47f34c */ mov x21, x2;
    av_match_name();
    /* 0x47f354 */ cbnz w0, #0x47f36c;
    /* 0x47f358 */ ldr x1, [x19];
    av_match_name();
    av_guess_format();
    return x0;
}
