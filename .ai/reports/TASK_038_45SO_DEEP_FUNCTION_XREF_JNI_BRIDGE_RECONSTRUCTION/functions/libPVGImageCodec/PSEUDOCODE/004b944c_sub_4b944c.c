// Library: libPVGImageCodec.so
// Function ID: libPVGImageCodec::0x4b944c
// Recovered Name: sub_4b944c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x4b944c | Size: 660 bytes | SHA256: 1c586d3b4e1d1a77f134b75bff43f3d857dd78695c1e23dc722aa40b05b4b7fe
// Callers: 3 | Callees: 6 | Imports: 7

// Calls external APIs: _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv, _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm, _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev, _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev, _ZdlPv, __stack_chk_fail
// Strings referenced:
//   " range:["
//   ") segment_range:["
//   "Invalid location:"

void sub_4b944c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 165 instructions
    /* 0x4b944c */ sub sp, sp, #0x1b0;
    /* 0x4b9450 */ str x29, [sp, #0x170];
    /* 0x4b9454 */ stp x30, x23, [sp, #0x180];
    /* 0x4b9458 */ stp x22, x21, [sp, #0x190];
    /* 0x4b945c */ stp x20, x19, [sp, #0x1a0];
    /* 0x4b9460 */ mrs x21, tpidr_el0;
    /* 0x4b9464 */ mov x20, x8;
    /* 0x4b9468 */ mov x19, x0;
    /* 0x4b946c */ ldr x8, [x21, #0x28];
    /* 0x4b9470 */ add x0, sp, #0x50;
    /* 0x4b9474 */ add x22, sp, #0x50;
    sub_4aa430();
    sub_1a363c();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm();
    sub_1a363c();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm();
    sub_1a363c();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm();
    sub_1a363c();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm();
    sub_1a363c();
    _ZNSt6__ndk113basic_ostreamIcNS_11char_traitsIcEEElsEm();
    sub_1a363c();
    _ZNKSt6__ndk115basic_stringbufIcNS_11char_traitsIcEENS_9allocatorIcEEE3strEv();
    sub_4b97c0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk115basic_streambufIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk114basic_iostreamIcNS_11char_traitsIcEEED2Ev();
    _ZNSt6__ndk19basic_iosIcNS_11char_traitsIcEEED2Ev();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_4b77e0();
    sub_4aa558();
    sub_4bebfc();
    _ZdlPv();
    _ZdlPv();
    sub_4aa558();
    sub_4aa558();
    __stack_chk_fail();
}
