// Library: libffmpeg.so
// Function ID: libffmpeg::0x2e0c84
// Recovered Name: sub_2e0c84
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e0c84 | Size: 2548 bytes | SHA256: 42c4d7aa3be71b9fd578dfd1d4da74ccff42f7777be0f93c62713e88228d347b
// Callers: 0 | Callees: 18 | Imports: 3

// Calls external APIs: ff_cbs_read_signed, ff_cbs_read_simple_unsigned, ff_cbs_read_unsigned
// Strings referenced:
//   "base_q_idx"
//   "context_update_tile_id"
//   "delta_q_present"
//   "delta_q_res"
//   "delta_q_u_ac.delta_coded"

void sub_2e0c84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 637 instructions
    /* 0x2e0c84 */ ldrb w8, [x20, #2];
    /* 0x2e0c88 */ cbnz w8, #0x2e0c94;
    /* 0x2e0c8c */ ldrb w8, [x19, #0x10];
    /* 0x2e0c90 */ cbz w8, #0x2e0f40;
    /* 0x2e0c94 */ mov w8, #1;
    /* 0x2e0c98 */ strb w8, [x19, #0xe9];
    /* 0x2e0c9c */ mov w11, #6;
    /* 0x2e0ca0 */ mov w14, #0x1000;
    /* 0x2e0ca4 */ ldr x22, [x21, #0x10];
    /* 0x2e0ca8 */ mov w15, #0x900000;
    /* 0x2e0cac */ ldp w8, w9, [x22, #0x4c];
    sub_2e6cc8();
    sub_2e290c();
    sub_2e6c30();
    sub_2e290c();
    sub_2e290c();
    sub_2e70d8();
    sub_2e66d8();
    sub_2e70b8();
    sub_2e2928();
    sub_2e70b8();
    sub_2e2928();
    sub_2e2a34();
    sub_2e66d8();
    sub_2e290c();
    sub_2e70b8();
    sub_2e2a34();
    sub_2e290c();
    sub_2e70d8();
    ff_cbs_read_simple_unsigned();
    sub_2e70d8();
    ff_cbs_read_simple_unsigned();
    sub_2e7370();
    ff_cbs_read_simple_unsigned();
    sub_2e67ac();
    ff_cbs_read_unsigned();
    sub_2e67b8();
    sub_2e66d8();
    sub_2e66d8();
    sub_2e737c();
    ff_cbs_read_simple_unsigned();
    sub_2e737c();
    ff_cbs_read_simple_unsigned();
    sub_2e7370();
    ff_cbs_read_simple_unsigned();
    sub_2e66d8();
    sub_2e66d8();
    sub_2e6ba4();
    sub_2e6e98();
    sub_2e67b8();
    sub_2e67ac();
    ff_cbs_read_unsigned();
    sub_2e67b8();
    sub_2e6e98();
    sub_2e67b8();
    sub_2e67ac();
    ff_cbs_read_unsigned();
    sub_2e67b8();
    sub_2e66d8();
    sub_2e66d8();
    sub_2e66d8();
    sub_2e70e8();
    sub_2e6cbc();
    sub_2e67ac();
    ff_cbs_read_unsigned();
    ff_cbs_read_unsigned();
    sub_2e7390();
    ff_cbs_read_signed();
    sub_2e66d8();
    sub_2e69a8();
}
