// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x62efc4
// Recovered Name: sub_62efc4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x62efc4 | Size: 3676 bytes | SHA256: 476f02cc274be7fba75d6b281459c372003dabde81ef74c4f0c584d3d54d1a35
// Callers: 0 | Callees: 26 | Imports: 6

// Calls external APIs: _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_, _ZdlPv, __android_log_print, __stack_chk_fail
// Strings referenced:
//   "AddPath"
//   "AdditionalTexture"
//   "AlignCenterList"
//   "AlignIndexList"
//   "BlendMode"

void sub_62efc4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 919 instructions
    /* 0x62efc4 */ stp x29, x30, [sp, #0x60];
    /* 0x62efc8 */ stp x28, x27, [sp, #0x70];
    /* 0x62efcc */ stp x26, x25, [sp, #0x80];
    /* 0x62efd0 */ stp x24, x23, [sp, #0x90];
    /* 0x62efd4 */ stp x22, x21, [sp, #0xa0];
    /* 0x62efd8 */ stp x20, x19, [sp, #0xb0];
    /* 0x62efdc */ add x29, sp, #0x60;
    /* 0x62efe0 */ mrs x24, tpidr_el0;
    /* 0x62efe4 */ mov x21, x1;
    /* 0x62efe8 */ mov x20, x0;
    /* 0x62efec */ ldr x8, [x24, #0x28];
    sub_61bfa0();
    sub_5a8de8();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_68c86c();
    sub_5a8f24();
    _ZdlPv();
    sub_68c87c();
    sub_5a8d0c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6assignEPKc();
    sub_570f58();
    sub_bc3bb4();
    _ZdlPv();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_a19264();
    sub_5a8de8();
    sub_a19290();
    sub_63c910();
    sub_a192a0();
    _ZdlPv();
    sub_63c910();
    sub_a192cc();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    _ZdlPv();
    sub_5a8d1c();
    sub_5a8de8();
    sub_a192f8();
    sub_5b7fa8();
    sub_5cb9b8();
    _ZdlPv();
    sub_5b7fa8();
    sub_5cb9b8();
    _ZdlPv();
    sub_5a8de8();
    sub_5b7fa8();
    sub_5a6b20();
    __android_log_print();
    _ZdlPv();
    sub_5cb124();
    sub_5cb47c();
    sub_63c850();
    _ZdlPv();
    sub_5a8da0();
    _ZdlPv();
    sub_5a8de8();
    sub_a19264();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_5a8de8();
    sub_62b658();
    sub_5a6eb4();
    sub_58f19c();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEaSERKS5_();
    return x0;
    sub_63c83c();
    __stack_chk_fail();
}
