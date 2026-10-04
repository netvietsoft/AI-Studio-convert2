// Function: MMDetectionPlugin::AIVideoRecognition::setSkipFrameCount(int)
// RVA: 0x4effc, Size: 116 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition17setSkipFrameCountEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_set_skip_frame(...); // call imported API via PLT at 0x4f00c
    const char* s_30045 = "MTMVCore";
    const char* s_30b8a = "[%s(%d)]:> [VideoRecognition] setSkipFrameCount failed
"; // string xref
    const char* s_30235 = "setSkipFrameCount"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4f058
    return a0;
}
