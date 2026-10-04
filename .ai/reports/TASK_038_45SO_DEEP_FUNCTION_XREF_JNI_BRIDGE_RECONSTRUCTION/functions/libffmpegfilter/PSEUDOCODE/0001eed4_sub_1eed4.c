// Library: libffmpegfilter.so
// Function ID: libffmpegfilter::0x1eed4
// Recovered Name: sub_1eed4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1eed4 | Size: 132 bytes | SHA256: 4cecf6c5d07105fec0951c40ffc206b21fd032f0407220a9f6f36327491d52df
// Callers: 2 | Callees: 0 | Imports: 2

// Calls external APIs: av_frame_free, ff_filter_process_command

void sub_1eed4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x1eed4 */ add x0, sp, #8;
    /* 0x1eed8 */ b #0x3cfd0;
    /* 0x1eedc */ mov x8, x0;
    /* 0x1eee0 */ mov w0, wzr;
    /* 0x1eee4 */ mov w9, #-1;
    /* 0x1eee8 */ ldr x8, [x8, #0x48];
    /* 0x1eeec */ str w9, [x8, #0x38];
    /* 0x1eef0 */ str wzr, [x8, #0xd0];
    return x0;
    /* 0x1eef8 */ ldr x0, [x0, #0x48];
    /* 0x1eefc */ b #0x1ff20;
    ff_filter_process_command();
    return x0;
}
