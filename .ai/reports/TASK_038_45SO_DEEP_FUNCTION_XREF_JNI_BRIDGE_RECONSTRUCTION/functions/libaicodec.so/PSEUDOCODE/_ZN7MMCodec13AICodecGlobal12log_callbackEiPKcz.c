// Function: MMCodec::AICodecGlobal::log_callback(int, char const*, ...)
// RVA: 0x12e5dc, Size: 316 bytes
int64_t _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call imported API via PLT at 0x12e690
    vsnprintf(...); // call imported API via PLT at 0x12e6d0
    (*x8)(...); // indirect call at 0x12e6e0
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x12e714
}
