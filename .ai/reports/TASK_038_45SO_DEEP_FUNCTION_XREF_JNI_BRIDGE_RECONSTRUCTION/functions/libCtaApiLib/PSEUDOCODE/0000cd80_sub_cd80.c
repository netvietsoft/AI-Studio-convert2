// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xcd80
// Recovered Name: sub_cd80
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xcd80 | Size: 16 bytes | SHA256: acfe64030b5593be8860130b3cfc874ea1f5739401205f65ee50dd4b312be14e
// Callers: 1 | Callees: 0 | Imports: 0


void sub_cd80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xcd80 */ sub sp, sp, #0xb0;
    /* 0xcd84 */ str x23, [sp, #0x70];
    /* 0xcd88 */ stp x22, x21, [sp, #0x80];
    /* 0xcd8c */ stp x20, x19, [sp, #0x90];
}
