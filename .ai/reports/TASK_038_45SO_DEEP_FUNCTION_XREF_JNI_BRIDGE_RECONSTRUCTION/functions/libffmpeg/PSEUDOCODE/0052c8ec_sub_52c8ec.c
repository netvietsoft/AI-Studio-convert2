// Library: libffmpeg.so
// Function ID: libffmpeg::0x52c8ec
// Recovered Name: sub_52c8ec
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x52c8ec | Size: 2268 bytes | SHA256: 540aababbf23967f4cad58db5b965f7eeb26b42e4ecc9d15395409fe5c6078b5
// Callers: 4 | Callees: 1 | Imports: 3

// Calls external APIs: memalign, sprintf, strlen
// Strings referenced:
//   " 8x8dct=%d"
//   " analyse=%#x:%#x"
//   " aq=%d"
//   " b_pyramid=%d b_adapt=%d b_bias=%d direct=%d weightb=%d open_gop=%d"
//   " bframes=%d"

void sub_52c8ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 567 instructions
    /* 0x52c8ec */ sub sp, sp, #0x50;
    /* 0x52c8f0 */ str x30, [sp, #0x20];
    /* 0x52c8f4 */ stp x22, x21, [sp, #0x30];
    /* 0x52c8f8 */ stp x20, x19, [sp, #0x40];
    /* 0x52c8fc */ mov x19, x0;
    /* 0x52c900 */ ldr x0, [x0, #0x318];
    /* 0x52c904 */ mov w22, w1;
    /* 0x52c908 */ cbz x0, #0x52cca8;
    strlen();
    /* 0x52c910 */ adds w8, w0, #0x7d0;
    /* 0x52c914 */ sxtw x21, w8;
    memalign();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    memalign();
    sub_528b64();
    return x0;
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    sprintf();
    return x0;
    return x0;
}
