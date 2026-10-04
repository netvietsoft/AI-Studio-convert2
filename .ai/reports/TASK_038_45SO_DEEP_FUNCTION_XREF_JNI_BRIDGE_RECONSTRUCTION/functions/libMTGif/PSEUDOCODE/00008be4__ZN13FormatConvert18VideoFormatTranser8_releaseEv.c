// Library: libMTGif.so
// Function ID: libMTGif::0x8be4
// Recovered Name: _ZN13FormatConvert18VideoFormatTranser8_releaseEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8be4 | Size: 208 bytes | SHA256: c32d489e45b9be7e0e9560710583819ba51dc36ba7d81f10f3b978318869c7aa
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: avcodec_close, avcodec_free_context, avcodec_is_open, avformat_close_input, sws_freeContext

void _ZN13FormatConvert18VideoFormatTranser8_releaseEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0x8be4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8be8 */ str x19, [sp, #0x10];
    /* 0x8bec */ mov x29, sp;
    /* 0x8bf0 */ ldr x8, [x0, #0x10];
    /* 0x8bf4 */ mov x19, x0;
    /* 0x8bf8 */ ldr x0, [x8, #0x10];
    /* 0x8bfc */ cbz x0, #0x8c28;
    avcodec_is_open();
    /* 0x8c04 */ cbz w0, #0x8c14;
    /* 0x8c08 */ ldr x8, [x19, #0x10];
    /* 0x8c0c */ ldr x0, [x8, #0x10];
    avcodec_close();
    avcodec_free_context();
    avcodec_is_open();
    avcodec_close();
    avcodec_free_context();
    avformat_close_input();
    avformat_close_input();
    sws_freeContext();
    return x0;
}
