// Function: MMCodec::AndroidPixelEncoder::_initKeyValue()
// RVA: 0xf5cb4, Size: 652 bytes
int64_t _ZN7MMCodec19AndroidPixelEncoder13_initKeyValueEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _ZN7MMCodec14AndroidEncoder13_initKeyValueEv(...); // call imported API via PLT at 0xf5ce8
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xf5cf0
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xf5d08
    const char* s_82ebe = "<init>"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0xf5d30
    const char* s_8596b = "()I"; // string xref
    const char* s_7a362 = "dequeueInputBuffer"; // string xref
    (*x8)(...); // indirect call at 0xf5d64
    const char* s_75f24 = "queueInputBuffer"; // string xref
    (*x8)(...); // indirect call at 0xf5d90
    const char* s_69a32 = "mInputBuffer"; // string xref
    const char* s_7269c = "Ljava/nio/ByteBuffer;"; // string xref
    (*x8)(...); // indirect call at 0xf5dc0
    void* g_8cb53 = (void*)0x8cb53; // global ref
    const char* s_8cc5f = "mInputBufferOffset"; // string xref
    (*x8)(...); // indirect call at 0xf5df4
    const char* s_6bbea = "mInputBufferSize"; // string xref
    (*x8)(...); // indirect call at 0xf5e20
    const char* s_859cb = "mInputBufferTimeUs"; // string xref
    void* g_88458 = (void*)0x88458; // global ref
    (*x8)(...); // indirect call at 0xf5e50
    const char* s_884f7 = "mInputBufferFlags"; // string xref
    (*x8)(...); // indirect call at 0xf5e7c
    return a0;
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6a972 = "[%s(%d)]:> %s:: getEnv error!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xf5ee8
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_8593b = "%s/MTMV_AICodec: [%s(%d)]:> %s:: getEnv error!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xf5f28
    return a0;
}
