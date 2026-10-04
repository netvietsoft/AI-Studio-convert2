// Function: MMDetectionPlugin::AIVideoRecognition::setStartTimeAndDuration(long, long)
// RVA: 0x4ef30, Size: 204 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition23setStartTimeAndDurationEll(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_set_start_time(...); // call imported API via PLT at 0x4ef48
    vlai_video_recognition_codec_set_duration_time(...); // call imported API via PLT at 0x4ef5c
    const char* s_30045 = "MTMVCore";
    const char* s_3127c = "[%s(%d)]:> [VideoRecognition] setStartTime failed
"; // string xref
    const char* s_303cd = "setStartTimeAndDuration"; // string xref
    const char* s_30045 = "MTMVCore";
    const char* s_31aa3 = "[%s(%d)]:> [VideoRecognition] setDuration failed
"; // string xref
    const char* s_303cd = "setStartTimeAndDuration"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4efe8
    return a0;
}
