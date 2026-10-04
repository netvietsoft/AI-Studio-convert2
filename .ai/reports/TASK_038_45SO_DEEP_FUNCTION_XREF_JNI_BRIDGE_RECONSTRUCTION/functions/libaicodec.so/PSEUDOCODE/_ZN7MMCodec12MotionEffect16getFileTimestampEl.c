// Function: MMCodec::MotionEffect::getFileTimestamp(long)
// RVA: 0x120038, Size: 308 bytes
int64_t _ZN7MMCodec12MotionEffect16getFileTimestampEl(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x120058
    (*x8)(...); // indirect call at 0x120070
    return a0;
    pthread_self(...); // call imported API via PLT at 0x1200dc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d717 = "[%s(%d)]:> [MotionEffect(%p)](%ld):> _changeFileTimestamp failed"; // string xref
    const char* s_6e7f5 = "getFileTimestamp"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x120108
    pthread_self(...); // call imported API via PLT at 0x12012c
    const char* s_8d0a0 = "%s/MTMV_AICodec: [%s(%d)]:> [MotionEffect(%p)](%ld):> _changeFileTimestamp failed
"; // string xref
    const char* s_6e7f5 = "getFileTimestamp"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x120154
    return a0;
}
