// Function: sub_D8F80
// RVA: 0xd8f80, Size: 200 bytes
int64_t sub_D8F80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0xd8fc0
    void* g_fad08 = (void*)0xfad08; // global ref
    return a0;
    _ZSt9terminatev(...); // call imported API via PLT at 0xd9040
}
