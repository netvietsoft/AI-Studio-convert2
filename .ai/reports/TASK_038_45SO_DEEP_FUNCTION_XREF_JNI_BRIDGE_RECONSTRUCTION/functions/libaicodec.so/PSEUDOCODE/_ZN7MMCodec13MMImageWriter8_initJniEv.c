// Function: MMCodec::MMImageWriter::_initJni()
// RVA: 0x109fb4, Size: 5492 bytes
int64_t _ZN7MMCodec13MMImageWriter8_initJniEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN9JniHelper6getEnvEv(...); // call imported API via PLT at 0x109fc4
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x109fd8
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x109ff4
    const char* s_82ebe = "<init>"; // string xref
    const char* s_80d16 = "(Landroid/view/Surface;II)V"; // string xref
    (*x8)(...); // indirect call at 0x10a030
    const char* s_7a5bb = "newInstance"; // string xref
    const char* s_7efea = "(Landroid/view/Surface;I)Landroid/media/ImageWriter;"; // string xref
    (*x8)(...); // indirect call at 0x10a06c
    const char* s_8888e = "dequeueInputImage"; // string xref
    const char* s_7ef9e = "()Landroid/media/Image;"; // string xref
    (*x8)(...); // indirect call at 0x10a0a8
    const char* s_74eed = "queueInputImage"; // string xref
    const char* s_8fd0d = "(Landroid/media/Image;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a0e4
    const char* s_8a24e = "setOnImageReleasedListener"; // string xref
    const char* s_84437 = "(Landroid/media/ImageWriter$OnImageReleasedListener;Landroid/os/Handler;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a120
    const char* s_75e12 = "close"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a15c
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a180
    const char* s_82ebe = "<init>"; // string xref
    const char* s_84394 = "(I)V"; // string xref
    (*x8)(...); // indirect call at 0x10a1bc
    const char* s_7638c = "setDefaultBufferSize"; // string xref
    const char* s_8b356 = "(II)V"; // string xref
    (*x8)(...); // indirect call at 0x10a1f8
    const char* s_72bb5 = "setOnFrameAvailableListener"; // string xref
    const char* s_8203b = "(Landroid/graphics/SurfaceTexture$OnFrameAvailableListener;Landroid/os/Handler;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a234
    const char* s_8fd76 = "updateTexImage"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a270
    const char* s_74f27 = "getTransformMatrix"; // string xref
    const char* s_69b2c = "([F)V"; // string xref
    (*x8)(...); // indirect call at 0x10a2ac
    const char* s_8330e = "release"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a2e8
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a30c
    const char* s_82ebe = "<init>"; // string xref
    const char* s_7cbe5 = "(Landroid/graphics/SurfaceTexture;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a348
    const char* s_8330e = "release"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a384
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a3a8
    const char* s_871f1 = "getPlanes"; // string xref
    const char* s_7de57 = "()[Landroid/media/Image$Plane;"; // string xref
    (*x8)(...); // indirect call at 0x10a3e0
    const char* s_75e12 = "close"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a418
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a43c
    const char* s_843ec = "getRowStride"; // string xref
    const char* s_8596b = "()I"; // string xref
    (*x8)(...); // indirect call at 0x10a474
    const char* s_91096 = "getPixelStride"; // string xref
    const char* s_8596b = "()I"; // string xref
    (*x8)(...); // indirect call at 0x10a4ac
    const char* s_72b45 = "getBuffer"; // string xref
    const char* s_8a1ef = "()Ljava/nio/ByteBuffer;"; // string xref
    (*x8)(...); // indirect call at 0x10a4e4
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a508
    const char* s_82ebe = "<init>"; // string xref
    const char* s_8a238 = "(Ljava/lang/String;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a540
    const char* s_67200 = "start"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a578
    const char* s_6783f = "getLooper"; // string xref
    const char* s_6ad14 = "()Landroid/os/Looper;"; // string xref
    (*x8)(...); // indirect call at 0x10a5b0
    const char* s_8e8b1 = "quit"; // string xref
    const char* s_7a5da = "()Z"; // string xref
    (*x8)(...); // indirect call at 0x10a5e8
    const char* s_7efe5 = "join"; // string xref
    const char* s_6bad5 = "()V"; // string xref
    (*x8)(...); // indirect call at 0x10a620
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a644
    const char* s_82ebe = "<init>"; // string xref
    const char* s_6d46d = "(Landroid/os/Looper;)V"; // string xref
    (*x8)(...); // indirect call at 0x10a67c
    void* g_20a6c0 = (void*)0x20a6c0; // global ref
    _ZN7MMCodec10JniUtility12getJavaClassEPKc(...); // call imported API via PLT at 0x10a6ac
    const char* s_82ebe = "<init>"; // string xref
    const char* s_80c70 = "(J)V"; // string xref
    (*x8)(...); // indirect call at 0x10a6e4
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8fcf4 = "[%s(%d)]:> getEnv failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a734
    const char* s_6d484 = "%s/MTMV_AICodec: [%s(%d)]:> getEnv failed
