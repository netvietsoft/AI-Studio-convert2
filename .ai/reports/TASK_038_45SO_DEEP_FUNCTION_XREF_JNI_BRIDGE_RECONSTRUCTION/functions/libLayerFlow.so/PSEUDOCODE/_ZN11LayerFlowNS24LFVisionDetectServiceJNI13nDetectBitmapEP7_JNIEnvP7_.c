// Function: LayerFlowNS::LFVisionDetectServiceJNI::nDetectBitmap(_JNIEnv*, _jclass*, long, _jobject*, _jbyteArray*, int)
// RVA: 0x47061c, Size: 1332 bytes
int64_t _ZN11LayerFlowNS24LFVisionDetectServiceJNI13nDetectBitmapEP7_JNIEnvP7_jclasslP8_jobjectP11_jbyteArrayi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    AndroidBitmap_getInfo(...); // call PLT API at 0x470670
    AndroidBitmap_lockPixels(...); // call PLT API at 0x4706a8
    malloc(...); // call PLT API at 0x4706c4
    memcpy(...); // call PLT API at 0x4706d8
    AndroidBitmap_unlockPixels(...); // call PLT API at 0x4706e4
    sub_470BE0(...); // call internal at 0x470738
    (*x8)(...);
    (*x8)(...);
    const char* str = "service not initialized";
    const char* str = "null bitmap";
    sub_470364(...); // call internal at 0x47079c
    const char* str = "iklf";
    const char* str = "lfVDSvcJNI<%s:%d> nDetectBitmap: AndroidBitmap_getInfo failed.";
    const char* str = "doDetectBitmap";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x4707c4
    const char* str = "AndroidBitmap_getInfo failed";
    const char* str = "iklf";
    const char* str = "lfVDSvcJNI<%s:%d> nDetectBitmap: unsupported bitmap format %d (need RGBA_8888=1).";
    const char* str = "doDetectBitmap";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x4707f4
    const char* str = "bitmap must be ARGB_8888 config";
    const char* str = "iklf";
    const char* str = "lfVDSvcJNI<%s:%d> nDetectBitmap: invalid bitmap dims w=%u h=%u stride=%u.";
    const char* str = "doDetectBitmap";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x470824
    const char* str = "invalid bitmap dimensions";
    sub_470364(...); // call internal at 0x470834
    return a0;
    const char* str = "iklf";
    const char* str = "lfVDSvcJNI<%s:%d> nDetectBitmap: AndroidBitmap_lockPixels failed.";
    const char* str = "doDetectBitmap";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x470888
    const char* str = "AndroidBitmap_lockPixels failed";
    sub_470364(...); // call internal at 0x470898
    AndroidBitmap_unlockPixels(...); // call PLT API at 0x4708a8
    const char* str = "iklf";
    const char* str = "lfVDSvcJNI<%s:%d> nDetectBitmap: malloc %zu bytes failed.";
    const char* str = "doDetectBitmap";
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z(...); // call PLT API at 0x4708d0
    const char* str = "malloc failed";
    sub_470364(...); // call internal at 0x4708e0
    sub_5263B0(...); // call internal at 0x47090c
    _ZN11LayerFlowNS20CVisionDetectService18detectDecodedImageENSt6__ndk110shared_ptrIN12MTImageKitNS5ImageEEEPKhmRKNS_19VisionDetectOptionsE(...); // call internal at 0x470930
    sub_2BBDB4(...); // call internal at 0x470938
    (*x8)(...);
    sub_5263B0(...); // call internal at 0x470970
    sub_4704E0(...); // call internal at 0x47097c
    sub_4705CC(...); // call internal at 0x470988
    sub_4705CC(...); // call internal at 0x470990
    sub_2BBDB4(...); // call internal at 0x470998
    sub_4705CC(...); // call internal at 0x4709bc
    sub_4705CC(...); // call internal at 0x4709c4
    sub_2BBDB4(...); // call internal at 0x4709d8
    sub_2BBDB4(...); // call internal at 0x4709ec
    __cxa_begin_catch(...); // call PLT API at 0x470a08
    const char* str = "{"error":"unknown error: ";
    sub_2FA2E8(...); // call internal at 0x470a1c
    (*x8)(...);
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call PLT API at 0x470a38
    const char* str = ""}";
    _ZNSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE6appendEPKc(...); // call PLT API at 0x470a60
    _ZdlPv(...); // call PLT API at 0x470a88
    _ZdlPv(...); // call PLT API at 0x470a98
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0x470ad4
    __cxa_end_catch(...); // call PLT API at 0x470ad8
    _ZdlPv(...); // call PLT API at 0x470b08
    _ZdlPv(...); // call PLT API at 0x470b20
    __cxa_end_catch(...); // call PLT API at 0x470b2c
    sub_526544(...); // call internal at 0x470b44
    __stack_chk_fail(...); // call PLT API at 0x470b48
    sub_2BF8C4(...); // call internal at 0x470b4c
}
