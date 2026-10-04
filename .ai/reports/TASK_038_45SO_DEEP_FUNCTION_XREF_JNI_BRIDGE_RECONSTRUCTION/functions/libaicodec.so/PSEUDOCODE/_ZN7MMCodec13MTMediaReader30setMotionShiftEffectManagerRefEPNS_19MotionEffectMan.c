// Function: MMCodec::MTMediaReader::setMotionShiftEffectManagerRef(MMCodec::MotionEffectManager*)
// RVA: 0x1315c0, Size: 252 bytes
int64_t _ZN7MMCodec13MTMediaReader30setMotionShiftEffectManagerRefEPNS_19MotionEffectManagerE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec6AVIRef7releaseEv(...); // call imported API via PLT at 0x1315e4
    _ZN7MMCodec6AVIRef6retainEv(...); // call imported API via PLT at 0x1315f4
    _ZN7MMCodec13InMediaHandle30setMotionShiftEffectManagerRefEPNS_19MotionEffectManagerE(...); // call imported API via PLT at 0x131604
    pthread_self(...); // call imported API via PLT at 0x131628
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d7f5 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> hold motion shift manager %p"; // string xref
    const char* s_8247f = "setMotionShiftEffectManagerRef"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x131658
    pthread_self(...); // call imported API via PLT at 0x13167c
    const char* s_76781 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> hold motion shift manager %p
"; // string xref
    const char* s_8247f = "setMotionShiftEffectManagerRef"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1316a8
    return a0;
}
