// Function: MMDetectionPlugin::AIVideoRecognition::run()
// RVA: 0x4f1f0, Size: 116 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition3runEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_run(...); // call imported API via PLT at 0x4f200
    const char* s_30045 = "MTMVCore";
    const char* s_30d8b = "[%s(%d)]:> [VideoRecognition] run failed
"; // string xref
    const char* s_3092a = "run"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4f24c
    return a0;
}
