// Library: libffmpeg.so
// Function ID: libffmpeg::0x211f70
// Recovered Name: avpriv_strtod
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x211f70 | Size: 424 bytes | SHA256: b00a5118b4e8bebac7acf02e2dfbfca205aaabf74cdf5013fa7bcead1592510f
// Callers: 0 | Callees: 4 | Imports: 3

// Calls external APIs: av_strncasecmp, strtod, strtoll
// Strings referenced:
//   "+0x"
//   "+inf"
//   "+infinity"
//   "+nan"
//   "-0x"

void avpriv_strtod(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 106 instructions
    /* 0x211f70 */ str x30, [sp, #-0x20]!;
    /* 0x211f74 */ stp x20, x19, [sp, #0x10];
    /* 0x211f78 */ mov x9, #0x3e00;
    /* 0x211f7c */ mov x19, x1;
    /* 0x211f80 */ mov x20, x0;
    /* 0x211f84 */ mov w8, #1;
    /* 0x211f88 */ movk x9, #1, lsl #32;
    /* 0x211f8c */ ldrb w10, [x20];
    /* 0x211f90 */ lsl x11, x8, x10;
    /* 0x211f94 */ cmp w10, #0x20;
    /* 0x211f98 */ and x10, x11, x9;
    av_strncasecmp();
    sub_21216c();
    sub_212178();
    sub_212160();
    sub_212178();
    sub_212160();
    sub_21216c();
    sub_212160();
    sub_212160();
    av_strncasecmp();
    sub_21216c();
    sub_21216c();
    strtod();
    return x0;
    sub_212118();
    strtoll();
}
