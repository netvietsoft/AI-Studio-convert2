// Library: libaicodec.so
// Function ID: libaicodec::0x107ee4
// Recovered Name: sub_107ee4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107ee4 | Size: 36 bytes | SHA256: 8ebf7551543b0fa57f9163cb7684063a2773df127130bc0263cd45e534faea42
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_setStartTime(JJ)V (table at 0x1fee10)
// Calls external APIs: _ZN7MMCodec13MTMediaReader12setStartTimeEl

jlong sub_107ee4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x107ee4 */ cbz x2, #0x107ef4;
    /* 0x107ee8 */ mov x0, x2;
    /* 0x107eec */ mov x1, x3;
    /* 0x107ef0 */ b #0x1f65e0;
    /* 0x107ef4 */ adrp x8, #0x201000;
    /* 0x107ef8 */ ldr x8, [x8, #0x868];
    /* 0x107efc */ ldr w8, [x8];
    /* 0x107f00 */ cmp w8, #5;
    /* 0x107f04 */ b.gt #0x107f40;
}
