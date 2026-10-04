// Library: libManis.so
// Function ID: libManis::0x32cf7c
// Recovered Name: sub_32cf7c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x32cf7c | Size: 60 bytes | SHA256: d9001017d9687d0e965d27ffa6ed5bbea3cf61a74dee8a9612b05c4a9d827d83
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_32cf7c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 15 instructions
    /* 0x32cf7c */ ldr x8, [x26, #0x28];
    /* 0x32cf80 */ ldur x9, [x29, #-0x10];
    /* 0x32cf84 */ cmp x8, x9;
    /* 0x32cf88 */ b.ne #0x32cfb0;
    /* 0x32cf8c */ and w0, w19, #1;
    /* 0x32cf90 */ mov sp, x29;
    /* 0x32cf94 */ ldp x20, x19, [sp, #0x50];
    /* 0x32cf98 */ ldp x22, x21, [sp, #0x40];
    /* 0x32cf9c */ ldp x24, x23, [sp, #0x30];
    /* 0x32cfa0 */ ldp x26, x25, [sp, #0x20];
    /* 0x32cfa4 */ ldp x28, x27, [sp, #0x10];
    return x0;
    __stack_chk_fail();
}
