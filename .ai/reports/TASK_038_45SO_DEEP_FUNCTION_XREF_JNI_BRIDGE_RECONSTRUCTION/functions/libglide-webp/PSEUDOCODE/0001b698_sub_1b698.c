// Library: libglide-webp.so
// Function ID: libglide-webp::0x1b698
// Recovered Name: sub_1b698
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x1b698 | Size: 1340 bytes | SHA256: 57a02c3402fbdf4ec9578fd2e24394fa4a977555fff15641e5ee5cc2c5351ae9
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: VP8GetSignedValue, VP8GetValue, VP8InitBitReader, VP8ParseProba, VP8ParseQuant
// Strings referenced:
//   "Not a key frame."
//   "cannot parse filter header"
//   "cannot parse partitions"
//   "cannot parse segment header"

void sub_1b698(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 335 instructions
    /* 0x1b698 */ str x8, [x19, #8];
    /* 0x1b69c */ str d0, [x19];
    /* 0x1b6a0 */ b #0x1ba68;
    /* 0x1b6a4 */ add x20, x19, #0x10;
    /* 0x1b6a8 */ mov x0, x20;
    /* 0x1b6ac */ mov x1, x21;
    VP8InitBitReader();
    /* 0x1b6b4 */ ldrb w8, [x19, #0x40];
    /* 0x1b6b8 */ ldr w24, [x19, #0x44];
    /* 0x1b6bc */ cbz w8, #0x1b6e0;
    /* 0x1b6c0 */ mov w1, #1;
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetSignedValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    VP8GetValue();
    return x0;
    VP8GetValue();
    VP8InitBitReader();
    VP8InitBitReader();
    VP8ParseQuant();
    VP8GetValue();
    VP8ParseProba();
}
