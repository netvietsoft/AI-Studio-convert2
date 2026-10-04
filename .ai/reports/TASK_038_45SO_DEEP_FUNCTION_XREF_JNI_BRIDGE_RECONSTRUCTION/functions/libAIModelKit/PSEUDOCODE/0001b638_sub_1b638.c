// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b638
// Recovered Name: sub_1b638
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1b638 | Size: 28 bytes | SHA256: 0d8f36cc1607619f5d1b0a7e82c0f712c508d78d6fab37c537d7f5d487402cbe
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: strncpy

void sub_1b638(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x1b638 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x1b63c */ mov x29, sp;
    /* 0x1b640 */ mov w2, #0xff;
    strncpy();
    /* 0x1b648 */ strb wzr, [x0, #0xff];
    /* 0x1b64c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
