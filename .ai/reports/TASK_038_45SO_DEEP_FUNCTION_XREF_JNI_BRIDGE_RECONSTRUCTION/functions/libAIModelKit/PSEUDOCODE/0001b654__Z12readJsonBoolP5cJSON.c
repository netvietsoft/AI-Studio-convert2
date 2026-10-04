// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b654
// Recovered Name: _Z12readJsonBoolP5cJSON
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1b654 | Size: 40 bytes | SHA256: 2af5698d5743edf99c7764ec7dde108a0aca21f84421a5b7f1cae90e92c78675
// Callers: 0 | Callees: 0 | Imports: 0


void _Z12readJsonBoolP5cJSON(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x1b654 */ cbz x0, #0x1b6bc;
    /* 0x1b658 */ ldr w8, [x0, #0x18];
    /* 0x1b65c */ cmp w8, #1;
    /* 0x1b660 */ b.eq #0x1b6b0;
    /* 0x1b664 */ cmp w8, #3;
    /* 0x1b668 */ b.eq #0x1b6a0;
    /* 0x1b66c */ cmp w8, #4;
    /* 0x1b670 */ b.ne #0x1b6b8;
    /* 0x1b674 */ ldr x0, [x0, #0x20];
    /* 0x1b678 */ cbz x0, #0x1b6bc;
}
