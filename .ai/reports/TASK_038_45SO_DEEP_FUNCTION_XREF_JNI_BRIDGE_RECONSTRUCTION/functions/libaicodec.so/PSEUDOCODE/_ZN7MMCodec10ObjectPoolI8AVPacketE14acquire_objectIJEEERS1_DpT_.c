// Function: AVPacket& MMCodec::ObjectPool<AVPacket>::acquire_object<>()
// RVA: 0x123778, Size: 168 bytes
int64_t _ZN7MMCodec10ObjectPoolI8AVPacketE14acquire_objectIJEEERS1_DpT_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0x12378c
    _ZN7MMCodec10ObjectPoolI8AVPacketE14allocate_chunkIJEEEvDpT_(...); // call imported API via PLT at 0x12379c
    _ZdlPv(...); // call imported API via PLT at 0x1237d8
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x1237f8
    return a0;
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0x123814
}
