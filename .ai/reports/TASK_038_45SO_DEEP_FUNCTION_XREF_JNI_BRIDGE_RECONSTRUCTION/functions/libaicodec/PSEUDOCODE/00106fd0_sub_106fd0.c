// Library: libaicodec.so
// Function ID: libaicodec::0x106fd0
// Recovered Name: sub_106fd0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x106fd0 | Size: 32 bytes | SHA256: 18ef90e03dc19f2d9391a41f3ccabdb861a8c7f7c9653836974606cef7dd7293
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_stop(J)V (table at 0x1fec00)
// Calls external APIs: _ZN7MMCodec13MTMediaReader11stopDecoderEv

jlong sub_106fd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x106fd0 */ cbz x2, #0x106fdc;
    /* 0x106fd4 */ mov x0, x2;
    /* 0x106fd8 */ b #0x1f6570;
    /* 0x106fdc */ adrp x8, #0x201000;
    /* 0x106fe0 */ ldr x8, [x8, #0x868];
    /* 0x106fe4 */ ldr w8, [x8];
    /* 0x106fe8 */ cmp w8, #5;
    /* 0x106fec */ b.gt #0x107028;
}
