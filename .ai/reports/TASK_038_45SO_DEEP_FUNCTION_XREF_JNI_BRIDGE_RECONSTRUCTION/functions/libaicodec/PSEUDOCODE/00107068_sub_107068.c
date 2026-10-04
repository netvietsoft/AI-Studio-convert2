// Library: libaicodec.so
// Function ID: libaicodec::0x107068
// Recovered Name: sub_107068
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107068 | Size: 32 bytes | SHA256: a28251a8322e245833d90e834a657bcb6927e30ed5f9bb3cab0c39910f6bcd6d
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_pause(J)V (table at 0x1fec18)
// Calls external APIs: _ZN7MMCodec13MTMediaReader5pauseEv

jlong sub_107068(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x107068 */ cbz x2, #0x107074;
    /* 0x10706c */ mov x0, x2;
    /* 0x107070 */ b #0x1f6580;
    /* 0x107074 */ adrp x8, #0x201000;
    /* 0x107078 */ ldr x8, [x8, #0x868];
    /* 0x10707c */ ldr w8, [x8];
    /* 0x107080 */ cmp w8, #5;
    /* 0x107084 */ b.gt #0x1070c0;
}
