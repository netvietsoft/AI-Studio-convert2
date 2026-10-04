// Function: MMCodec::EglCore::querySurface(void*, int)
// RVA: 0x10f750, Size: 80 bytes
int64_t _ZN7MMCodec7EglCore12querySurfaceEPvi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    eglQuerySurface(...); // call imported API via PLT at 0x10f774
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x10f79c
}
