// Library: libffmpeg.so
// Function ID: libffmpeg::0x377570
// Recovered Name: sub_377570
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x377570 | Size: 128 bytes | SHA256: 28fdf392b14192e35b71676e9ccf06ddca105b515928e3e2fc2d4a14106f520d
// Callers: 0 | Callees: 3 | Imports: 1

// Calls external APIs: ff_cbs_read_unsigned
// Strings referenced:
//   "slice_sao_luma_flag"
//   "slice_segment_address"

void sub_377570(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x377570 */ ldrb w8, [x22, #0x85b];
    /* 0x377574 */ cbz w8, #0x3778d8;
    /* 0x377578 */ adrp x3, #0xd2000;
    /* 0x37757c */ add x3, x3, #0x74d;
    /* 0x377580 */ add x1, sp, #0x28;
    /* 0x377584 */ add x4, sp, #0xd0;
    sub_39dea8();
    /* 0x37758c */ tbnz w0, #0x1f, #0x379178;
    /* 0x377590 */ ldr w8, [sp, #0xd0];
    /* 0x377594 */ strb w8, [x21, #0x129];
    /* 0x377598 */ ldrb w8, [x22, #0x1b1];
    sub_39f908();
    sub_3a1d9c();
    ff_cbs_read_unsigned();
}
