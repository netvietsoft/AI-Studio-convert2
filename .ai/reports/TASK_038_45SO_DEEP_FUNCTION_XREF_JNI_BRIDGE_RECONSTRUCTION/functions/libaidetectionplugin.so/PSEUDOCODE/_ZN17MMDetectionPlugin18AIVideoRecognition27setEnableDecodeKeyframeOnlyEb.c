// Function: MMDetectionPlugin::AIVideoRecognition::setEnableDecodeKeyframeOnly(bool)
// RVA: 0x4f0e4, Size: 120 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition27setEnableDecodeKeyframeOnlyEb(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_set_enable_key_frame_only(...); // call imported API via PLT at 0x4f0f8
    const char* s_30045 = "MTMVCore";
    const char* s_30bc2 = "[%s(%d)]:> [VideoRecognition] setEnableDecodeKeyframeOnly failed
"; // string xref
    const char* s_302fa = "setEnableDecodeKeyframeOnly"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4f144
    return a0;
}
