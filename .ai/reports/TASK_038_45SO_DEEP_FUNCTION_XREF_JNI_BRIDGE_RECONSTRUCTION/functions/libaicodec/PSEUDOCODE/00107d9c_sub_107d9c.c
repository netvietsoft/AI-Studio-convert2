// Library: libaicodec.so
// Function ID: libaicodec::0x107d9c
// Recovered Name: sub_107d9c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107d9c | Size: 44 bytes | SHA256: 1cb106260ed69545dafd3903ff86570a33f5d7294846f3d7b0375f98f932d9f4
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setEnableAudio(JZ)V (table at 0x1fede0)
// Calls external APIs: _ZN7MMCodec13MTMediaReader14setEnableAudioEb

jlong sub_107d9c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x107d9c */ cbz x2, #0x107db4;
    /* 0x107da0 */ and w8, w3, #0xff;
    /* 0x107da4 */ mov x0, x2;
    /* 0x107da8 */ cmp w8, #1;
    /* 0x107dac */ cset w1, eq;
    /* 0x107db0 */ b #0x1f65c0;
    /* 0x107db4 */ adrp x8, #0x201000;
    /* 0x107db8 */ ldr x8, [x8, #0x868];
    /* 0x107dbc */ ldr w8, [x8];
    /* 0x107dc0 */ cmp w8, #5;
    /* 0x107dc4 */ b.gt #0x107e00;
}
