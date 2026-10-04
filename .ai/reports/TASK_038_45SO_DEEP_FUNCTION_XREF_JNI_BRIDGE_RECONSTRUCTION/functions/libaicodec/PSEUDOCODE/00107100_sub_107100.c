// Library: libaicodec.so
// Function ID: libaicodec::0x107100
// Recovered Name: sub_107100
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x107100 | Size: 32 bytes | SHA256: 6cea0baa0b734b42eb7b4250beb9d8d0d973c8bd680236b4974cb14bc82f9221
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: native_resume(J)V (table at 0x1fec30)
// Calls external APIs: _ZN7MMCodec13MTMediaReader6resumeEv

jlong sub_107100(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x107100 */ cbz x2, #0x10710c;
    /* 0x107104 */ mov x0, x2;
    /* 0x107108 */ b #0x1f6590;
    /* 0x10710c */ adrp x8, #0x201000;
    /* 0x107110 */ ldr x8, [x8, #0x868];
    /* 0x107114 */ ldr w8, [x8];
    /* 0x107118 */ cmp w8, #5;
    /* 0x10711c */ b.gt #0x107158;
}
