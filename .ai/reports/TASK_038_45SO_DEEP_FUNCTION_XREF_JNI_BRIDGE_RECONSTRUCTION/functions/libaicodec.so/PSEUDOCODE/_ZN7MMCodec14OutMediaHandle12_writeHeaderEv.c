// Function: MMCodec::OutMediaHandle::_writeHeader()
// RVA: 0xeac28, Size: 768 bytes
int64_t _ZN7MMCodec14OutMediaHandle12_writeHeaderEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_7a284 = "movflags"; // string xref
    const char* s_7a28d = "faststart"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xeac78
    const char* s_7a284 = "movflags"; // string xref
    const char* s_8aeab = "use_metadata_tags"; // string xref
    av_dict_set(...); // call imported API via PLT at 0xeac94
    avformat_write_header(...); // call imported API via PLT at 0xeaca0
    _ZN7MMCodec12makeErrorStrEi(...); // call imported API via PLT at 0xeacb0
    strlen(...); // call imported API via PLT at 0xeacb8
    _Znwm(...); // call imported API via PLT at 0xeacf0
    memmove(...); // call imported API via PLT at 0xead10
    const char* s_67436 = "write file header error:"; // string xref
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6insertEmPKc(...); // call imported API via PLT at 0xead28
    _ZdlPv(...); // call imported API via PLT at 0xead50
    pthread_self(...); // call imported API via PLT at 0xead74
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7261b = "[%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s"; // string xref
    const char* s_86e6c = "_writeHeader"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xeadb8
    pthread_self(...); // call imported API via PLT at 0xeaddc
    const char* s_86de7 = "%s/MTMV_AICodec: [%s(%d)]:> [OutMediaHandle(%p)](%ld):> %s
"; // string xref
    const char* s_86e6c = "_writeHeader"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xeae1c
    (*x8)(...); // indirect call at 0xeae80
    _ZdlPv(...); // call imported API via PLT at 0xeae90
    av_dict_free(...); // call imported API via PLT at 0xeae98
    return a0;
    sub_D22F8(...); // call internal func at 0xeaee0
    _ZdlPv(...); // call imported API via PLT at 0xeaf08
    __stack_chk_fail(...); // call imported API via PLT at 0xeaf24
}
