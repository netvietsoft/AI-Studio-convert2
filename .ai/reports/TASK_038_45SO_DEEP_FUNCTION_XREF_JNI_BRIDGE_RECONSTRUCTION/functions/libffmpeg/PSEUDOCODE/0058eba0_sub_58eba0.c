// Library: libffmpeg.so
// Function ID: libffmpeg::0x58eba0
// Recovered Name: sub_58eba0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x58eba0 | Size: 4020 bytes | SHA256: 2e27840e7810df6d34304cc5ff594b76736a83220d75b3455571889962a96204
// Callers: 0 | Callees: 8 | Imports: 18

// Calls external APIs: exp2, exp2f, fopen, log2, log2f, memcpy, memset, powf, sprintf, sscanf, strchr, strcmp, strcpy, strcspn, strlen, strncmp, strstr, strtok_r
// Strings referenced:
//   "#options:"
//   "#options: %dx%d"
//   "%d "
//   "%d,%d%n"
//   "%d,%d,b=%f%n"

void sub_58eba0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 1005 instructions
    /* 0x58eba0 */ stp x29, x30, [sp, #0xc0];
    /* 0x58eba4 */ stp x28, x27, [sp, #0xd0];
    /* 0x58eba8 */ stp x26, x25, [sp, #0xe0];
    /* 0x58ebac */ stp x24, x23, [sp, #0xf0];
    /* 0x58ebb0 */ stp x22, x21, [sp, #0x100];
    /* 0x58ebb4 */ stp x20, x19, [sp, #0x110];
    /* 0x58ebb8 */ ldrsw x8, [x0, #4];
    /* 0x58ebbc */ mov w9, #0x308;
    /* 0x58ebc0 */ mov x19, x0;
    /* 0x58ebc4 */ smull x0, w8, w9;
    /* 0x58ebc8 */ mov w8, #0x5f58;
    sub_528c1c();
    memset();
    sub_58e6e4();
    sub_528aa0();
    log2();
    log2();
    log2();
    sub_53c298();
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
    sub_53c298();
    strlen();
    sub_528c1c();
    strcpy();
    sub_53c298();
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
    sub_53c298();
    sub_528c80();
    sub_528c80();
    sub_528c8c();
    sub_5905a8();
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
    sub_53c298();
    sub_53c298();
    sub_53c298();
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
    sub_53c298();
    sscanf();
    strcmp();
    sub_53c298();
    strstr();
    sprintf();
    strlen();
    strncmp();
    strcspn();
    sub_53c298();
    strstr();
    sub_53c298();
    strstr();
    sub_53c298();
    strstr();
    sscanf();
    strstr();
    sscanf();
    strchr();
    sub_53c298();
}
