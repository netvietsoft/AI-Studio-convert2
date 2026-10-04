// Function: MMCodec::AICodecContext::releaseFrame(MMCodec::MMCodecFrame*)
// RVA: 0x123198, Size: 56 bytes
int64_t _ZN7MMCodec14AICodecContext12releaseFrameEPNS_12MMCodecFrameE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec12MMCodecFrame5resetEv(...); // call imported API via PLT at 0x1231b4
    _ZN7MMCodec10ObjectPoolINS_12MMCodecFrameEE14release_objectERS1_(...); // call imported API via PLT at 0x1231c8
    return a0;
}
