// Library: libffmpeg.so
// Function ID: libffmpeg::0x625e84
// Recovered Name: sub_625e84
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x625e84 | Size: 4052 bytes | SHA256: a0b2ed2e3ee73b8ef8c78469eae2aa5340049b069fa114d8dbbf116b92d8a52e
// Callers: 0 | Callees: 8 | Imports: 18

// Calls external APIs: exp2, exp2f, fopen, log2, log2f, memcpy, memset, powf, sprintf, sscanf, strchr, strcmp, strcpy, strcspn, strlen, strncmp, strstr, strtok_r
// Strings referenced:
//   "#options:"
//   "#options: %dx%d"
//   "%d "
//   "%d,%d%n"
//   "%d,%d,b=%f%n"

void sub_625e84(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1013 instructions
    /* 0x625e84 */ stp x29, x30, [sp, #0xd0];
    /* 0x625e88 */ stp x28, x27, [sp, #0xe0];
    /* 0x625e8c */ stp x26, x25, [sp, #0xf0];
    /* 0x625e90 */ stp x24, x23, [sp, #0x100];
    /* 0x625e94 */ stp x22, x21, [sp, #0x110];
    /* 0x625e98 */ stp x20, x19, [sp, #0x120];
    /* 0x625e9c */ ldrsw x8, [x0, #4];
    /* 0x625ea0 */ mov w9, #0x308;
    /* 0x625ea4 */ mov x19, x0;
    /* 0x625ea8 */ smull x0, w8, w9;
    /* 0x625eac */ mov w8, #0xb790;
    sub_528c1c();
    memset();
    sub_6259bc();
    sub_528aa0();
    log2();
    log2();
    log2();
    sub_5d44d0();
    exp2();
    log2f();
    log2f();
    exp2();
    sub_528c1c();
    sub_528c1c();
    exp2f();
    exp2f();
    exp2f();
    exp2f();
    exp2f();
    sub_5d44d0();
    strlen();
    sub_528c1c();
    strcpy();
    sub_5d44d0();
    sub_528c1c();
    memcpy();
    sub_528c1c();
    memcpy();
    sub_528c1c();
    strcspn();
    sscanf();
    sscanf();
    sscanf();
    sub_528c1c();
    memcpy();
    strtok_r();
    strchr();
    sub_529c70();
    strtok_r();
    sub_5d44d0();
    sub_528c80();
    sub_528c80();
    sub_528c8c();
    sub_6278b8();
    fopen();
    sub_528c80();
    strncmp();
    strchr();
    sscanf();
    powf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    sub_5d44d0();
    sub_5d44d0();
    sub_5d44d0();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strstr();
    sub_5d44d0();
    sscanf();
    strcmp();
    sub_5d44d0();
    strstr();
    sprintf();
    strlen();
    strncmp();
    strcspn();
    sub_5d44d0();
    strstr();
    sub_5d44d0();
    strstr();
    sub_5d44d0();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strchr();
    sub_5d44d0();
}
