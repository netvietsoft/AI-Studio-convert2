// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x47b184
// Recovered Name: sub_47b184
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x47b184 | Size: 1372 bytes | SHA256: ef36490f57f90deeeb84a3c1e82f7205f7bcc377b00331709c2c37c2993b9fc2
// Callers: 0 | Callees: 7 | Imports: 4

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm, __stack_chk_fail
// Strings referenced:
//   "EXIF parse failed (non-jpeg or no exif segment)"
//   "ZN11LayerFlowNS20CVisionDetectService6detectENSt6__ndk110shared_ptrIN12MTImageKitNS5ImageEEERKNS1_12basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERKNS_19VisionDetectOptionsEE3$_3"
//   "no exif source (neither path nor buffer)"

void sub_47b184(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 343 instructions
    /* 0x47b184 */ stp x29, x30, [sp, #0x30];
    /* 0x47b188 */ stp x24, x23, [sp, #0x40];
    /* 0x47b18c */ stp x22, x21, [sp, #0x50];
    /* 0x47b190 */ stp x20, x19, [sp, #0x60];
    /* 0x47b194 */ add x29, sp, #0x30;
    /* 0x47b198 */ mrs x23, tpidr_el0;
    /* 0x47b19c */ mov x19, x0;
    /* 0x47b1a0 */ ldr x8, [x23, #0x28];
    /* 0x47b1a4 */ stur x8, [x29, #-8];
    /* 0x47b1a8 */ ldp x22, x24, [x0, #8];
    /* 0x47b1ac */ ldrb w8, [x22];
    _Znwm();
    _ZN11LayerFlowNS11CExifReader14readFromBufferEPKhmRNS_10ExifResultERNS_19PhotoLocationResultE();
    _ZN11LayerFlowNS11CExifReader12readFromFileERKNSt6__ndk112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEERNS_10ExifResultERNS_19PhotoLocationResultE();
    sub_5263b0();
    sub_5263e0();
    _Znwm();
    _Znwm();
    sub_2bc34c();
    _ZdlPv();
    _Znwm();
    _Znwm();
    sub_2bc34c();
    _ZdlPv();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _Znwm();
    sub_2bc34c();
    _ZdlPv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    _ZdlPv();
    _ZdlPv();
    sub_47b6e0();
    sub_526544();
    __stack_chk_fail();
    return x0;
    return x0;
}
