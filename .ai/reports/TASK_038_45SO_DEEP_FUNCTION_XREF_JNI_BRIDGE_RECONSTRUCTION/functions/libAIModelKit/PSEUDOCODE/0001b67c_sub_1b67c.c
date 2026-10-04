// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b67c
// Recovered Name: sub_1b67c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1b67c | Size: 68 bytes | SHA256: 5784ff98558a85b68bf06b521a14fcb490381774b798d8f3b32330fbd2b4ce5e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: strstr

void sub_1b67c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x1b67c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1b680 */ mov x29, sp;
    /* 0x1b684 */ nop ;
    /* 0x1b688 */ adr x1, #0x1087d;
    strstr();
    /* 0x1b690 */ cmp x0, #0;
    /* 0x1b694 */ cset w0, ne;
    /* 0x1b698 */ ldp x29, x30, [sp], #0x10;
    return x0;
    /* 0x1b6a0 */ ldr w8, [x0, #0x28];
    /* 0x1b6a4 */ cmp w8, #0;
    return x0;
    return x0;
    return x0;
}
