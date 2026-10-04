// Library: libCtaApiLib.so
// Function ID: libCtaApiLib::0xc780
// Recovered Name: sub_c780
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc780 | Size: 64 bytes | SHA256: 618b8e6a97a3fa0aa904c35066f3db075c6bb0ade90db78ba973a719e4b5b7af
// Callers: 3 | Callees: 0 | Imports: 0


void sub_c780(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0xc780 */ adrp x2, #0x87000;
    /* 0xc784 */ ldr x2, [x2, #0xe60];
    /* 0xc788 */ cbz x2, #0xc7a4;
    /* 0xc78c */ add x3, x0, #0x10;
    /* 0xc790 */ ldaxr w2, [x3];
    /* 0xc794 */ sub w4, w2, #1;
    /* 0xc798 */ stlxr w5, w4, [x3];
    /* 0xc79c */ cbz w5, #0xc7b0;
    /* 0xc7a0 */ b #0xc790;
    /* 0xc7a4 */ ldr w2, [x0, #0x10];
    /* 0xc7a8 */ sub w3, w2, #1;
    return x0;
}
