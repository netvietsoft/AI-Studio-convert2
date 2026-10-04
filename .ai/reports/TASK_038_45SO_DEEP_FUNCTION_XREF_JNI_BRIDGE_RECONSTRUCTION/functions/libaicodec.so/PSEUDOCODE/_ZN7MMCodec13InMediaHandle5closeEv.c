// Function: MMCodec::InMediaHandle::close()
// RVA: 0x14039c, Size: 220 bytes
int64_t _ZN7MMCodec13InMediaHandle5closeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avformat_close_input(...); // call imported API via PLT at 0x1403d8
    av_freep(...); // call imported API via PLT at 0x1403e0
    _ZdlPv(...); // call imported API via PLT at 0x1403ec
    (*x8)(...); // indirect call at 0x140404
    _ZN7MMCodec18MediaHandleContext15setStatCallbackEPFvPviidS1_ES1_(...); // call imported API via PLT at 0x140418
    _ZN7MMCodec18MediaHandleContextD1Ev(...); // call imported API via PLT at 0x140428
    _ZdlPv(...); // call imported API via PLT at 0x140430
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x140474
}
