// Library: libMtlabSign.so
// Function ID: libMtlabSign::0x21d4
// Recovered Name: Java_com_meitu_mtlab_hmacsha_HmacSHA1Sign_getSign
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x21d4 | Size: 792 bytes | SHA256: 8a6397398efe733d3c01419035942c24d3f2961b44dfd94a15d370acc61ba240
// Callers: 0 | Callees: 0 | Imports: 14

// Calls external APIs: _Z10getSignKeyP7_JNIEnvP8_jstringS2_S2_, _Z11jstring2strP7_JNIEnvP8_jstring, _ZN10CHMAC_SHA19HMAC_SHA1EPhiS0_iS0_, _ZN5CSHA1C2Ev, _ZN5CSHA1D2Ev, _ZN7ZBase646EncodeEPKhi, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc, _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm, _ZdaPv, _ZdlPv, _Znam, __stack_chk_fail, memcpy, strlen

jlong Java_com_meitu_mtlab_hmacsha_HmacSHA1Sign_getSign(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 198 instructions
    /* 0x21d4 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x21d8 */ stp x28, x27, [sp, #0x10];
    /* 0x21dc */ stp x26, x25, [sp, #0x20];
    /* 0x21e0 */ stp x24, x23, [sp, #0x30];
    /* 0x21e4 */ stp x22, x21, [sp, #0x40];
    /* 0x21e8 */ stp x20, x19, [sp, #0x50];
    /* 0x21ec */ mov x29, sp;
    /* 0x21f0 */ sub sp, sp, #0x210;
    /* 0x21f4 */ mrs x25, tpidr_el0;
    /* 0x21f8 */ mov x19, sp;
    /* 0x21fc */ mov x1, x3;
    _Z10getSignKeyP7_JNIEnvP8_jstringS2_S2_();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _Z11jstring2strP7_JNIEnvP8_jstring();
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKcm();
    _ZN5CSHA1C2Ev();
    _Znam();
    _Znam();
    _Znam();
    _Znam();
    strlen();
    strlen();
    _ZN10CHMAC_SHA19HMAC_SHA1EPhiS0_iS0_();
    memcpy();
    memcpy();
    _ZN7ZBase646EncodeEPKhi();
    _ZdlPv();
    _ZdaPv();
    _ZdaPv();
    _ZdaPv();
    _ZdaPv();
    _ZN5CSHA1D2Ev();
    return x0;
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    __stack_chk_fail();
}
