// Function: MMCodec::GLUtil::CreateTexture(int, int, int)
// RVA: 0x10dd28, Size: 240 bytes
int64_t _ZN7MMCodec6GLUtil13CreateTextureEiii(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glGenTextures(...); // call imported API via PLT at 0x10dd5c
    glBindTexture(...); // call imported API via PLT at 0x10dd6c
    glTexImage2D(...); // call imported API via PLT at 0x10dd94
    glTexParameteri(...); // call imported API via PLT at 0x10dda4
    glTexParameteri(...); // call imported API via PLT at 0x10ddb4
    glTexParameteri(...); // call imported API via PLT at 0x10ddc4
    glTexParameteri(...); // call imported API via PLT at 0x10ddd4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10de14
}
