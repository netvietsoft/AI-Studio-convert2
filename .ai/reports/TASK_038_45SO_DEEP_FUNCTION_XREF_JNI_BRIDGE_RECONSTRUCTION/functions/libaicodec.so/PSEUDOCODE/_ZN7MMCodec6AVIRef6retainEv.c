// Function: MMCodec::AVIRef::retain()
// RVA: 0x1285f8, Size: 100 bytes
int64_t _ZN7MMCodec6AVIRef6retainEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x12860c
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x12862c
    const char* s_67aa0 = "Assertion %s failed at %s:%d
";
    const char* s_8d164 = "_referenceCount > 0"; // string xref
    const char* s_823b8 = "/Users/meitu/apollo-ws/proj/android/aicodec/src/main/cpp/src/base/AVIRef.cpp"; // string xref
    av_log(...); // call imported API via PLT at 0x128654
    abort(...); // call imported API via PLT at 0x128658
}
