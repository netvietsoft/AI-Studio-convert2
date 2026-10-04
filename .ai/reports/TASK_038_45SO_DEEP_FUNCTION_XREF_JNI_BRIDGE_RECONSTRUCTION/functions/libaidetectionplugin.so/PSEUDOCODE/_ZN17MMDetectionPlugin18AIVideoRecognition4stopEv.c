// Function: MMDetectionPlugin::AIVideoRecognition::stop()
// RVA: 0x4f934, Size: 116 bytes
int64_t _ZN17MMDetectionPlugin18AIVideoRecognition4stopEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_video_recognition_codec_stop(...); // call imported API via PLT at 0x4f944
    const char* s_30045 = "MTMVCore";
    const char* s_3110c = "[%s(%d)]:> [VideoRecognition] stop failed
"; // string xref
    const char* s_31716 = "stop"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x4f990
    return a0;
}
