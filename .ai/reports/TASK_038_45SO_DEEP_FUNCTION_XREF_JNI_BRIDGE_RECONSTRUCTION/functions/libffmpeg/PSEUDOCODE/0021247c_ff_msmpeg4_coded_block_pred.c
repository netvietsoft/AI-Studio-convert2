// Library: libffmpeg.so
// Function ID: libffmpeg::0x21247c
// Recovered Name: ff_msmpeg4_coded_block_pred
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x21247c | Size: 60 bytes | SHA256: cd48cbc19c9643facbd7180cf1ba16a9f3ff8305786f89501f784315c46f3716
// Callers: 0 | Callees: 0 | Imports: 0


void ff_msmpeg4_coded_block_pred(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x21247c */ add x8, x0, w1, sxtw #2;
    /* 0x212480 */ ldrsw x11, [x0, #0x254];
    /* 0x212484 */ ldr x9, [x0, #0x5d0];
    /* 0x212488 */ ldrsw x8, [x8, #0x12b0];
    /* 0x21248c */ sub x12, x9, x11;
    /* 0x212490 */ sub x10, x8, #1;
    /* 0x212494 */ sub x11, x8, x11;
    /* 0x212498 */ ldrb w12, [x12, w10, sxtw];
    /* 0x21249c */ ldrb w0, [x9, x11];
    /* 0x2124a0 */ cmp w12, w0;
    /* 0x2124a4 */ b.ne #0x2124ac;
    return x0;
}
