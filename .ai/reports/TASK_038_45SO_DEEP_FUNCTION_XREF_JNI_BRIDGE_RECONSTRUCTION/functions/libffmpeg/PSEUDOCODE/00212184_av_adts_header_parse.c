// Library: libffmpeg.so
// Function ID: libffmpeg::0x212184
// Recovered Name: av_adts_header_parse
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x212184 | Size: 100 bytes | SHA256: 4fc09d08aa3191364060579306d22ae223ba582b689223320b0b0b502cde5564
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: ff_adts_header_parse_buf

void av_adts_header_parse(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0x212184 */ cbz x0, #0x2121e0;
    /* 0x212188 */ sub sp, sp, #0x80;
    /* 0x21218c */ str x30, [sp, #0x60];
    /* 0x212190 */ stp x20, x19, [sp, #0x70];
    /* 0x212194 */ ldr w8, [x0];
    /* 0x212198 */ ldur w9, [x0, #3];
    /* 0x21219c */ mov x20, x1;
    /* 0x2121a0 */ add x0, sp, #0x18;
    /* 0x2121a4 */ mov x1, sp;
    /* 0x2121a8 */ mov x19, x2;
    /* 0x2121ac */ str w8, [sp, #0x18];
    ff_adts_header_parse_buf();
    return x0;
    return x0;
}
