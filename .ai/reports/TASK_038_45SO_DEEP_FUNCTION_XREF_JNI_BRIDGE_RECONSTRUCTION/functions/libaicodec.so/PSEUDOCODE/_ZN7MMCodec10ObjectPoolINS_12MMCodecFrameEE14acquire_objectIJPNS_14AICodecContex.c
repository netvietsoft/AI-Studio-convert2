// Function: MMCodec::MMCodecFrame& MMCodec::ObjectPool<MMCodec::MMCodecFrame>::acquire_object<MMCodec::AICodecContext*>(MMCodec::AICodecContext*)
// RVA: 0x1230d8, Size: 176 bytes
int64_t _ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14acquire_objectIJPNS_14AICodecContextEEEERS1_DpT_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x1230f0
    _ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14allocate_chunkIJPNS_14AICodecContextEEEEvDpT_(...); // call imported API via PLT at 0x123104
    _ZdlPv(...); // call imported API via PLT at 0x123140
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123160
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x12317c
}
