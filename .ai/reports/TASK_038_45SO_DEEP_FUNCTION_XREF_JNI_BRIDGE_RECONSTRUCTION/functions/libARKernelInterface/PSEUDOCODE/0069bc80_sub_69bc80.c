// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x69bc80
// Recovered Name: sub_69bc80
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x69bc80 | Size: 236 bytes | SHA256: c20c6ff05b28f2cec330eba09bed557cdbd4a43b89ddd35c13b56d0120b56561
// Callers: 0 | Callees: 2 | Imports: 3

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "MEITU_USE_FACE_SEGMENT_MASK_TEXTURE"

void sub_69bc80(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 59 instructions
    /* 0x69bc80 */ stp x29, x30, [sp, #0x40];
    /* 0x69bc84 */ str x21, [sp, #0x50];
    /* 0x69bc88 */ stp x20, x19, [sp, #0x60];
    /* 0x69bc8c */ add x29, sp, #0x40;
    /* 0x69bc90 */ mrs x21, tpidr_el0;
    /* 0x69bc94 */ mov x19, x0;
    /* 0x69bc98 */ ldr x8, [x21, #0x28];
    /* 0x69bc9c */ stur x8, [x29, #-8];
    /* 0x69bca0 */ ldr x8, [x0];
    /* 0x69bca4 */ ldr x8, [x8, #0xc8];
    /* 0x69bca8 */ blr x8;
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    sub_570f58();
    _ZdlPv();
    _ZdlPv();
    return x0;
    __stack_chk_fail();
}
