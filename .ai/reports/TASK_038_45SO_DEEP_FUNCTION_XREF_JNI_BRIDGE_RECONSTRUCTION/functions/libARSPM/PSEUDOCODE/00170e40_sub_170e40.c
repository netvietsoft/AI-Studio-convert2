// Library: libARSPM.so
// Function ID: libARSPM::0x170e40
// Recovered Name: sub_170e40
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x170e40 | Size: 156 bytes | SHA256: eea6384e882fbdc66cfcc0f7b5bf61740e06e004a532f70f581b692a949fe08f
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: abort
// Strings referenced:
//   "../../../../src/core/SkMaskBlurFilter.cpp"

void sub_170e40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x170e40 */ ldur w8, [x29, #-0x18];
    /* 0x170e44 */ ldr x24, [sp, #0xc8];
    /* 0x170e48 */ sub w2, w8, w27;
    /* 0x170e4c */ cmp w2, #1;
    /* 0x170e50 */ b.lt #0x1708e0;
    /* 0x170e54 */ shrn v0.8b, v20.8h, #8;
    /* 0x170e58 */ cmp w2, #8;
    /* 0x170e5c */ b.ne #0x1708c0;
    /* 0x170e60 */ str d0, [x26];
    /* 0x170e64 */ b #0x1708e0;
    /* 0x170e68 */ ldr x28, [sp, #0x60];
    abort();
    abort();
    sub_2cfaa0();
    sub_2666c0();
    sub_2cfaa0();
    sub_2666c0();
}