"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10a770
    return a0;
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6f83f = "[%s(%d)]:> find java ImageWriter class failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a7c8
    const char* s_81fba = "%s/MTMV_AICodec: [%s(%d)]:> find java ImageWriter class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_88866 = "[%s(%d)]:> find ImageWriter init failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a82c
    const char* s_7a5de = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter init failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e8b6 = "[%s(%d)]:> find ImageWriter newInstance failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a890
    const char* s_81ffa = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter newInstance failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72b4f = "[%s(%d)]:> find ImageWriter dequeueInputImage failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a8f4
    const char* s_68899 = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter dequeueInputImage failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_832db = "[%s(%d)]:> find ImageWriter queueInputImage failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a958
    const char* s_6f86d = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter queueInputImage failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85cf9 = "[%s(%d)]:> find ImageWriter setOnImageReleasedListener failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10a9bc
    const char* s_8fd26 = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter setOnImageReleasedListener failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85d37 = "[%s(%d)]:> find ImageWriter close failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10aa20
    const char* s_871fb = "%s/MTMV_AICodec: [%s(%d)]:> find ImageWriter close failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72b84 = "[%s(%d)]:> find java SurfaceTexture class failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10aa84
    const char* s_8a269 = "%s/MTMV_AICodec: [%s(%d)]:> find java SurfaceTexture class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_74efd = "[%s(%d)]:> find SurfaceTexture new failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10aae8
    const char* s_7cb67 = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture new failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6d4af = "[%s(%d)]:> find SurfaceTexture setDefaultBufferSize failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ab4c
    const char* s_69adf = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture setDefaultBufferSize failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7cba3 = "[%s(%d)]:> find SurfaceTexture SetOnFrameAvailableListener failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10abb0
    const char* s_84482 = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture SetOnFrameAvailableListener failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7b97f = "[%s(%d)]:> find SurfaceTexture updateTexImage failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ac14
    const char* s_763a1 = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture updateTexImage failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_85d60 = "[%s(%d)]:> find SurfaceTexture getTransformMatrix failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ac78
    const char* s_74f3a = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture getTransformMatrix failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_888a0 = "[%s(%d)]:> find SurfaceTexture release failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10acdc
    const char* s_77e31 = "%s/MTMV_AICodec: [%s(%d)]:> find SurfaceTexture release failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72bd1 = "[%s(%d)]:> find java Surface class failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ad40
    const char* s_8fd85 = "%s/MTMV_AICodec: [%s(%d)]:> find java Surface class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_67849 = "[%s(%d)]:> find Surface new failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ada4
    const char* s_844d6 = "%s/MTMV_AICodec: [%s(%d)]:> find Surface new failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_87236 = "[%s(%d)]:> find Surface release failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ae08
    const char* s_69b32 = "%s/MTMV_AICodec: [%s(%d)]:> find Surface release failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_72b1d = "[%s(%d)]:> find java Image class failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10ae6c
    const char* s_74eb3 = "%s/MTMV_AICodec: [%s(%d)]:> find java Image class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77dc9 = "[%s(%d)]:> get java Image's func "getPlanes" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10aed0
    const char* s_8cea8 = "%s/MTMV_AICodec: [%s(%d)]:> get java Image's func "getPlanes" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_717ed = "[%s(%d)]:> get java Image's func "close" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10af34
    const char* s_91054 = "%s/MTMV_AICodec: [%s(%d)]:> get java Image's func "close" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_77dfd = "[%s(%d)]:> find java Plane class failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10af98
    const char* s_7cb2d = "%s/MTMV_AICodec: [%s(%d)]:> find java Plane class failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7de76 = "[%s(%d)]:> get java Plane's func "getRowStride" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10affc
    const char* s_8e85d = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getRowStride" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_83257 = "[%s(%d)]:> get java Plane's func "getPixelStride" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b060
    const char* s_83290 = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getPixelStride" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_6bfec = "[%s(%d)]:> get java Plane's func "getBuffer" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b0c4
    const char* s_6acc2 = "%s/MTMV_AICodec: [%s(%d)]:> get java Plane's func "getBuffer" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_910c1 = "[%s(%d)]:> FindClass "HandlerThread" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b128
    const char* s_6786c = "%s/MTMV_AICodec: [%s(%d)]:> FindClass "HandlerThread" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8725d = "[%s(%d)]:> get java HandlerThread's func "init" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b18c
    const char* s_87294 = "%s/MTMV_AICodec: [%s(%d)]:> get java HandlerThread's func "init" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_763e8 = "[%s(%d)]:> get java HandlerThread's func "start" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b1f0
    const char* s_8208d = "%s/MTMV_AICodec: [%s(%d)]:> get java HandlerThread's func "start" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7cc0a = "[%s(%d)]:> get java HandlerThread's func "getLooper" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b254
    const char* s_8e8e5 = "%s/MTMV_AICodec: [%s(%d)]:> get java HandlerThread's func "getLooper" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_678aa = "[%s(%d)]:> get java HandlerThread's func "quit" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b2b8
    const char* s_6ad2a = "%s/MTMV_AICodec: [%s(%d)]:> get java HandlerThread's func "quit" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8fdc1 = "[%s(%d)]:> get java HandlerThread's func "join" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b31c
    const char* s_6e623 = "%s/MTMV_AICodec: [%s(%d)]:> get java HandlerThread's func "join" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_7a618 = "[%s(%d)]:> FindClass "Handler" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b380
    const char* s_69b6b = "%s/MTMV_AICodec: [%s(%d)]:> FindClass "Handler" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_8e933 = "[%s(%d)]:> get java Handler's func "init" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b3e4
    const char* s_83316 = "%s/MTMV_AICodec: [%s(%d)]:> get java Handler's func "init" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_80d32 = "[%s(%d)]:> FindClass "SurfaceTextureCallback" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b448
    const char* s_8b35c = "%s/MTMV_AICodec: [%s(%d)]:> FindClass "SurfaceTextureCallback" failed
"; // string xref
    const char* s_7d752 = "MTMV_AICodec";
    const char* s_678e1 = "[%s(%d)]:> get java SurfaceTextureCallback's func "init" failed"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x10b4ac
    const char* s_8e964 = "%s/MTMV_AICodec: [%s(%d)]:> get java SurfaceTextureCallback's func "init" failed
"; // string xref
    const char* s_6c020 = "_initJni"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x10b4e8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x10b4f8
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x10b51c
}
