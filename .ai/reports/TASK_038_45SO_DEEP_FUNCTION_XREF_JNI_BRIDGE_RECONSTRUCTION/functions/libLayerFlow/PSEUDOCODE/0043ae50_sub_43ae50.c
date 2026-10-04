// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x43ae50
// Recovered Name: sub_43ae50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x43ae50 | Size: 1396 bytes | SHA256: ce45c5bdf3b3319e3eceec0aa7567fb17e0608fbb7d95c438aaa5ad44dd02663
// Callers: 0 | Callees: 10 | Imports: 7

// Calls external APIs: _ZN12MTImageKitNS11CMTIKFilter17getLayersDurationEv, _ZN12MTImageKitNS12CMTIKManager9getFilterEl, _ZN12MTImageKitNS19CMTIKWakeSkinFilter23getBodyEffectCacheImageEbb, _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __dynamic_cast, __stack_chk_fail
// Strings referenced:
//   "cWakeSkinProcessor<%s:%d> CLFWakeSkinProcessor::onProcessLayer, bodyDodge: %p, hairRemove: %p, bothEffect: %p"
//   "cWakeSkinProcessor<%s:%d> CLFWakeSkinProcessor::onProcessLayer, faceResultCount: %d"
//   "cWakeSkinProcessor<%s:%d> CLFWakeSkinProcessor::onProcessLayer, filter-uuid: %ld"
//   "cWakeSkinProcessor<%s:%d> CLFWakeSkinProcessor::onProcessLayer, result.hasDoEffect %b, duration: %.2f"
//   "collectResult"

void sub_43ae50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 349 instructions
    /* 0x43ae50 */ stp x29, x30, [sp, #0xc0];
    /* 0x43ae54 */ str x23, [sp, #0xd0];
    /* 0x43ae58 */ stp x22, x21, [sp, #0xe0];
    /* 0x43ae5c */ stp x20, x19, [sp, #0xf0];
    /* 0x43ae60 */ add x29, sp, #0xc0;
    /* 0x43ae64 */ mrs x23, tpidr_el0;
    /* 0x43ae68 */ mov x19, x0;
    /* 0x43ae6c */ ldr x8, [x23, #0x28];
    /* 0x43ae70 */ stur x8, [x29, #-8];
    /* 0x43ae74 */ ldr x0, [x0, #0x40];
    /* 0x43ae78 */ cbz x0, #0x43b308;
    __dynamic_cast();
    sub_5263b0();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS12CMTIKManager9getFilterEl();
    __dynamic_cast();
    _ZN12MTImageKitNS11CMTIKFilter17getLayersDurationEv();
    _ZN12MTImageKitNS19CMTIKWakeSkinFilter23getBodyEffectCacheImageEbb();
    _ZN12MTImageKitNS19CMTIKWakeSkinFilter23getBodyEffectCacheImageEbb();
    _ZN12MTImageKitNS19CMTIKWakeSkinFilter23getBodyEffectCacheImageEbb();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263b0();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    _ZNSt6__ndk116__variant_detail12__assignmentINS0_8__traitsIJ16LFWakeSkinResult18LFSkinWhitenResult16LFFaceFullResult18LFFaceRemoldResult14LFMakeUpResult22LFOneClickBeautyResultEEEE12__assign_altB8ne180000ILm0ES3_RS3_EEvRNS0_5__altIXT_ET0_EEOT1_();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    _ZN16LFWakeSkinResultD2Ev();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    sub_5263e0();
    _ZNSt6__ndk119__shared_weak_count14__release_weakEv();
    return x0;
    sub_2bf8c4();
    _ZN16LFWakeSkinResultD2Ev();
    sub_2d29e8();
    sub_2bbdb4();
    sub_2bbdb4();
    sub_2bbdb4();
    sub_33b634();
    sub_43adfc();
    sub_526544();
    __stack_chk_fail();
}
