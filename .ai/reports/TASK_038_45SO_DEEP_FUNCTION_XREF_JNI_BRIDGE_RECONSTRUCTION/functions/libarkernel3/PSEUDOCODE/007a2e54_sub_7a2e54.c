// Library: libarkernel3.so
// Function ID: libarkernel3::0x7a2e54
// Recovered Name: sub_7a2e54
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x7a2e54 | Size: 156 bytes | SHA256: 4a4335495ceb70dfd1ccddd88e5b6d5b7dd801a6f5d997a697f172a893b49458
// Callers: 0 | Callees: 3 | Imports: 1

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc
// Strings referenced:
//   "kFaceliftControl_VideoFluffyHair"

void sub_7a2e54(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x7a2e54 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x7a2e58 */ str x19, [sp, #0x10];
    /* 0x7a2e5c */ mov x29, sp;
    /* 0x7a2e60 */ mov x19, x0;
    /* 0x7a2e64 */ add x0, x0, #0x4a8;
    /* 0x7a2e68 */ mov w1, #1;
    sub_7a2ef0();
    /* 0x7a2e70 */ ldr x0, [x19, #0x4a8];
    /* 0x7a2e74 */ adrp x1, #0x1da000;
    /* 0x7a2e78 */ add x1, x1, #0xeab;
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_5a704c();
    sub_5a704c();
    sub_705d4c();
    return x0;
}
