// Function: MMCodec::GL::bindTextureExternalN(unsigned int, unsigned int, unsigned int)
// RVA: 0x17d0a0, Size: 52 bytes
int64_t _ZN7MMCodec2GL20bindTextureExternalNEjjj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glActiveTexture(...); // call imported API via PLT at 0x17d0bc
    glBindTexture(...); // call imported API via PLT at 0x17d0d0
}
