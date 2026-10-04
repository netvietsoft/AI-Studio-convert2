// Function: MMCodec::AndroidEncoder::_initKeyValue()
// RVA: 0xed5b8, Size: 2028 bytes
int64_t _ZN7MMCodec14AndroidEncoder13_initKeyValueEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0xed5ec
    const char* s_7dc2a = "isSupportMime"; // string xref
    const char* s_7b579 = "(Ljava/lang/String;Z)Z"; // string xref
    (*x8)(...); // indirect call at 0xed6b4
    const char* s_8e4ac = "getCodecNameLowerCase"; // string xref
    const char* s_8f8b0 = "(Ljava/lang/String;Z)Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0xed6e4
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xed704
    const char* s_82ebe = "<init>"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0xed72c
    const char* s_840a6 = "configure"; // string xref
    const char* s_88425 = "(Landroid/media/MediaFormat;)I"; // string xref
    (*x8)(...); // indirect call at 0xed75c
    const char* s_8596b = "()I"; // string xref
    const char* s_67493 = "codecOpen"; // string xref
    (*x8)(...); // indirect call at 0xed790
    const char* s_8f8d8 = "codecClose"; // string xref
    (*x8)(...); // indirect call at 0xed7bc
    const char* s_7c849 = "dequeueOutputBuffer"; // string xref
    (*x8)(...); // indirect call at 0xed7e8
    const char* s_88444 = "releaseOutputBuffer"; // string xref
    (*x8)(...); // indirect call at 0xed814
    const char* s_6a9cd = "mOutputBuffer"; // string xref
    const char* s_7269c = "Ljava/nio/ByteBuffer;"; // string xref
    (*x8)(...); // indirect call at 0xed844
    void* g_8cb53 = (void*)0x8cb53; // global ref
    const char* s_89f35 = "mOutputBufferPos"; // string xref
    (*x8)(...); // indirect call at 0xed878
    const char* s_7c85d = "mOutputBufferSize"; // string xref
    (*x8)(...); // indirect call at 0xed8a4
    const char* s_712bb = "mOutputBufferPts"; // string xref
    void* g_88458 = (void*)0x88458; // global ref
    (*x8)(...); // indirect call at 0xed8d4
    const char* s_75eb2 = "mCSD0BufferSize"; // string xref
    (*x8)(...); // indirect call at 0xed900
    const char* s_82ec5 = "mCSD1BufferSize"; // string xref
    (*x8)(...); // indirect call at 0xed92c
    const char* s_840b0 = "mBufFlags"; // string xref
    (*x8)(...); // indirect call at 0xed958
    const char* s_8845a = "mCodecName"; // string xref
    const char* s_6749d = "Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0xed988
    const char* s_81b6b = "mOutputMediaFormatWidth"; // string xref
    (*x8)(...); // indirect call at 0xed9b4
    const char* s_7c86f = "mOutputMediaFormatHeight"; // string xref
    (*x8)(...); // indirect call at 0xed9e0
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6a972 = "[%s(%d)]:> %s:: getEnv error!"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xeda54
    const char* s_8af8f = "_initKeyValue"; // string xref
    const char* s_8593b = "%s/MTMV_AICodec: [%s(%d)]:> %s:: getEnv error!
"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xeda94
    return a0;
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xedab8
    const char* s_82ebe = "<init>"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0xedaf0
    const char* s_8cb49 = "setString"; // string xref
    const char* s_8af9d = "(Ljava/lang/String;Ljava/lang/String;)V"; // string xref
    (*x8)(...); // indirect call at 0xedb28
    const char* s_90be1 = "setInteger"; // string xref
    const char* s_77afb = "(Ljava/lang/String;I)V"; // string xref
    (*x8)(...); // indirect call at 0xedb60
    const char* s_8841d = "setLong"; // string xref
    const char* s_78dd3 = "(Ljava/lang/String;J)V"; // string xref
    (*x8)(...); // indirect call at 0xedb98
    const char* s_90bec = "setByteBuffer"; // string xref
    const char* s_8afc5 = "(Ljava/lang/String;Ljava/nio/ByteBuffer;)V"; // string xref
    (*x8)(...); // indirect call at 0xedbd0
    const char* s_712b1 = "getString"; // string xref
    const char* s_6a990 = "(Ljava/lang/String;)Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0xedc08
    const char* s_80875 = "getInteger"; // string xref
    const char* s_6a9b7 = "(Ljava/lang/String;)I"; // string xref
    (*x8)(...); // indirect call at 0xedc40
    const char* s_80880 = "toString"; // string xref
    const char* s_69932 = "()Ljava/lang/String;"; // string xref
    (*x8)(...); // indirect call at 0xedc78
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xedc9c
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0xedcb8
    const char* s_80889 = "contains"; // string xref
    const char* s_86f43 = "(Ljava/lang/CharSequence;)Z"; // string xref
    (*x8)(...); // indirect call at 0xedcf0
    return a0;
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_74abc = "[%s(%d)]:> find String contains failed"; // string xref
    const char* s_8af8f = "_initKeyValue"; // string xref
    __android_log_print(...); // call imported API via PLT at 0xedd50
    const char* s_6bad9 = "%s/MTMV_AICodec: [%s(%d)]:> find String contains failed
"; // string xref
    const char* s_8af8f = "_initKeyValue"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0xedd8c
    return a0;
}
