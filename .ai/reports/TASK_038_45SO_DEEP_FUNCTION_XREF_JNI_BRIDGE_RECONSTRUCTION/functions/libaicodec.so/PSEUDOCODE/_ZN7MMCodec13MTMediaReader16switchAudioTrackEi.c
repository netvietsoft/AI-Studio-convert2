// Function: MMCodec::MTMediaReader::switchAudioTrack(int)
// RVA: 0x130bd8, Size: 432 bytes
int64_t _ZN7MMCodec13MTMediaReader16switchAudioTrackEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_self(...); // call imported API via PLT at 0x130c10
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_846d9 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> has started, can't set audio parameter"; // string xref
    const char* s_8d4a3 = "switchAudioTrack"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x130c3c
    pthread_self(...); // call imported API via PLT at 0x130c60
    const char* s_78120 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> has started, can't set audio parameter
"; // string xref
    const char* s_8d4a3 = "switchAudioTrack"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x130c88
    return a0;
    return a0;
    pthread_self(...); // call imported API via PLT at 0x130cfc
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7bd56 = "[%s(%d)]:> [MTMediaReader(%p)](%ld):> no audio stream found"; // string xref
    const char* s_8d4a3 = "switchAudioTrack"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x130d28
    pthread_self(...); // call imported API via PLT at 0x130d4c
    const char* s_7a9d3 = "%s/MTMV_AICodec: [%s(%d)]:> [MTMediaReader(%p)](%ld):> no audio stream found
"; // string xref
    const char* s_8d4a3 = "switchAudioTrack"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x130d74
    return a0;
}
