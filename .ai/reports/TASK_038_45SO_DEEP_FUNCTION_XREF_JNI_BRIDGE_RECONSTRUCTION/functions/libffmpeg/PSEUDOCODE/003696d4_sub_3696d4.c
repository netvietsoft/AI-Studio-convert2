// Library: libffmpeg.so
// Function ID: libffmpeg::0x3696d4
// Recovered Name: sub_3696d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3696d4 | Size: 624 bytes | SHA256: dc8b9a2898ec8b3669aca9168033b4f94f6cd5c204b4b232433eb9c90c58abc6
// Callers: 0 | Callees: 8 | Imports: 2

// Calls external APIs: ff_cbs_alloc_unit_content, ff_cbs_trace_header
// Strings referenced:
//   "Frame"
//   "first_partition_length_in_bytes"
//   "frame_type"
//   "profile"
//   "segment_feature_mode"

void sub_3696d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 156 instructions
    /* 0x3696d4 */ stp x29, x30, [sp, #0x90];
    /* 0x3696d8 */ stp x28, x27, [sp, #0xa0];
    /* 0x3696dc */ stp x26, x25, [sp, #0xb0];
    /* 0x3696e0 */ stp x24, x23, [sp, #0xc0];
    /* 0x3696e4 */ stp x22, x21, [sp, #0xd0];
    /* 0x3696e8 */ stp x20, x19, [sp, #0xe0];
    /* 0x3696ec */ mov x19, x1;
    /* 0x3696f0 */ mov x20, x0;
    ff_cbs_alloc_unit_content();
    /* 0x3696f8 */ tbnz w0, #0x1f, #0x369944;
    /* 0x3696fc */ ldr w8, [x19, #0x10];
    ff_cbs_trace_header();
    sub_36a8cc();
    sub_36a32c();
    sub_36a32c();
    sub_36a8cc();
    sub_36a32c();
    sub_36a32c();
    sub_36a7cc();
    sub_36a7ec();
    sub_36a85c();
    sub_36a470();
    sub_36a85c();
    sub_36a470();
    sub_36a7fc();
    sub_36a6dc();
}
