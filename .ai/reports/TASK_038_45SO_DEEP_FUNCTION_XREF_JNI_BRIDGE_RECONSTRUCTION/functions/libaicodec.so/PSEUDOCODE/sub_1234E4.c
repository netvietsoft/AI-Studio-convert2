// Function: sub_1234E4
// RVA: 0x1234e4, Size: 52 bytes
int64_t sub_1234E4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_frame_unref(...); // call imported API via PLT at 0x1234fc
    _ZN7MMCodec10ObjectPoolI7AVFrameE14release_objectERS1_(...); // call imported API via PLT at 0x123510
    return a0;
}
