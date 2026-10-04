// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x46d094
// Recovered Name: sub_46d094
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x46d094 | Size: 3288 bytes | SHA256: a76db663f2f6864643fc502a82dabf48ca98cf29d35c12b6443c0c6bb4d5c00b
// Callers: 0 | Callees: 9 | Imports: 3

// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, _ZdlPv, _Znwm
// Strings referenced:
//   "MTAi_BodyInOneBox"
//   "MTAi_BodyInOneBreast_Image"
//   "MTAi_BodyInOneContour"
//   "MTAi_BodyInOneNeck_Image"
//   "MTAi_BodyInOnePose"

void sub_46d094(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 822 instructions
    /* 0x46d094 */ str x20, [sp, #0x560];
    _ZdlPv();
    /* 0x46d09c */ ldr x22, [sp, #0xa68];
    /* 0x46d0a0 */ cbz x22, #0x46d104;
    /* 0x46d0a4 */ ldr x20, [sp, #0xa70];
    /* 0x46d0a8 */ mov x0, x22;
    /* 0x46d0ac */ cmp x20, x22;
    /* 0x46d0b0 */ b.ne #0x46d0c4;
    /* 0x46d0b4 */ b #0x46d0fc;
    /* 0x46d0b8 */ sub x20, x20, #0x10;
    /* 0x46d0bc */ cmp x20, x22;
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZdlPv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_2fa2e8();
    sub_46b134();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    sub_46b134();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    _ZdlPv();
    _Znwm();
    sub_46b134();
    sub_303354();
    sub_2bea64();
    sub_31c6e8();
    _ZdlPv();
    _ZN19LFAutoBeautyModularD2Ev();
    sub_3a51e0();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZN15LFFilterModularD2Ev();
    _ZdlPv();
}
