// Function: MMCodec::MTImageReader::init(int, int, int, int)
// RVA: 0x108418, Size: 1812 bytes
int64_t _ZN7MMCodec13MTImageReader4initEiiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x108438
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x108450
    (*x8)(...); // indirect call at 0x108468
    const char* s_7a5bb = "newInstance"; // string xref
    const char* s_68877 = "(IIII)Landroid/media/ImageReader;"; // string xref
    (*x8)(...); // indirect call at 0x108490
    _ZN7_JNIEnv22CallStaticObjectMethodEP7_jclassP10_jmethodIDz(...); // call imported API via PLT at 0x1084ac
    (*x8)(...); // indirect call at 0x1084c8
    const char* s_6acb1 = "acquireNextImage"; // string xref
    const char* s_7ef9e = "()Landroid/media/Image;"; // string xref
    (*x8)(...); // indirect call at 0x1084f0
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x108508
    (*x8)(...); // indirect call at 0x108520
    const char* s_871f1 = "getPlanes"; // string xref
    const char* s_7de57 = "()[Landroid/media/Image$Plane;"; // string xref
    (*x8)(...); // indirect call at 0x108548
    const char* s_75e12 = "close"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x108574
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10858c
    (*x8)(...); // indirect call at 0x1085a4
    const char* s_843ec = "getRowStride"; // string xref
    const char* s_8596b = "()I"; // string xref
    (*x8)(...); // indirect call at 0x1085cc
    const char* s_91096 = "getPixelStride"; // string xref
    const char* s_8596b = "()I"; // string xref
    (*x8)(...); // indirect call at 0x1085f8
    const char* s_72b45 = "getBuffer"; // string xref
    const char* s_8a1ef = "()Ljava/nio/ByteBuffer;"; // string xref
    (*x8)(...); // indirect call at 0x108624
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_843be = "[%s(%d)]:> find java ImageReader class failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108678
    const char* s_6bfac = "%s/MTMV_AICodec: [%s(%d)]:> find java ImageReader class failed
"; // string xref
    const char* s_7d75f = "init"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6ac82 = "[%s(%d)]:> newInstance java ImageReader failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1086f0
    const char* s_8fc53 = "%s/MTMV_AICodec: [%s(%d)]:> newInstance java ImageReader failed
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10872c
    return a0;
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8fc94 = "[%s(%d)]:> get java ImageReader's func "acquireNextImage" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10879c
    const char* s_7b8bb = "%s/MTMV_AICodec: [%s(%d)]:> get java ImageReader's func "acquireNextImage" failed
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x1087d8
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72b1d = "[%s(%d)]:> find java Image class failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10881c
    const char* s_74eb3 = "%s/MTMV_AICodec: [%s(%d)]:> find java Image class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77dc9 = "[%s(%d)]:> get java Image's func "getPlanes" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108880
    const char* s_8cea8 = "%s/MTMV_AICodec: [%s(%d)]:> get java Image's func "getPlanes" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_717ed = "[%s(%d)]:> get java Image's func "close" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1088e4
    const char* s_91054 = "%s/MTMV_AICodec: [%s(%d)]:> get java Image's func "close" failed
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x108920
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77dfd = "[%s(%d)]:> find java Plane class failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108964
    const char* s_7cb2d = "%s/MTMV_AICodec: [%s(%d)]:> find java Plane class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7de76 = "[%s(%d)]:> get java Plane's func "getRowStride" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x1089c8
    const char* s_8e85d = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getRowStride" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83257 = "[%s(%d)]:> get java Plane's func "getPixelStride" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108a2c
    const char* s_83290 = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getPixelStride" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6bfec = "[%s(%d)]:> get java Plane's func "getBuffer" failed"; // string xref
    const char* s_7d75f = "init"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x108a90
    const char* s_6acc2 = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getBuffer" failed
"; // string xref
    const char* s_7d75f = "init"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x108acc
    (*x8)(...); // indirect call at 0x108ae4
    return a0;
    sub_CEBC4(...); // call internal func at 0x108b00
    (*x8)(...); // indirect call at 0x108b1c
    sub_CEBC4(...); // call internal func at 0x108b28
}
