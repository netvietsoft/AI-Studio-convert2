// Function: sub_BD163C
// RVA: 0xbd163c, Size: 236 bytes
int64_t sub_BD163C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    AMediaFormat_new(...); // call imported API via PLT at 0xbd1664
    AMediaFormat_setString(...); // call imported API via PLT at 0xbd167c
    AMediaFormat_setInt32(...); // call imported API via PLT at 0xbd1694
    AMediaFormat_setInt32(...); // call imported API via PLT at 0xbd16ac
    AMediaCodec_createDecoderByType(...); // call imported API via PLT at 0xbd16b4
    AMediaCodec_configure(...); // call imported API via PLT at 0xbd16d0
    AMediaCodec_start(...); // call imported API via PLT at 0xbd16e0
    AMediaCodec_stop(...); // call imported API via PLT at 0xbd16fc
    AMediaCodec_delete(...); // call imported API via PLT at 0xbd1708
    AMediaFormat_delete(...); // call imported API via PLT at 0xbd1710
    return a0;
}
