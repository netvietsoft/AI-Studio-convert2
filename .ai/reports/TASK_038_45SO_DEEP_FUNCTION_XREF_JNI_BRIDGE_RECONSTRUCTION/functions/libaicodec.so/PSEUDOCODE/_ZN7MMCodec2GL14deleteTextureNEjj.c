// Function: MMCodec::GL::deleteTextureN(unsigned int, unsigned int)
// RVA: 0x17d124, Size: 80 bytes
int64_t _ZN7MMCodec2GL14deleteTextureNEjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glDeleteTextures(...); // call imported API via PLT at 0x17d14c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x17d170
}
