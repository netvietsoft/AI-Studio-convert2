// Function: AVFrame& MMCodec::ObjectPool<AVFrame>::acquire_object<>()
// RVA: 0x123438, Size: 168 bytes
int64_t _ZN7MMCodec10ObjectPoolI7AVFrameE14acquire_objectIJEEERS1_DpT_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x12344c
    _ZN7MMCodec10ObjectPoolI7AVFrameE14allocate_chunkIJEEEvDpT_(...); // call imported API via PLT at 0x12345c
    _ZdlPv(...); // call imported API via PLT at 0x123498
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1234b8
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1234d4
}
