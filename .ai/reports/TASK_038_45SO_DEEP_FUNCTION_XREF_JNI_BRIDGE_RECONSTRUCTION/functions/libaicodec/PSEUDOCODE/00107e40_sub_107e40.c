// Library: libaicodec.so
// Function ID: libaicodec::0x107e40
// Recovered Name: sub_107e40
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107e40 | Size: 44 bytes | SHA256: 6f8f2e52c0fbf6a5a240ed7012031d8d81bdb58761c38db4cb4878a3773b84ea
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setEnableVideo(JZ)V (table at 0x1fedf8)
// Calls external APIs: _ZN7MMCodec13MTMediaReader14setEnableVideoEb

jlong sub_107e40(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x107e40 */ cbz x2, #0x107e58;
    /* 0x107e44 */ and w8, w3, #0xff;
    /* 0x107e48 */ mov x0, x2;
    /* 0x107e4c */ cmp w8, #1;
    /* 0x107e50 */ cset w1, eq;
    /* 0x107e54 */ b #0x1f65d0;
    /* 0x107e58 */ adrp x8, #0x201000;
    /* 0x107e5c */ ldr x8, [x8, #0x868];
    /* 0x107e60 */ ldr w8, [x8];
    /* 0x107e64 */ cmp w8, #5;
    /* 0x107e68 */ b.gt #0x107ea4;
}
