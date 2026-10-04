// Function: sub_E3A488
// RVA: 0xe3a488, Size: 232 bytes
int64_t sub_E3A488(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wgpuTextureRelease(...); // call PLT API at 0xe3a4c4
    wgpuTextureViewRelease(...); // call PLT API at 0xe3a4d4
    wgpuTextureViewRelease(...); // call PLT API at 0xe3a4e4
    sub_D7C64C(...); // call internal at 0xe3a4f4
    sub_D7D428(...); // call internal at 0xe3a4f8
    sub_E3C230(...); // call internal at 0xe3a508
    _ZdlPv(...); // call PLT API at 0xe3a518
    sub_E16CA0(...); // call internal at 0xe3a520
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe3a544
    sub_562D14(...); // call internal at 0xe3a548
    sub_E3A488(...); // call internal at 0xe3a55c
    _ZdlPv(...); // call PLT API at 0xe3a56c
}
