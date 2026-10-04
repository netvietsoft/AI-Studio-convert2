// Function: MMDetectionPlugin::AIVideoRecognition::setScale(float)
// RVA: 0x4f070, Size: 116 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition8setScaleEf(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_set_scale(...); // call imported API via PLT at 0x4f080
    const char* s_30045 = "MTMVCore";
    const char* s_309c0 = "[%s(%d)]:> [VideoRecognition] setScale failed
"; // string xref
    const char* s_313af = "setScale"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4f0cc
    return a0;
}
